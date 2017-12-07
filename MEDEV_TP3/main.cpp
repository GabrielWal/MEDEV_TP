#include "dames.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	Dames jeu = Dames(); // initialisation du jeu et du plateau
	vector<coord> deplacements = jeu.deplacements_possibles();
	jeu.disp();
	bool b = jeu.deplacement(0,3,1,4); // déplace (0,3) en (1,4)
	cout << "deplacement effectue : " << b << endl;
	jeu.disp();
	return 0;
}