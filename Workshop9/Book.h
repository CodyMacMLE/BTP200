#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <iostream>
#include "LibraryItem.h"

namespace seneca {
	class Book : public LibraryItem 
	{
		/// <summary>
		/// Author of the book
		/// </summary>
		char* m_author;
	
	public:
		/// <summary>
		/// Constructor takes three parameters: title, year, and author.
		/// </summary>
		/// <param name="title"></param>
		/// <param name="year"></param>
		/// <param name="author"></param>
		Book(const char* title, int year, const char* author);

		/// <summary>
		/// Copy constructor
		/// </summary>
		/// <param name="that"></param>
		Book(const Book& that);

		/// <summary>
		/// Destructor handles m_author
		/// </summary>
		~Book();


		/// <summary>
		/// Copy Assignment
		/// </summary>
		/// <param name="that"></param>
		/// <returns></returns>
		Book& operator= (const Book& that);

		/// <summary>
		/// This method should display the title, year, and author of the book as follows
		/// </summary>
		/// <param name="ostr"></param>
		/// <returns></returns>
		std::ostream& display(std::ostream& ostr = std::cout) const;

		/// <summary>
		/// This method checks for non-null author names and checks to see if the object's author name is lexicographically greater than the other object's author name
		/// </summary>
		/// <param name="that"></param>
		/// <returns>it returns true; otherwise, it returns false</returns>
		bool operator>(const Book& that) const;
	};
}
#endif // !SENECA_BOOK_H

