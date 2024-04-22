7color : o/map.o o/affichage.o o/jeu.o o/joueur.o
	gcc $(FLAGS) o/map.o o/affichage.o o/jeu.o o/joueur.o -o 7color

o/map.o: head/map.h src/map.c
	gcc $(FLAGS) -c src/map.c -o o/map.o

o/affichage.o: head/Affichage.h head/map.h src/Affichage.c
	gcc $(FLAGS) -c src/Affichage.c -o o/affichage.o

o/jeu.o: head/Jeu.h head/map.h src/Jeu.c
	gcc $(FLAGS) -c src/Jeu.c -o o/jeu.o

o/joueur.o: head/Joueur.h head/map.h src/Joueur.c
	gcc $(FLAGS) -c src/Joueur.c -o o/joueur.o
