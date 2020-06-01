#ifndef _GOBLIN_H_
#define _GOBLIN_H_
#include "Monster.h"
class Goblin : public Monster{
public:
	Goblin(const char* newName, double newStrength, double newIntellect): Monster(newName,10,newStrength, newIntellect){}
	Goblin(const Goblin& other);
	Goblin& operator=(const Goblin& other) = default;
	~Goblin() = default;
public:
	virtual bool monsterAttack(Hero*  hero);
	virtual bool monsterDeff(double powerOfAttack);
};

#endif