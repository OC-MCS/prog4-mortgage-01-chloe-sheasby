// implementation file for Mortgage class
#include <iostream>
#include <cmath>
#include "Mortgage.h"

using namespace std;

// do I need another constructor?

//===============================================================
// this is a constructor that initalizes the values of an item  
//===============================================================
Mortgage::Mortgage(float l, float r, int y)
{
	loan = l;
	rate = r / 100;		// changes the rate percentage into the decimal form
	years = y;
}

//=================================================================
// calcTerm calculates the term based on rate and years 
// it also returns the term so that monthlyPaymentAmount can use it
//=================================================================
float Mortgage::calcTerm()	
{
	float term;

	term = pow((1 + (rate / 12)), (12 * years));	// calculates term

	return term;
}

//======================================================================
// monthlyPaymentAmount calculates the monthly payment the user must pay
// it also returns the payment amount so that main can cout it
//======================================================================
float Mortgage::monthlyPaymentAmount()	
{
	float payment;
	float term = calcTerm();		// initalizes term based on the term formula in calcTerm

	payment = (loan * (rate / 12) * term) / (term - 1);	// calculates payment

	return payment;
}

//===============================================================
// getTotalAmount calculates the total amount of money paid to 
// the bank at the end of the loan period  
// it also returns the total so that main can cout it
//===============================================================
float Mortgage::getTotalAmount()			
{
	float payment = monthlyPaymentAmount();			// monthly payment amount
	float total = payment * years * 12;				// 12 includes all of the months per year
	return total;
}
