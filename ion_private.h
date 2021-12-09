/*
    +--------------------------------------------------------------------+
    | PECL :: ion                                                        |
    +--------------------------------------------------------------------+
    | Redistribution and use in source and binary forms, with or without |
    | modification, are permitted provided that the conditions mentioned |
    | in the accompanying LICENSE file are met.                          |
    +--------------------------------------------------------------------+
    | Copyright (c) 2021, Michael Wallner <mike@php.net>                 |
    +--------------------------------------------------------------------+
*/

#include "ionc/ion.h"

#include "php.h"
#include "ext/date/php_date.h"

typedef struct php_ion_serializer {
	ION_WRITER *writer;
	ION_WRITER_OPTIONS *options;
	smart_str *buffer;
	zend_string *call_custom;
	zend_bool call_magic;
	uint32_t level;
	HashTable *ids;
	HashTable *tmp;
} php_ion_serializer;

typedef struct php_ion_unserializer {
	ION_READER *reader;
	ION_READER_OPTIONS *options;
	zend_string *call_custom;
	zend_bool call_magic;
	uint32_t level;
	HashTable *ids;
	HashTable *tmp;
	HashTable *addref;
} php_ion_unserializer;

ZEND_BEGIN_MODULE_GLOBALS(ion)

	php_ion_serializer serializer;
	php_ion_unserializer unserializer;

	struct {
		HashTable serializer[2];
		HashTable unserializer[3];
	} _ht;

ZEND_END_MODULE_GLOBALS(ion);

#ifdef ZTS
#	define php_ion_globals (*((zend_ion_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(ion_globals_id)]))
#else
#	define php_ion_globals ion_globals
#endif

ZEND_DECLARE_MODULE_GLOBALS(ion);

static inline void php_ion_globals_serializer_init(void)
{
	php_ion_serializer *s = &php_ion_globals.serializer;
	HashTable *h = php_ion_globals._ht.serializer;

	zend_hash_init(s->tmp = &h[0], 0, NULL, ZVAL_PTR_DTOR, 0);
	zend_hash_init(s->ids = &h[1], 0, NULL, NULL, 0);
}

static inline uint32_t php_ion_globals_serializer_step(void)
{
	php_ion_serializer *s = &php_ion_globals.serializer;
	uint32_t level;

	if (!(level = s->level++)) {
		zend_hash_clean(s->ids);
		zend_hash_clean(s->tmp);
	}
	return level;
}

static inline uint32_t php_ion_globals_serializer_exit(void)
{
	php_ion_serializer *s = &php_ion_globals.serializer;

	ZEND_ASSERT(s->level);
	if (!--s->level) {
		zend_hash_clean(s->ids);
		zend_hash_clean(s->tmp);
	}
	return s->level;
}

static inline void php_ion_globals_serializer_dtor(void)
{
	php_ion_serializer *s = &php_ion_globals.serializer;

	zend_hash_destroy(s->tmp);
	zend_hash_destroy(s->ids);
}

void ZVAL_ADDREF(zval *zv)
{
	if (Z_ISREF_P(zv)) {
		Z_TRY_ADDREF_P(Z_REFVAL_P(zv));
	} else {
		Z_TRY_ADDREF_P(zv);
	}
}
static inline void php_ion_globals_unserializer_init(void)
{
	php_ion_unserializer *s = &php_ion_globals.unserializer;
	HashTable *h = php_ion_globals._ht.unserializer;

	zend_hash_init(s->tmp = &h[0], 0, NULL, ZVAL_PTR_DTOR, 0);
	zend_hash_init(s->ids = &h[1], 0, NULL, NULL, 0);
	zend_hash_init(s->addref = &h[2], 0, NULL, ZVAL_ADDREF, 0);
}

static inline void php_ion_globals_unserializer_step(void)
{
	php_ion_unserializer *s = &php_ion_globals.unserializer;

	if (!s->level++) {
		zend_hash_clean(s->addref);
		zend_hash_clean(s->ids);
		zend_hash_clean(s->tmp);
	}
}

static inline void php_ion_globals_unserializer_exit(void)
{
	php_ion_unserializer *s = &php_ion_globals.unserializer;

	ZEND_ASSERT(s->level);
	if (!--s->level) {
		zend_hash_clean(s->addref);
		zend_hash_clean(s->ids);
		zend_hash_clean(s->tmp);
	}
}

static inline void php_ion_globals_unserializer_dtor(void)
{
	php_ion_unserializer *s = &php_ion_globals.unserializer;

	zend_hash_destroy(s->addref);
	zend_hash_destroy(s->ids);
	zend_hash_destroy(s->tmp);
}

static zend_class_entry
	*ce_Annotation,
	*ce_Catalog,
	*ce_Collection,
	*ce_Decimal,
	*ce_Decimal_Context,
	*ce_Reader,
	*ce_Reader_Options,
	*ce_Reader_Reader,
	*ce_Reader_Buffer,
	*ce_Reader_Stream,
	*ce_Reader_Buffer_Reader,
	*ce_Reader_Stream_Reader,
	*ce_Serializer,
	*ce_Serializer_PHP,
	*ce_Symbol,
	*ce_Symbol_ImportLocation,
	*ce_Symbol_System,
	*ce_Symbol_System_SID,
	*ce_Symbol_Table,
	*ce_Timestamp,
	*ce_Timestamp_Precision,
	*ce_Type,
	*ce_Unserializer,
	*ce_Unserializer_PHP,
	*ce_Writer,
	*ce_Writer_Options,
	*ce_Writer_Buffer,
	*ce_Writer_Buffer_Writer,
	*ce_Writer_Stream,
	*ce_Writer_Stream_Writer,
	*ce_Writer_Writer
	;

#define php_ion_decl(type, cname, ...) \
	static zend_object_handlers oh_ ## cname; \
	static inline zend_object *create_ion_ ## cname(zend_class_entry *ce) \
	{ \
		if (!ce) ce = ce_ ## cname; \
		php_ion_ ## type *o = ecalloc(1, sizeof(*o) + zend_object_properties_size(ce)); \
		zend_object_std_init(&o->std, ce); \
		object_properties_init(&o->std, ce); \
		o->std.handlers = &oh_ ## cname; \
		return &o->std; \
	} \
	static inline void free_ion_ ## cname(zend_object *std) \
	{ \
		php_ion_ ## type *obj = php_ion_obj(type, std); \
		__VA_ARGS__; \
		zend_object_std_dtor(std); \
		(void) obj; \
	}
#define php_ion_register(type, cname, ...) do { \
	ce_ ## cname = register_class_ion_ ## cname(__VA_ARGS__); \
	ce_ ## cname ->create_object = create_ion_ ## cname; \
	memcpy(&oh_ ## cname, zend_get_std_object_handlers(), sizeof(zend_object_handlers)); \
	oh_ ## cname .offset = offsetof(php_ion_ ## type, std); \
	oh_ ## cname .free_obj = free_ion_ ## cname; \
} while (0)

#define php_ion_obj(type, obj) \
	((php_ion_ ## type *) (obj ? ((char *)(obj) - XtOffsetOf(php_ion_ ## type, std)) : NULL))

#define ION_CHECK(err, ...) do { \
	iERR __err = err; \
	if (__err) { \
		zend_throw_exception_ex(spl_ce_RuntimeException, __err, "%s: %s", ion_error_to_str(__err), #err); \
		__VA_ARGS__; \
		return; \
	} \
} while (0)

#define ION_CATCH(...) do { \
	if (EG(exception)) { \
		__VA_ARGS__; \
		return; \
	} \
} while (0)

#define PTR_CHECK(ptr, ...) do { \
	if (!(ptr)) { \
		zend_throw_error(NULL, "Uninitialized object"); \
		__VA_ARGS__; \
		return; \
	} \
} while (0)

#define OBJ_CHECK(obj) do { \
	PTR_CHECK(obj); \
	PTR_CHECK(*((void **)obj)); \
} while (0)

