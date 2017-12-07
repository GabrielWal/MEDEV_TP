//
//  read.cpp
//  Netbeans
//
//  Created by Yongze on 2017/11/16.
//  Copyright © 2017年 Yongze. All rights reserved.
//

#include <iostream>
#include "histogramme.h"

Image Image::histogramme(){
    int tableauHisto[this->max+1] = {0};
    
    //count number of pixels in each gray level
    for(int i=0; i<this->y; i++){
        for (int j=0; j<this->x; j++) {
            tableauHisto[this->table[i][j]]++;
        }
    }

    
    //find new y i.e. maximum in tableauHisto[]
    int maximum=0;
    for(int i=0; i<this->max+1; i++){
        if(tableauHisto[i]>=maximum){
            maximum=tableauHisto[i];
        }
    }

    // Create new image that will hold histogram
    Image newImage = Image(this->max+1, maximum, 9);

    for(int i=0; i<this->max+1; i++){
        for(int j=0; j<maximum; j++){
            int pixelValue = (j<maximum-tableauHisto[i])?0:9;
            newImage.SetTableElement(i,j,pixelValue);
            cout << i << " " << j << " " << pixelValue << " " << newImage.GetTable()[i][j] << endl;
        }
    }
    cout << newImage.GetX() << " " << newImage.GetY() << endl;
    for(int i=0; i<newImage.GetX(); i++){
        for(int j=0; j<newImage.GetY(); j++){
            cout << i << " " << j << " " << newImage.GetTable()[i][j] << endl;
        }
    }
    newImage.createPGM("histo.pgm");
    return newImage;
}

void Image::createPGM(char const* filename){
    ofstream filePGM (filename);
    if(filePGM.is_open()){
        filePGM<<"P2"<<endl<<"#No comment"<<endl<<x<<" "<<y<<endl;
        filePGM<<9<<endl;
        for(int i=0; i<this->y; i++){
            for(int j=0; j<this->x; j++){
                filePGM<<this->table[j][i]<<" ";
            }
            filePGM<<endl;
        }
    }
    filePGM.close();
    return;
}
