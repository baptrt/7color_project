#include "../head/map.h"
#include <stdlib.h>
#include <stdio.h>

Map map = {.map = NULL, .size = 0};

void create_empty_map (Map* map, int size){
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
set_map_value(map, 0, map -> size, 1);
set_map_value(map, map -> size, 0, 2);
}

int main(int argc, char** argv){
}

void print_map(Map* map){
	for (int i = 0; i < map -> size; i++){
		for (int j = 0; j < map -> size; j++){
			printf("%c", map[i + j]);
		}
		printf("\n");
	}


}