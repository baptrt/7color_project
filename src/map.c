#include "../head/map.h"
#include "../head/Jeu.h"
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

int main(int argc, char** argv){
	int i = 0;
	printf("En quel mode veux-tu jouer? \n");
	printf("0 - Afficher la map \n");
	printf("1 - Mode un contre un \n");
	printf("2 - Mode un contre IA \n");
	printf("3 - Mode affrontement d'IA \n");
	printf("4 - Mode statistique affrontement d'IA \n");
	scanf("%d",&i);

	if (i == 0){
		char tableau_couleur = {"RED", "GREEN", "BLUE", "YELLOW", "MAGENTA", "CYAN", "WHITE"};
		char n;
		int k = 1;

		create_empty_map(&map, 10);
		fill_map(&map);
		Gr7_print_map(&map);
	}

	if (i == 1){
		int n;
		create_empty_map(&map, 10);
		fill_map(&map);
		Gr7_print_map(&map);

		while(Gr7_game_finished(&map) == 0){
			printf("Joueur 1 quelle couleur choisis-tu? ");
			scanf("%d",&n);
			Gr7_update_map(&map, n, 1);
			Gr7_print_map(&map);

			printf("Joueur 2 quelle couleur choisis-tu? ");
			scanf("%d",&n);
			Gr7_update_map(&map, n, 2);
			Gr7_print_map(&map);
		}
}

	if (i == 2){
		int n;
		create_empty_map(&map, 10);
		fill_map(&map);
		Gr7_print_map(&map);

		while(Gr7_game_finished(&map) == 0){
			printf("Joueur 1 quelle couleur choisis-tu? ");
			scanf("%d",&n);
			Gr7_update_map(&map, n, 1);
			Gr7_print_map(&map);

			Gr7_update_map(&map, Gr7_player_random(), 2);
		}
		if (Gr7_game_finished(&map) == 1){
			printf("Bravo joueur 1 tu as gagné");
		}
		if (Gr7_game_finished(&map) == 2){
			printf("Bravo joueur 2 tu as gagné");
		}
	}

	if (i == 3){
		create_empty_map(&map, 10);
		fill_map(&map);

		while(Gr7_game_finished(&map) == 0){
			Gr7_update_map(&map, Gr7_player_random(), 1);

			Gr7_update_map(&map, Gr7_player_super_smart(&map, 2), 2);

			Gr7_print_map(&map);
		}

		if (Gr7_game_finished(&map) == 1){
			printf("Bravo joueur 1 tu as gagné");
		}
		if (Gr7_game_finished(&map) == 2){
			printf("Bravo joueur 2 tu as gagné");
		}
	}

	if (i ==  4){
		int compteur_1 = 0;
		int compteur_2 = 0;
		srand(time(NULL));

		for (int k = 0; k<500; k++){
			create_empty_map(&map, 15);
			fill_map(&map);
				while (Gr7_game_finished(&map) == 0){
					Gr7_update_map(&map, Gr7_player_super_smart(&map, 1), 1);
					Gr7_update_map(&map, Gr7_player_smart(&map, 2), 2);
				}
				if (Gr7_game_finished(&map) == 1){
					compteur_1++;
				}
				if (Gr7_game_finished(&map) == 2){
					compteur_2++;
				}
			}
		printf("Le joueur intelligent a gagné %i fois sur 500 parties", compteur_1);
		printf("\n");
		printf("Le joueur qui joue au hasard a gagné %i fois sur 500 parties", compteur_2);
	}
}

