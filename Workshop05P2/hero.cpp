#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "hero.h"

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// February 14th, 2024

using namespace std;
namespace seneca {

	Hero::Hero() : m_name{ nullptr }, m_abilities{ nullptr }, m_cntAbilities{ 0 }, m_level{ 0 }
	{}

	Hero::Hero(const char* name, const Ability* abilities, int cntAbilities)
	{
		*this = Hero();
		if (name != nullptr || name[0] != '\0')
		{
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_abilities = new Ability[cntAbilities];
			for (auto i = 0; i < cntAbilities; ++i)
			{
				if(abilities[i])
				m_abilities[i] = abilities[i];
			}
			m_cntAbilities = cntAbilities;
			m_level = 1;
		}
	}

	Hero::~Hero()
	{
		delete[] m_name;
		delete[] m_abilities;
	}

	Hero::operator bool() const
	{
		return (m_level > 0) ? true : false;
	}

	Hero::operator const char* () const
	{
		return (*this) ? m_name : "Not a Hero";
	}

	Hero::operator int() const
	{
		int power = 0;
		if (*this)
		{
			for (auto i = 0; i < m_cntAbilities; ++i)
				power += int(m_abilities[i]);
			power *= m_level;
		}
		return power;
	}

	Hero& Hero::operator += (const Ability& ability)
	{
		if (*this && ability)
		{
			Ability* temp = new Ability[m_cntAbilities + 1];
			for (auto i = 0; i < m_cntAbilities; ++i)
				temp[i] = m_abilities[i];
			temp[m_cntAbilities] = ability;
			
			++m_cntAbilities;
			delete[] m_abilities;
			m_abilities = new Ability[m_cntAbilities];
			for (auto i = 0; i < m_cntAbilities; ++i)
				m_abilities[i] = temp[i];
			delete[] temp;
		}
		return *this;
	}

	Hero& Hero::operator += (int lvlchange)
	{
		if (*this)
		{
			m_level += lvlchange;
			if (m_level < 1)
				m_level = 1;
		}
		return *this;
	}

	Hero& Hero::operator ++ ()
	{
		if (*this)
			++m_level;
		return *this;
	}

	void Hero::display() const
	{
		cout << (const char*)*this << " (lvl: " << m_level << ", str: " << (int)*this << ")" << endl;
		for (auto i = 0; i < m_cntAbilities; ++i)
		{
			cout << "  - " << (const char*)m_abilities[i] << " (" << (int)m_abilities[i] << ")" << endl;
		}
	}

	bool operator< (const Hero& h1, const Hero& h2)
	{
		return (int)h1 < (int)h2 ? true : false; // does it return false when equal?
	}

	bool operator> (const Hero& h1, const Hero& h2)
	{
		return (int)h1 > (int)h2 ? true : false; // does it return false when equal?
	}

	Hero& operator>> (const Ability& ability, Hero& hero)
	{
		return hero += ability;
	}

	Hero& operator<< (Hero& hero, const Ability& ability)
	{
		return hero += ability;
	}
}