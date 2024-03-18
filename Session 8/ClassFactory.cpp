#include <iostream>
#include "Archer.h"
#include "Wizzard.h"
#include "ClassFactory.h"
using namespace std;

GameCharacter* createGC()
{
	cout << "What Game Character to create? (a/w) ";
	char choice = '\0';
	cin >> choice;
	GameCharacter* result = nullptr;
	if (choice == 'a')
	{
		result = new Archer();
	}
	else
	{
		result = new Wizzard();
	}
	return result;
}