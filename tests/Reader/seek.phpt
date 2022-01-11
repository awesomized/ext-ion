--TEST--
ion\Reader/seek
--EXTENSIONS--
ion
--FILE--
TEST
<?php
$r = new ion\Reader\Buffer\Reader("{val:123}");
$r->seek(5,1);
$r->next();
echo $r->getType()->name, "\n";
echo $r->readInt(), "\n";
?>
DONE
--EXPECT--
TEST
Int
123
DONE
