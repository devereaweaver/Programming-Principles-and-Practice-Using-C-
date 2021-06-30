/* temp_stats.cpp - Program reads data from the raw_temps.txt file created in exercise 2. 
 *	The program reads the values into a vector and then calculates the mean and median 
 *	of the TEMPERATURES ONLY in the data set. 
 * 
 * Primary Author: D'Anthony Weaver
 * Contributing Authors: N/A
 * Last Modified: 15 JUNE 2021
 *
 * Outline:
 *	[X] 1) Read values from a file into a vector
 *	[] 2) Calculate the median of the temperatures in the data set
 *	[X] 3) Calculate the mean of the temperatures in the data set
 */

#include "../../std_lib_facilities.h"

//================================================
// Function Declaration(s)
//================================================
double calculateMean(vector<double>&);
void displayVector(vector<double>&);

//================================================
// Main
//================================================
int main()
{
	// Variable declarations 
	vector<double> temperatures{}, days{}, hours{};	// vectors for input data
	double temp{}, day{}, hour{};			// store each data read
	char firstChar{}, lastChar{};			// for test first and last characters
	std::string inputFile{}, line{};			// name of file to be read

	// Create input stream
	std::cout << "Enter input file: ";
	std::cin >> inputFile;
	ifstream ist{inputFile};
	if(!ist) error("Error: could not open input file", inputFile);

	// TO DO: Read input until EOF is reached, starting here
	// Read valid input data for processing
	// WHY IS IT READING 4 TEMPS AND NOT 3??
	while(ist>>firstChar && firstChar=='(')	
	{
		ist >> day >> hour >> temp >> lastChar;		// if good, read values into variables 
		if(lastChar!=')')				// test if last character is valid, MUST be ')'
			error("Error: Bad last character!", lastChar);	// if not, error and bail on program

		// Add temps to temperatures vector
		temperatures.push_back(temp);
	}

	displayVector(temperatures);

	// calculate mean 
	std::cout << "\nTemperature mean: " << calculateMean(temperatures) 
		  << std::endl;

	return 0;
}

//================================================
// Function Definition(s)
//================================================
double calculateMean(vector<double>& v)
{
	/* calculateMean() -> calculates the mean value of a given vector
	 * Args:
	 *	- v -> reference to a vector
	 * Return:
	 *	- double that stores the mean value of the vector
	 */

	double total{}, mean{};

	for(size_t i{}; i < v.size(); ++i)
		total += v[i];	// add all values in vector

	mean = total/v.size();

	return mean;
};

//------------------------------------------------
void displayVector(vector<double>& v)
{
	for(size_t i{}; i < v.size(); ++i)
		std::cout << "Temp[" << i << "] = "
			  << v[i] << std::endl;
};
