# variable definitions: if you write A = x then $(A) will correspond to x
# do not write comments next to command lines else the makefile crashes out

# CC = C compiler
CC = gcc

# flags
CFLAGS = -Wall

# function called when you write "make" whatever
# default target called when you just write "make" (shows a small help message instead of compiling a random file)
all:
# actual terminal line
	@echo "Usage: make 00   -> compiles ex00.c into ex00"
	@echo "Usage: make 01   -> compiles ex01.c into ex01"
	@echo "Usage: make clean"

%:
# if you write "make XX", then $@ becomes XX
	$(CC) $(CFLAGS) ex$@.c

# removes generated executables and object files
clean:
	rm -f ex?? *.o





## removed things

# lists files matching pattern *.c
# SRC = $(wildcard *.c)

# variable X declared and defaulted to 1
#X ?= 1

# target is set to exPX where X is the variable
#TARGET = exP$(X)