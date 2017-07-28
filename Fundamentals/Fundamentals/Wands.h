#pragma once
class player;
class enemy;
enum spellTypes {DISARM, BODY_BIND, SHIELD, LIGHT, KILLING, TONGUE_TIE, DESTRUCT, REPAIR};
enum wandTypes {};

class wand {
public:
	bool broken;
	bool isPlayer;
	//int damageOutput;
	bool inUse;
	//bool isDisarm;
	//bool isParalyzed;
	//bool spellBlock;
	//bool isTongueTied;
	bool lightOn;
	int range;
	void chooseRandomAttack(spellTypes, player, enemy);
	spellTypes enemySpell;

	spellTypes damageType;

	void attack(player, enemy, spellTypes, bool);

	wand();
	~wand();
};

void disarmAbility(player p);



