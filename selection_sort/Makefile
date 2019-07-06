.PHONY: all
all: test

selection_sort: main.c
	gcc -o selection_sort main.c

test: selection_sort
	./selection_sort

.PHONY: clean
clean:
	rm -rf selection_sort *.o
