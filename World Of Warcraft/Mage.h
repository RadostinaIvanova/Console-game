#ifndef _MAGE_H
#define _MAGE_H_
#include "Hero.h"

class Mage : public Hero {
public:
	Mage(const char* newName);
	Mage(const Mage& other);
	Mage& operator=(const Mage& other);
	~Mage() {}
public:
	void setMana(double newMana);
public:
	virtual bool attackOfHero(Monster* other);
	virtual bool deffOfHero(double powerOfOpponent);
private:
	double mana;

	// Inherited via Hero
	virtual void setAnger(size_t newAnger) override;
	virtual size_t getAnger() const override;
	virtual void setAngerForTheWholeFight(double newAngerForWholeFight) override;
	virtual double getAngerForWholeFight() override;
};
#endif // !_MAGE_H


