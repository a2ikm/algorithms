.PHONY: all
all: test

insert_sort: main.c
	gcc -o insert_sort main.c

test: insert_sort
	./insert_sort

.PHONY: clean
clean:
	rm -rf insrt_sort *.o
