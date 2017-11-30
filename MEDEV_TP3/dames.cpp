#include "dames.h"
#include <iostream>
#include "pion.h"
#include <vector>

using namespace std;

Dames::Dames() {
	// On initialise les pions de deux joueurs (20 pions chacun au départ)
	for (int i=0; i<2; i++) {
		for (int j=0; j<20; j++) {
			pions.push_back(Pion((i==0)?false:true));
		}
	}

	// On initialise les coordonnées et le plateau
	int cnt = 0;
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			if (j<4 && (i+j)%2) { // pions blancs
				pions[cnt].setPosition(i,j);
				cnt++;
				plateau[i][j] = 1;
			}
			else if (j>5 && (i+j)%2) {
				pions[cnt].setPosition(i,j);
				cnt++;
				plateau[i][j] = 1;
			}
			else { plateau[i][j] = 0; }
		}
	}
}

vector<coord> Dames::deplacements_possibles() {
	// Liste des déplacements possibles de tous les pions
	// On renvoie une liste de coordonnées (on associe à chaque coord l'index du pion concerné)
	vector<coord> deplacements;
	for (int i=0; i<pions.size(); i++) {
		coord move;
		move.x = pions[i].getX();
		move.y = pions[i].getY();
		move.index = i;
		if (move.x-1>0 && move.y-1>0 && plateau[move.x-1,move.y-1]==0) {
			coord newMove;
			newMove.x = move.x-1;
			newMove.y = move.y-1;
			newMove.index = move.i;
			deplacements.push_back(newMove);
		}
		if (move.x-1>0 && move.y+1<N && plateau[move.x-1,move.y+1]==0) {
			coord newMove;
			newMove.x = move.x-1;
			newMove.y = move.y+1;
			newMove.index = move.i;
			deplacements.push_back(newMove);
		}
		if (move.x+1<N && move.y-1>0 && plateau[move.x+1,move.y-1]==0) {
			coord newMove;
			newMove.x = move.x+1;
			newMove.y = move.y-1;
			newMove.index = move.i;
			deplacements.push_back(newMove);
		}
		if (move.x+1<N && move.y+1<N && plateau[move.x+1,move.y+1]==0) {
			coord newMove;
			newMove.x = move.x+1;
			newMove.y = move.y+1;
			newMove.index = move.i;
			deplacements.push_back(newMove);
		}
	}
	return deplacements;
}
