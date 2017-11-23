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
    int tableauHisto[max+1];
    
    //count
    for(int i=0; i<this->y; i++){
        for (int j=0; j<this->x; j++) {
            tableauHisto[this->table[i][j]]++;
        }
    }

    
    //find new y i.e. maximum in tableauhisto[]
    int maximum=0;
    for(int i=0; i<this->max; i++){
        if(tableauHisto[i]>=maximum){
            maximum=tableauHisto[i];
        }
    }

    Image newImage = Image(this->max, maximum, this->max);
    
    for(int i=0; i<maximum; i++){
        for(int j=0; j<max; j++){
            newImage.SetTableElement(i,j,(j<=maximum-tableauHisto[i])?1:0);
        }
    }
    cout << "banana" << endl;
    newImage.createPGM("histo.pgm");
    return newImage;
}

void Image::createPGM(char const* filename){
    ofstream filePGM (filename);
    if(filePGM.is_open()){
        filePGM<<"P2"<<endl<<"#No comment"<<endl<<x<<" "<<y<<endl;
        filePGM<<max<<endl;
        for(int i=0; i<this->y; i++){
            for(int j=0; j<this->x; j++){
                filePGM<<this->table[i][j]<<" ";
            }
            filePGM<<endl;
        }
    }
    filePGM.close();
    return;
}
