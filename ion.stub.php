<?php

/**
 * Amazon ION serialization format.
 *
 * @link https://github.com/awesomized/ext-ion
 *
 * @see https://github.com/amzn/ion-c amzn/ion-c
 * @see https://amzn.github.io/ion-docs/ Amazon ION spec
 *
 * @generate-class-entries static
 * @generate-function-entries static
 */

namespace ion;

/**
 * Serialize a PHP value as ION data.
 *
 * Serializes supported PHP values with the optionally provided \ion\Serializer:
 *  * NULL
 *  * bool
 *  * int
 *  * float
 *  * string
 *  * reference
 *  * array
 *  * object (incl. \Serializable, and classes implementing magic and custom __serialize)
 *
 * @param mixed $data PHP value(s).
 * @param Serializer|array|null $serializer Custom serializer.
 * @return string serialized ION data
 * @throws \ion\Exception
 */
function serialize(mixed $data, Serializer|array|null $serializer = null) : string {}

/**
 * Unserialize ION data (stream) as PHP value(s).
 *
 * @param string|resource $data Serialized ION data, either as string buffer or stream.
 * @return mixed unserialized PHP values
 * @throws \ion\Exception
 */
function unserialize($data, Unserializer|array|null $unserializer = null) : mixed {}

/**
 * Serializer interface, used to customize ion\serialize()'s behavior.
 */
interface Serializer {
    public function serialize(mixed $data) : string;
}

/**
 * Unserializer interface, used to customize ion\unserialize()'s behavior.
 */
interface Unserializer {
    /** @param string|resource $data */
    public function unserialize($data) : mixed;
}

/**
 * Base exception for the ION extension.
 */
class Exception extends \Exception {
}

/**
 * ION data type.
 *
 * The following special PHP classes are provided for some data types:
 * * ion\Decimal
 * * ion\Timestamp
 * * ion\Symbol
 * * ion\Lob
 */
enum Type : int {
    case Null       = 0x000;
    case Bool       = 0x100;
    case Int        = 0x200;
    case Float      = 0x400;
    case Decimal    = 0x500;
    case Timestamp  = 0x600;
    case Symbol     = 0x700;
    case String     = 0x800;
    case CLob       = 0x900;
    case BLob       = 0xa00;
    case List       = 0xb00;
    case SExp       = 0xc00;
    case Struct     = 0xd00;
    case Datagram   = 0xf00;

    case EOF        =-0x100;
    case NONE       =-0x200;
}

/**
 * @see https://amzn.github.io/ion-docs/docs/spec.html#symbol ION spec's symbol definition
 * @see https://amzn.github.io/ion-docs/guides/symbols-guide.html ION spec's symbol guide
 */
class Symbol {
    /**
     * Create an ION symbol.
     */
    public function __construct(
        /**
         * The symbol's text representation.
         */
        public readonly ?string $value = null,
        /**
         * The symbols ID, referencing its location within a shared symbol table.
         */
        public readonly int $sid = -1,
        /**
         * The import location referencing a shared symbol table.
         */
        public readonly ?Symbol\ImportLocation $importLocation = null,
    ) {}

    /**
     * Compare two symbols for equality.
     *
     * Two symbols are considered equal, if either:
     * * both are the same object or NULL
     * * both values are NULL (unknown text), and both $importLocations match
     * * both values match, regardless of $sid and $importLocation
     *
     * @param Symbol $symbol
     * @return bool whether the two Symbols equal
     */
    public function equals(Symbol $symbol): bool {}
    public function __toString() : string {}
    /** @alias ion\Symbol::__toString */
    public function toString() : string {}
}

/**
 * The Catalog holds a collection of ion\Symbol\Table instances queried from ion\Reader and ion\Writer instances.
 *
 * @see https://amzn.github.io/ion-docs/docs/symbols.html#the-catalog the ION spec's symbol guide chapter on catalog.
 */
class Catalog implements \Countable {
    /** Internal cache. */
    private array $symbolTables = [];

    /** Create a new Catalog. */
    public function __construct() {}

    /** Count how many symbol tables the catalog holds. */
    public function count() : int {}

    /**
     * Add a shared symbol table to the catalog.
     *
     * @param Symbol\Table $table The new table to add.
     */
    public function add(Symbol\Table $table) : void {}

