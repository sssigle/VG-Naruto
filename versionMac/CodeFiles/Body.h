//
//  Body.h
//  ConsoleNaruto001Mac
//
//  Created by Quentin Dupont on 04/07/2022.
//

#ifndef Body_h
#define Body_h
#pragma once
#include <string>
#include <vector>
using namespace std;
const vector<string> position = {"left","right"};
const vector<string> ability = {"sharingan","mangekyo sharingan","rinnegan","byakugan","rinne sharingan","none"};


class BodyPart {
protected:
    int _bpHealthMax;
public:
    BodyPart(int bpHealthMax = 1){
        _bpHealthMax = bpHealthMax;
    }
    
    int getHealth() {
        return _bpHealthMax;
    }
    
    
};

class BodyPartEye : public BodyPart {
protected:
    string _bpAbility;
public:
    BodyPartEye(int bpHealthMax = 1, string bpAbility = "none"):BodyPart(bpHealthMax){
        _bpAbility = bpAbility;
    }
    
    string getAbility() {
        return _bpAbility;
    }
};

class Body {
protected:
    const int _bodyEyeHealth = 1000;
    BodyPart _bodyArmLeft, _bodyArmRight, _bodyTorso, _bodyLegLeft, _bodyLegRight, _bodyHead;
    BodyPartEye _bodyEyeLeft, _bodyEyeRight;
public:
    Body(vector<string> dojustsuType = {"none","none"}, int bodyHeadHealth = 100, int bodyTorsoHealth = 300, int bodyLegHealth = 100, int bodyArmHealth = 75
         ){
        _bodyTorso = BodyPart(bodyTorsoHealth);
        _bodyArmLeft = BodyPart(bodyArmHealth);
        _bodyArmRight = BodyPart(bodyArmHealth);
        _bodyLegLeft = BodyPart(bodyLegHealth);
        _bodyLegRight = BodyPart(bodyLegHealth);
        _bodyHead = BodyPart(bodyHeadHealth);
        updateEyes(dojustsuType);
    }
    
    void updateEyes(vector<string> eyeAbility) {
        for (int x = 0; x < ability.size(); x++) {
            eyeAbility[0] = to_Lower(eyeAbility[0]);
            if (eyeAbility[0] == ability.at(x)) {
                _bodyEyeLeft = BodyPartEye(_bodyEyeHealth,ability.at(x));
                break;
            }
        }
        for (int x = 0; x < ability.size(); x++) {
            eyeAbility[1] = to_Lower(eyeAbility[1]);
            if (eyeAbility[1] == ability.at(x)) {
                _bodyEyeRight = BodyPartEye(_bodyEyeHealth,ability.at(x));
                break;
            }
        }
    }
    
    void showAll(){
        cout << "Head : " << _bodyHead.getHealth() << endl;
        cout << "Torso : " << _bodyTorso.getHealth() << endl;
        cout << "Arm left : " << _bodyArmLeft.getHealth() << endl;
        cout << "Arm right : " << _bodyArmRight.getHealth() << endl;
        cout << "Legs left : " << _bodyLegLeft.getHealth() << endl;
        cout << "Legs right : " << _bodyLegRight.getHealth() << endl;
        cout << "Eye left : " << _bodyEyeLeft.getHealth() << " "<< to_Stylish(_bodyEyeLeft.getAbility()) << endl;
        cout << "Eye right : " << _bodyEyeRight.getHealth() << " " << to_Stylish(_bodyEyeRight.getAbility()) << endl;
    }
};
#endif /* Body_h */
