--TEST--
ion\Reader
--EXTENSIONS--
ion
--INI--
date.timezone=UTC
--FILE--
TEST
<?php

$tests = [
	"getType" => [
		["0d0", ion\Type::Decimal],
		["1.23", ion\Type::Decimal],
		["abc", ion\Type::Symbol],
		["()", ion\Type::SExp],
	],
	"hasAnnotations" => [
		["foo::1", true],
		["1", false],
	],
	"hasAnnotation" => [
		["foo::1", false, "bar"],
		["foo::1", true, "foo"],
	],
	"isNull" => [
		["null", true],
		["1", false],
	],
	"isInStruct" => [
		["{a:b}", false],
		"step" => ["{a:b}", true],
	],
	"getFieldName" => [
		["{a:b}", ""],
		"step" => ["{a:b}", "a"],
	],
	"getFieldNameSymbol" => [
		["{a:b}", new ion\Symbol("")],
		"step" => ["{a:b}", new ion\Symbol("a")],
	],
	"getAnnotations" => [
		["foo::bar::1", ["foo", "bar"]],
		["1", []],
	],
	"getAnnotationSymbols" => [
		["f::b::1", [new ion\Symbol("f"), new ion\Symbol("b")]],
		["1", []],
	],
	"countAnnotations" => [
		["f::b::z::1", 3],
		["1", 0],
	],
	"getAnnotation" => [
		["foo::bar::1", "bar", 1],
	],
	"getAnnotationSymbol" => [
		["foo::bar::1", new ion\Symbol("foo"), 0],
	],
	"readNull" => [
		["null.int", ion\Type::Int],
		["null", ion\Type::Null],
	],
	"readBool" => [
		["true", true],
		["false", false],
	],
	"readInt" => [
		["0", 0],
		["1234", 1234],
		[PHP_INT_MAX, PHP_INT_MAX],
		[PHP_INT_MIN, PHP_INT_MIN],
	],
	"readFloat" => [
		["1e", 1e0],
	],
	"readDecimal" => [
		["1.23", new ion\Decimal("1.23")],
	],
	"readTimestamp" => [
		["2003-05T", new ion\Timestamp(ion\Timestamp\Precision::Month, "!Y-m", "2003-05")],
	],
	"readSymbol" => [
		["abc", new ion\Symbol("abc")],
	],
	"readString" => [
		["'''abc'''", "abc"],
	],
	"readLob" => [
		["{{'''abcdef'''}}", "abcdef"],
	],
	"getPosition" => [
		["{}", 1],
		"next" => ["{}", 2],
	],
	"getDepth" => [
		["{}", 0],
		"step" => ["{}", 1],
	],
	"hasChildren" => [
		["{a:b}", true],
		"step" => ["{a:b}", false],
	],
	"getValueOffset" => [
		["a", 0],
		"step" => ["{ab:'''cdefgh'''", 4],
	],
	"getValueLength" => [ // always returns -1 for text readers
		["a", -1],
		"step" => ["{ab:'''cdefgh'''", -1],
	],
];

foreach ($tests as $test => $specs) {
	foreach ($specs as $prep => $spec) {
		[$data, $check] = $spec;
		$args = array_slice($spec, 2);

		$r = new ion\Reader\Buffer\Reader($data);
		$r->next();
		try {
			switch ($prep) {
				case "step":	$r->getChildren();	/* fall through */
				case "next":	$r->next();			break;
			}
			$result = $r->$test(...$args);
		} catch (Throwable $e) {
			$result = $e;
		}

		if ($check != $result) {
			echo "$test@$prep\n";
			var_dump(compact("check", "result"));
			var_dump((string)$result);
			echo "\n";
		}
	}
}
?>
DONE
--EXPECT--
TEST
DONE
