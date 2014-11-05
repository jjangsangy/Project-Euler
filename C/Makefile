CC=clang
CFLAGS=-g -O2 -Wall -Wextra $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)
PREFIX=bin
EXEC_PREFIX=$(PREFIX)

SOURCES=$(wildcard *.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))
TARGET=$(patsubst %.c,%,$(SOURCES))


all:
	$(CC) $(CFLAGS) -o $@ $^

build:
	@mkdir -p build
	@mkdir -p bin

.PHONY: clean

clean:
	rm -rf build bin $(OBJECTS)
	rm -rf `find . -name "*.dSYM" -print`

