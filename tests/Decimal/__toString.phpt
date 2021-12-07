--TEST--
ion\Decimal::__toString
--EXTENSIONS--
ion
--FILE--
TEST
<?php
use ion\Decimal;
echo new Decimal(1), "\n";
echo new Decimal("2"), "\n";
echo new Decimal("1.2"), "\n";
echo new Decimal(-1), "\n";
echo new Decimal("-2"), "\n";
echo new Decimal("-1.2"), "\n";
?>
DONE
--EXPECT--
TEST
1d0
2d0
1.2
-1d0
-2d0
-1.2
DONE
