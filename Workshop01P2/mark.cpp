#include <iostream>
#include <iomanip> // The following link helped me understand how to create trainling spaces for std::cout
#include <iostream> // https://www.phon.ucl.ac.uk/courses/spsci/abc/lesson6.htm#:~:text=By%20default%2C%20cout%20outputs%20a,output%20equal%20to%20'width'
#include <string> // The Following link helped me understand how to convert an int into a string: https://stackoverflow.com/questions/5590381/how-to-convert-int-to-string-in-c
#include "mark.h"
#include "file.h"
#include "graph.h"

// Cody MacDonald
// 159702232
// cmacdonald33@myseneca.ca
// January 19th, 2024

namespace seneca {
	/// <summary>
	/// This file prints a statistic report of the collection of marks
	///   found in a file. This function will count how many students have
	///   received marks in the interval 0%-10%, 10%-20%, 20%-30%, ..., 90%-100%.
	/// 
	/// Using a *Bar Chart*, this function will display the report in the
	///   following format:
	/// 
	/// +--- Students' Mark Distribution -----------------------------------+
	/// 100 | ************************* 3                                   |
	/// 90  | **************** 2                                            |
	/// 80  | ********************************* 4                           |
	/// 70  | ************************* 3                                   |
	/// 60  | ********************************* 4                           |
	/// 50  | ********************************* 4                           |
	/// 40  | ************************************************** 6          |
	/// 30  | *********************************************************** 7 |
	/// 20  | ************************* 3                                   |
	/// 10  | *********************************************************** 7 |
	/// +-------------------------------------------------------------------+
	/// 
	///   and then print the sorted list of all the marks found in the file.
	/// </summary>
	/// <param name="filename">stores the address of an array of characters
	///   representing the filename that holds the data with marks</param>
	/// <returns>true if the data files is opened successfully, false otherwise.</returns>
	/* TODO: define the `printReport` function
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* printReport()
	*
	* - use the function `seneca::openFile()` to open the file
	* - if the file is successfully open:
	*   - use the function `seneca::readMarks()` to load the content of the file
	*   - create an array with how many marks are in each interval
	*   - use the function `seneca::printGraph()` to print the *Bar Chart* with the
	*       number of marks in each interval
	*   - sort ascending the collection of marks based on the `m_mark` field
	*   - print all the marks in the sorted collection using the format
	*       `## : [MARK] FIRST_NAME LAST_NAME`
	*       (see sample output)
	*   - use the function `seneca::closeFile()` to close the file
	* - return true if the file was successfully open, false otherwise
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	bool printReport(const char* filename)
	{
		bool flag = seneca::openFile(filename);
		int fileLength;
		Mark studentFile[700];
		int markInterval[10] = {0,0,0,0,0,0,0,0,0,0};

		if (flag)
		{
			fileLength = seneca::readAllMarks(studentFile); // Reading File and storing in struct "studentFile" of type Mark
			seneca::assignInterval(markInterval,studentFile, fileLength);
			seneca::printGraph(markInterval, 10, "Students' Mark Distribution");
			seneca::sortByMark(studentFile, fileLength);
			seneca::printStudentFile(studentFile, fileLength);
			seneca::closeFile();
		}		
		return flag;
	}

	void assignInterval(int markInterval[], Mark* studentFile, int fileLength)
	{
		for (int i = 0; i < fileLength; i++)
		{
			if (0 <= studentFile[i].m_mark && 10 >= studentFile[i].m_mark)	    // 1 to 10
			{
				markInterval[9]++;
			}
			else if (10 < studentFile[i].m_mark && 20 >= studentFile[i].m_mark) // 11 to 20		
			{
				markInterval[8]++;
			}
			else if (20 < studentFile[i].m_mark && 30 >= studentFile[i].m_mark) // 21 to 30
			{
				markInterval[7]++;
			}
			else if (30 < studentFile[i].m_mark && 40 >= studentFile[i].m_mark) // 31 to 40
			{
				markInterval[6]++;
			}
			else if (40 < studentFile[i].m_mark && 50 >= studentFile[i].m_mark) // 41 to 50
			{
				markInterval[5]++;
			}
			else if (50 < studentFile[i].m_mark && 60 >= studentFile[i].m_mark) // 51 to 60
			{
				markInterval[4]++;
			}
			else if (60 < studentFile[i].m_mark && 70 >= studentFile[i].m_mark) // 61 to 70
			{
				markInterval[3]++;
			}
			else if (70 < studentFile[i].m_mark && 80 >= studentFile[i].m_mark) // 71 to 80
			{
				markInterval[2]++;
			}
			else if (80 < studentFile[i].m_mark && 90 >= studentFile[i].m_mark) // 81 to 90
			{
				markInterval[1]++;
			}
			else if (90 < studentFile[i].m_mark && 100 >= studentFile[i].m_mark)// 91 to 100
			{
				markInterval[0]++;
			}
		}
	}

	void sortByMark(Mark* studentFile, int fileLength)
	{
		Mark temp;
		for (int i = fileLength - 1; i > 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (studentFile[j].m_mark < studentFile[j + 1].m_mark)
				{
					temp = studentFile[j];
					studentFile[j] = studentFile[j + 1];
					studentFile[j + 1] = temp;
				}
			}
		}
	}

	void printStudentFile(Mark* studentFile, int fileLength)
	{
		for (int i = 0; i < fileLength; i++)
		{
			auto currentNo = std::to_string(i + 1);
			std::cout << std::setiosflags(std::ios::left) << std::setfill(' ') << std::setw(3) << currentNo << ": [";
			std::cout << std::setiosflags(std::ios::left) << std::setfill(' ') << std::setw(3) << studentFile[i].m_mark;
			std::cout << "] " << studentFile[i].m_firstName << " " << studentFile[i].m_lastName << std::endl;
		}
		std::cout << "------------------------------" << std::endl;
	}

};

