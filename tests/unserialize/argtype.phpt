--TEST--
ion\unserialize/argtype
--EXTENSIONS--
ion
--FILE--
TEST
<?php
$a=[];
foreach ([&$a,  $a, (object) $a] as $s) {
	try { var_dump(ion\unserialize($s)); }
	catch (Throwable $e) { printf("caught %s: %s\n", get_class($e), $e->getMessage()); }
}
?>
DONE
--EXPECT--
TEST
caught InvalidArgumentException: Invalid source to unserialize: expected string or resource, got array
caught InvalidArgumentException: Invalid source to unserialize: expected string or resource, got array
caught InvalidArgumentException: Invalid source to unserialize: expected string or resource, got stdClass
DONE
