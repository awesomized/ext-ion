--TEST--
ion\Decimal::equals
--EXTENSIONS--
ion
--FILE--
TEST
<?php
use ion\Decimal;

var_dump(new Decimal(1) == new Decimal("1"));
var_dump((new Decimal(1))->equals(new Decimal("1")));

var_dump(new Decimal(1) == new Decimal(2));
var_dump((new Decimal(1))->equals(new Decimal(2)));
?>
DONE
--EXPECT--
TEST
bool(true)
bool(true)
bool(false)
bool(false)
DONE
