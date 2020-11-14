#include "Library_System.h"

using namespace Library_System;
using namespace std;

int main() {
	Library lib;

	// test add_book() function
	//lib.add_book();
	//cout << '\n';
	//lib.add_book();
	//vector<Book> my_books = lib.get_books();
	//for (size_t i{ 0 }; i < my_books.size(); ++i)	
	//	cout << "\nEntry " << (i + 1) << ": \n" << my_books[i] << endl;

	// test add_patron() function 
	//lib.add_patron();
	//vector<Patron> my_patrons = lib.get_patrons();
	//for (size_t i{ 0 }; i < my_patrons.size(); ++i)	
	//	cout << "\nEntry " << (i + 1) << ": \n" << my_patrons[i] << endl;
	//

	// test Transaction object and add_transaction() function
	//// create objects
	//lib.add_book();
	//lib.add_book();
	//lib.add_patron();
	//lib.add_patron();

	//// assign vector of objects 
	//vector<Book> books = lib.get_books();
	//cout << '\n';
	//vector<Patron> patrons = lib.get_patrons();

	//// create Transaction object 
	//lib.add_transaction(patrons[0], books[0], "8-June-2020");
	//lib.add_transaction(patrons[1], books[1], "8-June-2020");

	//// get transactions 
	//vector<Library::Transaction> transactions = lib.get_transactions();
	//for (size_t i{ 0 }; i < transactions.size(); ++i)
	//	cout << transactions[i] << endl;

	/* Test checkout_book() */
	// Create a Patron, add them to vector and then check if they exist
	lib.add_patron();
	lib.add_book();
	lib.checkout_book();

	vector<Library::Transaction> transactions = lib.get_transactions();
	for (size_t i{ 0 }; i < transactions.size(); ++i)
		cout << transactions[i] << endl;


	return 0;
}