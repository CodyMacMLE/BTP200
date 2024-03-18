#include <iostream>
#include "Archer.h"
using namespace std;

Archer::Archer() : GameCharacter("Bob")
{
	m_range = 57.89;
	cout << this << "  ->  Archer()\n";
}
Archer::~Archer()
{
	cout << this << "  ->  ~Archer()\n";
}

void Archer::move()
{
	cout << this << "  ->  Archer::move()\n";
	cout << "   The archer is runnin very fast towards its target.\n";
}

float Archer::getPower() const
{
	return 123.456;
}