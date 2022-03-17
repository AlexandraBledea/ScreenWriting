//
// Created by Alexandra on 6/21/2021.
//

#include "ScreenWritersRepo.h"

void ScreenWritersRepo::LoadData() {
    ifstream inFile("screenwriters.txt");
    ScreenWriter currentElement;
    this->screenWriters.clear();
    while(inFile >> currentElement){
        this->screenWriters.push_back(currentElement);
    }
    inFile.close();
}

ScreenWritersRepo::ScreenWritersRepo() {
    this->LoadData();
}

ScreenWritersRepo::~ScreenWritersRepo() {

}

vector<ScreenWriter> &ScreenWritersRepo::getScreenWriters() {
    return this->screenWriters;
}
