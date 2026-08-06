
#include <iostream>
#include <cmath>
using namespace std;

/*

 Problem 47:

 Write a program to read a LoanAmount and Monthly Payment
 and calculate how many months you need to settle the loan.

 Input
 5000
 500

 Output
 10 Months

*/


double ReadDoubleNumber(const string& message)   // pass by constant ref.
{
	double number;  // what's returned.

	cout << message;
	cin >> number;
	cout << "\n";

	return number;
}

bool ValidateLoanAmount(const double& LoanAmount)      // pass by const. ref. since 'value' is ONLY used for comparison against the range
{
	return (LoanAmount > 0);
}

double ReadLoanAmount(const string& message)   // pass by constant reference.
{
	double LoanAmount; // what's returned
	int counter = 0;

	do
	{
		counter++;
		if (counter > 1)
		{
			cout << "Error. Only Positive Value is Allowed For The Loan Amount. ";
		}
		LoanAmount = ReadDoubleNumber(message);  // 'value' is to be IMMEDIATELY validated against the range, in the while condition 

	} while (!ValidateLoanAmount(LoanAmount));  // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

	return LoanAmount;

	// The above block of code is to be implemented line by line & at the end, implement the functions of:
	// ReadDoubleNumber()   &   ValidateValze

}


bool ValidateMonthlyPayment(const double& MonthlyPayment, double LoanAmount)  // MonthlyPayment passed by const. ref. since it's ONLY compared against the range 'LoanAmount'  // Ranges AöWAYS passed by value.
{
	return (MonthlyPayment <= LoanAmount && MonthlyPayment > 0);
}



double ReadMonthlyPayment(const string& message, double LoanAmount)     // pass by const. ref.   // Ranges ALWAYS passed by value.
{
	int counter = 0;
	double MonthlyPayment;  // what's returned

	do
	{
		counter++;
		if (counter > 1)
		{
			cout << "Error. Monthly payment should be less than or equal to the Loan Amount & not zero. \n";
		}
		MonthlyPayment = ReadDoubleNumber(message);  // 'MonthlyPayment' is to be IMMEDIATELY validated against the range, in the while condition-

	} while (!ValidateMonthlyPayment(MonthlyPayment, LoanAmount));

	return MonthlyPayment;

	// The above block of code is to be implemented line by line & at the end, implement the function of:
	// ValidateMonthlyPayment()
}


double CalculateNumOfMonthsToSettleLoan(double LoanAmount, double MonthlyPayment)   // pass by value.
{
	return ceil(LoanAmount / MonthlyPayment); // will NOT be an integer division since at least one of the variables is double.
}


void PrintNumOfMonthsToSettleLoan(const double& LoanAmount, const double& MonthlyPayment)    // pass by constant reference.
{
	cout << "The number of months to settle the loan is: " << CalculateNumOfMonthsToSettleLoan(LoanAmount, MonthlyPayment) << " months." << endl;
}


int main()
{
	// Initializing the below variable via reading user input (Using Function since ONE variable is initialized & returned):

	double LoanAmount = ReadLoanAmount("Enter The LoanAmount: "); // Range NOT included as its value is NOT intrinsic.
	/*        |
			  |--- > to be typed at the end, after finishing typing the "return" keyword in the implementing function  */

	double MonthlyPayment = ReadMonthlyPayment("Enter Monthly Payment: ", LoanAmount);   // 'LoanAmount' is the range here.
	/*        |
			  |--- > to be typed at the end, after finishing typing the "return" keyword in the implementing function  */



	PrintNumOfMonthsToSettleLoan(LoanAmount, MonthlyPayment);
	// this printing procedure contains the function: CalculateNumOfMonthsToSettleLoan()
	// and this is a standard coding practice.
	// However - as a 'side effect', the printing procedure will have access/ can reference to the original variable
	// entered by the user (that are LoanAmounts & MonthlyPayment).



	return 0;
}


