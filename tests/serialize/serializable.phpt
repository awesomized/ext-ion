--TEST--
ion\serialize/serializable
--EXTENSIONS--
ion
--FILE--
TEST
<?php
class test implements Serializable {
	protected $data;
	function serialize() : string {
		return "foobar";
	}
	function unserialize(string $data) : void {
		$this->data = $data;
	}
}
$t = new test;
$s = ion\serialize($t);
echo $s, "\n";
$c = ion\unserialize($s);
var_dump($c);

class recursive implements Serializable {
	private $id;
	function __construct(
		protected $r
	) {
	}
	function serialize() : string {
		if ($this->r) {
			return "node:" . ion\serialize($this->r);
		} else {
			return "leaf";
		}
	}
	function unserialize(string $data) : void {
		if ($data === "leaf") {
			$this->id = $data;
		} else {
			$this->id = substr($data, 0, 4);
			$this->r = ion\unserialize(substr($data, 5));
		}
	}
}
$tree = new recursive(new recursive(null));
var_dump($tree);
$s = ion\serialize($tree);
echo $s,"\n";
var_dump(ion\unserialize($s));
?>
DONE
--EXPECTF--
TEST

Deprecated: test implements the Serializable interface, which is deprecated. Implement __serialize() and __unserialize() instead (or in addition, if support for old PHP versions is necessary) in %sserialize/serializable.php on line %d
PHP::S::test::"foobar"
object(test)#5 (1) {
  ["data":protected]=>
  string(6) "foobar"
}

Deprecated: recursive implements the Serializable interface, which is deprecated. Implement __serialize() and __unserialize() instead (or in addition, if support for old PHP versions is necessary) in %sserialize/serializable.php on line %d
object(recursive)#%d (2) {
  ["id":"recursive":private]=>
  NULL
  ["r":protected]=>
  object(recursive)#%d (2) {
    ["id":"recursive":private]=>
    NULL
    ["r":protected]=>
    NULL
  }
}
PHP::S::recursive::"node:S::recursive::\"leaf\""
object(recursive)#%d (2) {
  ["id":"recursive":private]=>
  string(4) "node"
  ["r":protected]=>
  object(recursive)#%d (2) {
    ["id":"recursive":private]=>
    string(4) "leaf"
    ["r":protected]=>
    NULL
  }
}
DONE
