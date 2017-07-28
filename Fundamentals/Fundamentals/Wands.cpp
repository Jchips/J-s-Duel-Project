#include "Wands.h"
#include "Player.h"
#include "Enemy.h"
#include <string>
#include <ctime>
#include <random>
#include <iostream>

wand::wand(){
	range = 10;
	broken = false;
	//damageOutput = 1;
}

wand::~wand()
{

}

void disarmAbility(player p)
{
	p.m_wand.broken = true;
}

void wand::attack(player p, enemy e, spellTypes damageType, bool isPlayer) {
	enemySpell = damageType;
	switch (damageType) {
		case SHIELD:
			if (isPlayer) {
				p.spellBlock = true;
				std::cout << "You blocked whatever spell the enemy casted at you" << std::endl;
			}
			else {
				e.spellBlock = true;
			}
			break;
		case DISARM:
			if (isPlayer) {
				//e.hasWand = false;
				std::cout << "You casted the disarm spell" << std::endl;
				if (e.spellBlock) { // If player casts disarm and the enemy blocks it, then they aren't disarmed
					e.isDisarm = false;
				}
				else { // If the enemy doesn't block it, then they are disarmed
					e.isDisarm = true;
					p.damageOutput = 1;
					e.hasWand = false;

				}
				//if (!isDisarm) {
					//p.hasWand = false;
				//}
			}
			else { // If the enemy is attacking
				//p.hasWand = false;
				if (p.spellBlock) {
					p.isDisarm = false;
				}
				else {
					p.isDisarm = true;
					e.damageOutput = 1;
					p.hasWand = false;
				}
			}
			break;
		case BODY_BIND:
			if (isPlayer) { // If player casts body bind and the enemy blocks it, then the enemy isn't paralyzed.
			//	e.hasWand = false;
				if (e.spellBlock) {
					e.isParalyzed = false;
				}
				else {
					e.isParalyzed = true;
					p.damageOutput = 1;
				}
			}
			else { // The enemy is attacking
				//p.hasWand = false;
				if (p.spellBlock) {
					p.isParalyzed = false;
				}
				else {
					p.isParalyzed = true;
					e.damageOutput = 1;
				}
			}
			break;
		case TONGUE_TIE:
			if (isPlayer) {
				//e.hasWand = false;
				if (e.spellBlock) {
					e.isTongueTied = false;
				}
				else {
					e.isTongueTied = true;
					p.damageOutput = 1;
				}
			}
			else {
				//p.hasWand = false;
				if (p.spellBlock) {
					p.isTongueTied = false;
				}
				else {
					p.isTongueTied = true;
					e.damageOutput = 1;
				}
			}
			break;
		case LIGHT:
			lightOn = true;
			break;
	}

}

void wand::chooseRandomAttack(spellTypes enemySpell, player p, enemy e)
{
	int RNG = 0;
	srand(time(NULL));
	RNG = rand() % 5 + 0; //5 is the max, 0 is the min

	switch (RNG)
	{
	case 0:
		//enemySpell = spellTypes::DISARM;
		attack(p, e, spellTypes::DISARM, false);
		std::cout << "Your opponent casted the disarm spell" << std::endl;
		break;
	case 1:
		attack(p, e, spellTypes::BODY_BIND, false);
		std::cout << "Your opponent casted the body bind spell" << std::endl;
		break;
	case 2:
		attack(p, e, spellTypes::TONGUE_TIE, false);
		std::cout << "Your opponent casted the tongue tie spell" << std::endl;
		break;
	case 3:
	case 4:
	case 5:
		attack(p, e, spellTypes::SHIELD, false);
		std::cout << "Your opponent blocked your spell" << std::endl;
	}
}