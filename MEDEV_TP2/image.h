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
using namespace std;
#ifndef IMAGE_H
#define IMAGE_H
class image{
private:
    //x,y dimensiosn
    int x;
    int y;
    //max grey
    int max;
    //pixel table
    int** table;

public:
    image() {
        
    }
    
    image(int x, int y, int max, int** table) :
    x(x), y(y), max(max), table(table) {
    }

    int GetMax() const {
        return max;
    }

    void SetMax(int max) {
        this->max = max;
    }

    int** GetTable() const {
        return table;
    }

    void SetTable(int** table) {
        this->table = table;
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
    void parse(string filepath);
    //Only print histogramme
    void histogramme();
    //Print and create PGM histogramme
    void createHisto();
    
};


#endif /* IMAGE_H */

