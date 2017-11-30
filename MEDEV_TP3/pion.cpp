
#include pion.h

Pion::Pion(bool joueur){
	this->joueurBlanc = joueur;
}

Pion::Pion(int x, int y, bool joueur){
	this->x = x;
	this->y = y;
	this->joueurBlanc = joueur;
}