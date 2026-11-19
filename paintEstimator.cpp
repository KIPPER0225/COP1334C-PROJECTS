/*
	Kaden Ip

	paintEstimator.cpp

	Prompt user for price of paint per gallon, number of rooms to be painted, 
	& square feet of wall space in each room.
	Calculate & display number of gallons of paint required, cost of the paint, hours of labor required,
	labor charges, & total cost of the paint job.

	Input: Price of paint per gallon, number of rooms to be painted,
	& square feet of wall space in each room.

	Processing: 1. Prompt user for price of paint per gallon, number of rooms to be painted,
				& square feet of wall space in each room.
				2. While price >= 0, number >= 1, & square feet >= 25 (No errors)
					Calculate & Display:
						Gallons of paint required
						Cost of paint
						Hours of labor required
						Cost of labor
						Total cost of paint job
				3. Display results

	Output: gallons of paint required, cost of paint, hours of labor required, 
	cost of labor, & total cost of paint job
*/

// Header Files
#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes
double getPricePerGallon();
int getRooms();
int calcWallSpace(int rooms);
void calcPaint(int sqrFeet, double pricePaint, int& gallons, double& cost);
void calcLabor(int sqrFeet, double& hours, double& cost);

int main()
{
	// Display intro
	cout << "\nPaint Job Estimator ..." << endl;

	// Variables/Prototypes
	// Calls for functions
	double pricePaint = getPricePerGallon();
	int rooms = getRooms();
	int sqrFeet = calcWallSpace(rooms);

	int gallons;
	double costPaint, hours, costLabor;

	calcPaint(sqrFeet, pricePaint, gallons, costPaint);
	calcLabor(sqrFeet, hours, costLabor);

	double totalCost = costPaint + costLabor;

	// Display summary report/output
	cout << fixed << setprecision(2); 
	cout << "\n\tPaint Job Estimate\n" << endl;
	cout << "Paint ...\n";
	cout << "Gallons of Paint:        " << gallons << '\n';
	cout << "Cost of Paint:           $ " << costPaint << '\n';
	cout << "\nLabor ...\n";
	cout << "Hours of Labor :         " << hours << '\n';
	cout << "Cost of Labor:           $ " << costLabor << '\n';
	cout << "                         ----------\n";
	cout << "Total Cost:              $ " << totalCost << '\n';

	return 0;
}

// Prompts/returns price per gallon
double getPricePerGallon()
{
	double price;

	cout << "\nPrice per gallon of paint (>=0): ";
	cin >> price;

	while (price < 0) // Dispalys error message
	{
		cout << "Error ... Invalid price per gallon of paint. Try again.\n";
		cout << "Price per gallon of paint (>=0): ";
		cin >> price;
	}

	return price;
}

// Prompts/returns number of rooms
int getRooms()
{
	int rooms;

	cout << "\nNumber of rooms to be painted (>=1): ";
	cin >> rooms;

	while (rooms < 1) // Displays error message
	{
		cout << "Error ... Invalid number of rooms. Try again.\n";
		cout << "Number of rooms to be painted (>=1): ";
		cin >> rooms;
	}

	return rooms;
}

// Prompts/returns wall space to be painted
int calcWallSpace(int rooms)
{
	int totalSquareFeet = 0;
	int roomSquareFeet;

	// Gets wall space for each room
	cout << "\nSquare feet of wall space (>=25)\n";
	for (int room = 1; room <= rooms; room++)
	{
		cout << "\tRoom " << room << ": ";
		cin >> roomSquareFeet;

		while (roomSquareFeet < 25) // Displays error message
		{
			cout << "\tError ... Incorrect wall space for the room. Try again.\n";
			cout << "\tRoom " << room << ": ";
			cin >> roomSquareFeet;
		}

		totalSquareFeet += roomSquareFeet;
	}

	return totalSquareFeet;
}

// Calculates cost of paint
void calcPaint(int sqrFeet, double pricePaint, int& gallons, double& cost)
{
	gallons = (sqrFeet + 114) / 115;
	cost = gallons * pricePaint;
}

// Calculates cost of labor
void calcLabor(int sqrFeet, double& hours, double& cost)
{
	hours = (sqrFeet / 115.0) * 8; 
	cost = hours * 25.00;
}