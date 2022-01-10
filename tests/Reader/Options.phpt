--TEST--
ion\Reader\Options
--EXTENSIONS--
ion
--FILE--
TEST
<?php
$o = new ion\Reader\Options;
var_dump($o, clone $o);

$o = new ion\Reader\Options(
	catalog: new ion\Catalog,
	decimalContext: ion\Decimal\Context::Dec32(),
	onContextChange: function(ion\Reader $r) {},
	returnSystemValues: true,
	skipCharacterValidation: true,
);
var_dump($o, clone $o);
?>
DONE
--EXPECTF--
TEST
object(ion\Reader\Options)#%d (13) {
  ["catalog"]=>
  NULL
  ["decimalContext"]=>
  NULL
  ["onContextChange"]=>
  NULL
  ["returnSystemValues"]=>
  bool(false)
  ["newLine"]=>
  int(10)
  ["maxContainerDepth"]=>
  int(10)
  ["maxAnnotations"]=>
  int(10)
  ["maxAnnotationBuffered"]=>
  int(512)
  ["symbolThreshold"]=>
  int(16384)
  ["userValueThreshold"]=>
  int(16384)
  ["chunkThreshold"]=>
  int(16384)
  ["allocationPageSize"]=>
  int(65536)
  ["skipCharacterValidation"]=>
  bool(false)
}
object(ion\Reader\Options)#%d (13) {
  ["catalog"]=>
  NULL
  ["decimalContext"]=>
  NULL
  ["onContextChange"]=>
  NULL
  ["returnSystemValues"]=>
  bool(false)
  ["newLine"]=>
  int(10)
  ["maxContainerDepth"]=>
  int(10)
  ["maxAnnotations"]=>
  int(10)
  ["maxAnnotationBuffered"]=>
  int(512)
  ["symbolThreshold"]=>
  int(16384)
  ["userValueThreshold"]=>
  int(16384)
  ["chunkThreshold"]=>
  int(16384)
  ["allocationPageSize"]=>
  int(65536)
  ["skipCharacterValidation"]=>
  bool(false)
}
object(ion\Reader\Options)#%d (13) {
  ["catalog"]=>
  object(ion\Catalog)#%d (1) {
    ["symbolTables":"ion\Catalog":private]=>
    array(0) {
    }
  }
  ["decimalContext"]=>
  object(ion\Decimal\Context)#%d (5) {
    ["digits"]=>
    int(7)
    ["eMax"]=>
    int(96)
    ["eMin"]=>
    int(-95)
    ["round"]=>
    int(3)
    ["clamp"]=>
    bool(true)
  }
  ["onContextChange"]=>
  object(Closure)#%d (1) {
    ["parameter"]=>
    array(1) {
      ["$r"]=>
      string(10) "<required>"
    }
  }
  ["returnSystemValues"]=>
  bool(true)
  ["newLine"]=>
  int(10)
  ["maxContainerDepth"]=>
  int(10)
  ["maxAnnotations"]=>
  int(10)
  ["maxAnnotationBuffered"]=>
  int(512)
  ["symbolThreshold"]=>
  int(16384)
  ["userValueThreshold"]=>
  int(16384)
  ["chunkThreshold"]=>
  int(16384)
  ["allocationPageSize"]=>
  int(65536)
  ["skipCharacterValidation"]=>
  bool(true)
}
object(ion\Reader\Options)#%d (13) {
  ["catalog"]=>
  object(ion\Catalog)#%d (1) {
    ["symbolTables":"ion\Catalog":private]=>
    array(0) {
    }
  }
  ["decimalContext"]=>
  object(ion\Decimal\Context)#%d (5) {
    ["digits"]=>
    int(7)
    ["eMax"]=>
    int(96)
    ["eMin"]=>
    int(-95)
    ["round"]=>
    int(3)
    ["clamp"]=>
    bool(true)
  }
  ["onContextChange"]=>
  object(Closure)#%d (1) {
    ["parameter"]=>
    array(1) {
      ["$r"]=>
      string(10) "<required>"
    }
  }
  ["returnSystemValues"]=>
  bool(true)
  ["newLine"]=>
  int(10)
  ["maxContainerDepth"]=>
  int(10)
  ["maxAnnotations"]=>
  int(10)
  ["maxAnnotationBuffered"]=>
  int(512)
  ["symbolThreshold"]=>
  int(16384)
  ["userValueThreshold"]=>
  int(16384)
  ["chunkThreshold"]=>
  int(16384)
  ["allocationPageSize"]=>
  int(65536)
  ["skipCharacterValidation"]=>
  bool(true)
}
DONE
