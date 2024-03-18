#include <iostream>
#include "GameCharacter.h"
#include "ClassFactory.h"
using namespace std;

void doStuff(GameCharacter* theGc)
{
	// theGc - has a declared type of "GameCharacter"
	// theGc - has an actual type of "???"
	theGc->move();
	theGc->display();
}

int main()
{
	//GameCharacter gc("Fibbles");
	//doStuff(gc);
	GameCharacter* army[2]; // an array of pointers
	army[0] = createGC();
	army[1] = createGC();

	doStuff(army[0]);

	delete army[0];
	delete army[1];

//	GameCharacter* gc = createGC();
//	doStuff(gc);
//	delete gc;
}
