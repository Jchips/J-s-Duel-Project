#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Wands.h"

class arena {
public:
	player playerInstance;
	enemy enemyInstance;
	int arena_min;
	int arena_max;
	bool isTurn;
	bool win;
	int distanceAway;
	int response;
	bool isPlayer;

	int distance(player, enemy);
	void battle(player p, enemy e);
	void fight(player p, enemy e);
	void fightOptions(player p);
	void attack(player p, enemy e);
	arena();
};





