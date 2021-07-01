/* temp_stats.cpp - Program reads data from the raw_temps.txt file created in exercise 2. 
 *	The program reads the values into a vector and then calculates the mean and median 
 *	of the TEMPERATURES ONLY in the data set. 
 * 
 * Primary Author: D'Anthony Weaver
 * Contributing Authors: N/A
 * Last Modified: 30 JUNE 2021
 *
 * Outline:
 *	[X] 1) Read values from a file into a vector
 *	[X] 2) Calculate the median of the temperatures in the data set
 *	[X] 3) Calculate the mean of the temperatures in the data set
 *	[X]  4) Exercise 4: test each temperature reading, convert Celsius to Fahrenheit before putting in vector
 *
 */

#include "../../std_lib_facilities.h"

//================================================
// Function Declaration(s)
//================================================
double calculateMean(const vector<double>&);
double calculateMedian(const vector<double>&);
void displayVector(const vector<double>&);
vector<double> sortVector(vector<double>&);

//================================================
// Main
//================================================
int main()
{
	// Variable declarations 
	vector<double> temperatures{}, days{}, hours{};	// vectors for input data
	double temp{}, day{}, hour{};			// store each data read
	char firstChar{}, lastChar{}, scale{};			// for test first and last characters
	std::string inputFile{}, line{};			// name of file to be read

	// Create input stream
	std::cout << "Enter input file: ";
	std::cin >> inputFile;
	ifstream ist{inputFile};
	if(!ist) error("Error: could not open input file", inputFile);

	while(ist>>firstChar && firstChar=='(')	
	{
		ist >> day >> hour >> temp >> scale >> lastChar;		// if good, read values into variables 
		if(lastChar!=')')				// test if last character is valid, MUST be ')'
			error("Error: Bad last character!", lastChar);	// if not, error and bail on program

		if(scale == 'c')	// if current reading is using Celsius scale, then convert to Fahrenheit
		{
			//	F = (C * (9/5)) + 32
			temp = (temp * (1.8)) + 32;
		}
		
		// Add temps to temperatures vector
		temperatures.push_back(temp);
	}

	std::cout << "Temperature Vector: " << std::endl;
	displayVector(temperatures);

	// calculate mean 
	std::cout << "\nTemperature mean: " << calculateMean(temperatures) 
		  << std::endl;

	// sort vector
	vector<double> q = sortVector(temperatures);	// work with copy of array instead of original array
	std::cout << "\nSorted Temperature Vector (in degrees Farenheit): " << std::endl;
	displayVector(q);
	
	// TO DO: Find vector median using copy of original temperatures vector
	std::cout << "\nMedian: " << calculateMedian(q) << std::endl;

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
double calculateMedian(const vector<double>& v)
{
	/* calculateMedian -> calculates median of a given vector
	 * Args:
	 *	- reference to vector of doubles 
	 * Return:
	 *	- median value
	 */

	/* Case 1: even number of elements
	 *	- find middle two elements (size/2 and size/2 + 1)
	 *	- add them 
	 * 	- divide sum by two
	 *	- return result
	 * Case 2: odd number of element
	 *	- return middle element (size//2 + 1)
	 */

	if(v.size() % 2 == 0)	// Case 1: even number of element
	{
		int x{}, y{}; 
		double r{};
		x = v.size()/2 - 1 ;	// position 1
		y = v.size()/2;	// position 2
		r = (v[x] + v[y]) / 2;
		return r;
	}
	else 	// Case 2: odd number of elements
	{
		int x{};	
		x = v.size()/2;	// go straight for middle 
		return v[x];
	}
	
};

//------------------------------------------------
void displayVector(const vector<double>& v)
{
	for(size_t i{}; i < v.size(); ++i)
		std::cout << "Temp[" << i << "] = "
			  << v[i] << " °F"<< std::endl;
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
