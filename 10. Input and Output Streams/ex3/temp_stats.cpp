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
double calculateMean(const vector<double>&);
void displayVector(const vector<double>&);
vector<double> sortVector(vector<double>&);	// needs to be changed

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

	// sort vector
	vector<double> q = sortVector(temperatures);	// work with copy of array instead of original array
	
	// TO DO: Find vector median using copy of original temperatures vector

	return 0;
}

//================================================
// Function Definition(s)
//================================================
double calculateMean(const vector<double>& v)
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
void displayVector(const vector<double>& v)
{
	for(size_t i{}; i < v.size(); ++i)
		std::cout << "Temp[" << i << "] = "
			  << v[i] << std::endl;
};

//------------------------------------------------
vector<double> sortVector(vector<double>& v)
{
	// implementation of bubble sort 

	/* Bubble sort algorithm:
	 * Do 
	 *	Set a swap flag to false
	 *	for loop to iterate over vector until next to last element
	 *		if current element is greater than next element
	 *		{
	 *			Swap the two elements
	 *			Set the swap flag to true since values were swapped
	 *		}
	 *		End if
	 *	End for
	 * While some elements have been swapped. Exit loop once values are in ascending order
	 */

	vector<double> c = v;

	bool swap{};
	double temp{};	// TO DO: consider creating a separate swap function later

	do
	{
		swap = false; // need to set to false each time
		for(size_t i{0}; i < c.size() - 1; ++i)
		{
			if(c[i] > c[i+1])
			{
				// SWAP
				temp = c[i];	// temp variable
				c[i] = c[i+1];	// current is equal to next 
				c[i+1] = temp;	// next is equal to temp (current)
				swap = true;
			} 
		} // end for
	} while(swap);

	return c;
};
