#pragma once
// Book class declarations
#include <iostream>
#include <string>

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
		void check_in()
		{
			checked_out = false;
		}

		void check_out()
		{
			checked_out = true;
		}

		/* non-modifying operations */
		bool is_checked_out()
		{
			return checked_out;
		}

		std::string get_isbn() const // need to add const for const references
		{
			return isbn;
		}

		std::string get_title() const
		{
			return title;
		}

		std::string get_author() const
		{
			return author;
		}

		std::string get_copyright_date() const
		{
			return copyright_date;
		}

		Genre get_genre() const
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
		// TO DO: add constructors
		//=============================================================================
		// Patron Constructors
		//=============================================================================
		Patron() {};
		Patron(std::string un, std::string cn)	// chose not to set fee in constructor, they might not owe anthing
			: user_name{ un }, card_num{ cn } {};

		// TO DO: add member functions 
		//=============================================================================
		// Patron Member Functions 
		//=============================================================================

	private:
		std::string user_name{};
		std::string card_num{};	// may change type later 
		double fees{};
	};
//-----------------------------------------------------------------------------

//=============================================================================
// Helper functions
//=============================================================================
	bool operator==(const Book& a, const Book& b) // test is ISBNs are the same
	{
		return a.get_isbn() == b.get_isbn();
	}

	bool operator!=(const Book& a, const Book& b)
	{
		return a.get_isbn() != b.get_isbn();
	}

	std::ostream& operator<<(std::ostream& os, const Book& a) // format Book
	{
		return os << "ISBN: " << a.get_isbn() << '\n'
			<< "Title: " << a.get_title() << '\n'
			<< "Author: " << a.get_author() << '\n'
			<< "Copyright Date: " << a.get_copyright_date() << '\n';
	}

	// TO DO: add Patron fee helper function

} // namespace Book