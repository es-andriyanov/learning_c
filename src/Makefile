all:
	make two_dem_array

two_dem_array: two_dem_array.o
	gcc -Wall -Werror -Wextra two_dem_array.o -D LOG -o ../build/two_dem_array
	rm -rf *.o

two_dem_array.o: two_dem_array.c
	gcc -c two_dem_array.c -o two_dem_array.o

clear:
	rm -rf ../build/*
	rm -rf ./log
	rm -rf *.o
