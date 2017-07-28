#include "Enemy.h"
#include <iostream>
#include <string>

enemy::enemy() {
	x_pos = 0;
	health = 10;
	speed = 0;
	isAlive = true;
	spellBlock = false;

}

enemy::~enemy()
{
}

void enemy::attack(attackTypes at) {
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

void enemy::differentEnemies(enemyTypes eT)
{
	switch (eT) {
	case DEATH_EATER:
		health = 10;
		//damageOutput = 1;
		std::cout << "You are dueling a death eater" << std::endl;
		break;
	case VOLDEMORT:
		health = 20;
		//damageOutput = 2;
		std::cout << "You are dueling Voldemort" << std::endl;
		break;
	}
}

void enemy::chooseEnemies()
{
	std::cout << "Which enemy do you want to fight? (1) Death eater, or (2) Voldemort? ";
	std::cin >> response;
	switch (response) {
	case 1:
		differentEnemies(DEATH_EATER);
		break;
	case 2:
		differentEnemies(VOLDEMORT);
		break;
	}
}



bool enemy::alive() {
	if (health > 0) {
		isAlive = true;
	}
	else {
		isAlive = false;
	}
	return isAlive;
}