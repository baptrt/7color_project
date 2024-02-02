FLAGS=-Wall -Werror -lm -g

7color : o/map.o
	gcc $(FLAGS) o/map.o -o 7color

o/map.o: head/map.h src/map.c
	gcc $(FLAGS) -c src/map.c -o o/map.o
