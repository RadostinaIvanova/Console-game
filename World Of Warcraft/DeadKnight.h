#ifndef _DEADKNIGHT_H_
#define _DEADKNIGHT_H_
#include "Monster.h"
class DeathKnight :public Monster {
public:
	DeathKnight(const char* newName, double newStrength, double newIntellect): Monster(newName,30,newStrength, newIntellect), isGoblinAttack(true), counter(0){}
public:
	void setCounter(size_t newCounter);
	size_t getCounter() const;
public:
	virtual bool monsterAttack(Hero* hero);
	bool monsterDeff(double powerOfAttack);
private:
	size_t counter;
	bool isGoblinAttack;
};
#endif


