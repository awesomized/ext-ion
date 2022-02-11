# Read the docs
Run caddy to read the docs as the would appear on https://awesomized.github.io/ext-ion.

```sh
caddy run
```
Use `$CADDY_ADDRESS` envvar to customize the HTTP endpoint, e.g:
```
CADDY_ADDRESS=localhost:1234 caddy run
```

# Build the docs

## Without docker:
### Prerequsites:
* composer v2
* PHP with ext-http and ext-dom
* GNU make

```sh
make
```

## With docker:
### Prerequisites:
* docker-compose
* your UID in docker-composer.yml
* GNU make

```sh
make COMPOSER="docker-compose run --rm composer" \
	PHP="docker-compose run --rm --entrypoint php composer"
```

# Release procedure

1. create tag
2. rebuild docs
3. review docs
4. commit
5. move tag
6. push
