# Makefile
CC = gcc
CFLAGS = -Wall -O2

# Default: build the program given by p=<number>
# e.g. make p=1
build: ./Problems/$(p)/build/Debug 
	$(CC) $(CFLAGS) ./Problems/$(p)/$(p).c -lm ./Problems/common.c -o ./Problems/$(p)/build/Debug/$(p).o	


./Problems/%/build/Debug:
	mkdir -p $@

# Clean up all binaries
# clean:
# 	rm -f p*
