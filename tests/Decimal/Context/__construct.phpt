--TEST--
ion\Decimal\Context::__construct
--EXTENSIONS--
ion
--FILE--
TEST
<?php
use ion\Decimal\Context;

new Context;
new Context(32);
try {
	new Context(123);
} catch (Throwable $e) {
	echo $e->getMessage(), "\n";
}
try {
	new Context("123");
} catch (Throwable $e) {
	echo $e->getMessage(), "\n";
}
try {
	new Context("foo");
} catch (Throwable $e) {
	echo $e->getMessage(), "\n";
}
?>
DONE
--EXPECTF--
TEST
Decimal context only allows 32, 64 or 128 bits
Decimal context only allows 32, 64 or 128 bits
ion\Decimal\Context::__construct(): Argument #1 ($bits) must be of type int, string given
DONE
