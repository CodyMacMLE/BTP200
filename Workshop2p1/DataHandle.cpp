// This prevents VS compiler from issuing warnings/errors related to utilization
//   of unsafe string functions.  Has no effect in g++.
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
// TODO: include any other header that is necessary for your solution

using namespace std;

// TODO: put everything in the `seneca` namespace

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
