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

#include "php.h"
#include "ext/standard/php_var.h"
#include "ext/date/php_date.h"

#define DECNUMDIGITS 34 /* DECQUAD_Pmax */
#include "ionc/ion.h"

#define PHP_ION_SYMBOL_TABLE_VERSION 1
#define PHP_ION_SYMBOL(c, s) { \
	{ \
		0, \
		{ sizeof(s)-1, (BYTE *) s }, \
		{ { 0, NULL }, 0 }, \
		0 \
	}, \
	{ sizeof(c)-1, (BYTE *) c } \
},

typedef struct php_ion_global_symbol {
	ION_SYMBOL s;
	ION_STRING e;
} php_ion_global_symbol;

static php_ion_global_symbol g_sym_tab_php_sym[] = {
#define PHP_ION_SYMBOL_PHP				(g_sym_tab_php_sym[0]).s
	PHP_ION_SYMBOL("PHP",			"PHP")
#define PHP_ION_SYMBOL_REFERENCE		(g_sym_tab_php_sym[1]).s
	PHP_ION_SYMBOL("Reference",		"R")
#define PHP_ION_SYMBOL_BACKREF			(g_sym_tab_php_sym[2]).s
	PHP_ION_SYMBOL("Backref",		"r")
#define PHP_ION_SYMBOL_PROPERTY			(g_sym_tab_php_sym[3]).s
	PHP_ION_SYMBOL("Property",		"p")
#define PHP_ION_SYMBOL_CLASS_OBJECT		(g_sym_tab_php_sym[4]).s
	PHP_ION_SYMBOL("ClassObject",	"c")
#define PHP_ION_SYMBOL_CUSTOM_OBJECT	(g_sym_tab_php_sym[5]).s
	PHP_ION_SYMBOL("CustomObject",	"C")
#define PHP_ION_SYMBOL_OBJECT			(g_sym_tab_php_sym[6]).s
	PHP_ION_SYMBOL("Object",		"o")
#define PHP_ION_SYMBOL_MAGIC_OBJECT		(g_sym_tab_php_sym[7]).s
	PHP_ION_SYMBOL("MagicObject",	"O")
#define PHP_ION_SYMBOL_SERIALIZEABLE	(g_sym_tab_php_sym[8]).s
	PHP_ION_SYMBOL("Serializable",	"S")
#define PHP_ION_SYMBOL_ENUM				(g_sym_tab_php_sym[9]).s
	PHP_ION_SYMBOL("Enum", "E")
	{{0}, {0}}
};
#undef PHP_ION_SYMBOL

static ION_SYMBOL_TABLE *g_sym_tab_php;

/* [SID => STRING, STRING => SID] */
static HashTable g_sym_hash;
/* [enum_case_name => SID] */
static HashTable g_sym_map;

#define ION_SYS_SYMBOL_SYMBOL_TABLE \
	ION_SYS_SYMBOL_ION_SYMBOL_TABLE
#define g_sym_add(enum_name, c_name) do { \
	g_sym_hash_add(ION_SYS_SID_ ## c_name, ION_SYS_SYMBOL_ ## c_name, ION_SYS_STRLEN_ ## c_name); \
	g_sym_map_add(ION_SYS_SID_ ## c_name, enum_name, sizeof(enum_name)-1); \
} while (0)

static void g_sym_hash_add(int sid, const char *str, size_t len)
{
	zval zl, zs;
	ZVAL_LONG(&zl, sid);
	ZVAL_STR(&zs, zend_string_init_interned(str, len ,1));
	zend_hash_add(&g_sym_hash, Z_STR(zs), &zl);
	zend_hash_index_add(&g_sym_hash, sid, &zs);
}

static void g_sym_map_add(int sid, const char *str, size_t len)
{
	zval zv;
	ZVAL_LONG(&zv, sid);
	zend_hash_str_add(&g_sym_map, str, len, &zv);
}

static void g_sym_dtor(void)
{
	ion_symbol_table_close(g_sym_tab_php);
	zend_hash_destroy(&g_sym_map);
	zend_hash_destroy(&g_sym_hash);
}

static int g_sym_init(void)
{
	zend_hash_init(&g_sym_hash, 0, NULL, NULL, 1);
	zend_hash_init(&g_sym_map, 0, NULL, NULL, 1);

	g_sym_hash_add(0, ZEND_STRL(""));
	g_sym_map_add(0, ZEND_STRL(""));
	g_sym_add("Ion", ION);
	g_sym_add("Ivm_1_0", IVM);
	g_sym_add("IonSymbolTable", SYMBOL_TABLE);
	g_sym_add("Name", NAME);
	g_sym_add("Version", VERSION);
	g_sym_add("Imports", IMPORTS);
	g_sym_add("Symbols", SYMBOLS);
	g_sym_add("MaxId", MAX_ID);
	g_sym_add("SharedSymbolTable", SHARED_SYMBOL_TABLE);

	int sys_max_id = ION_SYS_SID_SHARED_SYMBOL_TABLE;

	if (IERR_OK != ion_symbol_table_open_with_type(&g_sym_tab_php, NULL, ist_SHARED)) {
		return FAILURE;
	}
	php_ion_global_symbol *ptr = g_sym_tab_php_sym;
	ion_symbol_table_set_version(g_sym_tab_php, PHP_ION_SYMBOL_TABLE_VERSION);
	ion_symbol_table_set_name(g_sym_tab_php, &ptr->s.value);
	while (ptr->e.value) {
		ion_symbol_table_add_symbol(g_sym_tab_php, &ptr->s.value, &ptr->s.sid);
		g_sym_hash_add(sys_max_id + ptr->s.sid, (const char *) ptr->s.value.value, ptr->s.value.length);
		g_sym_map_add(sys_max_id + ptr->s.sid, (const char *) ptr->e.value, ptr->e.length);
		++ptr;
	}
	ion_symbol_table_lock(g_sym_tab_php);
	return SUCCESS;
}

static struct {
	zend_string *Year, *Month, *Day, *Min, *Sec, *Frac, *MinTZ, *SecTZ, *FracTZ;
} g_intern_str;

static void g_intern_str_init()
{
#define NEW_INTERN_STR(s) \
	g_intern_str.s = zend_string_init_interned(#s, sizeof(#s)-1, 1)
	NEW_INTERN_STR(Year);
	NEW_INTERN_STR(Month);
	NEW_INTERN_STR(Day);
	NEW_INTERN_STR(Min);
	NEW_INTERN_STR(Sec);
	NEW_INTERN_STR(Frac);
	NEW_INTERN_STR(MinTZ);
	NEW_INTERN_STR(SecTZ);
	NEW_INTERN_STR(FracTZ);
#undef NEW_INTERN_STR
}

typedef struct php_ion_serializer {
	zend_string *call_custom;
	zend_bool call_magic;
	zend_bool multi_seq;

	uint32_t level;
	HashTable *ids;
	HashTable *tmp;

	zend_object *wri, std;

} php_ion_serializer;

typedef int (*php_ion_serialize_zval_cb)(void *ctx, zval *zv);

typedef struct php_ion_annotations {
	uint8_t shared_symtab:1;
	uint8_t backref:1;
	uint8_t makeref:1;
	uint8_t object_prop:1;
	uint8_t object_type;
	zend_string *object_class;
	zend_string *property_class;
} php_ion_annotations;

typedef struct php_ion_unserializer {
	zend_string *call_custom;
	zend_bool call_magic;
	zend_bool multi_seq;

	uint32_t level;
	HashTable *ids;
	HashTable *tmp;

	HashTable *addref;

	ION_TYPE type; // FIXME: there's already `php_ion_obj(reader, rdr)->state`
	php_ion_annotations annotations;
	
	zend_object *rdr, std;
	
} php_ion_unserializer;

ZEND_BEGIN_MODULE_GLOBALS(ion)

	struct {
		decContext ctx;
		ION_DECIMAL zend_max;
		ION_DECIMAL zend_min;
	} decimal;

	struct {
		HashTable cache;
	} symbol;

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

static zend_class_entry
	*ce_Catalog,
	*ce_Decimal,
	*ce_Decimal_Context,
	*ce_Decimal_Context_Rounding,
	*ce_Exception,
	*ce_LOB,
	*ce_Reader,
	*ce_Reader_Reader,
	*ce_Reader_Buffer,
	*ce_Reader_Stream,
	*ce_Reader_Buffer_Reader,
	*ce_Reader_Stream_Reader,
	*ce_Serializer,
	*ce_Serializer_Serializer,
	*ce_Symbol,
	*ce_Symbol_ImportLocation,
	*ce_Symbol_Enum,
	*ce_Symbol_Table,
	*ce_Symbol_Table_Local,
	*ce_Symbol_Table_PHP,
	*ce_Symbol_Table_Shared,
	*ce_Symbol_Table_System,
	*ce_Timestamp,
	*ce_Timestamp_Format,
	*ce_Timestamp_Precision,
	*ce_Type,
	*ce_Unserializer,
	*ce_Unserializer_Unserializer,
	*ce_Writer,
	*ce_Writer_Buffer,
	*ce_Writer_Buffer_Writer,
	*ce_Writer_Stream,
	*ce_Writer_Stream_Writer,
	*ce_Writer_Writer
	;

static void php_ion_globals_symbols_init(void)
{
	zend_hash_init(&php_ion_globals.symbol.cache, 0, NULL, ZVAL_PTR_DTOR, 0);
}

static void php_ion_globals_symbols_dtor(void)
{
	zend_hash_destroy(&php_ion_globals.symbol.cache);
}

static void php_ion_globals_serializer_init(void)
{
	php_ion_serializer *s = &php_ion_globals.serializer;
	HashTable *h = php_ion_globals._ht.serializer;

	zend_hash_init(s->tmp = &h[0], 0, NULL, ZVAL_PTR_DTOR, 0);
	zend_hash_init(s->ids = &h[1], 0, NULL, NULL, 0);
}

static uint32_t php_ion_globals_serializer_step(void)
{
	php_ion_serializer *s = &php_ion_globals.serializer;
	uint32_t level;

	if (!(level = s->level++)) {
		zend_hash_clean(s->ids);
		zend_hash_clean(s->tmp);
	}
	return level;
}

static uint32_t php_ion_globals_serializer_exit(void)
{
	php_ion_serializer *s = &php_ion_globals.serializer;

	ZEND_ASSERT(s->level);
	if (!--s->level) {
		zend_hash_clean(s->ids);
		zend_hash_clean(s->tmp);
	}
	return s->level;
}

static void php_ion_globals_serializer_dtor(void)
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
static void php_ion_globals_unserializer_init(void)
{
	php_ion_unserializer *s = &php_ion_globals.unserializer;
	HashTable *h = php_ion_globals._ht.unserializer;

	zend_hash_init(s->tmp = &h[0], 0, NULL, ZVAL_PTR_DTOR, 0);
	zend_hash_init(s->ids = &h[1], 0, NULL, NULL, 0);
	zend_hash_init(s->addref = &h[2], 0, NULL, ZVAL_ADDREF, 0);
}

static void php_ion_globals_unserializer_step(void)
{
	php_ion_unserializer *s = &php_ion_globals.unserializer;

	if (!s->level++) {
		zend_hash_clean(s->addref);
		zend_hash_clean(s->ids);
		zend_hash_clean(s->tmp);
	}
}

static void php_ion_globals_unserializer_exit(void)
{
	php_ion_unserializer *s = &php_ion_globals.unserializer;

	ZEND_ASSERT(s->level);
	if (!--s->level) {
		zend_hash_clean(s->addref);
		zend_hash_clean(s->ids);
		zend_hash_clean(s->tmp);
	}
}

static void php_ion_globals_unserializer_dtor(void)
{
	php_ion_unserializer *s = &php_ion_globals.unserializer;

	zend_hash_destroy(s->addref);
	zend_hash_destroy(s->ids);
	zend_hash_destroy(s->tmp);
}

#define php_ion_obj(type, zo) \
	((php_ion_ ##type *) php_ion_obj_ex(zo, XtOffsetOf(php_ion_ ## type, std)))
static void *php_ion_obj_ex(void *obj, ptrdiff_t offset) {
	if (obj) {
		return ((char *) obj) - offset;
	}
	return NULL;
}

#define php_ion_decl_noclone(type, cname) \
	static zend_object_handlers oh_ ## cname; \
	static zend_object *create_ion_ ## cname(zend_class_entry *ce) \
	{ \
		if (!ce) ce = ce_ ## cname; \
		php_ion_ ## type *o = ecalloc(1, sizeof(*o) + zend_object_properties_size(ce)); \
		zend_object_std_init(&o->std, ce); \
		object_properties_init(&o->std, ce); \
		o->std.handlers = &oh_ ## cname; \
		return &o->std; \
	} \
	static void free_ion_ ## cname(zend_object *std) \
	{ \
		php_ion_ ## type *obj = php_ion_obj(type, std); \
		php_ion_ ## type ## _dtor(obj); \
		zend_object_std_dtor(std); \
	}
#define php_ion_decl(type, cname) \
    php_ion_decl_noclone(type, cname) \
	static zend_object *clone_ion_ ## cname(zend_object *std) \
	{ \
		php_ion_ ## type *old_obj = php_ion_obj(type, std), \
						 *new_obj = php_ion_obj(type, create_ion_ ## cname(std->ce)); \
		php_ion_ ## type ## _copy(new_obj, old_obj); \
		(void) old_obj; \
		return &new_obj->std; \
	}
#define php_ion_register(type, cname, ...) do { \
	ce_ ## cname = register_class_ion_ ## cname(__VA_ARGS__); \
	ce_ ## cname ->create_object = create_ion_ ## cname; \
	memcpy(&oh_ ## cname, zend_get_std_object_handlers(), sizeof(zend_object_handlers)); \
	oh_ ## cname .offset = offsetof(php_ion_ ## type, std); \
	oh_ ## cname .free_obj = free_ion_ ## cname; \
	oh_ ## cname .clone_obj = clone_ion_ ## cname; \
} while (0)

#define ION_CHECK_RETURN(r, err, ...) do { \
	iERR __err = err; \
	if (UNEXPECTED(__err)) { \
		zend_throw_exception_ex(ce_Exception, __err, "%s: %s", ion_error_to_str(__err), #err); \
		__VA_ARGS__; \
		return r; \
	} \
} while (0)

#define ION_CHECK(err, ...) \
	ION_CHECK_RETURN(, err, __VA_ARGS__)

#define ION_CATCH_RETURN(ret, ...) do { \
	if (UNEXPECTED(EG(exception))) { \
		__VA_ARGS__; \
		return ret; \
	} \
} while (0)

#define ION_CATCH(...) \
	ION_CATCH_RETURN(, __VA_ARGS__)

#define PTR_CHECK_RETURN(ret, ptr, ...) do { \
	if (UNEXPECTED(!(ptr))) { \
		zend_throw_error(NULL, "Uninitialized object"); \
		__VA_ARGS__; \
		return ret; \
	} \
} while (0)
#define PTR_CHECK(ptr, ...) PTR_CHECK_RETURN(, ptr, __VA_ARGS__)

#define OBJ_CHECK_RETURN(ret, obj, ...) do { \
	PTR_CHECK_RETURN(ret, obj, __VA_ARGS__); \
	PTR_CHECK_RETURN(ret, *((void **)obj), __VA_ARGS__); \
} while (0)
#define OBJ_CHECK(obj, ...) OBJ_CHECK_RETURN(, obj, __VA_ARGS__)

static ION_STRING *ion_string_from_zend(ION_STRING *is, const zend_string *zs)
{
	is->length = zs ? (SIZE) zs->len : 0;
	is->value = (BYTE *) (zs ? zs->val : NULL);
	return is;
}

static zend_string *zend_string_from_ion(const ION_STRING *s)
{
	return zend_string_init((const char *) s->value, s->length, 0);
}

static void call_constructor(zend_object *zo, uint32_t argc, zval *argv, zend_array *args_named)
{
	zend_call_known_function(zo->ce->constructor, zo, zo->ce, NULL, argc, argv, args_named);
}

static zend_object *object_construct(zend_class_entry *ce, uint32_t argc, zval *argv, zend_array *args_named)
{
	zval z_obj;
	object_init_ex(&z_obj, ce);
	call_constructor(Z_OBJ(z_obj), argc, argv, args_named);
	return Z_OBJ(z_obj);
}

static void update_property_obj_ex(zend_class_entry *scope, zend_object *obj, const char *n, size_t l, zend_object *p)
{
	zval zobj;
	ZVAL_OBJ(&zobj, p);
	zend_update_property(scope, obj, n, l, &zobj);
}
static void update_property_obj(zend_object *obj, const char *n, size_t l, zend_object *p)
{
	update_property_obj_ex(obj->ce, obj, n, l, p);
}

#define RETURN_IONTYPE(typ) do { \
	zend_object *__zo = php_ion_type_fetch(typ); \
	if (UNEXPECTED(!__zo)) { \
		RETURN_THROWS(); \
	} \
	RETURN_OBJ_COPY(__zo); \
} while(0)

static zend_object *php_ion_type_fetch(ION_TYPE typ)
{
	zend_long index = ION_TYPE_INT(typ);
	zval *ztype = zend_hash_index_find(ce_Type->backed_enum_table, index);

	if (UNEXPECTED(!ztype || Z_TYPE_P(ztype) != IS_STRING)) {
		zend_value_error(ZEND_LONG_FMT " is not a valid backing value for enum \"%s\"", index, ZSTR_VAL(ce_Type->name));
		return NULL;
	}
	return zend_enum_get_case(ce_Type, Z_STR_P(ztype));
}

static ION_TYPE ion_type_from_enum(zend_object *zo)
{
	return (ION_TYPE) Z_LVAL_P(zend_enum_fetch_case_value(zo));
}

typedef struct php_ion_symbol_iloc {
	ION_SYMBOL_IMPORT_LOCATION loc;
	zend_string *name;
	zend_object std;
} php_ion_symbol_iloc;

static void php_ion_symbol_iloc_ctor(php_ion_symbol_iloc *obj)
{
	zend_update_property_long(ce_Symbol_ImportLocation, &obj->std, ZEND_STRL("location"), obj->loc.location);
	zend_update_property_str(ce_Symbol_ImportLocation, &obj->std, ZEND_STRL("name"), obj->name);
	ion_string_from_zend(&obj->loc.name, obj->name);
}

static void php_ion_symbol_iloc_dtor(php_ion_symbol_iloc *obj)
{
	zend_string_release(obj->name);
}

static void php_ion_symbol_iloc_copy(php_ion_symbol_iloc *new_obj, php_ion_symbol_iloc *old_obj)
{
	zend_objects_clone_members(&new_obj->std, &old_obj->std);
	new_obj->name = zend_string_copy(old_obj->name);
	ion_string_from_zend(&new_obj->loc.name, new_obj->name);
	new_obj->loc.location = old_obj->loc.location;
}

php_ion_decl(symbol_iloc, Symbol_ImportLocation);

typedef struct php_ion_symbol {
	ION_SYMBOL sym;
	zend_string *value;
	zend_object *iloc, std;
} php_ion_symbol;

static int php_ion_symbol_zval_compare(zval *zv1, zval *zv2) {
	zend_string *zs1 = zval_get_string(zv1);
	zend_string *zs2 = zval_get_string(zv2);

	if (EG(exception)) {
		return 0;
	}

	int result;
	if (zs1->len > zs2->len) {
		result = 1;
	} else if (zs2->len > zs1->len) {
		result = -1;
	} else {
		result = memcmp(zs1->val, zs2->val, zs1->len);
	}
	zend_string_release(zs1);
	zend_string_release(zs2);
	return result;
}

static void php_ion_symbol_ctor(php_ion_symbol *obj)
{
	zend_update_property_long(ce_Symbol, &obj->std, ZEND_STRL("sid"),
		obj->sym.sid);
	if (obj->value) {
		zend_update_property_str(ce_Symbol, &obj->std, ZEND_STRL("value"), obj->value);
	} else{
		zend_update_property_null(ce_Symbol, &obj->std, ZEND_STRL("value"));
	}
	ion_string_from_zend(&obj->sym.value, obj->value);
	if (obj->iloc) {
		update_property_obj(&obj->std, ZEND_STRL("importLocation"), obj->iloc);
		obj->sym.import_location = php_ion_obj(symbol_iloc, obj->iloc)->loc;
	} else {
		zend_update_property_null(ce_Symbol, &obj->std, ZEND_STRL("importLocation"));
	}
}

static void php_ion_symbol_dtor(php_ion_symbol *obj)
{
	if (obj->value) {
		zend_string_release(obj->value);
	}
}

static void php_ion_symbol_copy(php_ion_symbol *new_obj, php_ion_symbol *old_obj)
{
	zend_objects_clone_members(&new_obj->std, &old_obj->std);
	new_obj->sym = old_obj->sym;
	if (old_obj->value) {
		new_obj->value = zend_string_copy(old_obj->value);
		ion_string_from_zend(&new_obj->sym.value, new_obj->value);
	}

	if ((new_obj->iloc = old_obj->iloc)) {
		new_obj->sym.import_location = php_ion_obj(symbol_iloc, new_obj->iloc)->loc;
	}
}

static void php_ion_symbol_zval(ION_SYMBOL *sym_ptr, zval *return_value)
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

	if (!ION_SYMBOL_IMPORT_LOCATION_IS_NULL(sym_ptr)) {
		GC_DELREF(sym->iloc);
	}
}

