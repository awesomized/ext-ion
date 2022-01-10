--TEST--
ion\serialize/timestamp
--EXTENSIONS--
ion
--FILE--
TEST
<?php
$dt = ion\unserialize("1971-02-03T04:05:06.789Z");
var_dump($dt, (string) $dt);
$ts = ion\serialize($dt);
var_dump($ts);

var_dump(ion\unserialize($ts));
?>
DONE
--EXPECTF--
TEST
object(ion\Timestamp)#%d (3) {
  ["precision"]=>
  int(247)
  ["format"]=>
  string(15) "Y-m-d\TH:i:s.vP"
  ["date"]=>
  string(26) "1971-02-03 04:05:06.789000"
}
string(29) "1971-02-03T04:05:06.789+00:00"
string(24) "1971-02-03T04:05:06.789Z"
object(ion\Timestamp)#%d (3) {
  ["precision"]=>
  int(247)
  ["format"]=>
  string(15) "Y-m-d\TH:i:s.vP"
  ["date"]=>
  string(26) "1971-02-03 04:05:06.789000"
}
DONE
