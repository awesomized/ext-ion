--TEST--
ion\LOB/RW
--EXTENSIONS--
ion
--FILE--
TEST
<?php
$s = stream_socket_pair(STREAM_PF_UNIX, STREAM_SOCK_STREAM, 0);
array_map(fn($s)=>stream_set_blocking($s,false), $s);

$w = new ion\Writer\Stream\Writer($s[0]);
$w->startLob(ion\Type::CLob);
$w->appendLob(str_repeat("a", 0x1000));

$l = 0;
$r = new ion\Reader\Stream\Reader($s[1]);
for ($i = 0; $i < 10; $i++) {
	$W=$E=[];
	for ($R=[$s[1]]; stream_select($R, $W, $E, 0); ) {
		if ($r->getType() != ion\Type::CLob)
			$r->next();
		echo "+";
		$r->readLobPart($b);
		$l += strlen($b);
	}
	echo "-";
	$w->appendLob(str_repeat("a", 0x1000));
}

$w->finishLob();
$w->finish();

while ($r->readLobPart($b)) {
	echo ".";
    $l += strlen($b);
}
echo "\n";

$r->next();
var_dump($r->key(), $l);
?>
DONE
--EXPECTF--
TEST
%r[-+]+\.+%r
enum(ion\Type::EOF)
int(45056)
DONE
