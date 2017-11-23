/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "image.h"
#include "seuillage.h"

Image Image::seuillage(int seuil){
    Image newImage = Image(*this);
    int newTable[this->y][this->x];
    for(int i=0; i<this->y;i++){
        for(int j=0; j<this->x;j++){
            newTable[i][j] = (this->table[i][j] <= seuil)?0:1;
        }
    }
    newImage.SetTable((int**)newTable);
    newImage.createPGM("seuillage.pgm");
    return newImage;
}