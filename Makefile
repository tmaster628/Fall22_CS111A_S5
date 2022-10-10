# A simple makefile for building a program composed of C source files.
# This makefile was shamelessly stolen by Trip Master from a version 
# of CS107. Sorry about that!


PROGRAMS = cats_bats

all:: $(PROGRAMS)

CC = gcc
CFLAGS = -g3 -O0 -std=gnu99 -Wall $$warnflags
export warnflags = -Wfloat-equal -Wtype-limits -Wpointer-arith -Wlogical-op -Wshadow -Winit-self -fno-diagnostics-show-option
LDFLAGS =
LDLIBS =

$(PROGRAMS): %:%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean::
	rm -f $(PROGRAMS) res.txt *.o

.PHONY: clean all
