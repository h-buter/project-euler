# Makefile
CC = gcc
CFLAGS = -Wall -O2

# Default: build the program given by p=<number>
# e.g. make p=1
build:
	$(CC) $(CFLAGS) ./Problems/$(p)/$(p).c ./Problems/common.c -o ./Problems/$(p)/build/Debug/$(p).o	

# Clean up all binaries
# clean:
# 	rm -f p*
