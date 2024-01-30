#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "car.h"
#include "car.h" // intentional

int cout = 0; // won't compile if headers don't follow convention

/// <summary>
/// Prints a string, an integer, and a floating point number to the screen
///   using current formatting options (alignment & precision).
/// </summary>
/// <param name="title"></param>
void checkOutputFomatting(const char* title)
{
	std::cout << title << "\n";
	std::cout << "==========:==========:==========:==========:==========\n";

	// check filling character and alignment for strings
	std::cout << '*';
	std::cout.width(52);
	std::cout << "ABC" << "*\n";

	// check formatting for floating point numbers
	std::cout << '*';
	std::cout.width(52);
	std::cout << 1.23456789 << "*\n";

	// check formatting for integers
	std::cout << '*';
	std::cout.width(52);
	std::cout << 123 << "*\n";
}


int main()
{
	const int cntCars = 12;

	seneca::Car cars[cntCars];
	for (int i = 0; i < cntCars; ++i)
		cars[i].setEmpty();

	cars[0].set("CKZ 344",  "Volkswagen Taos",      "Blown Head Gasket", 120.1);          // valid
	cars[1].set("ABC123",   nullptr,                "Winter Tires Change", 456.89);       // invalid, bad make
	cars[2].set("CF3 4E6",  "Honda Passport",       "Steering Wheel Sticking", 75.0);     // valid
	cars[3].set("GMP 929",  "Chevrolet Colorado",   "Excessive Oil Consumption", 95.05);  // valid
	cars[4].set("ABC1234",  "Toyota Camry",         nullptr, 0.0);                        // invalid, bad description
	cars[5].set("JNI 717",  "Ford F-150 Lightning", "Dead Battery", 999.99);              // valid
	cars[6].set("DEFG1234", "",                     "Air Filter Change", 9.01);           // invalid, bad make
	cars[7].set("ABC",      "Jeep Grand Cherokee",  "", 5.0);                             // invalid, bad description
	cars[8].set("ABC 1234", "Tesla Model 3",        "Loud Tapping Noise", 50);            // valid
	cars[9].set("CBPC 344", "Ram 2500", "Intermittent Loss of Power Steering", 150.49);   // valid
	cars[10].set("",        "Ford Escape",          "Coolant Leaking Into Engine", 85.5); // invalid, bad plate

	// change the filling character
	std::cout.fill('*');

	// Test 1: Checking the default formatting options
	checkOutputFomatting("T1: Default output formatting options");

	// Test 2: Print a valid car
	std::cout << "\n\nT2: Valid car\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	cars[9].display();
	std::cout << std::endl;

	// Test 3: Print an invalid car
	std::cout << "\n\nT3: Invalid car\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	cars[11].display();
	std::cout << std::endl;

	// Test 4: Print all valid cars
	std::cout << "\n\nT4: All valid cars in the AutoService\n";
	std::cout << "==========:==========:==========:==========:==========\n";

	std::cout << "+ -- + -------- + -------------------- + ---------------------------------------- + -------- +\n";
	std::cout << "+  # |  Plate # | Car Model            |                      Problem Description |     Cost +\n";
	std::cout << "+ -- + -------- + -------------------- + ---------------------------------------- + -------- +\n";
	for (int i = 0; i < cntCars; ++i)
	{
		if (cars[i].isEmpty() == false)
		{
			std::cout << "| ";
			std::cout.width(2);
			std::cout << i + 1 << " ";
			cars[i].display();
			std::cout << std::endl;
		}
	}
	std::cout << "+ -- + -------- + -------------------- + ---------------------------------------- + -------- +\n";


	// Test 5: Print all invalid cars
	std::cout << "\n\nT5: All invalid cars in the AutoService\n";
	std::cout << "==========:==========:==========:==========:==========\n";

	std::cout << "+ -- + ------------------------------------------------------------------------------------- +\n";
	std::cout << "+  # | Reason why the car object is not valid.                                               +\n";
	std::cout << "+ -- + ------------------------------------------------------------------------------------- +\n";
	for (int i = 0; i < cntCars; ++i)
	{
		if (cars[i].isEmpty())
		{
			std::cout << "| ";
			std::cout.width(2);
			std::cout << i + 1 << " ";
			cars[i].display();
			std::cout << std::endl;
		}
	}
	std::cout << "+ -- + ------------------------------------------------------------------------------------- +\n";

	// after student's code printed some data, check
	//   if the formatting options are the same or
	//   were side effects (should not be side effects)
	checkOutputFomatting("\n\nT6: Current output formatting options");


	for (int i = 0; i < cntCars; ++i)
		cars[i].deallocateMemory();

	return cout;
}
