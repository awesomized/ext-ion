--TEST--
ion\serialize/backref
--EXTENSIONS--
ion
--FILE--
TEST
<?php
$a = "a";
$b = (object) [];
$c = [1,2,3];
$d = [$a, $a, $b, $b, $c, $c];
$e = [&$e];
$s = ion\serialize($e);
echo $s,"\n";
$x = ion\unserialize($s);
var_dump($x);

$f = [$e, $d, $d, $a, $b, $c];
$s = ion\serialize($f);
echo $s,"\n";
$x = ion\unserialize($s);
debug_zval_dump($x);
?>
DONE
--EXPECTF--
TEST
PHP::[R::r::0]
array(1) {
  [0]=>
  *RECURSION*
}
PHP::[[R::r::1],["a",r::4,o::{},r::5,[1,2,3],r::6],r::3,r::4,r::5,r::6]
array(6) refcount(2){
  [0]=>
  array(1) refcount(2){
    [0]=>
    reference refcount(1) {
      *RECURSION*
    }
  }
  [1]=>
  array(6) refcount(2){
    [0]=>
    string(1) "a" refcount(3)
    [1]=>
    string(1) "a" refcount(3)
    [2]=>
    object(stdClass)#%d (0) refcount(3){
    }
    [3]=>
    object(stdClass)#%d (0) refcount(3){
    }
    [4]=>
    array(3) refcount(3){
      [0]=>
      int(1)
      [1]=>
      int(2)
      [2]=>
      int(3)
    }
    [5]=>
    array(3) refcount(3){
      [0]=>
      int(1)
      [1]=>
      int(2)
      [2]=>
      int(3)
    }
  }
  [2]=>
  array(6) refcount(2){
    [0]=>
    string(1) "a" refcount(3)
    [1]=>
    string(1) "a" refcount(3)
    [2]=>
    object(stdClass)#%d (0) refcount(3){
    }
    [3]=>
    object(stdClass)#%d (0) refcount(3){
    }
    [4]=>
    array(3) refcount(3){
      [0]=>
      int(1)
      [1]=>
      int(2)
      [2]=>
      int(3)
    }
    [5]=>
    array(3) refcount(3){
      [0]=>
      int(1)
      [1]=>
      int(2)
      [2]=>
      int(3)
    }
  }
  [3]=>
  string(1) "a" refcount(3)
  [4]=>
  object(stdClass)#%d (0) refcount(3){
  }
  [5]=>
  array(3) refcount(3){
    [0]=>
    int(1)
    [1]=>
    int(2)
    [2]=>
    int(3)
  }
}
DONE
