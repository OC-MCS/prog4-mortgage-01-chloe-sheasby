// Chloe Sheasby
// Programming II Assignment 4
// Description: Mortgage
// Due Wednesday, February 20th

#include <iostream>
#include <iomanip>
#include <string>
#include "Mortgage.h"

using namespace std;

float validateLoanOrRate(string input);
bool parseFloat(string sval, float& val);
int validateYears(string input);
bool parseInt(string sval, int& val);

int main()
{
	string inputL,	//temporarily holds the loan, rate, and years amounts as strings so that they can be checked for dummy input
		inputR,
		inputY;
	float loan,		// holds the value of the loan until it is placed into an instance of Mortgage
		rate;		// holds the annual interest rate
	int years;		// holds the number of years

	cout << "Please enter the dollar amount of your loan: "; 
	getline(cin, inputL);
	loan = validateLoanOrRate(inputL);		// checks for invalid input and then initializes the corresponding value

	cout << "Please enter the annual interest rate: ";
	getline(cin, inputR);
	rate = validateLoanOrRate(inputR);

	cout << "Please enter the number of years of the loan: ";
	getline(cin, inputY);
	years = validateYears(inputY);

	Mortgage mortgage(loan, rate, years);		// initializes an instance of Mortgage with the inputted values

	cout << "Your monthly payment: $" << fixed << showpoint << setprecision(2) 
		<< mortgage.monthlyPaymentAmount() << endl;		// gets the monthly payment amount and displays it
	cout << "Total amount paid to the bank: $" << fixed << showpoint << setprecision(2) 
		<< mortgage.getTotalAmount() << endl;	// gets the total amount payed to the bank and displays it

	return 0;
}

//=================================================================================
// validateLoanOrRate: this checks the user's input for validation, and asks the 
//					   user to try again until there is valid input, this is called 
//					   for loan or rate (when needed) because they are both floats
// parameters:
//	input: a string that temporarily holds the user's input until it is validated 
//		   by parseFloat
// return type: value (a float, holds the value for either loan or rate and is 
//			    returned to main)
//=================================================================================
float validateLoanOrRate(string input)
{
	float value;		// holds the value of either the loan or the rate inputted by the user

	while (!parseFloat(input, value))		// checks for dummy input
	{
		cout << "Error. Invalid input. Please try again and enter a numerical value. ";
		getline(cin, input);
	}
	while (value < 0)	// makes sure input is not negative
	{
		cout << "Error. Invalid input. Please try again a non-negative value.";
		getline(cin, input);
		parseFloat(input, value);		// this double checks for invalid input
	}

	return value;
}

//========================================================================================
// parseFloat: this temporarily takes an input as a string and checks for the validity of 
//			   the input by seeing if the string can successfully be changed into a float
// parameters:
//	sval: a string that gets turned into a float, if this doesn't work, success is 
//		  returned as false
//  val: this is passed by reference so that if the string is turned into a float 
//		 successfully, val is returned as the true input that is used in later areas
// return type: success (returns true or false if the input was valid or not)
//========================================================================================
bool parseFloat(string sval, float& val)
{
	float num;						// temporarily keeps the value that val will be intialized with
	bool success = true;
	try
	{
		num = stof(sval);			// this intializes num as the string changed into a float
		val = num;					// val, the float passed by reference, is given this value
	}
	catch (const std::exception&)	// this is done if the above is unsuccessful and changes the boolean value success to false
	{
		success = false;
	}
	return success;
}

//===============================================================================
// validateYears: this checks the user's input for validation, and asks the user 
//				  to try again until there is valid input, this is is called for 
//				  years only 
// parameters:
//	input: a string that temporarily holds the user's input until it is validated 
//	       by parseInt
// return type: value (an int, holds the value for years and is returned to main)
//===============================================================================
int validateYears(string input)
{
	int value;		// holds the value of the year inputted by the user

	while (!parseInt(input, value))		// checks for invalid input
	{
		cout << "Error. Invalid input. Please try again and enter a numerical value. ";
		getline(cin, input);
	}
	while (value < 0)	// makes sure input is not negative
	{
		cout << "Error. Invalid input. Please try again and enter a non-negative value. ";
		getline(cin, input);
		parseInt(input, value);		// this double checks for invalid input
	}

	return value;
}

//========================================================================================
// parseInt: this temporarily takes an input as a string and checks for the validity 
//			 of the input by seeing if the string can successfully be changed into an int
// parameters:
//	sval: a string that gets turned into an int, if this doesn't work, success is returned 
//		  as false
//  val: this is passed by reference so that if the string is turned into an int 
//		 successfully, val is returned as the true input that is used in later areas
// return type: success (returns true or false if the input was valid or not)
//========================================================================================
bool parseInt(string sval, int& val)
{
	int num;					// temporarily keeps the value that val will be intialized with
	bool success = true;
	try
	{
		num = stoi(sval);		// this intializes num as the string changed into an int
		val = num;				// val, the int passed by reference, is given this value
	}
	catch (const std::exception&)	// this is done if the above is unsuccessful and changes the boolean value success to false
	{
		success = false;
	}
	return success;
}