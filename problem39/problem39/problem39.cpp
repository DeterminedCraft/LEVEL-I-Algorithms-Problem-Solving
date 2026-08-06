
#include <iostream>
using namespace std;

/* Problem #39:
   Write a program to read a TotalBill and CashPaid and calculate the remainder to be paid back.

   Input
   20
   50

   Output
   30

*/







double ReadDoubleNumber(const string& message)  // passing by constant reference.
{
	double number;  // what's returned

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}

bool ValidateTotalBill(const double& TotalBill)   // pass by constant ref. since it's only used to be compared against the range.
{
	return (TotalBill > 0);
}

double ReadTotalBill(const string& message)   // pass by constant reference.
{
	int counter = 0;
	double TotalBill;   // what's returned.   // declared outside the do statement, so that it can be returned.
    
	do
	{
		counter++;
		if (counter > 1)
		{
			cout << "Bill amount entered should be positive. ";
		}

		TotalBill = ReadDoubleNumber(message);  // 'TotalBill' is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateTotalBill(TotalBill));  // the argument is written so that it evaluates to TRUE when the condition is INVALID.

	return TotalBill;

	/* Note:
	   The above block of code is to be sequentially composed line by line
	   and at the end, implement the functions of:
	   ReadDoubleNumber()   &  ValidateAmount()
	
	*/
}


bool ValidateCashPaid(const double& CashPaid, double TotalBill)   // pass by constant ref. since it's only used to be compared against the range.   // RANGES ALWAYS passed by value.
{
	return (CashPaid >= TotalBill);
}


double ReadCashPaid(const string& message, double TotalBill)   // pass by constant reference.  // RANGES ALWAYS passed by value.
{
	int counter = 0;
	double CashPaid;   // what's returned.   // declared outside the do statement, so that it can be returned.

	do
	{
		counter++;
		if (counter > 1)
		{
			cout << "Cash paid must be larger to equal to the total bill amount. ";
		}

		CashPaid = ReadDoubleNumber(message);  // 'TotalBill' is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateCashPaid(CashPaid, TotalBill));  // the argument is written so that it evaluates to TRUE when the condition is INVALID.

	return CashPaid;

	/* Note:
	   The above block of code is to be sequentially composed line by line
	   and at the end, implement the functions of:
	   ReadDoubleNumber()   &  ValidateAmount()

	*/
}


double CalculateChangeAmount(double TotalBill, double CashPaid)   // pass by value
{
	return (CashPaid - TotalBill);
}


void PrintChangeAmount(const double& TotalBill, const double& CashPaid)   // pass by constant ref.
{
	cout << "The change amount = " << CalculateChangeAmount(TotalBill, CashPaid) << endl;
}




int main()
{
  // Initializing the below variable via reading user input (Using Function - since ONE variable is initialized and returned):
  double TotalBill = ReadTotalBill("Enter The Total Bill Amount: ");   // Range(s) NOT included as their value(s) is NOT intrinsic.
  /*        |
            |---> // to be typed at the end, after finishing typing the "return" keyword in the implementing function. */

  double CashPaid = ReadCashPaid("Enter The Cash Paid Amount: ", TotalBill);  // 'TotalBill' is the range (CashPaid has to be larger or equal to the TotalBill)
 /*        |
		   |---> // to be typed at the end, after finishing typing the "return" keyword in the implementing function. */


  PrintChangeAmount(TotalBill, CashPaid);   // 

  return 0;
}





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// For the above solution,
// the counter variable with the do..while statement is used 
// for outputting a warning message that prompts the user to re-enter.

// It's assumed that the usage of counter variable renders the solution less optimized.
// Therefore - a better solution lies in utilizing a while loop instead of a do..while one.



double ReadDoubleNumber(const string& message)  // passing by constant reference.
{
	double number;  // what's returned

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}

bool ValidateTotalBill(const double& TotalBill)   // pass by constant ref. since it's only used to be compared against the range.
{
	return (TotalBill > 0);
}

double ReadTotalBill(const string& message)   // pass by constant reference.
{
	double TotalBill;  // what^s returned.

	TotalBill = ReadDoubleNumber(message);  // 'TotalBill' is to be IMMEDIATELY validated against the range, in the while condition.

	while (!ValidateTotalBill(TotalBill)) // the condition is written so that, it evaluates to TRUE when the condition is INVALID.
	{
		cout << "Total Bill Amount Must Be Positive. ";
		TotalBill = ReadDoubleNumber(message);
	}

	return TotalBill;
}


bool ValidateCashPaid(const double& CashPaid, double TotalBill)   // pass by constant ref. since it's only used to be compared against the range.   // RANGES ALWAYS passed by value.
{
	return (CashPaid >= TotalBill);
}


double ReadCashPaid(const string& message, double TotalBill)   // pass by constant reference.  // RANGES ALWAYS passed by value.
{
	double CashPaid;  // what's returned

	CashPaid = ReadDoubleNumber(message);   // 'CashPaid' is to be IMMEDIATELY validated against the range, in the while condition.

	while (!ValidateCashPaid(CashPaid, TotalBill))    // the condition is written so that, it evaluates to TRUE when the condition is INVALID.
	{
		cout << "Value must be larger or equal to the Total Bill amount. ";
		CashPaid = ReadDoubleNumber(message);
	}

	return CashPaid;
	/* Note:
	   The above block of code is to be sequentially composed line by line
	   and at the end, implement the functions of:
	   ReadDoubleNumber()   &  ValidateCashPaid()

	*/
}


double CalculateChangeAmount(double TotalBill, double CashPaid)   // pass by value
{
	return (CashPaid - TotalBill);
}


void PrintChangeAmount(const double& TotalBill, const double& CashPaid)   // pass by constant ref.
{
	cout << "The change amount = " << CalculateChangeAmount(TotalBill, CashPaid) << endl;
}




int main()
{
	// Initializing the below variable via reading user input (Using Function - since ONE variable is initialized and returned):
	double TotalBill = ReadTotalBill("Enter The Total Bill Amount: ");   // Range(s) NOT included as their value(s) is NOT intrinsic.
	/*        |
			  |---> // to be typed at the end, after finishing typing the "return" keyword in the implementing function. */

	double CashPaid = ReadCashPaid("Enter The Cash Paid Amount: ", TotalBill);  // 'TotalBill' is the range (CashPaid has to be larger or equal to the TotalBill)
	/*        |
			  |---> // to be typed at the end, after finishing typing the "return" keyword in the implementing function. */


	PrintChangeAmount(TotalBill, CashPaid);   // this printing procedure contains the method CalculateChangeAmount()
	                                          // this is a standard coding practice.
	                                          // which is, also, conducive to the printing procedure having access/ can reference
	                                          // the values originally entered by the user that are TotalBill & CashPaid.

	return 0;
}
