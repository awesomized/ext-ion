--TEST--
ion\Symbol\Table
--EXTENSIONS--
ion
--FILE--
TEST
<?php

echo "global\n";
var_dump(ion\Symbol\Table\System());
var_dump(ion\Symbol\Table\PHP());
var_dump(ion\Symbol\Table\PHP()->find(1));

echo "shared\n";
$shared = new ion\Symbol\Table\Shared("shared");

echo "add 3 syms\n";
var_dump(
	$shared->add("sym1"),
	$shared->add("sym2"),
	$sid3 = $shared->add($s3 = new ion\Symbol("sym3")),
);

echo "s3, sid3\n";
var_dump($s3, $sid3);

echo "find sym3, sid3\n";
var_dump($shared->find("sym3"));
var_dump($shared->find($sid3));

echo "local\n";
$local = new ion\Symbol\Table\Local;
echo "import PHP\n";
$local->import(ion\Symbol\Table\PHP());
echo "import shared\n";
$local->import($shared);

echo "find sym1, local sym1\n";
var_dump($local->find("sym1"));
var_dump($local->findLocal("sym1"));

echo "add, find, local sym4\n";
var_dump($local->add("sym4"));
var_dump($local->find("sym4"));
var_dump($local->findLocal("sym4"));
?>
DONE
--EXPECTF--
TEST
global
object(ion\Symbol\Table\Shared)#%d (3) {
  ["name"]=>
  string(4) "$ion"
  ["version"]=>
  int(1)
  ["symbols":"ion\Symbol\Table\Shared":private]=>
  array(0) {
  }
}
object(ion\Symbol\Table\Shared)#%d (3) {
  ["name"]=>
  string(3) "PHP"
  ["version"]=>
  int(1)
  ["symbols":"ion\Symbol\Table\Shared":private]=>
  array(0) {
  }
}
object(ion\Symbol)#%d (3) {
  ["value"]=>
  string(3) "PHP"
  ["sid"]=>
  int(1)
  ["importLocation"]=>
  object(ion\Symbol\ImportLocation)#%d (2) {
    ["name"]=>
    string(3) "PHP"
    ["location"]=>
    int(1)
  }
}
shared
add 3 syms
int(1)
int(2)
int(3)
s3, sid3
object(ion\Symbol)#%d (3) {
  ["value"]=>
  string(4) "sym3"
  ["sid"]=>
  int(-1)
  ["importLocation"]=>
  NULL
}
int(3)
find sym3, sid3
object(ion\Symbol)#%d (3) {
  ["value"]=>
  string(4) "sym3"
  ["sid"]=>
  int(3)
  ["importLocation"]=>
  object(ion\Symbol\ImportLocation)#%d (2) {
    ["name"]=>
    string(6) "shared"
    ["location"]=>
    int(3)
  }
}
object(ion\Symbol)#%d (3) {
  ["value"]=>
  string(4) "sym3"
  ["sid"]=>
  int(3)
  ["importLocation"]=>
  object(ion\Symbol\ImportLocation)#%d (2) {
    ["name"]=>
    string(6) "shared"
    ["location"]=>
    int(3)
  }
}
local
import PHP
import shared
find sym1, local sym1
object(ion\Symbol)#%d (3) {
  ["value"]=>
  string(4) "sym1"
  ["sid"]=>
  int(1)
  ["importLocation"]=>
  object(ion\Symbol\ImportLocation)#%d (2) {
    ["name"]=>
    string(6) "shared"
    ["location"]=>
    int(1)
  }
}
NULL
add, find, local sym4
int(23)
object(ion\Symbol)#%d (3) {
  ["value"]=>
  string(4) "sym4"
  ["sid"]=>
  int(23)
  ["importLocation"]=>
  NULL
}
object(ion\Symbol)#%d (3) {
  ["value"]=>
  string(4) "sym4"
  ["sid"]=>
  int(23)
  ["importLocation"]=>
  NULL
}
DONE
