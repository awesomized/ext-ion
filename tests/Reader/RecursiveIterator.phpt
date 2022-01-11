--TEST--
ion\Reader/RecursiveIterator
--EXTENSIONS--
ion
--FILE--
TEST
<?php

foreach (new RecursiveIteratorIterator(new ion\Reader\Buffer\Reader("[1,2,3,[4,5],6]")) as $r) {
	echo $r->getDepth(), ":", $r->getType()->name, "\n";
}
?>
DONE
--EXPECT--
TEST
1:Int
1:Int
1:Int
2:Int
2:Int
1:Int
DONE
