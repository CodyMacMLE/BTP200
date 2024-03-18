#pragma once
#include "GameCharacter.h"
class Archer : public GameCharacter
{
	float m_range = 12.5;
public:
	Archer();
	~Archer();
	void move();
	float getPower() const;
};