static inline ION_STRING *ion_string_from_cstr(ION_STRING *is, const char *s, size_t l)
{
	is->length = l;
	is->value = (BYTE *) s;
	return is;
}

static inline ION_STRING *ion_string_from_zend(ION_STRING *is, const zend_string *zs)
{
	is->length = zs ? zs->len : 0;
	is->value = (BYTE *) (zs ? zs->val : NULL);
	return is;
}

static inline zend_string *zend_string_from_ion(const ION_STRING *s)
{
	return zend_string_init((const char *) s->value, s->length, 0);
}

static inline void update_property_obj(zend_object *obj, const char *n, size_t l, zend_object *p)
{
	zval zobj;
	ZVAL_OBJ(&zobj, p);
	zend_update_property(obj->ce, obj, n, l, &zobj);
}

typedef struct php_ion_type {
	ION_TYPE typ;
	zend_object std;
} php_ion_type;

php_ion_decl(type, Type);

#define RETURN_IONTYPE(typ) do { \
	zend_object *__zo = php_ion_type_fetch(typ); \
	if (UNEXPECTED(!__zo)) { \
		RETURN_THROWS(); \
	} \
	RETURN_OBJ_COPY(__zo); \
} while(0)

static inline zend_object *php_ion_type_fetch(ION_TYPE typ)
{
	zend_long index = ION_TYPE_INT(typ);
	zval *ztype = zend_hash_index_find(ce_Type->backed_enum_table, index);

	if (UNEXPECTED(!ztype || Z_TYPE_P(ztype) != IS_STRING)) {
		zend_value_error(ZEND_LONG_FMT " is not a valid backing value for enum \"%s\"", index, ZSTR_VAL(ce_Type->name));
		return NULL;
	}
	return zend_enum_get_case(ce_Type, Z_STR_P(ztype));
}

typedef struct php_ion_symbol_iloc {
	ION_SYMBOL_IMPORT_LOCATION loc;
	zend_string *name;
	zend_object std;
} php_ion_symbol_iloc;

static inline void php_ion_symbol_iloc_ctor(php_ion_symbol_iloc *obj)
{
	zend_update_property_long(obj->std.ce, &obj->std, ZEND_STRL("location"), obj->loc.location);
	zend_update_property_str(obj->std.ce, &obj->std, ZEND_STRL("name"), obj->name);
	ion_string_from_zend(&obj->loc.name, obj->name);
}

static inline void php_ion_symbol_iloc_dtor(php_ion_symbol_iloc *obj)
{
	zend_string_release(obj->name);
}

php_ion_decl(symbol_iloc, Symbol_ImportLocation, php_ion_symbol_iloc_dtor(obj));

typedef struct php_ion_symbol {
	ION_SYMBOL sym;
	zend_string *value;
	zend_object *iloc, std;
} php_ion_symbol;

static inline void php_ion_symbol_ctor(php_ion_symbol *obj)
{
	zend_update_property_long(obj->std.ce, &obj->std, ZEND_STRL("sid"),
		obj->sym.sid);
	if (obj->value) {
		zend_update_property_str(obj->std.ce, &obj->std, ZEND_STRL("value"), obj->value);
	} else{
		zend_update_property_null(obj->std.ce, &obj->std, ZEND_STRL("value"));
	}
	ion_string_from_zend(&obj->sym.value, obj->value);
	if (obj->iloc) {
		update_property_obj(&obj->std, ZEND_STRL("importLocation"), obj->iloc);
		obj->sym.import_location = php_ion_obj(symbol_iloc, obj->iloc)->loc;
	} else {
		zend_update_property_null(obj->std.ce, &obj->std, ZEND_STRL("importLocation"));
	}
}

static inline void php_ion_symbol_dtor(php_ion_symbol *obj)
{
	if (obj->value) {
		zend_string_release(obj->value);
	}
}

static inline void php_ion_symbol_zval(ION_SYMBOL *sym_ptr, zval *return_value)
{
	object_init_ex(return_value, ce_Symbol);
	php_ion_symbol *sym = php_ion_obj(symbol, Z_OBJ_P(return_value));

	sym->sym.sid = sym_ptr->sid;
	sym->value = zend_string_from_ion(&sym_ptr->value);
	if (!ION_SYMBOL_IMPORT_LOCATION_IS_NULL(sym_ptr)) {
		zval ziloc;
		object_init_ex(&ziloc, ce_Symbol_ImportLocation);
		sym->iloc = Z_OBJ(ziloc);

		php_ion_symbol_iloc *iloc = php_ion_obj(symbol_iloc, sym->iloc);
		iloc->loc.location = sym_ptr->import_location.location;
		iloc->name = zend_string_from_ion(&sym_ptr->import_location.name);

		php_ion_symbol_iloc_ctor(iloc);
	}

	php_ion_symbol_ctor(sym);
}

php_ion_decl(symbol, Symbol, php_ion_symbol_dtor(obj));

typedef struct php_ion_symbol_table {
	zend_object std;
} php_ion_symbol_table;

php_ion_decl(symbol_table, Symbol_Table);

typedef struct php_ion_decimal_ctx {
	decContext ctx;
	zend_object std;
} php_ion_decimal_ctx;

static inline void php_ion_decimal_ctx_ctor(php_ion_decimal_ctx *obj) {
	zval tmp, *zbits = zend_read_property(obj->std.ce, &obj->std, ZEND_STRL("bits"), 1, &tmp);

	int bits = 128;
	if (zbits != &EG(uninitialized_zval)) {
		bits = Z_LVAL_P(zbits);
	} else {
		zend_update_property_long(obj->std.ce, &obj->std, ZEND_STRL("bits"), bits);
	}
	switch (bits) {
	case 32:
	case 64:
	case 128:
		decContextDefault(&obj->ctx, bits);
		break;
	default:
		zend_throw_exception_ex(spl_ce_InvalidArgumentException, IERR_INVALID_ARG,
				"Decimal context only allows 32, 64 or 128 bits");
	}
}

php_ion_decl(decimal_ctx, Decimal_Context);

typedef struct php_ion_decimal {
	ION_DECIMAL dec;
	zend_object *ctx, std;
} php_ion_decimal;

static inline zend_string *php_ion_decimal_to_string(ION_DECIMAL *dec)
{
	zend_string *zstr = zend_string_alloc(ION_DECIMAL_STRLEN(dec), 0);
	(void) ion_decimal_to_string(dec, zstr->val);
	return zend_string_truncate(zstr, strlen(zstr->val), 0);
}

static inline void php_ion_decimal_to_int(ION_DECIMAL *dec, decContext *ctx, zend_long *l)
{
	ION_INT *ii = NULL;
	ION_CHECK(ion_int_alloc(NULL, &ii));
	ION_CHECK(ion_decimal_to_ion_int(dec, ctx, ii), ion_int_free(ii));
	int64_t i64;
	ION_CHECK(ion_int_to_int64(ii, &i64), ion_int_free(ii));
	*l = i64;
	ion_int_free(ii);
}

static inline void php_ion_decimal_ctor(php_ion_decimal *obj)
{
	if (!obj->ctx) {
		zval zdc;
		object_init_ex(&zdc, ce_Decimal_Context);
		obj->ctx = Z_OBJ(zdc);
		php_ion_decimal_ctx_ctor(php_ion_obj(decimal_ctx, obj->ctx));
	}
	update_property_obj(&obj->std, ZEND_STRL("context"), obj->ctx);

	if (ion_decimal_is_integer(&obj->dec)) {
		zend_long l;
		php_ion_decimal_to_int(&obj->dec, &php_ion_obj(decimal_ctx, obj->ctx)->ctx, &l);
		zend_update_property_long(obj->std.ce, &obj->std, ZEND_STRL("number"), l);
	} else {
		zend_string *zstr = php_ion_decimal_to_string(&obj->dec);
		zend_update_property_str(obj->std.ce, &obj->std, ZEND_STRL("number"), zstr);
		zend_string_release(zstr);
	}
}

