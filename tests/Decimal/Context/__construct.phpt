--TEST--
ion\Decimal\Context::__construct
--EXTENSIONS--
ion
--FILE--
TEST
<?php

use ion\Decimal\Context;

new Context(1,2,3,4,true);
try {
	new Context(1,"bar",3,4,false);
} catch (Throwable $e) {
	echo $e->getMessage(), "\n";
}
try {
	new Context(false,false,false,false,false);
} catch (Throwable $e) {
	echo $e->getMessage(), "\n";
}
try {
	new Context(1,2);
} catch (Throwable $e) {
	echo $e->getMessage(), "\n";
}
try {
	new Context("foo");
} catch (Throwable $e) {
	echo $e->getMessage(), "\n";
}
try {
	new Context;
} catch (Throwable $e) {
	echo $e->getMessage(), "\n";
}
?>
DONE
--EXPECTF--
TEST
ion\Decimal\Context::__construct(): Argument #2 ($eMax) must be of type int, string given
ion\Decimal\Context::__construct() expects exactly 5 arguments, 2 given
ion\Decimal\Context::__construct() expects exactly 5 arguments, 1 given
ion\Decimal\Context::__construct() expects exactly 5 arguments, 0 given
DONE
