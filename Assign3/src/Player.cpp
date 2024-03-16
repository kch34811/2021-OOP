#include <iostream>
#include"Player.h"
#include"LinkedList.h"

void Player::act(const LinkedList* opponent) {
	std::cout << "Cooperating(1) or Cheating(0)?" << std::endl;
	int act;
	do {
		std::cin >> act;
		if (!(act == 1 || act == 0)) {
			std::cout << "Invalid Input!" << std::endl;
		}
	} while (!(act == 1 || act == 0));
	set_action(act);
}