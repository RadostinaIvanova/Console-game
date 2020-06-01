#include "Monster.h"

Monster::Monster(const char* newName,double newHp, double newStrength, double newIntellect) {
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
	strength = newStrength;
	intellect = newIntellect;
	hp = newHp;
}

Monster::Monster(const Monster& other) {
	copyFrom(other);
}

Monster& Monster::operator=(const Monster& other){
	if (this != &other) {
		clean();
		copyFrom(other);
	}
	return*this;
}

Monster::~Monster(){
	clean();
}

double Monster::getHp() const
{
	return hp;
}

double Monster::getStrength() const
{
	return strength;
}

double Monster::getIntellect() const
{
	return intellect;
}

const char* Monster::getName() const
{
	return name;
}

void Monster::setHp(double newHp){
	hp = newHp;
}

void Monster::setStrength(double newStrength){
	strength = newStrength;
}

void Monster::setName(const char* newName){
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}

void Monster::setIntellect(double newIntellect){
	intellect = newIntellect;
}

void Monster::print() const{
	std::cout << name << "!!!! " << " Hp: " << hp << " " << "Strength: " << strength << " Intellect: " << intellect << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << "\n";
}

void Monster::copyFrom(const Monster& other){
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	strength = other.strength;
	intellect = other.intellect;
	hp = other.hp;
}

void Monster::clean(){
	delete[] name;
}
