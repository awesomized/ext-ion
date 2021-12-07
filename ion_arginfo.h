/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 20996b59177d52516ad45582152909be017ba39d */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ion_serialize, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_MIXED, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, options, ion\\Writer\\Options, 0, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ion_unserialize, 0, 1, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, serialized, IS_MIXED, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, options, ion\\Reader\\Options, 0, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Symbol_ImportLocation___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Symbol___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, sid, IS_LONG, 0, "-1")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, importLocation, ion\\Symbol\\ImportLocation, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Symbol_equals, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, symbol, ion\\Symbol, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Decimal_Context___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bits, IS_LONG, 0, "128")
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

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Decimal___toString, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Decimal_toString arginfo_class_ion_Decimal___toString

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Decimal_toInt, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Timestamp___construct, 0, 0, 1)
	ZEND_ARG_OBJ_TYPE_MASK(0, precision, ion\\Timestamp\\Precision, MAY_BE_LONG, NULL)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, format, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, datetime, IS_STRING, 1, "null")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, timezone, DateTimeZone, 1, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Timestamp___toString arginfo_class_ion_Decimal___toString

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_ion_Reader_getType, 0, 0, ion\\Type, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Reader_hasAnnotations arginfo_class_ion_Decimal_isInt

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Reader_hasAnnotation, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, annotation, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Reader_isNull arginfo_class_ion_Decimal_isInt

#define arginfo_class_ion_Reader_isInStruct arginfo_class_ion_Decimal_isInt

#define arginfo_class_ion_Reader_getFieldName arginfo_class_ion_Decimal___toString

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_ion_Reader_getFieldNameSymbol, 0, 0, ion\\Symbol, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Reader_getAnnotations, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Reader_getAnnotationSymbols arginfo_class_ion_Reader_getAnnotations

#define arginfo_class_ion_Reader_countAnnotations arginfo_class_ion_Decimal_toInt

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

#define arginfo_class_ion_Reader_readString arginfo_class_ion_Decimal___toString

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Reader_readStringPart, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(1, string)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 0, "0x1000")
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Reader_readLob arginfo_class_ion_Decimal___toString

#define arginfo_class_ion_Reader_readLobPart arginfo_class_ion_Reader_readStringPart

#define arginfo_class_ion_Reader_getPosition arginfo_class_ion_Decimal_toInt

#define arginfo_class_ion_Reader_getDepth arginfo_class_ion_Decimal_toInt

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Reader_seek, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 0, "-1")
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Reader_getValueOffset arginfo_class_ion_Decimal_toInt

#define arginfo_class_ion_Reader_getValueLength arginfo_class_ion_Decimal_toInt

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Reader_Options___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, catalog, ion\\Catalog, 1, "null")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, decimalContext, ion\\Decimal\\Context, 1, "null")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, onContextChange, Closure, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, returnSystemValues, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, newLine, IS_LONG, 0, "0xa")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxContainerDepth, IS_LONG, 0, "10")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxAnnotations, IS_LONG, 0, "10")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxAnnotationBuffered, IS_LONG, 0, "512")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, symbolThreshold, IS_LONG, 0, "4096")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, userValueThreshold, IS_LONG, 0, "4096")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, chunkThreshold, IS_LONG, 0, "4096")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, allocationPageSize, IS_LONG, 0, "4096")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, skipCharacterValidation, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Reader_Reader_hasChildren arginfo_class_ion_Decimal_isInt

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_ion_Reader_Reader_getChildren, 0, 0, ion\\Reader, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Reader_Reader_rewind, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Reader_Reader_next arginfo_class_ion_Reader_Reader_rewind

#define arginfo_class_ion_Reader_Reader_valid arginfo_class_ion_Decimal_isInt

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Reader_Reader_key, 0, 0, IS_MIXED, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Reader_Reader_current arginfo_class_ion_Reader_Reader_key

#define arginfo_class_ion_Reader_Reader_getType arginfo_class_ion_Reader_getType

#define arginfo_class_ion_Reader_Reader_hasAnnotations arginfo_class_ion_Decimal_isInt

#define arginfo_class_ion_Reader_Reader_hasAnnotation arginfo_class_ion_Reader_hasAnnotation

#define arginfo_class_ion_Reader_Reader_isNull arginfo_class_ion_Decimal_isInt

#define arginfo_class_ion_Reader_Reader_isInStruct arginfo_class_ion_Decimal_isInt

#define arginfo_class_ion_Reader_Reader_getFieldName arginfo_class_ion_Decimal___toString

