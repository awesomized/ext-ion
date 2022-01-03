LIB_IONC_STATIC := $(builddir)/ion-c/build/ionc/libionc_static.a
LIB_DECN_STATIC := $(builddir)/ion-c/build/decNumber/libdecNumber_static.a

$(builddir)/ion.lo: $(LIB_IONC_STATIC) $(LIB_DECN_STATIC)

$(builddir)/ion-c/build:
	mkdir -p $@
	+cd $@ && CFLAGS=-w CXXFLAGS=-w \
	$(CMAKE) -Wno-dev --log-level=ERROR \
		-DCMAKE_BUILD_TYPE=Release \
		-DCMAKE_POSITION_INDEPENDENT_CODE=ON \
		$(srcdir)/ion-c

$(LIB_IONC_STATIC): | $(builddir)/ion-c/build
	+$(CMAKE) --build $| --target ionc_static -- VERBOSE=
$(LIB_DECN_STATIC): | $(builddir)/ion-c/build
	+$(CMAKE) --build $| --target decNumber_static -- VERBOSE=

clean: clean-ion

.PHONY: clean-ion
clean-ion:
	-rm -rf $(builddir)/ion-c/build

.PHONY: gcov-ion
gcov-ion:
	@rm -rf $@
	@mkdir -p $@
	gcovr -j $$(nproc) -sr . --html --html-details --html-title $@ -o $@/index.html -f '.*/(php_)?ion.*'
