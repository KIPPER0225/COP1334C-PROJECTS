/*
	Kaden Ip

	recSolid.cpp

	Prompt user for height, length, & width of a rectangular solid,
	calculate its surface area & volume, and display the results
*/

// Header Files
#include <iostream>
using namespace std;

int main()
{
	// Variables
	double height, length, width;
	double volume, surface_area;

	// Intro
	cout << "Rectangular Solid Geometry App ..." << endl << endl;

	//Prompt user for height, length, & width
	cout << "Please enter rectangle's height: ";
	cin >> height;
	cout << "                         length: ";
	cin >> length;
	cout << "                          width: ";
	cin >> width;

	// Calculate volume
	volume = height * length * width;
	
	cout << endl;

	// Display volume result
	cout << "The volume of the rectangle is " << volume << " units." << endl;

	// Calculate surface area
	surface_area = 2 * (length * height + width * height + width * length);

	// Display surface area result
	cout << "The surface area of the rectangle is " << surface_area << " units." << endl;

	return 0;
}