#ifndef NAMESPACE_IO_H // replace with relevant names, each header should have its own header guard, unique in the ENTIRE project
#define NAMESPACE_IO_H

// Cody MacDonald
// 159702232
// cmacdonald33@myseneca.ca
// January 19th, 2024

namespace seneca
{
	/// <summary>
	/// Maximum number of samples in an graph.
	/// </summary>
	const int MAX_NO_OF_SAMPLES = 20;

	/// <summary>
	/// The maximum width of the graph when drawn to the screen.
	/// </summary>
	const int GRAPH_WIDTH = 65;
	
  /// <summary>
		/// Draw on the screen a line of dashes of specified length; the first and last symbols
		///   in the line are `+`.
		/// 
		/// The line will look like this: `+------------------+`
		/// </summary>
		/// <param name="length">the length of the line (must be at least `2`).</param>
	void drawLine(int length);

	/// <summary>
		/// Calculates how many digits an integer has (i.e., number `5` has 1 digit,
		///   number `32` has 2 digits, number `6290` has 4 digits).
		/// </summary>
		/// <param name="value">the integer for which to calculate the number of digits.</param>
		/// <returns>the number of digits in the parameter.</returns>
	int intDigits(int value);

	/// <summary>
		/// Prints to screen an integer in a field of specified size. If the integer has
		///   fewer digits than the field size, the rest of the field will be filled with
		///   spaces.
		/// </summary>
		/// <param name="value">the value to be printed</param>
		/// <param name="fieldWidth">the size of field</param>
	void printInt(int value, int fieldWidth);

	/// <summary>
		/// Moves the screen cursor backwards a specified number of positions.
		/// </summary>
		/// <param name="n">the number of positions to go backwards.</param>
	void moveCursorBack(int n);

	/// <summary>
		/// Draw to the screen a line of dashes of specified length,
		///   with a label in the format: `+--- LABEL ---------------------+`
		/// 
		/// This function assumes that the `length` parameter is big enough to accommodate
		///   - the special characters used for line ending: `+`
		///   - the 3 dashes before the label
		///   - the 2 spaces surrounding the label
		///   - the label itself
		///   If this assumption is not met, the result will be **ugly**!
		/// 
		/// This function also assumes that the <code>label</code> stores the address
		///   of a valid C-style string (is not null, and the string contains the null-byte
		///   at the end).  If this assumption is not met, the behaviour of this function
		///   is undefined (a crash, or *weird* characters on the screen).
		/// </summary>
		/// <param name="length">the length of the line</param>
		/// <param name="text">the text to be printed as a label</param>
	void drawLineWithLabel(int length, const char* text);

	/// <summary>
		/// Reads from the keyboard an integer in the specified interval. If the user types
		///   a number outside of the allowed interval, this function ask user to type
		///   another one, until a valid number is extracted.
		/// 
		/// This function assumes that the user types an integer; if the user types something
		///   else, this function might enter in an infinite loop.
		/// </summary>
		/// <param name="min">the lower limit of the interval</param>
		/// <param name="max">the upper limit of the interval</param>
		/// <returns>the number in the interval the user typed</returns>
	int getInt(int min, int max);

	/// <summary>
		/// Prints the text received as a parameter to the screen.
		/// 
		/// This function assumes that the <code>msg</code> stores the address
		///   of a valid C-style string (is not null, and the string contains the null-byte
		///   at the end).  If this assumption is not met, the behaviour of this function
		///   is undefined (a crash, or *weird* characters on the screen).
		/// </summary>
		/// <param name="msg">the error text.</param>
	void printMsg(const char* msg);

	/// <summary>
		/// Prints an error to the screen, with the text received as a parameter.
		/// 
		/// This function assumes that the <code>msg</code> stores the address
		///   of a valid C-style string (is not null, and the string contains the null-byte
		///   at the end).  If this assumption is not met, the behaviour of this function
		///   is undefined (a crash, or *weird* characters on the screen).
		/// </summary>
		/// <param name="msg">the error text.</param>
	void printErrorMsg(const char* msg);

	/// <summary>
		/// Displays the user interface menu. Each menu item will have a number
		///   in front of it; the user chooses an item by typing the number
		///   and then pressing <kbd>enter</kbd>.
		/// </summary>
		/// <param name="noOfSamples">the number of sample that exist in the system</param>
		/// <returns>the choice the user has made.</returns>
	int menu(int noOfSamples);
}
#endif