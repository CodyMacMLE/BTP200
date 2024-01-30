// Classes: Constructors and Destructors
#include <iostream>
#include "ResizeableArray.h"
using namespace std;
using namespace lectures;

int main()
{
	ResizeableArray col;
	
	col.addItem(12.34);
	col.addItem(23.45);
	col.addItem(36.29);
	col.display();
}