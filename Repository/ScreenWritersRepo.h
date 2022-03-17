//
// Created by Alexandra on 6/21/2021.
//

#pragma once
#include "ScreenWriter.h"

class ScreenWritersRepo {

private:
    vector<ScreenWriter> screenWriters;
    void LoadData();

public:

    ScreenWritersRepo();
    ~ScreenWritersRepo();
    vector<ScreenWriter>& getScreenWriters();

};
