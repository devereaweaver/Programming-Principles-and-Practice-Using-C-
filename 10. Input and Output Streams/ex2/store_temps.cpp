/* store_temps.cpp - Exercise 2
 * 
 * Task - write a program that creates a file of data in the form of the temperature Reading type
 * 	previously defined. Test by filling the created file with 50 "temperature readings". 
 *	The output file should be named raw_temps.txt.
 */

#include "../../std_lib_facilities.h"

//================================================
// Function Declarations 
//================================================
void outputReading();
int getDay();
int getHour();
double getTemp();

//================================================
// Main 
//================================================
int main()
{
	// Kind of stupid that it only calls one function BUT keep it like this for now, more will be added later
	outputReading();
		
	return 0;
}

//================================================
//  Function Definitions 
//================================================
void outputReading()
{
	std::string outputFile{};
	std::cout << "Enter output file name: ";
	std::cin >> outputFile;
	ofstream ost{outputFile};
	if(!ost) error("Error during output.", outputFile);

	// create better input loop
	while(true)
	{
		int day{}, hour{};
		double temp{};
		char exit{};
		
		day = getDay(); 
		hour = getHour();
		temp = getTemp();

		// read values into output with following prescribed format
		ost << "(" << day << " " << hour << " " << temp << ")\n";
		
		std::cout << "More Readings? [y/N]: ";
		std::cin >> exit;

		if(exit == 'y' || exit == 'Y')
		{
			std::cout << std::endl;
			continue;
		}
		else
			break;
	}	
};

//------------------------------------------------
int getDay()
{
	int d{};
	
	do
	{
		std::cout << "Enter day number: ";
		std::cin >> d;
		if(d<1||d>31)
			std::cout << "Day must be in range of 1-31.\n" << std::endl;
	} while (d<1||d>31);

	return d;
};

//------------------------------------------------
int getHour()
{
	int h{};

	do
	{
		std::cout << "Enter hour: ";
		std::cin >> h;
		if(h<0||h>23)
			std::cout << "Hour must be in range of 0-23.\n" << std::endl;
	} while (h<0||h>23);

	return h;
};

//------------------------------------------------
double getTemp()
{
	double t{};

	do
	{
		std::cout << "Enter temp: ";
		std::cin >> t;
		if(t<-200||t>200)
			std::cout << "Temp must be in range of -200 - +200.\n" << std::endl;
	} while (t<-200||t>200);

	return t;
};
