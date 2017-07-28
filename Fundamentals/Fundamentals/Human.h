#pragma once

enum attackTypes { WAND, FISTS, KICK };

class Human
{
public:
	int speed;
	int health;
	bool isAlive;
	int x_pos;
	bool inRange;
	int damageOutput;
	bool isDisarm;
	bool isParalyzed;
	bool isTongueTied;
	bool spellBlock;

	void setRandomPosition(int min, int max);
	
	Human();
	~Human();
};

