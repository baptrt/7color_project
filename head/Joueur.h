#include "../head/map.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h> //Afin d'utiliser la fonction floor
#include <string.h> //Afin d'utiliser la fonction strcmp pour comparer des chaînes de caractères
#include <time.h> //Afin d'initialiser la fonction rand 

int player_random();

int player_smart(Map* map, int player);

Map copy_map(Map* map);

int player_super_smart(Map* map, int player);