    /**
     * Remove a shared symbol table from the catalog.
     *
     * @param Symbol\Table|string $table The symbol table to renmove.
     * @return bool Success.
     */
    public function remove(Symbol\Table|string $table) : bool {}

    /**
     * Find a shared symbol table within the catalog.
     *
     * @param string $name The name of the symbol table.
     * @param int $version The version the symbol table should match.
     * @return Symbol\Table|null The symbol table found, if any.
     */
    public function find(string $name, int $version = 0) : ?Symbol\Table {}

    /**
     * Find a "best match" for a shared symbol table within the catalog.
     *
     * @param string $name The name of the symbol table,
     * @param int $version The minimum version of the symbol table.
     * @return Symbol\Table|null The symbol table found, if any.
     */
    public function findBest(string $name, int $version = 0) : ?Symbol\Table {}
}

/**
 * A large object.
 *
 * @see ion\Type
 * @see https://amzn.github.io/ion-docs/docs/spec.html#blob the ION spec's BLob definition
 * @see https://amzn.github.io/ion-docs/docs/spec.html#clob the ION sepc's CLob definition
 */
class LOB {
    /**
     * Create an ION large object.
     */
    public function __construct(
        /**
         * The value of the large object.
         */
        public readonly string $value,
        /**
         * The type (CLob/BLob).
         */
        public readonly Type $type = Type::CLob,
    ) {}
}

/**
 * An arbitrary precision fixed point decimal.
 *
 * @see ion\Decimal\Context
 * @see https://amzn.github.io/ion-docs/docs/decimal.html the ION spec's decimal docs
 */
class Decimal {
    /**
     * Create a new fixed point decimal.
     */
    public function __construct(
        /**
         * The decimal number.
         */
        public readonly string|int $number,
        /**
         * The decimal context.
         */
        public readonly ?Decimal\Context $context = null,
    ) {}

    /**
     * Check two decimals for equality.
     *
     * @param Decimal $decimal The decimal to compare to.
     * @return bool Whether both decimals equal.
     */
    public function equals(Decimal $decimal) : bool {}

    /**
     * Check whether the decimal is actually a big integer.
     * @return bool Whether the decimal is actually an integer.
     */
    public function isInt() : bool {}

    public function __toString() : string {}
    /**
     * Get the string representation of the decimal.
     * @alias ion\Decimal::__toString
     */
    public function toString() : string {}

    /**
     * Get the integer represention of the decimal.
     * @throws \ion\Exception If the decimal is actually not an integer.
     */
    public function toInt() : int {}
}

/**
 * An ION Timestamp.
 * @see https://amzn.github.io/ion-docs/docs/spec.html#timestamp the ION spec's timestamp definition
 * @see https://php.net/date PHP's date documentation
 */
class Timestamp extends \DateTime {
    /**
     * The timestamp's precision. See ion\Timestamp\Precision.
     */
    public readonly int $precision;
    /**
     * The timestamp's format. See ion\Timestamp\Format.
     */
    public readonly string $format;

    /**
     * Create a new ION timestamp.
     *
     * @param Timestamp\Precision|int $precision The timestamp's precision.
     * @param Timestamp\Format|string|null $format The timestamp's format.
     * @param string|null $datetime The timestamp's value.
     * @param \DateTimeZone|string|null $timezone The timestamp's timezone.
     */
    public function __construct(
        Timestamp\Precision|int $precision,
        Timestamp\Format|string|null $format = null,
        ?string $datetime = null,
        \DateTimeZone|string|null $timezone = null,
    ) {}

    public function __toString() : string {}
}

/**
 * ION reader API.
 */
interface Reader extends \RecursiveIterator {
    public function getType() : Type;
    public function hasAnnotations() : bool;
    public function hasAnnotation(string $annotation) : bool;
    public function isNull() : bool;
    public function isInStruct() : bool;
    public function getFieldName() : string;
    public function getFieldNameSymbol() : Symbol;
    public function getAnnotations() : array;
    public function getAnnotationSymbols() : array;
    public function countAnnotations() : int;
    public function getAnnotation(int $index) : string;
    public function getAnnotationSymbol(int $index) : Symbol;

