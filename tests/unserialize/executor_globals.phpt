--TEST--
ion\unserialize/executor_globals
--EXTENSIONS--
ion
--FILE--
TEST
<?php
class test_class {
	public $s;
	public $u;
}
$c = new test_class;
$c->s = new ion\Serializer\Serializer;

$c->u = new ion\Unserializer\Unserializer;
$d = $c->s->serialize($c);
$c->u->unserialize($d);
?>
DONE
--EXPECT--
TEST
DONE
