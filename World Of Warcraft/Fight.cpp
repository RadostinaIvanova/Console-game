#include "Fight.h"

bool Fight::fightOfHeroAndMonster(Hero* hero,  Monster* mon)
{
	
		//if (hero.ifIsWarrior()) {
		hero->setAngerForTheWholeFight(hero->getAnger() / 5);
		hero->setAnger(0);
		//	}
		while (!hero->attackOfHero(mon) && !mon->monsterAttack(hero)) {
			std::cout << "\n____________________________________________________________\n";
		}
		if (hero->getHp() <= 0) {
			std::cout << "\nYOU LOSE! END OF GAME!\n" << std::endl;
			return false;
		}
		if (mon->getHp() <= 0) {
			std::cout << "                __    __" << std::endl;
			std::cout << std::endl;
			std::cout << "                   /\\   " << std::endl;
			std::cout << "                  ____  " << std::endl;
			std::cout << " __________________________________________________" << std::endl;
			std::cout << "|                                                  |" << std::endl;
			std::cout << "| **********YOU JUST KILLED AN ENEMY!************  |" << std::endl;
			std::cout << "|__________________________________________________|" << std::endl;
			std::cout << "Press any letter to continue the game";
			char key;
			std::cin >> key;
			system("CLS");
			system("color 0a");
			return true;
		}
		
		hero->setMana(100);
		return true;
}
