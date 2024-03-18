#include <iostream>
#include <cstring>
#include "GameCharacter.h"

using namespace std;

GameCharacter::GameCharacter(const char* name)
{
	cout << this << "  ->  GameCharacter(const char*)\n";
	strcpy(m_name, name);
}
GameCharacter::~GameCharacter()
{
	cout << this << "  ->  ~GameCharacter()\n";
}

void GameCharacter::display() const
{
	cout << this << "  ->  GameCharacter::display()\n";
	cout << "    name [" << m_name << "]\n";
	cout << "    power [" << getPower() << "]\n";
}
//void GameCharacter::move()
//{
//	cout << this << "  ->  GameCharacter::move()\n"
//		<< "    " << m_name << " is moving in a boring way.\n";
//}
