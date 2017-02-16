CC ?= cc
CFLAGS = -ansi -O2
DBGFLAGS = -W -Wall -Werror -Wextra -Wno-unused-parameter -pedantic -pedantic-errors -g -ansi
PREFIX = /usr/local

all:
	$(CC) $(CFLAGS) -o ç ccdille.c
debug:
	$(CC) $(DBGFLAGS) -o ç ccdille.c
clean:
	rm -rf ç
install: all
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	install -m 0755 ç $(DESTDIR)$(PREFIX)/bin

.PHONY: clean all debug install
