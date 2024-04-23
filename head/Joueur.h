#include "../head/map.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h> //Afin d'utiliser la fonction floor
#include <string.h> //Afin d'utiliser la fonction strcmp pour comparer des chaînes de caractères
#include <time.h> //Afin d'initialiser la fonction rand 

int Gr7_player_random();

int Gr7_player_smart(Map* map, int player);

Map Gr7_copy_map(Map* map);

int Gr7_player_super_smart(Map* map, int player);