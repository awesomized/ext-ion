--TEST--
ion\serialize/timestamp
--EXTENSIONS--
ion
--FILE--
TEST
<?php
$dt = ion\unserialize("1971-02-03T04:05:06.789Z");
var_dump($dt);
$ts = ion\serialize($dt);
var_dump($ts);

var_dump(ion\unserialize($ts));
?>
DONE
--EXPECTF--
TEST
object(ion\Timestamp)#5 (3) {
  ["precision"]=>
  int(247)
  ["format"]=>
  string(1) "c"
  ["date"]=>
  string(26) "1971-02-03 04:05:06.789000"
}
string(24) "1971-02-03T04:05:06.789Z"
object(ion\Timestamp)#6 (3) {
  ["precision"]=>
  int(247)
  ["format"]=>
  string(1) "c"
  ["date"]=>
  string(26) "1971-02-03 04:05:06.789000"
}
DONE
