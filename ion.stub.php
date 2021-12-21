<?php

/**
 * @generate-class-entries static
 * @generate-function-entries static
 */


namespace ion;
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
    case AList      = 0xb00;
    case SExp       = 0xc00;
    case Struct     = 0xd00;
    case Datagram   = 0xf00;

    case EOF        =-0x100;
    case NONE       =-0x200;
}

namespace ion\Symbol;
class ImportLocation {
    public function __construct(
        public readonly string $name,
        public readonly int $location,
    ) {}
}

namespace ion\Symbol;
interface Enum {
    public function toSymbol() : \ion\Symbol;
    public function toSID() : int;
    public function toString() : string;
}

namespace ion\Symbol\Table;
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
}

namespace ion\Symbol\Table;
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
}

namespace ion;
class Symbol {
    public function __construct(
        public readonly ?string $value = null,
        public readonly int $sid = -1,
        public readonly ?Symbol\ImportLocation $importLocation = null,
    ) {}

    public function equals(Symbol $symbol): bool {}
    public function __toString() : string {}
    /** @alias ion\Symbol::__toString */
    public function toString() : string {}
}

namespace ion\Symbol;
interface Table {
    public function getMaxId() : int;

    public function add(\ion\Symbol|string $symbol) : int;
    public function find(string|int $id) : ?\ion\Symbol;
    public function findLocal(string|int $id) : ?\ion\Symbol;
}

namespace ion\Symbol\Table;
function PHP() : \ion\Symbol\Table {}
function System() : \ion\Symbol\Table {}

namespace ion\Symbol\Table;
class Local implements \ion\Symbol\Table {
    private array $imports = [];
    private array $symbols = [];

    public function __construct() {}
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

namespace ion\Symbol\Table;
class Shared implements \ion\Symbol\Table {
    public function __construct(
        public readonly string $name,
        public readonly int $version = 1,
        ?array $symbols = null,
    ) {}

    /** Internal cache */
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

namespace ion;
class Catalog implements Countable {
    /** Internal cache */
    private array $symbolTables = [];

    public function __construct() {}

    public function count() : int {}

    public function add(Symbol\Table $table) : void {}
    public function remove(Symbol\Table|string $table) : bool {}

    public function find(string $name, int $version = 0) : ?Symbol\Table {}
    public function findBest(string $name, int $version = 0) : ?Symbol\Table {}
}

namespace ion;
class LOB {
    public function __construct(
        public readonly string $value,
        public readonly Type $type = Type::CLob,
    ) {
    }
}

namespace ion\Decimal\Context;
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

namespace ion\Decimal;
class Context {
    public function __construct(
        public readonly int $digits,
        public readonly int $eMax,
        public readonly int $eMin,
        public readonly Context\Rounding|int $round,
        public readonly bool $clamp,
    ) {}

    public static function Dec32() : Context {}
    public static function Dec64() : Context {}
    public static function Dec128() : Context {}
    public static function DecMax(Context\Rounding|int $round = Context\Rounding::HalfEven) : Context {}
}

namespace ion;
class Decimal {
    public function __construct(
        public readonly string|int $number,
        public readonly ?Decimal\Context $context = null,
    ) {}

    public function equals(Decimal $decimal) : bool {}
    public function isInt() : bool {}

    public function __toString() : string {}
    /** @alias ion\Decimal::__toString */
    public function toString() : string {}
    public function toInt() : int {}
}

namespace ion\Timestamp;
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
namespace ion;
class Timestamp extends \DateTime {
    public readonly int $precision;
    public readonly string $format;

    public function __construct(
        Timestamp\Precision|int $precision,
        ?string $format = null,
        ?string $datetime = null,
        ?\DateTimeZone $timezone = null,
    ) {}

    public function __toString() : string {}
}


namespace ion;
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
namespace ion\Reader;
class Options {
    public function __construct(
        public readonly ?\ion\Catalog $catalog = null,
        public readonly ?\ion\Decimal\Context $decimalContext = null,
        public readonly ?\Closure $onContextChange = null,
        public readonly bool $returnSystemValues = false,
        public readonly int $newLine = 0xa,
        public readonly int $maxContainerDepth = 10,
        public readonly int $maxAnnotations = 10,
        public readonly int $maxAnnotationBuffered = 512,
        public readonly int $symbolThreshold = 0x4000,
        public readonly int $userValueThreshold = 0x4000,
        public readonly int $chunkThreshold = 0x4000,
        public readonly int $allocationPageSize = 0x10000,
        public readonly bool $skipCharacterValidation = false,
    ) {}
}

namespace ion\Reader;
abstract class Reader implements \ion\Reader {
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
namespace ion\Reader;
interface Buffer extends \ion\Reader {
    public function getBuffer() : string;
}

namespace ion\Reader\Buffer;
class Reader extends \ion\Reader\Reader implements \ion\Reader\Buffer {
    public function __construct(
        string $buffer,
        ?\ion\Reader\Options $options = null,
    ) {}

