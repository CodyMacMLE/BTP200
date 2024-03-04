#include "foo.h"
#include "foo.h"

void Foo::set(short val = 100)
{
   if (val < 0)
	     val *= -1;
   this->m_val += val;
}