    public function readNull() : Type;
    public function readBool() : bool;
    public function readInt() : int|string;
    public function readFloat() : float;
    public function readDecimal() : Decimal;
    public function readTimestamp() : Timestamp;
    public function readSymbol() : Symbol;
    public function readString() : string;
    /** @param ref $string */
    public function readStringPart(&$string, int $length = 0x1000) : bool;
    public function readLob() : string;
    /** @param ref $string */
    public function readLobPart(&$string, int $length = 0x1000) : bool;

    public function getPosition() : int;
    public function getDepth() : int;

    public function seek(int $offset, int $length = -1) : void;
    /*
    public function getSymbolTable() : SymbolTable;
    public function setSymbolTable(SymbolTable $table) : void;
    */
    public function getValueOffset() : int;
    public function getValueLength() : int;
}

/**
 * ION writer API.
 */
interface Writer {
    public function writeNull() : void;
    public function writeTypedNull(Type $type) : void;
    public function writeBool(bool $value) : void;
    public function writeInt(int|string $value) : void;
    public function writeFloat(float $value) : void;
    public function writeDecimal(Decimal|string $value) : void;
    public function writeTimestamp(Timestamp|string $value) : void;
    public function writeSymbol(Symbol|string $value) : void;
    public function writeString(string $value) : void;
    public function writeCLob(string $value) : void;
    public function writeBLob(string $value) : void;

    public function startLob(Type $type) : void;
    public function appendLob(string $data) : void;
    public function finishLob() : void;

    public function startContainer(Type $type) : void;
    public function finishContainer() : void;

    public function writeFieldName(string $name) : void;

    public function writeAnnotation(Symbol|string ...$annotation) : void;

    public function getDepth() : int;
    public function flush() : int;
    public function finish() : int;

    // public function writeOne(Reader $reader) : void;
    // public function writeAll(Reader $reader) : void;

    // public function getCatalog() : Catalog;
    // public function setCatalog(Catalog $catalog) : void;

    // public function getSymbolTable() : Symbol\Table;
    // puvlic function setSymbolTable(Symbol\Table $table) : void;
}

namespace ion\Symbol;

/**
 * The import location (referring to a shared table) of a symbol.
 */
class ImportLocation {
    /**
     * Create a new import location.
     */
    public function __construct(
        /**
         * The name of the shared symbol table.
         */
        public readonly string $name,
        /**
         * The location (sid) of the symbol within the table.
         */
        public readonly int $location,
    ) {}
}

/**
 * Base interface of built-in shared symbol tables.
 */
interface Enum {
    /**
     * @return \ion\Symbol Instance of the symbol.
     */
    public function toSymbol() : \ion\Symbol;

    /**
     * @return int The symbol id.
     */
    public function toSID() : int;

    /**
     * @return string The symbol's textual representation.
     */
    public function toString() : string;
}

/**
 * Base interface of an ION symbol table.
 */
interface Table {
    /**
     * Get the maximum symbol ID within the symbol table.
     * @return int The maximum symbol ID.
     */
    public function getMaxId() : int;

    /**
     * Add a symbol to the table.
     *
     * @param \ion\Symbol|string $symbol The symbol (value) to add.
     * @return int The symbol ID.
     */
    public function add(\ion\Symbol|string $symbol) : int;

    /**
     * Find a symbol within the symbol table, including imports.
     *
     * @param string|int $id The ID or text of the symbol to find.
     * @return \ion\Symbol|null The symbol found, if any.
     */
    public function find(string|int $id) : ?\ion\Symbol;

    /**
     * Find a symbol within **only this** symbol table, ignoring imports.
     *
     * @param string|int $id The ID or text of the symbol to find.
     * @return \ion\Symbol|null The symbol found, if any.
     */
    public function findLocal(string|int $id) : ?\ion\Symbol;
}

/**
 * The built-in ION system symbols.
 */
enum System : string implements \ion\Symbol\Enum {
    case Ion                = '$ion';
    case Ivm_1_0            = '$ion_1_0';
    case IonSymbolTable     = '$ion_symbol_table';
    case Name               = 'name';
    case Version            = 'version';
    case Imports            = 'imports';
    case Symbols            = 'symbols';
    case MaxId              = 'max_id';
    case SharedSymbolTable  = '$ion_shared_symbol_table';

