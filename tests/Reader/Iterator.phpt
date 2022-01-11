--TEST--
ion\Reader/Iterator
--EXTENSIONS--
ion
--FILE--
TEST
<?php

foreach (new ion\Reader\Buffer\Reader("[1,2,3,[4,5],6]") as $r) {
	if (!$r->getDepth()) $r->getChildren(); // step in once
	echo $r->getType()->name, "\n";
}
?>
DONE
--EXPECT--
TEST
List
Int
Int
Int
List
Int
DONE
