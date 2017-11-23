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
    for(int i=0; i<x*y; i++){
        tableauHisto[**(table+i)]++;
    }
    
    //find new y i.e. maximum in tableauhisto[]
    int maximum=0;
    for(int i=0; i<max; i++){
        if(tableauHisto[i]>=maximum){
            maximum=tableauHisto[i];
        }
    }
    
    int new_table[max][maximum];
    
    for(int i=0; i<max; i++){
        for(int j=0; j<maximum; j++){
            new_table[i][j]=(j<=maximum-tableauHisto[i])?1:0;
        }
    }
    Image newImage = Image(max,maximum,1,(int**)new_table);
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
                cout << this->table[i][j] <<endl;
                filePGM<<this->table[i][j]<<" ";
            }
            filePGM<<endl;
        }
    }
    filePGM.close();
    return;
}
