//
//  FileFunctions.h
//  ConsoleNaruto001Mac
//
//  Created by Quentin Dupont on 06/07/2022.
//

#ifndef FileFunctions_h
#define FileFunctions_h
#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "StringFunctions.h"
#include <map>
#include "Spells.h"
using namespace std;

int countLine(string link) {
    ifstream file (link, ios_base::in);
    int count = 0;
    string line;
    if(file.is_open()) {
        while (file.peek() != EOF) {
            getline(file, line);
            count++;
        }
    }
    file.close();
    return count;
}

map<int,vector<string>> readFile(string link) {
    string var,varT;
    size_t pos;
    vector<string> vec;
    int count = 0;
    map<int,vector<string>> ma;
    ifstream file (link, ios_base::in);
    while (file.peek() != EOF) {
        file >> var;
        if (var == "!") {
            ma.insert(pair<int,vector<string>>(count,vec));
            var.clear();
            vec.clear();
            count++;
            continue;
        }
        if (var[0] == '{') {
            var = var.substr(1,var.length());
            repeat:
            if ((pos = var.find('*')) != string::npos) {
                varT = var;
                var = var.substr(0,pos);
                vec.push_back(to_Whitespace(to_Lower(var)));
                var = varT.erase(0,int(varT.find('*')+1));
                if (var.find('*') != string::npos) {
                    goto repeat;
                }
            }
        }
        else {
            vec.push_back(to_Whitespace(to_Lower(var)));
        }
    }
    return ma;
}

void readFileData(string link) {
    size_t pos;
    map<string,vector<string>> ma = {};
    vector<string> vec;
    string line, var,varT,spellID;
    ifstream file (link, ios_base::in);
    while (file.peek() != EOF) {
        getline(file,line);
        if ((pos = line.find(" ")) != string::npos) {
            spellID = line.substr(0,pos);
            line.erase(0,pos);
            if (spellID.size() != 4) {
                spellID.clear();
                break;
            }
            else {
                if (ma.find(spellID) == ma.end()) {
                    repeat1:
                    pos = line.find(" ");
                    var = line.substr(0,pos);
                    vec.push_back(var);
                    line.erase(0,pos);
                    if (line.size() <= 3) {
                        goto stop1;
                    }
                    else {
                        goto repeat1;
                    }
                    stop1:
                    ma.insert(pair<string,vector<string>>(spellID,vec));
                }
                else {
                    repeat2:
                    pos = line.find(" ");
                    var = line.substr(0,pos);
                    vec.push_back(var);
                    line.erase(0,pos);
                    if (line.size() <= 2) {
                        goto stop2;
                    }
                    else {
                        goto repeat2;
                    }
                    stop2:
                    ma.at(spellID).clear();
                    ma.at(spellID) = vec;
                    cout << ma.at(spellID).at(0) << endl;
                }
            }
        }
    }
}

#endif /* FileFunctions_h */

/*Renvoie tableau de lignes
 map<int,vector<string>> readFile(string link) {
     string var,varT;
     size_t pos;
     vector<string> vec;
     int count = 0;
     map<int,vector<string>> ma;
     ifstream file (link, ios_base::in);
     while (file.peek() != EOF) {
         file >> var;
         cout << "VARIABLE = "<< var << endl;
         if (var == "!") {
             ma.insert(pair<int,vector<string>>(count,vec));
             var.clear();
             vec.clear();
             count++;
             continue;
         }
         if (var[0] == '{') {
             var = var.substr(1,var.length());
             repeat:
             if ((pos = var.find('*')) != string::npos) {
                 varT = var;
                 var = var.substr(0,pos);
                 vec.push_back(to_Whitespace(to_Lower(var)));
                 var = varT.erase(0,int(varT.find('*')+1));
                 if (var.find('*') != string::npos) {
                     goto repeat;
                 }
             }
         }
         else {
             vec.push_back(to_Whitespace(to_Lower(var)));
             continue;
         }
     }
     return ma;
 }
 */
