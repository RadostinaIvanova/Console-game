#ifndef _PALADIN_H_
#define _PALADIN_H_
#include "Hero.h"
class Paladin :public Hero{
public:
	Paladin(const char* newName);
	Paladin(const Paladin& other);
	Paladin& operator=(const Paladin& other);
	~Paladin() {}
public:
	void setCounter(const size_t newCounter);
	size_t getCounter() const;
public:
	virtual bool attackOfHero(Monster* mon);
	virtual bool deffOfHero(double powerOfOpponent);
private:
	size_t counter;
	// Inherited via Hero
	virtual void setAnger(size_t newAnger) override;
	virtual size_t getAnger() const override;
	virtual void setAngerForTheWholeFight(double newAngerForWholeFight) override;
	virtual double getAngerForWholeFight() override;
	virtual void setMana(double newMana) override;
	// counterOfAttacks;
};

#endif