static inline void php_ion_decimal_dtor(php_ion_decimal *obj)
{
	ion_decimal_free(&obj->dec);
}

php_ion_decl(decimal, Decimal, php_ion_decimal_dtor(obj));

typedef php_date_obj php_ion_timestamp;

static inline zend_long php_usec_from_ion(const decQuad *frac, decContext *ctx)
{
	decQuad microsecs, result;
	decQuadMultiply(&result, decQuadFromInt32(&microsecs, 1000000), frac, ctx);
	return (zend_long) decQuadToUInt32(&result, ctx, DEC_ROUND_HALF_EVEN);
}

static inline decQuad *ion_ts_frac_from_usec(decQuad *frac, zend_long usec, decContext *ctx)
{
	decQuad microsecs, us;
 	return decQuadDivide(frac, decQuadFromInt32(&us, usec), decQuadFromInt32(&microsecs, 1000000), ctx);
}

static inline zend_string *php_dt_format_from_precision(uint8_t precision)
{
	switch (precision) {
	case ION_TS_FRAC:
		return zend_string_init(ZEND_STRL("c"), 0);
	case ION_TS_SEC:
		return zend_string_init(ZEND_STRL("Y-m-d\\TH:i:sP"), 0);
	case ION_TS_MIN:
		return zend_string_init(ZEND_STRL("Y-m-d\\TH:iP"), 0);
	case ION_TS_DAY:
		return zend_string_init(ZEND_STRL("Y-m-d\\T"), 0);
	case ION_TS_MONTH:
		return zend_string_init(ZEND_STRL("Y-m\\T"), 0);
	case ION_TS_YEAR:
		return zend_string_init(ZEND_STRL("Y\\T"), 0);
	default:
		return zend_string_init(ZEND_STRL("c"), 0);
	}
}

static inline timelib_time* php_time_from_ion(const ION_TIMESTAMP *ts, decContext *ctx, zend_string **fmt)
{
	timelib_time *time = timelib_time_ctor();

	switch (ts->precision) {
	case ION_TS_FRAC:
		time->us = php_usec_from_ion(&ts->fraction, ctx);
		/* fallthrough */
	case ION_TS_SEC:
		time->s = ts->seconds;
		/* fallthrough */
	case ION_TS_MIN:
		time->i = ts->minutes;
		time->h = ts->hours;
		/* fallthrough */
	case ION_TS_DAY:
		time->d = ts->day;
		/* fallthrough */
	case ION_TS_MONTH:
		time->m = ts->month;
		/* fallthrough */
	case ION_TS_YEAR:
		time->y = ts->year;
		/* fallthrough */
	default:
		time->z = ts->tz_offset * 60;
	}

	if (fmt) {
		*fmt = php_dt_format_from_precision(ts->precision);
	}
	return time;
}

static inline ION_TIMESTAMP *ion_timestamp_from_php(ION_TIMESTAMP *buf, php_ion_timestamp *ts, decContext *ctx)
{
	memset(buf, 0, sizeof(*buf));

	zval tmp;
	uint8_t precision = Z_LVAL_P(zend_read_property(ts->std.ce, &ts->std, ZEND_STRL("precision"), 0, &tmp));

	if (!precision || precision > ION_TS_FRAC) {
		zend_throw_exception_ex(spl_ce_InvalidArgumentException, IERR_INVALID_ARG,
				"Invalid precision (%u) of ion\\Timestamp", (unsigned) precision);
	} else switch ((buf->precision = precision)) {
	case ION_TS_FRAC:
		ion_ts_frac_from_usec(&buf->fraction, ts->time->us, ctx);
		/* fallthrough */
	case ION_TS_SEC:
		buf->seconds = ts->time->s;
		/* fallthrough */
	case ION_TS_MIN:
		buf->minutes = ts->time->i;
		/* fallthrough */
	case ION_TS_DAY:
		buf->hours = ts->time->h;
		buf->day = ts->time->d;
		/* fallthrough */
	case ION_TS_MONTH:
		buf->month = ts->time->m;
		/* fallthrough */
	case ION_TS_YEAR:
		buf->year = ts->time->y;
		/* fallthrough */
	default:
		buf->tz_offset = ts->time->z / 60;
	}

	return buf;
}

static inline void php_ion_timestamp_ctor(php_ion_timestamp *obj, zend_long precision, zend_string *fmt, zend_string *dt, zval *tz)
{
	if (!obj->time) {
		php_date_initialize(obj, dt ? dt->val : "", dt ? dt->len : 0, fmt ? fmt->val : NULL, tz, PHP_DATE_INIT_CTOR);
	}
	zend_update_property_long(obj->std.ce, &obj->std, ZEND_STRL("precision"), precision);

	fmt = php_dt_format_from_precision(precision);
	zend_update_property_str(obj->std.ce, &obj->std, ZEND_STRL("format"), fmt);
	zend_string_release(fmt);
}

static inline void php_ion_timestamp_dtor(php_ion_timestamp *obj)
{
	if (obj->time) {
		timelib_time_dtor(obj->time);
	}
}

php_ion_decl(timestamp, Timestamp, php_ion_timestamp_dtor(obj));

typedef struct php_ion_catalog {
	ION_CATALOG *cat;
	zend_object std;
} php_ion_catalog;

php_ion_decl(catalog, Catalog);

typedef struct php_ion_reader_options {
	ION_READER_OPTIONS opt;
	zend_object *cat, *dec_ctx, *cb, std;
} php_ion_reader_options;

php_ion_decl(reader_options, Reader_Options);

typedef struct php_ion_reader {
	ION_READER *reader;
	ION_TYPE state;
	enum {
		BUFFER_READER,
		STREAM_READER,
	} type;
	union {
		zend_string *buffer;
		struct {
			php_stream *ptr;
			ION_STRING buf;
		} stream;
	};
	zend_object *opt, std;
} php_ion_reader;

static inline iERR php_ion_reader_stream_handler(struct _ion_user_stream *user)
{
	php_ion_reader *reader = (php_ion_reader *) user->handler_state;
	size_t remaining = 0, spare = reader->stream.buf.length;

	if (user->curr && user->limit && (remaining = user->limit - user->curr)) {
		memmove(reader->stream.buf.value, user->curr, remaining);
		user->limit -= remaining;
		spare -= remaining;
	} else {
		user->curr = user->limit = reader->stream.buf.value;
	}

	ssize_t read = php_stream_read(reader->stream.ptr, (char *) user->limit, spare);
	if (EXPECTED(read > 0)) {
		user->limit += read;
		return IERR_OK;
	}

	if (EXPECTED(read == 0)) {
		return IERR_EOF;
	}

	return IERR_READ_ERROR;
}

static inline iERR on_context_change(void *context, ION_COLLECTION *imports)
{
	if (context) {
		php_ion_reader *obj = php_ion_obj(reader, context);
		(void) obj;
	}
	return IERR_OK;
}

static ION_READER_CONTEXT_CHANGE_NOTIFIER EMPTY_READER_CHANGE_NOTIFIER = {
	on_context_change,
	NULL
};

static inline void php_ion_reader_ctor(php_ion_reader *obj)
{
	iERR err;
	php_ion_reader_options *opt = php_ion_obj(reader_options, obj->opt);

	if (opt) {
		opt->opt.context_change_notifier.context = obj;
	}
	if (obj->type == STREAM_READER) {
		PTR_CHECK(obj->stream.ptr);
		GC_ADDREF(obj->stream.ptr->res);

		php_ion_reader_options *opt = php_ion_obj(reader_options, obj->opt);
		obj->stream.buf.length = opt ? opt->opt.allocation_page_size : 0x1000;
		obj->stream.buf.value = emalloc(obj->stream.buf.length);
		err = ion_reader_open_stream(&obj->reader, obj, php_ion_reader_stream_handler, opt ? &opt->opt : NULL);

	} else {
		err = ion_reader_open_buffer(&obj->reader,
				(BYTE *) obj->buffer->val, obj->buffer->len,
				opt ? &opt->opt : NULL);
	}
	if (opt) {
		opt->opt.context_change_notifier.context = NULL;
	}

	ION_CHECK(err);
	OBJ_CHECK(obj);
}
static inline void php_ion_reader_dtor(php_ion_reader *obj)
{
	if (obj->reader) {
		ion_reader_close(obj->reader);
	}
	if (obj->type == STREAM_READER) {
		if (obj->stream.buf.value) {
			efree(obj->stream.buf.value);
		}
		if (obj->stream.ptr) {
			zend_list_delete(obj->stream.ptr->res);
		}
	} else {
		if (obj->buffer) {
			zend_string_release(obj->buffer);
		}
	}
}

