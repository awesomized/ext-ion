/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 771b0ba1db693b7506ff427a667d029630caca09 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ion_serialize, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_MIXED, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, serializer, ion\\Serializer, MAY_BE_ARRAY|MAY_BE_NULL, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ion_unserialize, 0, 1, IS_MIXED, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_OBJ_TYPE_MASK(0, unserializer, ion\\Unserializer, MAY_BE_ARRAY|MAY_BE_NULL, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Serializer_serialize, 0, 1, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_MIXED, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, writer, ion\\Writer|ion\\Writer\\Options, MAY_BE_ARRAY|MAY_BE_NULL, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Unserializer_unserialize, 0, 1, IS_MIXED, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Symbol___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, value, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, sid, IS_LONG, 0, "-1")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, importLocation, ion\\Symbol\\ImportLocation, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Symbol_equals, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, symbol, ion\\Symbol, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Symbol___toString, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Symbol_toString arginfo_class_ion_Symbol___toString

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Catalog___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Catalog_count, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Catalog_add, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, table, ion\\Symbol\\Table, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Catalog_remove, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, table, ion\\Symbol\\Table, MAY_BE_STRING, NULL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_ion_Catalog_find, 0, 1, ion\\Symbol\\Table, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, version, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Catalog_findBest arginfo_class_ion_Catalog_find

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_LOB___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, type, ion\\Type, 0, "ion\\Type::CLob")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Decimal___construct, 0, 0, 1)
	ZEND_ARG_TYPE_MASK(0, number, MAY_BE_STRING|MAY_BE_LONG, NULL)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, context, ion\\Decimal\\Context, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Decimal_equals, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, decimal, ion\\Decimal, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Decimal_isInt, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Decimal___toString arginfo_class_ion_Symbol___toString

#define arginfo_class_ion_Decimal_toString arginfo_class_ion_Symbol___toString

#define arginfo_class_ion_Decimal_toInt arginfo_class_ion_Catalog_count

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Timestamp___construct, 0, 0, 1)
	ZEND_ARG_OBJ_TYPE_MASK(0, precision, ion\\Timestamp\\Precision, MAY_BE_LONG, NULL)
	ZEND_ARG_OBJ_TYPE_MASK(0, format, ion\\Timestamp\\Format, MAY_BE_STRING|MAY_BE_NULL, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, datetime, IS_STRING, 1, "null")
	ZEND_ARG_OBJ_TYPE_MASK(0, timezone, DateTimeZone, MAY_BE_STRING|MAY_BE_NULL, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Timestamp___toString arginfo_class_ion_Symbol___toString

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_ion_Reader_getType, 0, 0, ion\\Type, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Reader_hasAnnotations arginfo_class_ion_Decimal_isInt

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Reader_hasAnnotation, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, annotation, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Reader_isNull arginfo_class_ion_Decimal_isInt

#define arginfo_class_ion_Reader_isInStruct arginfo_class_ion_Decimal_isInt

#define arginfo_class_ion_Reader_getFieldName arginfo_class_ion_Symbol___toString

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_ion_Reader_getFieldNameSymbol, 0, 0, ion\\Symbol, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Reader_getAnnotations, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Reader_getAnnotationSymbols arginfo_class_ion_Reader_getAnnotations

#define arginfo_class_ion_Reader_countAnnotations arginfo_class_ion_Catalog_count

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Reader_getAnnotation, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_ion_Reader_getAnnotationSymbol, 0, 1, ion\\Symbol, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Reader_readNull arginfo_class_ion_Reader_getType

#define arginfo_class_ion_Reader_readBool arginfo_class_ion_Decimal_isInt

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_ion_Reader_readInt, 0, 0, MAY_BE_LONG|MAY_BE_STRING)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Reader_readFloat, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_ion_Reader_readDecimal, 0, 0, ion\\Decimal, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_ion_Reader_readTimestamp, 0, 0, ion\\Timestamp, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Reader_readSymbol arginfo_class_ion_Reader_getFieldNameSymbol

#define arginfo_class_ion_Reader_readString arginfo_class_ion_Symbol___toString

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Reader_readStringPart, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(1, string)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 0, "0x1000")
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Reader_readLob arginfo_class_ion_Symbol___toString

#define arginfo_class_ion_Reader_readLobPart arginfo_class_ion_Reader_readStringPart

#define arginfo_class_ion_Reader_getPosition arginfo_class_ion_Catalog_count

#define arginfo_class_ion_Reader_getDepth arginfo_class_ion_Catalog_count

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Reader_seek, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 0, "-1")
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Reader_getValueOffset arginfo_class_ion_Catalog_count

#define arginfo_class_ion_Reader_getValueLength arginfo_class_ion_Catalog_count

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Writer_writeNull, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Writer_writeTypedNull, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, type, ion\\Type, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Writer_writeBool, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, value, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Writer_writeInt, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_MASK(0, value, MAY_BE_LONG|MAY_BE_STRING, NULL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Writer_writeFloat, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Writer_writeDecimal, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, value, ion\\Decimal, MAY_BE_STRING, NULL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Writer_writeTimestamp, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, value, ion\\Timestamp, MAY_BE_STRING, NULL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Writer_writeSymbol, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, value, ion\\Symbol, MAY_BE_STRING, NULL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Writer_writeString, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Writer_writeCLob arginfo_class_ion_Writer_writeString

#define arginfo_class_ion_Writer_writeBLob arginfo_class_ion_Writer_writeString

#define arginfo_class_ion_Writer_startLob arginfo_class_ion_Writer_writeTypedNull

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Writer_appendLob, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Writer_finishLob arginfo_class_ion_Writer_writeNull

#define arginfo_class_ion_Writer_startContainer arginfo_class_ion_Writer_writeTypedNull

#define arginfo_class_ion_Writer_finishContainer arginfo_class_ion_Writer_writeNull

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Writer_writeFieldName, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Writer_writeAnnotation, 0, 0, IS_VOID, 0)
	ZEND_ARG_VARIADIC_OBJ_TYPE_MASK(0, annotation, ion\\Symbol, MAY_BE_STRING, NULL)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Writer_getDepth arginfo_class_ion_Catalog_count

#define arginfo_class_ion_Writer_flush arginfo_class_ion_Catalog_count

#define arginfo_class_ion_Writer_finish arginfo_class_ion_Catalog_count

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Symbol_ImportLocation___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Symbol_Enum_toSymbol arginfo_class_ion_Reader_getFieldNameSymbol

#define arginfo_class_ion_Symbol_Enum_toSID arginfo_class_ion_Catalog_count

#define arginfo_class_ion_Symbol_Enum_toString arginfo_class_ion_Symbol___toString

#define arginfo_class_ion_Symbol_Table_getMaxId arginfo_class_ion_Catalog_count

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Symbol_Table_add, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, symbol, ion\\Symbol, MAY_BE_STRING, NULL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_ion_Symbol_Table_find, 0, 1, ion\\Symbol, 1)
	ZEND_ARG_TYPE_MASK(0, id, MAY_BE_STRING|MAY_BE_LONG, NULL)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Symbol_Table_findLocal arginfo_class_ion_Symbol_Table_find

#define arginfo_class_ion_Symbol_System_toSymbol arginfo_class_ion_Reader_getFieldNameSymbol

#define arginfo_class_ion_Symbol_System_toSID arginfo_class_ion_Catalog_count

#define arginfo_class_ion_Symbol_System_toString arginfo_class_ion_Symbol___toString

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_ion_Symbol_System_asTable, 0, 0, ion\\Symbol\\Table\\Shared, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Symbol_PHP_toSymbol arginfo_class_ion_Reader_getFieldNameSymbol

#define arginfo_class_ion_Symbol_PHP_toSID arginfo_class_ion_Catalog_count

#define arginfo_class_ion_Symbol_PHP_toString arginfo_class_ion_Symbol___toString

#define arginfo_class_ion_Symbol_PHP_asTable arginfo_class_ion_Symbol_System_asTable

#define arginfo_class_ion_Symbol_Table_Local___construct arginfo_class_ion_Catalog___construct

#define arginfo_class_ion_Symbol_Table_Local_import arginfo_class_ion_Catalog_add

#define arginfo_class_ion_Symbol_Table_Local_getMaxId arginfo_class_ion_Catalog_count

#define arginfo_class_ion_Symbol_Table_Local_add arginfo_class_ion_Symbol_Table_add

#define arginfo_class_ion_Symbol_Table_Local_find arginfo_class_ion_Symbol_Table_find

#define arginfo_class_ion_Symbol_Table_Local_findLocal arginfo_class_ion_Symbol_Table_find

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Symbol_Table_Shared___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, version, IS_LONG, 0, "1")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, symbols, IS_ARRAY, 1, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Symbol_Table_Shared_getMaxId arginfo_class_ion_Catalog_count

#define arginfo_class_ion_Symbol_Table_Shared_add arginfo_class_ion_Symbol_Table_add

#define arginfo_class_ion_Symbol_Table_Shared_find arginfo_class_ion_Symbol_Table_find

#define arginfo_class_ion_Symbol_Table_Shared_findLocal arginfo_class_ion_Symbol_Table_find

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Decimal_Context___construct, 0, 0, 5)
	ZEND_ARG_TYPE_INFO(0, digits, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, eMax, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, eMin, IS_LONG, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, round, ion\\Decimal\\Context\\Rounding, MAY_BE_LONG, NULL)
	ZEND_ARG_TYPE_INFO(0, clamp, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_ion_Decimal_Context_Dec32, 0, 0, ion\\Decimal\\Context, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Decimal_Context_Dec64 arginfo_class_ion_Decimal_Context_Dec32

#define arginfo_class_ion_Decimal_Context_Dec128 arginfo_class_ion_Decimal_Context_Dec32

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_ion_Decimal_Context_DecMax, 0, 0, ion\\Decimal\\Context, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, round, ion\\Decimal\\Context\\Rounding, MAY_BE_LONG, "ion\\Decimal\\Context\\Rounding::HalfEven")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Reader_Options___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, catalog, ion\\Catalog, 1, "null")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, decimalContext, ion\\Decimal\\Context, 1, "null")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, onContextChange, Closure, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, returnSystemValues, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxContainerDepth, IS_LONG, 0, "10")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxAnnotations, IS_LONG, 0, "10")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, annotationBufferSize, IS_LONG, 0, "0x4000")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, tempBufferSize, IS_LONG, 0, "0x4000")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, skipCharacterValidation, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Reader_Reader_hasChildren arginfo_class_ion_Decimal_isInt

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_ion_Reader_Reader_getChildren, 0, 0, ion\\Reader, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Reader_Reader_rewind arginfo_class_ion_Writer_writeNull

#define arginfo_class_ion_Reader_Reader_next arginfo_class_ion_Writer_writeNull

#define arginfo_class_ion_Reader_Reader_valid arginfo_class_ion_Decimal_isInt

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Reader_Reader_key, 0, 0, IS_MIXED, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Reader_Reader_current arginfo_class_ion_Reader_Reader_key

#define arginfo_class_ion_Reader_Reader_getType arginfo_class_ion_Reader_getType

