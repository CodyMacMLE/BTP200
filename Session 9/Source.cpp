#include <iostream>
#include "Image.h"
#include "Painting.h"
using namespace std;

int main()
{
	Painting aPainting("John", 12.34);

	Painting Painting2(aPainting); 
	// Did not provide a copy constructor first to deep copy { base has dynamic memory, derived has static memory } 
	// dynamic memory has the same address for both, when compiled will crash because Painting2 will delete, then aPainting can't delete but tries.

	return 0;
}