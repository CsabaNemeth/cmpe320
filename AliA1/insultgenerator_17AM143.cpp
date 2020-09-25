#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include "insultgenerator_17AM143.h"

using namespace std;

//populate our column vectors from read of tab delimeted source file
void InsultGenerator::initialize() {
    //exception handling of file failure
    ifstream file("InsultsSource.txt");
    if (!(file.good())) {
        FileException f;
        throw f;
    }

    while (!file.eof()){ //continues so long as file has line literal
        string line;
        getline(file, line); //fills string with line

        //finds indicies of tab to slice string
        int ind1 = line.find('\t');
        int ind2 = ind1 + line.substr(ind1+1, line.length()-1).find('\t') + 2;

        string first, second, third;

        //slices string
        first = line.substr(0, ind1);
        second = line.substr(ind1+1, ind2-ind1-2);
        third = line.substr(ind2, line.length()-ind2-1);

        //populates current row of each column with corresponding string
        this->col1.push_back(first);
        this->col2.push_back(second);
        this->col3.push_back(third);
    }
    this->n = this->col1.size()-1; //assigns number of words attribute

}

//this should generate an insulte using our column vectors
string InsultGenerator::talkToMe() {
    int n = this->n; //upper bound of random number
    string out = "Thou " + this->col1[rand() % n] + " " + this->col2[rand() % n] + " " + this->col3[rand() % n] + "!"; //random insults
    return out;
}

//makes use of talkToMe multiple times
//ensures insults are in alphabetical order and unique via set collection
vector<string> InsultGenerator::generate(int numInsults) {
    //exception handling of invalid insult request
    if (!(1 <= numInsults && numInsults <= 10000)) {
        NumInsultsOutOfBounds b;
        b.setInsults(numInsults);
        b.getInsults();
        throw b;
        }

    set<string> out;

    //populates set with insults, uniques are discarded and order is preserved
    while (out.size()<numInsults) {
        string cand = this->talkToMe();
        out.insert(cand);
    }

    //essentially casts set to vector to ensure type match
    vector<string> insults(out.begin(), out.end());
    return insults;
}

//makes use of generate and simply writes to file
void InsultGenerator::generateAndSave(string path, int numInsults) {    ofstream file (path);
    vector<string> insults = this->generate(numInsults); //vector of insults

    //populates lines of file with insults
    if (file.is_open()) {
        for (vector<string>::iterator i = begin(insults); i != end(insults); ++i) {
            file << *i << endl; //defrences iterator to file of line
        }
        file.close();
    }
    else //exception handling if file cannot be opened
    {
        FileException f;
        throw f;
    }
}


