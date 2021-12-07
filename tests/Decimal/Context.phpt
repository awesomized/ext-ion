--TEST--
ion\Decimal\Context
--EXTENSIONS--
ion
--FILE--
TEST
<?php
var_dump(new ion\Decimal\Context);
var_dump(new ion\Decimal\Context(32));
?>
DONE
--EXPECTF--
TEST
object(ion\Decimal\Context)#1 (1) {
  ["bits"]=>
  int(128)
}
object(ion\Decimal\Context)#1 (1) {
  ["bits"]=>
  int(32)
}
DONE
