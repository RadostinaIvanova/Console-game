#include "Dragonkin.h"

void Dragonkin::setCounter(size_t newCounter){
	counter = newCounter;
}

size_t Dragonkin::getCounter() const
{
	return counter;
}

bool Dragonkin::monsterAttack(Hero* hero)
{
	std::cout << "\n->DRAGONKIN ATTACKS! DEFFEND YOURSELF!<-" << std::endl;
	double power = 4;
	std::cout << "Power Of the Attack of your Dragonkin: " << power << std::endl;
	if ((hero->deffOfHero(power))) {  //function deffOfHero will return true if Monster is dead
		return true;                  //if hero is dead will return true
	}
	return false;                     //if hero is still alive will return false
}

bool Dragonkin::monsterDeff(double powerOfAttack){
	std::cout << std::endl;
	  std::cout << "Current Hp of Dragonkin: " << getHp() << std::endl;
	    setCounter(getCounter() + 1);
		double deffence = 0;
		double currHp = getHp();
		if (getCounter() % 3 == 0) {
			deffence = powerOfAttack / 2 - getIntellect() * 0.1;
			std::cout << "Attack power after the Deffence of Dragonkin: " << deffence << std::endl;;
			setHp(currHp - deffence);
		}
		else {
			deffence = powerOfAttack + getIntellect() * 0.1;
			std::cout << "Attack power after the Deffence of Dragonkin: " << deffence << std::endl;
			setHp(currHp - deffence);
		}
		if (getHp() > 0) {
			std::cout << "Hp of Dragonkin after the Attack: " << getHp() << std::endl;
			return false;
		}
		else {
			setHp(0);
			std::cout << "Hp of Dragonkin after the Attack: " << getHp() << std::endl;

			return true;                      // if dragonkin is dead will return true
		}
}
