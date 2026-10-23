/*
	Kaden Ip

	loanCalculator.cpp

	Prompt user for loan amount, annual interest rate, & term of the loan (in years).
	Calculate & display expected monthly payment, total amount to be paid, &
	Total interest to be paid.

	Input: Borrower Name
		   Loaning Institution
		   Loan Amount ($)
		   Annual Interest Rate (%)
		   Term of Loan (years)
		   Date of Report

	Processing: 1. Prompt user for Borrower Name, Loaning Institution, Loan Amount ($),
				   Annual Interest Rate (%), Term of Loan (years), & Date of Report.
				2. Calculate monthly interest rate & number of payments
				   monthly_interest_rate = annual_interest_rate / 12
				   number_payments = loan_term * 12
				3. Calculate monthly payment, total amount to pay, & total interest
				   rate = monthly_interest_rate / 100
				   monthly_payment = (rate * pow(1+rate, number_payments) / (pow(1+rate, number_payments) - 1)) * loan_amount
				   total_amount_pay = monthly_payment * number_payments
				   total_interest = total_amount_pay - loan_amount
				4. Display report

	Output: Report showing loaning insitution, borrower name, annual interst rate,
			date, loan amount, monthly interest rate, number of payments,
			monthly payments, total amount to pay, & total interest.
*/

// Header Files
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	// Variables
	string borrower_name, loaning_institution, date_report;
	double loan_amount, annual_interest_rate, loan_term;
	double monthly_interest_rate, number_payments, rate;
	double monthly_payment, total_amount_pay, total_interest;

	// Intro
	cout << "\nLoan Payment Calculator ... \n";

	// Prompt user for Borrower Name, Loaning Institution, Loan Amount($), 
	// Annual Interest Rate(%), Term of Loan(years), & Date of Report
	cout << "\nPlease enter the following information: \n" << endl;
	cout << left << setw(35) << "Borrower's Name:";
	getline(cin, borrower_name);
	cout << left << setw(35) << "Loaning Institution:";
	getline(cin, loaning_institution); 
	cout << "\n";
	cout << left << setw(35) << "Loan Amount ($):";
	cin >> loan_amount;
	cout << left << setw(35) << "Annual Interest Rate (%):";
	cin >> annual_interest_rate;
	cout << left << setw(35) << "Term of Loan (years):";
	cin >> loan_term;
	cout << "\n";
	cout << left << setw(35) << "Date of Report:";
	cin.ignore();   // Flush cin stream
	getline(cin, date_report);
	cout << "\n---------------------------------------------------" << endl;

	// Calculate monthly interest rate, number of payments, monthly payment,
	// total amount to pay, & total interest
	monthly_interest_rate = annual_interest_rate / 12;
	number_payments = loan_term * 12;
	rate = monthly_interest_rate / 100;
	monthly_payment = (rate * pow(1 + rate, number_payments) / (pow(1 + rate, number_payments) - 1)) * loan_amount;
	total_amount_pay = monthly_payment * number_payments;
	total_interest = total_amount_pay - loan_amount;

	// Display result
	cout << "Loan Payment Summary Report\n" << endl;
	cout << fixed << showpoint << setprecision(2);

	cout << setw(30) << left << loaning_institution << borrower_name << endl;
	cout << "Annual Interest Rate: " << annual_interest_rate << "%" << endl;
	cout << "Date: " << date_report << endl;
	cout << setw(50) << left << "\nLoan Amount:" << left << setw(2) << "$" << right << setw(1) << loan_amount << endl
		<< fixed << showpoint << setprecision(2)
		<< setw(50) << left << "Monthly Interest Rate:" << right << setw(2) << monthly_interest_rate << "%" << endl
		<< fixed << showpoint << setprecision(2)
		<< setw(50) << left << "Number of Payments:" << right << setw(2) << number_payments << endl
		<< setw(49) << left << "Monthly Payment:" << left << setw(2) << "$" << right << monthly_payment << endl
		<< fixed << setprecision(2)
		<< setw(50) << left << "\nTotal Amount to Pay:" << left << setw(2) << "$" << right << setw(2) << total_amount_pay << endl
		<< fixed << showpoint << setprecision(2)
		<< setw(49) << left << "Total Interest:" << left << setw(2) << "$" << right << total_interest << endl
		<< fixed << showpoint << setprecision(2) << endl;
	cout << "\n---------------------------------------------------";

	return 0;
}