#include <iostream>
// Templates and Constrained Casting
using namespace std;

class Foo {
public:
	friend ostream& operator<< (ostream& ostr, Foo foo)
	{
		cout << "This is a foo string";
		return ostr;
	}
};

/*  Templates are useful in GENERIC Programming
*		Rather than making a thousand overloaded functions we can use a template
*		Which makes maintainability is easier
* 
*	When different types have the same functionality
*		ex. sorting
*/

// Rule 1: Templates are declared and implemented in headers 
//		   (if template is implemented in a .cpp it can only be used in that file)
// Rule 2: Template headers only apply to the next declaration below

// Assumption about type T(functions/operations available for T)
// - operator<<(ostream&, const T&)
// - copy constructor (because its a local copy and not a reference/pointer)
// - destructor
// If we pass by 'const T&' instead we can remove the last two restrictions


// Assumptions of T
// - copy constructor [Temp creation]
// - copy assignment [Temp creation]
// - destructor [Temp creation]
// - operator> (const T&, const T&) [comparison in if statement]
template<typename T> // Template Header
void display(T val)
{
	cout << "{" << val << "}\n";
}

template<typename T>
void sort(T* arr, int size)
{
	for (int i = 0; i < size - 1; ++i) // Selection sort
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[i] > arr[j])
			{
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

//	Assumptions of T
//	- ostream& operation<<(ostream&, const T*);
template<typename T>
void display(const T* arr, int size)
{
	for (int i = 0; i < size; ++i)
		cout << "[" << arr[i] << "] ";
	cout << "\n";
}

int main()
{
	double data = 1.234;
	display<double>(data); // <> insert type so template knows

	int value = 55;
	display<int>(value);

	Foo aFoo;
	display(aFoo);

	{
		int arr[]{ 12,87,33,23,9,72 };
		display<int>(arr, 6);
	}
	{
		double arr[]{ 12.1,87.23,33.87,23.90,9.00,72.104 };
		display<double>(arr, 6);
		sort<double>(arr, 6);
		display<double>(arr, 6);
	}
	
	// Casting Operators - converting in a safe way

	// C-style casting
	double val = 19.12;
	int data = (double)val; // this is dangerous, because it provides minumum checks to convert

	// 1. Static Cast --- static_cast<DST_T>(SRC_T)
	{
		int result = static_cast<int>(val);
		//SRC_TYPE & DEST_TYPE must be compatible (numeric types are compatible)
		// - all fundamental types are compatible
		// - if SRC_T or DST_T are custom, then casting type for SRC_T is implemented
		// - casting constructor is implemented for the DST_T
		// - SRC_T & DST_T are on the same heirarchy
		cout << "static_cast: " << result;
	}
	// 2. Dynamic Cast --- dynamic_cast<DST_T>(SRC_T)
	{
		// - Checking for:
		// - DST_T & SRC_T must be on the same heirarchy
		// - On that heirarchy, polymorphism must be enabled
		// - DST_T & SRC_T are either both references or pointers

		// Returns null if failed at run-time (checks pointers/references at run-time)


		// Down Casting --- dynamic_cast<Derived>(Base)
		// May not pass

		// Up Casting --- dynamic_cast<Base>(Derived)
		// Always succeeds
	}
	// 3. const_cast --- const_cast<DST_T>(const SRC_T)
	{
		// rarely used, usually the sign of a bad design

		// - DST_T & SRC_T are the same variable, butconst on DST_T has been removed
		// - DST_T & SRC_T are either both references or pointers
	}
	// 4. Reinterpret Cast --- reinterpret_cast<DST_T>SRC_T)
	{
		// only for programmers who know what they are doing - do not use yet

		// - DST_T & SRC_T have he same number of bytes (ie char = 1, char vs. char = good)
	}
}