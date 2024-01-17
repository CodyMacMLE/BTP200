// Foundamental Types (Comes with the hardware, APU/FPU in CPU)
	// Integers:        bool (1 bit), char (1 byte), short (2 bytes), int (2 - 4 bytes), long (8 bytes), long long (8 - 16 bytes)
	// Floating Points: float (4 bytes), double (8 bytes), long double (8-16 bytes)

#include <iostream>
using namespace std;

// Function Overloading
void bar() // Prototype: type, name, and parameters // Signature: name and parameters
{
	for (int i = 0; i < 5; ++i)
		cout << '*';
	cout << endl;
}

/* Unnecessary function due to function below with default value

void bar(int size) // Overloading allows changing the signature so we can run the same function with slight changes
{
	for (int i = 0; i < size; ++i)
		cout << '*';
	cout << endl;
}

*/

void bar(int size, char printed = '*') // adding one more with a default value
{
	for (int i = 0; i < size; ++i)
		cout << printed;
	cout << endl;
}

void changeMe(int& someInt)
{
	someInt = 123;
}

int main()
{
	bar();
	bar(10);
	bar(15, '$');

	// References
	int value = 11;
	// '&' creates a reference to an object of type 'int'
	int& refToInt = value;
	cout << "[" << value << "][" << refToInt << "]" << endl;

	value = 10;
	cout << "[" << value << "][" << refToInt << "]" << endl;

	refToInt = 5;
	cout << "[" << value << "][" << refToInt << "]" << endl;

	cout << "[" << &value << "][" << &refToInt << "]" << endl;


	changeMe(refToInt);
	cout << "[" << value << "]" << endl;


}