--TEST--
ion\Decimal
--EXTENSIONS--
ion
--FILE--
TEST
<?php
var_dump(new ion\Decimal(1));
var_dump(new ion\Decimal("1.23"));
?>
DONE
--EXPECTF--
TEST
object(ion\Decimal)#%d (2) {
  ["number"]=>
  int(1)
  ["context"]=>
  object(ion\Decimal\Context)#%d (1) {
    ["bits"]=>
    int(128)
  }
}
object(ion\Decimal)#%d (2) {
  ["number"]=>
  string(4) "1.23"
  ["context"]=>
  object(ion\Decimal\Context)#%d (1) {
    ["bits"]=>
    int(128)
  }
}
DONE
