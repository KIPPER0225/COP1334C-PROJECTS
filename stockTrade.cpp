/*
	Kaden Ip 

	stockTrade.cpp

	Given a Company Name & symbol, number of shares transacted,
	Cost per share at the time of buying, & price (market value),
	Per share at the time of selling.
	Calculate total cost, total proceeds, commission paid,
	& gains/losses (amount & percentage)

	Input: Company Name & symbol, number of shares transacted,
	Cost per share at the time of buying, & price (market value),
	Per share at the time of selling.

	Processing: 1. Initialize iTrade = 0.02
				2. Prompt user for Company Name and Symbol
				3. Prompt user for Number of Shares transacted
				4. Prompt user for Cost per share (@ buying)
				5. Prompt user for Price per share (@ selling)
				6. Calculate total cost
				   total_cost = number_shares * cost_shares + (number_shares * cost_shares * iTrade)
				7. Calculate total proceeds
				   total_proceeds = number_shares * price_shares - (number_shares * price_shares * iTrade)
				8. Calculate commissions
				   commission_paid = number_shares * cost_shares * iTrade + number_shares * price_shares * iTrade
				9. Calculate gains/losses
				   gains_losses = total_proceeds - total_cost 
				   percentage_gains_losses = (gains_losses / total_cost) * 100 
				10. Display Realized Gains/Losses Report

	Output: Realized Gains/Losses Report
*/

// Header FIles
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Constants & Variables
	// 2% iTrade commission per trade
	const double iTrade = 0.02;
	int number_shares;
	double cost_shares, price_shares, total_cost;
	double total_proceeds, commission_paid, gains_losses, percentage_gains_losses;
	string company_name, company_symbol;

	// Intro
	cout << "Stock Investment Performance Calculator ...\n" << endl;

	// Prompt user for Company Name and Symbol, Number of Shares transacted, 
	// Cost per share (@ buying), Price per share (@ selling)
	cout << "Company Name (no spaces) & Symbol: ";
	cin >> company_name >> company_symbol;
	cout << "Number of Shares transacted: ";
	cin >> number_shares;
	cout << "Cost per Share (@ buying): ";
	cin >> cost_shares;
	cout << "Price per Share (@ selling): ";
	cin >> price_shares;

	// Calculate total cost, total proceeds, commissions, & gains/losses($ & %)
	total_cost = number_shares * cost_shares + (number_shares * cost_shares * iTrade);
	total_proceeds = number_shares * price_shares - (number_shares * price_shares * iTrade);
	commission_paid = number_shares * cost_shares * iTrade + number_shares * price_shares * iTrade;
	gains_losses = total_proceeds - total_cost;
	percentage_gains_losses = (gains_losses / total_cost) * 100;

	// Display Gains/Losses Report
	cout << "\nRealized Gains/Losses Report ... " << endl;
	cout << "------------------------------------" << endl;
	cout << "Stock: " << company_name << ". " << company_symbol << endl;
	cout << "Quantity: " << number_shares << ".\n" << endl;
	cout << "Total Cost: " << "$" << total_cost << endl;
	cout << "Total Proceeds: " << "$" << total_proceeds << endl;
	cout << "Commissions: " << "$" << commission_paid << endl;
	cout << "Gains/Losses: " << "$" << gains_losses << " (" << percentage_gains_losses << "%)\n";

	return 0;
	
}