php_ion_decl(reader, Reader_Reader, php_ion_reader_dtor(obj));

typedef struct php_ion_writer_options {
	ION_WRITER_OPTIONS opt;
	zend_object *cat, *dec_ctx, *col, std;
} php_ion_writer_options;

php_ion_decl(writer_options, Writer_Options);

typedef struct php_ion_writer {
	ION_WRITER *writer;
	enum {
		BUFFER_WRITER,
		STREAM_WRITER,
	} type;
	union {
		struct {
			zval val;
			smart_str str;
		} buffer;
		struct {
			ION_STRING buf;
			php_stream *ptr;
		} stream;
	};
	zend_object *opt, std;

} php_ion_writer;

static inline iERR php_ion_writer_stream_handler(struct _ion_user_stream *user)
{
	php_ion_writer *writer = (php_ion_writer *) user->handler_state;

	if (EXPECTED(user->limit && user->curr)) {
		ptrdiff_t len = user->curr - writer->stream.buf.value;
		if (len != php_stream_write(writer->stream.ptr, (char *) writer->stream.buf.value, len)) {
			return IERR_WRITE_ERROR;
		}
	}
	user->curr = writer->stream.buf.value;
	user->limit = writer->stream.buf.value + writer->stream.buf.length;
	return IERR_OK;
}

#define REF_STR() do { \
	ZVAL_NEW_STR(ref, obj->buffer.str.s); \
	GC_ADDREF(obj->buffer.str.s); \
} while (0)

#define NEW_REF_STR() do {\
	if (Z_STR_P(ref) != obj->buffer.str.s) { \
		zval_ptr_dtor(ref); \
		REF_STR(); \
	} \
} while(0)

static inline void php_ion_writer_stream_init(php_ion_writer *obj, php_ion_writer_options *opt)
{
	PTR_CHECK(obj->stream.ptr);
	GC_ADDREF(obj->stream.ptr->res);

	obj->stream.buf.length = opt ? opt->opt.allocation_page_size : 0x1000;
	obj->stream.buf.value = emalloc(obj->stream.buf.length);
}
static inline void php_ion_writer_buffer_init(php_ion_writer *obj)
{
	zval *ref = &obj->buffer.val;
	ZVAL_DEREF(ref);

	smart_str_alloc(&obj->buffer.str, 0, 0);
	smart_str_0(&obj->buffer.str);
	REF_STR();
}

static inline void php_ion_writer_buffer_grow(php_ion_writer *obj)
{
	zval *ref = &obj->buffer.val;
	ZVAL_DEREF(ref);

	switch (GC_REFCOUNT(obj->buffer.str.s)) {
	case 2:
		// nothing to do
		break;
	case 1:
		// we've been separated
		GC_ADDREF(obj->buffer.str.s);
		break;
	default:
		// we have to separate
		fprintf(stderr, "SEPARATE\n");
		obj->buffer.str.s = zend_string_dup(obj->buffer.str.s, 0);
		break;
	}

	zend_string *old = obj->buffer.str.s;
	GC_DELREF(old);
	smart_str_erealloc(&obj->buffer.str, obj->buffer.str.a << 1);
	if (old == obj->buffer.str.s) {
		GC_ADDREF(old);
	} else if(old == Z_STR_P(ref)) {
		ZVAL_NULL(ref);
	}

	NEW_REF_STR();
}

static inline iERR php_ion_writer_buffer_handler(struct _ion_user_stream *user)
{
	php_ion_writer *writer = (php_ion_writer *) user->handler_state;

	if (user->curr) {
		writer->buffer.str.s->len += user->curr - (BYTE *) &writer->buffer.str.s->val[writer->buffer.str.s->len];
		smart_str_0(&writer->buffer.str);
		if (user->limit == user->curr) {
			php_ion_writer_buffer_grow(writer);
		}
	}
	user->curr = (BYTE *) &writer->buffer.str.s->val[writer->buffer.str.s->len];
	user->limit = user->curr + writer->buffer.str.a - writer->buffer.str.s->len;

	return IERR_OK;
}

static inline void php_ion_writer_ctor(php_ion_writer *obj)
{
	if (obj->opt) {
		update_property_obj(&obj->std, ZEND_STRL("options"), obj->opt);
	}

	php_ion_writer_options *opt = php_ion_obj(writer_options, obj->opt);
	ION_STREAM_HANDLER h;
	if (obj->type == STREAM_WRITER) {
		h = php_ion_writer_stream_handler;
		php_ion_writer_stream_init(obj, opt);
	} else {
		h = php_ion_writer_buffer_handler;
		php_ion_writer_buffer_init(obj);
	}

	ION_CHECK(ion_writer_open_stream(&obj->writer, h, obj, opt ? &opt->opt : NULL));
	OBJ_CHECK(obj);
}

static inline void php_ion_writer_dtor(php_ion_writer *obj)
{
	if (obj->writer) {
		ion_writer_close(obj->writer);
	}
	if (obj->type == STREAM_WRITER) {
		if (obj->stream.buf.value) {
			efree(obj->stream.buf.value);
		}
		if (obj->stream.ptr) {
			zend_list_delete(obj->stream.ptr->res);
		}
	} else {
		if (obj->buffer.str.s) {
			smart_str_0(&obj->buffer.str);
			zend_string_release(obj->buffer.str.s);
		}
		zval_ptr_dtor(&obj->buffer.val);
	}
}

php_ion_decl(writer, Writer_Writer, php_ion_writer_dtor(obj));

typedef struct php_ion_serializer_php {
	php_ion_serializer serializer;
	zend_object *opt, std;
} php_ion_serializer_php;

static inline void php_ion_serializer_php_ctor(php_ion_serializer_php *ser_obj)
{
	php_ion_serializer *global_ser = &php_ion_globals.serializer;
	ser_obj->serializer.ids = global_ser->ids;
	ser_obj->serializer.tmp = global_ser->tmp;

	zend_update_property_bool(ser_obj->std.ce, &ser_obj->std, ZEND_STRL("callMagicSerialize"),
			ser_obj->serializer.call_magic);
	if (ser_obj->serializer.call_custom) {
		zend_update_property_str(ser_obj->std.ce, &ser_obj->std, ZEND_STRL("callCustomSerialize"),
				ser_obj->serializer.call_custom);
		ser_obj->serializer.call_custom = zend_string_tolower(ser_obj->serializer.call_custom);
 	} else {
		zend_update_property_null(ser_obj->std.ce, &ser_obj->std, ZEND_STRL("callCustomSerialize"));
	}
	if (ser_obj->opt) {
		php_ion_writer_options *o_woptions = php_ion_obj(writer_options, ser_obj->opt);
		ser_obj->serializer.options = &o_woptions->opt;
		update_property_obj(&ser_obj->std, ZEND_STRL("writerOptions"), ser_obj->opt);
	} else {
		zend_update_property_null(ser_obj->std.ce, &ser_obj->std, ZEND_STRL("writerOptions"));
	}
}

static inline void php_ion_serializer_php_dtor(php_ion_serializer_php *obj)
{
	if (obj->serializer.call_custom) {
		zend_string_release(obj->serializer.call_custom);
	}
}

static inline void php_ion_serialize_zval(php_ion_serializer *, zval *);

