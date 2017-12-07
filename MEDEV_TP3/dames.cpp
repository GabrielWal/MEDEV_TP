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
			else if (j>5 && (i+j)%2) { // pions noirs
				pions[cnt].setPosition(i,j);
				cnt++;
				plateau[i][j] = 1;
			}
			else { plateau[i][j] = 0; }
		}
	}
}

void Dames::disp() const {
	// Affiche le plateau de jeu
	cout << "=====================" << endl << "  ";
	for (int i=-1; i<N; i++) {
		for (int j=-1; j<N; j++) {
			if (i==-1 && j>-1) {
				cout << j << " ";
			}
			if (j==-1 && i>-1) {
				cout << i << " ";
			}
			if (i>-1 && j>-1) {
				cout << plateau[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << "=====================" << endl;
}

coord fillCoord(int x, int y, int i) {
	// Fill a coord struct with the three arguments and return it
	coord move;
	move.x = x;
	move.y = y;
	move.index = i;
	return move;
}

vector<coord> Dames::deplacements_possibles() {
	// Liste des déplacements possibles de tous les pions
	// On renvoie une liste de coordonnées
	// (on associe à chaque coord l'index du pion concerné)
	vector<coord> deplacements;
	for (int i=0; i<pions.size(); i++) { // on parcourt tous les pions
		coord move = fillCoord(pions[i].getX(), pions[i].getY(), i);
		if (move.x-1>=0 && move.y-1>=0 && plateau[move.x-1][move.y-1]==0) {
			// si la case en haut à gauche est libre
			coord newMove = fillCoord(move.x-1, move.y-1, move.index);
			deplacements.push_back(newMove);
		}
		if (move.x-1>=0 && move.y+1<N && plateau[move.x-1][move.y+1]==0) {
			// si la case en bas à gauche est libre
			coord newMove = fillCoord(move.x-1, move.y+1, move.index);
			deplacements.push_back(newMove);
		}
		if (move.x+1<N && move.y-1>=0 && plateau[move.x+1][move.y-1]==0) {
			// si la case en haut à droite est libre
			coord newMove = fillCoord(move.x+1, move.y-1, move.index);
			deplacements.push_back(newMove);
		}
		if (move.x+1<N && move.y+1<N && plateau[move.x+1][move.y+1]==0) {
			// si la case en bas à droite est libre
			coord newMove = fillCoord(move.x+1, move.y+1, move.index);
			deplacements.push_back(newMove);
		}
	}
	return deplacements;
}

bool Dames::deplacement(int x, int y, int u, int v) {
	// Déplacement du pion (x,y) en (u,v)
	// Renvoi true si le déplacement a été possible, false sinon
	int pionIndex = -1;
	vector<coord> deplacements = deplacements_possibles(); // liste des déplacements possibles
	for (int i=0; i<pions.size(); i++) {
		// on recherche l'index du pion qu'on veut déplacer
		if (pions[i].getX() == x && pions[i].getY() == y) {
			pionIndex = i; // index trouvé !
		}
	}
	if (pionIndex == -1) {
		return false; // on a pas trouvé d'index pour ce pion
	}
	for (int i=0; i<deplacements.size(); i++) {
		// on recherche si le deplacement est possible
		if (deplacements[i].index == pionIndex && deplacements[i].x == u && deplacements[i].y == v) {
			// deplacement possible, on l'effectue sur le plateau :
			plateau[x][y] = 0;
			plateau[u][v] = 1;
			// puis on change les coordonnées du pion dans la liste des pions :
			pions[pionIndex].setPosition(u,v);
			return true;
		}
	}
	return false; // on n'a pas peu effectuer le déplacement demandé
}