    /** @alias ion\Symbol\Enum::toSymbol */
    public function toSymbol() : \ion\Symbol {}
    /** @alias ion\Symbol\Enum::toSID */
    public function toSID() : int {}
    /** @alias ion\Symbol\Enum::toString */
    public function toString() : string {}

    /**
     * Get the built-in ION system shared symbol table.
     *
     * @return Table\Shared The system symbol table.
     */
    public static function asTable() : Table\Shared {}
}

/**
 * The built-in PHP symbols.
 */
enum PHP : string implements \ion\Symbol\Enum {
    case PHP            = 'PHP';
    case Reference      = 'R';
    case Backref        = 'r';
    case Property       = 'p';
    case Object         = 'o';
    case ClassObject    = 'c';
    case MagicObject    = 'O';
    case CustomObject   = 'C';
    case Enum           = 'E';
    case Serializable   = 'S';

    /** @alias ion\Symbol\Enum::toSymbol */
    public function toSymbol() : \ion\Symbol {}
    /** @alias ion\Symbol\Enum::toSID */
    public function toSID() : int {}
    /** @alias ion\Symbol\Enum::toString */
    public function toString() : string {}

    /**
     * Get the built-in PHP shared symbol table.
     *
     * @return Table\Shared The builtin PHP shared symbol table.
     */
    public static function asTable() : Table\Shared {}
}

namespace ion\Symbol\Table;

/**
 * A local symbol table.
 *
 * @see https://amzn.github.io/ion-docs/guides/symbols-guide.html the ION spec's symbol guide
 * @see https://amzn.github.io/ion-docs/guides/cookbook.html#using-a-local-symbol-table the ION doc's cookbook
 */
class Local implements \ion\Symbol\Table {
    /** Internal cache. */
    private array $imports = [];
    /** Internal cache. */
    private array $symbols = [];

    /**
     * Create a local symbol table.
     */
    public function __construct() {}

    /**
     * Import a symbol table.
     *
     * @param \ion\Symbol\Table $table The symbol table to import.
     * @return void
     */
    public function import(\ion\Symbol\Table $table) : void {}

    /** @alias ion\Symbol\Table::getMaxId */
    public function getMaxId() : int {}

    /** @alias ion\Symbol\Table::add */
    public function add(\ion\Symbol|string $symbol) : int {}
    /** @alias ion\Symbol\Table::find */
    public function find(string|int $id) : ?\ion\Symbol {}
    /** @alias ion\Symbol\Table::findLocal */
    public function findLocal(string|int $id) : ?\ion\Symbol {}
}

/**
 * A shared symbol table.
 *
 * @see https://amzn.github.io/ion-docs/guides/symbols-guide.html the ION spec's symbol guide
 * @see https://amzn.github.io/ion-docs/guides/cookbook.html#using-a-shared-symbol-table the ION doc's cookbook
 */
class Shared implements \ion\Symbol\Table {
    /**
     * Create a shared symbol table.
     */
    public function __construct(
        /**
         * The name of the shared symbol table.
         */
        public readonly string $name,
        /**
         * The version of the shared symbol table.
         */
        public readonly int $version = 1,
        /**
         * Predefined list of symbols as array of strings.
         */
        ?array $symbols = null,
    ) {}

    /** Internal cache. */
    private array $symbols = [];

    /** @alias ion\Symbol\Table::getMaxId */
    public function getMaxId() : int {}

    /** @alias ion\Symbol\Table::add */
    public function add(\ion\Symbol|string $symbol) : int {}
    /** @alias ion\Symbol\Table::find */
    public function find(string|int $id) : ?\ion\Symbol {}
    /** @alias ion\Symbol\Table::findLocal */
    public function findLocal(string|int $id) : ?\ion\Symbol {}
}

namespace ion\Decimal;

/**
 * An ion\Decimal's context.
 */
class Context {
    /**
     * Create a new decimal context.
     */
    public function __construct(
        /**
         * Maximum digits.
         */
        public readonly int $digits,
        /**
         * Maximum exponent.
         */
        public readonly int $eMax,
        /**
         * Minimum exponent.
         */
        public readonly int $eMin,
        /**
         * Rounding mode.
         */
        public readonly Context\Rounding|int $round,
        /**
         * Whether to clamp.
         */
        public readonly bool $clamp,
    ) {}

    /**
     * Create a context suitable for 32bit decimals.
     */
    public static function Dec32() : Context {}

