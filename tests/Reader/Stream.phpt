--TEST--
ion\Reader\Stream
--EXTENSIONS--
ion
--FILE--
TEST
<?php
$s = fopen("php://memory", "r+");
fwrite($s, "123d0 567 890");
rewind($s);
$r = new ion\Reader\Stream\Reader($s);
$r->next();
var_dump($r->readDecimal());
var_dump($s === $r->getStream());

fseek($s, 2);
$r->resetStream($s);
var_dump($s === $r->getStream());
$r->next();
echo $r->getType()->name, "\n";
var_dump($r->readDecimal());

fseek($s, 6);
$r->resetStreamWithLength($s, 3);
var_dump($s === $r->getStream());
$r->next();
echo $r->getType()->name, "\n";
var_dump($r->readInt());

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
bool(true)
Decimal
object(ion\Decimal)#%d (2) {
  ["number"]=>
  int(3)
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
Int
int(567)
DONE
