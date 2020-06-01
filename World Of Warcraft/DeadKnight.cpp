#include "DeadKnight.h"

bool DeathKnight::monsterAttack(Hero* hero){
	std::cout << "\n->DEATH KNIGHT ATTACKS! DEFFEND YOURSELF!<-" << std::endl;
	double power = 0;
	if (isGoblinAttack == true) {
		std::cout << "Power Of the Attack of your DeathKnight: " << 8 << std::endl;
		isGoblinAttack = false;
		if ((hero->deffOfHero(8))) {      //function deffOfHero will return true if Monster is dead
			return true;                  //if hero is dead will return true
		}
		else {
			return false;
		}
	}
	else {
		std::cout << "Power Of the Attack of your DeathKnight: " << 4 << std::endl;
		isGoblinAttack = true;
		if (hero->deffOfHero(3 + 0.1 * hero->getIntellect())) {
			return true;
		}
		return false;                     //if hero is still alive will return false
	}
}

bool DeathKnight::monsterDeff(double powerOfAttack) {
	std::cout << std::endl;
	counter++;
	double currHp = getHp();
	double deffence = 0;
	std::cout << "Current Hp of Death Knight: " << currHp << std::endl;
	if (counter % 3 == 0) {
		deffence = powerOfAttack / 2 - getIntellect() * 0.1;
		std::cout << "Power of the attack after the Deffence of DeathKight: " << deffence << std::endl;;
		setHp(currHp - deffence);
	}
	else {
		deffence = powerOfAttack  -   getIntellect() * 0.1;
		std::cout << "Power of the attack after the Deffence of DeathKight: " << deffence << std::endl;;
		setHp(currHp - deffence);
	}
	if (getHp() > 0) {
		std::cout << "Hp of Death Knight after the Attack: " << getHp() << std::endl;
	}
	else {
		setHp(0);
		std::cout << "Hp of Death Knight after the Attack: " << getHp() << std::endl;

		return true;                 // if death is dead will return true
	}
	return false;
}

void DeathKnight::setCounter(size_t newCounter) {
	counter = newCounter;
}

size_t DeathKnight::getCounter() const
{
	return counter;
}