    /**
     * Create a context suitable for 64bit decimals.
     */
    public static function Dec64() : Context {}

    /**
     * Create a context suitable for 128bit decimals.
     */
    public static function Dec128() : Context {}

    /**
     * Create a context with maximum settings.
     * @param Context\Rounding|int $round Rounding mode.
     */
    public static function DecMax(Context\Rounding|int $round = Context\Rounding::HalfEven) : Context {}
}

namespace ion\Decimal\Context;

/**
 * Rounding mode.
 */
enum Rounding : int {
    case Ceiling    = 0;
    case Up         = 1;
    case HalfUp     = 2;
    case HalfEven   = 3;
    case HalfDown   = 4;
    case Down       = 5;
    case Floor      = 6;
    case Down05Up   = 7;
}

namespace ion\Timestamp;

/**
 * Timestamp precision.
 */
enum Precision : int {
    case Year           = 0x1;
    case Month          = 0x1|0x2;
    case Day            = 0x1|0x2|0x4;
    case Min            = 0x1|0x2|0x4|0x10;
    case Sec            = 0x1|0x2|0x4|0x10|0x20;
    case Frac           = 0x1|0x2|0x4|0x10|0x20|0x40;
    case MinTZ          = 0x1|0x2|0x4|0x10|0x80;
    case SecTZ          = 0x1|0x2|0x4|0x10|0x20|0x80;
    case FracTZ         = 0x1|0x2|0x4|0x10|0x20|0x40|0x80;
}

/**
 * Timestamp format.
 */
enum Format : string {
    case Year           = "Y\T";
    case Month          = "Y-m\T";
    case Day            = "Y-m-d\T";
    case Min            = "Y-m-d\TH:i";
    case Sec            = "Y-m-d\TH:i:s";
    case Frac           = "Y-m-d\TH:i:s.v";
    case MinTZ          = "Y-m-d\TH:iP";
    case SecTZ          = "Y-m-d\TH:i:sP";
    case FracTZ         = "Y-m-d\TH:i:s.vP";
}

namespace ion\Reader;

/**
 * Reader options.
 */
class Options {
    public function __construct(
        /**
         * ION catalog to use for symbol lookup.
         */
        public readonly ?\ion\Catalog $catalog = null,
        /**
         * Decimal context to use.
         */
        public readonly ?\ion\Decimal\Context $decimalContext = null,
        /**
         * Callback as function(\ion\Reader):void called upon local symbol table context change.
         */
        public readonly ?\Closure $onContextChange = null,
        /**
         * Whether to return otherwise hidden system values.
         */
        public readonly bool $returnSystemValues = false,
        /**
         * The maximum depth of nested containers.
         */
        public readonly int $maxContainerDepth = 10,
        /**
         * The maximum number of annotations allowed on a single value.
         */
        public readonly int $maxAnnotations = 10,
        /**
         * The maximum number of bytes of all annotations on a single value.
         */
        public readonly int $annotationBufferSize = 0x4000,
        /**
         * The maximum number of bytes of a symbol/value/chunk.
         */
        public readonly int $tempBufferSize = 0x4000,
        /**
         * Whether to skip UTF-8 validation.
         */
        public readonly bool $skipCharacterValidation = false,
    ) {}
}

/**
 * Base implementation of ION readers.
 */
abstract class Reader implements \ion\Reader {
    /**
     * Reader options.
     */
    public readonly ?Options $options;

    public function hasChildren() : bool {}
    public function getChildren() : \ion\Reader {}

    public function rewind() : void {}
    public function next() : void {}
    public function valid() : bool {}
    public function key() : mixed {}
    public function current() : mixed {}

    public function getType() : \ion\Type {}
    public function hasAnnotations() : bool {}
    public function hasAnnotation(string $annotation) : bool {}
    public function isNull() : bool {}
    public function isInStruct() : bool {}
    public function getFieldName() : string {}
    public function getFieldNameSymbol() : \ion\Symbol {}
    public function getAnnotations() : array {}
    public function getAnnotationSymbols() : array {}
    public function countAnnotations() : int {}
    public function getAnnotation(int $index) : string {}
    public function getAnnotationSymbol(int $index) : \ion\Symbol {}