static zval *php_ion_global_symbol_fetch_by_enum(zend_string *name)
{
	zval *zgs = zend_hash_find(&php_ion_globals.symbol.cache, name);
	if (!zgs) {
		zval *zid = zend_hash_find(&g_sym_map, name);
		if (zid) {
			zval *zss = zend_hash_index_find(&g_sym_hash, Z_LVAL_P(zid));
			if (zss) {
				zval zsym;
				object_init_ex(&zsym, ce_Symbol);
				php_ion_symbol *sym = php_ion_obj(symbol, Z_OBJ(zsym));
				sym->sym.sid = Z_LVAL_P(zid);
				sym->value = zval_get_string(zss);
				php_ion_symbol_ctor(sym);
				zgs = zend_hash_add(&php_ion_globals.symbol.cache, name, &zsym);
			}
		}
	}
	return zgs;
}

php_ion_decl(symbol, Symbol);

typedef struct php_ion_symbol_table {
	ION_SYMBOL_TABLE *tab;
	int (*dtor)(ION_SYMBOL_TABLE *);
	zend_object std;
} php_ion_symbol_table;

static void php_ion_symbol_table_ctor(php_ion_symbol_table *obj)
{
	OBJ_CHECK(obj);

	ION_SYMBOL_TABLE_TYPE typ = ist_EMPTY;
	ion_symbol_table_get_type(obj->tab, &typ);
	if (typ != ist_LOCAL) {
		ION_STRING is;
		if (IERR_OK == ion_symbol_table_get_name(obj->tab, &is)) {
			zend_update_property_stringl(ce_Symbol_Table_Shared, &obj->std, ZEND_STRL("name"), (char *) is.value, is.length);
		}
		int32_t iv;
		if (IERR_OK == ion_symbol_table_get_version(obj->tab, &iv)) {
			zend_update_property_long(ce_Symbol_Table_Shared, &obj->std, ZEND_STRL("version"), iv);
		}
	}
}

static void php_ion_symbol_table_dtor(php_ion_symbol_table *obj)
{
	if (obj->tab) {
		if (obj->dtor) {
			obj->dtor(obj->tab);
		}
		obj->tab = NULL;
	}
}

static void php_ion_symbol_table_copy(php_ion_symbol_table *new_obj, php_ion_symbol_table *old_obj)
{
	// do not clone cache members
	// zend_objects_clone_members(...)
	if ((new_obj->dtor = old_obj->dtor)) {
		ION_CHECK(ion_symbol_table_clone_with_owner(old_obj->tab, &new_obj->tab, NULL));
	} else {
		new_obj->tab = old_obj->tab;
	}
	// update non-cache members
	php_ion_symbol_table_ctor(new_obj);
}

static void php_ion_symbol_table_import(php_ion_symbol_table *obj, php_ion_symbol_table *import)
{
	OBJ_CHECK(obj);
	OBJ_CHECK(import);

	zval tmp;
	zval *zimports = zend_read_property(obj->std.ce, &obj->std, ZEND_STRL("imports"), 0, &tmp);
	if (zimports) {
		zend_ulong idx = (uintptr_t) &import->std.gc;
		if (!zend_hash_index_exists(Z_ARRVAL_P(zimports), idx)) {
			ION_CHECK(ion_symbol_table_import_symbol_table(obj->tab, import->tab));

			SEPARATE_ARRAY(zimports);
			GC_ADDREF(&import->std);
			add_index_object(zimports, idx, &import->std);
			zend_update_property(obj->std.ce, &obj->std, ZEND_STRL("imports"), zimports);
		}
	}
}

static void php_ion_symbol_table_symbol_zval(php_ion_symbol_table *obj, ION_SYMBOL *sym, zval *return_value)
{
	zval tmp;
	zval *zsyms = zend_read_property(obj->std.ce, &obj->std, ZEND_STRL("symbols"), 0, &tmp);
	if (zsyms) {
		zval *zsym = zend_hash_index_find(Z_ARRVAL_P(zsyms), sym->sid);
		if (zsym) {
			RETURN_COPY(zsym);
		}
	}

	php_ion_symbol_zval(sym, return_value);

	if (zsyms) {
		SEPARATE_ARRAY(zsyms);
		ZVAL_ADDREF(return_value);
		add_index_zval(zsyms, sym->sid, return_value);
	}
}

php_ion_decl(symbol_table, Symbol_Table);

typedef struct php_ion_decimal_ctx {
	decContext ctx;
	zend_object std;
} php_ion_decimal_ctx;

#define php_ion_decimal_ctx_init_max(c, rounding) \
	php_ion_decimal_ctx_init((c), DEC_MAX_DIGITS, DEC_MAX_EMAX, DEC_MIN_EMIN, (rounding), false)
static void php_ion_decimal_ctx_init(decContext *ctx,
		int digits, int emax, int emin, enum rounding round, zend_bool clamp)
{
	memset(ctx, 0, sizeof(*ctx));
	ctx->digits = digits;
	ctx->emax = emax;
	ctx->emin = emin;
	ctx->round = round;
	ctx->clamp = clamp;
}

static void php_ion_decimal_ctx_ctor(php_ion_decimal_ctx *obj, zend_object *o_round)
{
	if (!obj->ctx.digits) {
		php_ion_decimal_ctx_init_max(&obj->ctx, DEC_ROUND_HALF_EVEN);
	}
	if (o_round) {
		update_property_obj(&obj->std, ZEND_STRL("round"), o_round);
	} else {
		zend_update_property_long(obj->std.ce, &obj->std, ZEND_STRL("round"), obj->ctx.round);
	}
	zend_update_property_long(ce_Decimal_Context, &obj->std, ZEND_STRL("digits"), obj->ctx.digits);
	zend_update_property_long(ce_Decimal_Context, &obj->std, ZEND_STRL("eMax"), obj->ctx.emax);
	zend_update_property_long(ce_Decimal_Context, &obj->std, ZEND_STRL("eMin"), obj->ctx.emin);
	zend_update_property_bool(ce_Decimal_Context, &obj->std, ZEND_STRL("clamp"), obj->ctx.clamp);
}

static void php_ion_decimal_ctx_dtor(php_ion_decimal_ctx *obj)
{
}

static void php_ion_decimal_ctx_copy(php_ion_decimal_ctx *new_obj, php_ion_decimal_ctx *old_obj)
{
	zend_objects_clone_members(&new_obj->std, &old_obj->std);
	new_obj->ctx = old_obj->ctx;
}

php_ion_decl(decimal_ctx, Decimal_Context);

typedef struct php_ion_decimal {
	ION_DECIMAL dec;
	zend_object *ctx, std;
} php_ion_decimal;