#define arginfo_class_ion_Reader_Reader_hasAnnotations arginfo_class_ion_Decimal_isInt

#define arginfo_class_ion_Reader_Reader_hasAnnotation arginfo_class_ion_Reader_hasAnnotation

#define arginfo_class_ion_Reader_Reader_isNull arginfo_class_ion_Decimal_isInt

#define arginfo_class_ion_Reader_Reader_isInStruct arginfo_class_ion_Decimal_isInt

#define arginfo_class_ion_Reader_Reader_getFieldName arginfo_class_ion_Symbol___toString

#define arginfo_class_ion_Reader_Reader_getFieldNameSymbol arginfo_class_ion_Reader_getFieldNameSymbol

#define arginfo_class_ion_Reader_Reader_getAnnotations arginfo_class_ion_Reader_getAnnotations

#define arginfo_class_ion_Reader_Reader_getAnnotationSymbols arginfo_class_ion_Reader_getAnnotations

#define arginfo_class_ion_Reader_Reader_countAnnotations arginfo_class_ion_Catalog_count

#define arginfo_class_ion_Reader_Reader_getAnnotation arginfo_class_ion_Reader_getAnnotation

#define arginfo_class_ion_Reader_Reader_getAnnotationSymbol arginfo_class_ion_Reader_getAnnotationSymbol

#define arginfo_class_ion_Reader_Reader_readNull arginfo_class_ion_Reader_getType

#define arginfo_class_ion_Reader_Reader_readBool arginfo_class_ion_Decimal_isInt

#define arginfo_class_ion_Reader_Reader_readInt arginfo_class_ion_Reader_readInt

#define arginfo_class_ion_Reader_Reader_readFloat arginfo_class_ion_Reader_readFloat

#define arginfo_class_ion_Reader_Reader_readDecimal arginfo_class_ion_Reader_readDecimal

#define arginfo_class_ion_Reader_Reader_readTimestamp arginfo_class_ion_Reader_readTimestamp

#define arginfo_class_ion_Reader_Reader_readSymbol arginfo_class_ion_Reader_getFieldNameSymbol

#define arginfo_class_ion_Reader_Reader_readString arginfo_class_ion_Symbol___toString

#define arginfo_class_ion_Reader_Reader_readStringPart arginfo_class_ion_Reader_readStringPart

#define arginfo_class_ion_Reader_Reader_readLob arginfo_class_ion_Symbol___toString

#define arginfo_class_ion_Reader_Reader_readLobPart arginfo_class_ion_Reader_readStringPart

#define arginfo_class_ion_Reader_Reader_getPosition arginfo_class_ion_Catalog_count

#define arginfo_class_ion_Reader_Reader_getDepth arginfo_class_ion_Catalog_count

#define arginfo_class_ion_Reader_Reader_seek arginfo_class_ion_Reader_seek

#define arginfo_class_ion_Reader_Reader_getValueOffset arginfo_class_ion_Catalog_count

#define arginfo_class_ion_Reader_Reader_getValueLength arginfo_class_ion_Catalog_count

#define arginfo_class_ion_Reader_Buffer_getBuffer arginfo_class_ion_Symbol___toString

#define arginfo_class_ion_Reader_Stream_getStream arginfo_class_ion_Catalog___construct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Reader_Stream_resetStream, 0, 1, IS_VOID, 0)
	ZEND_ARG_INFO(0, stream)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Reader_Stream_resetStreamWithLength, 0, 2, IS_VOID, 0)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Reader_Buffer_Reader___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_STRING, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, options, ion\\Reader\\Options, MAY_BE_ARRAY|MAY_BE_NULL, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Reader_Buffer_Reader_getBuffer arginfo_class_ion_Symbol___toString

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Reader_Stream_Reader___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_OBJ_TYPE_MASK(0, options, ion\\Reader\\Options, MAY_BE_ARRAY|MAY_BE_NULL, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Reader_Stream_Reader_getStream arginfo_class_ion_Catalog___construct

#define arginfo_class_ion_Reader_Stream_Reader_resetStream arginfo_class_ion_Reader_Stream_resetStream

#define arginfo_class_ion_Reader_Stream_Reader_resetStreamWithLength arginfo_class_ion_Reader_Stream_resetStreamWithLength

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Writer_Options___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, catalog, ion\\Catalog, 1, "null")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, decimalContext, ion\\Decimal\\Context, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, outputBinary, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, compactFloats, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, escapeNonAscii, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, prettyPrint, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, indentTabs, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, indentSize, IS_LONG, 0, "2")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, flushEveryValue, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxContainerDepth, IS_LONG, 0, "10")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxAnnotations, IS_LONG, 0, "10")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, tempBufferSize, IS_LONG, 0, "0x4000")
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Writer_Writer_writeNull arginfo_class_ion_Writer_writeNull

#define arginfo_class_ion_Writer_Writer_writeTypedNull arginfo_class_ion_Writer_writeTypedNull

#define arginfo_class_ion_Writer_Writer_writeBool arginfo_class_ion_Writer_writeBool

#define arginfo_class_ion_Writer_Writer_writeInt arginfo_class_ion_Writer_writeInt

#define arginfo_class_ion_Writer_Writer_writeFloat arginfo_class_ion_Writer_writeFloat

#define arginfo_class_ion_Writer_Writer_writeDecimal arginfo_class_ion_Writer_writeDecimal

#define arginfo_class_ion_Writer_Writer_writeTimestamp arginfo_class_ion_Writer_writeTimestamp

#define arginfo_class_ion_Writer_Writer_writeSymbol arginfo_class_ion_Writer_writeSymbol

#define arginfo_class_ion_Writer_Writer_writeString arginfo_class_ion_Writer_writeString

#define arginfo_class_ion_Writer_Writer_writeCLob arginfo_class_ion_Writer_writeString

#define arginfo_class_ion_Writer_Writer_writeBLob arginfo_class_ion_Writer_writeString

#define arginfo_class_ion_Writer_Writer_startLob arginfo_class_ion_Writer_writeTypedNull

#define arginfo_class_ion_Writer_Writer_appendLob arginfo_class_ion_Writer_appendLob

#define arginfo_class_ion_Writer_Writer_finishLob arginfo_class_ion_Writer_writeNull

#define arginfo_class_ion_Writer_Writer_startContainer arginfo_class_ion_Writer_writeTypedNull

#define arginfo_class_ion_Writer_Writer_finishContainer arginfo_class_ion_Writer_writeNull

#define arginfo_class_ion_Writer_Writer_writeFieldName arginfo_class_ion_Writer_writeFieldName

#define arginfo_class_ion_Writer_Writer_writeAnnotation arginfo_class_ion_Writer_writeAnnotation

#define arginfo_class_ion_Writer_Writer_getDepth arginfo_class_ion_Catalog_count

#define arginfo_class_ion_Writer_Writer_flush arginfo_class_ion_Catalog_count

#define arginfo_class_ion_Writer_Writer_finish arginfo_class_ion_Catalog_count

#define arginfo_class_ion_Writer_Buffer_getBuffer arginfo_class_ion_Symbol___toString

#define arginfo_class_ion_Writer_Buffer_resetBuffer arginfo_class_ion_Writer_writeNull

#define arginfo_class_ion_Writer_Stream_getStream arginfo_class_ion_Catalog___construct

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Writer_Buffer_Writer___construct, 0, 0, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, options, ion\\Writer\\Options, MAY_BE_ARRAY|MAY_BE_NULL, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Writer_Buffer_Writer_getBuffer arginfo_class_ion_Symbol___toString

