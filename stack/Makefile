.PHONY: all
all: test

stack: main.c
	gcc -o stack main.c

test: stack
	./stack

.PHONY: clean
clean:
	rm -rf stack *.o
