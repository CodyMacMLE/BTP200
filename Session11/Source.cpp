#include <iostream>
using namespace std;

// Polymorphism:
// 1) Ad-Hoc (Fake polymorphism)
//		1.1) Coercion - Converts one type to another
//			ex. double val = 1.01; void display(int val); putting val into int function converts automatically
//		1.2) Overloading - Functions that have the same identifier, but with different parameter types
//			ex. void display(int val); void display(double val);
// 2) Universal (True polymorphism)
//		2.1) Inclusion - In an hierarchy, with virtual functions to override functions (resolved at run-time)
//		2.2) Parametric - Using template functions (resolved at compile time)

// iostreams
// >> - Extracts bytes from the stream and stores them in the second param
//		- Discards all leading blanks (space, \t, \n are included)
//		- Stops when it finds a blank, OR when the data doesn't match the type
//		- Any data that was not extracted is not discarded, but remains in the stream
//		- if it fails, sets the fail bit to true. fail() to check

// States of the Stream:
// 1) failbit, fail() - a previous operation failed, not following operations will work
// 2) badbit - Something went really bad, an unrecoverable error has occured (ex. while reading the file someone pulled the usb out, or there is hardware failure)
// 3) eofbit - a previous operation encountered EOF

// cin.get() vs. cin.getline()
//		.get() reads up to delimiter, but does not discard while .getline() discards the delimiter
//		If during the extraction encounter EOF, its set the eofbit	

// cin.peek()
// Allows you to look at the next character, but does not discard or change position stream


// cout, clog, cerr
// cout - Used to communicate with the user (average user) auto goes to screen
// clog - Goes to the standard error; informs the programmer but it doesn't mean there was an error
// cerr - Goes to the standard error; only use when something went wrong

// cout << endl; - immediate flush of buffer
// cout << '\n'; - stays in buffer until max OR flush call

int main()
{
	int a;


	cout << "An int:\n> ";
	cin >> a;
	if (cin.fail())
	{
		cout << "cin failed to extract\n";
		cin.clear(); // sets all stream state flags to false
		char buffer[100]{};
		cin.get(buffer, 100);
		cout << "The following failed characters were inputted [" << buffer << "]\n";
	}	
	else
	{
		cout << "I got [" << a << "]\n";
		cin.ignore(100000, '\n');
	}
}