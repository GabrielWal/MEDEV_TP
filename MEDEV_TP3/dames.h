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
	bool deplacement(int x, int y, int u, int v); // deplacement du pion (i,j) en (u,v)
	int getIndex(int x, int y) const; // retourne l'index correspondant au pion (x,y)
	// vector< vector<coord> > Dames::prises_possibles(int x, int y); // liste des prises possibles depuis la position (x,y)
	// bool Dames::prise(int x, int y, int u, int v);
};

#endif