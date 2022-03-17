//
// Created by Alexandra on 6/21/2021.
//

#include "Idea.h"

Idea::Idea() {

}

Idea::Idea(string description, string status, string creator, string act):
description{description}, status{status}, creator{creator}, act{act}
{

}

Idea::~Idea() {

}

string Idea::getDescription() {
    return this->description;
}

string Idea::getStatus() {
    return this->status;
}

string Idea::getCreator() {
    return this->creator;
}

string Idea::getAct() {
    return this->act;
}

vector<string> Idea::tokenize(string str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

ostream &operator<<(ostream &output, const Idea &i) {
    output<<i.description<<";"<<i.status<<";"<<i.creator<<";"<<i.act;
    return output;
}

istream &operator>>(istream &input, Idea &i) {
    string line;
    getline(input, line);
    vector<string> tokens = Idea::tokenize(line, ';');
    if(tokens.size() != 4)
        return input;
    i.description = tokens[0];
    i.status = tokens[1];
    i.creator = tokens[2];
    i.act = tokens[3];
    return input;
}

void Idea::setStatus(string status) {
    this->status = status;
}
