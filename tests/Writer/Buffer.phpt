--TEST--
ion\Writer\Buffer
--EXTENSIONS--
ion
--FILE--
TEST
<?php

$w = new ion\Writer\Buffer\Writer;
for ($i = 0; $i < 100; ++$i)
	$w->writeTypedNull(ion\Type::Int);
$w->flush();
echo $w->getBuffer(),"\n";
$w->resetBuffer();
var_dump($w->getBuffer());
$w->writeSymbol("bar");
$w->flush();
var_dump($w->getBuffer());
$w->resetBuffer();
// realloc
for ($i = 0; $i < 100; ++$i)
	$w->writeTypedNull(ion\Type::Int);
$w->flush();
echo $w->getBuffer(),"\n";
?>
DONE
--EXPECTF--
TEST
null.int%r( null.int)*%r
string(0) ""
string(4) " bar"
 null.int%r( null.int)*%r
DONE