static void php_ion_decimal_from_zend_long(ION_DECIMAL *dec, decContext *ctx, zend_long num)
{
	if (num <= INT32_MAX && num >= INT32_MIN) {
		ION_CHECK(ion_decimal_from_int32(dec, num));
	} else if (num > 0 && num <= UINT32_MAX) {
		ION_CHECK(ion_decimal_from_uint32(dec, num));
	} else {
		ION_INT *iint;
		ION_CHECK(ion_int_alloc(NULL, &iint));
		ION_CHECK(ion_int_from_long(iint, num),
				ion_int_free(iint));
		/* WATCH OUT: BS API */
		dec->type = ION_DECIMAL_TYPE_QUAD;
		ION_CHECK(ion_decimal_from_ion_int(dec, ctx, iint),
				ion_int_free(iint));
		ion_int_free(iint);
	}
}

static zend_string *php_ion_decimal_to_string(ION_DECIMAL *dec)
{
	zend_string *zstr = zend_string_alloc(ION_DECIMAL_STRLEN(dec), 0);
	(void) ion_decimal_to_string(dec, zstr->val);
	return zend_string_truncate(zstr, strlen(zstr->val), 0);
}

static void php_ion_decimal_to_zend_long(ION_DECIMAL *dec, decContext *ctx, zend_long *l)
{
	ION_INT *ii = NULL;
	ION_CHECK(ion_int_alloc(NULL, &ii));
	ION_CHECK(ion_decimal_to_ion_int(dec, ctx, ii), ion_int_free(ii));
	int64_t i64;
	ION_CHECK(ion_int_to_int64(ii, &i64), ion_int_free(ii));
	*l = i64;
	ion_int_free(ii);
}

static bool php_ion_decimal_fits_zend_long(php_ion_decimal *obj)
{
	int32_t result;

	if (!ion_decimal_is_integer(&obj->dec)) {
		return false;
	}

	result = 1;
	ion_decimal_compare(&obj->dec, &php_ion_globals.decimal.zend_max, &php_ion_globals.decimal.ctx, &result);
	if (result == 1) {
		return false;
	}
	result = -1;
	ion_decimal_compare(&obj->dec, &php_ion_globals.decimal.zend_min, &php_ion_globals.decimal.ctx, &result);
	if (result == -1) {
		return false;
	}
	return true;
}

static void php_ion_decimal_ctor(php_ion_decimal *obj)
{
	if (!obj->ctx) {
		zval zdc;
		object_init_ex(&zdc, ce_Decimal_Context);
		obj->ctx = Z_OBJ(zdc);
		php_ion_decimal_ctx_ctor(php_ion_obj(decimal_ctx, obj->ctx), NULL);
		GC_DELREF(obj->ctx);
	}
	update_property_obj(&obj->std, ZEND_STRL("context"), obj->ctx);

	if (php_ion_decimal_fits_zend_long(obj)) {
		zend_long l;
		php_ion_decimal_to_zend_long(&obj->dec, &php_ion_obj(decimal_ctx, obj->ctx)->ctx, &l);
		zend_update_property_long(ce_Decimal, &obj->std, ZEND_STRL("number"), l);
	} else {
		zend_string *zstr = php_ion_decimal_to_string(&obj->dec);
		zend_update_property_str(ce_Decimal, &obj->std, ZEND_STRL("number"), zstr);
		zend_string_release(zstr);
	}
}

static void php_ion_decimal_dtor(php_ion_decimal *obj)
{
	ion_decimal_free(&obj->dec);
}

static void php_ion_decimal_copy(php_ion_decimal *new_obj, php_ion_decimal *old_obj)
{
	zend_objects_clone_members(&new_obj->std, &old_obj->std);
	new_obj->ctx = old_obj->ctx;
	ION_CHECK(ion_decimal_copy(&new_obj->dec, &old_obj->dec));
}

php_ion_decl(decimal, Decimal);

typedef php_date_obj php_ion_timestamp;

static zend_long php_usec_from_ion(const decQuad *frac, decContext *ctx)
{
	if (!ctx) {
		ctx = &php_ion_globals.decimal.ctx;
	}
	decQuad microsecs, result;
	decQuadMultiply(&result, decQuadFromInt32(&microsecs, 1000000), frac, ctx);
	return (zend_long) decQuadToUInt32(&result, ctx, DEC_ROUND_HALF_EVEN);
}

static decQuad *ion_ts_frac_from_usec(decQuad *frac, int usec, decContext *ctx)
{
	if (!ctx) {
		ctx = &php_ion_globals.decimal.ctx;
	}
	decQuad microsecs, us;
 	return decQuadDivide(frac, decQuadFromInt32(&us, usec), decQuadFromInt32(&microsecs, 1000000), ctx);
}

static zend_string *php_ion_timestamp_format_fetch(zend_string *fmt_case)
{
	return Z_STR_P(zend_enum_fetch_case_value(zend_enum_get_case(ce_Timestamp_Format, fmt_case)));
}

static zend_string *php_dt_format_from_precision(uint8_t precision)
{
	switch (precision) {
	case ION_TS_FRAC | 0x80:
		return php_ion_timestamp_format_fetch(g_intern_str.FracTZ);
	case ION_TS_FRAC:
		return php_ion_timestamp_format_fetch(g_intern_str.Frac);
	case ION_TS_SEC | 0x80:
		return php_ion_timestamp_format_fetch(g_intern_str.SecTZ);
	case ION_TS_SEC:
		return php_ion_timestamp_format_fetch(g_intern_str.Sec);
	case ION_TS_MIN | 0x80:
		return php_ion_timestamp_format_fetch(g_intern_str.MinTZ);
	case ION_TS_MIN:
		return php_ion_timestamp_format_fetch(g_intern_str.Min);
	case ION_TS_DAY:
		return php_ion_timestamp_format_fetch(g_intern_str.Day);
	case ION_TS_MONTH:
		return php_ion_timestamp_format_fetch(g_intern_str.Month);
	case ION_TS_YEAR:
		return php_ion_timestamp_format_fetch(g_intern_str.Year);
	default:
		return ZSTR_CHAR('c');
	}
}

static timelib_time* php_time_from_ion(const ION_TIMESTAMP *ts, decContext *ctx, zend_string **fmt)
{
	timelib_time *time = ecalloc(1, sizeof(*time));

	/* defaults */
	time->y = 1970;
	time->m = 1;
	time->d = 1;

	switch (ts->precision & 0x7f) {
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
		if (time->z || ts->precision & 0x80) {
			time->zone_type = TIMELIB_ZONETYPE_OFFSET;
		} else {
			time->zone_type = TIMELIB_ZONETYPE_ID;
			time->tz_info = get_timezone_info();
		}
	}

	if (fmt) {
		*fmt = php_dt_format_from_precision(ts->precision);
	}
	return time;
}

static ION_TIMESTAMP *ion_timestamp_from_php(ION_TIMESTAMP *buf, php_ion_timestamp *ts, decContext *ctx)
{
	memset(buf, 0, sizeof(*buf));

	zval tmp;
	int precision = Z_LVAL_P(zend_read_property(ts->std.ce, &ts->std, ZEND_STRL("precision"), 0, &tmp));

	if (!precision || precision > (ION_TS_FRAC|0x80)) {
		zend_throw_exception_ex(ce_Exception, IERR_INVALID_ARG,
				"Invalid precision (%d) of ion\\Timestamp", precision);
	} else switch ((buf->precision = precision) & 0x7f) {
	case ION_TS_FRAC:
		ion_ts_frac_from_usec(&buf->fraction, (int) ts->time->us, ctx);
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
		buf->tz_offset = (short) (ts->time->z / 60);
		if (buf->tz_offset) {
			buf->precision |= 0x80;
		}
	}

	return buf;
}

static void php_ion_timestamp_ctor(php_ion_timestamp *obj, zend_long precision, zend_string *fmt, zend_string *dt, zval *tz)
{
	if (!obj->time) {
		php_date_initialize(obj, dt ? dt->val : "", dt ? dt->len : 0, fmt ? fmt->val : NULL, tz, PHP_DATE_INIT_CTOR);
	}
	zend_update_property_long(ce_Timestamp, &obj->std, ZEND_STRL("precision"), precision);

	fmt = php_dt_format_from_precision(precision);
	zend_update_property_str(ce_Timestamp, &obj->std, ZEND_STRL("format"), fmt);
	zend_string_release(fmt);
}

typedef struct php_ion_catalog {
	ION_CATALOG *cat;
	zend_object std;
} php_ion_catalog;

static void php_ion_catalog_ctor(php_ion_catalog *obj)
{
	ION_CHECK(ion_catalog_open(&obj->cat));
}

static void php_ion_catalog_dtor(php_ion_catalog *obj)
{
	if (obj->cat) {
		ion_catalog_close(obj->cat);
	}
}

static ION_COLLECTION *php_ion_catalog_collection(php_ion_catalog *cat)
{
	/* do not look too close */
	struct {
		void *owner;
		ION_SYMBOL_TABLE *sys;
		ION_COLLECTION collection;
	} *cat_ptr = (void *) cat->cat;
	return &cat_ptr->collection;
}
// see https://github.com/amzn/ion-c/issues/269
#ifndef IPCN_pNODE_TO_pDATA
# define IPCN_pNODE_TO_pDATA(x)    (&((x)->_data[0]))
#endif

static void php_ion_catalog_copy(php_ion_catalog *new_obj, php_ion_catalog *old_obj)
{
	// do not clone cache members
	php_ion_catalog_ctor(new_obj);
	OBJ_CHECK(new_obj);

	ION_COLLECTION *col = php_ion_catalog_collection(old_obj);
	if (!ION_COLLECTION_IS_EMPTY(col)) {
		ION_COLLECTION_CURSOR cur;
		ION_COLLECTION_OPEN(col, cur);
		while (cur) {
			ION_SYMBOL_TABLE **ptr;
			ION_COLLECTION_NEXT(cur, ptr);
			if (*ptr) {
				ION_CHECK(ion_catalog_add_symbol_table(new_obj->cat, *ptr));
			}
		}
	}
}

static zend_string *ion_symbol_table_to_key(ION_SYMBOL_TABLE *tab)
{
	int32_t version;
	ION_STRING is;
	ION_CHECK_RETURN(NULL, ion_symbol_table_get_name(tab, &is));
	ION_CHECK_RETURN(NULL, ion_symbol_table_get_version(tab, &version));

	smart_str s = {0};
	smart_str_appendl(&s, (char *) is.value, is.length);
	smart_str_appendc(&s, ':');
	smart_str_append_long(&s, version);
	smart_str_0(&s);

	return s.s;
}

static void php_ion_catalog_add_symbol_table(php_ion_catalog *obj, php_ion_symbol_table *tab)
{
	OBJ_CHECK(obj);
	OBJ_CHECK(tab);

	zval tmp;
	zval *ztabs = zend_read_property(obj->std.ce, &obj->std, ZEND_STRL("symbolTables"), 0, &tmp);
	if (ztabs) {
		zend_ulong idx = (uintptr_t) &tab->std.gc;
		if (!zend_hash_index_exists(Z_ARRVAL_P(ztabs), idx)) {
			zend_string *key = ion_symbol_table_to_key(tab->tab);
			if (key) {
				ION_CHECK(ion_catalog_add_symbol_table(obj->cat, tab->tab),
						zend_string_release(key));
				SEPARATE_ARRAY(ztabs);
				GC_ADDREF(&tab->std);
				add_index_object(ztabs, idx, &tab->std);
				GC_ADDREF(&tab->std);
				add_assoc_object_ex(ztabs, key->val, key->len, &tab->std);
				zend_update_property(obj->std.ce, &obj->std, ZEND_STRL("symbolTables"), ztabs);
				zend_string_release(key);
			}
		}
	}
}

static void php_ion_catalog_symbol_table_zval(php_ion_catalog *obj, ION_SYMBOL_TABLE *tab, zval *return_value)
{
	zend_string *key = ion_symbol_table_to_key(tab);
	PTR_CHECK(key);

	zval tmp;
	zval *ztabs = zend_read_property(obj->std.ce, &obj->std, ZEND_STRL("symbolTables"), 0, &tmp);
	if (ztabs) {
		zval *ztab = zend_hash_find(Z_ARRVAL_P(ztabs), key);
		if (ztab) {
			zend_string_release(key);
			RETURN_COPY(ztab);
		}
	}

	object_init_ex(return_value, ce_Symbol_Table_Shared);
	php_ion_symbol_table *o_tab = php_ion_obj(symbol_table, Z_OBJ_P(return_value));
	o_tab->tab = tab;
	php_ion_symbol_table_ctor(o_tab);

	if (ztabs) {
		SEPARATE_ARRAY(ztabs);
		ZVAL_ADDREF(return_value);
		add_index_zval(ztabs, (uintptr_t) &o_tab->std.gc, return_value);
		ZVAL_ADDREF(return_value);
		add_assoc_zval_ex(ztabs, key->val, key->len, return_value);
	}
	zend_string_release(key);
}

php_ion_decl(catalog, Catalog);

typedef struct php_ion_reader_ccn_ctx {
	zend_object *obj;
	zend_fcall_info fci;
	zend_fcall_info_cache fcc;
} php_ion_reader_ccn_ctx;

/*
static void php_ion_reader_options_copy(php_ion_reader_options *new_obj, php_ion_reader_options *old_obj)
{
	zend_objects_clone_members(&new_obj->std, &old_obj->std);

	new_obj->opt = old_obj->opt;
	new_obj->cat = old_obj->cat;
	new_obj->dec_ctx = old_obj->dec_ctx;
	new_obj->cb = old_obj->cb;
	if (new_obj->cb) {
		zval zcb;
		ZVAL_OBJ(&zcb, new_obj->cb);
		zend_fcall_info_init(&zcb, 0, &new_obj->ccn.fci, &new_obj->ccn.fcc, NULL, NULL);
		new_obj->opt.context_change_notifier.context = &new_obj->ccn;
	}
}
*/

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

	ION_READER_OPTIONS options;
	php_ion_reader_ccn_ctx ccn;
	zend_object *cat, *dec_ctx, *cb, std;
} php_ion_reader;

