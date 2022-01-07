--TEST--
ion\serialize/resource
--EXTENSIONS--
ion
--FILE--
TEST
<?php
try {
	ion\serialize(STDOUT);
} catch (Throwable $e) {
	printf("caught %s: %s\n", get_class($e), $e->getMessage());
}
?>
DONE
--EXPECTF--
TEST
caught InvalidArgumentException: Failed to serialize value of type resource
DONE
