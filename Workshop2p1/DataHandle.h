#ifndef W2_DATA_HANDLE_H
#define W2_DATA_HANDLE_H

namespace seneca {
	/// <summary>
	/// Opens the file specified as parameter for reading.
	///   If the file is already opened, this function does nothing
	///   and returns false.
	/// </summary>
	/// <param name="filename">The name of the file to open. Must not be null.</param>
	/// <returns>true if the files was opened, false otherwise.</returns>
	bool openFile(const char filename[]);

	/// <summary>
	/// Close the file that was previously opened with `openFile`.
	///   If no file is opened, this function does nothing.
	/// </summary>
	void closeFile();

	/// <summary>
	/// Counts how many records (lines) are in the file (a record is a line in the file).
	/// 
	/// The file must be already open for reading with `openFile`.
	/// 
	/// When the function finishes, the reading cursor will be positioned
	///   in the same place as it was found (the function has no side effects).
	/// </summary>
	/// <returns>the number of records (lines) in the file, or -1
	///   if no file is open.</returns>
	int getRecordsCount();


	/// <summary>
	/// Reads from the file an array of characters.  This function stops
	///   reading when `delim` is found in the file or when the end of the file
	///   has been reached. The delimiter is extracted from the file and discarded.
	/// 
	/// The file must be already open for reading with `openFile` 
	/// </summary>
	/// <param name="delim">the delimiter of the token to be extracted.
	///   The delimiter has comma as a default value (',').</param>
	/// <returns>the address of a dynamically allocated array of characters,
	///   containing the data extracted from the file.  The caller of this function
	///   is responsible to deallocate this array.</returns>
	char* read(char delim = ',');

	/// <summary>
	/// Reads from the file a single integer and stores it in the parameter.
	/// 
	/// This function assumes that the integer if followed by a delimiter.
	///   The delimiter is extracted and discarded.
	/// </summary>
	/// <param name="val">the function will put here the value read.</param>
	/// <param name="delim">the character following the number. The default
	///   value for the delimiter is a comma (`,`).</param>
	/// <returns>true if a number is read, false otherwise.</returns>
	bool read(int* val, char delim = ',');

	/// <summary>
	/// Reads from the file a single integer and stores it in the parameter.
	/// 
	/// This function assumes that the integer if followed by a delimiter.
	///   The delimiter is extracted and discarded.
	/// </summary>
	/// <param name="val">the function will put here the value read.</param>
	/// <param name="delim">the character following the number. The default
	///   value for the delimiter is a comma (`,`).</param>
	/// <returns>true if a number is read, false otherwise.</returns>
	bool read(long* val, char delim = ',');

	/// <summary>
	/// Reads from the file a single floating point number and stores it
	///   in the parameter.
	/// 
	/// This function assumes that the number if followed by a delimiter.
	///   The delimiter is extracted and discarded.
	/// </summary>
	/// <param name="val">the function will put here the value read.</param>
	/// <param name="delim">the character following the number. The default
	///   value for the delimiter is a comma (`,`).</param>
	/// <returns>true if a number is read, false otherwise.</returns>
	bool read(double* val, char delim = ',');
}
#endif

