/* main.cpp - Program produces the sum of all the members in a file of white-
 * space separated integers.
 * 
 */

#include "../../std_lib_facilities.h"

//================================================
// Function declarations
//================================================
void readInts(vector<int> &);
int sumInts(const vector<int>);


//================================================
// Main 
//================================================
int main()
{
	// create unitizialized vector of integers to store input values 
	vector<int> numbers{};

	readInts(numbers);

	std::cout << "Sum: " << sumInts(numbers)
		  << std::endl;
	return 0;
}

//================================================
// Function definitions
//================================================
void readInts(vector<int> &v)
{
	int num{};
	std::string inputFile{};
	std::cout << "Input file: ";
	std::cin >> inputFile;
	
	ifstream ist{inputFile};
	if(!ist) error("Error: could not open file or file does not exist", inputFile);

	while(ist >> num)
	{
		v.push_back(num);
	}

};

//------------------------------------------------
int sumInts(const vector<int> v)
{
	int sum{};
	
	for(size_t i{}; i < v.size(); ++i)
		sum += v[i];

	return sum;
};
