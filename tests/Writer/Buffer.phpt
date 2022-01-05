--TEST--
ion\Writer\Buffer
--EXTENSIONS--
ion
--FILE--
TEST
<?php

$w = new ion\Writer\Buffer\Writer($buf);
for ($i = 0; $i < 100; ++$i) $w->writeTypedNull(ion\Type::Int);
var_dump($buf === $w->getBuffer());
$w->finish();
echo $buf;
?>

DONE
--EXPECTF--
TEST
bool(true)
null.int%r( null.int)*%r
DONE
