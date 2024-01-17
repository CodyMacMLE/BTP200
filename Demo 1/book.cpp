#include <iostream> // std headers should be included first
#include "book.h" // then we add custom headers

using namespace std;

void display(Book Book)
{
	cout << "Title: [" << Book.m_title << "]" << endl;
	cout << "Pages: [" << Book.m_cntPages << "]" << endl;
};

void init(Book* someBook)
{
	cout << "Title?: ";
	cin >> someBook -> m_title; // arrow is used when it is an address a dot can be used when it is an object
	cout << "Pages?: ";
	cin >> someBook -> m_cntPages;
};