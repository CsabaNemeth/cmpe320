#ifndef INSULTGENERATOR
#define INSULTGENERATOR

#include <vector>
#include <string>
#include <exception>
#include <iostream>

using namespace std;

class FileException: public exception {
    public:
        const char* what(){
            return "Cannot open file.";
        }

};

class NumInsultsOutOfBounds : public exception {
    private:
        int insults;
    public:
        const char* what(){
            return "You need between 1 and 10,000 insults.";
        }
        void getInsults() {
            cout << endl << "You've asked for " << insults << endl;
        }
        void setInsults(int insults) {
            this->insults = insults;
        }
};

class InsultGenerator {
    private:
        vector<string> col1, col2, col3;
        int n;
    public:
        void initialize();
        string talkToMe();
        vector<string> generate(const int);
        void generateAndSave(string, int);
};

#endif
