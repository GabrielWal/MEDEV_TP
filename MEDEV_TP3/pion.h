#ifndef PION_H
#define PION_H

using namespace std;

class Pion{
private:
	// true si le pion appartient au joueur blanc 
	// false si il appartient au joueur noir
	bool joueurBlanc;
	// stateDame = true si le pion est une dame
	// false sinon
	bool stateDame;
	// x,y sont les coordonnées du pion sur le plateau
	int x;
	int y;
public:
	Pion();
	Pion(bool joueurBlanc);
	Pion(int x, int y, bool joueurBlanc);
	bool getStateDame() const {return this->stateDame;}
	bool getJoueur() const {return this->joueurBlanc;}
	int getX() const {return this->x;}
	int getY() const {return this->y;}
	void setStateDame(bool newState) {this->stateDame = newState;}
	void setJoueur(bool joueur) {this->joueurBlanc = joueur;}
	void setX(int newX) {this->x = newX;}
	void setY(int newY) {this->y = newY;}
	void setPosition(int newX, int newY){
		this->x = newX;
		this->y = newY;
	}
};

#endif