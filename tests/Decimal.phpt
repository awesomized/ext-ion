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
  object(ion\Decimal\Context)#%d (5) {
    ["digits"]=>
    int(999999999)
    ["eMax"]=>
    int(999999999)
    ["eMin"]=>
    int(-999999999)
    ["round"]=>
    int(3)
    ["clamp"]=>
    bool(false)
  }
}
object(ion\Decimal)#%d (2) {
  ["number"]=>
  string(4) "1.23"
  ["context"]=>
  object(ion\Decimal\Context)#%d (5) {
    ["digits"]=>
    int(999999999)
    ["eMax"]=>
    int(999999999)
    ["eMin"]=>
    int(-999999999)
    ["round"]=>
    int(3)
    ["clamp"]=>
    bool(false)
  }
}
DONE
