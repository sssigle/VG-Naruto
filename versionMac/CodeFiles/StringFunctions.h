//
//  StringFunctions.h
//  ConsoleNaruto001Mac
//
//  Created by Quentin Dupont on 04/07/2022.
//

#ifndef StringFunctions_h
#define StringFunctions_h
#pragma once
#include <string>
#include <iostream>
#include <cctype>
using namespace std;

string to_Lower(string text) {
    string final = "";
    for (int x = 0; x < text.size(); x++) {
        final += char(tolower(text[x]));
    }
    text = final;
    return text;
};

string to_Upper(string text) {
    string final = "";
    for (int x = 0; x < text.size(); x++) {
        final += char(toupper(text[x]));
    }
    text = final;
    return text;
};

string to_Stylish(string text) {
    string final = "";
    for (int x = 0; x < text.size(); x++) {
        if (x == 0) {
            final += char(toupper(text[x]));
        }
        else {
            final += char(tolower(text[x]));
        }
    }
    text = final;
    return text;
}

string to_Whitespace(string text) {
    string final = "";
    for (int x = 0; x < text.size(); x++) {
        if (text[x] == '_') {
            final += ' ';
        }
        else {
            final += char(tolower(text[x]));
        }
    }
    text = final;
    return text;
}
#endif /* StringFunctions_h */
