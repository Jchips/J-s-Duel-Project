#include "Arena.h"
#include "Player.h"
#include "Enemy.h"
#include "Wands.h"
#include "Human.h"
#include <string>
#include <iostream>
#include <math.h>
using namespace std;


arena::arena() {
	arena_min = 0;
	arena_max = 100;
	isTurn = true;
	isPlayer = true;
	//distanceAway = distance(player, enemy); //Put actual name for player, and computer name for enemy
}

int arena::distance(player p, enemy e) {
	int distance = abs(e.x_pos - p.x_pos);
	return distance;
}

void arena::battle(player p, enemy e) {
	p.setRandomPosition(arena_min, arena_max);
	e.setRandomPosition(arena_min, arena_max);

	cout << "Get ready for your fight, " << playerInstance.name << endl;

	while (playerInstance.health > 0 || enemyInstance.health > 0) {
		attack(p, e);
		fight(p, e);
		
	}

	if (playerInstance.health > 0 && enemyInstance.health < 0) {
		cout << "You beat your opponent in this duel!" << endl;
		enemyInstance.~enemy();
	}
	if (playerInstance.health < 0 && enemyInstance.health > 0) {
		cout << "Your opponent beat you in this duel" << endl;
		playerInstance.~player();
	}
}

void arena::fight(player p, enemy e)
{
	if (isTurn) {
		fightOptions(p);
		isPlayer = false;
		isTurn = false;
		system("Pause");
		
	}
	else {
		enemyInstance.m_wand.chooseRandomAttack(enemyInstance.m_wand.enemySpell, playerInstance, enemyInstance);
		isPlayer = true;
		isTurn = true;
	}
}
void arena::fightOptions(player p)
{
	if (p.hasWand = true)
	{
		cout << "Would you like to: (1) Attack, (2) Defend, or (3) See health" << endl;
		cin >> response;
		switch (response) {
		case 1:
			cout << "Which spell would you like to use?" << endl;
			cout << " " << endl;
			cout << "(1) Disarm, (2) Body bind, (3) Light, (4) Killing, (5) Tongue tying, (6) Destruct" << endl;
			cin >> response;
			switch (response) {
			case 1:
				playerInstance.m_wand.attack(playerInstance, enemyInstance, spellTypes::DISARM, true);
				break;
			case 2:
				playerInstance.m_wand.attack(playerInstance, enemyInstance, spellTypes::BODY_BIND, true);
				break;
			case 3:
				playerInstance.m_wand.attack(playerInstance, enemyInstance, spellTypes::LIGHT, true);
				break;
			case 4:
				playerInstance.m_wand.attack(playerInstance, enemyInstance, spellTypes::KILLING, true);
				break;
			case 5:
				playerInstance.m_wand.attack(playerInstance, enemyInstance, spellTypes::TONGUE_TIE, true);
				break;
			case 6:
				playerInstance.m_wand.attack(playerInstance, enemyInstance, spellTypes::DESTRUCT, true);
				break;
			}
		case 2:
			playerInstance.m_wand.attack(playerInstance, enemyInstance, spellTypes::SHIELD, true);
			break;
		case 3:
			cout << "Your health is: " << playerInstance.health << endl;
			break;
		}
	}
	else {
		cout << "You were disarmed and you don't have your wand" << endl;
	}
	
}

void arena::attack(player p, enemy e) {
	if (playerInstance.spellBlock == false && enemyInstance.damageOutput >= 1) {
		cout << "Test" << endl;
		playerInstance.health = playerInstance.health - enemyInstance.damageOutput;
	} else if (playerInstance.spellBlock == true && enemyInstance.damageOutput >= 1) {
		playerInstance.health;
	}

	if (playerInstance.spellBlock == true && enemyInstance.spellBlock == true) {
		playerInstance.health;
		enemyInstance.health;
	}

	if (enemyInstance.spellBlock == false && playerInstance.damageOutput >= 1) {
		enemyInstance.health = enemyInstance.health - playerInstance.damageOutput;
	} else if (playerInstance.spellBlock == true && enemyInstance.damageOutput >= 1) {
		playerInstance.health;
	}

	cout << "Your health is now: " << playerInstance.health << endl;
	cout << "Your opponents health is now: " << enemyInstance.health << endl;
}