static iERR php_ion_reader_stream_handler(struct _ion_user_stream *user)
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

static iERR on_context_change(void *context, ION_COLLECTION *imports)
{
	iERR e = IERR_OK;

	if (context) {
		php_ion_reader_ccn_ctx *ctx = context;

		zval zobj;
		ZVAL_OBJ(&zobj, ctx->obj);
		zend_fcall_info_argn(&ctx->fci, 1, &zobj);
		if (SUCCESS != zend_fcall_info_call(&ctx->fci, &ctx->fcc, NULL, NULL)) {
			e = IERR_INTERNAL_ERROR;
		}
		zend_fcall_info_args_clear(&ctx->fci, false);
	}
	return e;
}

static void php_ion_reader_ctor(php_ion_reader *obj)
{
	iERR err;

	if (obj->cb) {
		zval zcb;
		ZVAL_OBJ(&zcb, obj->cb);
		zend_fcall_info_init(&zcb, 0, &obj->ccn.fci, &obj->ccn.fcc, NULL, NULL);
		obj->ccn.obj = &obj->std;
		obj->options.context_change_notifier.context = &obj->ccn;
		obj->options.context_change_notifier.notify = on_context_change;
		update_property_obj_ex(ce_Reader_Reader,&obj->std, ZEND_STRL("onContextChange"), obj->cb);
	} else {
		zend_update_property_null(ce_Reader_Reader, &obj->std, ZEND_STRL("onContextChange"));
	}
	if (obj->cat) {
		update_property_obj_ex(ce_Reader_Reader,&obj->std, ZEND_STRL("catalog"), obj->cat);
		obj->options.pcatalog = php_ion_obj(catalog, obj->cat)->cat;
	} else {
		zend_update_property_null(ce_Reader_Reader, &obj->std, ZEND_STRL("catalog"));
	}
	if (obj->dec_ctx) {
		update_property_obj_ex(ce_Reader_Reader,&obj->std, ZEND_STRL("decimalContext"), obj->dec_ctx);
		obj->options.decimal_context = &php_ion_obj(decimal_ctx, obj->dec_ctx)->ctx;
	} else {
		zend_update_property_null(ce_Reader_Reader, &obj->std, ZEND_STRL("decimalContext"));
	}

	zend_update_property_bool(ce_Reader_Reader, &obj->std, ZEND_STRL("returnSystemValues"),
							  obj->options.return_system_values);
	zend_update_property_long(ce_Reader_Reader, &obj->std, ZEND_STRL("maxContainerDepth"),
							  obj->options.max_container_depth);
	zend_update_property_long(ce_Reader_Reader, &obj->std, ZEND_STRL("maxAnnotations"),
							  obj->options.max_annotation_count);
	zend_update_property_long(ce_Reader_Reader, &obj->std, ZEND_STRL("annotationBufferSize"),
							  obj->options.max_annotation_buffered);
	zend_update_property_long(ce_Reader_Reader, &obj->std, ZEND_STRL("tempBufferSize"),
							  obj->options.chunk_threshold);
	zend_update_property_bool(ce_Reader_Reader, &obj->std, ZEND_STRL("skipCharacterValidation"),
							  obj->options.skip_character_validation);
	
	if (obj->type == STREAM_READER) {
		obj->stream.buf.length = obj->options.chunk_threshold ? obj->options.chunk_threshold : 0x4000;
		obj->stream.buf.value = emalloc(obj->stream.buf.length);
		err = ion_reader_open_stream(&obj->reader, obj, php_ion_reader_stream_handler, &obj->options);
	} else {
		err = ion_reader_open_buffer(&obj->reader, (BYTE *) obj->buffer->val, (SIZE) obj->buffer->len, &obj->options);
	}

	ION_CHECK(err);
	OBJ_CHECK(obj);
}

