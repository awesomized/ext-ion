--TEST--
ion\Symbol\Table\Local
--EXTENSIONS--
ion
--FILE--
TEST
<?php

$w = new ion\Writer\Buffer\Writer($buf,
	new ion\Writer\Options(outputBinary: true));

$w->writeSymbol("local1");
$w->writeSymbol("local1");
$w->writeSymbol("local2");
$w->writeSymbol("local2");

$w->finish();

foreach (str_split($buf, 8) as $line) {
	printf("%-26s", chunk_split(bin2hex($line), 2, " "));
	foreach (str_split($line) as $byte) {
		echo ctype_print($byte) ? $byte : ".";
	}
	echo "\n";
}
echo "\n";

$u = new ion\Unserializer\PHP(multiSequence: true);
var_dump($u->unserialize($buf));

?>
DONE
--EXPECTF--
TEST
e0 01 00 ea ee 95 81 83   ........
de 91 87 be 8e 86 6c 6f   ......lo
63 61 6c 31 86 6c 6f 63   cal1.loc
61 6c 32 71 0a 71 0a 71   al2q.q.q
0b 71 0b                  .q.

array(4) {
  [0]=>
  object(ion\Symbol)#%d (3) {
    ["value"]=>
    string(6) "local1"
    ["sid"]=>
    int(10)
    ["importLocation"]=>
    NULL
  }
  [1]=>
  object(ion\Symbol)#%d (3) {
    ["value"]=>
    string(6) "local1"
    ["sid"]=>
    int(10)
    ["importLocation"]=>
    NULL
  }
  [2]=>
  object(ion\Symbol)#%d (3) {
    ["value"]=>
    string(6) "local2"
    ["sid"]=>
    int(11)
    ["importLocation"]=>
    NULL
  }
  [3]=>
  object(ion\Symbol)#%d (3) {
    ["value"]=>
    string(6) "local2"
    ["sid"]=>
    int(11)
    ["importLocation"]=>
    NULL
  }
}
DONE
