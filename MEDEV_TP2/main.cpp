/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: walbrongabriel
 *
 * Created on November 16, 2017, 11:10 AM
 */

#include <cstdlib>
#include <iostream>
#include "image.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Image im = Image("exemple.pgm");
    // Image seuillage = im.seuillage(3); // ça marche
    Image histogramme = im.histogramme();
    return 0;
}

