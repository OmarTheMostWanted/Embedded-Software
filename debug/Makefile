CC      = gcc
CFLAGS  += -Wall -g #-std=c99
CPPFLAGS+= -I.

LIBSRC := $(wildcard [a-su-z]*.c)
OBJECTS := $(LIBSRC:.c=.o)
TARGET := tstprog

all: t3config $(TARGET)
	# run test cases
	./$(TARGET) || true
	./$(TARGET) missing-schema || true
	./$(TARGET) meta_schema.schema || true

t3config:
	ln -s . t3config

tstprog: $(OBJECTS) tstprog.o
	$(CC) -o $@ $^

submit:
	zip submit.zip Makefile *.[ch] meta_schema.bytes *.schema

clean:
	rm -f $(TARGET) $(OBJECTS) $(TARGET) $(TARGET).o out submit.zip
