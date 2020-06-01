#ifndef _WARRIOR_H_
#define _WARRIOR_H_
#include "Hero.h"
class Warrior : public Hero{
public:
	Warrior();
	Warrior(const char* newName);
	Warrior(const Warrior& other);
	Warrior& operator=(const Warrior& other);
	~Warrior() {}
public:
	virtual void setAnger(size_t newAnger);
	virtual size_t getAnger() const;
	virtual void setAngerForTheWholeFight(double newAngerForWholeFight);
	virtual double getAngerForWholeFight() const;
public:
	virtual bool attackOfHero(Monster* mon);
	virtual bool deffOfHero(double powerOfOpponent);
public:
	virtual void setMana(double newMana) {}


private:
	size_t anger;
	double angerInTheWholeFight;

	// Inherited via Hero
	virtual double getAngerForWholeFight() override;
	//size_t numOfAttacks;
};
#endif