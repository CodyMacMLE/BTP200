#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

class GameCharacter
{
	char m_name[100]{};
public:
	GameCharacter(const char* name);
	virtual ~GameCharacter();
	void display() const;
	// virtual - enables polymorphism on function "move"
	//         - requests late binding on this function
	// "=0" - the function is "pure virtual"
	// "=0" - the class is abstract (incomplete)
	// abstract classes cannot be instantiated
	virtual void move() = 0;
	virtual float getPower() const = 0;
};

#endif
