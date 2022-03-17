//
// Created by Alexandra on 6/21/2021.
//

#include "IdeasRepo.h"

void IdeasRepo::LoadData() {
    ifstream inFile("ideas.txt");
    Idea currentElement;
    this->ideas.clear();
    while(inFile >> currentElement){
        this->ideas.push_back(currentElement);
    }
    inFile.close();
    ::sort(this->ideas.begin(), this->ideas.end(), [](Idea i1, Idea i2){
        return i1.getAct()<i2.getAct();
    });
}

IdeasRepo::IdeasRepo() {
    this->LoadData();

}

IdeasRepo::~IdeasRepo() {

}

vector<Idea> &IdeasRepo::getIdeas() {
    return this->ideas;
}

int IdeasRepo::checkExistence(Idea idea) {
    for(int i = 0; i < this->ideas.size(); i++){
        if(this->ideas[i].getDescription() == idea.getDescription())
            return i;
    }
    return -1;
}

void IdeasRepo::addIdea(Idea i) {
    int pos = this->checkExistence(i);
    if(pos == -1){
        this->ideas.push_back(i);
        ::sort(this->ideas.begin(), this->ideas.end(), [](Idea i1, Idea i2){
            return i1.getAct()<i2.getAct();
        });
        this->notify();
    }
    else
    {
        throw exception();
    }
}

void IdeasRepo::acceptIdea(Idea& i) {
    int pos = this->checkExistence(i);
    this->ideas[pos].setStatus("accepted");
    this->notify();
}

vector<Idea> IdeasRepo::getAcceptedIdeas(ScreenWriter s) {
    vector<Idea> filtered;

    for(auto & i: this->ideas){
        if(i.getCreator() == s.getName() and i.getStatus() == "accepted"){
            filtered.push_back(i);
        }
    }
    return filtered;
}

vector<Idea> IdeasRepo::sortByActs() {
    vector<Idea> sorted(this->getIdeas());
    for(int i = 0 ; i < sorted.size() - 1; i++){
        for(int j = i + 1; j < sorted.size(); j++){
            if(sorted[i].getAct()> sorted[j].getAct()){
                swap(sorted[i], sorted[j]);
            }
        }
    };
    return sorted;
}
