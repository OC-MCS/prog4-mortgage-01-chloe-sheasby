// implementation file for Mortgage class
#include <iostream>
#include <cmath>
#include "Mortgage.h"

using namespace std;

Mortgage::Mortgage()	// constructor
{
	loan = 10000;
	rate = .15;
	years = 10;
}

Mortgage::Mortgage(float l, float r, int y)	//constructor
{
	l = loan;
	r = rate;
	y = years;
}

float Mortgage::getLoan(float l)
{
	if (l >= 0)
		loan = l;
	else
	{
		cout << "Invalid loan. Please enter a positive dollar amount." << endl;
		exit(EXIT_FAILURE);
	}
	float loan;
}

float Mortgage::getRate(float r)
{
	if (r >= 0)
		rate = r;
	else
	{
		cout << "Invalid rate." << endl;
		exit(EXIT_FAILURE);
	}
	return rate;
}

int Mortgage::getYears(int y)
{
	if (y >= 0)
		years = y;
	else
	{
		cout << "Invalid years." << endl;
		exit(EXIT_FAILURE);
	}
	return years;
}

float Mortgage::calcTerm()	// calculates the term based on rate and years
{
	float term;

	term = pow((1 + (rate / 12)), (12 * years));

	return term;
}

float Mortgage::monthlyPaymentAmount()	// calculates the monthly payment amount
{
	float payment;
	float term = calcTerm();

	payment = (loan * (rate / 12) * term) / (term - 1);

	return payment;
}
void Mortgage::getTotalAmount()			// calculates the total amount of money paid to the bank at the end of the loan period
{
	float payment = monthlyPaymentAmount();			// month payment amount
	float total = payment * years;
}
