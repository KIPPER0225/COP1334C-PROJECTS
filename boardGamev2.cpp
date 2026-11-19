/*
	Kaden Ip

	boardGamev2.cpp

	Invite user to play an awesome online board game about traveling the galaxy in order to find a rescue station,
	making their own decisions along the way.

	Input: User name & main menu choice

	Processing: 1. Display intro of the game
				2. Prompt user for their name
				3. Display main menu choices
				4. Prompt user for their main menu choice
				5. Display result based on user input
				-rules, 5 card choices with point values and user position, 
				 thank you message, or error message.

	Output: Intro, main menu choices, (rules, 5 card choices with point values and user position,
	thank you message, or error message).

	Version 2 updates:
		-Added two more card scenarios
		-Added decision structure based on main menu choice to guide user through game
		-Included input validation for main menu choice
		-Added variable to keep track of user position
		-Added card values that influence user position
		-Changed winning position to be 12 spaces
		-Require user input of "enter" to display next card

*/

// Header Files
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Variables
	int menu_choice, user_position = 0; // User starts at position 0
	int const card1 = 3, card2 = -3, card3 = 4, card4 = -2 , card5 = 5; // Card values
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
	if (menu_choice == 1)
	{
		cout << "\nIn this game, you are a lone voyager of the vast galaxy, "
			"desperately looking for a rescue station.\n" << endl;

		cout << "In order to seek this rescue station, you must "
			"venture out into the unknown and overcome any challenges you may face.\n" << endl;

		cout << "To move closer to your goal of reaching the rescue station, "
			"you must choose a card from the deck of random events.\n" << endl;

		cout << "Based on your card, you will either advance or move back.\n" << endl;

		cout << "You will be able to choose from a selection of 10 cards. "
			"If you make it to the end of the board (12 spaces) before or during your tenth card draw, "
			"you will have successfully reached the rescue station and win the game.\n" << endl;

		cout << "Have fun and best of luck to you voyager!\n" << endl;
	}

	// Display five card scenarios, their point values, & user position
	else if (menu_choice == 2)
	{
		cout << "\nYou have chosen to play the game!\n" << endl; // Congratulate player for playing

		cin.ignore(); // Flush cin from line 60
		cout << "Card 1: \n" << endl;
		cout << "***************\n";
		cout << "*             *\n";
		cout << "*   " << "SUCCESS" << "   *\n";
		cout << "*             *\n";
		cout << "***************\n";
		cout << "\nYou have found a random rocket thruster in space! "
		"This allows you to propel further, closer to your destination! "
		"Advance 3 spaces.\n" << endl;
		user_position += card1;
		cout << "Current location: " << user_position << endl;
		cin.get();

		cout << "Card 2: \n" << endl;
		cout << "***************\n";
		cout << "*             *\n";
		cout << "*   " << "OBSTACLE" << "  *\n";
		cout << "*             *\n";
		cout << "***************\n";
		cout << "\nOH NO!! You have found yourself in a large asteroid belt, blocking your flight path! "
		"Move back 3 spaces.\n" << endl;
		user_position += card2;
		cout << "Current location: " << user_position << endl;
		cin.get();

		cout << "Card 3: \n" << endl;
		cout << "***************\n";
		cout << "*             *\n";
		cout << "*   " << "SUCCESS" << "   *\n";
		cout << "*             *\n";
		cout << "***************\n";
		cout << "\nYour ship is currently being boosted by a solar wind! "
		"Advance 4 spaces.\n" << endl;
		user_position += card3;
		cout << "Current location: " << user_position << endl;
		cin.get();

		cout << "Card 4: \n" << endl;
		cout << "***************\n";
		cout << "*             *\n";
		cout << "*   " << "OBSTALCE" << "  *\n";
		cout << "*             *\n";
		cout << "***************\n";
		cout << "\nYour navigation systems have gone down, sending you off course! "
		"Move back 2 spaces.\n" << endl;
		user_position += card4;
		cout << "Current location: " << user_position << endl;
		cin.get();

		cout << "Card 5: \n" << endl;
		cout << "***************\n";
		cout << "*             *\n";
		cout << "*   " << "SUCCESS" << "   *\n";
		cout << "*             *\n";
		cout << "***************\n";
		cout << "\nYou have been sucked up by an unexpected wormhole! "
		"Your navigation system picks up a location for the rescue station! "
		"Advance 5 spaces.\n" << endl;
		user_position += card5;
		cout << "Current location: " << user_position << endl;
	}
	
	// Display thank you message
	else if (menu_choice == 3)
	{
		cout << "\nThank you for playing! Good bye!";
	}

	// Display error message
	else
	{
		cout << "\nInvalid choice. Please choose 1 - 3 from the menu.";
	}

	return 0;

}