    public function readNull() : \ion\Type {}
    public function readBool() : bool {}
    public function readInt() : int|string {}
    public function readFloat() : float {}
    public function readDecimal() : \ion\Decimal {}
    public function readTimestamp() : \ion\Timestamp {}
    public function readSymbol() : \ion\Symbol {}
    public function readString() : string {}
    /** @param ref $string */
    public function readStringPart(&$string, int $length = 0x1000) : bool {}
    public function readLob() : string {}
    /** @param ref $string */
    public function readLobPart(&$string, int $length = 0x1000) : bool {}

    public function getPosition() : int {}
    public function getDepth() : int{}

    public function seek(int $offset, int $length = -1) : void {}
    /*
    public function getSymbolTable() : SymbolTable {}
    public function setSymbolTable(SymbolTable $table) : void {}
    */
    public function getValueOffset() : int {}
    public function getValueLength() : int {}
}

/**
 * ION string buffer reader API.
 */
interface Buffer extends \ion\Reader {
    /**
     * Get the buffer read from.
     *
     * @return string The buffer read from.
     */
    public function getBuffer() : string;
}

/**
 * ION stream reader API.
 */
interface Stream extends \ion\Reader {
    /**
     * Get the stream read from.
     *
     * @return resource The stream read from.
     */
    public function getStream();

    /**
     * Reset the stream read from.
     *
     * @param resource $stream The new stream to from.
     */
    public function resetStream($stream) : void;

    /**
     * Reset the stream read from, limiting length to read.
     *
     * @param resource $stream The stream to read from.
     * @param int $length The maximum length to read from $stream.
     */
    public function resetStreamWithLength($stream, int $length) : void;
}

namespace ion\Reader\Buffer;

/**
 * ION buffer reader.
 */
class Reader extends \ion\Reader\Reader implements \ion\Reader\Buffer {
    /**
     * Create a new string buffer reader.
     *
     * @param string $buffer The buffer to read from.
     * @param \ion\Reader\Options|null $options Reader options.
     */
    public function __construct(
        string $buffer,
        ?\ion\Reader\Options $options = null,
    ) {}

    public function getBuffer() : string {}
}

namespace ion\Reader\Stream;

/**
 * ION stream reader.
 */
class Reader extends \ion\Reader\Reader implements \ion\Reader\Stream {
    /**
     * Create a new stream reader.
     *
     * @param resource $stream The stream to read from.
     * @param \ion\Reader\Options|null $options Reader options.
     */
    public function __construct(
        $stream,
        ?\ion\Reader\Options $options = null,
    ) {}

    /**
     * Get the stream read from.
     *
     * @return resource The stream read from.
     */
    public function getStream() {}

    /** @param resource $stream */
    public function resetStream($stream) : void {}
    /** @param resource $stream */
    public function resetStreamWithLength($stream, int $length) : void {}
}

namespace ion\Writer;

/**
 * ION writer options.
 */
class Options {
    /**
     * Create custom ION writer options.
     */
    public function __construct(
        /**
         * ION catalog to use for symbol lookup.
         */
        public readonly ?\ion\Catalog $catalog = null,
        /**
         * Decimal context to use.
         */
        public readonly ?\ion\Decimal\Context $decimalContext = null,
        /**
         * Whether to output binary ION.
         */
        public readonly bool $outputBinary = false,
        /**
         * Whether to write doubles which fit in 32 bits as floats.
         */
        public readonly bool $compactFloats = false,
        /**
         * Whether to slash-escape all non ASCII bytes.
         */
        public readonly bool $escapeNonAscii = false,
        /**
         * Whether to produce pretty-printed output.
         */
        public readonly bool $prettyPrint = false,
        /**
         * Whether to indent with tabs, when pretty-printing.
         */
        public readonly bool $indentTabs = true,
        /**
         * The number of spaces to use for indentation instead of tabs, when pretty-printing.
         */
        public readonly int $indentSize = 2,
        /**
         * Whether to immediately flush every value written.
         */
        public readonly bool $flushEveryValue = false,
        /**
         * Maximum depth of nested containers.
         */
        public readonly int $maxContainerDepth = 10,
        /**
         * The maximum number of annotations allowed on a single value.
         */
        public readonly int $maxAnnotations = 10,
        /**
         * Temporary buffer size.
         */
        public readonly int $tempBufferSize = 0x4000,
    ) {}
}

