#include "Goblin.h"

Goblin::Goblin(const Goblin& other):Monster(other){}

bool Goblin::monsterAttack(Hero* hero){
	std::cout << "\n->GOBLIN ATTACKS! DEFFEND YOURSELF!<-" << std::endl;
	double power = 0;
	power = 3 + 0.1 * hero->getIntellect();
	std::cout << "Power of the attack of Goblin: " << power << std::endl;
	if ((hero->deffOfHero(power))) {  //function deffOfHero will return true if Monster is dead
		return true;                  //if hero is dead will return true
	}
	return false;                     //if hero is still alive will return false
}

bool Goblin::monsterDeff(double powerOfAttack){
	std::cout << std::endl;
	double currHp = getHp();
	double attackAfterDeffence = 0;
	std::cout << "Current Hp of the Goblin: " << currHp << std::endl;
	attackAfterDeffence = powerOfAttack - getStrength() * 0.2;
	if (attackAfterDeffence < 0) {
		attackAfterDeffence = -attackAfterDeffence;
	}
	std::cout << "Power of the Attack after the Deffence of Hero: " << attackAfterDeffence << std::endl;
	setHp(currHp - attackAfterDeffence);
	if (getHp() > 0) {
		std::cout << "Hp of Goblin after the Attack: " << getHp() << std::endl;
		return false;
	}
	else {
		setHp(0);
		std::cout << "Hp of Goblin after the Attack: " << getHp() << std::endl;

		return true;                      // if dragonkin is dead will return true
	}                  //if goblin is alive will return false
}

