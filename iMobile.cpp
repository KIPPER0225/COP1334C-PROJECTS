/*
	Kaden Ip

	iMobile.cpp

	Prompt user for an integer number (1-3), which refers to their specific plan, and number of gigabytes of data used.
	Calculate and display the total amount due.

	Input: An integer number (1-3) & number of gigabytes of data used

	Processing: 1. Display different plans
				2. Prompt user for an integer number (1-3) & number of gigabytes of data used
				3. Determine the corresponding plan that is assigned the specific integer
				4. Calculate user's monthly bill
				5. Display result

	Output: Based on user input, their monthly bill
	* Display error message should user input an invalid plan number and/or negative number for gigabytes
*/

// Header Files
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// Variables
	int plan_number;
	double plan_input, gigabytes_data, monthly_bill;

	// Intro
	cout << "iMobile Bill Calculator ...\n" << endl;

	// Set number formatting
	cout << fixed << showpoint << setprecision(2);

	// Display different plans & prompt user for their plan 
	cout << "Select a subscription package:" << endl;
	cout << right << setw(25) << "1. Package A" << endl;
	cout << right << setw(25) << "2. Package B" << endl;
	cout << right << setw(25) << "3. Package C" << endl;

	cout << "Package: ";
	cin >> plan_input;
	plan_number = plan_input;

	// Stops program if input contains invalid plan number
	
	if (plan_input != 1 && plan_input != 2 && plan_input != 3)
	{
		cout << "\nError ... Invalid package. Try again." << endl;

		return 0;
	}

	// Prompt user for gigabytes of data used
	cout << "\nHow many gigabytes of data were used? ";
	cin >> gigabytes_data;

	// Calculate user monthly bill
	if (gigabytes_data < 0)
	{
		cout << "Error ... Invalid gigabytes entered. Try again.";
		return 0;
	}

	switch (plan_number)
	{
		case 1: monthly_bill = 39.99;
		if (gigabytes_data > 4)
		{
			monthly_bill += (gigabytes_data - 4) * 10;
		}
		cout << "\nThe total amount due is $" << monthly_bill << endl;
		break;
	
		case 2: monthly_bill = 59.99;
		if (gigabytes_data > 8)
		{
			monthly_bill += (gigabytes_data - 8) * 5;
		}
		cout << "\nThe total amount due is $" << monthly_bill << endl;
		break;
	
		case 3: monthly_bill = 69.99;
		cout << "\nThe total amount due is $" << monthly_bill << endl;
		break; 
	}

	return 0;

}
