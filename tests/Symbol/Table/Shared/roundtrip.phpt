--TEST--
ion\Symbol\Table\Shared/roundtrip
--EXTENSIONS--
ion
--FILE--
TEST
<?php
$s = '$ion_shared_symbol_table::{name:"shared",version:1,symbols:["foo","bar","baz"]}';
$t = new ion\Symbol\Table\Shared(name: "shared", symbols: ["foo","bar","baz"]);
var_dump(
	ion\serialize(
		ion\unserialize(
			ion\serialize(
				ion\unserialize(
					ion\serialize($t)
				)
			)
		)
	)
);

var_dump(
	ion\unserialize(
		ion\serialize(
			ion\unserialize(
				ion\serialize(
					ion\unserialize($s)
				)
			)
		)
	)
);
?>
DONE
--EXPECTF--
TEST
string(79) "$ion_shared_symbol_table::{name:"shared",version:1,symbols:["foo","bar","baz"]}"
object(ion\Symbol\Table\Shared)#%d (3) {
  ["name"]=>
  string(6) "shared"
  ["version"]=>
  int(1)
  ["symbols":"ion\Symbol\Table\Shared":private]=>
  array(0) {
  }
}
DONE
