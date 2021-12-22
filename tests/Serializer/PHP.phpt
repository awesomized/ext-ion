--TEST--
ion\Serializer\PHP
--EXTENSIONS--
ion
--FILE--
TEST
<?php
$o1 = ion\serialize(["foo", ["p" => 1]]);
$o2 = ion\serialize(["foo", ["p" => 1]], $s1 = new ion\Serializer\PHP);
$o3 = ion\serialize(["foo", ["p" => 1]], $s2 = new ion\Serializer\PHP(new ion\Writer\Options));
if ($o1 !== $o2) {
	var_dump($o1, $o2);
}
var_dump($s1);
if ($s1 != $s2) {
	var_dump($s2);
}
?>
DONE
--EXPECTF--
TEST
object(ion\Serializer\PHP)#%d (4) {
  ["writerOptions"]=>
  object(ion\Writer\Options)#%d (15) {
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
    ["smallContainersInline"]=>
    bool(true)
    ["suppressSystemValues"]=>
    bool(false)
    ["flushEveryValue"]=>
    bool(false)
    ["maxContainerDepth"]=>
    int(10)
    ["maxAnnotations"]=>
    int(10)
    ["tempBufferSize"]=>
    int(16384)
    ["allocationPageSize"]=>
    int(65536)
  }
  ["multiSequence"]=>
  bool(false)
  ["callMagicSerialize"]=>
  bool(true)
  ["callCustomSerialize"]=>
  NULL
}
DONE

