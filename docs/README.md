# ext-ion docs
https://awesomized.github.io/ext-ion

## Howto update docs

1. Edit stub: `$EDITOR ../ion.stub.php`
2. [Rebuild](#Build)
3. [Review](#Review); repeat from 2. if necessary
4. [Deploy](#Deployment)

## Howto make a release

### 1. Create tag
```
git tag vX.Y.Z
```

### 2. Rebuild docs
See [Rebuild](#Rebuild).

### 3. Review docs
See [Review](#Review).

### 4. Commit docs with release changelog:  
```
git add .
git commit
```
```
release vX.Y.Z

* Additions ...
* Changes ...
```
### 5. Move tag:
```
git tag -f vX.Y.Z
```
### 6. Release & [deploy](#Deployment):
```
git push
```

## Build
### Prerequisites without docker:
* composer v2
* PHP with ext-http and ext-dom but **without** ext-ion

```
   ┌─────────┐
   │  BUILD  │                     ┌──────────┐
 ┌─┴─────────┴──────────────┐      │  SOURCE  │
 │  $ make #docker UID=$UID ├──►┌──┴──────────┴───────────┐
 └──────────────────────────┘   │ ../README.md            │
                                │ ../ion.stub.php         │
 ┌──────────────────────────────┤ ../...                  │
 │                              └─────────────────────────┘
 │ ┌────────────────┐
 │ │  PROCESSED BY  │              ┌────────────┐
┌▼─┴────────────────┴───────┐      │  MARKDOWN  │
│ ./vendor/bin/stub2ref     ├──►┌──┴────────────┴─────────┐
└───────────────────────────┘   │ ./src/mdref.json        │
                                │ ./src/ion.md            │
 ┌──────────────────────────────┤ ./src/ion/...           │
 │                              └─────────────────────────┘
 │ ┌────────────────┐
 │ │  PROCESSED BY  │              ┌────────┐
┌▼─┴────────────────┴───────┐      │  HTML  │
│ ./vendor/bin/ref2html     ├──►┌──┴────────┴─────────────┐
└───────────────────────────┘   │ ./docs/latest -> vX.Y/  │
                                │ ./docs/vX.Y/index.html  │
                                │ ./docs/vX.Y/ion/...     │
                                └─────────────────────────┘
```

## Review
### Caddy
Run caddy to read the docs as they would appear on https://awesomized.github.io/ext-ion.
```shell
caddy run
```

Use `$CADDY_ADDRESS` env var to customize the HTTP endpoint, e.g:
```shell
CADDY_ADDRESS=localhost:8080 caddy run
```

Use docker, if you do not have caddy installed:
```shell
docker-compose -f docker/compose.yml run -p 8080:80 caddy
```
### PHP
Use PHP CLI server if you're desperate:
```shell
php -S localhost:0 -r . .router.php
```

## Deployment
```
   ┌──────────┐
   │  DEPLOY  │
┌──┴──────────┴─────────────┐
│  $ git add .              │      ┌────────────┐
│  $ git commit             │      │ GH ACTION  │
│  $ git push               ├──►┌──┴────────────┴─────────┐
└───────────────────────────┘   │  pages-build-deployment │
                                └─┬───────────────────────┘
   ┌──────────────┐               │
   │  DEPLOYMENT  │               │
┌──┴──────────────┴───────────────▼───────────────────────┐
│                                                         │
│       https://awesomized.github.io/ext-ion/latest/      │
│                                                         │
└─────────────────────────────────────────────────────────┘

```
