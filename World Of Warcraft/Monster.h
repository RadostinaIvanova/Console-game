#ifndef  _MONSTER_H_
#define _MONSTER_H_
#include "Hero.h"
class Hero;

class Monster {
public:
	Monster() : name(nullptr), hp(0), strength(0), intellect(0) {};
	Monster(const char* newName, double hp, double newStrength, double newIntellect);
	Monster(const Monster& other);
	Monster& operator=(const Monster& other);
	virtual ~Monster();

	virtual bool monsterAttack(Hero* hero) = 0;
	virtual bool monsterDeff(double powerOfAttack) = 0;
public:
	double getHp() const;
	double getStrength() const;
	double getIntellect() const;
	const char* getName() const;

	void setHp(double newHp);
	void setStrength(double newStrength);
	void setName(const char* newName);
	void setIntellect(double newIntellect);

	void print() const;
private:
	void copyFrom(const Monster& other);
	void clean();
private:
	char* name;
	double hp;
	double strength;
	double intellect;
};
#endif 