#include "Player.h"
#include "Enemy.h"
#include "Arena.h"
#include <iostream>
#include <string>
using namespace std;

//player p;
enemy e;
arena Arena;


string name;
string spell;
string answer;

//enum spells { DISARM, BODY_BIND, KILLING, TONGUE_TIE} mySpells;
//mySpells = disarm;

void function() {
	cout << "Code" << endl;
	cin >> name;
	cout << "My name is: " << name << endl;
	cout << name << endl;
}

//void chooseSpell(spells mySpells) {
//	cout << "Which spell do you want to use to attack back?  (1) - disarm spell, (2) - body-bind spell, or (3) - killing curse" << spell << endl;
//	cin >> spell;
//
//	if (spell == "1") {
//		cout << "You used the disarm spell." << endl;
//		mySpells = DISARM;
//		system("Pause");
//		//cout << "Your opponent blocked the spell, and tries to " << endl;
//
//	}
//	if (spell == "2") {
//		cout << "You used the body-bind curse." << endl;
//		mySpells = BODY_BIND;
//	}
//	if (spell == "3") {
//		cout << "You used the killing curse." << endl;
//		mySpells = KILLING;
//		system("Pause");
//	}
//}
//
//void playGame() {
//	cout << "Harry Potter sort of game" << endl;
//	//cout << "" << endl;
//	//askQuestion(spell);
//	cout << " " << endl;
//	chooseSpell(mySpells);
//
//}

//void murderStudent() {
//	cout << "Now that you have killed another student, do you want to escape the castle using a secret passageway? Y/N" << endl;
//	cin >> answer;
//
//	if (answer[0] == 'Y') {
//		cout << "As you are escaping, you h " << endl;
//	} else {
//		cout << "You stay at the castle." << endl;
//		system("Pause");
//		cout << "The rest of the castle soon finds out there's a murder and Draco Malfoy suspects that you killed the Slytherin student. " << endl;
//		cout << "He corners you in the courtyard" << endl;
//	}
//}

//bool askQuestion(string spell) {
//	cout << "Which spell do you want to use to attack?  " << spell;
//	cin >> spell;
//
//	if (mySpells == "disarm") {
//		cout << "" << endl;
//		return true;
//	}
//	else {
//		cout << "" << endl;
//		return false;
//	}
//}
void initDuel() {

}

int main() {
	player p;
	//Arena.fightOptions(p);
	e.chooseEnemies();
	Arena.battle(p, e);

	
	
	
	
	
	//cout << "Hello world" << endl;
	//cout << " " << endl;
	//function();
	//playGame();
	//chooseSpell(mySpells);
	//askQuestion(spell);

	system("Pause");
}