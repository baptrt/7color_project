#ifndef MAP_H
#define MAP_H

typedef enum Color{
	ERROR = -1,
	EMPTY,
	PLAYER_1,
	PLAYER_2,
	RED,
	GREEN,
	BLUE,
	YELLOW,
	MAGENTA,
	CYAN,
	WHITE
}Color; 

typedef struct Map{
	Color* map;
	int size;
} Map;


void create_empty_map (Map* map, int size);

void set_map_value (Map* map, int x, int y, Color value);

Color get_map_value (Map* map, int x, int y);

void fill_map(Map* map);

int main(int argc, char** argv);

#endif