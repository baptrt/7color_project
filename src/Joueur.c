#include "../head/Affichage.h"
#include "../head/map.h"
#include "../head/Jeu.h"

//Joueur qui joue au hasard

int player_random(){
	return (rand()%7 + 3);
}

//Joueur glouton

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

//Joueur intelligent v

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

int player_super_smart(Map* map, int player){
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
                if (get_map_value(&temp_map, i, j) == player) {
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