--TEST--
ion\Serializer\PHP
--EXTENSIONS--
ion
--FILE--
TEST
<?php
$o1 = ion\serialize(["foo", ["p" => 1]]);
$o2 = ion\serialize(["foo", ["p" => 1]], $s1 = new ion\Serializer\Serializer);
if ($o1 !== $o2) {
	var_dump($o1, $o2);
}
var_dump($s1);
?>
DONE
--EXPECTF--
TEST
object(ion\Serializer\Serializer)#%d (3) {
  ["multiSequence"]=>
  bool(false)
  ["callMagicSerialize"]=>
  bool(true)
  ["callCustomSerialize"]=>
  NULL
}
DONE

