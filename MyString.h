#pragma once
#include<iostream>
#include<string>
#include <sstream>
using namespace std;
#define LOW_A 97
#define LOW_Z 122

inline string To_upper(string word) {
    string upper;
    //Lower To Upper:
    for (int i = 0; i < word.length(); i++) {
        if (word.at(i) >= LOW_A && word.at(i) <= LOW_Z) {
            upper += (word.at(i) - 32);
        }
        else {
            upper += word.at(i);
        }
    }
    return upper;

}

inline int convertStringToInt(string str) {
    int resl;
    stringstream geek(str);
    geek >> resl;
    return resl;
    /*int l1 = str.length();
    int num = 0;
    for (int i = l1 - 1; i >= 0; --i) {
        num += (int)(str.at(i) - '0') * pow(10, l1 - i - 1);
    }
    return num;*/
}
