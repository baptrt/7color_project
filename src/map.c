#include "../head/map.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h> //Afin d'utiliser la fonction floor
#include <string.h> //Afin d'utiliser la fonction strcmp pour comparer des chaînes de caractères
#include <time.h> //Afin d'initialiser la fonction rand 

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
void update_map(Map* map, Color value, int player);
int* compteur(Map* map);
int game_finished(Map* map);

int couleur_indice(char couleur, char* tableau){
	int k = 0;
	for (int i = 0; i < sizeof(tableau); i++){
		if (strcmp(&tableau[i], &couleur) == 0){
			k = i;
		}
	}
	return k;
}

//Tentative de jouer avec les couleurs
/*
int main(int argc, char** argv){
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
int main(int argc, char** argv){
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
	printf("\n");
}

//Question 3 : 

void update_map(Map* map, Color value, int player){
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


//Question 4 : Fin de partie

int game_finished(Map* map){
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
		printf("Le joueur 1 a gagné");
		return 1;
	}
	if (player2 >= floor((map -> size) * (map -> size))/2){
		printf("Le joueur 2 a gagné\n");
		return 1;
	}
	else{
		return 0;
	}
}

//Question 6 : IA qui joue au hasard

int player_random(){
	srand(time(NULL));
	return (rand()%7 + 3);
}

//Question 7 : IA glouton 

int player_smart(Map* map, int player){
    int R = 0;
    int G = 0;
    int B = 0;
    int Y = 0;
    int M = 0;
    int C = 0;
    int W = 0;
    int L[7] = {R, G, B, Y, M, C, W};
    
    for (int i = 0; i < map -> size; i++){
        for (int j = 0; j < map -> size; j++){
            if (get_map_value(map, i, j) == player){
                if (i > 0){
                    L[get_map_value(map, i-1, j) - 3]++;
                }
                if (j > 0){
                    L[get_map_value(map, i, j-1) - 3]++;
                }
                if (j < map -> size - 1){
                    L[get_map_value(map, i, j+1) - 3]++;
                }
                if (i < map -> size - 1){
                    L[get_map_value(map, i+1, j) - 3]++;
                }
            }
        }
    }

    int a = 0; 
    int i = 0;
    while (a == 0){
        i = rand() % 7;
        a = L[i];
    }
    return i + 3;
}

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

//Question 8 :

Map copy_map(Map* map){
	Map copy = {.map = NULL, .size = 0};
	create_empty_map (&copy, map -> size);
	for (int i = 0; i < map -> size; i++){
		for (int j = 0; j < map -> size; j++){
			set_map_value(&copy, i, j, get_map_value(map, i, j));
		}
	}
	return copy;
}

int player_super_smart(Map* map, int player) {
    int R = 0;
    int G = 0;
    int B = 0;
    int Y = 0;
    int M = 0;
    int C = 0;
    int W = 0;
    int L[7] = {R, G, B, Y, M, C, W};
    int conteur = 0;

    for (int k = 0; k < sizeof(L) / sizeof(L[0]); k++) {
		Map temp_map = copy_map(map);
        update_map(&temp_map, k + 3, player); //Modifie la copie de la carte
        conteur = 0;
        for (int i = 0; i < temp_map.size; i++) {
            for (int j = 0; j < temp_map.size; j++) {
                if (get_map_value(&temp_map, i, j) == 1) {
                    conteur++;
                }
            }
        }
        L[k] = conteur;
    }

    int indice = 0;
    int max = L[0];

    for (int k = 1; k < sizeof(L) / sizeof(L[0]); k++) {
        if (max < L[k]) {
            max = L[k];
            indice = k;
        }
    }

    return (indice + 3);
}

int main(int argc, char** argv){
	int n;
	create_empty_map(&map, 10);
	fill_map(&map);
	print_map(&map);

while(game_finished(&map) == 0){
	printf("%i", player_super_smart(&map, 1));
	printf("\n");

	update_map(&map, player_super_smart(&map, 1), 1);
	print_map(&map);

	printf("Joueur 2 quelle couleur choisis-tu? ");
	scanf("%d",&n);
	update_map(&map, n, 2);
	print_map(&map);
}
}