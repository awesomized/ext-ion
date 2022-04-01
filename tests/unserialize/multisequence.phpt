--TEST--
ion\unserialize/multi sequence
--EXTENSIONS--
ion
--FILE--
TEST
<?php
var_dump(ion\unserialize("1 2 3", new \ion\Unserializer\Unserializer(multiSequence: true)));
?>
DONE
--EXPECT--
TEST
array(3) {
  [0]=>
  int(1)
  [1]=>
  int(2)
  [2]=>
  int(3)
}
DONE
