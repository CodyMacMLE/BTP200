#include <cstring>
#include "book.h"

/*
namespace john
{
	int x = 10; // written by john
}

namespace sarah
{
	float x = 1.2; // written by sarah
}

char x[] = "John";

using namespace std; // exposes all identifiers from namespace "std" (if you can't find cout, also look in std namespace)
//using namespace sarah; // Shows confliction

int main()
{
	//using non-namespace std format
	std::string hello;
	std::cout << "Write a string to be repeated and press <enter>: ";
	std::cin >> hello;

	//using namespace std format
	cout << hello << std::endl 
		<< "Value of john's variable: " << john::x << std::endl 
		<< "Value of sarah's variable: " << sarah::x << std::endl
		<< ::x; // resolution operator in front of variable selects the global variable

	return 0;
}
*/



int main()
{
	Book someBook;
	// someBook.m_title = "Dune"; // C++ std forbids copy-assignment of arrays
	std::strcpy(someBook.m_title, "Dune");
	someBook.m_cntPages = 500;

	display(someBook);
	init(&someBook);
	display(someBook);

	return 0;
}

// Step over goes through the line
// Step into enters a function (helpful when function is located in another cpp file)
// Step out exits the function we are in an executes the line after in main.cpp