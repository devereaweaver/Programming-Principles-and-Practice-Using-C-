/* concat.cpp - program concatenates the contents of two files. The output file is 
 * a file with the contents of the first file followed by the contents of the second
 * file. 
 * 
 * Primary author: D'Anthony Weaver
 * Contributing authors: N/A
 * Last Modified: 30 JUNE 2021
 *
 */

#include "../../std_lib_facilities.h"

int main()
{
	// variables for input files and output file
	string input1{}, input2{}, outputFile{}, line{};

	// Open input stream from input1
	std::cout << "Enter file 1: ";
	std::cin >> input1;
	ifstream ist1{input1};
	if(!ist1) error("Error: could not open input stream first file!", input1);

	// Open input stream from input2
	std::cout << "Enter file 2: ";
	std::cin >> input2;
	ifstream ist2{input2};
	if(!ist2) error("Error: could not open input stream to second file!", input2);

	// Get name of desired output file 
	std::cout << "Enter output file name: ";
	std::cin >> outputFile;
	ofstream ost{outputFile};
	if(!ost) error("Error: could not write to file!", outputFile);

	while(std::getline(ist1, line))	// Read contents of first file to output
		ost << line << "\n";
	ist1.close();

	while(std::getline(ist2, line)) // Read contents of second file to output
		ost << line << "\n";
	ist2.close();

	ost.close();

	return 0;
}
