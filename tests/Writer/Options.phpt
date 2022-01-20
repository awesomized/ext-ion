--TEST--
ion\Writer\Options
--EXTENSIONS--
ion
--FILE--
TEST
<?php
$o = new ion\Writer\Options;
var_dump($o, clone $o);

$o = new ion\Writer\Options(
	catalog: new ion\Catalog,
	decimalContext: ion\Decimal\Context::Dec64(),
	outputBinary: true,
	maxContainerDepth: 20,
	tempBufferSize: 0x20000
);
var_dump($o, clone $o);
?>
DONE
--EXPECTF--
TEST
object(ion\Writer\Options)#%d (12) {
  ["catalog"]=>
  NULL
  ["decimalContext"]=>
  NULL
  ["outputBinary"]=>
  bool(false)
  ["compactFloats"]=>
  bool(false)
  ["escapeNonAscii"]=>
  bool(false)
  ["prettyPrint"]=>
  bool(false)
  ["indentTabs"]=>
  bool(true)
  ["indentSize"]=>
  int(2)
  ["flushEveryValue"]=>
  bool(false)
  ["maxContainerDepth"]=>
  int(10)
  ["maxAnnotations"]=>
  int(10)
  ["tempBufferSize"]=>
  int(16384)
}
object(ion\Writer\Options)#%d (12) {
  ["catalog"]=>
  NULL
  ["decimalContext"]=>
  NULL
  ["outputBinary"]=>
  bool(false)
  ["compactFloats"]=>
  bool(false)
  ["escapeNonAscii"]=>
  bool(false)
  ["prettyPrint"]=>
  bool(false)
  ["indentTabs"]=>
  bool(true)
  ["indentSize"]=>
  int(2)
  ["flushEveryValue"]=>
  bool(false)
  ["maxContainerDepth"]=>
  int(10)
  ["maxAnnotations"]=>
  int(10)
  ["tempBufferSize"]=>
  int(16384)
}
object(ion\Writer\Options)#%d (12) {
  ["catalog"]=>
  object(ion\Catalog)#%d (1) {
    ["symbolTables":"ion\Catalog":private]=>
    array(0) {
    }
  }
  ["decimalContext"]=>
  object(ion\Decimal\Context)#%d (5) {
    ["digits"]=>
    int(16)
    ["eMax"]=>
    int(384)
    ["eMin"]=>
    int(-383)
    ["round"]=>
    int(3)
    ["clamp"]=>
    bool(true)
  }
  ["outputBinary"]=>
  bool(true)
  ["compactFloats"]=>
  bool(false)
  ["escapeNonAscii"]=>
  bool(false)
  ["prettyPrint"]=>
  bool(false)
  ["indentTabs"]=>
  bool(true)
  ["indentSize"]=>
  int(2)
  ["flushEveryValue"]=>
  bool(false)
  ["maxContainerDepth"]=>
  int(20)
  ["maxAnnotations"]=>
  int(10)
  ["tempBufferSize"]=>
  int(131072)
}
object(ion\Writer\Options)#%d (12) {
  ["catalog"]=>
  object(ion\Catalog)#%d (1) {
    ["symbolTables":"ion\Catalog":private]=>
    array(0) {
    }
  }
  ["decimalContext"]=>
  object(ion\Decimal\Context)#%d (5) {
    ["digits"]=>
    int(16)
    ["eMax"]=>
    int(384)
    ["eMin"]=>
    int(-383)
    ["round"]=>
    int(3)
    ["clamp"]=>
    bool(true)
  }
  ["outputBinary"]=>
  bool(true)
  ["compactFloats"]=>
  bool(false)
  ["escapeNonAscii"]=>
  bool(false)
  ["prettyPrint"]=>
  bool(false)
  ["indentTabs"]=>
  bool(true)
  ["indentSize"]=>
  int(2)
  ["flushEveryValue"]=>
  bool(false)
  ["maxContainerDepth"]=>
  int(20)
  ["maxAnnotations"]=>
  int(10)
  ["tempBufferSize"]=>
  int(131072)
}
DONE
