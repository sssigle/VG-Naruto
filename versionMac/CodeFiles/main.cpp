//
//  main.cpp
//  ConsoleNaruto001Mac
//
//  Created by Quentin Dupont on 04/07/2022.
//

#include <iostream>
#include "Spells.h"
#include "Body.h"
#include "StringFunctions.h"
#include "FileFunctions.h"
#include <map>
using namespace std;

const string lien = "/Users/quentindupont/XCodeProjects/Projet Mac/ConsoleNaruto001Mac/ConsoleNaruto001Mac/SpellData2.txt";
const string lienData = "/Users/quentindupont/XCodeProjects/Projet Mac/ConsoleNaruto001Mac/ConsoleNaruto001Mac/spellData.txt";


int main() {
    Spell testS(0,"fire release : firebalL","Deals $0 damage and then $1 damage.","FIRE","NInjutsu","HERmit","Attack",{"Hit"},{1,0},5,{20,10});
    Body testB({"sharingan","none"});
    SpellList testL;
    testL.addSpell(testS);
    testL.addSpell(testS);
    //testS.showAll();
    //testB.showAll();
    //testL.showAll();
    map<int,vector<string>> testMA = readFile(lien);
    readFileData(lienData);
    return 0;
}
    
