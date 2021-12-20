--TEST--
ion\serialize/popo
--EXTENSIONS--
ion
--FILE--
TEST
<?php
class popo {
	private $priv;
	protected $prot;
	public $pub;

	function __construct() {
		$this->priv = 1;
		$this->prot = 2;
		$this->pub = 3;
	}

}
$s = ion\serialize(new popo);
echo $s,"\n";
var_dump(ion\unserialize($s));
?>
DONE
--EXPECTF--
TEST
c::popo::{priv:p::popo::1,prot:p::'*'::2,pub:3}
object(popo)#%d (3) {
  ["priv":"popo":private]=>
  int(1)
  ["prot":protected]=>
  int(2)
  ["pub"]=>
  int(3)
}
DONE
