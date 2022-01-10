--TEST--
ion\unserialize/sid
--EXTENSIONS--
ion
--FILE--
TEST
<?php
$ION = <<<'ION'
$ion_symbol_table::{
	imports: [
		{name: "st", version: 1, max_id: 90}
	],
	symbols:["foo"]
}
[$33, {$99: $100}]
ION;
var_dump(ion\unserialize($ION));
?>
DONE
--EXPECTF--
TEST
array(2) {
  [0]=>
  object(ion\Symbol)#%d (3) {
    ["value"]=>
    string(0) ""
    ["sid"]=>
    int(33)
    ["importLocation"]=>
    object(ion\Symbol\ImportLocation)#%d (2) {
      ["name"]=>
      string(2) "st"
      ["location"]=>
      int(24)
    }
  }
  [1]=>
  array(1) {
    ["$99"]=>
    object(ion\Symbol)#%d (3) {
      ["value"]=>
      string(3) "foo"
      ["sid"]=>
      int(100)
      ["importLocation"]=>
      NULL
    }
  }
}
DONE
