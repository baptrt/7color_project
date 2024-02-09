#include "../head/map.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h> //Afin d'utiliser la fonction floor
#include <string.h> //Afin d'utiliser la fonction strcmp pour comparer des chaînes de caractères
#include <time.h> //Afin d'initialiser la fonction rand 



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

	printf("Joueur 2 quelle couleur choisis-tu? ");
	scanf("%d",&n);
	update_map(&map, n, 2);
	print_map(&map);
}
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
	printf("\n");
}

//Question 3 : 
void update_map(Map* map, Color value, int player){
	int m = 1;
	while (m == 1){
 	for (int i = 0; i < map -> size; i++){
		for (int j = 0; j < map -> size; j++){
			if (get_map_value(map, i, j) == player){
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
				else {
					m = 0;
				}
			}
		}	

}
}
}

//Question 4 : 

int game_finished(Map* map){
	int player1 = 0;
	int player2 = 0;
	int players[] = {player1, player2};
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
	if (players[0] >= floor((map -> size) * (map -> size))/2){
		printf("Le joueur 1 a gagné\n");
		return 1;
	}
	if (players[1] >= floor((map -> size) * (map -> size))/2){
		printf("Le joueur 2 a gagné\n");
		return 1;
	}
	else{
		return 0;
	}
}