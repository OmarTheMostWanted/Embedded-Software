CC      = gcc
CFLAGS  += -std=c99 -g -Wall
CPPFLAGS+= -I.

SOURCES := $(wildcard buggy[1-5].c)
TARGETS := $(SOURCES:.c=)

all: $(TARGETS)
	# run test cases
	./buggy1 || true
	echo "11+13" | ./buggy2 || true
	./buggy3 | diff buggy3.out - || true
	./buggy4 || true
	./buggy5 || true

clean:
	rm -f $(TARGETS)
