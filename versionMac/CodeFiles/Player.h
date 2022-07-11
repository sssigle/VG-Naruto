//
//  Player.h
//  ConsoleNaruto001Mac
//
//  Created by Quentin Dupont on 06/07/2022.
//

#ifndef Player_h
#define Player_h
#pragma once
#include "Body.h"
#include "Spell.h"
using namespace std;

class Player{
protected:
    Body _playerBody;
    SpellList _playerSpells;
public:
    Player(Body playerBody, vector<) {
        _playerBody = playerBody;
        _playerSpells = playerSpells;
    }
    
};

#endif /* Player_h */
