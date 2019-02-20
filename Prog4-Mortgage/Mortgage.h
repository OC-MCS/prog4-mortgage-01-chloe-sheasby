#pragma once
#include<iostream>
using namespace std;

class Mortgage
{
private:
	float loan;			// the dollar amount of the loan
	float rate;			// the annual interest rate
	int years;			// the number of years of the loan
	float calcTerm();	// calculates the term based on rate and years
public:
	Mortgage(float l, float r, int y);	// constructor
	float monthlyPaymentAmount();		// calculates the monthly payment amount
	float getTotalAmount();				// calculates the total amount of money paid to the bank at the end of the loan period
};
