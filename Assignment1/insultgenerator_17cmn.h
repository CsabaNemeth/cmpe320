/*
 * insultgenerator_17cmn.h
 *
 *  Created on: Sep. 19, 2020
 *      Author: Csaba Nemeth
 *      Version: 1.0
 *
 */

#ifndef INSULTGENERATOR_17CMN_H_
#define INSULTGENERATOR_17CMN_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

//Exception class thrown when encountering a read/write error.
class FileException {
public:
	FileException(const std::string& message); //Constructor for FileException class.
	std::string& what(); //Returns the supplied error message.
private:
	std::string message; //Holds the error message.
};

//Thrown if the number of requested insults to generate does not fall within the inclusive range [0, 10000].
class NumInsultsOutOfBounds {
public:
	NumInsultsOutOfBounds(const std::string& message); //Constructor for NumInsultsOutOfBounds class.
	std::string& what(); //Returns the supplied error message.
private:
	std::string message; //Holds the error message.
};

/*
 * class InsultGenerator
 *
 * Contains three methods to generate Shakespearean insults using a source .txt file.
 * The columns of the file are read into vectors once initialize() is called, and a word is chosen
 * from each column to construct the insult.
 *
 * InsultGenerator::talkToMe() - Returns a single insult as a string.
 *
 * InsultGenerator::generate(int) - Generates a requested number of insults in the (0, 10000] range and returns a sorted vector.
 * To avoid duplicate insults, an std::set is used to achieve fast lookup times and avoid duplicates.
 * std::set is automatically ordered.
 *
 * InsultGenerator::generateAndSave(string, int) - Generates a requested number of insults in the (0, 10000] range
 * and saves a file containing the alphabetically sorted insults.
 *
 */
class InsultGenerator {
public:
	void initialize(); //Loads all the source phrases into the class attributes.
	std::string talkToMe();
	std::vector<std::string> generate(const int);
	void generateAndSave(const std::string, const int);
private:
	std::vector<std::string> col1, col2, col3; //Vectors holding each individual text column from source file.
	int n; //The number of insults to generate.
};

#endif /* INSULTGENERATOR_17CMN_H_ */
