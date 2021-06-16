/* temp_stats.cpp - Program reads data from the raw_temps.txt file created in exercise 2. 
 *	The program reads the values into a vector and then calculates the mean and median 
 *	of the TEMPERATURES ONLY in the data set. 
 * 
 * Primary Author: D'Anthony Weaver
 * Contributing Authors: N/A
 * Last Modified: 15 JUNE 2021
 *
 * Outline:
 *	1) Read values from a file into a vector
 *	2) Calculate the median of the temperatures in the data set
 *	3) Calculate the mean of the temperatures in the data set
 */

#include "../../std_lib_facilities.h"

int main()
{
	// Variable declarations 
	vector<double> temperatures{}, days{}, hours{};
	double temp{}, day{}, hour{};
	char firstChar{}, lastChar{};
	std::string inputFile{};

	// Create input stream
	std::cout << "Enter input file: ";
	std::cin >> inputFile;
	ifstream ist{inputFile};
	if(!ist) error("Error: could not open input file", inputFile);

	// TO DO: Read input until EOF is reached, starting here
	// Read valid input data for processing
	if(ist>>firstChar && firstChar!='(')	// test if first character is valid, MUST be '('
		error("Error: Bad first character!", firstChar);	// just throw error and exit program
	ist >> day >> hour >> temp >> lastChar;
	if(lastChar!=')')
		error("Error: Bad last character!", lastChar);

	// Add temps to temperatures vector
	temperatures.push_back(temp);

	return 0;
}
