--TEST--
ion\Symbol
--EXTENSIONS--
ion
--FILE--
TEST
<?php
use ion\Symbol;

try {
	var_dump(new Symbol);
} catch (Throwable) {
	echo "caught empty\n";
}

var_dump($s=new Symbol, (string)$s, $s->sid);
var_dump($s=new Symbol("s"), (string)$s, $s->sid);
var_dump($s=new Symbol("s", 1), (string)$s, $s->sid);
var_dump($s=new Symbol(1, 2), (string)$s, $s->sid);

?>
DONE
--EXPECTF--
TEST
object(ion\Symbol)#%d (3) {
  ["value"]=>
  NULL
  ["sid"]=>
  int(-1)
  ["importLocation"]=>
  NULL
}
object(ion\Symbol)#%d (3) {
  ["value"]=>
  NULL
  ["sid"]=>
  int(-1)
  ["importLocation"]=>
  NULL
}
string(0) ""
int(-1)
object(ion\Symbol)#%d (3) {
  ["value"]=>
  string(1) "s"
  ["sid"]=>
  int(-1)
  ["importLocation"]=>
  NULL
}
string(1) "s"
int(-1)
object(ion\Symbol)#%d (3) {
  ["value"]=>
  string(1) "s"
  ["sid"]=>
  int(1)
  ["importLocation"]=>
  NULL
}
string(1) "s"
int(1)
object(ion\Symbol)#%d (3) {
  ["value"]=>
  string(1) "1"
  ["sid"]=>
  int(2)
  ["importLocation"]=>
  NULL
}
string(1) "1"
int(2)
DONE
