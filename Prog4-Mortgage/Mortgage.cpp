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
	loan = l;
	rate = r;
	years = y;
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

float Mortgage::getTotalAmount()			// calculates the total amount of money paid to the bank at the end of the loan period
{
	float payment = monthlyPaymentAmount();			// month payment amount
	float total = payment * years * 12;				// 12 includes all of the months per year
	return total;
}
