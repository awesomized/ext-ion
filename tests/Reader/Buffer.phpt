--TEST--
ion\Reader\Buffer
--EXTENSIONS--
ion
--FILE--
TEST
<?php
$s = "123d0";
$r = new ion\Reader\Buffer\Reader($s);
$r->next();
var_dump($r->readDecimal());
var_dump($s === $r->getBuffer());
?>
DONE
--EXPECTF--
TEST
object(ion\Decimal)#%d (2) {
  ["number"]=>
  int(123)
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
bool(true)
DONE
