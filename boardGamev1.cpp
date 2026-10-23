/*
	Kaden Ip

	boardGamev1.cpp

	Invite user to play an awesome online board game about traveling the galaxy in order to find a rescue station,
	making their own decisions along the way.

	Input: User name & main menu choice

	Processing: 1. Display intro of the game
				2. Prompt user for their name
				3. Display main menu choices
				4. Prompt user for their main menu choice
				5. Display rules of the game
				6. Display 3 card scenarios and their point values
				7. Display all results

	Output: Intro, main menu choices, rules, & 3 card scenarios with their respective point values.
*/

// Header Files
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Variables
	int menu_choice;
	string user_name;

	// Intro
	cout << "WELCOME TO GALAXY ESCAPE!\n" << endl;

	// Prompt user for name
	cout << "Before we start this experience,\n"
	<< "Please enter your name: ";
	getline(cin, user_name);
	cout << "It's an honor to have you play this game " << user_name << endl;

	// Display main menu choices
	cout << "\nPlease choose from the following menu:" << endl;
	cout << "1) See Rules" << endl;
	cout << "2) Play Game" << endl;
	cout << "3) Exit" << endl;
	cout << "Enter your choice here: ";
	cin >> menu_choice;

	// Display the rules of game
	cout << "\nIn this game, you are a lone voyager of the vast galaxy, "
	"desperately looking for a rescue station.\n" << endl;

	cout << "In order to seek this rescue station, you must "
	"venture out into the unknown and overcome any challenges you may face.\n" << endl;

	cout << "To move closer to your goal of reaching the rescue station, "
	"you must choose a card from the deck of random events.\n" << endl;

	cout << "Based on your card, you will either advance or move back.\n" << endl;

	cout << "You will be able to choose from a selection of 10 cards. "
	"If you make it to the end of the board (10 spaces) before or during your tenth card draw, "
	"you will have successfully reached the rescue station and win the game.\n" << endl;

	cout << "Have fun and best of luck you to voyager!\n" << endl;

	// Display three card scenarios and their points values
	cout << "***************\n";
	cout << "*             *\n";
	cout << "*   " << "SUCCESS" << "   *\n";
	cout << "*             *\n";
	cout << "***************\n";
	cout << "\nYou have found a random rocket thruster in space! "
	"This allows you to propel further, closer to your destination! "
	"Advance 3 spaces.\n" << endl;

	cout << "***************\n";
	cout << "*             *\n";
	cout << "*   " << "OBSTACLE" << "  *\n";
	cout << "*             *\n";
	cout << "***************\n";
	cout << "\nOH NO!! You have found yourself in a large asteroid belt, blocking your flight path! "
	"Move back 3 spaces.\n" << endl;

	cout << "***************\n";
	cout << "*             *\n";
	cout << "*   " << "SUCCESS" << "   *\n";
	cout << "*             *\n";
	cout << "***************\n";
	cout << "\nYour ship is currently being boosted by a solar wind! "
	"Advance 4 spaces.\n" << endl;

	return 0;

}