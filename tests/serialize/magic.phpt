--TEST--
ion\serialize/magic
--EXTENSIONS--
ion
--FILE--
TEST
<?php
class magic {
	private $priv;
	protected $prot;
	public $pub;

	function __serialize() : array {
		return [
			"priv" => 1,
			"prot" => 2,
			"pub" => 3
		];
	}

	function __unserialize(array $data) : void {
		foreach ($data as $k => $v) {
			$this->$k = $v;
		}
	}
}
$s = ion\serialize(new magic);
echo $s,"\n";
var_dump(ion\unserialize($s));
?>
DONE
--EXPECTF--
TEST
PHP::O::magic::{priv:1,prot:2,pub:3}
object(magic)#%d (3) {
  ["priv":"magic":private]=>
  int(1)
  ["prot":protected]=>
  int(2)
  ["pub"]=>
  int(3)
}
DONE
