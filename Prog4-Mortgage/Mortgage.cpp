#include <iostream>
#include <cmath>
#include "Mortgage.h"

using namespace std;

//============================================================
// this is a constructor that initalizes the values of an item  
//============================================================
Mortgage::Mortgage(float l, float r, int y)
{
	loan = l;			// initializes loan
	rate = r / 100;		// initializes rate with the decimal form of the rate percentage
	years = y;			// initializes years
}

//=================================================================
// calcTerm calculates the term based on rate and years 
// it also returns the term so that monthlyPaymentAmount can use it
//=================================================================
float Mortgage::calcTerm()	
{
	float term;		// holds the value for term

	term = pow((1 + (rate / 12)), (12 * years));	// calculates term

	return term;
}

//======================================================================
// monthlyPaymentAmount calculates the monthly payment the user must pay
// it also returns the payment amount so that main can cout it
//======================================================================
float Mortgage::monthlyPaymentAmount()	
{
	float payment;					// holds the monthly payment value
	float term = calcTerm();		// initalizes term based on the term formula in calcTerm

	payment = (loan * (rate / 12) * term) / (term - 1);	// calculates payment

	return payment;
}

//===============================================================================
// getTotalAmount calculates the total amount of money paid to the bank at 
// the end of the loan period, it also returns the total so that main can cout it
//===============================================================================
float Mortgage::getTotalAmount()			
{
	float payment = monthlyPaymentAmount();			// monthly payment amount
	float total = payment * years * 12;				// calculates total, the 12 is so that all of the months per year are included
	return total;
}
