#include "../head/map.h"
#include "../head/Jeu.h"
#include "../head/Affichage.h"
#include "../head/Joueur.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h> //Afin d'utiliser la fonction floor
#include <string.h> //Afin d'utiliser la fonction strcmp pour comparer des chaînes de caractères
#include <time.h> //Afin d'initialiser la fonction rand 

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

//Tentative de jouer avec les couleurs
/*
int main1(int argc, char** argv){
	char tableau_couleur = {"RED", "GREEN", "BLUE", "YELLOW", "MAGENTA", "CYAN", "WHITE"};
	char n;
	int k = 1;

	create_empty_map(&map, 10);
	fill_map(&map);
	print_map(&map);

	printf("Joueur 1 quelle couleur choisis-tu? ");
	scanf("%s",&n);
	update_map(&map, couleur_indice(n, &tableau_couleur), 1);
	print_map(&map);

}
*/

//MAIN (Question 5)

/*
int main2(int argc, char** argv){
	int n;
	create_empty_map(&map, 2);
	fill_map(&map);
	print_map(&map);

while(game_finished(&map) == 0){
	printf("Joueur 1 quelle couleur choisis-tu? ");
	scanf("%d",&n);
	update_map(&map, n, 1);
	print_map(&map);

	printf("Joueur 2 quelle couleur choisis-tu? ");
	scanf("%d",&n);
	update_map(&map, n, 2);
	print_map(&map);
}
}
*/

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

/*
int main(int argc, char** argv){
	int n;
	create_empty_map(&map, 3);
	fill_map(&map);
	print_map(&map);

while(game_finished(&map) == 0){
	printf("%i", player_smart(&map, 1));
	printf("\n");

	update_map(&map, player_smart(&map, 1), 1);
	print_map(&map);

	printf("Joueur 2 quelle couleur choisis-tu? ");
	scanf("%d",&n);
	update_map(&map, n, 2);
	print_map(&map);
}
}
*/


/*
int main(int argc, char** argv){
	int n;
	create_empty_map(&map, 10);
	fill_map(&map);
	print_map(&map);

while(game_finished(&map) == 0){
	printf("Joueur 1 quelle couleur choisis-tu? ");
	scanf("%d",&n);
	update_map(&map, n, 1);
	print_map(&map);

	printf("%i", player_super_smart(&map, 2));
	printf("\n");

	update_map(&map, player_super_smart(&map, 2), 2);
	print_map(&map);

}
}
*/

