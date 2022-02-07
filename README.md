# pecl/ion

## About:
PHP extension wrapping [amzn/ion-c](https://github.com/amzn/ion-c).
See the [Amazon ION specification](https://amzn.github.io/ion-docs/).

## License:
[BSD-2-Clause](https://github.com/awesomized/ext-ion/blob/master/LICENSE);
see [spdx.org](https://spdx.org/licenses/BSD-2-Clause.html).

## Installation:

### Dependencies:
#### Required:
* PHP-8.1
  * ext/date (standard)
  * ext/spl (standard)
#### Optional:
* [amzn/ion-c](https://github.com/amzn/ion-c) (bundled as git submodule)

### Trinity:
```shell
phpize
./configure # --with-php-config=<path/to/php-config>
make # -j$(nproc)
sudo make install # INSTALL=install
```

### PECL

	pecl install ion

### PHARext

Watch out for [PECL replicates](https://replicator.pharext.org?ion)
and pharext packages attached to [releases](./releases).

### Try with Docker:
```shell
docker build -t php-ion
docker run --rm php-ion -r 'echo ion\serialize(ion\Symbol\PHP::asTable());'
```

## Editor Stub:
See [ion.stub.php](https://github.com/awesomized/ext-ion/blob/master/ion.stub.php).

## Known Issues:
Due to private internal state of ion-c's readers and writers,
instances of the following PHP classes cannot be cloned:
* ion\Reader\Reader
* ion\Writer\Writer
* ion\Serializer\PHP
* ion\Unserializer\PHP
