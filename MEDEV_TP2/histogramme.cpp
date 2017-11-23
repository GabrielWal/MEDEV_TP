//
//  read.cpp
//  Netbeans
//
//  Created by Yongze on 2017/11/16.
//  Copyright © 2017年 Yongze. All rights reserved.
//

#include "histogramme.h"

void Image::histogramme(){
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
    
    this->SetX(max);
    this->SetY(maximum);
    this->SetMax(1);
    this->SetTable((int**)new_table);
    
    return;
}

void Image::createHisto(){
    
}
