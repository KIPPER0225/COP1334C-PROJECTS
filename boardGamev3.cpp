/*
	Kaden Ip

	boardGamev3.cpp

	Invite user to play an awesome online board game about traveling the galaxy in order to find a rescue station,
	making their own decisions along the way.

	Input: Main menu choice

	Processing: 1. Display intro of the game
				2. Prompt user for their name
				3. Display main menu choices
				4. Prompt user for their main menu choice
				5. Display result based on user input
				-rules, 7 card choices with point values and user position,
				 thank you message, or error message(s).

	Output: Intro, main menu choices, (rules, 7 card choices with point values and user position,
	thank you message, or error message(s)).

	Version 3 updates:
		-Added 2 new card scenarios
		-Added cards.txt text file which contains card scenarios and point values
		-Added while loop to allow player to play again
		-Added for loop to read and display each card and update position
		-Removed prompt for user's name
*/

// Header Files
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	// Variables
	int menu_choice = 0, user_position = 0; // User starts at position 0
	const int total_cards = 7;
	const int board_end = 12;
	string scenario;
	int point_value;

	while (menu_choice != 3) { // While loop to repeat menu until user exits
		// Intro
		cout << "WELCOME TO GALAXY ESCAPE!\n" << endl;

		// Display main menu choices
		cout << "\nPlease choose from the following menu:" << endl;
		cout << "1) See Rules" << endl;
		cout << "2) Play Game" << endl;
		cout << "3) Exit" << endl;
		cout << "Enter your choice here: ";
		cin >> menu_choice;

		// Allows card scenarios to be presented one at a time
		cin.ignore(100, '\n');

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

		// Display seven card scenarios, their point values, & user position
		else if (menu_choice == 2)
		{
			user_position = 0; // Resets position for every new game

			cout << "\nYou have chosen to play the game!\n" << endl; // Congratulate player for playing

			// Open text file with card data
			ifstream card_file;
			card_file.open("cards.txt");

			if (!card_file)
			{
				cout << "\nCannot open cards.txt.";
			}
			else
			{
				// For loop to read card scenarios & point values
				// Display cards and updates accumulator
				for (int card_number = 1; card_number <= total_cards && user_position < board_end; card_number++)
				{
					if (!getline(card_file, scenario))
					{
						cout << "\nCannot read scenario(s) from cards.txt." << endl;
						break;
					}
					if (!(card_file >> point_value))
					{
						cout << "\nCannot read point value from cards.txt." << endl;
						break;
					}

					// Flush newline for next getline
					card_file.ignore(100, '\n');

					cout << "Card " << card_number << ":" << endl;

					if (point_value > 0)
					{
						cout << "***************" << endl;
						cout << "*             *" << endl;
						cout << "*   Success   *" << endl;
						cout << "*             *" << endl;
						cout << "***************" << endl;

						cout << scenario << "  Advance " << point_value
							<< " spaces.\n" << endl;
					}
					else
					{
						cout << "***************" << endl;
						cout << "*             *" << endl;
						cout << "*   Obstacle  *" << endl;
						cout << "*             *" << endl;
						cout << "***************" << endl;

						cout << scenario << "  Move back " << -point_value
							<< " spaces.\n" << endl;
					}

					// Update & display accumulator
					user_position += point_value;
					cout << "Current location: " << user_position << endl << endl;

					// Allows player to view card scenarios one at a time
					if (card_number < total_cards && user_position < board_end)
					{
						cin.get();
					}
				}

				if (user_position >= board_end)
				{
					cout << "You have found the rescue station!" << endl << endl;
				}

				card_file.close();

			}
		}

		// Display thank you message
		else if (menu_choice == 3)
		{
			cout << "\nThank you for playing! Good bye!";
		}

		// Display error message
		else
		{
			cout << "\nInvalid choice. Please choose 1 - 3 from the menu." << endl;
		}
	}

	return 0;

}