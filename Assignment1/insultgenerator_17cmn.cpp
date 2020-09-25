/*
 * insultgenerator_17cmn.cpp
 *
 *  Created on: Sep. 19, 2020
 *      Author: Csaba Nemeth
 *      Version: 1.2
 */
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
#include <time.h>

#include "insultgenerator_17cmn.h"

using namespace std;

//FileException Class
FileException::FileException(const string& message) : message(message) {} //Constructor
string& FileException::what() { return message; } //Return the message when called.

//NumInsultsOutOfBounds Class
NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& message) : message(message) {} //Constructor
string& NumInsultsOutOfBounds::what() { return message; } //Return the message when called.

//InsultGenerator Class Members
void InsultGenerator::initialize() {
	string first, second, third; //Strings to hold each delimited word.
	ifstream inFile("InsultsSource.txt"); //Open file
	if (inFile.fail()) {
		throw FileException("Source file cannot be opened!"); //Throw exception if failed.
	}
	srand(time(0)); //Initialize a random seed.
	//Read each delimited into std::vector<string>
	while ((inFile >> first) && (inFile >> second) && (inFile >> third)) {
		col1.push_back(first);
		col2.push_back(second);
		col3.push_back(third);
	}
	this->n = col1.size(); //n is the number of rows.
	inFile.close();

}

//Create a single random insult.
string InsultGenerator::talkToMe() {
	string retString("Thou " + col1.at(rand() % n) + " " + col2.at(rand() % n) + " " + col3.at(rand() % n) + "!");
	return retString;
}

//Create numRequested unique insults sorted alphabetically in an std:vector<string>, which is returned.
vector<string> InsultGenerator::generate(int const numRequested) {

	if (numRequested < 1 || numRequested > 10000) { //Throw exception if the requested number is illegal.
		throw NumInsultsOutOfBounds("Invalid number of requested insults!");
	}

	//This is not 100% necessary but is included to suppress a warning on the comparison in line 69.
	unsigned const int n = numRequested; //This is safe becuase we already checked for the sign right above.

	/*Create an unordered set for quick lookup times: O(1) average.
	 * Use an ordered set std::set to allow faster insert speeds and automatic duplicate checking.
	 * O(1) + O(nlogn) > O(logn).
	 */
	set<string> oSet;
	//While the set size is less than the requested number, keep inserting elements.
    while (oSet.size()<n) {
        oSet.insert(this->talkToMe()); //Cannot have duplicates in a set.
    }
	vector<string> retVector(oSet.begin(), oSet.end());//Copy unordered set to vector.
	return retVector; //Return.
}

//Generates and saves numRequested insults into a txt file called filename.
void InsultGenerator::generateAndSave(const string filename, const int numRequested) {
	vector<string> toWrite = this->generate(numRequested); //Create vector to hold this->generate() output
	ofstream outFile(filename); //Start a stream with the filename
	for (const string &val : toWrite) outFile << val << "\n"; //Write each insult to the file.
	outFile.close(); //Close the file.
}



