//
//  read.cpp
//  Netbeans
//
//  Created by Yongze on 2017/11/16.
//  Copyright © 2017年 Yongze. All rights reserved.
//

#include "read.h"

int** imageToTable(std::string name){
    ifstream filePGM;
    filePGM.open(name, ios::in);
    
    string a;
    //A faire
    filePGM>>a;
    
    int x,y;
    int max;
    
    filePGM>>x>>y>>max;
    
    int** table=new int*;
    
    for(int i=0; i<x*y; i++){
        filePGM>>**(table+i);
    }
    
    image imagePGM(x,y,max,table);
    
    return imagePGM.GetTable();
}
