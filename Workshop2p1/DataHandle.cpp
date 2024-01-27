// This prevents VS compiler from issuing warnings/errors related to utilization
//   of unsafe string functions.  Has no effect in g++.
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include "DataHandle.h"
#include "Movie.h"

/// Cody MacDonald
/// cmacdonald33@senecacollege.ca
/// 159702232
/// January 24th, 2024

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

	char* read(char delim)
	{
		int count = 0;
		long position = ftell(g_fptr);
		bool done = false;
		while(!done)
		{
			char c;
			fscanf(g_fptr, "%c", &c);
			if (c != delim) {
				count++;
			}
			else
			{
				done = true;
			}
		}
		fseek(g_fptr, position, SEEK_SET);
		char* str = nullptr;
		str = new char[count + 1];
		for (int i = 0; i < count + 1; i++)
		{
			fscanf(g_fptr, "%c", &str[i]);
		}
		str[count] = '\0';
		return str;
	}

	bool read(int& val, char delim)
	{
		bool isVal = false;
		int& dDataRef = val;

		char* str = read(delim);
		if (str != nullptr)
		{
			dDataRef = atoi(str);
			isVal = true;
		}

		delete[] str;
		str = nullptr;

		
		return isVal;
	}

	bool read(long& val, char delim)
	{
		bool isValNull = true;
		char* str = read(delim);
		if (str != nullptr)
		{
			val = atol(str);
			isValNull = false;
		}
		delete[] str;
		str = nullptr;

		return isValNull;
	}

	bool read(double& val, char delim)
	{
		bool isValNull = true;
		char* str = read(delim);
		if (str != nullptr)
		{
			val = atof(str);
			isValNull = false;
		}
		delete[] str;
		str = nullptr;

		return isValNull;
	}
}