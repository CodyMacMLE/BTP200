// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// Completion Date

/***********************************************************************
Workshop 1: Compiling modular source code
File	SeneGraph.cpp
Version 2.0
Author	Fardad Soleimanloo  2241
Description:
   This provides some source code in a single file to break
   into modules and compile together

Revision History
-----------------------------------------------------------
Name            Date            Reason
Cornel          2024.01.11      tiny changes
***********************************************************************/

#include <iostream>
using namespace std;

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
void drawLine(int length)
{
	cout << '+';
	for (int i = 0; i < length - 2; ++i)
		cout << '-';
	cout << '+' << '\n';
}

/// <summary>
/// Calculates how many digits an integer has (i.e., number `5` has 1 digit,
///   number `32` has 2 digits, number `6290` has 4 digits).
/// </summary>
/// <param name="value">the integer for which to calculate the number of digits.</param>
/// <returns>the number of digits in the parameter.</returns>
int intDigits(int value)
{
	int count = 0;

	// Count how many times the number can be divided by 10 before the result is 0.
	//   This is an integer division (the fractionary part of the result is discarded).
	do
	{
		value /= 10;
		++count;
	} while (value != 0);

	return count;
}

/// <summary>
/// Prints to screen an integer in a field of specified size. If the integer has
///   fewer digits than the field size, the rest of the field will be filled with
///   spaces.
/// </summary>
/// <param name="value">the value to be printed</param>
/// <param name="fieldWidth">the size of field</param>
void printInt(int value, int fieldWidth)
{
	// prints the value
	cout << value;

	// find how many spaces we must add after the value in order to fill the entire field
	int extraSpaces = fieldWidth - intDigits(value);

	// do the filling
	for (int i = 0; i < extraSpaces; ++i)
		cout << ' ';
}

/// <summary>
/// Moves the screen cursor backwards a specified number of positions.
/// </summary>
/// <param name="n">the number of positions to go backwards.</param>
void moveCursorBack(int n)
{
	// `\b` moves the cursor back a single position in the current line
	//   - doesn't move to a previous line
	//   - characters that are already printed on the screen are not erased
	for (int i = 0; i < n; ++i)
		cout << '\b';
}

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
void drawLineWithLabel(int length, const char* text)
{
	// print the line first (ignore the text)
	cout << '+';
	for (int i = 0; i < length - 2; ++i)
		cout << '-';
	cout << '+';


	if (text)
	{
		// move the cursor back, but leave the first 4 characters in places
		moveCursorBack(length - 4);
		// erase the exiting printed characters (the dashes) and replace them
		//   with the `text` surounded by spaces.
		cout << ' ' << text << ' ';
	}

	cout << endl;
}

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
int getInt(int min, int max)
{
	int val = min - 1;
	bool done = false;
	while (!done)
	{
		// Extract a value from user.
		// 
		// If the user types a non-integer, this program cannot use the
		//   keyboard anymore (the `cin` object will enter in error mode).
		//   The user must restart the program.
		cin >> val;
		if (val < min || max < val)
		{
			// the value is outside the boundaries of the interval
			cout << "  Invalid value! The value must be between "
				<< min << " and " << max << ".\n  Try again: ";
		}
		else
		{
			// value is good; exit the loop
			done = true;
		}
	}
	return val;
}

/// <summary>
/// Prints the text received as a parameter to the screen.
/// 
/// This function assumes that the <code>msg</code> stores the address
///   of a valid C-style string (is not null, and the string contains the null-byte
///   at the end).  If this assumption is not met, the behaviour of this function
///   is undefined (a crash, or *weird* characters on the screen).
/// </summary>
/// <param name="msg">the error text.</param>
void printMsg(const char* msg)
{
	cout << "  " << msg;
}

/// <summary>
/// Prints an error to the screen, with the text received as a parameter.
/// 
/// This function assumes that the <code>msg</code> stores the address
///   of a valid C-style string (is not null, and the string contains the null-byte
///   at the end).  If this assumption is not met, the behaviour of this function
///   is undefined (a crash, or *weird* characters on the screen).
/// </summary>
/// <param name="msg">the error text.</param>
void printErrorMsg(const char* msg)
{
	cout << "  ERROR: " << msg << endl;
}

/// <summary>
/// Prints a scaled bar relevant to the maximum value in the samples array.
/// </summary>
/// <param name="val">the of the sample to print</param>
/// <param name="max">the biggest sample in the collection</param>
void printSampleBar(int val, int max)
{
	// Calculate the bar length as the width of the graph, minus
	//   - 2 to account for the left border (`| `)
	//   - 1 to account for the space between the bar and the sample value
	//   - 2 to account for the right border (` |`)
	//   - the number of digits in `max`
	//   and scaled to `max`. This scaling ensures that the largest
	//   sample will always occupy the width of the entire graph.
	int barLength = (GRAPH_WIDTH - 5 - intDigits(max)) * val / max;
	cout << "| ";
	for (int i = 0; i < barLength; ++i)
		cout << '*';
	cout << ' ';
	printInt(val, GRAPH_WIDTH - 5 - barLength);
	cout << " |" << endl;
}

