#ifndef LECTURES_CAT_H
#define LECTURES_CAT_H
#include "pet.h"

namespace lectures
{
	class Cat : public Pet // default inheritance is private
	{
		char m_furColor[50 + 1];
	public:
		Cat();
		Cat(const char* name, const char* furColor);
		Cat(const char* name, int location, int speed, const char* furColor);
		~Cat();
		void display() const;
	};
}
#endif // !LECTURES_CAT_H

// member functions/members from Pet exists in Cat, but restriction is changed to them by properties below:
// private restricts access to all members/member functions of Pet
// public gives access to the public members/member functions of Pet
// protected 