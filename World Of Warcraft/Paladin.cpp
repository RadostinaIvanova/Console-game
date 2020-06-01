#include "Paladin.h" 
Paladin::Paladin(const char* newName): Hero(newName, 9, 6), counter(0){}

Paladin::Paladin(const Paladin& other) : Hero(other), counter(0) {}

Paladin& Paladin::operator=(const Paladin& other){
	if (this != &other) {
		Hero::operator=(other);
	}
	return *this;
}

void Paladin::setCounter(const size_t newCounter){
	counter = newCounter;
}

size_t Paladin::getCounter() const
{
	return counter;
}

bool Paladin::attackOfHero(Monster* mon){
	char key1;
	std::cout << "Press A to Attack"<< std::endl;
	std::cin >> key1;
	while (key1 != 'A' && key1 != 'a') {
		std::cout << "Wrong Button!";
		std::cin >> key1;
	}
	std::cout << "->YOU ATTACK!<-" << std::endl;
	setCounter(getCounter() + 1);
	double power = 0;
	power = 0.5 * getStrength() + 0.5 * getIntellect();
	std::cout << "Power of the attack of your hero: " << power;

	if (getCounter() == 3) {
		power += ((0.5 * getStrength() + 0.5 * getIntellect()) * (1 / 2));
		setCounter(0);
	}
	if (mon->monsterDeff(power)) {  //function monsterDeff will return true if Monster is dead
		return true;                  //if monster is dead will return true
	}
	return false;                     //if monster is still alive will return false
}
bool Paladin::deffOfHero(double powerOfOpponent) {

	double currHp = getHp();
	double powerOfTheAttackAfterDeffence = powerOfOpponent / 3;
	std::cout << "Current Hp Of the Hero: " << currHp << std::endl;
	setHp(currHp - powerOfTheAttackAfterDeffence);
	std::cout << "Power of the attack after the deffence: " << powerOfTheAttackAfterDeffence << std::endl;
	if (getHp() < 0) {
		setHp(0);
		std::cout << "Hp of Hero:" << getHp();
		return true;
	}
	if (getHp() >= 0) {
		std::cout << "Hp of Hero:" << getHp();
		return false;
	}
}

void Paladin::setAnger(size_t newAnger){}

size_t Paladin::getAnger() const
{
	return size_t();
}

void Paladin::setAngerForTheWholeFight(double newAngerForWholeFight){}

double Paladin::getAngerForWholeFight()
{
	return 0.0;
}

void Paladin::setMana(double newMana){}

