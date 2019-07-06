.PHONY: all
all: test

bubble_sort: main.c
	gcc -o bubble_sort main.c

test: bubble_sort
	./bubble_sort

.PHONY: clean
clean:
	rm -rf bubble_sort *.o
