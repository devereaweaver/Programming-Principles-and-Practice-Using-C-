#include "Book.h"

using namespace std;
using namespace Library;

int main()
{
    Book pp2("1-2-3-4", "Programming:Principles and Practice Using C++", "Bjarne Stroustrup", Genre::nonfiction,  "1963", false);

    std::cout << std::boolalpha; // print out true/false instead of 1/0

    //// test functions
    //cout << "ISBN: " << pp2.get_isbn() << endl;
    //cout << "Title: " << pp2.get_title() << endl;
    //cout << "Author: " << pp2.get_author() << endl;
    ////cout << "Genre: " << pp2.get_genre() << endl;   // ERROR
    //cout << "Copyright Date: " << pp2.get_copyright_date() << endl;
    //cout << "Checked out: " << pp2.is_checked_out() << endl;
    //cout << "\nNow checking out..." << endl;
    //pp2.check_out();
    //cout << "Checked out: " << pp2.is_checked_out() << endl;

	// test helper function
    /* Book a("11-22-33-44", "Programming in C", "S. Kochan", "2011", false);
     Book b("11-22-33-45", "C Primer Plus", "S. Prata", "2010", false);

     bool equal = a == b;
     bool not_equal = a != b;

     cout << "Are the books the same: " << equal << endl;
     cout << "Are the books NOT the same: " << not_equal << endl;
*/
    cout << '\n' << pp2;	// test output operator 
    return 0;
}