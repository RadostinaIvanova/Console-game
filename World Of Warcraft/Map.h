#ifndef _MAP_H_
#define _MAP_H_
#include "Fight.h"
#include "DeadKnight.h"
#include "Dragonkin.h"
#include "Goblin.h"
#include <stdlib.h>
#include <time.h>
const unsigned int MAX= 6;

class Map{
public:
	Map();
public:
	Monster* getMonster(size_t i, size_t j) const;
private:
	Monster*** map;
};

#endif