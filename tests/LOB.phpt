--TEST--
ion\LOB
--EXTENSIONS--
ion
--FILE--
TEST
<?php
$l = new ion\LOB("foobar");
echo ion\serialize($l), "\n";
$l = new ion\LOB("barfuz", ion\Type::CLob);
echo ion\serialize($l), "\n";
$l = new ion\LOB("gooza", ion\Type::BLob);
echo ion\serialize($l), "\n";
var_dump(ion\unserialize(ion\serialize(clone new ion\LOB("ü"))));
?>
DONE
--EXPECTF--
TEST
{{"foobar"}}
{{"barfuz"}}
{{Z29vemE=}}
string(2) "ü"
DONE