static void php_ion_reader_dtor(php_ion_reader *obj)
{
	if (obj->reader) {
		ion_reader_close(obj->reader);
	}
	if (obj->cb) {
		zend_fcall_info_args_clear(&obj->ccn.fci, true);
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

#define php_ion_reader_copy(n,o)
php_ion_decl_noclone(reader, Reader_Reader);
#define clone_ion_Reader_Reader NULL

typedef struct php_ion_writer {
	ION_WRITER *writer;
	enum {
		BUFFER_WRITER,
		STREAM_WRITER,
	} type;
	union {
		struct {
			smart_str str;
			struct _ion_user_stream *usr;
		} buffer;
		struct {
			ION_STRING buf;
			php_stream *ptr;
		} stream;
	};

	ION_WRITER_OPTIONS options;
	zend_object *cat, *dec_ctx, std;

} php_ion_writer;

static iERR php_ion_writer_stream_handler(struct _ion_user_stream *user)
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

static void php_ion_writer_stream_init(php_ion_writer *obj)
{
	obj->stream.buf.length = obj->options.temp_buffer_size ? obj->options.temp_buffer_size : 0x1000;
	obj->stream.buf.value = emalloc(obj->stream.buf.length);
}

static void php_ion_writer_buffer_offer(php_ion_writer *obj)
{
	if (obj->buffer.usr) {
		obj->buffer.usr->curr = (BYTE *) &obj->buffer.str.s->val[obj->buffer.str.s->len];
		obj->buffer.usr->limit = obj->buffer.usr->curr + obj->buffer.str.a - obj->buffer.str.s->len;
	}
}

static void php_ion_writer_buffer_init(php_ion_writer *obj)
{
	smart_str_alloc(&obj->buffer.str, 0, false);
	php_ion_writer_buffer_offer(obj);
}

static void php_ion_writer_buffer_reset(php_ion_writer *obj)
{
	smart_str_free(&obj->buffer.str);
	memset(&obj->buffer.str, 0, sizeof(obj->buffer.str));
	php_ion_writer_buffer_init(obj);
}

static zend_string *php_ion_writer_buffer_copy(php_ion_writer *obj)
{
	if (obj->buffer.usr) {
		// ensure that brain-dead ion_stream interface calls us again
		obj->buffer.usr->curr = NULL;
		obj->buffer.usr->limit = NULL;
	}
	smart_str_0(&obj->buffer.str);
	return zend_string_copy(obj->buffer.str.s);
}

static void php_ion_writer_buffer_separate(php_ion_writer *obj, bool grow)
{
	// see zend_string_separate and smart_str_erealloc
	zend_string *old_str = obj->buffer.str.s;
	zend_string *new_str = zend_string_alloc(obj->buffer.str.a << grow, false);
	memcpy(new_str->val, old_str->val, new_str->len = old_str->len);
	zend_string_release(old_str);
	obj->buffer.str.s = new_str;
}

static void php_ion_writer_buffer_grow(php_ion_writer *obj)
{
	if (obj->buffer.usr && obj->buffer.usr->curr) {
		obj->buffer.str.s->len = obj->buffer.usr->curr - (BYTE *) obj->buffer.str.s->val;
	}
	if (obj->buffer.usr && obj->buffer.usr->curr && obj->buffer.usr->curr == obj->buffer.usr->limit) {
		if (UNEXPECTED(GC_REFCOUNT(obj->buffer.str.s) > 1)) {
			php_ion_writer_buffer_separate(obj, true);
		} else {
			smart_str_erealloc(&obj->buffer.str, obj->buffer.str.a << 1);
		}
	} else if (UNEXPECTED(GC_REFCOUNT(obj->buffer.str.s) > 1)) {
		php_ion_writer_buffer_separate(obj, false);
	}
	php_ion_writer_buffer_offer(obj);
}


static iERR php_ion_writer_buffer_handler(struct _ion_user_stream *user)
{
	php_ion_writer *writer = (php_ion_writer *) user->handler_state;
	writer->buffer.usr = user;
	php_ion_writer_buffer_grow(writer);
	return IERR_OK;
}

static void php_ion_writer_init_shared_imports(php_ion_writer *obj)
{
	php_ion_catalog *cat = php_ion_obj(catalog, obj->cat);
	OBJ_CHECK(cat);

	ION_CHECK(ion_writer_options_initialize_shared_imports(&obj->options));

	ION_COLLECTION *col = php_ion_catalog_collection(cat);
	if (!ION_COLLECTION_IS_EMPTY(col)) {
		// holy, nah, forget it batman...
		ION_COLLECTION_CURSOR cur;
		ION_COLLECTION_OPEN(col, cur);
		while (cur) {
			ION_SYMBOL_TABLE **ptr;
			ION_COLLECTION_NEXT(cur, ptr);
			if (*ptr) {
				ION_CHECK(ion_writer_options_add_shared_imports_symbol_tables(&obj->options, ptr, 1));
			}
		}
	}
}

static void php_ion_writer_ctor(php_ion_writer *obj)
{
	if (obj->dec_ctx) {
		update_property_obj_ex(ce_Writer_Writer, &obj->std, ZEND_STRL("decimalContext"), obj->dec_ctx);
		obj->options.decimal_context = &php_ion_obj(decimal_ctx, obj->dec_ctx)->ctx;
	} else {
		zend_update_property_null(ce_Writer_Writer, &obj->std, ZEND_STRL("decimalContext"));
	}
	if (obj->cat) {
		update_property_obj_ex(ce_Writer_Writer, &obj->std, ZEND_STRL("catalog"), obj->cat);
		obj->options.pcatalog = php_ion_obj(catalog, obj->cat)->cat;
		php_ion_writer_init_shared_imports(obj);
	} else {
		zend_update_property_null(ce_Writer_Writer, &obj->std, ZEND_STRL("catalog"));
	}

	zend_update_property_bool(ce_Writer_Writer, &obj->std, ZEND_STRL("outputBinary"),
							  obj->options.output_as_binary);
	zend_update_property_bool(ce_Writer_Writer, &obj->std, ZEND_STRL("compactFloats"),
							  obj->options.compact_floats);
	zend_update_property_bool(ce_Writer_Writer, &obj->std, ZEND_STRL("escapeNonAscii"),
							  obj->options.escape_all_non_ascii);
	zend_update_property_bool(ce_Writer_Writer, &obj->std, ZEND_STRL("prettyPrint"),
							  obj->options.pretty_print);
	zend_update_property_bool(ce_Writer_Writer, &obj->std, ZEND_STRL("indentTabs"),
							  obj->options.indent_with_tabs);
	zend_update_property_long(ce_Writer_Writer, &obj->std, ZEND_STRL("indentSize"),
							  obj->options.indent_size);
	zend_update_property_bool(ce_Writer_Writer, &obj->std, ZEND_STRL("flushEveryValue"),
							  obj->options.flush_every_value);
	zend_update_property_long(ce_Writer_Writer, &obj->std, ZEND_STRL("maxContainerDepth"),
							  obj->options.max_container_depth);
	zend_update_property_long(ce_Writer_Writer, &obj->std, ZEND_STRL("maxAnnotations"),
							  obj->options.max_annotation_count);
	zend_update_property_long(ce_Writer_Writer, &obj->std, ZEND_STRL("tempBufferSize"),
							  obj->options.temp_buffer_size);

	ION_STREAM_HANDLER h;
	if (obj->type == STREAM_WRITER) {
		h = php_ion_writer_stream_handler;
		php_ion_writer_stream_init(obj);
	} else {
		h = php_ion_writer_buffer_handler;
		php_ion_writer_buffer_init(obj);
	}

	ION_CHECK(ion_writer_open_stream(&obj->writer, h, obj, &obj->options));
	OBJ_CHECK(obj);
}

static void php_ion_writer_dtor(php_ion_writer *obj)
{
	if (obj->writer) {
		ion_writer_close(obj->writer);
	}
	if (obj->cat) {
		ion_writer_options_close_shared_imports(&obj->options);
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
	}
}

#define php_ion_writer_copy(o,n)
php_ion_decl_noclone(writer, Writer_Writer);
#define clone_ion_Writer_Writer NULL

static bool can_serialize_fast(php_ion_serializer *ser)
{
	if (ser->wri->ce != ce_Writer_Buffer_Writer && ser->wri->ce != ce_Writer_Stream_Writer) {
		return false;
	}

	if (ser->std.ce != ce_Serializer_Serializer) {
		return false;
	}

	return true;
}

static void php_ion_serializer_ctor(php_ion_serializer *ser_obj)
{
	php_ion_serializer *global_ser = &php_ion_globals.serializer;
	ser_obj->ids = global_ser->ids;
	ser_obj->tmp = global_ser->tmp;

	zend_update_property_bool(ce_Serializer_Serializer, &ser_obj->std, ZEND_STRL("multiSequence"),
			ser_obj->multi_seq);
	zend_update_property_bool(ce_Serializer_Serializer, &ser_obj->std, ZEND_STRL("callMagicSerialize"),
			ser_obj->call_magic);
	if (ser_obj->call_custom) {
		zend_update_property_str(ce_Serializer_Serializer, &ser_obj->std, ZEND_STRL("callCustomSerialize"),
				ser_obj->call_custom);
		ser_obj->call_custom = zend_string_tolower(ser_obj->call_custom);
 	} else {
		zend_update_property_null(ce_Serializer_Serializer, &ser_obj->std, ZEND_STRL("callCustomSerialize"));
	}
}

static void php_ion_serializer_dtor(php_ion_serializer *obj)
{
	if (obj->call_custom) {
		zend_string_release(obj->call_custom);
	}
}

static void php_ion_serialize_zval(php_ion_serializer *, zval *);

static void php_ion_serialize_struct(php_ion_serializer *ser, zend_array *arr, bool unmangle_props, bool annotate_props)
{
	if (can_serialize_fast(ser)) {
		ION_CHECK(ion_writer_start_container(php_ion_obj(writer, ser->wri)->writer, tid_STRUCT));
	} else {
		zval z_type;
		ZVAL_OBJ(&z_type, php_ion_type_fetch(tid_STRUCT));
		zend_call_method_with_1_params(ser->wri, NULL, NULL, "startContainer", NULL, &z_type);
		ION_CATCH();
	}

	zval *v;
	zend_ulong h;
	zend_string *k = NULL;
	if (arr) ZEND_HASH_FOREACH_KEY_VAL_IND(arr, h, k, v)
		char buf[MAX_LENGTH_OF_LONG + 1];
		ION_STRING is;
		if (k) {
			size_t prop_len;
			const char *class_name, *prop_name;
			if (unmangle_props && (SUCCESS == zend_unmangle_property_name_ex(k, &class_name, &prop_name, &prop_len)) && class_name) {
				if (annotate_props) {
					if (can_serialize_fast(ser)) {
						ION_CHECK(ion_writer_add_annotation_symbol(php_ion_obj(writer, ser->wri)->writer, &PHP_ION_SYMBOL_PROPERTY));
						ION_CHECK(ion_writer_add_annotation(php_ion_obj(writer, ser->wri)->writer,
															ion_string_assign_cstr(&is, (char *) class_name, prop_name - class_name - 1)));
					} else {
						zval z_ann_prop, z_ann_class;
						ZVAL_CHAR(&z_ann_prop, 'p');
						ZVAL_STRINGL(&z_ann_class, class_name, prop_name - class_name);
						zend_call_method_with_2_params(ser->wri, NULL, NULL, "writeAnnotation", NULL, &z_ann_prop, &z_ann_class);
						zval_ptr_dtor(&z_ann_class);
						ION_CATCH();
					}
				}
			} else {
				prop_name = k->val;
				prop_len = k->len;
			}
			ion_string_assign_cstr(&is, (char *) prop_name, (SIZE) prop_len);
		} else {
			char *end = buf + sizeof(buf) - 1;
			char *ptr = zend_print_long_to_buf(end, (zend_long) h);
			ion_string_assign_cstr(&is, ptr, (SIZE) (end - ptr));
		}

		if (can_serialize_fast(ser)) {
			// WATCH OUT: field names need to be copied
			ION_STRING fn;
			ION_CHECK(ion_string_copy_to_owner(php_ion_obj(writer, ser->wri)->writer, &fn, &is));
			ION_CHECK(ion_writer_write_field_name(php_ion_obj(writer, ser->wri)->writer, &fn));
		} else {
			zval z_field_name;
			ZVAL_STRINGL(&z_field_name, (const char *) is.value, is.length);
			zend_call_method_with_1_params(ser->wri, NULL, NULL, "writeFieldName", NULL, &z_field_name);
			zval_ptr_dtor(&z_field_name);
			ION_CATCH();
		}

		php_ion_serialize_zval(ser, v);
		ION_CATCH();
	ZEND_HASH_FOREACH_END();

	if(can_serialize_fast(ser)) {
		ION_CHECK(ion_writer_finish_container(php_ion_obj(writer, ser->wri)->writer));
	} else {
		zend_call_method_with_0_params(ser->wri, NULL, NULL, "finishContainer", NULL);
	}
}

static void php_ion_serialize_list(php_ion_serializer *ser, zend_array *arr)
{
	if (can_serialize_fast(ser)) {
		ION_CHECK(ion_writer_start_container(php_ion_obj(writer, ser->wri)->writer, tid_LIST));
	} else {
		zval z_type;
		ZVAL_OBJ(&z_type, php_ion_type_fetch(tid_LIST));
		zend_call_method_with_1_params(ser->wri, NULL, NULL, "startContainer", NULL, &z_type);
		ION_CATCH();
	}

	zval *v;
	ZEND_HASH_FOREACH_VAL_IND(arr, v)
			php_ion_serialize_zval(ser, v);
			ION_CATCH();
	ZEND_HASH_FOREACH_END();

	if (can_serialize_fast(ser)) {
		ION_CHECK(ion_writer_finish_container(php_ion_obj(writer, ser->wri)->writer));
	} else {
		zend_call_method_with_0_params(ser->wri, NULL, NULL, "finishContainer", NULL);
	}
}

static void php_ion_serialize_object_iface(php_ion_serializer *ser, zend_object *zobject)
{
	uint8_t *buf;
	size_t len;
	zval tmp;

	ZVAL_OBJ(&tmp, zobject);
	if (SUCCESS == zobject->ce->serialize(&tmp, &buf, &len, NULL)) {
		if (can_serialize_fast(ser)) {
			ION_STRING is;
			ION_CHECK(ion_writer_add_annotation_symbol(php_ion_obj(writer, ser->wri)->writer, &PHP_ION_SYMBOL_SERIALIZEABLE));
			ION_CHECK(ion_writer_add_annotation(php_ion_obj(writer, ser->wri)->writer, ion_string_from_zend(&is, zobject->ce->name)));
			ION_CHECK(ion_writer_write_clob(php_ion_obj(writer, ser->wri)->writer, buf, len));
			efree(buf);
		} else {
			zval z_ann_srlzbl, z_ann_class, z_clob;
			ZVAL_CHAR(&z_ann_srlzbl, 'S');
			ZVAL_STR_COPY(&z_ann_class, zobject->ce->name);
			zend_call_method_with_2_params(ser->wri, NULL, NULL, "writeAnnotation", NULL, &z_ann_srlzbl, &z_ann_class);
			zval_ptr_dtor(&z_ann_class);
			ION_CATCH();
			ZVAL_STRINGL(&z_clob, (const char *) buf, len);
			zend_call_method_with_1_params(ser->wri, NULL, NULL, "writeCLob", NULL, &z_clob);
			zval_ptr_dtor(&z_clob);
		}
	} else if (!EG(exception)){
		zend_throw_exception_ex(ce_Exception, IERR_INTERNAL_ERROR,
				"Failed to serialize class %s", zobject->ce->name->val);
	}
}

static void php_ion_serialize_object_magic(php_ion_serializer *ser, zend_object *zobject, zend_function *fn)
{
	zval rv;

	ZVAL_NULL(&rv);
	zend_call_known_instance_method_with_0_params(fn ? fn : zobject->ce->__serialize, zobject, &rv);
	ION_CATCH();

	if (IS_ARRAY == Z_TYPE(rv)) {
		if (can_serialize_fast(ser)) {
			ION_STRING is;
			ION_CHECK(ion_writer_add_annotation_symbol(php_ion_obj(writer, ser->wri)->writer, fn ? &PHP_ION_SYMBOL_CUSTOM_OBJECT : &PHP_ION_SYMBOL_MAGIC_OBJECT));
			ION_CHECK(ion_writer_add_annotation(php_ion_obj(writer, ser->wri)->writer, ion_string_from_zend(&is, zobject->ce->name)));
		} else {
			zval z_ann_cust, z_ann_class;
			ZVAL_CHAR(&z_ann_cust, 'C');
			ZVAL_STR_COPY(&z_ann_class, zobject->ce->name);
			zend_call_method_with_2_params(ser->wri, NULL, NULL, "writeAnnotation", NULL, &z_ann_cust, &z_ann_class);
			zval_ptr_dtor(&z_ann_class);
		}
		if (!EG(exception)) {
			php_ion_serialize_zval(ser, &rv);
		}
		zval_ptr_dtor(&rv);
	} else {
		zend_throw_exception_ex(ce_Exception, IERR_INTERNAL_ERROR,
				"%s serializer %s::%s did not return an array",
				fn ? "Custom" : "Magic", zobject->ce->name->val,
				fn ? fn->common.function_name->val : "__serialize");
	}
}

static void php_ion_serialize_object_enum(php_ion_serializer *ser, zend_object *zobject)
{
	zval *z_cname = zend_enum_fetch_case_name(zobject);

	if (can_serialize_fast(ser)) {
		ION_STRING is;
		ION_CHECK(ion_writer_add_annotation_symbol(php_ion_obj(writer, ser->wri)->writer, &PHP_ION_SYMBOL_ENUM));
		ION_CHECK(ion_writer_add_annotation(php_ion_obj(writer, ser->wri)->writer, ion_string_from_zend(&is, zobject->ce->name)));
		ION_CHECK(ion_writer_write_symbol(php_ion_obj(writer, ser->wri)->writer, ion_string_from_zend(&is, Z_STR_P(z_cname))));
	} else {
		zval z_ann_enm, z_ann_class;
		ZVAL_CHAR(&z_ann_enm, 'E');
		ZVAL_STR_COPY(&z_ann_class, zobject->ce->name);
		zend_call_method_with_2_params(ser->wri, NULL, NULL, "writeAnnotation", NULL, &z_ann_enm, &z_ann_class);
		zval_ptr_dtor(&z_ann_class);
		ION_CATCH();
		zend_call_method_with_1_params(ser->wri, NULL, NULL, "writeSymbol", NULL, z_cname);
	}
}

static void php_ion_serialize_object_std(php_ion_serializer *ser, zend_object *zobject)
{
	if (can_serialize_fast(ser)) {
		ION_STRING is;

		if (zobject->ce != zend_standard_class_def) {
			ION_CHECK(ion_writer_add_annotation_symbol(php_ion_obj(writer, ser->wri)->writer, &PHP_ION_SYMBOL_CLASS_OBJECT));
			ION_CHECK(ion_writer_add_annotation(php_ion_obj(writer, ser->wri)->writer, ion_string_from_zend(&is, zobject->ce->name)));
		} else {
			ION_CHECK(ion_writer_add_annotation_symbol(php_ion_obj(writer, ser->wri)->writer, &PHP_ION_SYMBOL_OBJECT));
		}
	} else {
		if (zobject->ce != zend_standard_class_def) {
			zval z_ann_cobj, z_ann_class;
			ZVAL_CHAR(&z_ann_cobj, 'c');
			ZVAL_STR_COPY(&z_ann_class, zobject->ce->name);
			zend_call_method_with_2_params(ser->wri, NULL, NULL, "writeAnnotation", NULL, &z_ann_cobj, &z_ann_class);
			zval_ptr_dtor(&z_ann_class);
		} else {
			zval z_ann_obj;
			ZVAL_CHAR(&z_ann_obj, 'o');
			zend_call_method_with_1_params(ser->wri, NULL, NULL, "writeAnnotation", NULL, &z_ann_obj);
		}
		ION_CATCH();
	}

	zval zobj;
	ZVAL_OBJ(&zobj, zobject);
	HashTable *props = zend_get_properties_for(&zobj, ZEND_PROP_PURPOSE_SERIALIZE);
	if (props) {
		php_ion_serialize_struct(ser, props, true, true);
		zend_release_properties(props);
	} else {
		zend_throw_exception_ex(ce_Exception, IERR_INTERNAL_ERROR,
				"Could not get properties for serialization of class %s",
				zobject->ce->name->val);
	}
}

static void php_ion_serialize_object_lob(php_ion_serializer *ser, zend_object *zobject)
{
	zval tmp_type, *type = zend_read_property_ex(NULL, zobject, ZSTR_KNOWN(ZEND_STR_TYPE), 0, &tmp_type);
	zval tmp_value, *value = zend_read_property_ex(NULL, zobject, ZSTR_KNOWN(ZEND_STR_VALUE), 0, &tmp_value);

	switch (Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(type)))) {
	case tid_BLOB_INT:
		if (can_serialize_fast(ser)) {
			ION_CHECK(ion_writer_write_blob(php_ion_obj(writer, ser->wri)->writer, (BYTE *) Z_STRVAL_P(value), Z_STRLEN_P(value)));
		} else {
			zend_call_method_with_1_params(ser->wri, NULL, NULL, "writeBLob", NULL, value);
		}
		break;
	case tid_CLOB_INT:
		if (can_serialize_fast(ser)) {
			ION_CHECK(ion_writer_write_clob(php_ion_obj(writer, ser->wri)->writer, (BYTE *) Z_STRVAL_P(value), Z_STRLEN_P(value)));
		} else {
			zend_call_method_with_1_params(ser->wri, NULL, NULL, "writeCLob", NULL, value);
		}
		break;
	default:
		zend_throw_exception_ex(ce_Exception, IERR_INVALID_ARG,
				"Unsupported LOB type: ion\\Type::%s", Z_STRVAL_P(zend_enum_fetch_case_name(Z_OBJ_P(type))));
		break;
	}
}

static bool can_call_magic_serialize(php_ion_serializer *ser, zend_class_entry *ce)
{
	return ce->__serialize && ser->call_magic;
}

static bool can_call_iface_serialize(php_ion_serializer *ser, zend_class_entry *ce)
{
	(void) ser;
	return !!ce->serialize; // NOLINT
}

static bool can_call_custom_serialize(php_ion_serializer *ser, zend_object *zobject, zend_function **fn)
{
	if (ser->call_custom) {
		return !!(*fn = zend_hash_find_ptr(&zobject->ce->function_table, ser->call_custom)); // NOLINT
	}
	return false;
}

static bool is_special_class(const zend_class_entry *ce, zend_class_entry **target) {
#define IS_TARGET(_ce) \
    if (instanceof_function(ce, _ce)) { \
        *target = _ce;    \
        return true; \
    }
	IS_TARGET(ce_Symbol);
	IS_TARGET(ce_Decimal);
	IS_TARGET(ce_Timestamp);
	IS_TARGET(ce_LOB);
	return false;
#undef IS_TARGET
}

