#include "Hero.h"

Hero::Hero() : name(nullptr), hp(0), level(0), strength(0), intellect(0) {}

Hero::Hero(const char* newName, double newStrength, double newIntellect) : hp(100), level(0) {
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
	strength = newStrength;
	intellect = newIntellect;
}

Hero::Hero(const Hero& other) {
	copyFrom(other);
}

Hero& Hero::operator=(const Hero& other) {
	if (this != &other) {
		clean();
		copyFrom(other);
	}
	return *this;
}


Hero::~Hero() {
	clean();
}

double Hero::getIntellect() const
{
	return intellect;

}

double Hero::getStrength() const
{
	return strength;

}

double Hero::getHp() const
{
	return hp;
}

const char* Hero::getName() const
{
	return name;
}

void Hero::setHp(double newHp){
	hp = newHp;
}

void Hero::print() const{
	std::cout << "Name:" << name << " Hp: " << hp << " Strength: " << strength << " Intellect: " << intellect << std::endl;
}

void Hero::writeHeroToFile(){
	std::ofstream ofile;
	ofile.open("ListOfHeroes.txt", std::ios::app);
	if (ofile.is_open()) {
		ofile << name << " ";
		ofile << hp << " ";
		ofile << strength << " ";
		ofile << intellect << "\n";
		ofile.close();
	}
}

void Hero::copyFrom(const Hero& other) {
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	hp = other.hp;
	strength = other.strength;
	intellect = other.intellect;
	level = other.level;
}

void Hero::clean() {
	delete[] name;
}

void Hero::levelUp() {
	hp = hp * 0.1 + hp;
	strength = strength / 3 + strength;
	intellect = intellect / 3 + intellect;
}
