#ifndef SENECA_LIBRARYITEM_H
#define SENECA_LIBRARYITEM_H
#include <iostream>

namespace seneca {
	class LibraryItem {
		/// <summary>
		/// a pointer to store the address of a dynamically allocated array of characters representing the title of the item.
		/// </summary>
		char* m_title;

		/// <summary>
		/// an integer to store the publication year of the item.
		/// </summary>
		int m_year;

	public:
		/// <summary>
		/// Default constructor - sets pointer to null and year to 0
		/// </summary>
		LibraryItem();

		/// <summary>
		/// Constructor that takes two parameters: title and year and sets accordingly
		/// </summary>
		/// <param name="title">title of item</param>
		/// <param name="year">publishing year</param>
		LibraryItem(const char* title, int year);

		/// <summary>
		/// Copy Constructor
		/// </summary>
		/// <param name="that"></param>
		LibraryItem(const LibraryItem& that);

		/// <summary>
		/// Destructor - deals with m_title memory
		/// </summary>
		~LibraryItem();

		/// <summary>
		/// Copy assignment operator
		/// </summary>
		/// <param name="that">object to be copied</param>
		/// <returns>newly copied object</returns>
		LibraryItem& operator= (const LibraryItem& that);

		/// <summary>
		/// This method should display the title and year of the library item
		/// </summary>
		/// <param name="ostr"></param>
		/// <returns></returns>
		virtual std::ostream& display(std::ostream& ostr = std::cout) const;
	};
}
#endif // !SENECA_LIBRARY_ITEM_H

