#ifndef DAMES_H
#define DAMES_H

#define N 10

#include "pion.h"
#include <vector>

using namespace std;

typedef struct coord {
	int x,y,index;
} coord;

class Dames { // classe définissant un plateau de jeu de dames
private:
	int plateau[N][N]; // plateau de jeu
	vector<Pion> pions; // liste des pions
public:
	Dames(); // Constructeur
	void disp() const; // Affiche plateau
	vector<coord> deplacements_possibles(); // liste de déplacements possibles
};

#endif