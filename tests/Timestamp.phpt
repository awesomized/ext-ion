--TEST--
ion\Timestamp
--EXTENSIONS--
ion
--FILE--
TEST
<?php
use ion\Timestamp;

try {
	var_dump(new Timestamp);
} catch (Throwable) {
	echo "caught empty\n";
}
$full = "2021-12-07T14:08:51+00:00";
var_dump($t=new Timestamp(Timestamp\Precision::Day, datetime:$full),(string)$t);
var_dump($t=new Timestamp(Timestamp\Precision::Day->value, datetime:$full),(string)$t);
var_dump($t=new Timestamp(Timestamp\Precision::Min, datetime:"2020-10-01"),(string)$t);
var_dump($t=new Timestamp(Timestamp\Precision::Day, "!Y-m", "2000-10"),(string)$t);
?>
DONE
--EXPECTF--
TEST
caught empty
object(ion\Timestamp)#%d (2) {
  ["precision"]=>
  int(7)
  ["format"]=>
  string(7) "Y-m-d\T"
}
string(11) "2021-12-07T"
object(ion\Timestamp)#%d (2) {
  ["precision"]=>
  int(7)
  ["format"]=>
  string(7) "Y-m-d\T"
}
string(11) "2021-12-07T"
object(ion\Timestamp)#%d (2) {
  ["precision"]=>
  int(23)
  ["format"]=>
  string(11) "Y-m-d\TH:iP"
}
string(22) "2020-10-01T00:00+00:00"
object(ion\Timestamp)#%d (2) {
  ["precision"]=>
  int(7)
  ["format"]=>
  string(7) "Y-m-d\T"
}
string(11) "2000-10-01T"
DONE