static void php_ion_serialize_object(php_ion_serializer *ser, zend_object *zobject) {
	zend_function *fn;
	zend_class_entry *special_ce, *ce = zobject->ce;
	ZEND_ASSERT(ce);

	if (ce->ce_flags & ZEND_ACC_NOT_SERIALIZABLE) {
		zend_throw_exception_ex(ce_Exception, IERR_INVALID_ARG,
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
	} else if (!is_special_class(ce, &special_ce)) {
		php_ion_serialize_object_std(ser, zobject);
	} else {
		if (can_serialize_fast(ser) || special_ce == ce_LOB) {
			if (special_ce == ce_Symbol) {
				ION_CHECK(ion_writer_write_ion_symbol(php_ion_obj(writer, ser->wri)->writer, &php_ion_obj(symbol, zobject)->sym));
			} else if (special_ce == ce_Decimal) {
				ION_CHECK(ion_writer_write_ion_decimal(php_ion_obj(writer, ser->wri)->writer, &php_ion_obj(decimal, zobject)->dec));
			} else if (special_ce == ce_Timestamp) {
				ION_TIMESTAMP its;
				php_ion_timestamp *pts = php_ion_obj(timestamp, zobject);
				decContext *ctx = php_ion_obj(writer, ser->wri)->options.decimal_context;
				ION_CHECK(ion_writer_write_timestamp(php_ion_obj(writer, ser->wri)->writer, ion_timestamp_from_php(&its, pts, ctx)));
			} else {
			 	assert(special_ce == ce_LOB);
				php_ion_serialize_object_lob(ser, zobject);
			}
		} else {
			zval z_param;
			const char *method = NULL;

			ZVAL_OBJ(&z_param, zobject);
			if (special_ce == ce_Symbol) {
				method = "writeSymbol";
			} else if (special_ce == ce_Decimal) {
				method = "writeDecimal";
			} else if (special_ce == ce_Timestamp) {
				method = "writeTimestamp";
			} else {
				assert(!!method);
			}
			zend_call_method(ser->wri, NULL, NULL, method, strlen(method), NULL, 1, &z_param, NULL);
		}
	}
}

static bool php_ion_serialize_system_value(php_ion_serializer *ser, zval *zv)
{
	if (1 == php_ion_globals.serializer.level) {
		if (Z_TYPE_P(zv) == IS_OBJECT) {
			if (Z_OBJCE_P(zv) == ce_Symbol_Table_Shared) {
				php_ion_symbol_table *obj = php_ion_obj(symbol_table, Z_OBJ_P(zv));
				ION_CHECK_RETURN(true, ion_symbol_table_unload(obj->tab, php_ion_obj(writer, ser->wri)->writer));
				return true;
			}
		}
	}
	return false;
}

static bool php_ion_serialize_backref(php_ion_serializer *ser, zval *zv)
{
	if (Z_TYPE_P(zv) == IS_STRING && Z_STR_P(zv) == zend_empty_string) {
		return false;
	}
	if (Z_TYPE_P(zv) == IS_ARRAY && Z_ARR_P(zv) == &zend_empty_array) {
		return false;
	}

	zend_ulong idx = (zend_ulong) (uintptr_t) Z_COUNTED_P(zv);
	zval *ref = zend_hash_index_find(ser->ids, idx);
	if (!ref) {
		zval num;

		ZVAL_LONG(&num, zend_hash_num_elements(ser->ids));
		zend_hash_index_add(ser->ids, idx, &num);

		Z_TRY_ADDREF_P(zv);
		zend_hash_next_index_insert(ser->tmp, zv);

		return false;
	}

	if (can_serialize_fast(ser)) {
		ION_CHECK_RETURN(true, ion_writer_add_annotation_symbol(php_ion_obj(writer, ser->wri)->writer, &PHP_ION_SYMBOL_BACKREF));
		ION_CHECK_RETURN(true, ion_writer_write_int64(php_ion_obj(writer, ser->wri)->writer, Z_LVAL_P(ref)));
	} else {
		zval z_ann_bref;
		ZVAL_CHAR(&z_ann_bref, 'r');
		zend_call_method_with_1_params(ser->wri, NULL, NULL, "writeAnnotation", NULL, &z_ann_bref);
		ION_CATCH_RETURN(true);
		zend_call_method_with_1_params(ser->wri, NULL, NULL, "writeInt", NULL, ref);
	}
	return true;
}

static void php_ion_serialize_string(php_ion_serializer *ser, zend_string *str)
{
	if (can_serialize_fast(ser)) {
		ION_STRING is;
		ION_CHECK(ion_writer_write_string(php_ion_obj(writer, ser->wri)->writer, ion_string_from_zend(&is, str)));
	} else {
		zval zs;
		ZVAL_STR(&zs, str);
		zend_call_method_with_1_params(ser->wri, NULL, NULL, "writeString", NULL, &zs);
	}
}

static void php_ion_serialize_reference(php_ion_serializer *ser, zval *noref)
{
	if (can_serialize_fast(ser)) {
		ION_CHECK(ion_writer_add_annotation_symbol(php_ion_obj(writer, ser->wri)->writer, &PHP_ION_SYMBOL_REFERENCE));
	} else {
		zval z_ann_ref;
		ZVAL_CHAR(&z_ann_ref, 'R');
		zend_call_method_with_1_params(ser->wri, NULL, NULL, "writeAnnotation", NULL, &z_ann_ref);
		ION_CATCH();
	}
	php_ion_serialize_zval(ser, noref);

}
static void php_ion_serialize_refcounted(php_ion_serializer *ser, zval *zv)
{
	if (php_ion_serialize_system_value(ser, zv)) {
		return;
	}
	if (php_ion_serialize_backref(ser, zv)) {
		return;
	}

	switch (Z_TYPE_P(zv)) {
	case IS_STRING:
		php_ion_serialize_string(ser, Z_STR_P(zv));
		break;

	case IS_ARRAY:
		if (zend_array_is_list(Z_ARRVAL_P(zv))) {
			php_ion_serialize_list(ser, Z_ARRVAL_P(zv));
		} else {
			php_ion_serialize_struct(ser, Z_ARRVAL_P(zv), false, false);
		}
		break;

	case IS_OBJECT:
		php_ion_serialize_object(ser, Z_OBJ_P(zv));
		break;

	case IS_REFERENCE:
		php_ion_serialize_reference(ser, Z_REFVAL_P(zv));
		break;
	}
}

static void php_ion_serialize_scalar(php_ion_serializer *ser, zval *zv)
{
	if (can_serialize_fast(ser)) {
		switch (Z_TYPE_P(zv)) {
		case IS_NULL:
			ION_CHECK(ion_writer_write_null(php_ion_obj(writer, ser->wri)->writer));
			break;
		case IS_TRUE:
			ION_CHECK(ion_writer_write_bool(php_ion_obj(writer, ser->wri)->writer, TRUE));
			break;
		case IS_FALSE:
			ION_CHECK(ion_writer_write_bool(php_ion_obj(writer, ser->wri)->writer, FALSE));
			break;
		case IS_LONG:
			ION_CHECK(ion_writer_write_int64(php_ion_obj(writer, ser->wri)->writer, Z_LVAL_P(zv)));
			break;
		case IS_DOUBLE:
			ION_CHECK(ion_writer_write_double(php_ion_obj(writer, ser->wri)->writer, Z_DVAL_P(zv)));
			break;
		}
	} else {
		if (Z_ISNULL_P(zv)) {
			zend_call_method_with_0_params(ser->wri, NULL, NULL, "writeNull", NULL);
		} else {
			const char *method = NULL;

			if (Z_TYPE_P(zv) < IS_LONG) {
				method = "writeBool";
			} else if (Z_TYPE_P(zv) < IS_DOUBLE) {
				method = "writeInt";
			} else {
				method = "writeFloat";
			}

			zend_call_method(ser->wri, NULL, NULL, method, strlen(method), NULL, 1, zv, NULL);
		}
	}
}

static void php_ion_serialize_zval(php_ion_serializer *ser, zval *zv)
{
	PTR_CHECK(ser);

	switch (Z_TYPE_P(zv)) {
	case IS_NULL:
	case IS_TRUE:
	case IS_FALSE:
	case IS_LONG:
	case IS_DOUBLE:
		php_ion_serialize_scalar(ser, zv);
		break;
	case IS_STRING:
	case IS_ARRAY:
	case IS_OBJECT:
	case IS_REFERENCE:
		php_ion_serialize_refcounted(ser, zv);
		break;
	default:
		zend_throw_exception_ex(ce_Exception, IERR_INVALID_ARG,
				"Failed to serialize value of type %s", zend_zval_type_name(zv));
	}
}

#define php_ion_serializer_copy(o,n)
php_ion_decl(serializer, Serializer_Serializer);
#define clone_ion_Serializer NULL

static void php_ion_serialize_ex(php_ion_serializer *ser, zval *zv)
{
	HashPosition pos;
	HashTable *arr = NULL;

	if (ser->multi_seq) {
		if (Z_TYPE_P(zv) != IS_ARRAY || !zend_array_is_list(Z_ARRVAL_P(zv))) {
			zend_throw_exception_ex(ce_Exception, IERR_INVALID_ARG,
					"Expected a packed, consecutively numerically indexed array as argument to the multi sequence serializer");
			return;
		}

		arr = Z_ARRVAL_P(zv);

		zend_hash_internal_pointer_reset_ex(arr, &pos);
		zv = zend_hash_get_current_data_ex(arr, &pos);
	}

	while (zv) {
		php_ion_globals_serializer_step();
		php_ion_serialize_zval(ser, zv);
		php_ion_globals_serializer_exit();

		if (!ser->multi_seq) {
			break;
		}
		zend_hash_move_forward_ex(arr, &pos);
		zv = zend_hash_get_current_data_ex(arr, &pos);
	}
}

void php_ion_serialize(php_ion_serializer *ser, zval *zv, zval *return_value)
{
	zend_object *zo_ser = NULL, *zo_wri = NULL;

	if (!ser) {
		zo_ser = create_ion_Serializer_Serializer(NULL);
		ser = php_ion_obj(serializer, zo_ser);
		PTR_CHECK(ser);
		ser->call_magic = true;
		php_ion_serializer_ctor(ser);
		ION_CATCH();
	}

	if (!ser->wri) {
		zo_wri = create_ion_Writer_Writer(ce_Writer_Buffer_Writer);
		php_ion_writer_ctor(php_ion_obj(writer, zo_wri));
		ser->wri = zo_wri;
	}

	php_ion_serialize_ex(ser, zv);

	/* make sure to flush when done, else str.s might not contain everything until the writer is closed */
	if (can_serialize_fast(ser)) {
		ion_writer_flush(php_ion_obj(writer, ser->wri)->writer, NULL);
	} else {
		zend_call_method_with_0_params(ser->wri, NULL, NULL, "flush", NULL);
	}
	RETVAL_STR_COPY(php_ion_obj(writer, ser->wri)->buffer.str.s);

	if (zo_wri) {
		OBJ_RELEASE(zo_wri);
		ser->wri = NULL;
	}
	if (zo_ser) {
		OBJ_RELEASE(zo_ser);
	}
}

static bool can_unserialize_fast(php_ion_unserializer *ser)
{
	if (ser->rdr->ce != ce_Reader_Buffer_Reader && ser->rdr->ce != ce_Reader_Stream_Reader) {
		return false;
	}

	if (ser->std.ce != ce_Unserializer_Unserializer) {
		return false;
	}

	return true;
}

static void php_ion_unserializer_ctor(php_ion_unserializer *ser_obj)
{
	php_ion_unserializer *global_ser = &php_ion_globals.unserializer;
	ser_obj->ids = global_ser->ids;
	ser_obj->tmp = global_ser->tmp;
	ser_obj->addref = global_ser->addref;

	zend_update_property_bool(ce_Unserializer_Unserializer, &ser_obj->std, ZEND_STRL("multiSequence"),
			ser_obj->multi_seq);
	zend_update_property_bool(ce_Unserializer_Unserializer, &ser_obj->std, ZEND_STRL("callMagicUnserialize"),
			ser_obj->call_magic);
	if (ser_obj->call_custom) {
		zend_update_property_str(ce_Unserializer_Unserializer, &ser_obj->std, ZEND_STRL("callCustomUnserialize"),
				ser_obj->call_custom);
		ser_obj->call_custom = zend_string_tolower(ser_obj->call_custom);
	} else {
		zend_update_property_null(ce_Unserializer_Unserializer, &ser_obj->std, ZEND_STRL("callCustomUnserialize"));
	}
}

static void php_ion_unserializer_dtor(php_ion_unserializer *obj)
{
	if (obj->call_custom) {
		zend_string_release(obj->call_custom);
	}
}

static void php_ion_unserializer_next(php_ion_unserializer *ser, ION_TYPE *typ)
{
	if (can_unserialize_fast(ser)) {
		ION_CHECK(ion_reader_next(php_ion_obj(reader, ser->rdr)->reader, typ));
	} else {
		zend_call_method_with_0_params(&ser->std, NULL, NULL, "next", NULL);
		ION_CATCH();
		zval z_type;
		zend_call_method_with_0_params(&ser->std, NULL, NULL, "key", &z_type);
		ION_CATCH();
		*typ = ion_type_from_enum(Z_OBJ(z_type));
	}
}

static void php_ion_unserialize_zval(php_ion_unserializer *ser, zval *return_value, ION_TYPE *typ);

static bool can_call_magic_unserialize(php_ion_unserializer *ser, zend_class_entry *ce)
{
	return (ce && ce->__unserialize && ser->call_magic);
}

static bool can_call_iface_unserialize(php_ion_unserializer *ser, zend_class_entry *ce)
{
	return (ce && ce->unserialize);
}

static bool can_call_custom_unserialize(php_ion_unserializer *ser, zend_object *zobject, zend_function **fn)
{
	if (ser->call_custom) {
		return !!(*fn = zend_hash_find_ptr(&zobject->ce->function_table, ser->call_custom)); // NOLINT
	}
	return false;
}

static zval *php_ion_unserialize_class(php_ion_unserializer *ser, zval *return_value)
{
	zend_class_entry *ce = zend_lookup_class(ser->annotations.object_class);

	if (ce) {
		object_init_ex(return_value, ce);
		return zend_hash_next_index_insert(ser->ids, return_value);
	}

	zend_throw_exception_ex(ce_Exception, IERR_IMPORT_NOT_FOUND,
			"Could not find class %s", ser->annotations.object_class->val);
	return NULL;
}

static void php_ion_unserialize_object_enum(php_ion_unserializer *ser, zval *return_value)
{
	zend_string *zs_case = zval_get_string(return_value);
	zend_hash_next_index_insert(ser->tmp, return_value);
	ZVAL_NULL(return_value);
	ION_CATCH();

	zend_class_entry *ce = zend_lookup_class(ser->annotations.object_class);
	if (!ce || !(ce->ce_flags & ZEND_ACC_ENUM)) {
		zend_throw_exception_ex(ce_Exception, IERR_INVALID_TOKEN,
				"Not a valid enum: %s", ser->annotations.object_class->val);
		return;
	}
	if (!zend_hash_exists(CE_CONSTANTS_TABLE(ce), zs_case)) {
		zend_throw_exception_ex(ce_Exception, IERR_INVALID_TOKEN,
				"Not a valid enum case: %s::%s", ser->annotations.object_class->val, zs_case->val);
		return;
	}
	RETVAL_OBJ_COPY(zend_enum_get_case(ce, zs_case));
	zend_hash_next_index_insert(ser->ids, return_value);
	zend_string_release(zs_case);
}

static void php_ion_unserialize_object_iface(php_ion_unserializer *ser, zval *return_value)
{
	zend_class_entry *ce = zend_lookup_class(ser->annotations.object_class);
	if (can_call_iface_unserialize(ser, ce)) {
		zend_string *s = zval_get_string(return_value);
		zend_hash_next_index_insert(ser->tmp, return_value);
		ZVAL_NULL(return_value);
		zval *backref = zend_hash_next_index_insert(ser->ids, return_value);
		if (SUCCESS == ce->unserialize(backref, ce, (BYTE *) s->val, s->len, NULL)) {
			RETVAL_ZVAL(backref, 0, 0);
		} else {
			zval_ptr_dtor(backref);
			ZVAL_NULL(backref);
			if (!EG(exception)) {
				zend_throw_exception_ex(ce_Exception, IERR_INTERNAL_ERROR,
										"Failed to unserialize class %s", ce->name->val);
			}
		}
		zend_string_release(s);
	} else {
		zend_throw_exception_ex(ce_Exception, IERR_INVALID_TOKEN,
				"Class %s does not implement Serializable", ser->annotations.object_class->val);
	}
}

static void php_ion_unserialize_field_name(php_ion_unserializer *ser, zend_string **key, bool is_prop)
{
	if (can_unserialize_fast(ser)) {
		// FIXME: symbol table?
		ION_STRING name;
		SID sid = UNKNOWN_SID;
		char buf[MAX_LENGTH_OF_LONG + 1 + 1] = {0}, *end = buf + sizeof(buf) - 1, *ptr;

		ION_CHECK(ion_reader_get_field_name(php_ion_obj(reader, ser->rdr)->reader, &name));
		if (!name.length) {
			ION_SYMBOL *is_ptr;
			ION_CHECK(ion_reader_get_field_name_symbol(php_ion_obj(reader, ser->rdr)->reader, &is_ptr));
			if (!ION_SYMBOL_IS_NULL(is_ptr) && is_ptr->value.length) {
				ION_STRING_ASSIGN(&name, &is_ptr->value);
			} else {
				sid = is_ptr->sid;
			}
		}

		switch (name.length) {
		case 0:
			ptr = zend_print_long_to_buf(end, sid);
			*--ptr = '$';
			*key = zend_string_init(ptr, end - ptr, 0);
			break;
		case 1:
			*key = ZSTR_CHAR(*name.value);
			break;
		default:
			if (is_prop) {
				*key = zend_string_init_interned((char *) name.value, name.length, 0);
			} else {
				*key = zend_string_from_ion(&name);
			}
			break;
		}
	} else {
		zval z_fn;
		ZVAL_UNDEF(&z_fn);
		zend_call_method_with_0_params(&ser->std, NULL, NULL, "getFieldName", &z_fn);
		if (!Z_STRLEN(z_fn) || EG(exception)) {
			zend_clear_exception();
			zend_call_method_with_0_params(&ser->std, NULL, NULL, "getFieldNameSymbol", &z_fn);
			ION_CATCH();

		}
		*key = zval_get_string(&z_fn);
		zval_ptr_dtor(&z_fn);
	}
}

static void php_ion_unserialize_props(php_ion_unserializer *ser, zval *return_value)
{
	zend_hash_next_index_insert(ser->ids, return_value);

	if (can_unserialize_fast(ser)) {
		ION_CHECK(ion_reader_step_in(php_ion_obj(reader, ser->rdr)->reader));
	} else {
		zend_call_method_with_0_params(&ser->std, NULL, NULL, "getChildren", NULL);
		ION_CATCH();
	}

	while (true) {
		ION_TYPE typ;
		php_ion_unserializer_next(ser, &typ);
		ION_CATCH();

		if (typ == tid_EOF) {
			break;
		}

		zend_string *key;
		php_ion_unserialize_field_name(ser, &key, true);
		ION_CATCH();

		zval zvalue;
		ZVAL_UNDEF(&zvalue);
		php_ion_unserialize_zval(ser, &zvalue, &typ);
		ION_CATCH(zend_string_release(key));

		zend_class_entry *ce = Z_OBJCE_P(return_value);
		if (ser->annotations.object_prop && ser->annotations.property_class->val[0] != '*') {
			ce = zend_lookup_class(ser->annotations.property_class);
		}
		zend_update_property_ex(ce, Z_OBJ_P(return_value), key, &zvalue);
		zval_ptr_dtor(&zvalue);
		zend_string_release(key);
	}

	if (can_unserialize_fast(ser)) {
		ION_CHECK(ion_reader_step_out(php_ion_obj(reader, ser->rdr)->reader));
	}
}

/**
 * @link https://amzn.github.io/ion-docs/docs/spec.html#struct
 * When two fields in the same struct have the same name [...] Implementations must preserve all such fields,
 * i.e., they may not discard fields that have repeated names. However, implementations may reorder fields
 * (the binary format identifies structs that are sorted by symbolID), so certain operations may lead to
 * nondeterministic behavior.
 */
static void php_ion_unserialize_hash(php_ion_unserializer *ser, zval *return_value)
{
	zend_hash_next_index_insert(ser->ids, return_value);

	if (can_unserialize_fast(ser)) {
		ION_CHECK(ion_reader_step_in(php_ion_obj(reader, ser->rdr)->reader));
	} else {
		zend_call_method_with_0_params(&ser->std, NULL, NULL, "getChildren", NULL);
		ION_CATCH();
	}

	while (true) {
		ION_TYPE typ;
		php_ion_unserializer_next(ser, &typ);
		ION_CATCH();

		if (typ == tid_EOF) {
			break;
		}

		zend_string *key;
		php_ion_unserialize_field_name(ser, &key, false);
		ION_CATCH();

		zval zvalue;
		php_ion_unserialize_zval(ser, &zvalue, &typ);
		ION_CATCH(zend_string_release(key));

		// FIXME:: too naive; b0rked if the previous value is an array
		if (zend_symtable_exists(HASH_OF(return_value), key)) {
			zval tmp, *prev = zend_hash_find(HASH_OF(return_value), key);
			if (Z_TYPE_P(prev) != IS_ARRAY) {
				array_init(&tmp);
				Z_TRY_ADDREF_P(prev);
				zend_hash_next_index_insert(Z_ARRVAL(tmp), prev);
				prev = zend_hash_update(HASH_OF(return_value), key, &tmp);
			}
			zend_hash_next_index_insert(Z_ARRVAL_P(prev), &zvalue);
		} else {
			zend_symtable_update(HASH_OF(return_value), key, &zvalue);
		}
		zend_string_release(key);
	}

	if (can_unserialize_fast(ser)) {
		ION_CHECK(ion_reader_step_out(php_ion_obj(reader, ser->rdr)->reader));
	}
}

static void verify_unserializer(php_ion_unserializer *ser, zend_object *zobject, zend_function **fn)
{
	switch (ser->annotations.object_type) {
	case 'c':
		*fn = NULL;
		break;

	case 'C':
		if (!can_call_custom_unserialize(ser, zobject, fn)) {
			zend_throw_exception_ex(ce_Exception, IERR_INVALID_TOKEN,
					"Could not find custom serializer method of %s", ser->annotations.object_class->val);
		}
		break;

	case 'O':
		if (!can_call_magic_unserialize(ser, zobject->ce)) {
			zend_throw_exception_ex(ce_Exception, IERR_INVALID_TOKEN,
					"Could not find method %s::__unserialize()", ser->annotations.object_class->val);
		}
		*fn = zobject->ce->__unserialize;
		break;

	default:
		zend_throw_exception_ex(ce_Exception, IERR_INVALID_TOKEN,
				"Invalid object type %c", ser->annotations.object_type);
	}
}

static void php_ion_unserialize_object(php_ion_unserializer *ser, zval *return_value)
{
	// backup possible backref to array returned by magic/custom __serialize()
	zval *input = zend_hash_next_index_insert(ser->tmp, return_value);
	ZVAL_NULL(return_value);
	php_ion_unserialize_class(ser, return_value);
	ION_CATCH();

	zend_function *fn = NULL;
	zend_object *zobject = Z_OBJ_P(return_value);
	verify_unserializer(ser, zobject, &fn);
	ION_CATCH();

	// plain object
	if (!fn) {
		php_ion_unserialize_props(ser, return_value);
		return;
	}

	// magic object
	if (Z_TYPE_P(input) != IS_ARRAY) {
		zval_ptr_dtor(input);
		array_init(input);
		zend_hash_real_init_mixed(Z_ARRVAL_P(input));
		php_ion_unserialize_hash(ser, input);
		ION_CATCH();
	}
	zval rv;
	ZVAL_NULL(&rv);
	zend_call_method_with_1_params(zobject, zobject->ce, &fn, "", &rv, input);
	zval_ptr_dtor(&rv);
}

static void php_ion_unserialize_struct(php_ion_unserializer *ser, zval *return_value)
{
	if (ser->annotations.object_class) {
		switch (ser->annotations.object_type) {
		case 'S':
			php_ion_unserialize_object_iface(ser, return_value);
			break;
		case 'E':
			php_ion_unserialize_object_enum(ser, return_value);
			break;
		default:
			php_ion_unserialize_object(ser, return_value);
		}
	} else if (!ser->annotations.object_type) {
		bool is_shared_symtab = ser->annotations.shared_symtab;
		array_init(return_value);
		php_ion_unserialize_hash(ser, return_value);
		if (is_shared_symtab) {
			zend_object *zo_ss = object_construct(ce_Symbol_Table_Shared, 0, NULL, Z_ARRVAL_P(return_value));
			zval_ptr_dtor(return_value);
			RETURN_OBJ(zo_ss);
		}
	} else if (ser->annotations.object_type == 'o') {
		object_init(return_value);
		php_ion_unserialize_hash(ser, return_value);
	} else {
		zend_throw_exception_ex(ce_Exception, IERR_INVALID_TOKEN,
				"Invalid object annotation %c::", ser->annotations.object_type);
	}
}

static void php_ion_unserialize_list(php_ion_unserializer *ser, zval *return_value)
{
	if (can_unserialize_fast(ser)) {
		ION_CHECK(ion_reader_step_in(php_ion_obj(reader, ser->rdr)->reader));
	} else {
		zend_call_method_with_0_params(&ser->std, NULL, NULL, "getChildren", NULL);
	}
	array_init(return_value);
	zend_hash_next_index_insert(ser->ids, return_value);

	while (true) {
		ION_TYPE typ;
		php_ion_unserializer_next(ser, &typ);
		ION_CATCH();

		if (typ == tid_EOF) {
			break;
		}

		zval next;
		php_ion_unserialize_zval(ser, &next, &typ);
		ION_CATCH();

		zend_hash_next_index_insert(Z_ARRVAL_P(return_value), &next);
	}

	if (can_unserialize_fast(ser)) {
		ION_CHECK(ion_reader_step_out(php_ion_obj(reader, ser->rdr)->reader));
	} else {
		// userland reader object already stepped out
	}
}

static void php_ion_reader_read_lob(ION_READER *reader, zval *return_value)
{
	zend_string *zstr = zend_string_alloc(0x1000, 0);
again: ;
	SIZE read = 0;
	iERR err = ion_reader_read_lob_bytes(reader, (BYTE *) zstr->val, (SIZE) zstr->len, &read);
	if (err == IERR_BUFFER_TOO_SMALL) {
		zstr = zend_string_extend(zstr, zstr->len << 2, 0);
		goto again;
	}
	ION_CHECK(err, zend_string_release(zstr));
	if (zstr->len > read) {
		zstr->val[read] = 0;
		zstr = zend_string_truncate(zstr, read, 0);
	}
	RETURN_STR(zstr);
}

static void php_ion_reader_read_timestamp(ION_READER *reader, ION_READER_OPTIONS *opt, zval *return_value)
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

static void php_ion_reader_read_int(ION_READER *reader, zval *return_value)
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

	case IERR_NUMERIC_OVERFLOW: ;
		SIZE max, len;
		ION_CHECK(ion_int_char_length(num, &max));
		zend_string *zs = zend_string_alloc(max, 0);

		err = ion_int_to_char(num, (BYTE *) zs->val, max, &len);
		zs->val[zs->len = len] = 0;
		RETVAL_STR(zs);
		/* fall through */

	default:
	done:
		ion_int_free(num);
		ION_CHECK(err);
	}
}

