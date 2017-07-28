#pragma once
#include "Wands.h"
#include "Human.h"
#include <string>


class player : public Human {
public:
	bool hasWand;
	bool drawWand;
	bool useFist;
	bool kick;
	bool spellBlock;
	wand m_wand;
	void attack(attackTypes);
	attackTypes fight;
	bool alive();
	int distance;
	std::string name;
 
	player();
	~player();


};

