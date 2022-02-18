// RandWeb.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Surfer.h"
using namespace std;

#define CMD_SEPARATOR ','
#define PARAM_SEPARATOR ';'

vector<string> cmdsarray;
vector<string> paramsarray;

void SplitArray(string src) {
    stringstream stream(src);
    string data;

    cmdsarray.clear();

    while (getline(stream, data, CMD_SEPARATOR)) {
        cmdsarray.push_back(data);
    }
}

void SplitParams(string src) {
    stringstream stream(src);
    string data;

    paramsarray.clear();

    while (getline(stream, data, PARAM_SEPARATOR)) {
        paramsarray.push_back(data);
    }
}

int main()
{
    vector<string> chars{ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0" };

    while (true) {
        string range;
        cout << "Enter link size values: ";
        cin >> range;

        SplitArray(range);
        if (cmdsarray.size() >= 4) {
            SplitParams(cmdsarray[3]);
        }

        string linkToOpen = "";
        
        if (cmdsarray.size() < 3)
            linkToOpen = Surfer::MakeLink(stoi(cmdsarray[0]), stoi(cmdsarray[1]), chars, "https://www.google.com/search?q=", paramsarray);
        else
            linkToOpen = Surfer::MakeLink(stoi(cmdsarray[0]), stoi(cmdsarray[1]), chars, cmdsarray[2], paramsarray);

        cout << "Opening " << linkToOpen << endl;
        Surfer::Surf(linkToOpen);
    }
}