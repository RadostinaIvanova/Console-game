#include "Map.h"
#include "Warrior.h"
#include "Mage.h"
#include "Paladin.h"

const size_t LIMITS_OF_MAP = 6;

void printWin() {
	system("CLS");
	system("color 0b");
	std::cout << "                         YOU HAVE REACHED THE END OF THE MAP " << std::endl;
	std::cout << " ________________________________________________________________________________" << std::endl;
	std::cout << "|                                                                                |" << std::endl;
	std::cout << "|                                                                                |" << std::endl;
	std::cout << "|                                                                                |" << std::endl;
	std::cout << "|                     !!!!!!!!!!   YOU WIN   !!!!!!!!!                           |" << std::endl;
	std::cout << "|                                                                                |" << std::endl;
	std::cout << "|________________________________________________________________________________|" << std::endl;

	std::cout << "                                   \\     /      " << std::endl;
	std::cout << "                                    \\   /       " << std::endl;
	std::cout << "                                      O       " << std::endl;
	std::cout << "                                     ( )        " << std::endl;
	std::cout << "                                      |         " << std::endl;
	std::cout << "                                     / \\       " << std::endl;
	std::cout << "                                    /   \\      " << std::endl;
}


int main() {
	system("color 0a");
	size_t op;
	char nameOfHero[256];
	std::cout << "NEW GAME";
	std::cout << "\n Choose name of Hero: ";
	std::cin.getline(nameOfHero, 256);
	system("CLS");
	std::cout << "Choose type of Hero." << "\n";
	std::cout << "For WARRIOR type 1." << "\n";
	std::cout << "For MAGE type 2" << "\n";
	std::cout << "For PALADIN type 3" << "\n";
	std::cin >> op;
	while (op != 1 && op != 2 && op != 3) {
		std::cout << "You have pressed button that is different from 1, 2 or 3. Please try again.." << std::endl;
		std::cout << "Press 1,2 or 3 to choose type of Hero." << std::endl;
		std::cin >> op;
	}
	Hero* hero;
	switch (op) {
	case 1: {
		hero = new Warrior(nameOfHero);
		break;
	}
	case 2: {
		hero = new Mage(nameOfHero);
		break;
	}
			
	case 3: {
		hero = new Paladin(nameOfHero);
		break;
	}
	default:
		hero = new Warrior(nameOfHero);
	}
	hero->writeHeroToFile();
	system("CLS");
	Map map;
	size_t i, j;
	i = 0; j = 0;
	char key;
	Fight fight;
	std::cout << "\nYOUR HERO:" << std::endl;
	hero->print();         
	std::cout << "         O         " << std::endl;
	std::cout << "       /( )\\      " << std::endl;
	std::cout << "      /  |  \\     " << std::endl;
	std::cout << "        / \\       " << std::endl;
	std::cout << "       /   \\      " << std::endl;
	std::cout << "\nYour hero starts from the begining. Now you can choose from forward and right." << std::endl;
	char mapVisual[16][81] = {
		"################################################################################",
		"#       0   0                                                                  #",
		"#         .                                                                    #",
		"#        ^^^              __ __                __ __                           #",
		"#                           .                    .                             #",
		"#      __ __               ^^^                  ^^^                            #",
		"#        .                                                      __ __          #",
		"#       ^^^                                                       .            #",
		"#                                O   O                            0            #",
		"#                                  ^                                           #",
		"#                                 ---                @   @                     #",
		"#                                                      .                       #",
		"#         0   0                                       ^^^                      #",
		"#           .                                                                  #",
		"#          ---                                                                 #",
	    "###############################################################################" };
	for (size_t i = 0; i < 16; i++) {
			std::cout << mapVisual[i] << std::endl;
	}
	while (i < LIMITS_OF_MAP && j < LIMITS_OF_MAP) {
		std::cout << "Choose direction: " << "\n" << "W - forward, D -right" << std::endl;
		std::cin >> key;
		system("CLS");
		if (key == 'W' || key == 'w') {
			if (j < LIMITS_OF_MAP - 1) {
				j++;
				if (j == LIMITS_OF_MAP - 1 && i == LIMITS_OF_MAP - 1){
					printWin();
					break;
				}
			}
			else {
				std::cout << "You have reached the end of map on the right" << std::endl << "You can only go right. Tap only D" << std::endl;
				std::cin >> key;
			}
		}
		else if (key == 'D' || key == 'd') {
			if (i < LIMITS_OF_MAP - 1) {
				i++;
				if (j == LIMITS_OF_MAP - 1 && i == LIMITS_OF_MAP - 1) {
					printWin();
					break;
				}
			}
			else {
				std::cout << "You have reached the end of the map" << std::endl << "You can only go forward. Tap only W" << std::endl;
				std::cin >> key;
			}
		}
		else {
			std::cout << "INVALID COMMAND! YOU CAN ONLY GO FORWARD - w , RIGHT - d" << std::endl;
			continue;
		} 
		
		std::cout << "Your hero is a position X =" << i + 1 << " and Y=" << j + 1 << std::endl << std::endl;
		if ((map.getMonster(i, j)) != nullptr) {
			system("CLS");
			system("color 0c");
			std::cout << " _________________________________________________________________________  " << std::endl;
			std::cout << "|                                   o   o                                 | " << std::endl;
			std::cout << "|                                     .                                   | " << std::endl;
			std::cout << "|                                    ^^^                                  | " << std::endl;
			std::cout << "|   WATCH OUT, WATCH OUT! Enemy is on your way! FIGHT TILL YOU DIE OR HE  | " << std::endl;
			std::cout << "|_________________________________________________________________________|\n " << std::endl;
			(map.getMonster(i, j))->print();
			if (!fight.fightOfHeroAndMonster(hero, map.getMonster(i, j))){
				std::cout << "The end"; 
				break;
			}
		}
	}
	delete hero;
	return 0;
}