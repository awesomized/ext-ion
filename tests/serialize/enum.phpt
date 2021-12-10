--TEST--
ion\serialize/enum
--EXTENSIONS--
ion
--FILE--
TEST
<?php
enum e {
	case a;
	case b;
}
$s = ion\serialize(e::a);
echo $s,"\n";
var_dump(ion\unserialize($s));

enum i : int {
	case a = 123;
	case b = 456;
}
$s = ion\serialize(i::b);
echo $s,"\n";
var_dump(ion\unserialize($s));

enum s : string {
	case a = "abc";
	case b = "def";
}
$s = ion\serialize(s::a);
echo $s,"\n";
var_dump(ion\unserialize($s));
?>
DONE
--EXPECTF--
TEST
PHP::E::e::a
enum(e::a)
PHP::E::i::b
enum(i::b)
PHP::E::s::a
enum(s::a)
DONE
