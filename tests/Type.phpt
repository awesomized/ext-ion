--TEST--
ion\Type
--EXTENSIONS--
ion
--FILE--
TEST
<?php
var_dump(ion\Type::Null);
var_dump(ion\Type::Decimal->name);
var_dump(ion\Type::EOF->value);
?>
DONE
--EXPECT--
TEST
enum(ion\Type::Null)
string(7) "Decimal"
int(-256)
DONE
