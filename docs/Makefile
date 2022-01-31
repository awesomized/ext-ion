PHP ?= php
COMPOSER ?= composer
TAG := $(shell (git describe --tags --exact-match --match=v[1-9]*  2>/dev/null || echo v0.0) | cut -d. -f-2)

# ---

SPECIAL_SRC := src/ion/\\\:\\\ Security.md src/ion/\\\:\\\ Contributing.md src/ion.md

.PHONY: all
all: latest

latest: $(TAG)
	-unlink $@ 2>/dev/null
	ln -s "$(TAG)/" $@
	touch $@

$(TAG): markdown | vendor/bin/ref2html
	mkdir -p $@
	$(PHP) $| ext-ion/$@ src
	touch $@

.PHONY: markdown
markdown: src/ion.stub.php $(SPECIAL_SRC) | vendor/bin/stub2ref
	$(PHP) $| ion $< src

src src/ion:
	-mkdir -p $@
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

.PHONY: clean
clean:
	-rm -rf latest src vendor composer.*


