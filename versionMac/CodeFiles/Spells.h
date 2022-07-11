//
//  Spells.h
//  ConsoleNaruto001Mac
//
//  Created by Quentin Dupont on 04/07/2022.
//

#ifndef Spells_h
#define Spells_h
#pragma once
#include <string>
#include <vector>
#include <map>
#include "StringFunctions.h"
using namespace std;

const vector<string> ElementList = {"fire","wind","earth","water","lightning"};
const vector<string> ClassList = {"ninjutsu","taijutsu","genjutsu"};
const vector<string> SpecialClassList = {"unique","bloodline","secret","hermit","gene","seals","none"};
const vector<string> TypeList = {"attack","defense","supplementary"};
const vector<string> Parameters = {"id","name","expl","element","class","special class","type","effect","cost","range","value"};

class Spell
{
protected:
    string _spellName, _spellEffectText, _spellElement, _spellClass, _spellSpecialClass, _spellType;
    vector<string> _spellEffect;
    int _spellRange, _spellId;
    vector<int> _spellCost, _spellValues;
    bool _isUsable;
    
public:
    Spell(int spellId, string spellName = "Name", string spellEffectText = "Deals $0", string spellElement = "Element", string spellClass = "Class", string spellSpecialClass = "None", string spellType = "Type", vector<string> spellEffect = {"Effect1","Effect2"}, vector<int> spellCost = {1,0}, int spellRange = 2, vector<int> spellValues = {10}){
        _spellId = spellId;
        _spellName = spellName;
        _spellElement = updateSpellElement(spellElement);
        _spellClass = updateSpellClass(spellClass);
        _spellSpecialClass = updateSpellSpecialClass(spellSpecialClass);
        _spellType = updateSpellType(spellType);
        _spellValues = spellValues;
        _spellEffectText = updateSpellEffectText(spellEffectText, _spellType,_spellValues);
        _spellEffect = spellEffect;
        _spellCost = spellCost;
        _spellRange = spellRange;
        _isUsable = updateUsability();
    };
    
    bool updateUsability(){
        if (_spellElement == "error") {
            return false;
        }
        else if (_spellType == "error") {
            return false;
        }
        else if (_spellClass == "error") {
            return false;
        }
        else if (_spellSpecialClass == "error") {
            return false;
        }
        else {
            return true;
        }
    }
    
    string updateSpellClass(string text) {
        text = to_Lower(text);
        bool error = true;
        for (int x = 0; x < ClassList.size();x++) {
            if (text.find(ClassList.at(x)) != string::npos) {
                text = ClassList.at(x);
                error = !error;
                break;
            }
        }
        if (error) { return "error"; }
        else { return text; }
    };
    
    string updateSpellSpecialClass(string text) {
        text = to_Lower(text);
        bool error = true;
        for (int x = 0; x < SpecialClassList.size();x++) {
            if (text.find(SpecialClassList.at(x)) != string::npos) {
                text = SpecialClassList.at(x);
                error = !error;
                break;
            }
        }
        if (error) { return "error"; }
        else { return text; }
    };
    
    string updateSpellType(string text) {
        text = to_Lower(text);
        bool error = true;
        for (int x = 0; x < TypeList.size();x++) {
            if (text.find(TypeList.at(x)) != string::npos) {
                text = TypeList.at(x);
                error = !error;
                break;
            }
        }
        if (error) { return "error"; }
        else { return text; }
    };
    
    string updateSpellElement(string text) {
        text = to_Lower(text);
        bool error = true;
        for (int x = 0; x < ElementList.size();x++) {
            if (text.find(ElementList.at(x)) != string::npos) {
                text = ElementList.at(x);
                error = !error;
                break;
            }
        }
        if (error) { return "error"; }
        else { return text; }
    };
    
    string updateSpellEffectText(string text, string type, vector<int> tab){
        for (int x = 0; x < text.length(); x++) {
            if (text[x] == '$') {
                if (x <= text.length()-1) {
                    text.replace(x,2,to_string(tab.at(text.at(x+1)-'0')));
                }
            }
        }
        return text;
    };
    
    int getSpellId(){
        return _spellId;
    }
    
    string getSpellName(){
        return _spellName;
    };
    
    string getSpellEffectText(){
        return _spellEffectText;
    };
    
    string getSpellElement(){
        return _spellElement;
    }
    
    string getSpellClass(){
        return _spellClass;
    }
    
    string getSpellSpecialClass(){
        return _spellSpecialClass;
    }
    
    string getSpellType(){
        return _spellType;
    }
    
    bool getUsability() {
        return _isUsable;
    }
    
    void showAll(){
        cout << "Name : " << to_Stylish(_spellName) << endl;
        cout << "Effect text : " << to_Stylish(_spellEffectText) << endl;
        cout << "Class : " << to_Stylish(_spellClass) << endl;
        cout << "Special class : " << to_Stylish(_spellSpecialClass) << endl;
        cout << "Type : " << to_Stylish(_spellType) << endl;
        cout << "Element : " << to_Stylish(_spellElement) << endl;
    }
};

class SpellList {
protected:
    map<int,Spell> _listOfSpell;
public:
    SpellList(){
    }
    
    void addSpell(Spell spell) {
        bool exists = false;
        for (int x = 0; x < _listOfSpell.size(); x++) {
            if (_listOfSpell.at(x).getSpellId() == spell.getSpellId()) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            _listOfSpell.insert(pair<int,Spell>(spell.getSpellId(),spell));
        }
    }
    
    void addSpells(vector<int> id, SpellList spellList) {
        for (int x = 0; x < id.size(); x++) {
            _listOfSpell.insert(pair<int,Spell>(spellList.getListOfSpell().at(id[x]).getSpellId(),spellList.getListOfSpell().at(id[x])));        }
    }
    
    Spell getSpellOfList(int index) {
        return _listOfSpell.at(index);
    }
    
    map<int,Spell> getListOfSpell() {
        return _listOfSpell;
    }
    
    void showAll() {
        for (int x = 0; x < _listOfSpell.size(); x++) {
            if (_listOfSpell.at(x).getUsability()) {
                cout << x << " - " << to_Stylish(_listOfSpell.at(x).getSpellName()) << " - " << to_Stylish(_listOfSpell.at(x).getSpellType()) << " - " << to_Stylish(_listOfSpell.at(x).getSpellClass()) << endl;
            }
        }
    }
};
#endif /* Spells_h */
