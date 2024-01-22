// TODO: Add header guard to protect against multiple inclussions
//       The header guard must follow standard conventions.

// TODO: put all the code `seneca` namespace
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
	/* TODO: add the prototype of the `read` function that receives as parameters
	*         a reference to an object of type `int` and a character, and returns a
	*         boolean value.  Implement it in the cpp file as described below.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* read()
	* - use `seneca::read()` to extract an array of characters from the file
	*     up until the delimiter is found (or the end of file is reached).
	*     Store the address of this array in a pointer (this array is dynamically
	*     allocated, and must be deallocated later).
	* - if the address received above is not null, use `std::atoi()` to convert
	*     the array of characters to an integer. Pass the array's address to
	*     `std::atoi()` and store the returned value in the parameter.
	*   - deallocate the memory used by the array of characters (the number is stored
	*       now in the parameter).
	*   - return `true`.
	* - if the address received above is null, return `false`.
	* 
	*
	* Documentation to read:
	* - `std::atoi`    - https://en.cppreference.com/w/cpp/string/byte/atoi
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/

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
	/* TODO: add the prototype of the `read` function that receives as parameters
	*         a reference to an object of type `long` and a character, and returns a
	*         boolean value.  Implement it in the cpp file as described below.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* read()
	* - similar as the previous function. Use `std::atol()` to convert
	*     the array of characters into a number.
	*
	* Documentation to read:
	* - `std::atol`    - https://en.cppreference.com/w/cpp/string/byte/atoi
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/

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
	/* TODO: add the prototype of the `read` function that receives as parameters
	*         a reference to an object of type `double` and a character, and returns a
	*         Boolean value.  Implement it in the cpp file as described below.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* read()
	* - similar as the previous function. Use `std::atof()` to convert
	*     the array of characters into a number.
	*
	* Documentation to read:
	* - `std::atof`    - https://en.cppreference.com/w/cpp/string/byte/atof
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
