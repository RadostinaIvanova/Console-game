#include "Warrior.h"
#include "Monster.h"
const unsigned int MAX_ANGER = 100;


Warrior::Warrior(): anger(0), angerInTheWholeFight(0){}

Warrior::Warrior(const char* newName) : Hero(newName, 13, 2), anger(1), angerInTheWholeFight(1) {}

Warrior::Warrior(const Warrior& other) : Hero(other) {
	anger = other.anger;
	angerInTheWholeFight = other.angerInTheWholeFight;
}

Warrior& Warrior::operator=(const Warrior& other){
	if (this != &other) {
		Hero::operator=(other);
		anger = other.anger;
	}
	return *this;
}

bool Warrior::attackOfHero(Monster* mon) {
	char key1;
	std::cout << "Press A to Attack" << std::endl;
	std::cin >> key1;
	while (key1 != 'A' && key1 != 'a') {
		std::cout << "Wrong Button!";
		std::cin >> key1;
	}
	std::cout << "->YOU ATTACK!<- " << std::endl;
	double power = 0;
	if (anger <= 98) {
		anger += 2;
	}
	power = (0.3 * getIntellect() + getStrength()) + ((0.3 * getIntellect() + getStrength()) * getAngerForWholeFight())/ 100;////// this is anger from the beginning of the Fight
	std::cout << "Power Of the Attack of your Hero: " << power;
	if ((mon->monsterDeff(power))) {  //function monsterDeff will return true if Monster is dead
		return true;                  //if monster is dead will return true
	}
	return false;                     //if monster is still alive will return false
}

bool Warrior::deffOfHero(double powerOfOpponent) {
	if (anger <= 97) {
		anger += 3;
	}
	double currHp = getHp();
	double deffence = powerOfOpponent * 0.98;
	std::cout << "Current Hp of Warrior: " << currHp << std::endl;
	std::cout << "Power of the attack after the deffence of Warrior: " << deffence << std::endl;
	setHp(currHp - deffence);
	std::cout << "Hp after the Attack of Monster: " << getHp() << std::endl;
	if (getHp() <= 0) { 
		return true;                 // if warrior is dead will return true
	}
	return false;                    //if warrior is alive will return false
}

double Warrior::getAngerForWholeFight()
{
	return angerInTheWholeFight;
}

void Warrior::setAnger(size_t newAnger) {
	anger = newAnger;
}

size_t Warrior::getAnger() const
{
	return anger;
}

void Warrior::setAngerForTheWholeFight(double newAngerForWholeFight) {
	angerInTheWholeFight = newAngerForWholeFight;
}

double Warrior::getAngerForWholeFight() const{
	return angerInTheWholeFight;
}
