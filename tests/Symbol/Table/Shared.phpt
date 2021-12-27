--TEST--
ion\Symbol\Table\Shared
--EXTENSIONS--
ion
--FILE--
TEST
<?php

$c = new ion\Catalog;
$c->add(new ion\Symbol\Table\Shared("shared", 1, ["shared1", "shared2"]));
$w = new ion\Writer\Buffer\Writer($buf,
	new ion\Writer\Options(catalog: $c, outputBinary: true));

$w->writeSymbol("shared1");
$w->writeSymbol("shared1");
$w->writeSymbol("shared2");
$w->writeSymbol("shared2");

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
var_dump($s = $u->unserialize($buf));

foreach ($s as $sym) {
	/** @var ion\Symbol $sym */
	$t = $c->findBest($sym->importLocation->name);
	$r = $t->findLocal($sym->importLocation->location);
	printf("%s: %s@%d\n", $r->value, $sym->importLocation->name,
		$sym->importLocation->location);
}

$u = new ion\Unserializer\PHP(multiSequence: true,
	readerOptions: new ion\Reader\Options(
		catalog: $c,
		onContextChange: fn(ion\Reader $r) => print("on_context_change\n")));
var_dump($u->unserialize($buf));

?>
DONE
--EXPECTF--
TEST
e0 01 00 ea ee 97 81 83   ........
de 93 86 be 90 de 8e 84   ........
86 73 68 61 72 65 64 85   .shared.
21 01 88 21 02 71 0a 71   !..!.q.q
0a 71 0b 71 0b            .q.q.

array(4) {
  [0]=>
  object(ion\Symbol)#%d (3) {
    ["value"]=>
    string(0) ""
    ["sid"]=>
    int(10)
    ["importLocation"]=>
    object(ion\Symbol\ImportLocation)#%d (2) {
      ["name"]=>
      string(6) "shared"
      ["location"]=>
      int(1)
    }
  }
  [1]=>
  object(ion\Symbol)#%d (3) {
    ["value"]=>
    string(0) ""
    ["sid"]=>
    int(10)
    ["importLocation"]=>
    object(ion\Symbol\ImportLocation)#%d (2) {
      ["name"]=>
      string(6) "shared"
      ["location"]=>
      int(1)
    }
  }
  [2]=>
  object(ion\Symbol)#%d (3) {
    ["value"]=>
    string(0) ""
    ["sid"]=>
    int(11)
    ["importLocation"]=>
    object(ion\Symbol\ImportLocation)#%d (2) {
      ["name"]=>
      string(6) "shared"
      ["location"]=>
      int(2)
    }
  }
  [3]=>
  object(ion\Symbol)#%d (3) {
    ["value"]=>
    string(0) ""
    ["sid"]=>
    int(11)
    ["importLocation"]=>
    object(ion\Symbol\ImportLocation)#%d (2) {
      ["name"]=>
      string(6) "shared"
      ["location"]=>
      int(2)
    }
  }
}
shared1: shared@1
shared1: shared@1
shared2: shared@2
shared2: shared@2
on_context_change
array(4) {
  [0]=>
  object(ion\Symbol)#%d (3) {
    ["value"]=>
    string(7) "shared1"
    ["sid"]=>
    int(10)
    ["importLocation"]=>
    object(ion\Symbol\ImportLocation)#%d (2) {
      ["name"]=>
      string(6) "shared"
      ["location"]=>
      int(1)
    }
  }
  [1]=>
  object(ion\Symbol)#%d (3) {
    ["value"]=>
    string(7) "shared1"
    ["sid"]=>
    int(10)
    ["importLocation"]=>
    object(ion\Symbol\ImportLocation)#%d (2) {
      ["name"]=>
      string(6) "shared"
      ["location"]=>
      int(1)
    }
  }
  [2]=>
  object(ion\Symbol)#%d (3) {
    ["value"]=>
    string(7) "shared2"
    ["sid"]=>
    int(11)
    ["importLocation"]=>
    object(ion\Symbol\ImportLocation)#%d (2) {
      ["name"]=>
      string(6) "shared"
      ["location"]=>
      int(2)
    }
  }
  [3]=>
  object(ion\Symbol)#%d (3) {
    ["value"]=>
    string(7) "shared2"
    ["sid"]=>
    int(11)
    ["importLocation"]=>
    object(ion\Symbol\ImportLocation)#%d (2) {
      ["name"]=>
      string(6) "shared"
      ["location"]=>
      int(2)
    }
  }
}
DONE
