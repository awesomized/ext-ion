--TEST--
ion\Symbol\ImportLocation
--EXTENSIONS--
ion
--FILE--
TEST
<?php
var_dump($iloc = new ion\Symbol\ImportLocation("table", 123));
var_dump(clone $iloc);
unset($iloc);
var_dump(clone new ion\Symbol\ImportLocation("table", 123));
?>
DONE
--EXPECTF--
TEST
object(ion\Symbol\ImportLocation)#%d (2) {
  ["name"]=>
  string(5) "table"
  ["location"]=>
  int(123)
}
object(ion\Symbol\ImportLocation)#%d (2) {
  ["name"]=>
  string(5) "table"
  ["location"]=>
  int(123)
}
object(ion\Symbol\ImportLocation)#%d (2) {
  ["name"]=>
  string(5) "table"
  ["location"]=>
  int(123)
}
DONE
