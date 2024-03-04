#include <iostream>
#include "pet.h"
#include "cat.h"

// Inheritance

// Higher the base = lower the specifics
// Lower the heirarchy = specialization

using namespace std;
using namespace lectures;

int main()
{
	cout << "-----------------------------------------------" << endl;
	Pet aPet("Mustang", 5, 1);
	aPet.display();
	cout << "-----------------------------------------------" << endl;

	cout << endl << "-----------------------------------------------" << endl;
	Cat aCat("SnowBall", 10, 3, "White");
	aCat.display();
	aCat.move(16);
	aCat.setName("Jerry");
	aCat.display();
	cout << "-----------------------------------------------" << endl;
}