--TEST--
ion\unserialize/multifield
--EXTENSIONS--
ion
--FILE--
TEST
<?php
var_dump(ion\unserialize("{a: 1, a: 2, a: 3, b: 4}"));
?>
DONE
--EXPECT--
TEST
array(2) {
  ["a"]=>
  array(3) {
    [0]=>
    int(1)
    [1]=>
    int(2)
    [2]=>
    int(3)
  }
  ["b"]=>
  int(4)
}
DONE
