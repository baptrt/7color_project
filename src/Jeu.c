#include "../head/map.h"
#include "../head/Jeu.h"

//Création de la map dans le terminal

void Gr7_print_map(Map* map){
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
	printf("\n");
}

//Récupération de l'indice associé à une couleur 

int Gr7_couleur_indice(char couleur, char* tableau){
	int k = 0;
	for (int i = 0; i < sizeof(tableau); i++){
		if (strcmp(&tableau[i], &couleur) == 0){
			k = i;
		}
	}
	return k;
}

//Mise à jour de la map 

void Gr7_update_map(Map* map, Color value, int player){
	int m = 1;
	while (m){
		m = 0;
		for (int i = 0; i < map->size; i++) {
       		for (int j = 0; j < map->size; j++) {
            	if (get_map_value(map, i, j) == player) {
					if ((i < map -> size - 1) && (get_map_value(map, i + 1, j) == value)){					
						set_map_value (map, i + 1, j, player);
						m = 1;
						}
					if ((j < map -> size - 1) && (get_map_value(map, i, j + 1) == value)){
						set_map_value (map, i, j + 1, player);
						m = 1;
						}
					if ((i > 0) && (get_map_value(map, i - 1, j) == value)){
						set_map_value (map, i - 1, j, player);
						m = 1;
						}
					if ((j > 0) && get_map_value(map, i, j - 1) == value){
						set_map_value (map, i, j - 1, player);
						m = 1;
					}
				}
			}
		}
	}
}

//Fin de partie 

int Gr7_game_finished(Map* map){
	int player1 = 0;
	int player2 = 0;
	for (int i = 0; i < map -> size; i++){
		for (int j = 0; j < map -> size; j++){
			if (get_map_value(map, i, j) == 1){
				player1 += 1; 
			}
			if (get_map_value(map, i, j) == 2){
				player2 += 1; 
			}
		}
	}
	if (player1 >= floor((map -> size) * (map -> size))/2){
		//printf("Le joueur 1 a gagné");
		return 1;
	}
	if (player2 >= floor((map -> size) * (map -> size))/2){
		//printf("Le joueur 2 a gagné");
		return 2;
	}
	else{
		return 0;
	}
}