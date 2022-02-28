--TEST--
ion\Timestamp with TZ as string
--EXTENSIONS--
ion
--INI--
date.timezone=UTC
--FILE--
TEST
<?php
$ts = new ion\Timestamp(
	precision: ion\Timestamp\Precision::MinTZ,
	format: \ion\Timestamp\Format::Min,
	datetime: "2022-02-28T11:40",
	timezone: "Europe/Madrid",
);
var_dump($ts->getTimezone());
echo $ts, "\n";
echo $ts->setTimezone(new DateTimeZone(("America/Toronto"))), "\n";
?>
DONE
--EXPECTF--
TEST
object(DateTimeZone)#%d (2) {
  ["timezone_type"]=>
  int(3)
  ["timezone"]=>
  string(13) "Europe/Madrid"
}
2022-02-28T11:40+01:00
2022-02-28T05:40-05:00
DONE
