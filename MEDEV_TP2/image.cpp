/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "image.h"
#include <fstream>
#include <string>
#include <sstream>
#include "stdlib.h"

vector<string> split(const string& line, char c);

void image::parse(const char* filepath){
    ifstream file (filepath);
    string line;
    int stage = 1;
    if (file.is_open()){
        while(getline(file,line)){
            while(line[0]=='P' || line[0]=='#'){
                getline(file,line);  
            }
            if(stage==1){
                vector<string> v = split(line,' ');
                this->x = atoi(v[0].c_str());
                this->y = atoi(v[1].c_str());
            } else if(stage==2){
                vector<string> v = split(line,' ');
                this->max = atoi(v[0].c_str());
            } else {
                int pixelTable[this->x][this->y];
                
            }
        }
    }
}

vector<string> split(const string& line, char c){
    vector<string> v;
    stringstream ss(line);
    string item;
    while(getline(ss,item,c)){
        v.push_back(item);
    }
    return v;
}