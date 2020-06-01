#ifndef _DRAGONKIN_H_
#define _DRAGONKIN_H_
//#include "Monster.h"
#include "Monster.h"
class Dragonkin :public Monster {
public:
	Dragonkin(const char* newName, double newStrength, double newIntellect) : Monster(newName, 30, newStrength, newIntellect), counter(0){}
public:
	void setCounter(size_t newCounter);
	size_t getCounter() const;
public:
	virtual bool monsterAttack(Hero* hero);
	virtual bool monsterDeff(double powerOfAttack);
private:
	size_t counter;
};


#endif

