#include "Library.h"

using namespace Library;
using namespace std;

int main()
{
	// io manipulation
	cout << boolalpha;
	cout << fixed;
	cout << setprecision(2);


	// test out the Patron class constructors 
	Patron me("Devere Weaver", "0001");		// create Patron object
	cout << "User name: " << me.get_username() << endl;	// return Patron user name
	cout << "Card number: " << me.get_cardnum() << endl;	// return Patron card number
	cout << "Curent Fees: $" << me.get_fees() << endl;		// TO DO: properly format fees, return fees owed by user
	cout << "\nSetting fees..." << endl;
	me.set_fees(50.69);										// set amount of fees owed by user
	cout << "Current Fees: $" << me.get_fees() << endl;		// return fees owed by user
	cout << "Do I have any fees?: " << has_fee(me) << endl;	// check if user owes any fees 

	return 0;
}