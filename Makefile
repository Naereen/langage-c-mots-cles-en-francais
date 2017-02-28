CC ?= cc
CFLAGS = -ansi -O2
DBGFLAGS = -W -Wall -Werror -Wextra -Wno-unused-parameter -pedantic -pedantic-errors -g -ansi
PREFIX = /usr/local

ç: ç.c ç.h
	$(CC) $(CFLAGS) -o ç ç.c
ç.c: ç.c.fr
	./ç traduire ç.c.fr
ç.h: ç.h.fr
	./ç traduire ç.h.fr

all: ç
debug: ç.c ç.h
	$(CC) $(DBGFLAGS) -o ç.debug ç.c
bootstrap:
	$(MAKE) -o ç.c -o ç.h
clean:
	rm -rf ç ç.debug
install: all
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	install -m 0755 ç $(DESTDIR)$(PREFIX)/bin

.PHONY: clean all debug bootstrap install
