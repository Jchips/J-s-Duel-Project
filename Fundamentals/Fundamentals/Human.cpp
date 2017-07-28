#include "Human.h"
#include <ctime>
#include <random>



void Human::setRandomPosition(int min, int max)
{
	int RNG;
	srand(time(NULL));
	RNG = rand() % max + min;
	x_pos = RNG;
};

Human::Human()
{
	x_pos = 0;
	health = 10;
	//damageOutput = 1;
	isDisarm = false;
	isParalyzed = false;
	isTongueTied = false;
	spellBlock = false;
}


Human::~Human()
{
}
