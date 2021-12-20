--TEST--
ion\serialize/basic
--EXTENSIONS--
ion
--FILE--
TEST
<?php
$data = [
	"null" => null,
	"bool" => true,
	"int" => 123,
	"double" => 123.123,
	"string" => "foobar",
	"object" => (object) ["prop" => "data"],
];
echo $s = ion\serialize($data), "\n";
var_dump($data == ion\unserialize($s));
?>
DONE
--EXPECTF--
TEST
{'null':null,bool:true,int:123,double:12%f,string:"foobar",object:o::{prop:"data"}}
bool(true)
DONE
