--TEST--
ion\serialize/custom
--EXTENSIONS--
ion
--FILE--
TEST
<?php
class custom {
	private $priv;
	protected $prot;
	public $pub;

	function serialize() : array {
		return [
			"priv" => 1,
			"prot" => 2,
			"pub" => 3
		];
	}

	function unserialize(array $data) : void {
		foreach ($data as $k => $v) {
			$this->$k = $v;
		}
	}
}
$s = ion\serialize(new custom, new ion\Serializer\Serializer(callCustomSerialize: "serialize"));
echo $s,"\n";
var_dump(ion\unserialize($s, new ion\Unserializer\Unserializer(callCustomUnserialize: "unserialize")));
?>
DONE
--EXPECTF--
TEST
C::custom::{priv:1,prot:2,pub:3}
object(custom)#%d (3) {
  ["priv":"custom":private]=>
  int(1)
  ["prot":protected]=>
  int(2)
  ["pub"]=>
  int(3)
}
DONE