static inline void php_ion_serialize_struct(php_ion_serializer *ser, zend_array *arr)
{
	ION_CHECK(ion_writer_start_container(ser->writer, tid_STRUCT));

	zval *v;
	zend_ulong h;
	zend_string *k = NULL;
	if (arr) ZEND_HASH_FOREACH_KEY_VAL_IND(arr, h, k, v)
		ION_STRING is;
		if (k) {
			ION_CHECK(ion_writer_write_field_name(ser->writer, ion_string_from_zend(&is, k)));
		} else {
			char buf[MAX_LENGTH_OF_LONG + 1], *end = buf + sizeof(buf) - 1;
			char *ptr = zend_print_long_to_buf(end, (zend_long) h);
			ION_CHECK(ion_writer_write_field_name(ser->writer, ion_string_from_cstr(&is, ptr, end - ptr)));
		}

		php_ion_serialize_zval(ser, v);
		ION_CATCH();
	ZEND_HASH_FOREACH_END();

	ION_CHECK(ion_writer_finish_container(ser->writer));
}

static inline void php_ion_serialize_list(php_ion_serializer *ser, zend_array *arr)
{
	ION_CHECK(ion_writer_start_container(ser->writer, tid_LIST));

	zval *v;
	ZEND_HASH_FOREACH_VAL_IND(arr, v)
		php_ion_serialize_zval(ser, v);
		ION_CATCH();
	ZEND_HASH_FOREACH_END();

	ION_CHECK(ion_writer_finish_container(ser->writer));
}

static inline void php_ion_serialize_array(php_ion_serializer *ser, zend_array *arr)
{
	if (zend_array_is_list(arr)) {
		php_ion_serialize_list(ser, arr);
	} else {
		php_ion_serialize_struct(ser, arr);
	}
}

static inline void php_ion_serialize_object_iface(php_ion_serializer *ser, zend_object *zobject)
{
	uint8_t *buf;
	size_t len;
	zval tmp;

	ZVAL_OBJ(&tmp, zobject);
	if (SUCCESS == zobject->ce->serialize(&tmp, &buf, &len, NULL)) {
		ION_STRING is;
		ION_CHECK(ion_writer_add_annotation(ser->writer, ion_string_from_cstr(&is, ZEND_STRL("S"))));
		ION_CHECK(ion_writer_add_annotation(ser->writer, ion_string_from_zend(&is, zobject->ce->name)));
		ION_CHECK(ion_writer_write_string(ser->writer, ion_string_from_cstr(&is, (char *) buf, len)));
		efree(buf);
	} else if (!EG(exception)){
		zend_throw_exception_ex(spl_ce_UnexpectedValueException, IERR_INTERNAL_ERROR,
				"Failed to serialize class %s", zobject->ce->name->val);
	}
}

static inline void php_ion_serialize_object_magic(php_ion_serializer *ser, zend_object *zobject, zend_function *fn)
{
	zval rv;

	ZVAL_NULL(&rv);
	zend_call_known_instance_method_with_0_params(fn ? fn : zobject->ce->__serialize, zobject, &rv);
	ION_CATCH();

	if (IS_ARRAY == Z_TYPE(rv)) {
		ION_STRING is;
		ION_CHECK(ion_writer_add_annotation(ser->writer, ion_string_from_cstr(&is, fn ? "C" : "O", 1)));
		ION_CHECK(ion_writer_add_annotation(ser->writer, ion_string_from_zend(&is, zobject->ce->name)));
		php_ion_serialize_zval(ser, &rv);
		zval_ptr_dtor(&rv);
	} else {
		zend_throw_exception_ex(spl_ce_UnexpectedValueException, IERR_INTERNAL_ERROR,
				"%s serializer %s::%s did not return an array",
				fn ? "Custom" : "Magic", zobject->ce->name->val,
				fn ? fn->common.function_name->val : "__serialize");
	}
}

static inline zend_string *fq_enum_case(zend_object *zobject)
{
	zval *cn = zend_enum_fetch_case_name(zobject);
	zend_string *en = zend_string_alloc(zobject->ce->name->len + Z_STRLEN_P(cn) + strlen("\\"), 0);
	memcpy(en->val, zobject->ce->name->val, zobject->ce->name->len);
	en->val[zobject->ce->name->len] = '\\';
	memcpy(&en->val[zobject->ce->name->len + 1], Z_STRVAL_P(cn), Z_STRLEN_P(cn));
	en->val[en->len] = 0;
	return en;
}

static inline void php_ion_serialize_object_enum(php_ion_serializer *ser, zend_object *zobject)
{
	ION_STRING is;
	ION_CHECK(ion_writer_add_annotation(ser->writer, ion_string_from_cstr(&is, ZEND_STRL("E"))));

	zend_string *en = fq_enum_case(zobject);
	ION_CHECK(ion_writer_write_string(ser->writer, ion_string_from_zend(&is, en)));
	zend_string_release(en);
}

static inline void php_ion_serialize_object_std(php_ion_serializer *ser, zend_object *zobject)
{
	ION_STRING is;

	if (zobject->ce != zend_standard_class_def) {
		ION_CHECK(ion_writer_add_annotation(ser->writer, ion_string_from_cstr(&is, ZEND_STRL("c"))));
		ION_CHECK(ion_writer_add_annotation(ser->writer, ion_string_from_zend(&is, zobject->ce->name)));
	} else {
		ION_CHECK(ion_writer_add_annotation(ser->writer, ion_string_from_cstr(&is, ZEND_STRL("o"))));
	}

	zval zobj;
	ZVAL_OBJ(&zobj, zobject);
	HashTable *props = zend_get_properties_for(&zobj, ZEND_PROP_PURPOSE_SERIALIZE);
	if (props) {
		php_ion_serialize_struct(ser, props);
		zend_release_properties(props);
	} else {
		zend_throw_exception_ex(spl_ce_UnexpectedValueException, IERR_INTERNAL_ERROR,
				"Could not get properties for serialization of class %s",
				zobject->ce->name->val);
	}
}

static inline bool can_call_magic_serialize(php_ion_serializer *ser, zend_class_entry *ce)
{
	return ce->__serialize && ser->call_magic;
}

static inline bool can_call_iface_serialize(php_ion_serializer *, zend_class_entry *ce)
{
	return !!ce->serialize;
}

static inline bool can_call_custom_serialize(php_ion_serializer *ser, zend_object *zobject, zend_function **fn)
{
	if (ser->call_custom) {
		return !!(*fn = zend_hash_find_ptr(&zobject->ce->function_table, ser->call_custom));
	}
	return false;
}

static inline void php_ion_serialize_object(php_ion_serializer *ser, zend_object *zobject)
{
	zend_function *fn;
	zend_class_entry *ce = zobject->ce;
	ZEND_ASSERT(ce);

	if (ce->ce_flags & ZEND_ACC_NOT_SERIALIZABLE) {
		zend_throw_exception_ex(spl_ce_InvalidArgumentException, IERR_INVALID_ARG,
				"Serializing %s is not allowed", ce->name->val);
		return;
	}

	if (can_call_magic_serialize(ser, ce)) {
		php_ion_serialize_object_magic(ser, zobject, NULL);
	} else if (can_call_iface_serialize(ser, ce)) {
		php_ion_serialize_object_iface(ser, zobject);
	} else if (can_call_custom_serialize(ser, zobject, &fn)) {
		php_ion_serialize_object_magic(ser, zobject, fn);
	} else if (zobject->ce->ce_flags & ZEND_ACC_ENUM) {
		php_ion_serialize_object_enum(ser, zobject);
	} else if (ce == ce_Symbol) {
		ION_CHECK(ion_writer_write_ion_symbol(ser->writer, &php_ion_obj(symbol, zobject)->sym));
	} else if (ce == ce_Decimal) {
		ION_CHECK(ion_writer_write_ion_decimal(ser->writer, &php_ion_obj(decimal, zobject)->dec));
	} else if (ce == ce_Timestamp) {
		ION_TIMESTAMP its;
		php_ion_timestamp *pts = php_ion_obj(timestamp, zobject);
		decContext *ctx = ser->options ? ser->options->decimal_context : NULL;
		ION_CHECK(ion_writer_write_timestamp(ser->writer, ion_timestamp_from_php(&its, pts, ctx)));
	} else {
		php_ion_serialize_object_std(ser, zobject);
	}
}

