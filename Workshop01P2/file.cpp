#define _CRT_SECURE_NO_WARNINGS // prevents some warning in VS compiler; has no effect in g++
#include <cstdio>
#include "file.h"
#include "mark.h"

// Cody MacDonald
// 159702232
// cmacdonald33@myseneca.ca
// January 19th, 2024

namespace seneca
{
	/// <summary>
	/// The descriptor of the file once it's opened.
	/// </summary>
	std::FILE* g_fileptr = nullptr;

	bool openFile(const char* fname)
	{
		// check if a file was already open; if yes, close it to prevent memory leaks
		if (g_fileptr != nullptr)
			closeFile();

		// open the new file for reading
		g_fileptr = fopen(fname, "r");

		// return true if the file successfully open
		return g_fileptr != nullptr;
	}

	void closeFile()
	{
		// check if a file is already open
		if (g_fileptr)
		{
			fclose(g_fileptr);
			g_fileptr = nullptr;
		}
	}

	bool readSingleMark(Mark* markRec)
	{
		return fscanf(g_fileptr, "%[^,],%[^,],%d\n", markRec->m_firstName, markRec->m_lastName, &markRec->m_mark) == 3;
	}

	int readAllMarks(Mark* marks)
	{
		int cnt = 0;
		for (; cnt < MAX_NO_RECS && readSingleMark(&marks[cnt]); cnt++);
		return cnt;
	}
}