/// <summary>
/// Fills the samples array with the values read from keyboard.
/// </summary>
/// <param name="samples">the array to be filled with data</param>
/// <param name="noOfSamples">the maximum number of values to read from keyboard</param>
void getSamples(int samples[], int noOfSamples)
{
	for (int i = 0; i < noOfSamples; ++i)
	{
		cout << "  >> " << (i + 1) << "/";
		printInt(noOfSamples, 2);
		cout << ": ";
		samples[i] = getInt(1, 1000000);
	}
}

/// <summary>
/// Search in a collection of numbers, the biggest value.
/// </summary>
/// <param name="arr">an array representing the collection of integers</param>
/// <param name="arrSize">the number of integers in the collection</param>
/// <returns>the largest value from the array</returns>
int findMax(int arr[], int arrSize)
{
	int max = arr[0];
	for (int i = 1; i < arrSize; i++)
		if (max < arr[i])
			max = arr[i];

	return max;
}

/// <summary>
/// Draw a graph, allowing the user to visually compare the samples.
/// </summary>
/// <param name="samples">the collection of samples to be drawn</param>
/// <param name="noOfSamples">the number of samples in the collection</param>
/// <param name="label">the name of the graph</param>
void printGraph(int samples[], int noOfSamples, const char* label)
{
	// find which sample is the biggest. This sample will be used
	//   to scale the other sample so they can be visually compared.
	int max = findMax(samples, noOfSamples);

	printMsg("\n");
	drawLineWithLabel(GRAPH_WIDTH, label);
	for (int i = 0; i < noOfSamples; ++i)
		printSampleBar(samples[i], max);
	drawLine(GRAPH_WIDTH);
}

/// <summary>
/// Displays the user interface menu. Each menu item will have a number
///   in front of it; the user chooses an item by typing the number
///   and then pressing <kbd>enter</kbd>.
/// </summary>
/// <param name="noOfSamples">the number of sample that exist in the system</param>
/// <returns>the choice the user has made.</returns>
int menu(int noOfSamples)
{
	{
		// print the header of the menu
		cout << endl;
		drawLine(GRAPH_WIDTH);
		cout << "| Number of Samples: ";

		// print the number to fill the rest of the line
		// - subtract 21 to account for the characters printed above
		// - subtract 2 to account for the characters that come at the end
		//     of the line: ` |` (see below)
		printInt(noOfSamples, GRAPH_WIDTH - 21 - 2);
		cout << " |" << endl;

		drawLine(GRAPH_WIDTH);
	}

	// print the menu items and the prompt for user to select an item
	cout << "| 1- Set Number of Samples                                      |" << endl;
	cout << "| 2- Enter Samples                                              |" << endl;
	cout << "| 3- Graphs                                                     |" << endl;
	cout << "| 0- Exit                                                       |" << endl;
	cout << "\\ >>                                                            /";
	moveCursorBack(GRAPH_WIDTH - 5);

	return getInt(0, 3);
}

/// <summary>
/// The main function of the program.
/// </summary>
/// <returns>Always returns 0.</returns>
int main()
{
	int noOfSamples = 0;
	int samples[MAX_NO_OF_SAMPLES] = { 0 };
	bool done = false;

	drawLine(GRAPH_WIDTH);
	drawLineWithLabel(GRAPH_WIDTH, "Welcome to SeneGraph");
	drawLine(GRAPH_WIDTH);

	while (!done)
	{
		int userChoice = menu(noOfSamples);
		switch (userChoice)
		{
		case 1:
			printMsg("Enter number of available samples: ");
			noOfSamples = getInt(1, MAX_NO_OF_SAMPLES);
			break;
		case 2:
			if (noOfSamples == 0)
			{
				printErrorMsg("Number of samples must be set first!");
			}
			else
			{
				printMsg("Please enter the sample values:\n");
				getSamples(samples, noOfSamples);
			}
			break;
		case 3:
			if (noOfSamples == 0)
			{
				printErrorMsg("Number of samples must be set first!");
			}
			else if (samples[0] == 0)
			{
				printMsg("Samples missing. Please enter the sample values.\n");
			}
			else
			{
				printGraph(samples, noOfSamples, "SeneGraph");
			}
			break;
		case 0:
			printMsg("Thank you for using SeneGraph. Bye!\n");
			done = true;
		}
	}
}