#ifndef SENECA_MARK_H
#define SENECA_MARK_H

// Cody MacDonald
// 159702232
// cmacdonald33@myseneca.ca
// January 19th, 2024

namespace seneca
{
	/// <summary>
	/// Record of a mark received by a student.
	/// </summary>
	struct Mark
	{
		/// <summary>
		/// The first name of the student.
		/// </summary>
		char m_firstName[20 + 1];
		/// <summary>
		/// The last name of the student.
		/// </summary>
		char m_lastName[30 + 1];
		/// <summary>
		/// The mark the student received (as a number between 0 and 100).
		/// </summary>
		int m_mark;
	};

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
	bool printReport(const char* filename);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="markInterval">An array that stores the # of marks per interval</param>
	/// <param name="studentFile">a list of students with type Mark</param>
	/// <param name="fileLength">number of students in file</param>
	void assignInterval(int markInterval[], Mark* studentFile, int fileLength);

	/// <summary>
	/// Sort students by mark (ascending)
	/// </summary>
	/// <param name="studentFile">a list of students with type Mark</param>
	/// <param name="fileLength">number of students in file</param>
	void sortByMark(Mark* studentFile, int fileLength);

	/// <summary>
	/// Prints all students line by line
	/// </summary>
	/// <param name="studentFile">a list of students with type Mark</param>
	/// <param name="fileLength">number of students in file</param>
	void printStudentFile(Mark* studentFile, int fileLength);

};
#endif // !SENECA_MARK_H

