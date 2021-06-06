/* main.cpp - Working through the drill steps for chapter 10 of PPP2 
 * 
 * 1) Start a program to work with points. First define the data type Point that has two coordinate members x and y
 * 2) Prompt user to input seven (x,y) pairs. Store the data ina vector of Points called original_points.
 * 3) Print the data in original_points to see what it looks like
 * 4) Open an ofstream and output each point to a file name mydata.txt
 * 5) Open an ifstream for the newly created output file and then read the Point data and store it in a new 
 *    vecotr called processed_points.
*/

#include "../std_lib_facilities.h"

//================================================
// User defined types
//================================================
struct Point		// may want to switch to class later depending on needs of access
{
	double x;
	double y;
};

//================================================
// Function Declarations)
//================================================
void writePoints(vector<Point>);
vector<Point> readPoints();

//================================================
// Main 
//================================================
int main()
{
	vector<Point> original_points;	

	for (size_t i{}; i < 7; ++i)	// fill vector
	{
		Point p;	// create Point object
		std::cout << "Enter a coordinate pair, (x,y)" << std::endl;
		std::cout << "> ";
		std::cin >> p.x >> p.y;
		original_points.push_back(p);
	}

	writePoints(original_points);	// output Point vector to file

	vector<Point> processed_points{};
	processed_points = readPoints();	// read Point coordinates from file

	// ouptut coordinate points 
	std::cout << "\nOriginal Points" << std::endl;
	for (size_t i{}; i < original_points.size(); ++i)
		std::cout << original_points[i].x << " " << original_points[i].y << std::endl;
	
	std::cout << "\nProcessed Points" << std::endl;
	for (size_t i{}; i < processed_points.size(); ++i)
		std::cout << processed_points[i].x << " " << processed_points[i].y << std::endl;

	/* TO DO: Figure out how to compare the two elements using built-in functions and types?... */
		
	return 0;
}

//================================================
// Function Definition(s)
//================================================
void writePoints(vector<Point> vp)
{
	/* outputPoints() -> allows user to write Point coordinates to a file 
	 * Args: 
	 *	- vector<Point> vp -> a vector of Point objects
	 */

	string outputFile{};
	std::cout << "Enter name of ouptut file: ";
	std::cin >> outputFile;

	ofstream ost{outputFile};	// create output stream
	if(!ost) error("Error: could not open output file! ", outputFile);  // test file opened

	for(size_t i{}; i < vp.size(); ++i)	// write points to file 
		ost << vp[i].x << " " << vp[i].y << "\n";
};

//------------------------------------------------
vector<Point> readPoints()
{
	/* readPoints() -> read a series of Point coordinate values from a file
	 *	and saves them to a vector of Point objects
	 * 
	 * Return value: vector<Point> -> a vector of Point objects 
	 */
	double x{}, y{};	
	string inputFile{};
	std::cout << "Enter name of input file: ";
	std::cin >> inputFile;

	ifstream ist{inputFile};
	if(!ist) error("Error: could not open inputput file! ", inputFile);

	vector<Point> vp{};	// local vector 

	while(ist >> x >> y)	// while reading values into x and y 
	{
		Point p;
		p.x = x;
		p.y = y;
		vp.push_back(p);
	}
	return vp;
};