    public function getBuffer() : string {}
}

namespace ion\Reader;
interface Stream extends \ion\Reader {
    /** @return resource */
    public function getStream();
    /** @param resource $stream */
    public function resetStream($stream) : void;
    /** @param resource $stream */
    public function resetStreamWithLength($stream, int $position, int $length = -1) : void;
}

namespace ion\Reader\Stream;
class Reader extends \ion\Reader\Reader implements \ion\Reader\Stream {
    /** @param resource $stream */
    public function __construct(
        $stream,
        ?\ion\Reader\Options $options = null,
    ) {
    }
    /** @return resource */
    public function getStream() {}
    /** @param resource $stream */
    public function resetStream($stream) : void {}
    /** @param resource $stream */
    public function resetStreamWithLength($stream, int $position, int $length = -1) : void {}
}

namespace ion\Writer;
class Options {
    public function __construct(
        public readonly ?\ion\Catalog $catalog = null,
        public readonly ?\ion\Decimal\Context $decimalContext = null,
        public readonly bool $outputBinary = false,
        public readonly bool $compactFloats = false,
        public readonly bool $escapeNonAscii = false,
        public readonly bool $prettyPrint = false,
        public readonly bool $indentTabs = true,
        public readonly int $indentSize = 2,
        public readonly bool $smallContainersInline = true,
        public readonly bool $suppressSystemValues = false,
        public readonly bool $flushEveryValue = false,
        public readonly int $maxContainerDepth = 10,
        public readonly int $maxAnnotations = 10,
        public readonly int $tempBufferSize = 0x4000,
        public readonly int $allocationPageSize = 0x10000,
    ) {}
}

namespace ion;
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

    public function writeOne(Reader $reader) : void;
    public function writeAll(Reader $reader) : void;

    // public function getCatalog() : Catalog;
    // public function setCatalog(Catalog $catalog) : void;

    // public function getSymbolTable() : Symbol\Table;
    // puvlic function setSymbolTable(Symbol\Table $table) : void;
}

namespace ion\Writer;
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

    public function writeOne(\ion\Reader $reader) : void {}
    public function writeAll(\ion\Reader $reader) : void {}
}

namespace ion\Writer;
interface Buffer extends \ion\Writer {
    public function getBuffer() : string;
}

namespace ion\Writer\Buffer;
class Writer extends \ion\Writer\Writer implements \ion\Writer\Buffer {
    /** @param ref $buffer */
    public function __construct(
        ?string &$buffer,
        ?\ion\Writer\Options $options = null,
    ) {}

    /**
     * @return string a _copy_ of $buffer passed to the constructor
     */
    public function getBuffer() : string {}
}

namespace ion\Writer;
interface Stream extends \ion\Writer {
    /** @return resource */
    public function getStream();
}

namespace ion\Writer\Stream;
class Writer extends \ion\Writer\Writer implements \ion\Writer\Stream {
    /** @param resource $stream */
    public function __construct(
        $stream,
        ?\ion\Writer\Options $options = null,
    ) {}
    /** @return resource */
    public function getStream() {}
}

namespace ion;
interface Serializer {
    public function __invoke(mixed $data) : string;
    // protected function serialize(mixed $data) : string;
}
namespace ion;
interface Unserializer {
    /** @param string|resource $data */
    public function __invoke($data) : mixed;
    // /** @param string|resource $data */
    // protected function unserialize($data) : mixed;
}

namespace ion\Serializer;
class PHP implements \ion\Serializer {
    public function __construct(
        public readonly ?\ion\Writer\Options $writerOptions = null,
        public readonly bool $multiSequence = false,
        public readonly bool $callMagicSerialize = true,
        public readonly ?string $callCustomSerialize = null,
    ) {}
    public function __invoke(mixed $data) : string {}
    protected function serialize(mixed $data) : string {}
}

namespace ion\Unserializer;
class PHP implements \ion\Unserializer {
    public function __construct(
        public readonly ?\ion\Reader\Options $readerOptions = null,
        public readonly bool $multiSequence = true,
        public readonly bool $callMagicUnserialize = true,
        public readonly ?string $callCustomUnserialize = null,
    ){}
    /** @param string|resource $data */
    public function __invoke($data) : mixed {}
    /** @param string|resource $data */
    protected function unserialize($data) : mixed {}
}

namespace ion;
function serialize(mixed $data, ?Serializer $serializer = null) : string {}
/** @param string|resource $data */
function unserialize($data, ?Unserializer $unserializer = null) : mixed {}
