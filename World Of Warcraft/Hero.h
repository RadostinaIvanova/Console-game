#define _CRT_SECURE_NO_WARNINGS
#ifndef _HERO_H_
#define _HERO_H_
#include <cstring>
#include <iostream>
#include <fstream>
#include "Monster.h"
class Monster;

class Hero{
public:
	Hero();
	Hero(const char* newName, double newStrength, double newIntellect);
	Hero(const Hero& other);
	Hero& operator=(const Hero& other);
	virtual ~Hero();
public:
	double getIntellect() const;
	double getStrength() const;
	double getHp() const;
	const char* getName() const;

	void setHp(double newHp);

	void print() const;
public:
	virtual bool attackOfHero(Monster* mon) = 0;
	virtual bool deffOfHero(double powerOfOpponent) = 0;
	void writeHeroToFile();

public:
	virtual void setAnger(size_t newAnger) = 0;
	virtual size_t getAnger() const = 0;
	virtual void setAngerForTheWholeFight(double newAngerForWholeFight) = 0;
	virtual double getAngerForWholeFight() = 0;
	virtual void setMana(double newMana) = 0;

private:
	void copyFrom(const Hero& other);
	void clean();
	void levelUp();
private:
	char* name;
	double hp;
	double strength;
	double intellect;
	size_t level;
};
#endif 

