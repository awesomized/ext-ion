--TEST--
ion\Decimal::toString
--EXTENSIONS--
ion
--FILE--
TEST
<?php
use ion\Decimal;

var_dump((new Decimal(1))->toString());
var_dump((new Decimal(-1))->toString());
var_dump((new Decimal(123456789))->toString());
var_dump((new Decimal(-123456789))->toString());
try {
	var_dump((new Decimal("1.23"))->toString());
} catch (Throwable) {
	echo "caught 1.23\n";
}
try {
	var_dump((new Decimal("-1.23"))->toString());
} catch (Throwable) {
	echo "caught -1.23\n";
}
?>
DONE
--EXPECT--
TEST
string(3) "1d0"
string(4) "-1d0"
string(11) "123456789d0"
string(12) "-123456789d0"
string(4) "1.23"
string(5) "-1.23"
DONE
