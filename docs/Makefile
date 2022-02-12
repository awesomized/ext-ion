DOCKER ?=
PHP ?= $(DOCKER) php
COMPOSER ?= $(DOCKER) composer
TAG := $(shell (git describe --tags --match=v[0-9]*  2>/dev/null || git tag --sort=authordate | egrep ^v[0-9] | tail -n1) | cut -d. -f-2)

# ---

SPECIAL_SRC := src/ion/\\\:\\\ Security.md src/ion/\\\:\\\ Contributing.md src/ion.md src/mdref.json

.PHONY: all
all: latest

latest: $(TAG)
	-unlink $@ 2>/dev/null
	ln -s "$(TAG)/" $@
	touch $@

$(TAG): markdown | vendor/bin/ref2html
	mkdir -p $@
	-ln -s . ext-ion
	$(PHP) $| ext-ion/$@ src
	unlink ext-ion
	touch $@

.PHONY: markdown
markdown: src/ion.stub.php $(SPECIAL_SRC) | vendor/bin/stub2ref
	$(PHP) $| ion $< src

src src/ion:
	-mkdir -p $@
src/mdref.json: mdref.json
	-test -e $@ || ln $^ $@
src/ion.stub.php: ../ion.stub.php | src
	-test -e $@ || ln $^ $@
src/ion.md: ../README.md | src
	-test -e $@ || ln $^ $@
src/ion/\\\:\\\ Security.md: ../SECURITY.md | src/ion
	-test -e $@ || ln $^ $@
src/ion/\\\:\\\ Contributing.md: ../CONTRIBUTING.md | src/ion
	-test -e $@ || ln $^ $@

vendor/%:
	COMPOSER= $(COMPOSER) require m6w6/mdref:dev-master

.PHONY: docker
docker:
	docker-compose -f docker/compose.yml build php
	docker-compose -f docker/compose.yml build composer
	$(MAKE) DOCKER="docker-compose -f docker/compose.yml run --rm"

.PHONY: clean
clean:
	-rm -rf latest src vendor composer* .composer


