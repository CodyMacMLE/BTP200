#include <iostream>
#include "Movie.h"
#include "DataHandle.h"


int cout = 0; // won't compile if headers don't follow convention regarding namespaces

const int ERROR_MISSING_FILE = 1;
const int ERROR_CORRECT_FILE = 2;

int main()
{
	{
		// TEST: Check that the "read" overloads work
		std::cout << "T1: Extract various tokens from the file\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		// assume the data in the file is perfect
		seneca::openFile("tokens.txt");

		// get the first token as a C-style array of characters (delimiter is ',')
		//   - the array is dynamically allocated; after we're done
		//     with it, we must deallocate it.
		char* str = seneca::read();
		std::cout << "[" << str << "]";
		delete[] str;
		str = nullptr;
		
		// get the second token as an int (delimiter is '|')
		int iData = 0;
		seneca::read(&iData, '|');
		std::cout << "[" << iData << "]";

		// get the third token as a double (delimiter is ',')
		double dData = 0;
		seneca::read(&dData);
		std::cout << "[" << dData << "]";

		// get the fourth token as a string (delimiter is '!')
		str = seneca::read('!');
		std::cout << "[" << str << "]";
		delete[] str;

		// get the last token as a long (delimiter is ',')
		long lData = 0;
		seneca::read(&lData);
		std::cout << "[" << lData << "]\n";
		seneca::closeFile();
	}

	{
		// TEST: Check that "seneca::loadData" detects that the file is missing
		std::cout << "\n\nT2: Check missing file detection\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		if (seneca::loadData("penguin.jpg") == false)
		{
			std::cout << "[Success] Missing file correctly handled.\n";
		}
		else
		{
			std::cout << "[Error] missing file incorrectly handled. Exiting ...";
			return ERROR_MISSING_FILE;
		}
	}

	// The code below work with data from a good file (assume the file has perfect data)

	{
		// TEST: Check that "seneca::loadData" loads data from a good file
		std::cout << "\n\nT3: Check data loading with a good file\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		if (seneca::loadData("movies.csv") == false)
		{
			std::cout << "[Error] The file 'movies.csv' should be good; check if"
				"        your code contains the file in the project's folder.\n";
			return ERROR_CORRECT_FILE;
		}
		else
		{
			std::cout << "[Success] The file 'movies.csv' was loaded.\n";
		}
	}
	/*
	{
		// TEST: print some of the loaded movies
		std::cout << "\n\nT4: Show some movies loaded from file\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		seneca::display(   0); // good -> "Look Who's Talking"
		seneca::display(   1); // good -> "Driving Miss Daisy"
		seneca::display(  10); // good -> "The War of the Roses"
		seneca::display( 100); // good -> "Ace Ventura: Pet Detective"
		seneca::display( 199); // good -> "American Pie"
		seneca::display( 200); // Out of Bounds
	}

	{
		// TEST: check the display with ranges
		std::cout << "\n\nT5: Show specific ranges as loaded from file\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		seneca::display("First movies in collection", 0, 5);
		seneca::display("Movies in the middle of collection", 98, 103);
		seneca::display("Last three movies from collection", 197); // using default value for the third param
	}

	{
		// TEST: load data from a second file
		std::cout << "\n\nT6: Load a second collection of movies\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		seneca::loadData("favorites.csv"); // will generate a memory leak if memory is not properly managed
		seneca::display("My Favorites");
	}

	// cleanup: if memory is leaked, "valgrind" will flag it.
	seneca::deallocateMemory();
	*/
	return cout;
}
s