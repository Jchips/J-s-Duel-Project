#pragma once
#include "Wands.h"
#include "Human.h"

enum enemyTypes { DEATH_EATER, VOLDEMORT };

class enemy : public Human {
public:
	wand m_wand;
	bool hasWand;
	bool drawWand;
	bool useFist;
	bool kick;
	bool spellBlock;
	int response;

	attackTypes fight;
	void attack(attackTypes);

	void differentEnemies(enemyTypes);
	void chooseEnemies();
		
	bool alive();
	enemyTypes eT;


	enemy();
	~enemy();
};