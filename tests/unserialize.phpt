--TEST--
ion\Unserializer\Unserializer
--EXTENSIONS--
ion
--FILE--
TEST
<?php
$o1 = ion\unserialize("[foo,{p:1}]");
$o2 = ion\unserialize("[foo,{p:1}]", $u1 = new ion\Unserializer\Unserializer);
if ($o1 != $o2) {
	var_dump($o1, $o2);
}
var_dump($u1);
?>
DONE
--EXPECTF--
TEST
object(ion\Unserializer\Unserializer)#%d (3) {
  ["multiSequence"]=>
  bool(false)
  ["callMagicUnserialize"]=>
  bool(true)
  ["callCustomUnserialize"]=>
  NULL
}
DONE
