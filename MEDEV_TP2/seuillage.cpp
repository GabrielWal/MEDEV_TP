/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "image.h"
#include "seuillage.h"
#include <iostream>

Image Image::seuillage(int seuil){
    Image newImage = Image(*this);
    for(int i=0; i<this->y;i++){
        for(int j=0; j<this->x;j++){
            newImage.SetTableElement(i,j,(this->table[i][j] <= seuil)?0:1);
        }
    }
    newImage.createPGM("seuillage.pgm");
    return newImage;
}