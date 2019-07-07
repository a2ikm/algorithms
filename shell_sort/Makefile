.PHONY: all
all: test

shell_sort: main.c
	gcc -o shell_sort main.c

test: shell_sort
	./shell_sort

.PHONY: clean
clean:
	rm -rf shell_sort *.o
