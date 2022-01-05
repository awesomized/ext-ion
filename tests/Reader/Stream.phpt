--TEST--
ion\Reader\Stream
--EXTENSIONS--
ion
--FILE--
TEST
<?php
$s = fopen("php://memory", "r+");
var_dump(fwrite($s, "123d0"));
rewind($s);
$r = new ion\Reader\Stream\Reader($s);
$r->next();
var_dump($r->readDecimal());
?>
DONE
--EXPECTF--
TEST
int(5)
object(ion\Decimal)#2 (2) {
  ["number"]=>
  int(123)
  ["context"]=>
  object(ion\Decimal\Context)#3 (5) {
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
