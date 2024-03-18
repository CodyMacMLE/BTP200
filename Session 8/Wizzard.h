#pragma once
#include "GameCharacter.h"
class Wizzard : public GameCharacter
{
public:
	Wizzard();
	~Wizzard();
	void move() override;
	float getPower() const override;
};