static inline void php_ion_serialize_refcounted(php_ion_serializer *ser, zval *zv)
{
	zend_ulong idx = (zend_ulong) (uintptr_t) Z_COUNTED_P(zv);

	ION_STRING is;
	if (zend_hash_index_exists(ser->ids, idx)) {
		zval *num = zend_hash_index_find(ser->ids, idx);

		ION_CHECK(ion_writer_add_annotation(ser->writer, ion_string_from_cstr(&is, ZEND_STRL("r"))));
		ION_CHECK(ion_writer_write_int64(ser->writer, Z_LVAL_P(num)));
	} else {
		zval num;

		ZVAL_LONG(&num, zend_hash_num_elements(ser->ids));
		zend_hash_index_add(ser->ids, idx, &num);

		Z_TRY_ADDREF_P(zv);
		zend_hash_next_index_insert(ser->tmp, zv);

		switch (Z_TYPE_P(zv)) {
		case IS_STRING:
			ION_CHECK(ion_writer_write_string(ser->writer, ion_string_from_zend(&is, Z_STR_P(zv))));
			break;

		case IS_ARRAY:
			php_ion_serialize_array(ser, Z_ARRVAL_P(zv));
			break;

		case IS_OBJECT:
			php_ion_serialize_object(ser, Z_OBJ_P(zv));
			break;

		case IS_REFERENCE:
			ION_CHECK(ion_writer_add_annotation(ser->writer, ion_string_from_cstr(&is, ZEND_STRL("R"))));
			php_ion_serialize_zval(ser, Z_REFVAL_P(zv));
			break;
		}
	}
}

static inline void php_ion_serialize_zval(php_ion_serializer *ser, zval *zv)
{
	OBJ_CHECK(ser);

	switch (Z_TYPE_P(zv)) {
	case IS_NULL:
		ION_CHECK(ion_writer_write_null(ser->writer));
		break;
	case IS_TRUE:
		ION_CHECK(ion_writer_write_bool(ser->writer, TRUE));
		break;
	case IS_FALSE:
		ION_CHECK(ion_writer_write_bool(ser->writer, FALSE));
		break;
	case IS_LONG:
		ION_CHECK(ion_writer_write_int64(ser->writer, Z_LVAL_P(zv)));
		break;
	case IS_DOUBLE:
		ION_CHECK(ion_writer_write_double(ser->writer, Z_DVAL_P(zv)));
		break;
	case IS_STRING:
	case IS_ARRAY:
	case IS_OBJECT:
	case IS_REFERENCE:
		php_ion_serialize_refcounted(ser, zv);
		break;
	default:
		zend_throw_exception_ex(spl_ce_InvalidArgumentException, IERR_INVALID_ARG,
				"Failed to serialize value of type %s", zend_zval_type_name(zv));
	}
}

php_ion_decl(serializer_php, Serializer_PHP, php_ion_serializer_php_dtor(obj));

void php_ion_serialize(php_ion_serializer *ser, zval *zv, zval *return_value)
{
	zend_object *zo_opt = NULL, *zo_ser = NULL;

	if (!ser) {
		zo_ser = create_ion_Serializer_PHP(NULL);
		php_ion_serializer_php *o_ser = php_ion_obj(serializer_php, zo_ser);
		PTR_CHECK(o_ser);
		php_ion_serializer_php_ctor(o_ser);
		ION_CATCH();
		ser = &o_ser->serializer;
	}

	zend_object *zo_writer = create_ion_Writer_Writer(ce_Writer_Buffer_Writer);
	php_ion_writer *writer = php_ion_obj(writer, zo_writer);
	writer->type = BUFFER_WRITER;

	if (ser->options) {
		zo_opt = writer->opt = create_ion_Writer_Options(NULL);
		php_ion_obj(writer_options, writer->opt)->opt = *ser->options;
	}

	php_ion_writer_ctor(writer);
	ser->writer = writer->writer;
	ser->buffer = &writer->buffer.str;

	/* start off with a global PHP annotation instead of repeating it all over the place */
	if (0 == php_ion_globals_serializer_step()) {
		ION_STRING is;
		ION_CHECK(ion_writer_add_annotation(ser->writer, ion_string_from_cstr(&is, ZEND_STRL("PHP"))),
				if (zo_ser) OBJ_RELEASE(zo_ser));
	}
	php_ion_serialize_zval(ser, zv);
	php_ion_globals_serializer_exit();

	/* make sure to flush when done, else str.s might not contain everything until the writer is closed */
	ion_writer_flush(ser->writer, NULL);
	RETVAL_STR_COPY(ser->buffer->s);

	OBJ_RELEASE(zo_writer);
	if (zo_opt) {
		OBJ_RELEASE(zo_opt);
	}
	if (zo_ser) {
		OBJ_RELEASE(zo_ser);
	}
}

typedef struct php_ion_unserializer_php {
	php_ion_unserializer unserializer;
	zend_object *opt, std;
} php_ion_unserializer_php;

static inline void php_ion_unserializer_php_ctor(php_ion_unserializer_php *ser_obj)
{
	php_ion_unserializer *global_ser = &php_ion_globals.unserializer;
	ser_obj->unserializer.ids = global_ser->ids;
	ser_obj->unserializer.tmp = global_ser->tmp;
	ser_obj->unserializer.addref = global_ser->addref;

	zend_update_property_bool(ser_obj->std.ce, &ser_obj->std, ZEND_STRL("callMagicSerialize"),
			ser_obj->unserializer.call_magic);
	if (ser_obj->unserializer.call_custom) {
		zend_update_property_str(ser_obj->std.ce, &ser_obj->std, ZEND_STRL("callCustomSerialize"),
				ser_obj->unserializer.call_custom);
		ser_obj->unserializer.call_custom = zend_string_tolower(ser_obj->unserializer.call_custom);
	} else {
		zend_update_property_null(ser_obj->std.ce, &ser_obj->std, ZEND_STRL("callCustomSerialize"));
	}
	if (ser_obj->opt) {
		php_ion_reader_options *o_roptions = php_ion_obj(reader_options, ser_obj->opt);
		ser_obj->unserializer.options = &o_roptions->opt;
		update_property_obj(&ser_obj->std, ZEND_STRL("readerOptions"), ser_obj->opt);
	} else {
		zend_update_property_null(ser_obj->std.ce, &ser_obj->std, ZEND_STRL("readerOptions"));
	}
}

static inline void php_ion_unserializer_php_dtor(php_ion_unserializer_php *obj)
{
	if (obj->unserializer.call_custom) {
		zend_string_release(obj->unserializer.call_custom);
	}
}

static inline void php_ion_unserialize_zval(php_ion_unserializer *ser, zval *return_value, ION_TYPE *typ);

static inline bool can_call_magic_unserialize(php_ion_unserializer *ser, zend_class_entry *ce)
{
	return (ce->__unserialize && ser->call_magic);
}

static inline bool can_call_iface_unserialize(php_ion_unserializer *ser, zend_class_entry *ce)
{
	return !!ce->unserialize;
}

static inline bool can_call_custom_unserialize(php_ion_unserializer *ser, zend_object *zobject, zend_function **fn)
{
	if (ser->call_custom) {
		return !!(*fn = zend_hash_find_ptr(&zobject->ce->function_table, ser->call_custom));
	}
	return false;
}

