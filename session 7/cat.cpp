#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cat.h"

using namespace std;

namespace lectures
{
	Cat::Cat()
	{
		cout << "The Cat object at [" << this << "] == open" << endl;
		strcpy(m_furColor, "EMPTY");
	}
	Cat::Cat(const char* name, const char* furColor) : Pet(name) // this calls the constructor for Pet before Cat constructor
	{
		cout << "The Cat object at [" << this << "] == open" << endl;
	}
	Cat::Cat(const char* name, int location, int speed, const char* furColor) : Pet(name, location, speed)
	{
		cout << "The Cat object at [" << this << "] == open" << endl;
		if (furColor != nullptr || furColor[0] != '\0')
			strcpy(m_furColor, furColor);
	}
	Cat::~Cat()
	{
		cout << "The Cat object at [" << this << "] == closed" << endl;
	}
	void Cat::display() const
	{
		Pet::display();
		cout << "\tThe cat is [" << m_furColor << "]" << endl;
	}
}
