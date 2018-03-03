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


typedef char CharacterAttribute;

CharacterAttribute AskPlayerForAttribute( const char * attributeName ) {
	// Reads out "Enter Your Strength: "
	cout << "Enter your " << attributeName << ": " << endl;

	char inputString[ 256 ];
	cin >> inputString;

	CharacterAttribute attribute = atoi( inputString );
	return attribute;
}

/*
===============================================
main
===============================================
*/
int main() {

	char name[ 256 ];

	cout << "Enter Your Name!" << endl;
	cin >> name;

	cout << " Hello " << name << " Welcome to AutoQuest!" << endl;
	
	CharacterAttribute strength = AskPlayerForAttribute( "strength" );


	return 0;
}