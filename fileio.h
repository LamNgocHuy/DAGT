#include "vattu.h"
#include "MyString.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

// Trim space at start, end
string removeSpaceSE(string s)
{
    int i = 0;
    int start = 0, end = s.length();
    while (i < s.length()) {
        if (s.substr(i,1) == " ") {
            start++;
        } else {
            break;
        }
        i++;
    }
    i = s.length();
    while (i > 0) {
        if (s.substr(i-1,1) == " ") {
            end--;
        } else {
            break;
        }
        i--;
    }
    if (start == s.length()) return "null";
    return s.substr(start, end-start);
}

int numberOfLines() {
    ifstream myfile("dsvt.txt");
    string line;
    int number_of_lines = 0;

    if(myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile,line);
            number_of_lines++;
        }
        myfile.close();
    }
    number_of_lines--;
    return number_of_lines;
}

void readGoodsFromFile(vattu* dsvt, int size) {
    ifstream filein;
    filein.open("dsvt.txt");
    for (int i = 0; i < size; i++) {
        vattu vt;
        string in;

        getline(filein, in, '|');
        vt.mvt = removeSpaceSE(in);

        getline(filein, in, '|');
        vt.ten = removeSpaceSE(in);

        getline(filein, in, '|');
        vt.loai = removeSpaceSE(in);

        getline(filein, in, '|');
        vt.DV = removeSpaceSE(in);

        getline(filein, in, '|');
        vt.ngay = convertStringToInt(in);

        getline(filein, in, '|');
        vt.thang = convertStringToInt(in);

        getline(filein, in, '|');
        vt.nam = convertStringToInt(in);

        getline(filein, in, '|');
        vt.nsx = removeSpaceSE(in);

        getline(filein, in, '|');
        vt.sl = convertStringToInt(in);

        getline(filein, in);
        vt.DG = convertStringToInt(in);

        dsvt[i] = vt;
    }
    filein.close();
}

void writeGoodsToFile(vattu* dsvt, int size) {
    fstream fileout;
    fileout.open("dsvt.txt", ios::out);
    for (int i = 0; i < size; i++)
    {
        (dsvt+i)->mvt = removeSpaceSE((dsvt+i)->mvt );
        (dsvt+i)->ten = removeSpaceSE((dsvt+i)->ten );
        (dsvt+i)->loai = removeSpaceSE((dsvt+i)->loai);
        (dsvt+i)->DV = removeSpaceSE((dsvt+i)->DV ) ;
        (dsvt+i)->nsx = removeSpaceSE((dsvt+i)->nsx) ;
        fileout 
            << (dsvt+i)->mvt  << " | " 
            << (dsvt+i)->ten  << " | " 
            << (dsvt+i)->loai << " | "
            << (dsvt+i)->DV   << " | " 
            << (dsvt+i)->ngay << " | " 
            << (dsvt+i)->thang<< " | "
            << (dsvt+i)->nam  << " | " 
            << (dsvt+i)->nsx  << " | " 
            << (dsvt+i)->sl   << " | " 
            << (dsvt+i)->DG   << endl;
    }
    fileout.close();
}

