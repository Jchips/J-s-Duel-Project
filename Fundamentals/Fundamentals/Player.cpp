#include "Player.h"
#include "Wands.h"
#include <iostream>



player::player() {
	speed = 0;
	health = 10;
	isAlive = true;	
	//damageOutput = 1;
	spellBlock = false;
	
	std::cout << "What is your name? ";
	std::cin >> name;
}

player::~player()
{
}

void player::attack(attackTypes at) {
	switch (at) {
	case WAND:
		if (hasWand) {
			drawWand = true;
		}
		else {
			drawWand = false;
		}
		break;
	case FISTS:
		useFist = true;
		break;
	case KICK:
		kick = true;
		break;
	}

}
bool player::alive() {
	if (health > 0) {
		isAlive = true;
	} else {
		isAlive = false;
	}
	return isAlive;
}

