#include "../head/Affichage.h"
#include "../head/map.h"
#include "../head/Jeu.h"
#include "../head/Joueur.h"

Map map;

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
		print_map(&map);
	}

	if (i == 1){
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

	if (i == 2){
		int n;
		create_empty_map(&map, 10);
		fill_map(&map);
		print_map(&map);

		while(game_finished(&map) == 0){
			printf("Joueur 1 quelle couleur choisis-tu? ");
			scanf("%d",&n);
			update_map(&map, n, 1);
			print_map(&map);

			update_map(&map, player_random(), 2);
		}
		if (game_finished(&map) == 1){
			printf("Bravo joueur 1 tu as gagné");
		}
		if (game_finished(&map) == 2){
			printf("Bravo joueur 2 tu as gagné");
		}
	}

	if (i == 3){
		create_empty_map(&map, 10);
		fill_map(&map);

		while(game_finished(&map) == 0){
			update_map(&map, player_random(), 1);

			update_map(&map, player_super_smart(&map, 2), 2);

			print_map(&map);
		}

		if (game_finished(&map) == 1){
			printf("Bravo joueur 1 tu as gagné");
		}
		if (game_finished(&map) == 2){
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
				while (game_finished(&map) == 0){
					update_map(&map, player_super_smart(&map, 1), 1);
					update_map(&map, player_smart(&map, 2), 2);
				}
				if (game_finished(&map) == 1){
					print_map(&map);
					compteur_1++;
				}
				if (game_finished(&map) == 2){
					print_map(&map);
					compteur_2++;
				}
			}
		printf("Le joueur intelligent a gagné %i fois sur 500 parties", compteur_1);
		printf("\n");
		printf("Le joueur qui joue au hasard a gagné %i fois sur 500 parties", compteur_2);
	}
}

