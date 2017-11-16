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
    
    //A faire
    
    
    int x,y;
    int max;
    int** table;
    
    image imagePGM(x,y,max,table);
    
    return imagePGM.GetTable();
}
