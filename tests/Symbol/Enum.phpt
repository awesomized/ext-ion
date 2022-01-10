--TEST--
ion\Symbol\Enum
--EXTENSIONS--
ion
--FILE--
TEST
<?php
$t = ion\Symbol\Table\PHP::PHP;
var_dump($t instanceof ion\Symbol\Enum);
var_dump($t->toSymbol(), $t->toSID(), $t->toString());
?>
DONE
--EXPECTF--
TEST
bool(true)
object(ion\Symbol)#2 (3) {
  ["value"]=>
  string(3) "PHP"
  ["sid"]=>
  int(10)
  ["importLocation"]=>
  NULL
}
int(10)
string(3) "PHP"
DONE
