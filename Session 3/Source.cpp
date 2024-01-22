#include "person.h"

using namespace lectures;
int main() 
{
	Person aPerson;
	
	aPerson.set("John Smith", 185);
	aPerson.display(aPerson);

	aPerson.set("John Smith", -20);
	aPerson.display(aPerson);
}