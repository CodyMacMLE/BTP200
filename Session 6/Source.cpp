// Classes: Constructors and Destructors
#include <iostream>
#include "ResizeableArray.h"
using namespace std;
using namespace lectures;

int main()
{
	ResizeableArray col(4);
	++col;
	col += 123.456;
	col++;
	/*
	if (col)
		col.display();
	else
		cout << "Nothing in the collection" << endl;
	*/

	cout << col;
	
	/*
	col.addItem(12.34);
	col.addItem(23.45);
	col.addItem(36.29);
	col.display();

	ResizeableArray col2(10);
	col2.display();

	// add 123.456 to the collection col2; We will need to overload the operator so that it works with our custom type
	((col2 += 123.456) += 230.456) += 345.678;
	col2.display();
	(++col2).display();

	col += col2;
	col.display();
	*/
}