#define arginfo_class_ion_Reader_Reader_getFieldNameSymbol arginfo_class_ion_Reader_getFieldNameSymbol

#define arginfo_class_ion_Reader_Reader_getAnnotations arginfo_class_ion_Reader_getAnnotations

#define arginfo_class_ion_Reader_Reader_getAnnotationSymbols arginfo_class_ion_Reader_getAnnotations

#define arginfo_class_ion_Reader_Reader_countAnnotations arginfo_class_ion_Decimal_toInt

#define arginfo_class_ion_Reader_Reader_getAnnotation arginfo_class_ion_Reader_getAnnotation

#define arginfo_class_ion_Reader_Reader_getAnnotationSymbol arginfo_class_ion_Reader_getAnnotationSymbol

#define arginfo_class_ion_Reader_Reader_readNull arginfo_class_ion_Reader_getType

#define arginfo_class_ion_Reader_Reader_readBool arginfo_class_ion_Decimal_isInt

#define arginfo_class_ion_Reader_Reader_readInt arginfo_class_ion_Reader_readInt

#define arginfo_class_ion_Reader_Reader_readFloat arginfo_class_ion_Reader_readFloat

#define arginfo_class_ion_Reader_Reader_readDecimal arginfo_class_ion_Reader_readDecimal

#define arginfo_class_ion_Reader_Reader_readTimestamp arginfo_class_ion_Reader_readTimestamp

#define arginfo_class_ion_Reader_Reader_readSymbol arginfo_class_ion_Reader_getFieldNameSymbol

#define arginfo_class_ion_Reader_Reader_readString arginfo_class_ion_Decimal___toString

#define arginfo_class_ion_Reader_Reader_readStringPart arginfo_class_ion_Reader_readStringPart

#define arginfo_class_ion_Reader_Reader_readLob arginfo_class_ion_Decimal___toString

#define arginfo_class_ion_Reader_Reader_readLobPart arginfo_class_ion_Reader_readStringPart

#define arginfo_class_ion_Reader_Reader_getPosition arginfo_class_ion_Decimal_toInt

#define arginfo_class_ion_Reader_Reader_getDepth arginfo_class_ion_Decimal_toInt

#define arginfo_class_ion_Reader_Reader_seek arginfo_class_ion_Reader_seek

#define arginfo_class_ion_Reader_Reader_getValueOffset arginfo_class_ion_Decimal_toInt

#define arginfo_class_ion_Reader_Reader_getValueLength arginfo_class_ion_Decimal_toInt

#define arginfo_class_ion_Reader_Buffer_getBuffer arginfo_class_ion_Decimal___toString

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Reader_Buffer_Reader___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, options, ion\\Reader\\Options, 1, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Reader_Buffer_Reader_getBuffer arginfo_class_ion_Decimal___toString

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Reader_Stream_getStream, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Reader_Stream_resetStream, 0, 1, IS_VOID, 0)
	ZEND_ARG_INFO(0, stream)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Reader_Stream_resetStreamWithLength, 0, 2, IS_VOID, 0)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 0, "-1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Reader_Stream_Reader___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, options, ion\\Reader\\Options, 1, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Reader_Stream_Reader_getStream arginfo_class_ion_Reader_Stream_getStream

#define arginfo_class_ion_Reader_Stream_Reader_resetStream arginfo_class_ion_Reader_Stream_resetStream

#define arginfo_class_ion_Reader_Stream_Reader_resetStreamWithLength arginfo_class_ion_Reader_Stream_resetStreamWithLength

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Writer_Options___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, catalog, ion\\Catalog, 1, "null")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, decimalContext, ion\\Decimal\\Context, 1, "null")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, encodingSymbolTable, ion\\Collection, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, outputBinary, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, compactFloats, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, escapeNonAscii, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, prettyPrint, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, indentTabs, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, indentSize, IS_LONG, 0, "2")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, smallContainersInline, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, suppressSystemValues, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, flushEveryValue, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxContainerDepth, IS_LONG, 0, "10")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxAnnotations, IS_LONG, 0, "10")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, tempBufferSize, IS_LONG, 0, "0x400")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, allocationPageSize, IS_LONG, 0, "0x1000")
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Writer_writeNull arginfo_class_ion_Reader_Reader_rewind

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

#define arginfo_class_ion_Writer_finishLob arginfo_class_ion_Reader_Reader_rewind

#define arginfo_class_ion_Writer_startContainer arginfo_class_ion_Writer_writeTypedNull

