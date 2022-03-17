//
// Created by Alexandra on 6/21/2021.
//

#pragma once
#include <vector>
#include <string>
using namespace std;
#include <sstream>
#include <fstream>

class ScreenWriter {

private:
    string name;
    string expertise;

public:
    ScreenWriter();
    ScreenWriter(string name, string expertise);
    ~ScreenWriter();

    string getName();
    string getExpertise();

    friend istream& operator>>(istream&, ScreenWriter&);

};
