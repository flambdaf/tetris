all: 
	gcc -Wall -Wextra backend.c
	./a.out
	rm a.out