// Chloe Sheasby
// Programming II Assignment 4
// Description: Mortgage
// Due Wednesday, February 20th

#include <iostream>
#include <string>
#include "Mortgage.h"

using namespace std;

int main()
{
	float loan, rate;
	int years;

	cout << "Please enter the dollar amount of your loan: "; 
	cin >> loan;
	cout << "Please enter the annual interest rate: ";
	cin >> rate;
	cout << "Please enter the number of years of the loan: ";
	cin >> years;
	cin.ignore();

	Mortgage mortgage(loan, rate, years);		// is this allowed?

	cout << "Your monthly payment: $" << mortgage.monthlyPaymentAmount() << endl;
	cout << "Total amount paid to the bank: $" << mortgage.getTotalAmount() << endl;

	return 0;
}