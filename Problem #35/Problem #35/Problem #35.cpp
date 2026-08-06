
#include <iostream>
#include <cmath>
using namespace std; 


/*
 Problem #35:

 Write a program to ask the user to enter:

 - Pennies
 - Nickels
 - Dimes
 - Quarters
 - Dollars

 Then calculate the total pennies, total dollars, and print them on the screen, given that:

 - Penny   = 1
 - Nickel  = 5
 - Dime    = 10
 - Quarter = 25
 - Dollar  = 100

 Example Inputs:
 5, 5, 5, 5, 5

 Outputs:
 
 705 Pennies
 7.05 Dollars


*/

// for financial transactions, I will use int and doubles. float may be used to round off the very last value.

struct stMoney
{
	int pennies;
	int nickles;
	int dimes;
	int quarters;
	int dollars;
};
// so far, only a structure user-defined data type has been created and nothing more.
// The next natural step, is declaring a variable of this structure user-defined data type.
// 
// But the main question is:   Where to declare this variable ?
// - If it's going to be initiaLized directly, then declare it inside main().
// - if it's going to be initialized via reading user input, then declare it inside a reading function of the structure user-defined data type that returns this variable
// 
// since it's going to be the latter, then IMMEDIATELY start implementing this function NOW below:


int ReadintNumber(const string &message)   //pass by reference.
{
	int number;  // what's returned

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}


bool ValidateMoneyRange(int money)   // pass by constant reference, since 'money' is compared against the range.
{
	return (money >= 0);
}



