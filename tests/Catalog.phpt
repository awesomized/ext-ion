--TEST--
ion\Catalog
--EXTENSIONS--
ion
--FILE--
TEST
<?php

$c = new ion\Catalog;
var_dump(count($c));
$c->add(ion\Symbol\Table\PHP());
var_dump(count($c));
$c->add(new ion\Symbol\Table\Shared("shared", 1, ["foo", "bar", "baz"]));
var_dump(count($c));
$c->add(new ion\Symbol\Table\Shared("shared", 2, ["foo", "bar", "baz", "new"]));
var_dump(count($c));


var_dump($c);
var_dump($c->find("shared", 1));
var_dump($c->findBest("shared"));

$c->remove("shared");
var_dump(count($c));

var_dump(clone $c);
?>
DONE
--EXPECTF--
TEST
int(0)
int(1)
int(2)
int(3)
object(ion\Catalog)#%d (1) {
  ["symbolTables":"ion\Catalog":private]=>
  array(6) {
    [%d]=>
    object(ion\Symbol\Table\Shared)#%d (3) {
      ["name"]=>
      string(3) "PHP"
      ["version"]=>
      int(1)
      ["symbols":"ion\Symbol\Table\Shared":private]=>
      array(0) {
      }
    }
    ["PHP:1"]=>
    object(ion\Symbol\Table\Shared)#%d (3) {
      ["name"]=>
      string(3) "PHP"
      ["version"]=>
      int(1)
      ["symbols":"ion\Symbol\Table\Shared":private]=>
      array(0) {
      }
    }
    [%d]=>
    object(ion\Symbol\Table\Shared)#%d (3) {
      ["name"]=>
      string(6) "shared"
      ["version"]=>
      int(1)
      ["symbols":"ion\Symbol\Table\Shared":private]=>
      array(0) {
      }
    }
    ["shared:1"]=>
    object(ion\Symbol\Table\Shared)#%d (3) {
      ["name"]=>
      string(6) "shared"
      ["version"]=>
      int(1)
      ["symbols":"ion\Symbol\Table\Shared":private]=>
      array(0) {
      }
    }
    [%d]=>
    object(ion\Symbol\Table\Shared)#%d (3) {
      ["name"]=>
      string(6) "shared"
      ["version"]=>
      int(2)
      ["symbols":"ion\Symbol\Table\Shared":private]=>
      array(0) {
      }
    }
    ["shared:2"]=>
    object(ion\Symbol\Table\Shared)#%d (3) {
      ["name"]=>
      string(6) "shared"
      ["version"]=>
      int(2)
      ["symbols":"ion\Symbol\Table\Shared":private]=>
      array(0) {
      }
    }
  }
}
object(ion\Symbol\Table\Shared)#%d (3) {
  ["name"]=>
  string(6) "shared"
  ["version"]=>
  int(1)
  ["symbols":"ion\Symbol\Table\Shared":private]=>
  array(0) {
  }
}
object(ion\Symbol\Table\Shared)#%d (3) {
  ["name"]=>
  string(6) "shared"
  ["version"]=>
  int(2)
  ["symbols":"ion\Symbol\Table\Shared":private]=>
  array(0) {
  }
}
int(1)
object(ion\Catalog)#%d (1) {
  ["symbolTables":"ion\Catalog":private]=>
  array(0) {
  }
}
DONE
