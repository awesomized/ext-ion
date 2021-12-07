--TEST--
ion\Decimal::isInt
--EXTENSIONS--
ion
--FILE--
TEST
<?php
use ion\Decimal;

var_dump((new Decimal(1))->isInt());
var_dump((new Decimal(-1))->isInt());
var_dump((new Decimal(123456789))->isInt());
var_dump((new Decimal(-123456789))->isInt());
var_dump((new Decimal("1.23"))->isInt());
var_dump((new Decimal("-1.23"))->isInt());
?>
DONE
--EXPECT--
TEST
bool(true)
bool(true)
bool(true)
bool(true)
bool(false)
bool(false)
DONE