static inline zval *php_ion_unserialize_class(php_ion_unserializer *ser, zend_string *class_name, zval *return_value)
{
	zend_class_entry *ce = zend_lookup_class(class_name);

	if (ce) {
		object_init_ex(return_value, ce);
		return zend_hash_next_index_insert(ser->ids, return_value);
	}

	zend_throw_exception_ex(spl_ce_RuntimeException, IERR_IMPORT_NOT_FOUND,
			"Could not find class %s", class_name->val);
	return NULL;
}

static inline void php_ion_unserialize_object_iface(php_ion_unserializer *ser, zend_string *class_name, zval *return_value)
{
	// this string is already in the unserializer's tmp hash
	ZEND_ASSERT(Z_TYPE_P(return_value) == IS_STRING);
	zend_string *s = Z_STR_P(return_value);

	zval *backref = php_ion_unserialize_class(ser, class_name, return_value);
	ION_CATCH();

	zend_class_entry *ce = Z_OBJCE_P(return_value);
	if (can_call_iface_unserialize(ser, ce)) {
		if (SUCCESS == ce->unserialize(backref, ce, (BYTE *) s->val, s->len, NULL)) {
			// remove all this Serializable crap in PHP-9
			zval_ptr_dtor(return_value);
			ZVAL_COPY_VALUE(return_value, backref);
		} else if (!EG(exception)) {
			zend_throw_exception_ex(spl_ce_UnexpectedValueException, IERR_INTERNAL_ERROR,
					"Failed to unserialize class %s", ce->name->val);
		}
	} else {
		zend_throw_exception_ex(spl_ce_RuntimeException, IERR_INVALID_TOKEN,
				"Class %s does not implement Serializable", class_name->val);
	}
}

static inline void php_ion_unserialize_hash(php_ion_unserializer *ser, zval *return_value)
{
	zend_hash_next_index_insert(ser->ids, return_value);

	ION_CHECK(ion_reader_step_in(ser->reader));

	while (true) {
		ION_TYPE typ;
		ION_CHECK(ion_reader_next(ser->reader, &typ));

		ION_STRING name;
		ION_CHECK(ion_reader_get_field_name(ser->reader, &name));
		zend_string *key = zend_string_from_ion(&name);

		zval zvalue;
		php_ion_unserialize_zval(ser, &zvalue, &typ);
		ION_CATCH(zend_string_release(key));

		if (typ == tid_EOF) {
			zend_string_release(key);
			break;
		}

		zend_symtable_update(HASH_OF(return_value), key, &zvalue);
		zend_string_release(key);
	}

	ION_CHECK(ion_reader_step_out(ser->reader));
}

static inline void verify_unserializer(php_ion_unserializer *ser, uint8_t object_type,
		zend_string *class_name, zend_object *zobject, zend_function **fn)
{
	switch (object_type) {
	case 'C':
		if (!can_call_custom_unserialize(ser, zobject, fn)) {
			zend_throw_exception_ex(spl_ce_RuntimeException, IERR_INVALID_TOKEN,
					"Could not find custom serializer method of %s", class_name->val);
		}
		break;

	case 'O':
		if (!can_call_magic_unserialize(ser, zobject->ce)) {
			zend_throw_exception_ex(spl_ce_RuntimeException, IERR_INVALID_TOKEN,
					"Could not find method %s::__serialize()", class_name->val);
		}
		*fn = zobject->ce->__unserialize;
		break;

	default:
		zend_throw_exception_ex(spl_ce_RuntimeException, IERR_INVALID_TOKEN,
				"Invalid object type %c", object_type);
	}
}
static inline void php_ion_unserialize_object(php_ion_unserializer *ser, uint8_t object_type, zend_string *class_name, zval *return_value)
{
	// backup possible backref to array returned by magic/custom __serialize()
	zval zarr;
	ZVAL_COPY_VALUE(&zarr, return_value);
	zend_hash_next_index_insert(ser->tmp, &zarr);

	php_ion_unserialize_class(ser, class_name, return_value);
	ION_CATCH();

	zend_object *zobject = Z_OBJ_P(return_value);
	zend_function *fn = NULL;
	verify_unserializer(ser, object_type, class_name, zobject, &fn);
	ION_CATCH();

	if (Z_TYPE(zarr) != IS_ARRAY) {
		ZEND_ASSERT(Z_TYPE(zarr) != IS_OBJECT);
		array_init(&zarr);
		zend_hash_next_index_insert(ser->tmp, &zarr);
		php_ion_unserialize_hash(ser, &zarr);
		ION_CATCH();
	}

	zval rv;
	ZVAL_NULL(&rv);
	zend_call_method_with_1_params(zobject, zobject->ce, &fn, "", &rv, &zarr);
	zval_ptr_dtor(&rv);
}

static inline void php_ion_unserialize_struct(php_ion_unserializer *ser, uint8_t object_type, zend_string *class_name, zval *return_value)
{
	if (class_name) {
		php_ion_unserialize_object(ser, object_type, class_name, return_value);
	} else if (!object_type) {
		array_init(return_value);
		php_ion_unserialize_hash(ser, return_value);
	} else if (object_type == 'o') {
		object_init(return_value);
		php_ion_unserialize_hash(ser, return_value);
	} else {
		zend_throw_exception_ex(spl_ce_RuntimeException, IERR_INVALID_TOKEN,
				"Invalid object type %c", object_type);
	}
}

static inline void php_ion_unserialize_list(php_ion_unserializer *ser, zval *return_value)
{
	ION_CHECK(ion_reader_step_in(ser->reader));
	array_init(return_value);
	zend_hash_next_index_insert(ser->ids, return_value);

	while (true) {
		ION_TYPE typ;
		ION_CHECK(ion_reader_next(ser->reader, &typ));

		zval next;
		php_ion_unserialize_zval(ser, &next, &typ);
		ION_CATCH();

		if (typ == tid_EOF) {
			break;
		}

		zend_hash_next_index_insert(Z_ARRVAL_P(return_value), &next);
	}

	ION_CHECK(ion_reader_step_out(ser->reader));
}

static inline void php_ion_reader_read_lob(ION_READER *reader, zval *return_value)
{
	zend_string *zstr = zend_string_alloc(0x1000, 0);
again:
	SIZE read = 0;
	iERR err = ion_reader_read_lob_bytes(reader, (BYTE *) zstr->val, zstr->len, &read);
	if (err == IERR_BUFFER_TOO_SMALL) {
		zstr = zend_string_extend(zstr, zstr->len << 2, 0);
		goto again;
	}
	ION_CHECK(err, zend_string_release(zstr));
	if (zstr->len > read) {
		zstr = zend_string_truncate(zstr, read, 0);
	}
	RETURN_STR(zstr);
}

static inline void php_ion_reader_read_timestamp(ION_READER *reader, ION_READER_OPTIONS *opt, zval *return_value)
{
	ION_TIMESTAMP ts;
	ION_CHECK(ion_reader_read_timestamp(reader, &ts));

	object_init_ex(return_value, ce_Timestamp);
	php_ion_timestamp *ts_obj = php_ion_obj(timestamp, Z_OBJ_P(return_value));

	zend_string *fmt = NULL;
	decContext *ctx = opt ? opt->decimal_context : NULL;
	ts_obj->time = php_time_from_ion(&ts, ctx, &fmt);
	php_ion_timestamp_ctor(ts_obj, ts.precision, fmt, NULL, NULL);
	zend_string_release(fmt);

	OBJ_CHECK(ts_obj);
}

static inline void php_ion_reader_read_int(ION_READER *reader, zval *return_value)
{
	ION_INT *num = NULL;
	ION_CHECK(ion_int_alloc(reader, &num));
	ION_CHECK(ion_reader_read_ion_int(reader, num));

	// TODO: SIZEOF_ZEND_LONG == 4
	int64_t i64;
	iERR err = ion_int_to_int64(num, &i64);
	switch (err) {
	case IERR_OK:
		RETVAL_LONG(i64);
		goto done;

	case IERR_NUMERIC_OVERFLOW:
		SIZE max, len;
		ION_CHECK(ion_int_char_length(num, &max));
		zend_string *zs = zend_string_alloc(max-1, 0);

		err = ion_int_to_char(num, (BYTE *) zs->val, max, &len);
		ZEND_ASSERT(len == zs->len);
		RETVAL_STR(zs);
		/* fall through */

	default:
	done:
		ion_int_free(num);
		ION_CHECK(err);
	}
}

