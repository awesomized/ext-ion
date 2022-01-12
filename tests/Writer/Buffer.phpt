--TEST--
ion\Writer\Buffer
--EXTENSIONS--
ion
--FILE--
TEST
<?php

$w = new ion\Writer\Buffer\Writer;
for ($i = 0; $i < 10; ++$i)
	$w->writeTypedNull(ion\Type::Int);
$w->flush();
var_dump($w->getBuffer());
$ref=$w->getBuffer();
// realloc
for ($i = 0; $i < 100; ++$i)
	$w->writeTypedNull(ion\Type::Int);
$w->flush();
var_dump($ref, $w->getBuffer());
$w->resetBuffer();
var_dump($w->getBuffer());
$w->writeSymbol("bar");
$w->flush();
var_dump($w->getBuffer());

$w->resetBuffer();
$ref=$w->getBuffer();
// realloc
for ($i = 0; $i < 100; ++$i)
	$w->writeTypedNull(ion\Type::Int);
$w->flush();
echo $ref,"----",$w->getBuffer(),"\n";
?>
DONE
--EXPECTF--
TEST
string(89) "null.int%r( null.int){9}%r"
string(89) "null.int%r( null.int){9}%r"
string(989) "null.int%r( null.int){109}%r"
string(0) ""
string(4) " bar"
---- null.int%r( null.int){99}%r
DONE
