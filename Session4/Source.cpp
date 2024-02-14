// Classes: Constructors and Destructors

#include <iostream>
#include <fstream>
#include "ResizeableArray.h"
using namespace std;
using namespace lectures;

int main()
{
	ResizeableArray col(4);
	
	/*
	if (col)
		col.display();
	else
		cout << "Nothing in the collection" << endl;
	*/

	cout << col;
	
	/*
	col.addItem(12.34);
	col.addItem(23.45);
	col.addItem(36.29);
	col.display();

	ResizeableArray col2(10);
	col2.display();

	// add 123.456 to the collection col2; We will need to overload the operator so that it works with our custom type
	((col2 += 123.456) += 230.456) += 345.678;
	col2.display();
	(++col2).display();

	col += col2;
	col.display();
	*/

	// writing to a file
	/*
	std::ofstream file;
	file.open("data.txt");
	if (file.is_open())
	{
		file << "Hello world from C++!\n" << "Bye.\n";
		file << col;
		file.close();
	}
	else
	{
		std::cout << "Error: File could not be opened" << std::endl;
	}
	*/

	// reading from a file
	
	std::ifstream file;
	file.open("data.txt");
	if (file.is_open())
	{
		char* txtFromFile = new char[1] {};
		int cnt = 0;
		// do not use >> for char: it stops extracting at any blank, \n or eof
		// how it works
		// 1) finds first non-blank
		// 2) grabs data one byte at a time
		// 3.1) stops at first byte that does not make sense for data type
		// 3.2) or for char, extracts until first blank 
		while (file.good())
		{
			char token[4];
			file.getline(token, 4, '\0'); // getline(where to store, number of bytes, delimiter) : '\0' does not exist in file therefor we can remove the delimiter
			if (file.eof() == false)
			{
				cout << "The token  is [" << token << "]\n";

				char* tmp = new char[cnt + strlen(token) + 1];
				strcpy(tmp, txtFromFile);
				strcat(tmp, token);

				cnt += strlen(token);
				delete[] txtFromFile;
				txtFromFile = tmp;
				if (file.good() == false)
				{
					file.clear();
				}
			}
		}
		cout << "The content of the file is {{" << txtFromFile << "}}";
	}
	else
	{
		std::cout << "Error: File could not be opened" << std::endl;
	}
	
}

