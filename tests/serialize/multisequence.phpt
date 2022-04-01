--TEST--
ion\serialize/multi sequence
--EXTENSIONS--
ion
--FILE--
TEST
<?php
echo ion\serialize([1,2,3], new \ion\Serializer\Serializer(multiSequence: true)), "\n";
?>
DONE
--EXPECT--
TEST
1 2 3
DONE
