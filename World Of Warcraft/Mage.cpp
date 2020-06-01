#include "Mage.h"

Mage::Mage(const char* newName): Hero(newName, 4, 11), mana(100) {}

Mage::Mage(const Mage& other): Hero(other){
	mana = other.mana;

}

Mage& Mage::operator=(const Mage& other) {
	if (this != &other) {
		Hero::operator=(other);
		mana = other.mana;
	}
	return *this;
}

void Mage::setMana(double newMana){
	mana = newMana;
}


bool Mage::attackOfHero(Monster* mon){
	char key1;
	std::cout << "Press A to Attack" << std::endl;
	std::cin >> key1;
	while (key1 != 'A' && key1 != 'a') {
		std::cout << "Wrong Button!";
		std::cin >> key1;
	}
	std::cout << "->YOU ATTACK!<-" << std::endl;
	double power = getIntellect() + ((mana / 100) * 3);
	if (mana >= 10) {
		mana -= 10;
	}
	std::cout << "Power Of the Attack of your Hero: " << power;
	if (mon->monsterDeff(power)) {  //function monsterDeff will return true if Monster is dead
		return true;                  //if monster is dead will return true
	}
	return false;                     //if monster is still alive will return false
}

bool Mage::deffOfHero(double powerOfOpponent){
	double deffence = powerOfOpponent / 4;
	std::cout << "Current Hp of Mage: " << getHp() << std::endl;
	std::cout << "Power of the Monster after the Deffence of Mage: " << deffence << std::endl;
	setHp(getHp() - deffence);
	std::cout << "Hp after the Attack of Mage: " << getHp() << std::endl;
	if (getHp() <= 0) {
		return true;                 // if Mage is dead will return true
	}
	return false;                    //if Mage is alive will return false
}

void Mage::setAnger(size_t newAnger)
{
}

size_t Mage::getAnger() const
{
	return size_t();
}

void Mage::setAngerForTheWholeFight(double newAngerForWholeFight)
{
}

double Mage::getAngerForWholeFight()
{
	return 0.0;
}