#define arginfo_class_ion_Writer_finishContainer arginfo_class_ion_Reader_Reader_rewind

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Writer_writeFieldName, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Writer_writeAnnotation, 0, 0, IS_VOID, 0)
	ZEND_ARG_VARIADIC_OBJ_TYPE_MASK(0, annotation, ion\\Symbol, MAY_BE_STRING, NULL)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Writer_getDepth arginfo_class_ion_Decimal_toInt

#define arginfo_class_ion_Writer_flush arginfo_class_ion_Decimal_toInt

#define arginfo_class_ion_Writer_finish arginfo_class_ion_Decimal_toInt

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_Writer_writeOne, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, reader, ion\\Reader, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Writer_writeAll arginfo_class_ion_Writer_writeOne

#define arginfo_class_ion_Writer_Writer_writeNull arginfo_class_ion_Reader_Reader_rewind

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

#define arginfo_class_ion_Writer_Writer_finishLob arginfo_class_ion_Reader_Reader_rewind

#define arginfo_class_ion_Writer_Writer_startContainer arginfo_class_ion_Writer_writeTypedNull

#define arginfo_class_ion_Writer_Writer_finishContainer arginfo_class_ion_Reader_Reader_rewind

#define arginfo_class_ion_Writer_Writer_writeFieldName arginfo_class_ion_Writer_writeFieldName

#define arginfo_class_ion_Writer_Writer_writeAnnotation arginfo_class_ion_Writer_writeAnnotation

#define arginfo_class_ion_Writer_Writer_getDepth arginfo_class_ion_Decimal_toInt

#define arginfo_class_ion_Writer_Writer_flush arginfo_class_ion_Decimal_toInt

#define arginfo_class_ion_Writer_Writer_finish arginfo_class_ion_Decimal_toInt

#define arginfo_class_ion_Writer_Writer_writeOne arginfo_class_ion_Writer_writeOne

#define arginfo_class_ion_Writer_Writer_writeAll arginfo_class_ion_Writer_writeOne

#define arginfo_class_ion_Writer_Buffer_getBuffer arginfo_class_ion_Decimal___toString

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Writer_Buffer_Writer___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(1, buffer, IS_STRING, 1)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, options, ion\\Writer\\Options, 1, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Writer_Buffer_Writer_getBuffer arginfo_class_ion_Decimal___toString

#define arginfo_class_ion_Writer_Stream_getStream arginfo_class_ion_Reader_Stream_getStream

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_Writer_Stream_Writer___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, options, ion\\Writer\\Options, 1, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_ion_Writer_Stream_Writer_getStream arginfo_class_ion_Reader_Stream_getStream

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_PHP_Serializer___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, writer, ion\\Writer, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, callMagicSerialize, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, callCustomSerialize, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ion_PHP_Serializer___invoke, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_MIXED, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ion_PHP_Serializer_serialize arginfo_class_ion_PHP_Serializer___invoke

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ion_PHP_Unserializer___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, reader, ion\\Reader, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, callMagicUnserialize, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, callCustomUnserialize, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_ion_PHP_Unserializer___invoke arginfo_class_ion_Reader_Reader_key

#define arginfo_class_ion_PHP_Unserializer_unserialize arginfo_class_ion_Reader_Reader_key


