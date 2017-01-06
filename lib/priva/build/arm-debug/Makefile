#
#  CONTENT
#    
#
#  AUTHOR
#    Norbert Stoeffler
#
#  DATE
#    2017-01-03
#
#  LANGUAGE
#    make
#
GTEST =		../../../../3rdparty/gtest
BLIB =		../../../../blib

CFLAGS +=	-Wall
CFLAGS +=	-I../../include -I$(GTEST)/include
CXXFLAGS :=	$(CFLAGS)

# help
help:
	@echo "'make tests'" to build and test libnav
	@echo "'make install'" to build, test, and copy to binlibs

# libpriva, the main artefact of our project
VPATH += 	../../src
libpriva.a:	priva.o util.o
	ar rs $@ $^

# clean
clean:
	rm -f *.o *.a *.elf

# hack, build gtest here
libgtest.a:	CXXFLAGS += -I$(GTEST) -DGTEST_HAS_PTHREAD=0
VPATH += $(GTEST)/src
libgtest.a: 	gtest-all.o gtest-death-test.o gtest-filepath.o gtest-port.o \
		gtest-printers.o gtest-test-part.o gtest-typed-test.o gtest.o \
		gtest_main.o
	ar rs $@ $^

# build and run the tests
VPATH += 	../../src/tests
tests.elf:	test_priva.o libpriva.a libgtest.a
	g++ -o $@ $^
tests:		tests.elf
	./tests.elf

# install binaries + interfaces
install:	tests
	cp libpriva.a $(BLIB)/priva/build/arm-debug
	cp -a ../../include/priva $(BLIB)/priva/include