#define arginfo_class_ion_Writer_Buffer_Writer_resetBuffer arginfo_class_ion_Writer_writeNull

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Writer_Stream_Writer___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_OBJ_TYPE_MASK(0, options, ion\\Writer\\Options, MAY_BE_ARRAY|MAY_BE_NULL, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Writer_Stream_Writer_getStream arginfo_class_ion_Catalog___construct

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Serializer_Serializer___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, multiSequence, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, callMagicSerialize, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, callCustomSerialize, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Serializer_Serializer_serialize arginfo_class_ion_Serializer_serialize

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Unserializer_Unserializer___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, multiSequence, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, callMagicUnserialize, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, callCustomUnserialize, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Unserializer_Unserializer_unserialize arginfo_class_ion_Unserializer_unserialize


static ZEND_FUNCTION(ion_serialize);
static ZEND_FUNCTION(ion_unserialize);
static ZEND_METHOD(ion_Symbol, __construct);
static ZEND_METHOD(ion_Symbol, equals);
static ZEND_METHOD(ion_Symbol, __toString);
static ZEND_METHOD(ion_Catalog, __construct);
static ZEND_METHOD(ion_Catalog, count);
static ZEND_METHOD(ion_Catalog, add);
static ZEND_METHOD(ion_Catalog, remove);
static ZEND_METHOD(ion_Catalog, find);
static ZEND_METHOD(ion_Catalog, findBest);
static ZEND_METHOD(ion_LOB, __construct);
static ZEND_METHOD(ion_Decimal, __construct);
static ZEND_METHOD(ion_Decimal, equals);
static ZEND_METHOD(ion_Decimal, isInt);
static ZEND_METHOD(ion_Decimal, __toString);
static ZEND_METHOD(ion_Decimal, toInt);
static ZEND_METHOD(ion_Timestamp, __construct);
static ZEND_METHOD(ion_Timestamp, __toString);
static ZEND_METHOD(ion_Symbol_ImportLocation, __construct);
static ZEND_METHOD(ion_Symbol_System, asTable);
static ZEND_METHOD(ion_Symbol_PHP, asTable);
static ZEND_METHOD(ion_Symbol_Table_Local, __construct);
static ZEND_METHOD(ion_Symbol_Table_Local, import);
static ZEND_METHOD(ion_Symbol_Table_Shared, __construct);
static ZEND_METHOD(ion_Decimal_Context, __construct);
static ZEND_METHOD(ion_Decimal_Context, Dec32);
static ZEND_METHOD(ion_Decimal_Context, Dec64);
static ZEND_METHOD(ion_Decimal_Context, Dec128);
static ZEND_METHOD(ion_Decimal_Context, DecMax);
static ZEND_METHOD(ion_Reader_Options, __construct);
static ZEND_METHOD(ion_Reader_Reader, hasChildren);
static ZEND_METHOD(ion_Reader_Reader, getChildren);
static ZEND_METHOD(ion_Reader_Reader, rewind);
static ZEND_METHOD(ion_Reader_Reader, next);
static ZEND_METHOD(ion_Reader_Reader, valid);
static ZEND_METHOD(ion_Reader_Reader, key);
static ZEND_METHOD(ion_Reader_Reader, current);
static ZEND_METHOD(ion_Reader_Reader, getType);
static ZEND_METHOD(ion_Reader_Reader, hasAnnotations);
static ZEND_METHOD(ion_Reader_Reader, hasAnnotation);
static ZEND_METHOD(ion_Reader_Reader, isNull);
static ZEND_METHOD(ion_Reader_Reader, isInStruct);
static ZEND_METHOD(ion_Reader_Reader, getFieldName);
static ZEND_METHOD(ion_Reader_Reader, getFieldNameSymbol);
static ZEND_METHOD(ion_Reader_Reader, getAnnotations);
static ZEND_METHOD(ion_Reader_Reader, getAnnotationSymbols);
static ZEND_METHOD(ion_Reader_Reader, countAnnotations);
static ZEND_METHOD(ion_Reader_Reader, getAnnotation);
static ZEND_METHOD(ion_Reader_Reader, getAnnotationSymbol);
static ZEND_METHOD(ion_Reader_Reader, readNull);
static ZEND_METHOD(ion_Reader_Reader, readBool);
static ZEND_METHOD(ion_Reader_Reader, readInt);
static ZEND_METHOD(ion_Reader_Reader, readFloat);
static ZEND_METHOD(ion_Reader_Reader, readDecimal);
static ZEND_METHOD(ion_Reader_Reader, readTimestamp);
static ZEND_METHOD(ion_Reader_Reader, readSymbol);
static ZEND_METHOD(ion_Reader_Reader, readString);
static ZEND_METHOD(ion_Reader_Reader, readStringPart);
static ZEND_METHOD(ion_Reader_Reader, readLob);
static ZEND_METHOD(ion_Reader_Reader, readLobPart);
static ZEND_METHOD(ion_Reader_Reader, getPosition);
static ZEND_METHOD(ion_Reader_Reader, getDepth);
static ZEND_METHOD(ion_Reader_Reader, seek);
static ZEND_METHOD(ion_Reader_Reader, getValueOffset);
static ZEND_METHOD(ion_Reader_Reader, getValueLength);
static ZEND_METHOD(ion_Reader_Buffer_Reader, __construct);
static ZEND_METHOD(ion_Reader_Buffer_Reader, getBuffer);
static ZEND_METHOD(ion_Reader_Stream_Reader, __construct);
static ZEND_METHOD(ion_Reader_Stream_Reader, getStream);
static ZEND_METHOD(ion_Reader_Stream_Reader, resetStream);
static ZEND_METHOD(ion_Reader_Stream_Reader, resetStreamWithLength);
static ZEND_METHOD(ion_Writer_Options, __construct);
static ZEND_METHOD(ion_Writer_Writer, writeNull);
static ZEND_METHOD(ion_Writer_Writer, writeTypedNull);
static ZEND_METHOD(ion_Writer_Writer, writeBool);
static ZEND_METHOD(ion_Writer_Writer, writeInt);
static ZEND_METHOD(ion_Writer_Writer, writeFloat);
static ZEND_METHOD(ion_Writer_Writer, writeDecimal);
static ZEND_METHOD(ion_Writer_Writer, writeTimestamp);
static ZEND_METHOD(ion_Writer_Writer, writeSymbol);
static ZEND_METHOD(ion_Writer_Writer, writeString);
static ZEND_METHOD(ion_Writer_Writer, writeCLob);
static ZEND_METHOD(ion_Writer_Writer, writeBLob);
static ZEND_METHOD(ion_Writer_Writer, startLob);
static ZEND_METHOD(ion_Writer_Writer, appendLob);
static ZEND_METHOD(ion_Writer_Writer, finishLob);
static ZEND_METHOD(ion_Writer_Writer, startContainer);
static ZEND_METHOD(ion_Writer_Writer, finishContainer);
static ZEND_METHOD(ion_Writer_Writer, writeFieldName);
static ZEND_METHOD(ion_Writer_Writer, writeAnnotation);
static ZEND_METHOD(ion_Writer_Writer, getDepth);
static ZEND_METHOD(ion_Writer_Writer, flush);
static ZEND_METHOD(ion_Writer_Writer, finish);
static ZEND_METHOD(ion_Writer_Buffer_Writer, __construct);
static ZEND_METHOD(ion_Writer_Buffer_Writer, getBuffer);
static ZEND_METHOD(ion_Writer_Buffer_Writer, resetBuffer);
static ZEND_METHOD(ion_Writer_Stream_Writer, __construct);
static ZEND_METHOD(ion_Writer_Stream_Writer, getStream);
static ZEND_METHOD(ion_Serializer_Serializer, __construct);
static ZEND_METHOD(ion_Serializer_Serializer, serialize);
static ZEND_METHOD(ion_Unserializer_Unserializer, __construct);
static ZEND_METHOD(ion_Unserializer_Unserializer, unserialize);


static const zend_function_entry ext_functions[] = {
	ZEND_NS_RAW_FENTRY("ion", "serialize", ZEND_FN(ion_serialize), arginfo_ion_serialize, 0)
	ZEND_NS_RAW_FENTRY("ion", "unserialize", ZEND_FN(ion_unserialize), arginfo_ion_unserialize, 0)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Serializer_methods[] = {
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Serializer, serialize, arginfo_class_ion_Serializer_serialize, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Unserializer_methods[] = {
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Unserializer, unserialize, arginfo_class_ion_Unserializer_unserialize, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Exception_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_ion_Type_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_ion_Symbol_methods[] = {
	ZEND_ME(ion_Symbol, __construct, arginfo_class_ion_Symbol___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Symbol, equals, arginfo_class_ion_Symbol_equals, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Symbol, __toString, arginfo_class_ion_Symbol___toString, ZEND_ACC_PUBLIC)
	ZEND_MALIAS(ion_Symbol, toString, __toString, arginfo_class_ion_Symbol_toString, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Catalog_methods[] = {
	ZEND_ME(ion_Catalog, __construct, arginfo_class_ion_Catalog___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Catalog, count, arginfo_class_ion_Catalog_count, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Catalog, add, arginfo_class_ion_Catalog_add, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Catalog, remove, arginfo_class_ion_Catalog_remove, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Catalog, find, arginfo_class_ion_Catalog_find, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Catalog, findBest, arginfo_class_ion_Catalog_findBest, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_LOB_methods[] = {
	ZEND_ME(ion_LOB, __construct, arginfo_class_ion_LOB___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Decimal_methods[] = {
	ZEND_ME(ion_Decimal, __construct, arginfo_class_ion_Decimal___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Decimal, equals, arginfo_class_ion_Decimal_equals, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Decimal, isInt, arginfo_class_ion_Decimal_isInt, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Decimal, __toString, arginfo_class_ion_Decimal___toString, ZEND_ACC_PUBLIC)
	ZEND_MALIAS(ion_Decimal, toString, __toString, arginfo_class_ion_Decimal_toString, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Decimal, toInt, arginfo_class_ion_Decimal_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Timestamp_methods[] = {
	ZEND_ME(ion_Timestamp, __construct, arginfo_class_ion_Timestamp___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Timestamp, __toString, arginfo_class_ion_Timestamp___toString, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Reader_methods[] = {
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, getType, arginfo_class_ion_Reader_getType, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, hasAnnotations, arginfo_class_ion_Reader_hasAnnotations, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, hasAnnotation, arginfo_class_ion_Reader_hasAnnotation, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, isNull, arginfo_class_ion_Reader_isNull, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, isInStruct, arginfo_class_ion_Reader_isInStruct, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, getFieldName, arginfo_class_ion_Reader_getFieldName, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, getFieldNameSymbol, arginfo_class_ion_Reader_getFieldNameSymbol, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, getAnnotations, arginfo_class_ion_Reader_getAnnotations, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, getAnnotationSymbols, arginfo_class_ion_Reader_getAnnotationSymbols, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, countAnnotations, arginfo_class_ion_Reader_countAnnotations, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, getAnnotation, arginfo_class_ion_Reader_getAnnotation, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, getAnnotationSymbol, arginfo_class_ion_Reader_getAnnotationSymbol, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, readNull, arginfo_class_ion_Reader_readNull, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, readBool, arginfo_class_ion_Reader_readBool, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, readInt, arginfo_class_ion_Reader_readInt, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, readFloat, arginfo_class_ion_Reader_readFloat, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, readDecimal, arginfo_class_ion_Reader_readDecimal, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, readTimestamp, arginfo_class_ion_Reader_readTimestamp, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, readSymbol, arginfo_class_ion_Reader_readSymbol, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, readString, arginfo_class_ion_Reader_readString, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, readStringPart, arginfo_class_ion_Reader_readStringPart, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, readLob, arginfo_class_ion_Reader_readLob, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, readLobPart, arginfo_class_ion_Reader_readLobPart, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, getPosition, arginfo_class_ion_Reader_getPosition, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, getDepth, arginfo_class_ion_Reader_getDepth, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, seek, arginfo_class_ion_Reader_seek, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, getValueOffset, arginfo_class_ion_Reader_getValueOffset, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader, getValueLength, arginfo_class_ion_Reader_getValueLength, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Writer_methods[] = {
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer, writeNull, arginfo_class_ion_Writer_writeNull, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer, writeTypedNull, arginfo_class_ion_Writer_writeTypedNull, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer, writeBool, arginfo_class_ion_Writer_writeBool, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer, writeInt, arginfo_class_ion_Writer_writeInt, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer, writeFloat, arginfo_class_ion_Writer_writeFloat, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer, writeDecimal, arginfo_class_ion_Writer_writeDecimal, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer, writeTimestamp, arginfo_class_ion_Writer_writeTimestamp, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer, writeSymbol, arginfo_class_ion_Writer_writeSymbol, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer, writeString, arginfo_class_ion_Writer_writeString, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer, writeCLob, arginfo_class_ion_Writer_writeCLob, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer, writeBLob, arginfo_class_ion_Writer_writeBLob, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer, startLob, arginfo_class_ion_Writer_startLob, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer, appendLob, arginfo_class_ion_Writer_appendLob, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer, finishLob, arginfo_class_ion_Writer_finishLob, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer, startContainer, arginfo_class_ion_Writer_startContainer, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer, finishContainer, arginfo_class_ion_Writer_finishContainer, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer, writeFieldName, arginfo_class_ion_Writer_writeFieldName, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer, writeAnnotation, arginfo_class_ion_Writer_writeAnnotation, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer, getDepth, arginfo_class_ion_Writer_getDepth, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer, flush, arginfo_class_ion_Writer_flush, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer, finish, arginfo_class_ion_Writer_finish, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Symbol_ImportLocation_methods[] = {
	ZEND_ME(ion_Symbol_ImportLocation, __construct, arginfo_class_ion_Symbol_ImportLocation___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Symbol_Enum_methods[] = {
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Symbol_Enum, toSymbol, arginfo_class_ion_Symbol_Enum_toSymbol, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Symbol_Enum, toSID, arginfo_class_ion_Symbol_Enum_toSID, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Symbol_Enum, toString, arginfo_class_ion_Symbol_Enum_toString, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Symbol_Table_methods[] = {
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Symbol_Table, getMaxId, arginfo_class_ion_Symbol_Table_getMaxId, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Symbol_Table, add, arginfo_class_ion_Symbol_Table_add, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Symbol_Table, find, arginfo_class_ion_Symbol_Table_find, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Symbol_Table, findLocal, arginfo_class_ion_Symbol_Table_findLocal, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Symbol_System_methods[] = {
	ZEND_MALIAS(ion_Symbol_Enum, toSymbol, toSymbol, arginfo_class_ion_Symbol_System_toSymbol, ZEND_ACC_PUBLIC)
	ZEND_MALIAS(ion_Symbol_Enum, toSID, toSID, arginfo_class_ion_Symbol_System_toSID, ZEND_ACC_PUBLIC)
	ZEND_MALIAS(ion_Symbol_Enum, toString, toString, arginfo_class_ion_Symbol_System_toString, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Symbol_System, asTable, arginfo_class_ion_Symbol_System_asTable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Symbol_PHP_methods[] = {
	ZEND_MALIAS(ion_Symbol_Enum, toSymbol, toSymbol, arginfo_class_ion_Symbol_PHP_toSymbol, ZEND_ACC_PUBLIC)
	ZEND_MALIAS(ion_Symbol_Enum, toSID, toSID, arginfo_class_ion_Symbol_PHP_toSID, ZEND_ACC_PUBLIC)
	ZEND_MALIAS(ion_Symbol_Enum, toString, toString, arginfo_class_ion_Symbol_PHP_toString, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Symbol_PHP, asTable, arginfo_class_ion_Symbol_PHP_asTable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Symbol_Table_Local_methods[] = {
	ZEND_ME(ion_Symbol_Table_Local, __construct, arginfo_class_ion_Symbol_Table_Local___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Symbol_Table_Local, import, arginfo_class_ion_Symbol_Table_Local_import, ZEND_ACC_PUBLIC)
	ZEND_MALIAS(ion_Symbol_Table, getMaxId, getMaxId, arginfo_class_ion_Symbol_Table_Local_getMaxId, ZEND_ACC_PUBLIC)
	ZEND_MALIAS(ion_Symbol_Table, add, add, arginfo_class_ion_Symbol_Table_Local_add, ZEND_ACC_PUBLIC)
	ZEND_MALIAS(ion_Symbol_Table, find, find, arginfo_class_ion_Symbol_Table_Local_find, ZEND_ACC_PUBLIC)
	ZEND_MALIAS(ion_Symbol_Table, findLocal, findLocal, arginfo_class_ion_Symbol_Table_Local_findLocal, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Symbol_Table_Shared_methods[] = {
	ZEND_ME(ion_Symbol_Table_Shared, __construct, arginfo_class_ion_Symbol_Table_Shared___construct, ZEND_ACC_PUBLIC)
	ZEND_MALIAS(ion_Symbol_Table, getMaxId, getMaxId, arginfo_class_ion_Symbol_Table_Shared_getMaxId, ZEND_ACC_PUBLIC)
	ZEND_MALIAS(ion_Symbol_Table, add, add, arginfo_class_ion_Symbol_Table_Shared_add, ZEND_ACC_PUBLIC)
	ZEND_MALIAS(ion_Symbol_Table, find, find, arginfo_class_ion_Symbol_Table_Shared_find, ZEND_ACC_PUBLIC)
	ZEND_MALIAS(ion_Symbol_Table, findLocal, findLocal, arginfo_class_ion_Symbol_Table_Shared_findLocal, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Decimal_Context_methods[] = {
	ZEND_ME(ion_Decimal_Context, __construct, arginfo_class_ion_Decimal_Context___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Decimal_Context, Dec32, arginfo_class_ion_Decimal_Context_Dec32, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(ion_Decimal_Context, Dec64, arginfo_class_ion_Decimal_Context_Dec64, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(ion_Decimal_Context, Dec128, arginfo_class_ion_Decimal_Context_Dec128, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(ion_Decimal_Context, DecMax, arginfo_class_ion_Decimal_Context_DecMax, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Decimal_Context_Rounding_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_ion_Timestamp_Precision_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_ion_Timestamp_Format_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_ion_Reader_Options_methods[] = {
	ZEND_ME(ion_Reader_Options, __construct, arginfo_class_ion_Reader_Options___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Reader_Reader_methods[] = {
	ZEND_ME(ion_Reader_Reader, hasChildren, arginfo_class_ion_Reader_Reader_hasChildren, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, getChildren, arginfo_class_ion_Reader_Reader_getChildren, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, rewind, arginfo_class_ion_Reader_Reader_rewind, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, next, arginfo_class_ion_Reader_Reader_next, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, valid, arginfo_class_ion_Reader_Reader_valid, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, key, arginfo_class_ion_Reader_Reader_key, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, current, arginfo_class_ion_Reader_Reader_current, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, getType, arginfo_class_ion_Reader_Reader_getType, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, hasAnnotations, arginfo_class_ion_Reader_Reader_hasAnnotations, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, hasAnnotation, arginfo_class_ion_Reader_Reader_hasAnnotation, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, isNull, arginfo_class_ion_Reader_Reader_isNull, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, isInStruct, arginfo_class_ion_Reader_Reader_isInStruct, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, getFieldName, arginfo_class_ion_Reader_Reader_getFieldName, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, getFieldNameSymbol, arginfo_class_ion_Reader_Reader_getFieldNameSymbol, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, getAnnotations, arginfo_class_ion_Reader_Reader_getAnnotations, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, getAnnotationSymbols, arginfo_class_ion_Reader_Reader_getAnnotationSymbols, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, countAnnotations, arginfo_class_ion_Reader_Reader_countAnnotations, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, getAnnotation, arginfo_class_ion_Reader_Reader_getAnnotation, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, getAnnotationSymbol, arginfo_class_ion_Reader_Reader_getAnnotationSymbol, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, readNull, arginfo_class_ion_Reader_Reader_readNull, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, readBool, arginfo_class_ion_Reader_Reader_readBool, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, readInt, arginfo_class_ion_Reader_Reader_readInt, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, readFloat, arginfo_class_ion_Reader_Reader_readFloat, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, readDecimal, arginfo_class_ion_Reader_Reader_readDecimal, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, readTimestamp, arginfo_class_ion_Reader_Reader_readTimestamp, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, readSymbol, arginfo_class_ion_Reader_Reader_readSymbol, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, readString, arginfo_class_ion_Reader_Reader_readString, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, readStringPart, arginfo_class_ion_Reader_Reader_readStringPart, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, readLob, arginfo_class_ion_Reader_Reader_readLob, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, readLobPart, arginfo_class_ion_Reader_Reader_readLobPart, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, getPosition, arginfo_class_ion_Reader_Reader_getPosition, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, getDepth, arginfo_class_ion_Reader_Reader_getDepth, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, seek, arginfo_class_ion_Reader_Reader_seek, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, getValueOffset, arginfo_class_ion_Reader_Reader_getValueOffset, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Reader, getValueLength, arginfo_class_ion_Reader_Reader_getValueLength, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Reader_Buffer_methods[] = {
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader_Buffer, getBuffer, arginfo_class_ion_Reader_Buffer_getBuffer, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Reader_Stream_methods[] = {
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader_Stream, getStream, arginfo_class_ion_Reader_Stream_getStream, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader_Stream, resetStream, arginfo_class_ion_Reader_Stream_resetStream, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader_Stream, resetStreamWithLength, arginfo_class_ion_Reader_Stream_resetStreamWithLength, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Reader_Buffer_Reader_methods[] = {
	ZEND_ME(ion_Reader_Buffer_Reader, __construct, arginfo_class_ion_Reader_Buffer_Reader___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Buffer_Reader, getBuffer, arginfo_class_ion_Reader_Buffer_Reader_getBuffer, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Reader_Stream_Reader_methods[] = {
	ZEND_ME(ion_Reader_Stream_Reader, __construct, arginfo_class_ion_Reader_Stream_Reader___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Stream_Reader, getStream, arginfo_class_ion_Reader_Stream_Reader_getStream, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Stream_Reader, resetStream, arginfo_class_ion_Reader_Stream_Reader_resetStream, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Stream_Reader, resetStreamWithLength, arginfo_class_ion_Reader_Stream_Reader_resetStreamWithLength, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Writer_Options_methods[] = {
	ZEND_ME(ion_Writer_Options, __construct, arginfo_class_ion_Writer_Options___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Writer_Writer_methods[] = {
	ZEND_ME(ion_Writer_Writer, writeNull, arginfo_class_ion_Writer_Writer_writeNull, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Writer, writeTypedNull, arginfo_class_ion_Writer_Writer_writeTypedNull, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Writer, writeBool, arginfo_class_ion_Writer_Writer_writeBool, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Writer, writeInt, arginfo_class_ion_Writer_Writer_writeInt, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Writer, writeFloat, arginfo_class_ion_Writer_Writer_writeFloat, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Writer, writeDecimal, arginfo_class_ion_Writer_Writer_writeDecimal, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Writer, writeTimestamp, arginfo_class_ion_Writer_Writer_writeTimestamp, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Writer, writeSymbol, arginfo_class_ion_Writer_Writer_writeSymbol, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Writer, writeString, arginfo_class_ion_Writer_Writer_writeString, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Writer, writeCLob, arginfo_class_ion_Writer_Writer_writeCLob, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Writer, writeBLob, arginfo_class_ion_Writer_Writer_writeBLob, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Writer, startLob, arginfo_class_ion_Writer_Writer_startLob, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Writer, appendLob, arginfo_class_ion_Writer_Writer_appendLob, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Writer, finishLob, arginfo_class_ion_Writer_Writer_finishLob, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Writer, startContainer, arginfo_class_ion_Writer_Writer_startContainer, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Writer, finishContainer, arginfo_class_ion_Writer_Writer_finishContainer, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Writer, writeFieldName, arginfo_class_ion_Writer_Writer_writeFieldName, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Writer, writeAnnotation, arginfo_class_ion_Writer_Writer_writeAnnotation, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Writer, getDepth, arginfo_class_ion_Writer_Writer_getDepth, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Writer, flush, arginfo_class_ion_Writer_Writer_flush, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Writer, finish, arginfo_class_ion_Writer_Writer_finish, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Writer_Buffer_methods[] = {
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer_Buffer, getBuffer, arginfo_class_ion_Writer_Buffer_getBuffer, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer_Buffer, resetBuffer, arginfo_class_ion_Writer_Buffer_resetBuffer, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Writer_Stream_methods[] = {
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer_Stream, getStream, arginfo_class_ion_Writer_Stream_getStream, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Writer_Buffer_Writer_methods[] = {
	ZEND_ME(ion_Writer_Buffer_Writer, __construct, arginfo_class_ion_Writer_Buffer_Writer___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Buffer_Writer, getBuffer, arginfo_class_ion_Writer_Buffer_Writer_getBuffer, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Buffer_Writer, resetBuffer, arginfo_class_ion_Writer_Buffer_Writer_resetBuffer, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Writer_Stream_Writer_methods[] = {
	ZEND_ME(ion_Writer_Stream_Writer, __construct, arginfo_class_ion_Writer_Stream_Writer___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Stream_Writer, getStream, arginfo_class_ion_Writer_Stream_Writer_getStream, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Serializer_Serializer_methods[] = {
	ZEND_ME(ion_Serializer_Serializer, __construct, arginfo_class_ion_Serializer_Serializer___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Serializer_Serializer, serialize, arginfo_class_ion_Serializer_Serializer_serialize, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Unserializer_Unserializer_methods[] = {
	ZEND_ME(ion_Unserializer_Unserializer, __construct, arginfo_class_ion_Unserializer_Unserializer___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Unserializer_Unserializer, unserialize, arginfo_class_ion_Unserializer_Unserializer_unserialize, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_ion_Serializer(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion", "Serializer", class_ion_Serializer_methods);
	class_entry = zend_register_internal_interface(&ce);

	return class_entry;
}

static zend_class_entry *register_class_ion_Unserializer(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion", "Unserializer", class_ion_Unserializer_methods);
	class_entry = zend_register_internal_interface(&ce);

	return class_entry;
}

static zend_class_entry *register_class_ion_Exception(zend_class_entry *class_entry_Exception)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion", "Exception", class_ion_Exception_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Exception);

	return class_entry;
}

static zend_class_entry *register_class_ion_Type(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("ion\\Type", IS_LONG, class_ion_Type_methods);

	zval enum_case_Null_value;
	ZVAL_LONG(&enum_case_Null_value, 0);
	zend_enum_add_case_cstr(class_entry, "Null", &enum_case_Null_value);

	zval enum_case_Bool_value;
	ZVAL_LONG(&enum_case_Bool_value, 256);
	zend_enum_add_case_cstr(class_entry, "Bool", &enum_case_Bool_value);

	zval enum_case_Int_value;
	ZVAL_LONG(&enum_case_Int_value, 512);
	zend_enum_add_case_cstr(class_entry, "Int", &enum_case_Int_value);

	zval enum_case_Float_value;
	ZVAL_LONG(&enum_case_Float_value, 1024);
	zend_enum_add_case_cstr(class_entry, "Float", &enum_case_Float_value);

	zval enum_case_Decimal_value;
	ZVAL_LONG(&enum_case_Decimal_value, 1280);
	zend_enum_add_case_cstr(class_entry, "Decimal", &enum_case_Decimal_value);

	zval enum_case_Timestamp_value;
	ZVAL_LONG(&enum_case_Timestamp_value, 1536);
	zend_enum_add_case_cstr(class_entry, "Timestamp", &enum_case_Timestamp_value);

	zval enum_case_Symbol_value;
	ZVAL_LONG(&enum_case_Symbol_value, 1792);
	zend_enum_add_case_cstr(class_entry, "Symbol", &enum_case_Symbol_value);

	zval enum_case_String_value;
	ZVAL_LONG(&enum_case_String_value, 2048);
	zend_enum_add_case_cstr(class_entry, "String", &enum_case_String_value);

	zval enum_case_CLob_value;
	ZVAL_LONG(&enum_case_CLob_value, 2304);
	zend_enum_add_case_cstr(class_entry, "CLob", &enum_case_CLob_value);

	zval enum_case_BLob_value;
	ZVAL_LONG(&enum_case_BLob_value, 2560);
	zend_enum_add_case_cstr(class_entry, "BLob", &enum_case_BLob_value);

	zval enum_case_List_value;
	ZVAL_LONG(&enum_case_List_value, 2816);
	zend_enum_add_case_cstr(class_entry, "List", &enum_case_List_value);

	zval enum_case_SExp_value;
	ZVAL_LONG(&enum_case_SExp_value, 3072);
	zend_enum_add_case_cstr(class_entry, "SExp", &enum_case_SExp_value);

	zval enum_case_Struct_value;
	ZVAL_LONG(&enum_case_Struct_value, 3328);
	zend_enum_add_case_cstr(class_entry, "Struct", &enum_case_Struct_value);

	zval enum_case_Datagram_value;
	ZVAL_LONG(&enum_case_Datagram_value, 3840);
	zend_enum_add_case_cstr(class_entry, "Datagram", &enum_case_Datagram_value);

	zval enum_case_EOF_value;
	ZVAL_LONG(&enum_case_EOF_value, -256);
	zend_enum_add_case_cstr(class_entry, "EOF", &enum_case_EOF_value);

	zval enum_case_NONE_value;
	ZVAL_LONG(&enum_case_NONE_value, -512);
	zend_enum_add_case_cstr(class_entry, "NONE", &enum_case_NONE_value);

	return class_entry;
}

static zend_class_entry *register_class_ion_Symbol(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion", "Symbol", class_ion_Symbol_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_string *property_value_name = zend_string_init("value", sizeof("value") - 1, 1);
	zend_declare_typed_property(class_entry, property_value_name, &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_value_name);

	zval property_sid_default_value;
	ZVAL_UNDEF(&property_sid_default_value);
	zend_string *property_sid_name = zend_string_init("sid", sizeof("sid") - 1, 1);
	zend_declare_typed_property(class_entry, property_sid_name, &property_sid_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_sid_name);

	zend_string *property_importLocation_class_ion_Symbol_ImportLocation = zend_string_init("ion\\Symbol\\ImportLocation", sizeof("ion\\Symbol\\ImportLocation")-1, 1);
	zval property_importLocation_default_value;
	ZVAL_UNDEF(&property_importLocation_default_value);
	zend_string *property_importLocation_name = zend_string_init("importLocation", sizeof("importLocation") - 1, 1);
	zend_declare_typed_property(class_entry, property_importLocation_name, &property_importLocation_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_importLocation_class_ion_Symbol_ImportLocation, 0, MAY_BE_NULL));
	zend_string_release(property_importLocation_name);

	return class_entry;
}

static zend_class_entry *register_class_ion_Catalog(zend_class_entry *class_entry_Countable)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion", "Catalog", class_ion_Catalog_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	zend_class_implements(class_entry, 1, class_entry_Countable);

	zval property_symbolTables_default_value;
	ZVAL_EMPTY_ARRAY(&property_symbolTables_default_value);
	zend_string *property_symbolTables_name = zend_string_init("symbolTables", sizeof("symbolTables") - 1, 1);
	zend_declare_typed_property(class_entry, property_symbolTables_name, &property_symbolTables_default_value, ZEND_ACC_PRIVATE, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_symbolTables_name);

	return class_entry;
}

static zend_class_entry *register_class_ion_LOB(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion", "LOB", class_ion_LOB_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_string *property_value_name = zend_string_init("value", sizeof("value") - 1, 1);
	zend_declare_typed_property(class_entry, property_value_name, &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_value_name);

	zend_string *property_type_class_ion_Type = zend_string_init("ion\\Type", sizeof("ion\\Type")-1, 1);
	zval property_type_default_value;
	ZVAL_UNDEF(&property_type_default_value);
	zend_string *property_type_name = zend_string_init("type", sizeof("type") - 1, 1);
	zend_declare_typed_property(class_entry, property_type_name, &property_type_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_type_class_ion_Type, 0, 0));
	zend_string_release(property_type_name);

	return class_entry;
}

static zend_class_entry *register_class_ion_Decimal(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion", "Decimal", class_ion_Decimal_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval property_number_default_value;
	ZVAL_UNDEF(&property_number_default_value);
	zend_string *property_number_name = zend_string_init("number", sizeof("number") - 1, 1);
	zend_declare_typed_property(class_entry, property_number_name, &property_number_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_LONG));
	zend_string_release(property_number_name);

	zend_string *property_context_class_ion_Decimal_Context = zend_string_init("ion\\Decimal\\Context", sizeof("ion\\Decimal\\Context")-1, 1);
	zval property_context_default_value;
	ZVAL_UNDEF(&property_context_default_value);
	zend_string *property_context_name = zend_string_init("context", sizeof("context") - 1, 1);
	zend_declare_typed_property(class_entry, property_context_name, &property_context_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_context_class_ion_Decimal_Context, 0, MAY_BE_NULL));
	zend_string_release(property_context_name);

	return class_entry;
}

static zend_class_entry *register_class_ion_Timestamp(zend_class_entry *class_entry_DateTime)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion", "Timestamp", class_ion_Timestamp_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_DateTime);

	zval property_precision_default_value;
	ZVAL_UNDEF(&property_precision_default_value);
	zend_string *property_precision_name = zend_string_init("precision", sizeof("precision") - 1, 1);
	zend_declare_typed_property(class_entry, property_precision_name, &property_precision_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_precision_name);

	zval property_format_default_value;
	ZVAL_UNDEF(&property_format_default_value);
	zend_string *property_format_name = zend_string_init("format", sizeof("format") - 1, 1);
	zend_declare_typed_property(class_entry, property_format_name, &property_format_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_format_name);

	return class_entry;
}

static zend_class_entry *register_class_ion_Reader(zend_class_entry *class_entry_RecursiveIterator)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion", "Reader", class_ion_Reader_methods);
	class_entry = zend_register_internal_interface(&ce);
	zend_class_implements(class_entry, 1, class_entry_RecursiveIterator);

	return class_entry;
}

static zend_class_entry *register_class_ion_Writer(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion", "Writer", class_ion_Writer_methods);
	class_entry = zend_register_internal_interface(&ce);

	return class_entry;
}

static zend_class_entry *register_class_ion_Symbol_ImportLocation(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Symbol", "ImportLocation", class_ion_Symbol_ImportLocation_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval property_name_default_value;
	ZVAL_UNDEF(&property_name_default_value);
	zend_string *property_name_name = zend_string_init("name", sizeof("name") - 1, 1);
	zend_declare_typed_property(class_entry, property_name_name, &property_name_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_name_name);

	zval property_location_default_value;
	ZVAL_UNDEF(&property_location_default_value);
	zend_string *property_location_name = zend_string_init("location", sizeof("location") - 1, 1);
	zend_declare_typed_property(class_entry, property_location_name, &property_location_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_location_name);

	return class_entry;
}

static zend_class_entry *register_class_ion_Symbol_Enum(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Symbol", "Enum", class_ion_Symbol_Enum_methods);
	class_entry = zend_register_internal_interface(&ce);

	return class_entry;
}

static zend_class_entry *register_class_ion_Symbol_Table(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Symbol", "Table", class_ion_Symbol_Table_methods);
	class_entry = zend_register_internal_interface(&ce);

	return class_entry;
}

static zend_class_entry *register_class_ion_Symbol_System(zend_class_entry *class_entry_ion_Symbol_Enum)
{
	zend_class_entry *class_entry = zend_register_internal_enum("ion\\Symbol\\System", IS_STRING, class_ion_Symbol_System_methods);
	zend_class_implements(class_entry, 1, class_entry_ion_Symbol_Enum);

	zval enum_case_Ion_value;
	zend_string *enum_case_Ion_value_str = zend_string_init("$ion", sizeof("$ion") - 1, 1);
	ZVAL_STR(&enum_case_Ion_value, enum_case_Ion_value_str);
	zend_enum_add_case_cstr(class_entry, "Ion", &enum_case_Ion_value);

	zval enum_case_Ivm_1_0_value;
	zend_string *enum_case_Ivm_1_0_value_str = zend_string_init("$ion_1_0", sizeof("$ion_1_0") - 1, 1);
	ZVAL_STR(&enum_case_Ivm_1_0_value, enum_case_Ivm_1_0_value_str);
	zend_enum_add_case_cstr(class_entry, "Ivm_1_0", &enum_case_Ivm_1_0_value);

	zval enum_case_IonSymbolTable_value;
	zend_string *enum_case_IonSymbolTable_value_str = zend_string_init("$ion_symbol_table", sizeof("$ion_symbol_table") - 1, 1);
	ZVAL_STR(&enum_case_IonSymbolTable_value, enum_case_IonSymbolTable_value_str);
	zend_enum_add_case_cstr(class_entry, "IonSymbolTable", &enum_case_IonSymbolTable_value);

	zval enum_case_Name_value;
	zend_string *enum_case_Name_value_str = zend_string_init("name", sizeof("name") - 1, 1);
	ZVAL_STR(&enum_case_Name_value, enum_case_Name_value_str);
	zend_enum_add_case_cstr(class_entry, "Name", &enum_case_Name_value);

	zval enum_case_Version_value;
	zend_string *enum_case_Version_value_str = zend_string_init("version", sizeof("version") - 1, 1);
	ZVAL_STR(&enum_case_Version_value, enum_case_Version_value_str);
	zend_enum_add_case_cstr(class_entry, "Version", &enum_case_Version_value);

	zval enum_case_Imports_value;
	zend_string *enum_case_Imports_value_str = zend_string_init("imports", sizeof("imports") - 1, 1);
	ZVAL_STR(&enum_case_Imports_value, enum_case_Imports_value_str);
	zend_enum_add_case_cstr(class_entry, "Imports", &enum_case_Imports_value);

	zval enum_case_Symbols_value;
	zend_string *enum_case_Symbols_value_str = zend_string_init("symbols", sizeof("symbols") - 1, 1);
	ZVAL_STR(&enum_case_Symbols_value, enum_case_Symbols_value_str);
	zend_enum_add_case_cstr(class_entry, "Symbols", &enum_case_Symbols_value);

	zval enum_case_MaxId_value;
	zend_string *enum_case_MaxId_value_str = zend_string_init("max_id", sizeof("max_id") - 1, 1);
	ZVAL_STR(&enum_case_MaxId_value, enum_case_MaxId_value_str);
	zend_enum_add_case_cstr(class_entry, "MaxId", &enum_case_MaxId_value);

	zval enum_case_SharedSymbolTable_value;
	zend_string *enum_case_SharedSymbolTable_value_str = zend_string_init("$ion_shared_symbol_table", sizeof("$ion_shared_symbol_table") - 1, 1);
	ZVAL_STR(&enum_case_SharedSymbolTable_value, enum_case_SharedSymbolTable_value_str);
	zend_enum_add_case_cstr(class_entry, "SharedSymbolTable", &enum_case_SharedSymbolTable_value);

	return class_entry;
}

static zend_class_entry *register_class_ion_Symbol_PHP(zend_class_entry *class_entry_ion_Symbol_Enum)
{
	zend_class_entry *class_entry = zend_register_internal_enum("ion\\Symbol\\PHP", IS_STRING, class_ion_Symbol_PHP_methods);
	zend_class_implements(class_entry, 1, class_entry_ion_Symbol_Enum);

	zval enum_case_PHP_value;
	zend_string *enum_case_PHP_value_str = zend_string_init("PHP", sizeof("PHP") - 1, 1);
	ZVAL_STR(&enum_case_PHP_value, enum_case_PHP_value_str);
	zend_enum_add_case_cstr(class_entry, "PHP", &enum_case_PHP_value);

	zval enum_case_Reference_value;
	zend_string *enum_case_Reference_value_str = zend_string_init("R", sizeof("R") - 1, 1);
	ZVAL_STR(&enum_case_Reference_value, enum_case_Reference_value_str);
	zend_enum_add_case_cstr(class_entry, "Reference", &enum_case_Reference_value);

	zval enum_case_Backref_value;
	zend_string *enum_case_Backref_value_str = zend_string_init("r", sizeof("r") - 1, 1);
	ZVAL_STR(&enum_case_Backref_value, enum_case_Backref_value_str);
	zend_enum_add_case_cstr(class_entry, "Backref", &enum_case_Backref_value);

	zval enum_case_Property_value;
	zend_string *enum_case_Property_value_str = zend_string_init("p", sizeof("p") - 1, 1);
	ZVAL_STR(&enum_case_Property_value, enum_case_Property_value_str);
	zend_enum_add_case_cstr(class_entry, "Property", &enum_case_Property_value);

	zval enum_case_Object_value;
	zend_string *enum_case_Object_value_str = zend_string_init("o", sizeof("o") - 1, 1);
	ZVAL_STR(&enum_case_Object_value, enum_case_Object_value_str);
	zend_enum_add_case_cstr(class_entry, "Object", &enum_case_Object_value);

	zval enum_case_ClassObject_value;
	zend_string *enum_case_ClassObject_value_str = zend_string_init("c", sizeof("c") - 1, 1);
	ZVAL_STR(&enum_case_ClassObject_value, enum_case_ClassObject_value_str);
	zend_enum_add_case_cstr(class_entry, "ClassObject", &enum_case_ClassObject_value);

	zval enum_case_MagicObject_value;
	zend_string *enum_case_MagicObject_value_str = zend_string_init("O", sizeof("O") - 1, 1);
	ZVAL_STR(&enum_case_MagicObject_value, enum_case_MagicObject_value_str);
	zend_enum_add_case_cstr(class_entry, "MagicObject", &enum_case_MagicObject_value);

	zval enum_case_CustomObject_value;
	zend_string *enum_case_CustomObject_value_str = zend_string_init("C", sizeof("C") - 1, 1);
	ZVAL_STR(&enum_case_CustomObject_value, enum_case_CustomObject_value_str);
	zend_enum_add_case_cstr(class_entry, "CustomObject", &enum_case_CustomObject_value);

	zval enum_case_Enum_value;
	zend_string *enum_case_Enum_value_str = zend_string_init("E", sizeof("E") - 1, 1);
	ZVAL_STR(&enum_case_Enum_value, enum_case_Enum_value_str);
	zend_enum_add_case_cstr(class_entry, "Enum", &enum_case_Enum_value);

	zval enum_case_Serializable_value;
	zend_string *enum_case_Serializable_value_str = zend_string_init("S", sizeof("S") - 1, 1);
	ZVAL_STR(&enum_case_Serializable_value, enum_case_Serializable_value_str);
	zend_enum_add_case_cstr(class_entry, "Serializable", &enum_case_Serializable_value);

	return class_entry;
}

static zend_class_entry *register_class_ion_Symbol_Table_Local(zend_class_entry *class_entry_ion_Symbol_Table)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Symbol\\Table", "Local", class_ion_Symbol_Table_Local_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	zend_class_implements(class_entry, 1, class_entry_ion_Symbol_Table);

	zval property_imports_default_value;
	ZVAL_EMPTY_ARRAY(&property_imports_default_value);
	zend_string *property_imports_name = zend_string_init("imports", sizeof("imports") - 1, 1);
	zend_declare_typed_property(class_entry, property_imports_name, &property_imports_default_value, ZEND_ACC_PRIVATE, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_imports_name);

	zval property_symbols_default_value;
	ZVAL_EMPTY_ARRAY(&property_symbols_default_value);
	zend_string *property_symbols_name = zend_string_init("symbols", sizeof("symbols") - 1, 1);
	zend_declare_typed_property(class_entry, property_symbols_name, &property_symbols_default_value, ZEND_ACC_PRIVATE, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_symbols_name);

	return class_entry;
}

static zend_class_entry *register_class_ion_Symbol_Table_Shared(zend_class_entry *class_entry_ion_Symbol_Table)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Symbol\\Table", "Shared", class_ion_Symbol_Table_Shared_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	zend_class_implements(class_entry, 1, class_entry_ion_Symbol_Table);

	zval property_name_default_value;
	ZVAL_UNDEF(&property_name_default_value);
	zend_string *property_name_name = zend_string_init("name", sizeof("name") - 1, 1);
	zend_declare_typed_property(class_entry, property_name_name, &property_name_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_name_name);

	zval property_version_default_value;
	ZVAL_UNDEF(&property_version_default_value);
	zend_string *property_version_name = zend_string_init("version", sizeof("version") - 1, 1);
	zend_declare_typed_property(class_entry, property_version_name, &property_version_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_version_name);

	zval property_symbols_default_value;
	ZVAL_EMPTY_ARRAY(&property_symbols_default_value);
	zend_string *property_symbols_name = zend_string_init("symbols", sizeof("symbols") - 1, 1);
	zend_declare_typed_property(class_entry, property_symbols_name, &property_symbols_default_value, ZEND_ACC_PRIVATE, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_symbols_name);

	return class_entry;
}

static zend_class_entry *register_class_ion_Decimal_Context(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Decimal", "Context", class_ion_Decimal_Context_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval property_digits_default_value;
	ZVAL_UNDEF(&property_digits_default_value);
	zend_string *property_digits_name = zend_string_init("digits", sizeof("digits") - 1, 1);
	zend_declare_typed_property(class_entry, property_digits_name, &property_digits_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_digits_name);

	zval property_eMax_default_value;
	ZVAL_UNDEF(&property_eMax_default_value);
	zend_string *property_eMax_name = zend_string_init("eMax", sizeof("eMax") - 1, 1);
	zend_declare_typed_property(class_entry, property_eMax_name, &property_eMax_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_eMax_name);

	zval property_eMin_default_value;
	ZVAL_UNDEF(&property_eMin_default_value);
	zend_string *property_eMin_name = zend_string_init("eMin", sizeof("eMin") - 1, 1);
	zend_declare_typed_property(class_entry, property_eMin_name, &property_eMin_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_eMin_name);

	zend_string *property_round_class_ion_Decimal_Context_Rounding = zend_string_init("ion\\Decimal\\Context\\Rounding", sizeof("ion\\Decimal\\Context\\Rounding")-1, 1);
	zval property_round_default_value;
	ZVAL_UNDEF(&property_round_default_value);
	zend_string *property_round_name = zend_string_init("round", sizeof("round") - 1, 1);
	zend_declare_typed_property(class_entry, property_round_name, &property_round_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_round_class_ion_Decimal_Context_Rounding, 0, MAY_BE_LONG));
	zend_string_release(property_round_name);

	zval property_clamp_default_value;
	ZVAL_UNDEF(&property_clamp_default_value);
	zend_string *property_clamp_name = zend_string_init("clamp", sizeof("clamp") - 1, 1);
	zend_declare_typed_property(class_entry, property_clamp_name, &property_clamp_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_clamp_name);

	return class_entry;
}

static zend_class_entry *register_class_ion_Decimal_Context_Rounding(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("ion\\Decimal\\Context\\Rounding", IS_LONG, class_ion_Decimal_Context_Rounding_methods);

	zval enum_case_Ceiling_value;
	ZVAL_LONG(&enum_case_Ceiling_value, 0);
	zend_enum_add_case_cstr(class_entry, "Ceiling", &enum_case_Ceiling_value);

	zval enum_case_Up_value;
	ZVAL_LONG(&enum_case_Up_value, 1);
	zend_enum_add_case_cstr(class_entry, "Up", &enum_case_Up_value);

	zval enum_case_HalfUp_value;
	ZVAL_LONG(&enum_case_HalfUp_value, 2);
	zend_enum_add_case_cstr(class_entry, "HalfUp", &enum_case_HalfUp_value);

	zval enum_case_HalfEven_value;
	ZVAL_LONG(&enum_case_HalfEven_value, 3);
	zend_enum_add_case_cstr(class_entry, "HalfEven", &enum_case_HalfEven_value);

	zval enum_case_HalfDown_value;
	ZVAL_LONG(&enum_case_HalfDown_value, 4);
	zend_enum_add_case_cstr(class_entry, "HalfDown", &enum_case_HalfDown_value);

	zval enum_case_Down_value;
	ZVAL_LONG(&enum_case_Down_value, 5);
	zend_enum_add_case_cstr(class_entry, "Down", &enum_case_Down_value);

	zval enum_case_Floor_value;
	ZVAL_LONG(&enum_case_Floor_value, 6);
	zend_enum_add_case_cstr(class_entry, "Floor", &enum_case_Floor_value);

	zval enum_case_Down05Up_value;
	ZVAL_LONG(&enum_case_Down05Up_value, 7);
	zend_enum_add_case_cstr(class_entry, "Down05Up", &enum_case_Down05Up_value);

	return class_entry;
}

static zend_class_entry *register_class_ion_Timestamp_Precision(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("ion\\Timestamp\\Precision", IS_LONG, class_ion_Timestamp_Precision_methods);

	zval enum_case_Year_value;
	ZVAL_LONG(&enum_case_Year_value, 1);
	zend_enum_add_case_cstr(class_entry, "Year", &enum_case_Year_value);

	zval enum_case_Month_value;
	ZVAL_LONG(&enum_case_Month_value, 3);
	zend_enum_add_case_cstr(class_entry, "Month", &enum_case_Month_value);

	zval enum_case_Day_value;
	ZVAL_LONG(&enum_case_Day_value, 7);
	zend_enum_add_case_cstr(class_entry, "Day", &enum_case_Day_value);

	zval enum_case_Min_value;
	ZVAL_LONG(&enum_case_Min_value, 23);
	zend_enum_add_case_cstr(class_entry, "Min", &enum_case_Min_value);

	zval enum_case_Sec_value;
	ZVAL_LONG(&enum_case_Sec_value, 55);
	zend_enum_add_case_cstr(class_entry, "Sec", &enum_case_Sec_value);

	zval enum_case_Frac_value;
	ZVAL_LONG(&enum_case_Frac_value, 119);
	zend_enum_add_case_cstr(class_entry, "Frac", &enum_case_Frac_value);

	zval enum_case_MinTZ_value;
	ZVAL_LONG(&enum_case_MinTZ_value, 151);
	zend_enum_add_case_cstr(class_entry, "MinTZ", &enum_case_MinTZ_value);

	zval enum_case_SecTZ_value;
	ZVAL_LONG(&enum_case_SecTZ_value, 183);
	zend_enum_add_case_cstr(class_entry, "SecTZ", &enum_case_SecTZ_value);

	zval enum_case_FracTZ_value;
	ZVAL_LONG(&enum_case_FracTZ_value, 247);
	zend_enum_add_case_cstr(class_entry, "FracTZ", &enum_case_FracTZ_value);

	return class_entry;
}

static zend_class_entry *register_class_ion_Timestamp_Format(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("ion\\Timestamp\\Format", IS_STRING, class_ion_Timestamp_Format_methods);

	zval enum_case_Year_value;
	zend_string *enum_case_Year_value_str = zend_string_init("Y\\T", sizeof("Y\\T") - 1, 1);
	ZVAL_STR(&enum_case_Year_value, enum_case_Year_value_str);
	zend_enum_add_case_cstr(class_entry, "Year", &enum_case_Year_value);

	zval enum_case_Month_value;
	zend_string *enum_case_Month_value_str = zend_string_init("Y-m\\T", sizeof("Y-m\\T") - 1, 1);
	ZVAL_STR(&enum_case_Month_value, enum_case_Month_value_str);
	zend_enum_add_case_cstr(class_entry, "Month", &enum_case_Month_value);

	zval enum_case_Day_value;
	zend_string *enum_case_Day_value_str = zend_string_init("Y-m-d\\T", sizeof("Y-m-d\\T") - 1, 1);
	ZVAL_STR(&enum_case_Day_value, enum_case_Day_value_str);
	zend_enum_add_case_cstr(class_entry, "Day", &enum_case_Day_value);

	zval enum_case_Min_value;
	zend_string *enum_case_Min_value_str = zend_string_init("Y-m-d\\TH:i", sizeof("Y-m-d\\TH:i") - 1, 1);
	ZVAL_STR(&enum_case_Min_value, enum_case_Min_value_str);
	zend_enum_add_case_cstr(class_entry, "Min", &enum_case_Min_value);

	zval enum_case_Sec_value;
	zend_string *enum_case_Sec_value_str = zend_string_init("Y-m-d\\TH:i:s", sizeof("Y-m-d\\TH:i:s") - 1, 1);
	ZVAL_STR(&enum_case_Sec_value, enum_case_Sec_value_str);
	zend_enum_add_case_cstr(class_entry, "Sec", &enum_case_Sec_value);

	zval enum_case_Frac_value;
	zend_string *enum_case_Frac_value_str = zend_string_init("Y-m-d\\TH:i:s.v", sizeof("Y-m-d\\TH:i:s.v") - 1, 1);
	ZVAL_STR(&enum_case_Frac_value, enum_case_Frac_value_str);
	zend_enum_add_case_cstr(class_entry, "Frac", &enum_case_Frac_value);

	zval enum_case_MinTZ_value;
	zend_string *enum_case_MinTZ_value_str = zend_string_init("Y-m-d\\TH:iP", sizeof("Y-m-d\\TH:iP") - 1, 1);
	ZVAL_STR(&enum_case_MinTZ_value, enum_case_MinTZ_value_str);
	zend_enum_add_case_cstr(class_entry, "MinTZ", &enum_case_MinTZ_value);

	zval enum_case_SecTZ_value;
	zend_string *enum_case_SecTZ_value_str = zend_string_init("Y-m-d\\TH:i:sP", sizeof("Y-m-d\\TH:i:sP") - 1, 1);
	ZVAL_STR(&enum_case_SecTZ_value, enum_case_SecTZ_value_str);
	zend_enum_add_case_cstr(class_entry, "SecTZ", &enum_case_SecTZ_value);

	zval enum_case_FracTZ_value;
	zend_string *enum_case_FracTZ_value_str = zend_string_init("Y-m-d\\TH:i:s.vP", sizeof("Y-m-d\\TH:i:s.vP") - 1, 1);
	ZVAL_STR(&enum_case_FracTZ_value, enum_case_FracTZ_value_str);
	zend_enum_add_case_cstr(class_entry, "FracTZ", &enum_case_FracTZ_value);

	return class_entry;
}

static zend_class_entry *register_class_ion_Reader_Options(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Reader", "Options", class_ion_Reader_Options_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zend_string *property_catalog_class_ion_Catalog = zend_string_init("ion\\Catalog", sizeof("ion\\Catalog")-1, 1);
	zval property_catalog_default_value;
	ZVAL_UNDEF(&property_catalog_default_value);
	zend_string *property_catalog_name = zend_string_init("catalog", sizeof("catalog") - 1, 1);
	zend_declare_typed_property(class_entry, property_catalog_name, &property_catalog_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_catalog_class_ion_Catalog, 0, MAY_BE_NULL));
	zend_string_release(property_catalog_name);

	zend_string *property_decimalContext_class_ion_Decimal_Context = zend_string_init("ion\\Decimal\\Context", sizeof("ion\\Decimal\\Context")-1, 1);
	zval property_decimalContext_default_value;
	ZVAL_UNDEF(&property_decimalContext_default_value);
	zend_string *property_decimalContext_name = zend_string_init("decimalContext", sizeof("decimalContext") - 1, 1);
	zend_declare_typed_property(class_entry, property_decimalContext_name, &property_decimalContext_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_decimalContext_class_ion_Decimal_Context, 0, MAY_BE_NULL));
	zend_string_release(property_decimalContext_name);

	zend_string *property_onContextChange_class_Closure = zend_string_init("Closure", sizeof("Closure")-1, 1);
	zval property_onContextChange_default_value;
	ZVAL_UNDEF(&property_onContextChange_default_value);
	zend_string *property_onContextChange_name = zend_string_init("onContextChange", sizeof("onContextChange") - 1, 1);
	zend_declare_typed_property(class_entry, property_onContextChange_name, &property_onContextChange_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_onContextChange_class_Closure, 0, MAY_BE_NULL));
	zend_string_release(property_onContextChange_name);

	zval property_returnSystemValues_default_value;
	ZVAL_UNDEF(&property_returnSystemValues_default_value);
	zend_string *property_returnSystemValues_name = zend_string_init("returnSystemValues", sizeof("returnSystemValues") - 1, 1);
	zend_declare_typed_property(class_entry, property_returnSystemValues_name, &property_returnSystemValues_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_returnSystemValues_name);

	zval property_maxContainerDepth_default_value;
	ZVAL_UNDEF(&property_maxContainerDepth_default_value);
	zend_string *property_maxContainerDepth_name = zend_string_init("maxContainerDepth", sizeof("maxContainerDepth") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxContainerDepth_name, &property_maxContainerDepth_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxContainerDepth_name);

	zval property_maxAnnotations_default_value;
	ZVAL_UNDEF(&property_maxAnnotations_default_value);
	zend_string *property_maxAnnotations_name = zend_string_init("maxAnnotations", sizeof("maxAnnotations") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxAnnotations_name, &property_maxAnnotations_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxAnnotations_name);

	zval property_annotationBufferSize_default_value;
	ZVAL_UNDEF(&property_annotationBufferSize_default_value);
	zend_string *property_annotationBufferSize_name = zend_string_init("annotationBufferSize", sizeof("annotationBufferSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_annotationBufferSize_name, &property_annotationBufferSize_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_annotationBufferSize_name);

	zval property_tempBufferSize_default_value;
	ZVAL_UNDEF(&property_tempBufferSize_default_value);
	zend_string *property_tempBufferSize_name = zend_string_init("tempBufferSize", sizeof("tempBufferSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_tempBufferSize_name, &property_tempBufferSize_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_tempBufferSize_name);

	zval property_skipCharacterValidation_default_value;
	ZVAL_UNDEF(&property_skipCharacterValidation_default_value);
	zend_string *property_skipCharacterValidation_name = zend_string_init("skipCharacterValidation", sizeof("skipCharacterValidation") - 1, 1);
	zend_declare_typed_property(class_entry, property_skipCharacterValidation_name, &property_skipCharacterValidation_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_skipCharacterValidation_name);

	return class_entry;
}

static zend_class_entry *register_class_ion_Reader_Reader(zend_class_entry *class_entry_ion_Reader)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Reader", "Reader", class_ion_Reader_Reader_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_ABSTRACT;
	zend_class_implements(class_entry, 1, class_entry_ion_Reader);

	zend_string *property_options_class_ion_Reader_Options = zend_string_init("ion\\Reader\\Options", sizeof("ion\\Reader\\Options")-1, 1);
	zval property_options_default_value;
	ZVAL_UNDEF(&property_options_default_value);
	zend_string *property_options_name = zend_string_init("options", sizeof("options") - 1, 1);
	zend_declare_typed_property(class_entry, property_options_name, &property_options_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_options_class_ion_Reader_Options, 0, MAY_BE_NULL));
	zend_string_release(property_options_name);

	return class_entry;
}

static zend_class_entry *register_class_ion_Reader_Buffer(zend_class_entry *class_entry_ion_Reader)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Reader", "Buffer", class_ion_Reader_Buffer_methods);
	class_entry = zend_register_internal_interface(&ce);
	zend_class_implements(class_entry, 1, class_entry_ion_Reader);

	return class_entry;
}

static zend_class_entry *register_class_ion_Reader_Stream(zend_class_entry *class_entry_ion_Reader)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Reader", "Stream", class_ion_Reader_Stream_methods);
	class_entry = zend_register_internal_interface(&ce);
	zend_class_implements(class_entry, 1, class_entry_ion_Reader);

	return class_entry;
}

static zend_class_entry *register_class_ion_Reader_Buffer_Reader(zend_class_entry *class_entry_ion_Reader_Reader, zend_class_entry *class_entry_ion_Reader_Buffer)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Reader\\Buffer", "Reader", class_ion_Reader_Buffer_Reader_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_ion_Reader_Reader);
	zend_class_implements(class_entry, 1, class_entry_ion_Reader_Buffer);

	return class_entry;
}

static zend_class_entry *register_class_ion_Reader_Stream_Reader(zend_class_entry *class_entry_ion_Reader_Reader, zend_class_entry *class_entry_ion_Reader_Stream)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Reader\\Stream", "Reader", class_ion_Reader_Stream_Reader_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_ion_Reader_Reader);
	zend_class_implements(class_entry, 1, class_entry_ion_Reader_Stream);

	return class_entry;
}

static zend_class_entry *register_class_ion_Writer_Options(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Writer", "Options", class_ion_Writer_Options_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zend_string *property_catalog_class_ion_Catalog = zend_string_init("ion\\Catalog", sizeof("ion\\Catalog")-1, 1);
	zval property_catalog_default_value;
	ZVAL_UNDEF(&property_catalog_default_value);
	zend_string *property_catalog_name = zend_string_init("catalog", sizeof("catalog") - 1, 1);
	zend_declare_typed_property(class_entry, property_catalog_name, &property_catalog_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_catalog_class_ion_Catalog, 0, MAY_BE_NULL));
	zend_string_release(property_catalog_name);

	zend_string *property_decimalContext_class_ion_Decimal_Context = zend_string_init("ion\\Decimal\\Context", sizeof("ion\\Decimal\\Context")-1, 1);
	zval property_decimalContext_default_value;
	ZVAL_UNDEF(&property_decimalContext_default_value);
	zend_string *property_decimalContext_name = zend_string_init("decimalContext", sizeof("decimalContext") - 1, 1);
	zend_declare_typed_property(class_entry, property_decimalContext_name, &property_decimalContext_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_decimalContext_class_ion_Decimal_Context, 0, MAY_BE_NULL));
	zend_string_release(property_decimalContext_name);

	zval property_outputBinary_default_value;
	ZVAL_UNDEF(&property_outputBinary_default_value);
	zend_string *property_outputBinary_name = zend_string_init("outputBinary", sizeof("outputBinary") - 1, 1);
	zend_declare_typed_property(class_entry, property_outputBinary_name, &property_outputBinary_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_outputBinary_name);

	zval property_compactFloats_default_value;
	ZVAL_UNDEF(&property_compactFloats_default_value);
	zend_string *property_compactFloats_name = zend_string_init("compactFloats", sizeof("compactFloats") - 1, 1);
	zend_declare_typed_property(class_entry, property_compactFloats_name, &property_compactFloats_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_compactFloats_name);

	zval property_escapeNonAscii_default_value;
	ZVAL_UNDEF(&property_escapeNonAscii_default_value);
	zend_string *property_escapeNonAscii_name = zend_string_init("escapeNonAscii", sizeof("escapeNonAscii") - 1, 1);
	zend_declare_typed_property(class_entry, property_escapeNonAscii_name, &property_escapeNonAscii_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_escapeNonAscii_name);

	zval property_prettyPrint_default_value;
	ZVAL_UNDEF(&property_prettyPrint_default_value);
	zend_string *property_prettyPrint_name = zend_string_init("prettyPrint", sizeof("prettyPrint") - 1, 1);
	zend_declare_typed_property(class_entry, property_prettyPrint_name, &property_prettyPrint_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_prettyPrint_name);

	zval property_indentTabs_default_value;
	ZVAL_UNDEF(&property_indentTabs_default_value);
	zend_string *property_indentTabs_name = zend_string_init("indentTabs", sizeof("indentTabs") - 1, 1);
	zend_declare_typed_property(class_entry, property_indentTabs_name, &property_indentTabs_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_indentTabs_name);

	zval property_indentSize_default_value;
	ZVAL_UNDEF(&property_indentSize_default_value);
	zend_string *property_indentSize_name = zend_string_init("indentSize", sizeof("indentSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_indentSize_name, &property_indentSize_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_indentSize_name);

	zval property_flushEveryValue_default_value;
	ZVAL_UNDEF(&property_flushEveryValue_default_value);
	zend_string *property_flushEveryValue_name = zend_string_init("flushEveryValue", sizeof("flushEveryValue") - 1, 1);
	zend_declare_typed_property(class_entry, property_flushEveryValue_name, &property_flushEveryValue_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_flushEveryValue_name);

	zval property_maxContainerDepth_default_value;
	ZVAL_UNDEF(&property_maxContainerDepth_default_value);
	zend_string *property_maxContainerDepth_name = zend_string_init("maxContainerDepth", sizeof("maxContainerDepth") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxContainerDepth_name, &property_maxContainerDepth_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxContainerDepth_name);

	zval property_maxAnnotations_default_value;
	ZVAL_UNDEF(&property_maxAnnotations_default_value);
	zend_string *property_maxAnnotations_name = zend_string_init("maxAnnotations", sizeof("maxAnnotations") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxAnnotations_name, &property_maxAnnotations_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxAnnotations_name);

	zval property_tempBufferSize_default_value;
	ZVAL_UNDEF(&property_tempBufferSize_default_value);
	zend_string *property_tempBufferSize_name = zend_string_init("tempBufferSize", sizeof("tempBufferSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_tempBufferSize_name, &property_tempBufferSize_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_tempBufferSize_name);

	return class_entry;
}

static zend_class_entry *register_class_ion_Writer_Writer(zend_class_entry *class_entry_ion_Writer)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Writer", "Writer", class_ion_Writer_Writer_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_ABSTRACT;
	zend_class_implements(class_entry, 1, class_entry_ion_Writer);

	return class_entry;
}

static zend_class_entry *register_class_ion_Writer_Buffer(zend_class_entry *class_entry_ion_Writer)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Writer", "Buffer", class_ion_Writer_Buffer_methods);
	class_entry = zend_register_internal_interface(&ce);
	zend_class_implements(class_entry, 1, class_entry_ion_Writer);

	return class_entry;
}

static zend_class_entry *register_class_ion_Writer_Stream(zend_class_entry *class_entry_ion_Writer)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Writer", "Stream", class_ion_Writer_Stream_methods);
	class_entry = zend_register_internal_interface(&ce);
	zend_class_implements(class_entry, 1, class_entry_ion_Writer);

	return class_entry;
}

static zend_class_entry *register_class_ion_Writer_Buffer_Writer(zend_class_entry *class_entry_ion_Writer_Writer, zend_class_entry *class_entry_ion_Writer_Buffer)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Writer\\Buffer", "Writer", class_ion_Writer_Buffer_Writer_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_ion_Writer_Writer);
	zend_class_implements(class_entry, 1, class_entry_ion_Writer_Buffer);

	return class_entry;
}

static zend_class_entry *register_class_ion_Writer_Stream_Writer(zend_class_entry *class_entry_ion_Writer_Writer, zend_class_entry *class_entry_ion_Writer_Stream)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Writer\\Stream", "Writer", class_ion_Writer_Stream_Writer_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_ion_Writer_Writer);
	zend_class_implements(class_entry, 1, class_entry_ion_Writer_Stream);

	return class_entry;
}

static zend_class_entry *register_class_ion_Serializer_Serializer(zend_class_entry *class_entry_ion_Serializer)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Serializer", "Serializer", class_ion_Serializer_Serializer_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	zend_class_implements(class_entry, 1, class_entry_ion_Serializer);

	zval property_multiSequence_default_value;
	ZVAL_UNDEF(&property_multiSequence_default_value);
	zend_string *property_multiSequence_name = zend_string_init("multiSequence", sizeof("multiSequence") - 1, 1);
	zend_declare_typed_property(class_entry, property_multiSequence_name, &property_multiSequence_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_multiSequence_name);

	zval property_callMagicSerialize_default_value;
	ZVAL_UNDEF(&property_callMagicSerialize_default_value);
	zend_string *property_callMagicSerialize_name = zend_string_init("callMagicSerialize", sizeof("callMagicSerialize") - 1, 1);
	zend_declare_typed_property(class_entry, property_callMagicSerialize_name, &property_callMagicSerialize_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_callMagicSerialize_name);

	zval property_callCustomSerialize_default_value;
	ZVAL_UNDEF(&property_callCustomSerialize_default_value);
	zend_string *property_callCustomSerialize_name = zend_string_init("callCustomSerialize", sizeof("callCustomSerialize") - 1, 1);
	zend_declare_typed_property(class_entry, property_callCustomSerialize_name, &property_callCustomSerialize_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_callCustomSerialize_name);

	return class_entry;
}

static zend_class_entry *register_class_ion_Unserializer_Unserializer(zend_class_entry *class_entry_ion_Unserializer)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Unserializer", "Unserializer", class_ion_Unserializer_Unserializer_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	zend_class_implements(class_entry, 1, class_entry_ion_Unserializer);

	zval property_multiSequence_default_value;
	ZVAL_UNDEF(&property_multiSequence_default_value);
	zend_string *property_multiSequence_name = zend_string_init("multiSequence", sizeof("multiSequence") - 1, 1);
	zend_declare_typed_property(class_entry, property_multiSequence_name, &property_multiSequence_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_multiSequence_name);

	zval property_callMagicUnserialize_default_value;
	ZVAL_UNDEF(&property_callMagicUnserialize_default_value);
	zend_string *property_callMagicUnserialize_name = zend_string_init("callMagicUnserialize", sizeof("callMagicUnserialize") - 1, 1);
	zend_declare_typed_property(class_entry, property_callMagicUnserialize_name, &property_callMagicUnserialize_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_callMagicUnserialize_name);

	zval property_callCustomUnserialize_default_value;
	ZVAL_UNDEF(&property_callCustomUnserialize_default_value);
	zend_string *property_callCustomUnserialize_name = zend_string_init("callCustomUnserialize", sizeof("callCustomUnserialize") - 1, 1);
	zend_declare_typed_property(class_entry, property_callCustomUnserialize_name, &property_callCustomUnserialize_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_callCustomUnserialize_name);

	return class_entry;
}
