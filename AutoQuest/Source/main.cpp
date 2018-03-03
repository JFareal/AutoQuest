/*
*************************************************************************************************
Main.cpp

The Entry point of the application.
*************************************************************************************************
*/
#include <iostream>
using namespace std;

/*

AutoQuest is a Programmatic RPG.


User Enters Character information.

Character Fights programmatic monsters

Character Levels up.

Character Gets Stronger

Character Fights Harder Monsters.

Rinse Repeat.

*/

static const int MAX_MONSTER_STRENGTH = 20;
static const int MIN_MONSTER_STRENGTH = 10;

static const int MAX_MONSTER_DEXTERITY = 20;
static const int MIN_MONSTER_DEXTERITY = 10;

static const int MAX_MONSTER_STAMINA = 20;
static const int MIN_MONSTER_STAMINA = 10;

typedef char CharacterAttribute;

struct character_t
{
	CharacterAttribute strength;
	CharacterAttribute dexterity;
	CharacterAttribute stamina;
	CharacterAttribute health;
	char name[256];
};

CharacterAttribute AskPlayerForAttribute( const char * attributeName ) {
	// Reads out "Enter Your Strength: "
	cout << "Enter your " << attributeName << ": " << endl;

	char inputString[ 256 ];
	cin >> inputString;

	CharacterAttribute attribute = atoi( inputString );
	return attribute;
}

int RandMinMax(int min, int max)
{
	return rand() % (max - min) + min;
}

int GetMeleeAttackValue(CharacterAttribute strength)
{
	int baseAttack = RandMinMax(1, 6);

	if (strength < 10)
	{
		return baseAttack;
	}

	else if (strength > 10 && strength < 15)
	{
		return baseAttack + 1;
	}

	else if (strength > 15)
	{
		return baseAttack + 2;
	}

	return baseAttack;
}

int GetHealthValue(CharacterAttribute stamina)
{
	return (100 + RandMinMax(1, 10)) * stamina;
}

int AttackCharacter(CharacterAttribute dexterity, CharacterAttribute health, int damage)
{
	int whateverIWantToNameIt = RandMinMax(1, 20);
	if (dexterity > whateverIWantToNameIt) { return health; }
	
	return health - damage;
}

/*
===============================================
main
===============================================
*/
int main() {
	character_t theHero;

	cout << "Enter Your Name!" << endl;
	cin >> theHero.name;	

	theHero.strength = AskPlayerForAttribute("strength");
	theHero.dexterity = AskPlayerForAttribute("dexterity");
	theHero.stamina = AskPlayerForAttribute("stamina");
	theHero.health = GetHealthValue(theHero.stamina);

	character_t theMonster;

	theMonster.strength = RandMinMax(MIN_MONSTER_STRENGTH, MAX_MONSTER_STRENGTH);
	theMonster.dexterity = RandMinMax(MIN_MONSTER_DEXTERITY, MAX_MONSTER_DEXTERITY);
	theMonster.stamina = RandMinMax(MIN_MONSTER_STAMINA, MAX_MONSTER_STAMINA);
	theMonster.health = GetHealthValue(theMonster.stamina);



	while (true)
	{
		int damage = GetMeleeAttackValue(theHero.strength);
		theMonster.health = AttackCharacter(theMonster.dexterity, theMonster.health, damage);

		/*Player Turn:
		Player Attacks Monster For %d Attack.
		Monster Dodges! Or Monster Takes x Damage
		
		Monster's Turn:
		Monster Attacks Player for %d Attack.
		Player Dodges! Or Player Takes x Damage
		
		Check for death
		Break if death*/

		cout << "Next Turn..." << endl;
		getchar();

	}

	return 0;
}