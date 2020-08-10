#pragma once
#include <iostream>
#include <string>
#include <iomanip>

namespace Library
{
	//=============================================================================
	// Class Definitions
	//=============================================================================
	enum class Genre
	{
		fiction = 1,
		nonfiction,
		periodical,
		biography,
		childrens
	};

	//-----------------------------------------------------------------------------
	class Book
	{
	public:
		//=============================================================================
		// Book Constructor(s)
		//=============================================================================
		Book() {};
		Book(std::string i, std::string t, std::string a, Genre g, std::string cr, bool co)
			: isbn{ i }, title{ t }, author{ a }, genre{ g }, copyright_date{ cr }, checked_out{ false } {};

		//=============================================================================
		// Book Member functions
		//=============================================================================
		/* modifying operations */
		void check_in()	/* Check in a book object */
		{
			checked_out = false;
		}

		void check_out()	/* Check out a Book object */
		{
			checked_out = true;
		}

		/* non-modifying operations */
		bool is_checked_out()	/* Check if Book object is checked out */
		{
			return checked_out;
		}

		std::string get_isbn() const // need to add const for const references
		{
			return isbn;
		}

		std::string get_title() const	/* Return title membe of Book object */
		{
			return title;
		}

		std::string get_author() const	/* Return author member of Book object */
		{
			return author;
		}

		std::string get_copyright_date() const	/* Return copyright date of Book object */
		{
			return copyright_date;
		}

		Genre get_genre() const	/* Return genre of Book object */
		{
			return genre;
		}

	private:
		std::string isbn{};
		std::string title{};
		std::string author{};
		std::string copyright_date{}; // may change type later
		Genre genre{};
		bool checked_out{};
	};

	//-----------------------------------------------------------------------------
	class Patron
	{
	public:
		//=============================================================================
		// Patron Constructors
		//=============================================================================
		Patron(std::string un, std::string cn)	// chose not to set fee in constructor, they might not owe anthing
			: user_name{ un }, card_num{ cn } {};

		//=============================================================================
		// Patron Member Functions 
		//=============================================================================
		/* modifying operations */
		void set_fees(double f)	/* Set the amount of fees owed by a Patron */
		{
			fees = f;
		}

		/* non-modifying operations */
		std::string get_username() const	/* Return Patron object's user_name */
		{
			return user_name;
		}

		std::string get_cardnum() const	/* Return Patron object's card_num */
		{
			return card_num;
		}

		double get_fees() const	/* Return Patron object's fees owed */
		{
			return fees;
		}

	private:
		std::string user_name{};
		std::string card_num{};	// may change type later 
		double fees{};	
	};

	//=============================================================================
	// Helper functions
	//=============================================================================
	bool operator==(const Book& a, const Book& b)	/* Test if two ISBN's are the same */
	{
		return a.get_isbn() == b.get_isbn();
	}

	bool operator!=(const Book& a, const Book& b)	/* Test if two ISBN's are not the same */
	{
		return a.get_isbn() != b.get_isbn();
	}

	std::ostream& operator<<(std::ostream& os, const Book& a)	/* Format the output of a Book object*/
	{
		return os << "ISBN: " << a.get_isbn() << '\n'
			<< "Title: " << a.get_title() << '\n'
			<< "Author: " << a.get_author() << '\n'
			<< "Copyright Date: " << a.get_copyright_date() << '\n';
	}

	bool has_fee(const Patron& p)	/* Check if Patron object owes any fees */
	{
		// constant reference to Patron object so it can't be manipulated 
		bool fee = (p.get_fees() == 0) ? false : true;	// set return value based on if user has any fees
		return fee;		
	}


} // namespace Library