/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   image.h
 * Author: walbrongabriel
 *
 * Created on November 16, 2017, 11:36 AM
 */
#include <vector>
#include <iostream>
using namespace std;
#ifndef IMAGE_H
#define IMAGE_H
class Image{
private:
    //x,y dimensiosn
    int x;
    int y;
    //max grey
    int max;
    //pixel table
    int** table;

public:
    Image() {
        this->x = 0;
        this->y = 0;
        this->max = 0;
    }
    
    Image(const char* filepath);
    
    Image(int x, int y, int max, int** table) :
    x(x), y(y), max(max), table(table) {
    }
    
    Image(Image const& im);

    Image(int x, int y, int max);
    
    // ~Image(){
    //     for(int i=0; i<this->y;i++){
    //         delete this->table[i];
    //     }
    //     delete this->table;   
    // }
    
    int GetMax() const {
        return max;
    }

    void SetMax(int max) {
        this->max = max;
    }

    int** GetTable() const {
        return table;
    }

    void SetTable(int** table);

    void SetTableElement(int i, int j, int e) {
        this->table[i][j] = e;
    }

    int GetX() const {
        return x;
    }

    void SetX(int x) {
        this->x = x;
    }

    int GetY() const {
        return y;
    }

    void SetY(int y) {
        this->y = y;
    }
    //Parse from file 
    void parse(const char* filepath);
    //Only print histogramme
    Image histogramme();
    //Print and create PGM histogramme
    void createPGM(char const* filename);
    
    Image seuillage(int seuil);
};


#endif /* IMAGE_H */

