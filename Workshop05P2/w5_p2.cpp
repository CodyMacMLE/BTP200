#include <iostream>
#include "hero.h"
#include "hero.h" // intentional
#include "ability.h"
#include "ability.h"  // intentional

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// February 14th, 2024

int cout = 0; // prevents compilation if headers don't follow convention

int main()
{
	seneca::Ability abilities[]{
		/*               NAME                       ABILITY_STRENGTH */
		seneca::Ability( "Flying",                   2 ), //  0
		seneca::Ability( "Laser Eye",                8 ), //  1
		seneca::Ability( "Freezing Breath",          8 ), //  2
		seneca::Ability( "Super strength",           2 ), //  3
		seneca::Ability( "Super Speed",              8 ), //  4
		seneca::Ability( "Super Healing",            5 ), //  5
		seneca::Ability( "Telepathy",                9 ), //  6
		seneca::Ability( "Water Bending",            9 ), //  7
		seneca::Ability( "Animal telepathy",         9 ), //  8
		seneca::Ability( "Strong Will",             10 ), //  9
		seneca::Ability( "Phasing through objects", 10 ), // 10
		seneca::Ability( "Regeneration",             5 ), // 11
	};

	seneca::Hero heroes[5] = {
		/*            NAME                  ABILITIES      NUMBER_OF_ABILITIES */
		seneca::Hero( "Superman",            abilities,    4 ),
		seneca::Hero( "Flash",              &abilities[4], 2 ),
		seneca::Hero( "Martian-Man-Hunter", &abilities[6], 1 ),
		seneca::Hero( "Aquaman",            &abilities[7], 2 ),
		seneca::Hero( "Green Lantern",      &abilities[9], 1 ),
	};

	// Test 1
	std::cout << "T1: Testing the display function and constructors.\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	for (int i = 0; i < 5; ++i)
	{
		// will not compile if the display function is not a query
		const seneca::Hero& theHero = heroes[i];
		theHero.display();
	}
	std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";


// Test 2
	std::cout << "T2: Testing the +=/++ operators (level increase).\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	++(++heroes[0]);
	heroes[0].display();
	for (auto i = 1; i < 5; ++i)
	{
		heroes[i] += i;
		heroes[i].display();
	}
	std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";


	// Test 3
	std::cout << "T3: Testing the operator+= with negative parameters.\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	heroes[4] += -2;
	heroes[4].display();
	heroes[3] += -20;
	heroes[3].display();
	std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";


	// Test 4
	std::cout << "T4: Testing the other += operator (add abilities).\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	(heroes[2] += abilities[0]) += abilities[3];
	heroes[2].display();
	heroes[2] += abilities[10];
	heroes[2].display();
	std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";

	// Test 5
	std::cout << "T5: Testing insertion operators.\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	abilities[3] >> heroes[3];
	heroes[3].display();
	heroes[4] << abilities[11];
	heroes[4].display();
	std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";

	// Test 6
	std::cout << "T6: Testing the comparison/conversion operators.\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	// will not compile if the comparison/conversion operators are not queries
	const seneca::Hero& one = heroes[0];
	const seneca::Hero& another = heroes[1];
	std::cout << (const char*)one << " (" << (int)one << ")"
			<< " stronger than "
			<< (const char*)another << " (" << (int)another << ")? -> "
			<< (one > another ? "yes" : "no") << "\n";

	std::cout << (const char*)another << " (" << (int)another << ")"
			<< " stronger than "
			<< (const char*)one << " (" << (int)one << ")? -> "
			<< (another > one ? "yes" : "no") << "\n";
	std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n";

	return cout;
}
