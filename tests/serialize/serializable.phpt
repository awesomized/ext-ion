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

echo "\n";

$t = new test;
$s = ion\serialize([$t, $t]);
echo $s, "\n";
$c = ion\unserialize($s);
debug_zval_dump($c);
$tree = new recursive(new recursive(null));
var_dump($tree);
$s = ion\serialize($tree);
echo $s,"\n";
debug_zval_dump(ion\unserialize($s));
?>
DONE
--EXPECTF--
TEST

Deprecated: test implements the Serializable interface, which is deprecated. Implement __serialize() and __unserialize() instead (or in addition, if support for old PHP versions is necessary) in %sserialize/serializable.php on line %d

Deprecated: recursive implements the Serializable interface, which is deprecated. Implement __serialize() and __unserialize() instead (or in addition, if support for old PHP versions is necessary) in %sserialize/serializable.php on line %d

[S::test::"foobar",r::1]
array(2) refcount(2){
  [0]=>
  object(test)#%d (1) refcount(2){
    ["data":protected]=>
    string(6) "foobar" refcount(1)
  }
  [1]=>
  object(test)#%d (1) refcount(2){
    ["data":protected]=>
    string(6) "foobar" refcount(1)
  }
}
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
S::recursive::"node:S::recursive::\"leaf\""
object(recursive)#%d (2) refcount(1){
  ["id":"recursive":private]=>
  string(4) "node" refcount(1)
  ["r":protected]=>
  object(recursive)#%d (2) refcount(1){
    ["id":"recursive":private]=>
    string(4) "leaf" refcount(1)
    ["r":protected]=>
    NULL
  }
}
DONE
