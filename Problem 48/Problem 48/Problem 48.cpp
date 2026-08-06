
#include <iostream>
using namespace std;

/* 
  Problem #48

  Write a program to read a LoanAmount and ask you how many months you need to settle the loan,
  the calculate the monthly installement amount.

  Input:
  5000
  10

  Output:
  500



*/


double ReadDoubleNumber(const string& message)   // pass by const. ref.
{
	double number;    // what's returned.

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}

bool ValidatePositiveNumber(const double& number)      // pass by constant reference.
{
	return (number > 0 );
}


double ReadPositiveNumber(const string& message)   // pass by const. ref.
{   
	bool validation;
	double number; // what's returned.

	do
	{
		number = ReadDoubleNumber(message); // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

		validation = ValidatePositiveNumber(number);
		if (!validation)
		{
			cout << "Error. Enter a positive value. \n";
		}

	} while (!validation); // the argument is written so that, it evaluates to TRUE when the condition is INVALID

	return number;

	/*The above block of code is to be sequentially composed line by line & at the end, implement the functions of:  ReadDoubleNumber()   & ValidatePositiveNumber()*/
	
}

double CalculateMonthlyInstallment(double LoanAmount, double NumberOfMonths)   // pass by value
{
	return (LoanAmount / NumberOfMonths);   // this is NOT an integer division as both variables are doubles (one of them suffices).
}

void PrintMonthlyInstallment(const double& LoanAmount, const double& NumberOfMonths)    // pass by constant reference.
{
	cout << "The monthly amount needed to settle the loan is: " <<CalculateMonthlyInstallment(LoanAmount, NumberOfMonths) << endl;
}


int main()
{

    // Initializing the below variable via reading user input (Using Function - since ONE variable is initialized & returned):

 double LoanAmount = ReadPositiveNumber("Enter Loan Amount: "); // Range NOT included as its value is NOT intrinsic.
/*        |
          |--->   to be typed at the end, after finishing typing the "return" keyword in the implementing function. */

 double NumberOfMonths = ReadPositiveNumber("Enter the number of months needed to settle the loan: "); // Range NOT included as its value is NOT intrinsic
/*        |
		  |--->   to be typed at the end, after finishing typing the "return" keyword in the implementing function. */

 
 PrintMonthlyInstallment(LoanAmount, NumberOfMonths);
 // The printing procedure contains the method CalculateMonthlyInstallment()
 // this is a standard coding practice.
 // this is also conducive to the printing procedure having access / can reference the original variables the user entered
 // that are LoanAmount  & NumberOfMonths.

 
   return 0;
}
	

	
