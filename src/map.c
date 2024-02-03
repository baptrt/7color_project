#include "../head/map.h"
#include <stdlib.h>
#include <stdio.h>

Map map = {.map = NULL, .size = 0};

void create_empty_map (Map* map, int size){
	map -> size = size; 
	map -> map = malloc(sizeof(Color)* map -> size * map -> size);
}

void set_map_value (Map* map, int x, int y, Color value){
	map -> map[y * map -> size + x] = value;
}

Color get_map_value (Map* map, int x, int y){
	if (map -> map == NULL || x > map -> size || y > map -> size)
	{
		printf("[ERROR] map not big enough or not initialized %p %i access (%i %i)", map -> map, map -> size, x, y);
		return ERROR;
	}
	return map -> map[y * map -> size + x];
}

void fill_map(Map* map){
	int n = 0;
	for (int i = 0; i < map -> size; i++){
		for (int j = 0; j < map -> size; j++){
				n = rand()%7 + 3; 
				set_map_value (map, i, j, n);
		}
	}
set_map_value(map, 0, map -> size - 1, 1);
set_map_value(map, map -> size - 1, 0, 2);
}

void print_map(Map* map);

int main(int argc, char** argv){
	create_empty_map(&map, 10);
	fill_map(&map);
	print_map(&map);
}

void print_map(Map* map){
	for (int i = 0; i < map -> size; i++){
		for (int j = 0; j < map -> size; j++){
			if (get_map_value (map, i, j) == 1){
				printf("1");
			}
			if (get_map_value (map, i, j) == 2){
				printf("2");
			}
			if (get_map_value (map, i, j) == 3){
				//printf("R");
				printf("\033[1;31m■\033[0m");
			}
			if (get_map_value (map, i, j) == 4){
				//printf("G");
				printf("\033[1;32m■\033[0m");
			}
			if (get_map_value (map, i, j) == 5){
				//printf("B");
				printf("\033[1;34m■\033[0m");
			}
			if (get_map_value (map, i, j) == 6){
				//printf("Y");
				printf("\033[1;33m■\033[0m");
			}
			if (get_map_value (map, i, j) == 7){
				//printf("M");
				printf("\033[1;35m■\033[0m");
			}
			if (get_map_value (map, i, j) == 8){
				//printf("C");
				printf("\033[1;36m■\033[0m");
			}
			if (get_map_value (map, i, j) == 9){
				//printf("W");
				printf("\033[1;37m■\033[0m");
			}
		}
		printf("\n");
	}
}