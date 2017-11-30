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
	int plateau[N][N];
	vector<Pion> pions; // liste des pions
public:
	Dames(); // Constructeur
	vector<coord> deplacements_possibles();
};

#endif