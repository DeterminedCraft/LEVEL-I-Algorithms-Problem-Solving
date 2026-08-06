
#include <iostream>
#include <cmath>
using namespace std;

/*
 Problem 38:

 Write a program to read a number and check if it is a prime number or not.

 Note: Prime number can only divide on one and on itself.

 Input
 5
 6
 3

 Outputs->

 Prime
 Not Prime
 Prime


*/





// so whether the remainder is 0 or not, is what determines if the number in a Prime number.
//		If it's 0, then it's NOT a Prime number.
//      If it's NOT zero, then it's a prime number.
// where such 0 or any other number is not involved in any arithmetic operation (they denote whether a number is prime or not).

// This is why, enum should be utilized in this program. Therfore, enum is the FIRST THING TO EVER CODE in the program.


enum enPrimeOrNot { Prime = 1, NotPrime = 0};    // the enumeration constants (enumerators) that are Prime & NotPrime, act as labels for the raw integral values they represent.
// so FOREVER FORGET but these raw values and ALWAYS deal with / use their labels.

// so far, only an enum user-defined data type has been created and nothing more.
// the next natural step is creating a variable of this enum user-defined data type in main().


int ReadIntegerNumber(const string& message)    // pass by constant ref.
{
	int number;   // what's returned.

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}

bool ValidatePositiveInteger(const int& number)   // pass by constant reference.
{
	return (number > 0);
}


int ReadPositiveInteger(const string &message)   // pass by constant reference.
{
	int number;   // what's returned.

	do
	{
		number = ReadIntegerNumber(message);  // 'number is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidatePositiveInteger(number));   // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

	return number;

	// the above block of code is to be sequentially composed line by line
	// and at the end, implement the functions of:
	// ReadIntegerNumber()   & ValidatePositiveInteger()
}


bool IsRemainderZero(int value , int i)   // pass by value
{
	return (value % i == 0);
}


enPrimeOrNot DeterminePrimeOrNot(const int& number)   // pass by constant reference.
{
	int value = round(number / 2.0);       // NOT an integer division since 2.0 is used instead of 2.    // I do not understand this step as the logic seems faulty to start with
	for (int i = 2; i < value; i++)
	{
		if (IsRemainderZero(value, i))   //  value % i == 0  no matter how short & simple such line is, ALWAYS wrap it inside a function.
		{
			return enPrimeOrNot::NotPrime;    // returns 0 ( of data type enPrimeOrNot)
		}
	}
		
			return enPrimeOrNot::Prime;      // returns 1 ( of data type enPrimeOrNot)
}

void PrintPrimeOrNot(const int& number)   // pass by constant reference.
{
	switch (DeterminePrimeOrNot(number))
	{

	case enPrimeOrNot::Prime:    // equivalent to 1 ( of data type enPrimeOrNot)
			cout << number << " is a Prime Number. \n";
			break;

	case enPrimeOrNot::NotPrime:   // equivalent to 0 ( of data type enPrimeOrNot)
		cout << number << " is NOT a prime number. \n";
		break;

			
	}
}



int main()
{
	//enPrimeOrNot PrimeOrNotPrime;   // the next natural step of creating an anum user-defined data type.  // commented out as it turned out it was not needed.


	PrintPrimeOrNot(ReadPositiveInteger("Enter a positive integer: ")); // no ranges are included as their values are intrinsic.
	// this printing procedure contains the method DeterminePrimeOrNot()
	// this is a standard coding procedure, where also as a 'side effect', the printing procedure will have access / can reference 
	// the positive integer entered by the user.


	return 0;
}



























//// since enums are used, then it's to BE CODED FIRST in the program.
//enum enPrimeOrNotPrime { NotPrime = 0, Prime =1 }; //the enumeration constants (enumerators) that are NotPrime & Prime, act as labels for the raw integral values they represent
//// so from now and on FOREVER forget about these raw values and ONLY DEAL WITH THEIR LABELS.
//// so far, only an enum user-defined data type has been created and nothing more.
//// the next natural step is creating a variable of this enum user-defined data type in main().
//
//
//int ReadIntegerNumber(const string& message)    // pass by constant ref.
//{
//	int number;   // what's returned.
//
//	cout << message;
//	cin >> number;
//	cout << endl;
//
//	return number;
//}
//
//bool ValidatePositiveNumber(const int& number)  // pass by constant ref. since it's only compared against the range
//{
//	return (number > 0);
//}
//
//int ReadPositiveNumber(const string& message)    // pass by constant reference
//{
//	int number; // what's returned.
//
//	do
//	{
//		number = ReadIntegerNumber(message);  // 'number' is to be IMMEDIATELY validated against the range, in the while condition.
//
//	} while (!ValidatePositiveNumber(number));  // the argument is written so that, it evaluates to TRUE when the condition is INVALID.
//
//	return number;
//
//	// Note: The above block of code is to be sequentially composed line by line
//	//       , and at the end - Implement the functions of:  ReadIntegerNumber()  &  ValidatePositiveNumber()
//}
//
//
//bool IsRemainderZero(int number, int i)   // pass by value
//{
//	return (number % i== 0); 
//}
//
//enPrimeOrNotPrime DeterminePrimeOrNot(const int& number)   // pass by reference
//{
//	for (int i = number - 1; i > 1; i--)
//	{
//		if (IsRemainderZero(number, i))           //number % i == 0    no matter how simple and short such line is, ALWAYS wrap it inside a function.
//		{
//			return enPrimeOrNotPrime::NotPrime;
//		}
//	}
//
//	return enPrimeOrNotPrime::Prime;
//}
//
//
//void PrintPrimeOrNot(const int& number)    // pass by constant refence,
//{
//	if (DeterminePrimeOrNot(number) == enPrimeOrNotPrime::Prime)
//	{
//		cout << "Number is Prime \n";
//	}
//	else
//	{
//		cout << "Number is NOT prime \n";
//	}
//}
//
//
//
//
//
//int main()
//{
//	//enPrimeOrNotPrime PrimeOrNotPrime; // the enxt natural step of creating a variable of the enum user-defined data type. // commented out- turned out it was not needed.
//
//	PrintPrimeOrNot(ReadPositiveNumber("Enter a positive number: "));  // RANGE(s) not included as its value is not intrinsic
//
//	return 0;
//}
//

