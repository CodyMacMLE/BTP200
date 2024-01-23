// This prevents VS compiler from issuing warnings/errors related to utilization
//   of unsafe string functions.  Has no effect in g++.
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include "DataHandle.h"
#include "Movie.h"

using namespace std;

namespace seneca {

	/// <summary>
	/// The file descriptor; will be set when a file is open with
	///   `openFile`, and reset when the file is closed with `closeFile`.
	/// </summary>
	FILE* g_fptr;

	bool openFile(const char filename[])
	{
		bool allGood = false;
		if (g_fptr == nullptr)
		{
			g_fptr = fopen(filename, "r");
			allGood = g_fptr != nullptr;
		}
		return allGood;
	}

	void closeFile()
	{
		if (g_fptr)
		{
			fclose(g_fptr);
			g_fptr = nullptr;
		}
	}

	int getRecordsCount()
	{
		int noOfRecs = -1;

		if (g_fptr != nullptr)
		{
			// get current position in the file.
			auto currentPosition = std::ftell(g_fptr);

			// go to the begining of the file
			std::fseek(g_fptr, 0, SEEK_SET);

			// start counting from "0"
			noOfRecs = 0;

			// read from file a character at a time, and count '\n'
			char ch{};
			while (fscanf(g_fptr, "%c", &ch) == 1)
			{
				noOfRecs += (ch == '\n');
			}

			// done counting, reposition the cursor to the original location
			std::fseek(g_fptr, currentPosition, SEEK_SET);
		}
		return noOfRecs;
	}

	// TODO: define below all the functions from this module

	/* TODO: add the prototype of the `read` function that receives as a parameter
	*         a single character and returns the address of a dynamically allocated
	*         C-string. Implement it in the cpp file as described below.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* read()
	* - create a local variable that will store the number of characters
	*     that must be extracted from the file. This is your counter.
	*     Initialize it with 0.
	* - using `std::ftell()`, find the position in the file. Store the returned
	*      value in a local variable.
	* - in a loop, extract one character at a time from the file using
	*     `std::fscanf()`. If the extracted character is not the delimiter,
	*     increment the counter. If nothing was extracted from file or the
	*     delimiter was found, stop the loop.
	* - using `std::fseek()` reposition the cursor in file at the beginning
	*     of the token. Pass as second parameter the position returned by
	*     `std::ftell()` above, and pass `SEEK_SET` as the third parameter.
	* - create a pointer to `char` that will store the address of the array
	*     extracted from file. This is the extracted token from the file.
	*     Initialize the pointer with null.
	* - allocate dynamic memory for the array of characters. The amount of
	*     memory is the counter + 1 (to make room for the null byte).
	* - in a loop, extract one character at a time from the file using
	*     `std::fscanf()`. If the extracted character is not the delimiter,
	*     store it in the array at the next available position. If nothing
	*     was extracted from file or the delimiter was found, stop the loop.
	* - return the address of the array of characters.
	*
	* Documentation to read:
	* - `std::ftell`   - https://en.cppreference.com/w/cpp/io/c/ftell
	* - `std::fscanf`  - https://en.cppreference.com/w/cpp/io/c/fscanf
	* - `std::fseek`   - https://en.cppreference.com/w/cpp/io/c/fseek
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	char* read(char delim)
	{
		int count = 0;
		long position = ftell(g_fptr);
		while (fscanf(g_fptr, "r") != delim)
		{
			count++;
		}
		fseek(g_fptr, position, SEEK_SET);
		char* str = nullptr;
		str = new char[count + 1];
		for (int i = 0; i < count; i++)
		{
			str[i] = fscanf(g_fptr, "r");
		}
		return str;
	}
}