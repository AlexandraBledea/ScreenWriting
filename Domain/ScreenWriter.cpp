//
// Created by Alexandra on 6/21/2021.
//

#include "ScreenWriter.h"

ScreenWriter::ScreenWriter() {

}

ScreenWriter::ScreenWriter(string name, string expertise):name{name}, expertise{expertise} {

}

ScreenWriter::~ScreenWriter() {

}

string ScreenWriter::getName() {
    return this->name;
}

string ScreenWriter::getExpertise() {
    return this->expertise;
}

istream &operator>>(istream &input, ScreenWriter &s) {
    input>>s.name>>s.expertise;
    return input;
}
