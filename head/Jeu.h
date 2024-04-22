#include "../head/map.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h> //Afin d'utiliser la fonction floor
#include <string.h> //Afin d'utiliser la fonction strcmp pour comparer des chaînes de caractères
#include <time.h> //Afin d'initialiser la fonction rand 

void print_map(Map* map); 

void update_map(Map* map, Color value, int player);

int game_finished(Map* map);

int couleur_indice(char couleur, char* tableau);
