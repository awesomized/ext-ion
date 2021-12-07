--TEST--
ion\Decimal::toInt
--EXTENSIONS--
ion
--FILE--
TEST
<?php
use ion\Decimal;

var_dump((new Decimal(1))->toInt());
var_dump((new Decimal(-1))->toInt());
var_dump((new Decimal(123456789))->toInt());
var_dump((new Decimal(-123456789))->toInt());
try {
	var_dump((new Decimal("1.23"))->toInt());
} catch (Throwable) {
	echo "caught 1.23\n";
}
try {
	var_dump((new Decimal("-1.23"))->toInt());
} catch (Throwable) {
	echo "caught -1.23\n";
}
?>
DONE
--EXPECT--
TEST
int(1)
int(-1)
int(123456789)
int(-123456789)
caught 1.23
caught -1.23
DONE
