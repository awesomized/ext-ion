--TEST--
ion\Symbol::equals
--EXTENSIONS--
ion
--FILE--
TEST
<?php
use ion\Symbol;

var_dump(new Symbol(1) == new Symbol("1"));
var_dump((new Symbol(1))->equals(new Symbol("1")));

var_dump((new Symbol(1, 123))->equals(new Symbol("1", 321)));

var_dump(new Symbol(1) == new Symbol(2));
var_dump((new Symbol(1))->equals(new Symbol(2)));

// All local symbols with unknown text are equivalent to each other (and to symbol zero).
var_dump((new Symbol(sid:123))->equals(new Symbol(sid:321)));

?>
DONE
--EXPECT--
TEST
bool(true)
bool(true)
bool(true)
bool(false)
bool(false)
bool(true)
DONE