ZEND_FUNCTION(ion_serialize);
ZEND_FUNCTION(ion_unserialize);
ZEND_METHOD(ion_Symbol_ImportLocation, __construct);
ZEND_METHOD(ion_Symbol, __construct);
ZEND_METHOD(ion_Symbol, equals);
ZEND_METHOD(ion_Decimal_Context, __construct);
ZEND_METHOD(ion_Decimal, __construct);
ZEND_METHOD(ion_Decimal, equals);
ZEND_METHOD(ion_Decimal, isInt);
ZEND_METHOD(ion_Decimal, __toString);
ZEND_METHOD(ion_Decimal, toInt);
ZEND_METHOD(ion_Timestamp, __construct);
ZEND_METHOD(ion_Timestamp, __toString);
ZEND_METHOD(ion_Reader_Options, __construct);
ZEND_METHOD(ion_Reader_Reader, hasChildren);
ZEND_METHOD(ion_Reader_Reader, getChildren);
ZEND_METHOD(ion_Reader_Reader, rewind);
ZEND_METHOD(ion_Reader_Reader, next);
ZEND_METHOD(ion_Reader_Reader, valid);
ZEND_METHOD(ion_Reader_Reader, key);
ZEND_METHOD(ion_Reader_Reader, current);
ZEND_METHOD(ion_Reader_Reader, getType);
ZEND_METHOD(ion_Reader_Reader, hasAnnotations);
ZEND_METHOD(ion_Reader_Reader, hasAnnotation);
ZEND_METHOD(ion_Reader_Reader, isNull);
ZEND_METHOD(ion_Reader_Reader, isInStruct);
ZEND_METHOD(ion_Reader_Reader, getFieldName);
ZEND_METHOD(ion_Reader_Reader, getFieldNameSymbol);
ZEND_METHOD(ion_Reader_Reader, getAnnotations);
ZEND_METHOD(ion_Reader_Reader, getAnnotationSymbols);
ZEND_METHOD(ion_Reader_Reader, countAnnotations);
ZEND_METHOD(ion_Reader_Reader, getAnnotation);
ZEND_METHOD(ion_Reader_Reader, getAnnotationSymbol);
ZEND_METHOD(ion_Reader_Reader, readNull);
ZEND_METHOD(ion_Reader_Reader, readBool);
ZEND_METHOD(ion_Reader_Reader, readInt);
ZEND_METHOD(ion_Reader_Reader, readFloat);
ZEND_METHOD(ion_Reader_Reader, readDecimal);
ZEND_METHOD(ion_Reader_Reader, readTimestamp);
ZEND_METHOD(ion_Reader_Reader, readSymbol);
ZEND_METHOD(ion_Reader_Reader, readString);
ZEND_METHOD(ion_Reader_Reader, readStringPart);
ZEND_METHOD(ion_Reader_Reader, readLob);
ZEND_METHOD(ion_Reader_Reader, readLobPart);
ZEND_METHOD(ion_Reader_Reader, getPosition);
ZEND_METHOD(ion_Reader_Reader, getDepth);
ZEND_METHOD(ion_Reader_Reader, seek);
ZEND_METHOD(ion_Reader_Reader, getValueOffset);
ZEND_METHOD(ion_Reader_Reader, getValueLength);
ZEND_METHOD(ion_Reader_Buffer_Reader, __construct);
ZEND_METHOD(ion_Reader_Buffer_Reader, getBuffer);
ZEND_METHOD(ion_Reader_Stream_Reader, __construct);
ZEND_METHOD(ion_Reader_Stream_Reader, getStream);
ZEND_METHOD(ion_Reader_Stream_Reader, resetStream);
ZEND_METHOD(ion_Reader_Stream_Reader, resetStreamWithLength);
ZEND_METHOD(ion_Writer_Options, __construct);
ZEND_METHOD(ion_Writer_Writer, writeNull);
ZEND_METHOD(ion_Writer_Writer, writeTypedNull);
ZEND_METHOD(ion_Writer_Writer, writeBool);
ZEND_METHOD(ion_Writer_Writer, writeInt);
ZEND_METHOD(ion_Writer_Writer, writeFloat);
ZEND_METHOD(ion_Writer_Writer, writeDecimal);
ZEND_METHOD(ion_Writer_Writer, writeTimestamp);
ZEND_METHOD(ion_Writer_Writer, writeSymbol);
ZEND_METHOD(ion_Writer_Writer, writeString);
ZEND_METHOD(ion_Writer_Writer, writeCLob);
ZEND_METHOD(ion_Writer_Writer, writeBLob);
ZEND_METHOD(ion_Writer_Writer, startLob);
ZEND_METHOD(ion_Writer_Writer, appendLob);
ZEND_METHOD(ion_Writer_Writer, finishLob);
ZEND_METHOD(ion_Writer_Writer, startContainer);
ZEND_METHOD(ion_Writer_Writer, finishContainer);
ZEND_METHOD(ion_Writer_Writer, writeFieldName);
ZEND_METHOD(ion_Writer_Writer, writeAnnotation);
ZEND_METHOD(ion_Writer_Writer, getDepth);
ZEND_METHOD(ion_Writer_Writer, flush);
ZEND_METHOD(ion_Writer_Writer, finish);
ZEND_METHOD(ion_Writer_Writer, writeOne);
ZEND_METHOD(ion_Writer_Writer, writeAll);
ZEND_METHOD(ion_Writer_Buffer_Writer, __construct);
ZEND_METHOD(ion_Writer_Buffer_Writer, getBuffer);
ZEND_METHOD(ion_Writer_Stream_Writer, __construct);
ZEND_METHOD(ion_Writer_Stream_Writer, getStream);
ZEND_METHOD(ion_PHP_Serializer, __construct);
ZEND_METHOD(ion_PHP_Serializer, __invoke);
ZEND_METHOD(ion_PHP_Serializer, serialize);
ZEND_METHOD(ion_PHP_Unserializer, __construct);
ZEND_METHOD(ion_PHP_Unserializer, __invoke);
ZEND_METHOD(ion_PHP_Unserializer, unserialize);


