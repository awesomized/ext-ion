--TEST--
integration: do not write decimals but native floats only
--EXTENSIONS--
ion
--FILE--
TEST
<?php

class NoDecimals  extends ion\Serializer\Serializer {
	public function serialize(mixed $data, \ion\Writer\Options|\ion\Writer|array|null $writer = null): mixed {
		return parent::serialize($data, new class extends \ion\Writer\Buffer\Writer {
			public function writeDecimal(\ion\Decimal|string $value): void {
				if ($value instanceof \ion\Decimal) {
					$value = (string)$value;
				}
				$this->writeFloat((float) $value);
			}
		});
	}
}


$data = [1.123, new ion\Decimal("1.123"), 123, new ion\Decimal(123)];
echo ion\serialize($data), "\n";
echo ion\serialize($data, new NoDecimals), "\n";
?>
DONE
--EXPECTREGEX--
TEST
\[1\.12\d+e\+0,1\.123,123,123d0\]
\[(1\.12\d+e\+0),\1,123,123e\+0\]
DONE
