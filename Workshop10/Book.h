// Cody MacDonald
// 159702232
// cmacdonald33@myseneca.ca
// April 03, 2024

// Module supplied
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include<iostream>

namespace seneca
{
	class Student; // forward declaration

	class Book
	{
		char m_title[256];
		int m_numPages;
		double m_price;
		char m_progs[5][32];
		int m_numProgs;
	public:
		Book();
		Book(const char* title, int pages, double price, const char* disciplines, int numDisciplines);
		const char* Discipline(int n) const;
		int NumDsicplines() const;
		bool operator==(int) const;
		bool operator==(double) const;
		bool operator==(const Student& stu) const;
		std::ostream& display(std::ostream&) const;
	};

	std::ostream& operator<<(std::ostream&, const Book&);
}

#endif
