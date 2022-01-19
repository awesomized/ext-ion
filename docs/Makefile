PHP ?= php
COMPOSER ?= composer
TAG := $(shell (git describe --tags --exact-match --match=v[1-9]* || echo v0.0) | cut -d. -f-2 2>/dev/null)

.PHONY: all
all: latest

.PHONY: clean
clean:
	-rm -rf latest src vendor composer.*

vendor/%:
	$(COMPOSER) require m6w6/mdref:dev-master

src: ../ion.stub.php | vendor/bin/stub2ref
	mkdir -p $@ && cd $@ && $(PHP) ../$| ion ../$^
	touch $@

$(TAG): src | vendor/bin/ref2html
	mkdir -p $@
	$(PHP) $| $@ $^
	touch $@

latest: $(TAG)
	-unlink latest 2>/dev/null
	ln -s "$(TAG)/" latest
	touch $@
