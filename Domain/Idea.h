//
// Created by Alexandra on 6/21/2021.
//

#include <vector>
#include <string>
using namespace std;
#include <sstream>
#include <fstream>
class Idea {

private:
    string description;
    string status;
    string creator;
    string act;

public:

    Idea();
    Idea(string description, string status, string creator, string act);
    ~Idea();

    string getDescription();
    string getStatus();
    string getCreator();
    string getAct();

    void setStatus(string status);

    static vector<string> tokenize(string str, char delimiter);
    friend ostream& operator<<(ostream&, const Idea&);

    friend istream& operator>>(istream&, Idea&);



};
