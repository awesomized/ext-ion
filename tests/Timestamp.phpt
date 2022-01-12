--TEST--
ion\Timestamp
--EXTENSIONS--
ion
--INI--
date.timezone=CET
--FILE--
TEST
<?php
use ion\Timestamp;

try {
	var_dump(new Timestamp);
} catch (Throwable) {
	echo "caught empty\n";
}
$full = "2021-12-07T14:08:51.123456+00:00";
var_dump($t=new Timestamp(Timestamp\Precision::Day, datetime:$full),(string)$t);
var_dump($t=new Timestamp(Timestamp\Precision::Day->value, datetime:$full),(string)$t);
var_dump($t=new Timestamp(Timestamp\Precision::Min, datetime:"2020-10-01"),(string)$t);
$t->setTimezone(new DateTimeZone("Europe/Helsinki"));
var_dump((string) $t);
var_dump($t=new Timestamp(Timestamp\Precision::Day, "!Y-m", "2000-10"),(string)$t);
var_dump($t=new Timestamp(Timestamp\Precision::MinTZ, Timestamp\Format::MinTZ, "2000-10-20T11:11CET"),(string)$t);
var_dump(ion\unserialize(ion\serialize(clone new ion\Timestamp(ion\Timestamp\Precision::Sec, DateTime::RFC3339, "1971-02-03T04:05:06Z"))));
?>
DONE
--EXPECTF--
TEST
caught empty
object(ion\Timestamp)#%d (5) {
  ["precision"]=>
  int(7)
  ["format"]=>
  string(7) "Y-m-d\T"
  ["date"]=>
  string(26) "2021-12-07 14:08:51.123456"
  ["timezone_type"]=>
  int(1)
  ["timezone"]=>
  string(6) "+00:00"
}
string(11) "2021-12-07T"
object(ion\Timestamp)#%d (5) {
  ["precision"]=>
  int(7)
  ["format"]=>
  string(7) "Y-m-d\T"
  ["date"]=>
  string(26) "2021-12-07 14:08:51.123456"
  ["timezone_type"]=>
  int(1)
  ["timezone"]=>
  string(6) "+00:00"
}
string(11) "2021-12-07T"
object(ion\Timestamp)#%d (5) {
  ["precision"]=>
  int(23)
  ["format"]=>
  string(10) "Y-m-d\TH:i"
  ["date"]=>
  string(26) "2020-10-01 00:00:00.000000"
  ["timezone_type"]=>
  int(3)
  ["timezone"]=>
  string(3) "CET"
}
string(16) "2020-10-01T00:00"
string(16) "2020-10-01T01:00"
object(ion\Timestamp)#%d (5) {
  ["precision"]=>
  int(7)
  ["format"]=>
  string(7) "Y-m-d\T"
  ["date"]=>
  string(26) "2000-10-01 00:00:00.000000"
  ["timezone_type"]=>
  int(3)
  ["timezone"]=>
  string(3) "CET"
}
string(11) "2000-10-01T"
object(ion\Timestamp)#%d (5) {
  ["precision"]=>
  int(151)
  ["format"]=>
  string(11) "Y-m-d\TH:iP"
  ["date"]=>
  string(26) "2000-10-20 11:11:00.000000"
  ["timezone_type"]=>
  int(2)
  ["timezone"]=>
  string(3) "CET"
}
string(22) "2000-10-20T11:11+01:00"
object(ion\Timestamp)#%d (3) {
  ["precision"]=>
  int(55)
  ["format"]=>
  string(12) "Y-m-d\TH:i:s"
  ["date"]=>
  string(26) "1971-02-03 04:05:06.000000"
}
DONE
