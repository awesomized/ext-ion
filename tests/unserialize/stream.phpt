--TEST--
ion\unserialize/stream
--EXTENSIONS--
ion
--FILE--
TEST
<?php
$s = fopen("php://temp", "w+");
fwrite($s, "123");
rewind($s);
var_dump(ion\unserialize($s));
?>
DONE
--EXPECTF--
TEST
int(123)
DONE
