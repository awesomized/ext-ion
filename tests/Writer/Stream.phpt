--TEST--
ion\Writer\Stream
--EXTENSIONS--
ion
--FILE--
TEST
<?php

$w = new ion\Writer\Stream\Writer(STDOUT);
$w->writeTypedNull(ion\Type::Int);
var_dump(STDOUT === $w->getStream());
$w->finish();

?>

DONE
--EXPECTF--
TEST
bool(true)
null.int
DONE
