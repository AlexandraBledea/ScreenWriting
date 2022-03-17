#include <iostream>
#include <QApplication>
#include "IdeasRepo.h"
#include "ScreenWritersRepo.h"
#include "ScreenWriterWindow.h"

int main(int argc, char** argv) {
    QApplication a(argc, argv);

    IdeasRepo ideas;
    ScreenWritersRepo screenWriters;
    vector<ScreenWriterWindow*> windows;
    for(auto & s: screenWriters.getScreenWriters()){
        windows.push_back(new ScreenWriterWindow(ideas, s));
    }

    return a.exec();
}
