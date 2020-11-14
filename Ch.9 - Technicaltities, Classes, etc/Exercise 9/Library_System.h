#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <limits>
#include <cctype>

/* TO DO: Figure out how to add a Genre to the add_book() function */

namespace Library_System	// TO DO: possibly change the name of the namespace 
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

		void set_isbn(std::string i) {
			isbn = i;
		}

		void set_title(std::string t) {
			title = t;
		}

		void set_author(std::string a) {
			author = a;
		}

		void set_genre(Genre g) {
			genre = g;
		}

		void set_copyright_date(std::string c) {
			copyright_date = c;
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

		std::string get_title() const	/* Return title member of Book object */
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
		//=========================================================================
		// Book Data Members
		//=========================================================================
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
		Patron(std::string un, std::string cn, double f)	
			: user_name{ un }, card_num{ cn }, fees{ f } {};

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
		//===============================================================================
		// Patron Data Members
		//===============================================================================
		std::string user_name{};
		std::string card_num{};	// may change type later 
		double fees{};
	};

	//-----------------------------------------------------------------------------
	class Library {
	public:
		struct Transaction;		// forward declaration 
		//=============================================================================
		// Library Constructor(s)
		//=============================================================================
		Library() {};

		struct Transaction {
			/* Transaction constructor */
			Transaction(Patron p, Book b, std::string d) :
				patron{ p }, book{ b }, date{ d } {};

			Patron patron;
			Book book;
			std::string date{};	// later add the Date class to create Date object 
		};

		//=============================================================================
		// Library Member Functions 
		//=============================================================================
		/* modifying operations */
		void add_book()		/* Add a Book object to books vector */
		{	
			std::cout << "Add new book to database:" << std::endl;
			std::string isbn{};
			std::string title{};
			std::string author{};
			std::string copyright_date{};
			Genre genre;
			int genre_num{};

			// propmt for input 
			std::cout << "Enter ISBN: ";
			std::getline(std::cin, isbn);
			std::cout << "Enter title: ";
			std::getline(std::cin, title);
			std::cout << "Enter author: ";
			std::getline(std::cin, author);
			std::cout << "Enter copyright date: ";
			std::getline(std::cin, copyright_date);
			std::cout << "Enter the genre: " << std::endl;
			std::cout << "1. Fiction\t2. Nonfiction" << '\n'
				<< "3.Periodical\t4.Biography" << '\n'
				<< "5. Children's" << std::endl;
			std::cout << "> ";
			std::cin >> genre_num;												// cin leaves \n in the istream, 
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // so call ignore before getline() so it doesn't read it 
			switch (genre_num)	
			{
			case 1:
				genre = Genre::fiction;
				break;
			case 2:
				genre = Genre::nonfiction;
				break;
			case 3:
				genre = Genre::periodical;
				break;
			case 4:
				genre = Genre::biography;
				break;
			case 5:
				genre = Genre::childrens;
				break;
			default:
				break;
			}				
			Book new_book(isbn, title, author, genre, copyright_date, false);	// instantiate Book object
			books.push_back(new_book);
		}

		void add_patron()	/* Add a Patron to patrons vector*/
		{
			std::cout << "Adding a new Patron..." << std::endl;
			std::string user_name{};
			std::string card_num{};
			double fees{};	
			char c{};

			std::cout << "Enter Patron user name: ";
			std::getline(std::cin, user_name);
			std::cout << "Enter Patron card number: ";	// ideally automate card number assignment
			std::getline(std::cin, card_num);
			std::cout << "Does Patron owe any fees? (y/N) > ";
			std::cin >> c;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (tolower(c) == 'y')
			{
				std::cout << "Enter amount owed: "; 
				std::cin >> fees;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
				fees = 0;

			Patron new_patron(user_name, card_num, fees);
			patrons.push_back(new_patron);
		}

		void add_transaction(Transaction t)	/* Create new Transaction and add it to transaction vector*/
		{
			//Transaction new_transaction(p, b, d);
			transactions.push_back(t);
		}

		bool checkout_book()	/* Checkout a book from the library system */
		{
			std::cout << "Checkout Book:" << std::endl;
			// local variables to compare 
			bool user{};	// if user exists
			bool book{};	// if book exists 
			bool owes_fees{};	// if fees are owed
			std::string user_name{};
			std::string card_num{};
			std::string isbn{};

			// Check Patron (user)
			std::cout << "Enter Patron's user name: ";
			std::getline(std::cin, user_name);
			std::cout << "Enter Patron's card number: ";
			std::getline(std::cin, card_num);
			Patron test_patron(user_name, card_num, false);	// Create new object in order to compare 
			for (size_t i{ 0 }; i < patrons.size(); ++i)
			{
				if (patrons[i].get_username() == test_patron.get_username() 
					&& patrons[i].get_cardnum() == test_patron.get_cardnum())
					user = true;
			}
			//return user;

			// Check if use owes fees 
			for (size_t i{ 0 }; i < patrons.size(); ++i)
			{
				if (patrons[i].get_fees() == false)
					owes_fees = false;
				else
					owes_fees = true;
			}

			// Check Book (should only have to check ISBNs
			std::cout << "Enter ISBN of book: ";
			std::getline(std::cin, isbn);
			Book test_book;
			test_book.set_isbn(isbn);
			
			for (size_t i{ 0 }; i < books.size(); ++i)
			{
				if (books[i].get_isbn() == test_book.get_isbn() && books[i].is_checked_out() == false)
					book = true;
				else
					book = false;
			}
			//return book;



			// Test all three conditions
			if (owes_fees == true)
			{
				std::cout << "Error: User owes fees and cannot check out book" << std::endl;
				return false;
			}
			if (book == true && user == true)
			{
				std::cout << "\nChecking out book.\n"
					<< "Thank you for your patronage." << std::endl;

				Transaction new_transaction(test_patron, test_book, "8-Jun-2020");	// TO DO: fix so it records the desired book information
				add_transaction(new_transaction);
				return true;
			}
			else if (book == true && user == false)
			{
				std::cout << "Book available, but user doesn't exist" << std::endl;
				return false;
			}				
			else if (book == false && user == true)
			{
				std::cout << "User exists, but book is not available." << std::endl;
				return false;
			}
			else
			{
				std::cout << "Error: Neither book nor user exists!" << std::endl;
				return false;
			}
			
			// create a Transaction object
			// change Book's status to checked out (true) 
		}

		/* non-modifying operations */
		std::vector<Book> get_books()	/* Return vector of all books in Library object */
		{
			return books;
		}

		std::vector<Patron> get_patrons()	/* Return vector of all patrons in Library object */
		{
			return patrons;
		}

		std::vector<Transaction> get_transactions() 
		{
			return transactions;
		}


	private:
		//=============================================================================
		// Library Data Members
		//=============================================================================
		//struct Transaction {		// needed Transaction to be public for it to work, fix later to access it using a member function, keepin it private 
		//	/* Transaction constructor */
		//	Transaction(Patron p, Book b, std::string d) :
		//		patron{ p }, book{ b }, date{ d } {};

		//	Patron patron;
		//	Book book;
		//	std::string date{};	// later add the Date class to create Date object 
		//};
		// vectors for UDTs
		std::vector<Book> books{};
		std::vector<Patron> patrons{};
		std::vector<Transaction> transactions{};

	};

	//=============================================================================
	// Helper functions
	//=============================================================================
	bool operator==(const Book& a, const Book& b)	/* Test if two ISBN's are the same */
	{
		return a.get_isbn() == b.get_isbn();
	}

	bool operator==(const Patron& a, const Patron& b)
	{
		if (a.get_username() == b.get_username()
			&& a.get_cardnum() == b.get_cardnum())
			return true;
		else
			return false;
	}

	bool operator!=(const Book& a, const Book& b)	/* Test if two ISBN's are not the same */
	{
		return a.get_isbn() != b.get_isbn();
	}

	std::ostream& operator<<(std::ostream& os, const Genre& g)	/* Format the output of Genre object*/
	{
		std::string genre{};
		switch (g)
		{
		case Genre::fiction:
			genre = "fiction";
			break;
		case Genre::nonfiction:
			genre = "nonfiction";
			break;
		case Genre::periodical:
			genre = "periodical";
			break;
		case Genre::biography:
			genre = "biography";
			break;
		case Genre::childrens:
			genre = "childrens";
			break;
		default:
			break;
		}
		return os << genre;
	}

	std::ostream& operator<<(std::ostream& os, const Book& b)	/* Format the output of a Book object*/
	{
		return os << "ISBN: " << b.get_isbn() << '\n'
			<< "Title: " << b.get_title() << '\n'
			<< "Author: " << b.get_author() << '\n'
			<< "Copyright Date: " << b.get_copyright_date() << '\n'
			<< "Genre: " << b.get_genre();
	}

	std::ostream& operator<<(std::ostream& os, const Patron& p)		/* Format the output of Patron object */
	{
		std::cout << std::fixed;
		std::cout << std::setprecision(2);
		return os << "User name: " << p.get_username() << '\n'
			<< "Card number: " << p.get_cardnum() << '\n'
			<< "Fees owed: $" << p.get_fees();
	}

	std::ostream& operator<<(std::ostream& os, const Library::Transaction& t)
	{
		return os << "============================================" << '\n'
			<< "Transaction Information: " << '\n'
			<< "Date: " << t.date << '\n'
			<< "\nPatron: \n" << t.patron << '\n'
			<< "\nBook information: \n" << t.book << '\n'
			<< "============================================";
	}

	bool has_fee(const Patron& p)	/* Check if Patron object owes any fees */
	{
		bool fee = (p.get_fees() == 0) ? false : true;	// set return value based on if user has any fees
		return fee;
	}


} // namespace Library_System