static inline void php_ion_unserialize_backref(php_ion_unserializer *ser, zval *return_value)
{
	zval *backref = zend_hash_index_find(ser->ids, Z_LVAL_P(return_value));

	if (backref) {
		ZVAL_COPY_VALUE(return_value, backref);
		zend_hash_next_index_insert(ser->addref, return_value);
	} else {
		zend_throw_exception_ex(spl_ce_RuntimeException, IERR_INTERNAL_ERROR,
				"Could not find backref %ld", Z_LVAL_P(return_value));
	}
}

static inline void php_ion_unserialize_zval(php_ion_unserializer *ser, zval *return_value, ION_TYPE *typ)
{
	ION_TYPE typ_tmp;
	if (!typ) {
		typ = &typ_tmp;
		ION_CHECK(ion_reader_next(ser->reader, typ));
	}

	// process any annotations
	bool backref = false;
	uint8_t object_type = 0;
	zend_string *object_class = NULL;
	int32_t ann_cnt;
	ION_CHECK(ion_reader_get_annotation_count(ser->reader, &ann_cnt));
	for (int32_t i = 0; i < ann_cnt; ++i) {
		ION_STRING ann_str;
		ION_CHECK(ion_reader_get_an_annotation(ser->reader, i, &ann_str));
		switch (*ann_str.value) {
		case 'R':
			ZVAL_MAKE_REF(return_value);
			ZVAL_DEREF(return_value);
			zend_hash_next_index_insert(ser->addref, return_value);
			break;

		case 'r':
			// int
			backref = true;
			break;

		case 'E':
			// string
			object_type = *ann_str.value;
			break;

		case 'S':
			// string
		case 'O':
		case 'C':
		case 'o':
		case 'c':
			// structs
			ION_STRING class_name;
			ION_CHECK(ion_reader_get_an_annotation(ser->reader, ++i, &class_name));
			object_class = zend_string_from_ion(&class_name);
			object_type = *ann_str.value;
			break;
		}
	}

	BOOL bval;
	ION_CHECK(ion_reader_is_null(ser->reader, &bval));
	if (bval) {
		goto read_null;
	}

	switch (ION_TYPE_INT(*typ)) {
	case tid_NULL_INT:
read_null: ;
		ION_CHECK(ion_reader_read_null(ser->reader, typ));
		RETURN_NULL();

	case tid_BOOL_INT:
		ION_CHECK(ion_reader_read_bool(ser->reader, &bval));
		RETURN_BOOL(bval);

	case tid_INT_INT:
		php_ion_reader_read_int(ser->reader, return_value);
		if (backref) {
			ION_CATCH();
			php_ion_unserialize_backref(ser, return_value);
			switch (object_type) {
			case 0:
				break;
			case 'S':
			case 'E':
				ION_CATCH();
				goto from_backref_to_string;
			case 'c':
			case 'C':
			case 'o':
			case 'O':
				ION_CATCH();
				goto from_backref_to_struct;
			default:
				ZEND_ASSERT(0);
			}
		}
		return;

	case tid_FLOAT_INT:
		double d;
		ION_CHECK(ion_reader_read_double(ser->reader, &d));
		RETURN_DOUBLE(d);

	case tid_DECIMAL_INT:
		object_init_ex(return_value, ce_Decimal);
		php_ion_decimal *dec = php_ion_obj(decimal, Z_OBJ_P(return_value));
		ION_CHECK(ion_reader_read_ion_decimal(ser->reader, &dec->dec));
		php_ion_decimal_ctor(dec);
		zend_hash_next_index_insert(ser->ids, return_value);
		return;

	case tid_TIMESTAMP_INT:
		php_ion_reader_read_timestamp(ser->reader, ser->options, return_value);
		zend_hash_next_index_insert(ser->ids, return_value);
		return;

	case tid_SYMBOL_INT:
		ION_SYMBOL sym;
		ION_CHECK(ion_reader_read_ion_symbol(ser->reader, &sym));
		php_ion_symbol_zval(&sym, return_value);
		zend_hash_next_index_insert(ser->ids, return_value);
		return;

	case tid_STRING_INT:
		ION_STRING str;
		ION_CHECK(ion_reader_read_string(ser->reader, &str));
		RETVAL_STRINGL((char *) str.value, str.length);
		if (object_type) {
from_backref_to_string: ;
			zend_hash_next_index_insert(ser->tmp, return_value);
			switch (object_type) {
			case 'S':
				php_ion_unserialize_object_iface(ser, object_class, return_value);
				zend_string_release(object_class);
				return;
			case 'E':
				// TODO
				return;
			default:
				ZEND_ASSERT(0);
			}
		}
		zend_hash_next_index_insert(ser->ids, return_value);
		return;

	case tid_CLOB_INT:
	case tid_BLOB_INT:
		php_ion_reader_read_lob(ser->reader, return_value);
		zend_hash_next_index_insert(ser->ids, return_value);
		return;

	case tid_LIST_INT:
	case tid_SEXP_INT: // FIXME
		php_ion_unserialize_list(ser, return_value);
		if (!object_type) {
			return;
		}
		/* fall through */

	case tid_STRUCT_INT:
from_backref_to_struct: ;
		php_ion_unserialize_struct(ser, object_type, object_class, return_value);
		if (object_class) {
			zend_string_release(object_class);
		}
		return;

	case tid_none_INT:
		ZEND_ASSERT(0);
		break;

	case tid_DATAGRAM_INT:
		ZEND_ASSERT(!"datagram");
	case tid_EOF_INT:
		return;
	}
}

php_ion_decl(unserializer_php, Unserializer_PHP, php_ion_unserializer_php_dtor(obj));

void php_ion_unserialize(php_ion_unserializer *ser, zval *zdata, zval *return_value)
{
	zend_object *zo_opt = NULL, *zo_ser = NULL;

	if (!ser) {
		zo_ser = create_ion_Unserializer_PHP(NULL);
		php_ion_unserializer_php *o_ser = php_ion_obj(unserializer_php, zo_ser);
		PTR_CHECK(o_ser);
		php_ion_unserializer_php_ctor(o_ser);
		ION_CATCH();
		ser = &o_ser->unserializer;
	}

	zend_object *zo_reader;
	php_ion_reader *reader;
	ZVAL_DEREF(zdata);
	switch (Z_TYPE_P(zdata)) {
	case IS_STRING:
		zo_reader = create_ion_Reader_Reader(ce_Reader_Buffer_Reader);
		reader = php_ion_obj(reader, zo_reader);
		reader->type = BUFFER_READER;
		reader->buffer = zend_string_copy(Z_STR_P(zdata));
		break;

	case IS_RESOURCE:
		zo_reader = create_ion_Reader_Reader(ce_Reader_Stream_Reader);
		reader = php_ion_obj(reader, zo_reader);
		reader->type = STREAM_READER;
		php_stream_from_zval_no_verify(reader->stream.ptr, zdata);
		break;

	default:
		ZEND_ASSERT(!IS_STRING && !IS_RESOURCE);
	}

	if (ser->options) {
		zo_opt = reader->opt = create_ion_Reader_Options(NULL);
		php_ion_obj(reader_options, reader->opt)->opt = *ser->options;
	}

	php_ion_reader_ctor(reader);
	ser->reader = reader->reader;

	php_ion_globals_unserializer_step();
	php_ion_unserialize_zval(ser, return_value, NULL);
	php_ion_globals_unserializer_exit();

	OBJ_RELEASE(zo_reader);
	if (zo_opt)  {
		OBJ_RELEASE(zo_opt);
	}
	if (zo_ser) {
		OBJ_RELEASE(zo_ser);
	}
}
