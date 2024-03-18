#include <iostream>
#include "Wizzard.h"

using namespace std;

Wizzard::Wizzard() : GameCharacter("Oz")
{
	cout << this << "  -> Wizzard()\n";
}

Wizzard::~Wizzard()
{
	cout << this << "  -> ~Wizzard()\n";
}

void Wizzard::move()
{
	cout << this << "  ->  Wizzard::move()\n";
	cout << "    The wizzard is flying to the destination.\n";
}

float Wizzard::getPower() const
{
	return 987.654;
}