static void php_ion_unserialize_backref(php_ion_unserializer *ser, zval *return_value)
{
	zval *backref = zend_hash_index_find(ser->ids, Z_LVAL_P(return_value));

	if (backref) {
		ZVAL_COPY_VALUE(return_value, backref);
		zend_hash_next_index_insert(ser->addref, return_value);
	} else {
		zend_throw_exception_ex(ce_Exception, IERR_INTERNAL_ERROR,
				"Could not find back reference " ZEND_LONG_FMT, Z_LVAL_P(return_value));
	}
}

static zend_string *php_ion_unserialize_annotation(php_ion_unserializer *ser, zend_long idx)
{
	zval z_ann;

	if (can_unserialize_fast(ser)) {
		ION_STRING ann_str;
		ION_CHECK_RETURN(NULL, ion_reader_get_an_annotation(php_ion_obj(reader, ser->rdr)->reader, idx, &ann_str));

		if (ann_str.length == 1){
			// no need to remember interned string
			ZVAL_CHAR(&z_ann, *ann_str.value);
		} else {
			ZVAL_STRINGL(&z_ann, (char *) ann_str.value, ann_str.length);
			zend_hash_next_index_insert(ser->tmp, &z_ann);
		}
	} else {
		zval z_idx;
		ZVAL_LONG(&z_idx, idx);
		zend_call_method_with_1_params(&ser->std, NULL, NULL, "getAnnotation", &z_ann, &z_idx);
		ION_CATCH_RETURN(NULL);
		zend_hash_next_index_insert(ser->tmp, &z_ann);
	}

	return Z_STR(z_ann);
}

