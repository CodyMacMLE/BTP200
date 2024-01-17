#pragma once
struct Book
{
	char m_title[30];
	int m_cntPages;

};
/// <summary>
/// The Function will print to the screen the content of a book object
/// </summary>
/// <param name="Book">The object to be printed</param>
void display(Book Book);

/// <summary>
/// This fucntion initializes a book
/// </summary>
/// <param name="Book">Content of the book stored area</param>
void init(Book* Book);

