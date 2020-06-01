#include "Map.h"

Map::Map() 
{
		map = new Monster * *[MAX];
		srand(time(NULL));
		for (size_t i = 0; i < MAX; i++) {
			map[i] = new Monster * [MAX];
			for (size_t j = 0; j < MAX; j++) {
				if (rand() % 3 == 0) {
					map[i][j] = new Goblin("Goblin", rand() % 39 + 1.2, rand() % 8 + 4.1);
				}
				else if (rand() % 3 == 1) {
					map[i][j] = new Dragonkin("Dragonkin", rand() % 20 + 15.1, rand() % 4 + 4.2);
				}
				else if (rand() % 3 == 2) {
					map[i][j] = new DeathKnight("DeadKnight", rand() % 21 + 7.0, rand() % 5 + 4.0);
				}
				else
					map[i][j] = nullptr;
			}
		}
}

Monster* Map::getMonster(size_t i, size_t j) const
{
	return map[i][j];
}

