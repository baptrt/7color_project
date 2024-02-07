#include "../head/map.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>



/*
	maVariable  =  valeur de ma variable
	&maVariable   =  adresse de la variable
	*monPointeur  =  valeur de la variable pointee
	monPointeur = adresse de la variable pointée
	
	int Mateo = 5;
	int* a = &Mateo;
	print(a) --> 4 rue de Roumanie
	print(*a) = 5;
	print(&Mateo) = 4 rue de Roumanie

	*a = 4;
	print(Mateo) = 4
	print(&a) =  11 avenue Robert Schumann


	void changement(int* pointeurdelavariable, int valeurDuChangement)
	{
		*pointeurdelavariable = valeurDuChangement;

	}

	Mateo = changement(Mateo, 4);
*/
Map map = {.map = NULL, .size = 0};

//Question 1 : 
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
	srand(time(NULL));
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
void update_map(Map* map);

int main(int argc, char** argv){
	create_empty_map(&map, 10);
	fill_map(&map);
	print_map(&map);
}

//Question 2 : Affichage dans le terminal de l'état actuel de la partie avec des lettres
/*
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
				printf("R");
			}
			if (get_map_value (map, i, j) == 4){
				printf("G");
			}
			if (get_map_value (map, i, j) == 5){
				printf("B");
			}
			if (get_map_value (map, i, j) == 6){
				printf("Y");
			}
			if (get_map_value (map, i, j) == 7){
				printf("M");
			}
			if (get_map_value (map, i, j) == 8){
				printf("C");
			}
			if (get_map_value (map, i, j) == 9){
				printf("W");
			}
		}
		printf("\n");
	}
}
*/

//Question 2 : Affichage dans le terminal de l'état actuel de la partie en couleur
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
				printf("\033[1;31m■\033[0m");
			}
			if (get_map_value (map, i, j) == 4){
				printf("\033[1;32m■\033[0m");
			}
			if (get_map_value (map, i, j) == 5){
				printf("\033[1;34m■\033[0m");
			}
			if (get_map_value (map, i, j) == 6){
				printf("\033[1;33m■\033[0m");
			}
			if (get_map_value (map, i, j) == 7){
				printf("\033[1;35m■\033[0m");
			}
			if (get_map_value (map, i, j) == 8){
				printf("\033[1;36m■\033[0m");
			}
			if (get_map_value (map, i, j) == 9){
				printf("\033[1;37m■\033[0m");
			}
		}
		printf("\n");
	}
}

//Question 3 : 
void update_map(Map* map){

 	for (int i = 0; i < map -> size; i++){
		for (int j = 0; j < map -> size; j++){
			
		}
	
}
}