static const zend_function_entry ext_functions[] = {
	ZEND_NS_RAW_FENTRY("ion", "serialize", ZEND_FN(ion_serialize), arginfo_ion_serialize, 0)
	ZEND_NS_RAW_FENTRY("ion", "unserialize", ZEND_FN(ion_unserialize), arginfo_ion_unserialize, 0)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Type_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_ion_Annotation_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_ion_Symbol_ImportLocation_methods[] = {
	ZEND_ME(ion_Symbol_ImportLocation, __construct, arginfo_class_ion_Symbol_ImportLocation___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Symbol_System_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_ion_Symbol_System_SID_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_ion_Symbol_methods[] = {
	ZEND_ME(ion_Symbol, __construct, arginfo_class_ion_Symbol___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Symbol, equals, arginfo_class_ion_Symbol_equals, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Symbol_Table_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_ion_Catalog_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_ion_Collection_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_ion_Decimal_Context_methods[] = {
	ZEND_ME(ion_Decimal_Context, __construct, arginfo_class_ion_Decimal_Context___construct, ZEND_ACC_PUBLIC)
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


static const zend_function_entry class_ion_Timestamp_Precision_methods[] = {
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


static const zend_function_entry class_ion_Reader_Buffer_Reader_methods[] = {
	ZEND_ME(ion_Reader_Buffer_Reader, __construct, arginfo_class_ion_Reader_Buffer_Reader___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Reader_Buffer_Reader, getBuffer, arginfo_class_ion_Reader_Buffer_Reader_getBuffer, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Reader_Stream_methods[] = {
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader_Stream, getStream, arginfo_class_ion_Reader_Stream_getStream, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader_Stream, resetStream, arginfo_class_ion_Reader_Stream_resetStream, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Reader_Stream, resetStreamWithLength, arginfo_class_ion_Reader_Stream_resetStreamWithLength, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
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
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer, writeOne, arginfo_class_ion_Writer_writeOne, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer, writeAll, arginfo_class_ion_Writer_writeAll, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
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
	ZEND_ME(ion_Writer_Writer, writeOne, arginfo_class_ion_Writer_Writer_writeOne, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Writer, writeAll, arginfo_class_ion_Writer_Writer_writeAll, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Writer_Buffer_methods[] = {
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer_Buffer, getBuffer, arginfo_class_ion_Writer_Buffer_getBuffer, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Writer_Buffer_Writer_methods[] = {
	ZEND_ME(ion_Writer_Buffer_Writer, __construct, arginfo_class_ion_Writer_Buffer_Writer___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Buffer_Writer, getBuffer, arginfo_class_ion_Writer_Buffer_Writer_getBuffer, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Writer_Stream_methods[] = {
	ZEND_ABSTRACT_ME_WITH_FLAGS(ion_Writer_Stream, getStream, arginfo_class_ion_Writer_Stream_getStream, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_FE_END
};


static const zend_function_entry class_ion_Writer_Stream_Writer_methods[] = {
	ZEND_ME(ion_Writer_Stream_Writer, __construct, arginfo_class_ion_Writer_Stream_Writer___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_Writer_Stream_Writer, getStream, arginfo_class_ion_Writer_Stream_Writer_getStream, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ion_PHP_Serializer_methods[] = {
	ZEND_ME(ion_PHP_Serializer, __construct, arginfo_class_ion_PHP_Serializer___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_PHP_Serializer, __invoke, arginfo_class_ion_PHP_Serializer___invoke, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_PHP_Serializer, serialize, arginfo_class_ion_PHP_Serializer_serialize, ZEND_ACC_PROTECTED)
	ZEND_FE_END
};


static const zend_function_entry class_ion_PHP_Unserializer_methods[] = {
	ZEND_ME(ion_PHP_Unserializer, __construct, arginfo_class_ion_PHP_Unserializer___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_PHP_Unserializer, __invoke, arginfo_class_ion_PHP_Unserializer___invoke, ZEND_ACC_PUBLIC)
	ZEND_ME(ion_PHP_Unserializer, unserialize, arginfo_class_ion_PHP_Unserializer_unserialize, ZEND_ACC_PROTECTED)
	ZEND_FE_END
};

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

	zval enum_case_AList_value;
	ZVAL_LONG(&enum_case_AList_value, 2816);
	zend_enum_add_case_cstr(class_entry, "AList", &enum_case_AList_value);

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

static zend_class_entry *register_class_ion_Annotation(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("ion\\Annotation", IS_STRING, class_ion_Annotation_methods);

	zval enum_case_PHP_value;
	zend_string *enum_case_PHP_value_str = zend_string_init("PHP", sizeof("PHP") - 1, 1);
	ZVAL_STR(&enum_case_PHP_value, enum_case_PHP_value_str);
	zend_enum_add_case_cstr(class_entry, "PHP", &enum_case_PHP_value);

	zval enum_case_REFERENCE_value;
	zend_string *enum_case_REFERENCE_value_str = zend_string_init("R", sizeof("R") - 1, 1);
	ZVAL_STR(&enum_case_REFERENCE_value, enum_case_REFERENCE_value_str);
	zend_enum_add_case_cstr(class_entry, "REFERENCE", &enum_case_REFERENCE_value);

	zval enum_case_BACKREF_value;
	zend_string *enum_case_BACKREF_value_str = zend_string_init("r", sizeof("r") - 1, 1);
	ZVAL_STR(&enum_case_BACKREF_value, enum_case_BACKREF_value_str);
	zend_enum_add_case_cstr(class_entry, "BACKREF", &enum_case_BACKREF_value);

	zval enum_case_OBJECT_value;
	zend_string *enum_case_OBJECT_value_str = zend_string_init("o", sizeof("o") - 1, 1);
	ZVAL_STR(&enum_case_OBJECT_value, enum_case_OBJECT_value_str);
	zend_enum_add_case_cstr(class_entry, "OBJECT", &enum_case_OBJECT_value);

	zval enum_case_CLASS_OBJ_value;
	zend_string *enum_case_CLASS_OBJ_value_str = zend_string_init("c", sizeof("c") - 1, 1);
	ZVAL_STR(&enum_case_CLASS_OBJ_value, enum_case_CLASS_OBJ_value_str);
	zend_enum_add_case_cstr(class_entry, "CLASS_OBJ", &enum_case_CLASS_OBJ_value);

	zval enum_case_MAGIC_OBJ_value;
	zend_string *enum_case_MAGIC_OBJ_value_str = zend_string_init("O", sizeof("O") - 1, 1);
	ZVAL_STR(&enum_case_MAGIC_OBJ_value, enum_case_MAGIC_OBJ_value_str);
	zend_enum_add_case_cstr(class_entry, "MAGIC_OBJ", &enum_case_MAGIC_OBJ_value);

	zval enum_case_CUSTOM_OBJ_value;
	zend_string *enum_case_CUSTOM_OBJ_value_str = zend_string_init("C", sizeof("C") - 1, 1);
	ZVAL_STR(&enum_case_CUSTOM_OBJ_value, enum_case_CUSTOM_OBJ_value_str);
	zend_enum_add_case_cstr(class_entry, "CUSTOM_OBJ", &enum_case_CUSTOM_OBJ_value);

	zval enum_case_SERIALIZABLE_value;
	zend_string *enum_case_SERIALIZABLE_value_str = zend_string_init("S", sizeof("S") - 1, 1);
	ZVAL_STR(&enum_case_SERIALIZABLE_value, enum_case_SERIALIZABLE_value_str);
	zend_enum_add_case_cstr(class_entry, "SERIALIZABLE", &enum_case_SERIALIZABLE_value);

	zval enum_case_ENUM_value;
	zend_string *enum_case_ENUM_value_str = zend_string_init("E", sizeof("E") - 1, 1);
	ZVAL_STR(&enum_case_ENUM_value, enum_case_ENUM_value_str);
	zend_enum_add_case_cstr(class_entry, "ENUM", &enum_case_ENUM_value);

	zval enum_case_FIELD_NAME_INT_value;
	zend_string *enum_case_FIELD_NAME_INT_value_str = zend_string_init("i", sizeof("i") - 1, 1);
	ZVAL_STR(&enum_case_FIELD_NAME_INT_value, enum_case_FIELD_NAME_INT_value_str);
	zend_enum_add_case_cstr(class_entry, "FIELD_NAME_INT", &enum_case_FIELD_NAME_INT_value);

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

static zend_class_entry *register_class_ion_Symbol_System(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("ion\\Symbol\\System", IS_STRING, class_ion_Symbol_System_methods);

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

static zend_class_entry *register_class_ion_Symbol_System_SID(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("ion\\Symbol\\System\\SID", IS_LONG, class_ion_Symbol_System_SID_methods);

	zval enum_case_Ion_value;
	ZVAL_LONG(&enum_case_Ion_value, 1);
	zend_enum_add_case_cstr(class_entry, "Ion", &enum_case_Ion_value);

	zval enum_case_Ivm_1_0_value;
	ZVAL_LONG(&enum_case_Ivm_1_0_value, 2);
	zend_enum_add_case_cstr(class_entry, "Ivm_1_0", &enum_case_Ivm_1_0_value);

	zval enum_case_IonSymbolTable_value;
	ZVAL_LONG(&enum_case_IonSymbolTable_value, 3);
	zend_enum_add_case_cstr(class_entry, "IonSymbolTable", &enum_case_IonSymbolTable_value);

	zval enum_case_Name_value;
	ZVAL_LONG(&enum_case_Name_value, 4);
	zend_enum_add_case_cstr(class_entry, "Name", &enum_case_Name_value);

	zval enum_case_Version_value;
	ZVAL_LONG(&enum_case_Version_value, 5);
	zend_enum_add_case_cstr(class_entry, "Version", &enum_case_Version_value);

	zval enum_case_Imports_value;
	ZVAL_LONG(&enum_case_Imports_value, 6);
	zend_enum_add_case_cstr(class_entry, "Imports", &enum_case_Imports_value);

	zval enum_case_Symbols_value;
	ZVAL_LONG(&enum_case_Symbols_value, 7);
	zend_enum_add_case_cstr(class_entry, "Symbols", &enum_case_Symbols_value);

	zval enum_case_MaxId_value;
	ZVAL_LONG(&enum_case_MaxId_value, 8);
	zend_enum_add_case_cstr(class_entry, "MaxId", &enum_case_MaxId_value);

	zval enum_case_SharedSymbolTable_value;
	ZVAL_LONG(&enum_case_SharedSymbolTable_value, 9);
	zend_enum_add_case_cstr(class_entry, "SharedSymbolTable", &enum_case_SharedSymbolTable_value);

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
	zend_declare_typed_property(class_entry, property_value_name, &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
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

static zend_class_entry *register_class_ion_Symbol_Table(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Symbol", "Table", class_ion_Symbol_Table_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	return class_entry;
}

static zend_class_entry *register_class_ion_Catalog(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion", "Catalog", class_ion_Catalog_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	return class_entry;
}

static zend_class_entry *register_class_ion_Collection(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion", "Collection", class_ion_Collection_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	return class_entry;
}

static zend_class_entry *register_class_ion_Decimal_Context(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Decimal", "Context", class_ion_Decimal_Context_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval property_bits_default_value;
	ZVAL_UNDEF(&property_bits_default_value);
	zend_string *property_bits_name = zend_string_init("bits", sizeof("bits") - 1, 1);
	zend_declare_typed_property(class_entry, property_bits_name, &property_bits_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_bits_name);

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

	zval property_newLine_default_value;
	ZVAL_UNDEF(&property_newLine_default_value);
	zend_string *property_newLine_name = zend_string_init("newLine", sizeof("newLine") - 1, 1);
	zend_declare_typed_property(class_entry, property_newLine_name, &property_newLine_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_newLine_name);

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

	zval property_maxAnnotationBuffered_default_value;
	ZVAL_UNDEF(&property_maxAnnotationBuffered_default_value);
	zend_string *property_maxAnnotationBuffered_name = zend_string_init("maxAnnotationBuffered", sizeof("maxAnnotationBuffered") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxAnnotationBuffered_name, &property_maxAnnotationBuffered_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxAnnotationBuffered_name);

	zval property_symbolThreshold_default_value;
	ZVAL_UNDEF(&property_symbolThreshold_default_value);
	zend_string *property_symbolThreshold_name = zend_string_init("symbolThreshold", sizeof("symbolThreshold") - 1, 1);
	zend_declare_typed_property(class_entry, property_symbolThreshold_name, &property_symbolThreshold_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_symbolThreshold_name);

	zval property_userValueThreshold_default_value;
	ZVAL_UNDEF(&property_userValueThreshold_default_value);
	zend_string *property_userValueThreshold_name = zend_string_init("userValueThreshold", sizeof("userValueThreshold") - 1, 1);
	zend_declare_typed_property(class_entry, property_userValueThreshold_name, &property_userValueThreshold_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_userValueThreshold_name);

	zval property_chunkThreshold_default_value;
	ZVAL_UNDEF(&property_chunkThreshold_default_value);
	zend_string *property_chunkThreshold_name = zend_string_init("chunkThreshold", sizeof("chunkThreshold") - 1, 1);
	zend_declare_typed_property(class_entry, property_chunkThreshold_name, &property_chunkThreshold_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_chunkThreshold_name);

	zval property_allocationPageSize_default_value;
	ZVAL_UNDEF(&property_allocationPageSize_default_value);
	zend_string *property_allocationPageSize_name = zend_string_init("allocationPageSize", sizeof("allocationPageSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_allocationPageSize_name, &property_allocationPageSize_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_allocationPageSize_name);

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

static zend_class_entry *register_class_ion_Reader_Buffer_Reader(zend_class_entry *class_entry_ion_Reader_Reader, zend_class_entry *class_entry_ion_Reader_Buffer)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Reader\\Buffer", "Reader", class_ion_Reader_Buffer_Reader_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_ion_Reader_Reader);
	zend_class_implements(class_entry, 1, class_entry_ion_Reader_Buffer);

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

	zval property_smallContainersInline_default_value;
	ZVAL_UNDEF(&property_smallContainersInline_default_value);
	zend_string *property_smallContainersInline_name = zend_string_init("smallContainersInline", sizeof("smallContainersInline") - 1, 1);
	zend_declare_typed_property(class_entry, property_smallContainersInline_name, &property_smallContainersInline_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_smallContainersInline_name);

	zval property_suppressSystemValues_default_value;
	ZVAL_UNDEF(&property_suppressSystemValues_default_value);
	zend_string *property_suppressSystemValues_name = zend_string_init("suppressSystemValues", sizeof("suppressSystemValues") - 1, 1);
	zend_declare_typed_property(class_entry, property_suppressSystemValues_name, &property_suppressSystemValues_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_suppressSystemValues_name);

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

	zval property_allocationPageSize_default_value;
	ZVAL_UNDEF(&property_allocationPageSize_default_value);
	zend_string *property_allocationPageSize_name = zend_string_init("allocationPageSize", sizeof("allocationPageSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_allocationPageSize_name, &property_allocationPageSize_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_allocationPageSize_name);

	return class_entry;
}

static zend_class_entry *register_class_ion_Writer(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion", "Writer", class_ion_Writer_methods);
	class_entry = zend_register_internal_interface(&ce);

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

static zend_class_entry *register_class_ion_Writer_Buffer_Writer(zend_class_entry *class_entry_ion_Writer_Writer, zend_class_entry *class_entry_ion_Writer_Buffer)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Writer\\Buffer", "Writer", class_ion_Writer_Buffer_Writer_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_ion_Writer_Writer);
	zend_class_implements(class_entry, 1, class_entry_ion_Writer_Buffer);

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

static zend_class_entry *register_class_ion_Writer_Stream_Writer(zend_class_entry *class_entry_ion_Writer_Writer, zend_class_entry *class_entry_ion_Writer_Stream)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\Writer\\Stream", "Writer", class_ion_Writer_Stream_Writer_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_ion_Writer_Writer);
	zend_class_implements(class_entry, 1, class_entry_ion_Writer_Stream);

	return class_entry;
}

static zend_class_entry *register_class_ion_PHP_Serializer(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\PHP", "Serializer", class_ion_PHP_Serializer_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zend_string *property_writer_class_ion_Writer = zend_string_init("ion\\Writer", sizeof("ion\\Writer")-1, 1);
	zval property_writer_default_value;
	ZVAL_UNDEF(&property_writer_default_value);
	zend_string *property_writer_name = zend_string_init("writer", sizeof("writer") - 1, 1);
	zend_declare_typed_property(class_entry, property_writer_name, &property_writer_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_writer_class_ion_Writer, 0, 0));
	zend_string_release(property_writer_name);

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

static zend_class_entry *register_class_ion_PHP_Unserializer(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "ion\\PHP", "Unserializer", class_ion_PHP_Unserializer_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zend_string *property_reader_class_ion_Reader = zend_string_init("ion\\Reader", sizeof("ion\\Reader")-1, 1);
	zval property_reader_default_value;
	ZVAL_UNDEF(&property_reader_default_value);
	zend_string *property_reader_name = zend_string_init("reader", sizeof("reader") - 1, 1);
	zend_declare_typed_property(class_entry, property_reader_name, &property_reader_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_reader_class_ion_Reader, 0, 0));
	zend_string_release(property_reader_name);

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
