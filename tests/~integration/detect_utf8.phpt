--TEST--
integration: custom serializer which naïvly decides to write strings/clobs/blobs
--EXTENSIONS--
ion
intl
--FILE--
TEST
<?php

class AutoUtf8 extends ion\Serializer\Serializer {
	public function serialize(mixed $data, \ion\Writer|array|null $writer = null): mixed {
		return parent::serialize($data, new class extends \ion\Writer\Buffer\Writer {
			private function iterate(string $s) : Generator {
				for ($i = 0; $i < grapheme_strlen($s); ++$i) {
					yield grapheme_substr($s, $i, 1);
				}
			}
			private function classify(string $c) : bool {
				if (strlen($c) > 1) {
					return false;
				} elseif ($c < "\040") return match ($c) {
					"\n", "\r", "\t" => false,
					default => true
				};
				return $c >= "\177";
			}
			public function writeString(string $value) : void {
				$dist = [0, 0];
				foreach ($this->iterate($value) as $c) {
					if (false === $c) {
						goto binary;
					}
					++$dist[$this->classify($c)];
				}
				if ($dist[0] <= $dist[1]) {
				binary:
					parent::writeBLob($value);
				} elseif ($dist[1]) {
					parent::writeCLob($value);
				} else {
					parent::writeString($value);
				}
			}
		});
	}
}

$data = ["abc", "äöü", "\nabc\n", "foo\0bar", hex2bin("1f8b08003d96676200034bcacc4b2caae40200f5127b4207000000")];
echo ion\serialize($data), "\n";
echo ion\serialize($data, new AutoUtf8), "\n";
?>
DONE
--EXPECTF--
TEST
["abc","äöü","\nabc\n","foo\0bar","\x1F%s\x12{B\a\0\0\0"]
["abc","äöü","\nabc\n",{{"foo\0bar"}},{{H4sIAD2WZ2IAA0vKzEssquQCAPUSe0IHAAAA}}]
DONE
