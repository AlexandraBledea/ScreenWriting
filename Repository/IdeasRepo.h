//
// Created by Alexandra on 6/21/2021.
//

#pragma once
#include "Idea.h"
#include "Observer.h"
#include "ScreenWriter.h"

class IdeasRepo: public Observable {

private:

    vector<Idea> ideas;
    void LoadData();

public:

    IdeasRepo();
    ~IdeasRepo();

    int checkExistence(Idea i);
    vector<Idea>& getIdeas();
    void addIdea(Idea i);
    void acceptIdea(Idea& i);
    vector<Idea> getAcceptedIdeas(ScreenWriter s);
    vector<Idea> sortByActs();

};
