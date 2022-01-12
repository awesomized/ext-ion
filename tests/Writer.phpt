--TEST--
ion\Writer
--EXTENSIONS--
ion
--INI--
date.timezone=UTC
--FILE--
TEST
<?php

$w = new ion\Writer\Stream\Writer(STDOUT,
	new ion\Writer\Options(flushEveryValue: true));

$w->writeNull();
echo "\n";
$w->writeTypedNull(ion\Type::Int);
echo "\n";
$w->writeBool(true);
echo "\n";
$w->writeBool(false);
echo "\n";
$w->writeInt(0);
echo "\n";
$w->writeInt(123);
echo "\n";
$w->writeInt(-123);
echo "\n";
$w->writeInt("12345678901234567890");
echo "\n";
$w->writeFloat(1e0);
echo "\n";
$w->writeFloat(-.0);
echo "\n";
$w->writeDecimal("1.23");
echo "\n";
$w->writeDecimal(new ion\Decimal(-123));
echo "\n";
$w->writeTimestamp("2001T");
echo "\n";
$w->writeTimestamp(new ion\Timestamp(ion\Timestamp\Precision::Frac));
echo "\n";
$w->writeSymbol("a");
echo "\n";
$w->writeSymbol(new ion\Symbol("b"));
echo "\n";
$w->writeString("abc");
echo "\n";
$w->writeCLob("clob");
echo "\n";
$w->writeBLob("blob");
echo "\n";
$w->startLob(ion\Type::CLob);
$w->appendLob("clob");
$w->finishLob();
echo "\n";
$w->startContainer(ion\Type::Struct);
$w->writeFieldName("prop");
$w->writeAnnotation(ion\Symbol\Table\PHP::Property->toSymbol());
$w->writeInt($w->getDepth());
$w->writeFieldName(new ion\Symbol("priv"));
$w->writeAnnotation("a","b","c");
$w->writeInt($w->getDepth());
$w->finishContainer();
echo "\n";
$w->writeInt($w->getDepth());
$w->finish();
echo "\n";

?>
DONE
--EXPECTF--
TEST
null
 null.int
 true
 false
 0
 123
 -123
 12345678901234567890
 1e+0
 -0e0
 1.23
 -123d0
 2001T
 %r\d{4}-[01]\d-[0-3]\dT[0-2]\d:[0-5]\d:[0-5]\d\.\d+%r-00:00
 a
 b
 "abc"
 {{"clob"}}
 {{YmxvYg==}}
 {{"clob"}}
 {prop:p::1,priv:a::b::c::1}
 0
DONE
