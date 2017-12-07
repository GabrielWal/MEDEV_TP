#include "dames.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	Dames jeu = Dames(); // initialisation du jeu et du plateau
	vector<coord> deplacements = jeu.deplacements_possibles();
	jeu.disp();
	return 0;
}