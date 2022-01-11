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
$w->finish();
var_dump($w->getBuffer());
?>
DONE
--EXPECTF--
TEST
null.int%r( null.int)*%r
string(0) ""
string(3) "bar"
DONE
