#include <iostream>
//#include <crtdbg.h>
#include "Vendor.h"
#include "IceCream.h"

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// February 2nd, 2024

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
	std::cout << "Seneca IceCream Shop" << std::endl
		      << "       @" << std::endl
		      << "     (' .)" << std::endl
		      << "    (*.`. )" << std::endl
		      << "     \\###/" << std::endl
		      << "      \\#/" << std::endl
		      << "       V" << std::endl
	          << "Price List:" << std::endl
		      << "------------------------------------\n"
		      << "- Chocolate ........ $1.24 / scoop -\n"
		      << "- Tutti Frutti ..... $1.50 / scoop -\n"
		      << "- Other Flavours ... $0.99 / scoop -\n"
		      << "- Vanilla Waffer ... $0.50 / each  -\n"
		      << "------------------------------------\n";

	seneca::Vendor vendor;
	vendor.openShop();

	// change the filling character
	std::cout.fill('*');

	// Test 1: Checking the default formatting options
	checkOutputFomatting("\n\nT1: Default output formatting options");


	// Test 2: First Customer
	std::cout << "\n\nT2: First Customer\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	vendor.startNewOrder();
	vendor.addToOrder("Tutti Frutti", 2, false); // OK
	vendor.addToOrder("", 1, true);              // Rejected, no flavour
	vendor.addToOrder("Almond Crunch", 1, true); // OK
	vendor.addToOrder("Mango", 4, true);         // Rejected, too many scoops
	vendor.addToOrder("Strawberry", -1, true);   // Rejected, too few scoops
	vendor.addToOrder("Chocolate", 3, true);     // OK
	vendor.addToOrder("Tutti Frutti", 1, true);  // Rejected, already in the order
	vendor.addToOrder("Strawberry", 3, false);    // OK
	vendor.displayOrderReceipt();


	// Test 3: Second Customer
	std::cout << "\n\nT3: Second Customer\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	vendor.startNewOrder();
	vendor.addToOrder("Chocolate", 2, false);    // OK
	vendor.addToOrder("Chocolate", 2, false);    // Rejected, already in the order
	vendor.addToOrder("Strawberry", 2, true);    // OK
	vendor.displayOrderReceipt();

	// Test 4: Third Customer
	std::cout << "\n\nT4: Third Customer\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	vendor.startNewOrder();
	vendor.addToOrder("Mango", 3, false);         // OK
	vendor.addToOrder("Chocolate", 2, true);     // OK
	vendor.addToOrder("Mint", 2, true);           // OK
	vendor.addToOrder("Buttermilk", 2, false);     // OK
	vendor.addToOrder("French Vanilla", 3, true); // OK
	vendor.displayOrderReceipt();

	// Test 4: Checking the default formatting options
	checkOutputFomatting("\n\nT5: Default output formatting options");


	vendor.closeShop();
	//_CrtDumpMemoryLeaks();
	return cout;
}
