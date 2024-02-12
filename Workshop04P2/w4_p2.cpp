#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "guitar.h"
#include "guitar.h"  // intentional
#include "guitarString.h"
#include "guitarString.h"  // intentional

int cout = 0; // prevents compilation if headers don't follow convention

int main()
{
	seneca::GuitarString strings[]{
								seneca::GuitarString("Nylon", 0.50),
								seneca::GuitarString("Nylon", 0.50),
								seneca::GuitarString("Nylon", 0.50),
								seneca::GuitarString("Nylon", 0.50),
								seneca::GuitarString("Nylon", 0.50),
								seneca::GuitarString("Nylon", 0.50),
								seneca::GuitarString("High-Carbon Steel", 0.93),
								seneca::GuitarString("Pure Nickel", 0.81),
								seneca::GuitarString("Nickel Plated", 0.79),
								seneca::GuitarString("Cobalt", 0.95),
								seneca::GuitarString("Maraging Steel", 0.76),
								seneca::GuitarString("Bronze", 0.74),
								seneca::GuitarString("Steel",  0.92),
								seneca::GuitarString("Nylon",  0.62),
								seneca::GuitarString("Nylon",  0.77),
								seneca::GuitarString("Silver", 1.10),
	};

	{
		// TEST
		std::cout << "T1: Create an empty guitar object\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		seneca::Guitar aGuitar(nullptr);
		aGuitar.display();
		std::cout << "Has strings? [" << (aGuitar.isStrung() ? "yes" : "no") << "]\n";
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";
	}

	{
		// TEST
		std::cout << "T2: Create a guitar with a model, but no strings\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		seneca::Guitar aGuitar;
		aGuitar.display();
		std::cout << "Has strings? [" << (aGuitar.isStrung() ? "yes" : "no") << "]\n";
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";
	}

	{
		// TEST
		std::cout << "T3: Create a guitar with another model, but no strings\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		seneca::Guitar aGuitar("Les Paul");
		aGuitar.display();
		std::cout << "Has strings? [" << (aGuitar.isStrung() ? "yes" : "no") << "]\n";
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";
	}

	{
		// TEST
		std::cout << "T4: Create a complete guitar object\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		seneca::Guitar aGuitar(strings + 6, 6, "Yamaha C40II Classical Guitar");
		std::cout << "Has strings? [" << (aGuitar.isStrung() ? "yes" : "no") << "]\n";
		aGuitar.display();
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";
	}

	// TEST
	std::cout << "T5: Create a complete guitar object with more strings\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	seneca::Guitar aGuitar(strings, 12, "Cordoba F7 Acoustic Nylon String Flamenco Guitar");
	std::cout << "Has strings? [" << (aGuitar.isStrung() ? "yes" : "no") << "]\n";
	aGuitar.display();
	std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";


	// TEST
	std::cout << "T6: Change all strings\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	aGuitar.reString(strings, 6).display(std::cout);
	std::cout << "Has strings? [" << (aGuitar.isStrung() ? "yes" : "no") << "]\n";
	std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";

	// TEST
	std::cout << "T7: Change some strings\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	aGuitar.reString(strings[11], 3)
	       .reString(strings[12], 5)
	       .reString(strings[13], 0)
	       .reString(strings[14], 1)
	       .reString(strings[10], 4)
	       .reString(strings[15], 2);
	std::cout << "Has strings? [" << (aGuitar.isStrung() ? "yes" : "no") << "]\n";
	aGuitar.display();
	std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";

	// TEST
	std::cout << "T8: Remove the strings\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	aGuitar.deString().display(std::cout);
	std::cout << "Has strings? [" << (aGuitar.isStrung() ? "yes" : "no") << "]\n";
	std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n";

	return cout;
}