/**
 * Base implementation of common functionality of ION writers.
 */
abstract class Writer implements \ion\Writer {
    public function writeNull() : void {}
    public function writeTypedNull(\ion\Type $type) : void {}
    public function writeBool(bool $value) : void {}
    public function writeInt(int|string $value) : void {}
    public function writeFloat(float $value) : void {}
    public function writeDecimal(\ion\Decimal|string $value) : void {}
    public function writeTimestamp(\ion\Timestamp|string $value) : void {}
    public function writeSymbol(\ion\Symbol|string $value) : void {}
    public function writeString(string $value) : void {}
    public function writeCLob(string $value) : void {}
    public function writeBLob(string $value) : void {}

    public function startLob(\ion\Type $type) : void {}
    public function appendLob(string $data) : void {}
    public function finishLob() : void {}

    public function startContainer(\ion\Type $type) : void {}
    public function finishContainer() : void {}

    public function writeFieldName(string $name) : void {}

    public function writeAnnotation(\ion\Symbol|string ...$annotation) : void {}

    public function getDepth() : int {}
    public function flush() : int {}
    public function finish() : int {}

    // public function writeOne(\ion\Reader $reader) : void {}
    // public function writeAll(\ion\Reader $reader) : void {}
}

/**
 * ION buffer writer API.
 */
interface Buffer extends \ion\Writer {
    /**
     * Get the buffer written to.
     *
     * @reeturn string The buffer written so far.
     */
    public function getBuffer() : string;

    /**
     * Reset the buffer written to.
     */
    public function resetBuffer() : void;
}

/**
 * ION stream writer API.
 */
interface Stream extends \ion\Writer {
    /**
     * Get the stream being written to.
     * @return resource
     */
    public function getStream();
}

namespace ion\Writer\Buffer;

/**
 * IO buffer writer.
 */
class Writer extends \ion\Writer\Writer implements \ion\Writer\Buffer {
    /**
     * Create a new buffer writer.
     *
     * @param \ion\Writer\Options|null $options Writer options.
     */
    public function __construct(
        ?\ion\Writer\Options $options = null,
    ) {}

    public function getBuffer() : string {}
    public function resetBuffer() : void {}
}

namespace ion\Writer\Stream;

/**
 * ION stream writer.
 */
class Writer extends \ion\Writer\Writer implements \ion\Writer\Stream {
    /**
     * Create a new stream writer.
     *
     * @param resource $stream The stream to write to.
     * @param \ion\Writer\Options|null $options Writer options.
     */
    public function __construct(
        $stream,
        ?\ion\Writer\Options $options = null,
    ) {}
    /**
     * @return resource
     */
    public function getStream() {}
}

namespace ion\Serializer;

/**
 * Specialization of the serializer for PHP.
 */
class PHP implements \ion\Serializer {
    /**
     * Create a new PHP ION serializer.
     */
    public function __construct(
        /**
         * Writer options.
         */
        public readonly \ion\Writer\Options|array|null $writerOptions = null,
        /**
         * Whether to write the top level array as multiple ION sequences.
         */
        public readonly bool $multiSequence = false,
        /**
         * Whether to call magic __serialize() methods on objects to serialize.
         */
        public readonly bool $callMagicSerialize = true,
        /**
         * Whether and which custom serialize method to call on objects to serialize.
         */
        public readonly ?string $callCustomSerialize = null,
    ) {}

    public function serialize(mixed $data) : string {}
}

namespace ion\Unserializer;

/**
 * Specialization of the unserializer for PHP.
 */
class PHP implements \ion\Unserializer {
    /**
     * Create a new ION PHP unserializer.
     */
    public function __construct(
        /**
         * Reader options.
         */
        public readonly \ion\Reader\Options|array|null $readerOptions = null,
        /**
         * Whether to continue reading multiple ION sequences after the first one.
         */
        public readonly bool $multiSequence = false,
        /**
         * Whether to call magic __unserialize() methods on objects to unserialize.
         */
        public readonly bool $callMagicUnserialize = true,
        /**
         * Whether and which custom unserialize method to call on objects to unserialize.
         */
        public readonly ?string $callCustomUnserialize = null,
    ){}

    /** @param string|resource $data */
    public function unserialize($data) : mixed {}
}
