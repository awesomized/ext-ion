--TEST--
ion\Decimal::__construct
--EXTENSIONS--
ion
--FILE--
TEST
<?php
use ion\Decimal;

try {
	new Decimal();
} catch (Error $e) {
	echo $e->getMessage(), "\n";
}
new Decimal(1);
new Decimal("123");
new Decimal(123.123);
new Decimal("123.123");
new Decimal(1, null);
new Decimal(1, new Decimal\Context);
?>
DONE
--EXPECTF--
TEST
ion\Decimal::__construct() expects at least 1 argument, 0 given

Deprecated: Implicit conversion from float 123.123 to int loses precision in %s/Decimal/__construct.php on line %d
DONE
