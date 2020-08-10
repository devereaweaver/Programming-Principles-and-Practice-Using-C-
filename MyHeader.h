#pragma once
#include "std_lib_facilities.h"

void Sequence(int x, int y, int z) {
	/* Function takes 3 ints and displays them in numerical order (Ex. 3-6)*/
	int a = x;
	int b = y;
	int c = z;
	int first = 0;
	int second = 0;
	int third = 0;

	// MAKE COMPARISONS
	if (a <= b && a <= c) {			// If a is the smallest value		
		first = a;
		if (b >= c) {
			second = c;
			third = b;
		}
		else {
			second = b;
			third = c;
		}
	}
	else if (a >= b && a >= c) {	// If a is the largest value
		third = a;
		if (b >= c) {
			first = c;
			second = b;
		}
		else {
			first = b;
			second = c;
		}
	}
	else if (a <= b && a >= c) {	// If a is the middle value 
		second = a;
		if (b >= c) {
			first = c;
			third = b;
		}
		else {
			first = b;
			third = c;
		}
	}
	else if (a >= b && a <= c) {	// If a is the middle value 
		second = a;
		if (b >= c) {
			first = c;
			third = b;
		}
		else {
			first = b;
			third = c;
		}
	}
	cout << first << ", " << second << ", " << third << '\n';

}

void SequenceStrings(string x, string y, string z) {
	/* Function takes 3 strings and displays them in alphabetical order (Ex. 3-7) */
	string a = x;
	string b = y;
	string c = z;
	string first = " ";
	string second = " ";
	string third = " ";

	// MAKE COMPARISONS
	if (a <= b && a <= c) {			// If a is the smallest value		
		first = a;
		if (b >= c) {
			second = c;
			third = b;
		}
		else {
			second = b;
			third = c;
		}
	}
	else if (a >= b && a >= c) {	// If a is the largest value
		third = a;
		if (b >= c) {
			first = c;
			second = b;
		}
		else {
			first = b;
			second = c;
		}
	}
	else if (a <= b && a >= c) {	// If a is the middle value 
		second = a;
		if (b >= c) {
			first = c;
			third = b;
		}
		else {
			first = b;
			third = c;
		}
	}
	else if (a >= b && a <= c) {	// If a is the middle value 
		second = a;
		if (b >= c) {
			first = c;
			third = b;
		}
		else {
			first = b;
			third = c;
		}
	}
	cout << first << ", " << second << ", " << third << '\n';

}

void EvenOrOdd(int x) {
	if (x % 2 == 0) {
		cout << x << " is an even integer.\n";
	}
	else {
		cout << x << " is an odd integer.\n";
	}
}


void StringToInt(string x) {
	string a = x;

	if (a == "zero" || a == "Zero") {
		cout << 0 << '\n';
	}
	else if (a == "one" || a == "One") {
		cout << 1 << '\n';
	}
	else if (a == "two" || a == "Two") {
		cout << 2 << '\n';
	}
	else if (a == "three" || a == "Three") {
		cout << 3 << '\n';
	}
	else if (a == "four" || a == "Four") {
		cout << 4 << '\n';
	}
	else {
		cout << "Not a number I know...stupid computer!\n";
	}
}
