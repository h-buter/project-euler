# Makefile
CC = gcc
CFLAGS = -Wall -O2

# Default: build the program given by p=<number>
# e.g. make p=1
build: ./Problems/$(p)/build/Debug 
	$(CC) $(CFLAGS) ./Problems/$(p)/$(p).c -lm ./Problems/common.c -o ./Problems/$(p)/build/Debug/$(p).o	


./Problems/%/build/Debug:
	mkdir -p $@

# Run the program and print runtime
run: build
	@echo "Running ./Problems/$(p)/build/Debug/$(p).o"
	@start=$$(date +%s.%N); \
	./Problems/$(p)/build/Debug/$(p).o; \
	end=$$(date +%s.%N); \
	runtime=$$(echo "$$end - $$start" | bc); \
	intpart=$$(echo "$$runtime >= 1" | bc); \
	if [ "$$intpart" -eq 1 ]; then \
		echo "Runtime: $$runtime seconds"; \
	else \
		ms=$$(echo "$$runtime * 1000" | bc); \
		printf "Runtime: %.3f ms\n" "$$ms"; \
	fi