static void php_ion_unserialize_annotations(php_ion_unserializer *ser)
{
	memset(&ser->annotations, 0, sizeof(ser->annotations));

	int32_t ann_cnt;
	if (can_unserialize_fast(ser)) {
		ION_CHECK(ion_reader_get_annotation_count(php_ion_obj(reader, ser->rdr)->reader, &ann_cnt));
	} else {
		zval z_ann_cnt;
		zend_call_method_with_0_params(&ser->std, NULL, NULL, "countAnnotations", &z_ann_cnt);
		ION_CATCH();
		ann_cnt = Z_LVAL(z_ann_cnt);
	}

	for (int32_t i = 0; i < ann_cnt; ++i) {
		zend_string *zs_ann = php_ion_unserialize_annotation(ser, i);

		if (zs_ann->len != 1) {
			if (zend_string_equals_literal(zs_ann, ION_SYS_SYMBOL_SHARED_SYMBOL_TABLE)) {
				ser->annotations.shared_symtab = true;
			}

			continue;
		}

		switch (*zs_ann->val) {
		default:
			// ignore
			break;

		case 'R':
			if (ser->annotations.makeref) {
				zend_throw_exception_ex(ce_Exception, IERR_INVALID_SYNTAX,
						"Invalid multiple reference annotations");
				return;
			}
			ser->annotations.makeref = true;
			break;

		case 'r':
			if (ser->annotations.backref) {
				zend_throw_exception_ex(ce_Exception, IERR_INVALID_SYNTAX,
						"Invalid multiple back reference annotations");
				return;
			}
			ser->annotations.backref = true;
			break;

		case 'p':
			if (ser->annotations.object_prop) {
				zend_throw_exception_ex(ce_Exception, IERR_INVALID_SYNTAX,
						"Invalid multiple object property annotations");
				return;
			}
			ser->annotations.object_prop = true;
			ser->annotations.property_class = php_ion_unserialize_annotation(ser, ++i);
			ION_CATCH();
			break;

		case 'E':
		case 'S':
		case 'O':
		case 'C':
		case 'o':
		case 'c':
			if (ser->annotations.object_type) {
				zend_throw_exception_ex(ce_Exception, IERR_INVALID_SYNTAX,
						"Invalid multiple object type annotations: %c::%c",
						ser->annotations.object_type, *zs_ann->val);
				return;
			}

			ser->annotations.object_type = *zs_ann->val;
			if (ser->annotations.object_type != 'o') {
				ser->annotations.object_class = php_ion_unserialize_annotation(ser, ++i);
				ION_CATCH();
			}
			break;
		}

		// sanity checks
		if (ser->annotations.object_type && ser->annotations.object_type != 'o' && !ser->annotations.object_class) {
			zend_throw_exception_ex(ce_Exception, IERR_INVALID_SYNTAX,
					"Invalid object annotation without class name: %c::", ser->annotations.object_type);
			return;
		}
		if (ser->annotations.object_type == 'o' && ser->annotations.object_class) {
			zend_throw_exception_ex(ce_Exception, IERR_INVALID_SYNTAX,
					"Invalid object annotation with class name: o::%s", ser->annotations.object_class->val);
			return;
		}
	}
}

static void php_ion_unserialize_zval(php_ion_unserializer *ser, zval *return_value, ION_TYPE *typ)
{
	if (typ) {
		memcpy(&ser->type, typ, sizeof(ser->type)); // NOLINT
	} else {
		typ = &ser->type;
		if (can_unserialize_fast(ser)) {
			ION_CHECK(ion_reader_next(php_ion_obj(reader, ser->rdr)->reader, typ));
		} else {
			zend_call_method_with_0_params(&ser->std, NULL, NULL, "next", NULL);
			ION_CATCH();

			zval z_type;
			zend_call_method_with_0_params(&ser->std, NULL, NULL, "getType", &z_type);
			ION_CATCH();
			*typ = ion_type_from_enum(Z_OBJ_P(return_value));
		}
	}

	php_ion_unserialize_annotations(ser);
	ION_CATCH();

	if (ser->annotations.makeref) {
		ZVAL_MAKE_REF(return_value);
		zend_hash_next_index_insert(ser->ids, return_value);
		ZVAL_DEREF(return_value);
	}

	if (ION_TYPE_INT(*typ) > 0) {
		BOOL is_null;
		if (can_unserialize_fast(ser)) {
			ION_CHECK(ion_reader_is_null(php_ion_obj(reader, ser->rdr)->reader, &is_null));
		} else  {
			zval z_is_null;
			zend_call_method_with_0_params(&ser->std, NULL, NULL, "isNull", &z_is_null);
			is_null = i_zend_is_true(&z_is_null);
		}
		if (is_null) {
			RETURN_NULL();
		}
	}

	switch (ION_TYPE_INT(*typ)) {
	case tid_NULL_INT:
		if (can_unserialize_fast(ser)) {
			ION_CHECK(ion_reader_read_null(php_ion_obj(reader, ser->rdr)->reader, typ));
		} else {
			zend_call_method_with_0_params(&ser->std, NULL, NULL, "readNull", return_value);
			ION_CATCH();
			*typ = ion_type_from_enum(Z_OBJ_P(return_value));
		}
		RETURN_NULL();

	case tid_BOOL_INT:
		if (can_unserialize_fast(ser)) {
			BOOL bval;
			ION_CHECK(ion_reader_read_bool(php_ion_obj(reader, ser->rdr)->reader, &bval));
			RETURN_BOOL(bval);
		} else {
			zend_call_method_with_0_params(&ser->std, NULL, NULL, "readBool", return_value);
			return;
		}

	case tid_INT_INT:
		if (can_unserialize_fast(ser)) {
			php_ion_reader_read_int(php_ion_obj(reader, ser->rdr)->reader, return_value);
		} else {
			zend_call_method_with_0_params(&ser->std, NULL, NULL, "readInt", return_value);
		}
		if (ser->annotations.backref) {
			ION_CATCH();
			php_ion_unserialize_backref(ser, return_value);
		}
		if (ser->annotations.object_type) {
			if (!ser->annotations.backref) {
				zend_throw_exception_ex(ce_Exception, IERR_INVALID_SYNTAX,
						"Invalid object type annotation: %c::" ZEND_LONG_FMT,
						ser->annotations.object_type, Z_LVAL_P(return_value));
				return;
			}
			goto unserialize_struct;
		}
		return;

	case tid_FLOAT_INT:
		if (can_unserialize_fast(ser)) {
			double d;
			ION_CHECK(ion_reader_read_double(php_ion_obj(reader, ser->rdr)->reader, &d));
			RETURN_DOUBLE(d);
		} else {
			zend_call_method_with_0_params(&ser->std, NULL, NULL, "readFloat", return_value);
			return;
		}

	case tid_DECIMAL_INT:
		if (can_unserialize_fast(ser)) {
			object_init_ex(return_value, ce_Decimal);
			php_ion_decimal *dec = php_ion_obj(decimal, Z_OBJ_P(return_value));
			ION_CHECK(ion_reader_read_ion_decimal(php_ion_obj(reader, ser->rdr)->reader, &dec->dec));
			php_ion_decimal_ctor(dec);
		} else {
			zend_call_method_with_0_params(&ser->std, NULL, NULL, "readDecimal", return_value);
			ION_CATCH();
		}
		zend_hash_next_index_insert(ser->ids, return_value);
		return;

	case tid_TIMESTAMP_INT:
		if (can_unserialize_fast(ser)) {
			php_ion_reader *reader = php_ion_obj(reader, ser->rdr);
			php_ion_reader_read_timestamp(reader->reader, &reader->options, return_value);
		} else {
			zend_call_method_with_0_params(&ser->std, NULL, NULL, "readTimestamp", return_value);
		}
		ION_CATCH();
		zend_hash_next_index_insert(ser->ids, return_value);
		return;

	case tid_SYMBOL_INT:
		if (can_unserialize_fast(ser)) {
			ION_SYMBOL sym;
			ION_CHECK(ion_reader_read_ion_symbol(php_ion_obj(reader, ser->rdr)->reader, &sym));
			php_ion_symbol_zval(&sym, return_value);
		} else {
			zend_call_method_with_0_params(&ser->std, NULL, NULL, "readSymbol", return_value);
		}
		ION_CATCH();
		if (ser->annotations.object_type) {
			goto unserialize_struct;
		}
		zend_hash_next_index_insert(ser->ids, return_value);
		return;

	case tid_STRING_INT:
		if (can_unserialize_fast(ser)) {
			ION_STRING str;
			ION_CHECK(ion_reader_read_string(php_ion_obj(reader, ser->rdr)->reader, &str));
			RETVAL_STRINGL((char *) str.value, str.length);
		} else {
			zend_call_method_with_0_params(&ser->std, NULL, NULL, "readString", return_value);
			ION_CATCH();
		}
		if (ser->annotations.object_type) {
			goto unserialize_struct;
		}
		zend_hash_next_index_insert(ser->ids, return_value);
		return;

	case tid_CLOB_INT:
	case tid_BLOB_INT:
		if (can_unserialize_fast(ser)) {
			php_ion_reader_read_lob(php_ion_obj(reader, ser->rdr)->reader, return_value);
		} else {
			zend_call_method_with_0_params(&ser->std, NULL, NULL, *typ == tid_BLOB ? "readBLob" : "readCLob", return_value);
		}
		ION_CATCH();
		if (ser->annotations.object_type) {
			goto unserialize_struct;
		}
		zend_hash_next_index_insert(ser->ids, return_value);
		return;

	case tid_LIST_INT:
	case tid_SEXP_INT: // FIXME
		php_ion_unserialize_list(ser, return_value);
		ION_CATCH();
		if (!ser->annotations.object_type) {
			return;
		}
		/* fall through */

	case tid_STRUCT_INT:
unserialize_struct: ;
		php_ion_unserialize_struct(ser, return_value);
		return;

	case tid_none_INT:
		ZEND_ASSERT(!"none");
		break;

	case tid_DATAGRAM_INT:
		ZEND_ASSERT(!"datagram");
	case tid_EOF_INT:
		return;
	}
}

#define php_ion_unserializer_copy(o,n)
php_ion_decl(unserializer, Unserializer_Unserializer);
#define clone_ion_Unserializer NULL

static void php_ion_unserialize_ex(php_ion_unserializer *ser, zval *return_value)
{
	if (ser->multi_seq) {
		array_init(return_value);
	}

	do {
		zval tmp;
		ZVAL_NULL(&tmp);
		php_ion_globals_unserializer_step();
		php_ion_unserialize_zval(ser, &tmp, NULL);
		php_ion_globals_unserializer_exit();
		ION_CATCH(zval_ptr_dtor(&tmp));

		if (!ser->multi_seq) {
			RETURN_COPY_VALUE(&tmp);
		} else if (ser->type != tid_EOF) {
			zend_hash_next_index_insert(Z_ARRVAL_P(return_value), &tmp);
		}
	} while (ser->type != tid_EOF);
}

static php_ion_reader *create_unserialize_reader(zval *zdata)
{
	ZVAL_DEREF(zdata);

	if (Z_TYPE_P(zdata) == IS_OBJECT && instanceof_function(Z_OBJCE_P(zdata), ce_Reader)) {
		Z_ADDREF_P(zdata);
		return php_ion_obj(reader, Z_OBJ_P(zdata));
	} else {
		zend_object *zo_reader = NULL;
		php_ion_reader *reader = NULL;

		if (Z_TYPE_P(zdata) == IS_RESOURCE) {
			zo_reader = create_ion_Reader_Reader(ce_Reader_Stream_Reader);
			reader = php_ion_obj(reader, zo_reader);
			reader->type = STREAM_READER;
			php_stream_from_zval_no_verify(reader->stream.ptr, zdata);
			PTR_CHECK_RETURN(NULL, reader->stream.ptr, OBJ_RELEASE(zo_reader));
			GC_ADDREF(reader->stream.ptr->res);
			php_ion_reader_ctor(reader);
		} else if (Z_TYPE_P(zdata) <= IS_STRING) {
			zo_reader = create_ion_Reader_Reader(ce_Reader_Buffer_Reader);
			reader = php_ion_obj(reader, zo_reader);
			reader->type = BUFFER_READER;
			reader->buffer = zval_get_string(zdata);
			ION_CATCH_RETURN(NULL, OBJ_RELEASE(zo_reader));
			php_ion_reader_ctor(reader);
		} else {
			zend_throw_exception_ex(ce_Exception, IERR_INVALID_ARG,
									"Invalid source to unserialize: expected string or resource, got %s",
									zend_zval_type_name(zdata));
		}

		ION_CATCH_RETURN(NULL, if (zo_reader) {
			OBJ_RELEASE(zo_reader);
		});
		return reader;
	}
}

void php_ion_unserialize(php_ion_unserializer *ser, zval *zdata, zval *return_value)
{
	zend_object *zo_ser = NULL;

	if (!ser) {
		zo_ser = create_ion_Unserializer_Unserializer(NULL);
		ser = php_ion_obj(unserializer, zo_ser);
		PTR_CHECK(ser);
		ser->call_magic = true;
		php_ion_unserializer_ctor(ser);
		ION_CATCH();
	}

	php_ion_reader *reader = create_unserialize_reader(zdata);
	if (reader) {
		ser->rdr = &reader->std;
		if (!EG(exception)) {
			php_ion_unserialize_ex(ser, return_value);
		}
		OBJ_RELEASE(&reader->std);
		ser->rdr = NULL;
	}

	if (zo_ser) {
		OBJ_RELEASE(zo_ser);
	}
}