stMoney ReadMoney(const string &PenniesMessage, const string &NicklesMessage, const string &DimesMessage, const string &QuartersMessage, const string &DollarsMessage)   // pass by constant ref.
{
	stMoney money; // the next natural step of creating a variable of the structure user-defined data type. // AS SOON AS you see such line, ALWAYS envision the variable having access to all the member variables defined inside the structure.
	
	do
	{
		money.pennies = ReadintNumber(PenniesMessage);   // money.pennies is to be IMMEDIATELY validated against the range, in the whilc condition

	} while (!ValidateMoneyRange(money.pennies));     // the condition is written so that, it evaluates to TRUE when the condition is INVALID.

	do
	{
		money.nickles = ReadintNumber(NicklesMessage);  // money.nickes is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateMoneyRange(money.nickles));   // the condition is written so that, it evaluates to TRUE when the condition is INVALID.

	do
	{
		money.dimes = ReadintNumber(DimesMessage); // money.dimes is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateMoneyRange(money.dimes));    // the condition is written so that, it evaluates to TRUE when the condition is INVALID.

	do
	{
		money.quarters = ReadintNumber(QuartersMessage);// money.quarters is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateMoneyRange(money.quarters));    // the condition is written so that, it evaluates to TRUE when the condition is INVALID.

	do
	{
		money.dollars = ReadintNumber(DollarsMessage);// money.dollars is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateMoneyRange(money.dollars));   // the condition is written so that, it evaluates to TRUE when the condition is INVALID.


	return money;

	// Note: The above block of code is to be sequentially composed line by line
	//       and at the end, implement the functions of:  ReadintNumber()  & ValidateMoneyRange()
}

int ConvertNicklesToPennies(int nickles)  // pass by value
{
	return nickles * 5; 
}

int ConvertDimesToPennies(int dimes) // pass by value
{
	return dimes * 10;
}

int ConvertQuartersToPennies(int quarters)   // pass by value
{
	return quarters * 25;
}

int ConvertDollarsToPennies(int dollars)   // pass by value
{
	return dollars * 100;
}

int CalculateAllInPennies(stMoney money) // pass by value
{
	return money.pennies + ConvertNicklesToPennies(money.nickles) + ConvertDimesToPennies(money.dimes) + ConvertQuartersToPennies(money.quarters) + ConvertDollarsToPennies(money.dollars);
}

void printAllInDollars(const int& PenniesAmount)   // pass by constant reference.
{
	cout << "All the amount in Dollars = " << float(PenniesAmount) / 100 << endl;  // NOT an integer division   // or PenniesAmount / 100.0  
}


void PrintAllInPenniesAndThenInDollars(const stMoney& money)  // pass by constant ref.   // ALWAYS envision money having access to all member variables defined inside the stMoney structure
{
	int PenniesAmount = CalculateAllInPennies(money);
	cout << "All the amount in Pennies = " << PenniesAmount << endl;

	printAllInDollars(PenniesAmount);
}

int main()
{
  // Instead of declaring Pennies, Nickles, Dimes, Quarters, Dollars as variables in main()
  // , declare them as member variables inside a structure.


	PrintAllInPenniesAndThenInDollars(ReadMoney("Enter Pennies: ", "Enter Nickles: ", "Enter Dimes: ", "Enter Quarters: ", "Enter Dollars: "));


	return 0;
}








//
//   //////////////// Below: UNOPTIMIZTED PRIMITVE way of solving this problem as structures aren't utilized //////////////////////
//   //////////////// Below: UNOPTIMIZTED PRIMITVE way of solving this problem as structures aren't utilized //////////////////////
//   //////////////// Below: UNOPTIMIZTED PRIMITVE way of solving this problem as structures aren't utilized //////////////////////
//int ReadintNumber(const string& message)   // pass by constant reference
//{
//    int number;  // what's returned
//
//    cout << message;
//    cin >> number;
//    cout << endl;
//
//    return number;
//}
//
//bool ValidateValueRange(const int& value)   // pass by constant reference since value is only used to compare against the range.
//{
//    return (value >= 0);
//}
//  
//int ReadValue(const string& message)   // pass by constant reference
//{
//    int value;   // what's returned;
//    do
//    {
//        value = ReadintNumber(message);  // value is to be IMMEDIATELY validated againt the range, in the while condition.
//
//    } while (!ValidateValueRange(value));
//
//    return value;
//
//    // the above block of code is to be sequentially composed line by line
//    // and at the end, implement the functions of:  ReadintNumber()   & ValidateValueInRange() 
//}
//
//int ConvertNicklesToPennies(int nickles) // pass by value
//{
//    return nickles * 5;
//}
//
//int ConvertDimesToPennies(int dimes)  // pass by value
//{
//    return dimes * 10; 
//}
//
//int ConvertQuartersToPennies(int quarters)   // pass by value
//{
//    return quarters * 25;
//}
//
//int ConvertDollarsToPennies(int dollars)   // pass by value
//{
//    return dollars * 100;
//}
//
//int ConvertFromDollarsToPennies(int dollars)
//{
//    return dollars * 100;
//}
//
//
//int CalculateTotalPennies(int pennies, int nickles, int dimes, int quarters, int dollars)   // pass by value
//{
//    return pennies + ConvertNicklesToPennies(nickles) + ConvertDimesToPennies(dimes) + ConvertQuartersToPennies(quarters) + ConvertDollarsToPennies(dollars);
//}
//
//
//
//void PrintTotalDollars(const int& TotalPennies)   // pass by constant reference
//{
//    cout << "Total Dollars = " << TotalPennies / 100.0;     // 100 without a decimal, results in integer division.
//}
//
//void PrintTotalPenniesAndTotalDollars(const int& pennies, const int& nickles, const int& dimes, const int& quarters, const int& dollars)  // pass by constant reference.
//{
//    int TotalPennies = CalculateTotalPennies(pennies, nickles, dimes, quarters, dollars);
//    cout << "Total Pennies = " << TotalPennies << endl;
//
//    PrintTotalDollars(TotalPennies);
//}
//
//
//
//
//int main()
//{
//    // Initializing the below variable via reading user input (Using Function - since ONE variable will be initialized):
//    int pennies = ReadValue("Enter number of Pennies: ");
///*         |
//           |----> to be typed at the end, after finishing typing the "return" keyword  */
//
//
//    // Initializing the below variable via reading user input (Using Function - since ONE variable will be initialized):
//    int nickels = ReadValue("Enter number of Nickles: ");
///*         |
//           |----> to be typed at the end, after finishing typing the "return" keyword  */
//
//
//    // Initializing the below variable via reading user input (Using Function - since ONE variable will be initialized):
//    int dimes = ReadValue("Enter number of Dimes: ");
///*         |
//           |----> to be typed at the end, after finishing typing the "return" keyword  */
//
//
//    // Initializing the below variable via reading user input (Using Function - since ONE variable will be initialized):
//    int quarters = ReadValue("Enter number of Quarters: ");
///*         |
//           |----> to be typed at the end, after finishing typing the "return" keyword  */
//
//
//    // Initializing the below variable via reading user input (Using Function - since ONE variable will be initialized):
//    int dollars = ReadValue("Enter number of Dollars: ");
///*         |
//           |----> to be typed at the end, after finishing typing the "return" keyword  */
//
//
//
//    PrintTotalPenniesAndTotalDollars(pennies, nickels, dimes, quarters, dollars); 
//
//    return 0;
//}


