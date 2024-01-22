// Cody MacDonald
// 159702232
// cmacdonald33@myseneca.ca
// January 19th, 2024

/***********************************************************************
// Workshop 1 # p2: tester program
//
// File	main.cpp
// Version 1.0
// Date	 winter 2024
// Author Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "mark.h"

int main()
{
	bool done = false;
	char filename[256];
	while (!done)
	{
		std::cout << "Enter filename to generate report for or 'X' to exit:\n"
			">> ";
		std::cin >> filename;
		if ((filename[0] == 'X' || filename[0] == 'x') && filename[1] == 0)
			done = true;
		else if (!seneca::printReport(filename))
			std::cout << "Cannot open '" << filename << "'!\n";
	}

	std::cout << "Exiting program. Bye!\n";
}