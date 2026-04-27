// Problem #3.cpp :
//

#include <iostream>
using namespace std;

/*
Problem #3

 Write a program to ask the user to enter a number,
 then print "Odd" if it is odd, or "Even" if it is even.


*/


/* Solution:

 We will start this program by IMMEDIATELY creating an enum user-defined data type.
 Reason is that:

  -If the remainder is 0, then the number is EVEN.
  -If the remiander is not 0 (1 or -1 for negative numbers), then the number is ODD.

  So you notice here,
  the remainder (0 or not zero) denotes whether the number is even or odd. Where
  also, it will not be involved in any arithmetic operation.

  For this reason, the enum concept is to be utilized in this example.
  Generally speaking, if enums are to be used in a program, then the first step EVER is to
  start coding it in the program.

*/

enum enEvenOrOdd { Even = 0, Odd = 1 }; // the enumeration constants (enumerators) that are 'Even' & 'Odd' on this line, act as labels for the raw integral values they represent.
// from now and on- we ONLY deal with these labels. Therefore, FOREVER forget about the raw integral values & only deal with the labels representing them.

// so far, only an enum user-defined data type has been created and nothing else.
// the next natural step is creating a variable of this enum user-defined data type in main().



int ReadNumber(const string& message) // passing by constant reference.
{
	int number; // what's returned.

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}

bool ValidatePositiveInteger(const int& number)   // passing by constant reference
{
	return (number > 0);
}

int ReadPositiveInteger(const string& message) // pass by constant reference.
{
	int number;  // what's returned.
	do
	{
		number = ReadNumber(message);  // 'number is to be IMMEDIATELY validated against the range in the while condition.

	} while (!ValidatePositiveInteger(number)); // 👈 the argument is written so that, it evaluates to TRUE when the condition is INVALID (hence, the ! character).

	return number;
	/*
	 The variable 'number' was initialized & then returned.
	 The calling function, ReadPositiveInteger(), in main() evaluates to produce a value of type int (that initializes an object in the calling function).
	 The lifetime of the local variable 'number' ends when the program exists the curly brackets of this function.
	 🔥🔥🔥 correct !

	*/

	// NOTE: The above block is to be written line by line where
	// at the end the 2 functions:     ReadNumber() & ValidatePositiveInteger() are to be implemented.
}


enEvenOrOdd DetermineEvenOrOdd(const int& number)    // pass by constant reference
{
	if (number % 2 == 0)
	{
		return enEvenOrOdd::Even;    // returns  0  ( of data type enEvenOrOdd)
	}
	else   // could be 1 for positive numbers...or... -1 for negative numbers
	{
		return enEvenOrOdd::Odd;   //  returns 1  ( of data type enEvenOrOdd)
	}
}

void PrintEvenOrOdd(const enEvenOrOdd& EvenOrOdd) //pass by const ref  //The params here are implemented by looking @ the calling func. raw values that are either 1 or 0 of data type enEverOrOdd
{
	if (EvenOrOdd == enEvenOrOdd::Even)  // to the right of the operand (from the data type creation step).
	{
		cout << "Even \n";
	}
	else
	{
		cout << "Odd \n";
	}
}

int main()
{
	// enEvenOrOdd EvenOrOdd; // commented out as it was later discovered that it's not needed.  //the next natural step of creating a variable of the enum user-defined data type.


	PrintEvenOrOdd(DetermineEvenOrOdd(ReadPositiveInteger("Enter a positive integer: ")));  // DetermineEvenOrOdd()  &  ReadPositiveNumber()  have to be functions as procedures return void 
	// & void can NEVER be the argument of a function / procedures, as this throws an exception.

	return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//// Some first attempt older solution:
//enum enEvenOrOdd { Even = 0, Odd = 1};
//      
//
//int ReadNumber()
//{
//	int number;
//
//	cout << "Enter a number: ";
//	cin >> number;
//	cout << endl;
//
//	return number;
//}
//
//
//enEvenOrOdd CheckNumberType(const int &number) // passing by constant reference.
//{
//	if (number % 2 == 0)
//	{
//		return enEvenOrOdd::Even;  //  = 0
//	}
//	else // could be 1 for positive numbers   or   -1 for negative numbers.
//	{
//		return enEvenOrOdd::Odd;   // = 1
//	}
//}
//
//
//void PrintEvenOrOdd(const enEvenOrOdd &EvenOrOdd)  // passing by constant reference.
//{
//	if (EvenOrOdd == enEvenOrOdd::Even)
//	{
//		cout << " It is even" << endl;
//	}
//	else
//	{
//		cout << " It is odd" << endl;
//	}
//}
//
//int main()
//{
//	enEvenOrOdd EvenOrOdd;
//
//
//
//
//	PrintEvenOrOdd(CheckNumberType(ReadNumber()));  // let's start with this line.
//
//	return 0;
//}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/* ANother first attempt older solution:
* 
   If the remainder is 0, then the number is even.
   If the remainder is 1, then the number is odd.
   This means that we start writing this program utilizing enums, as 0 and 1 signify Even and Odd respectively.

   Note: Will eventually discover that this example will NOT follow the conventional enum mental model workflow.
         Think of it as a "forced" exercise by the instructor.
		 This is why declaring a variable of the enum type which is the next natural step was not utilized.
 
*/


//enum enNumberType {Even = 0, Odd =1};
//// so far, an enum user-defined data type has been created. That's all.
//// The next natural step is to create a variable of this enum user-defined data type.
//
//
//int ReadNumber()
//{
//	int number;
//	do
//	{
//		cout << "Enter a positive number: ";                            // future follow-up: entering negative decimal.
//		cin >> number;
//
//	} while(number <= 0);  //👉 condition written so that it evaluates to true when the range is invalid.
//
//	return number;
//}   
//
//// this should be a UTILITY that is implemented in an external file (We'll learn more about that soon);
//enNumberType CheckNumberType(int number) // passing by value  //parameter name can be named anything.
//{
//	 if (number % 2 == 0)
//	 {
//		 return enNumberType::Even;
//	 }
//	 else
//	 {
//		 return enNumberType::Odd;
//	 }
//}
//
//void PrintNumberType(const enNumberType &NumberType) // passing by constant reference.
//{
//	if (NumberType == enNumberType::Even)
//	{
//		cout << "Number is Even \n";
//	}
//	else
//	{
//		cout << "Number is Odd \n";
//	}
//}
//
//int main()
//{
//	//enNumberType NumberType;  // proven not to be needed.
//
//	PrintNumberType(CheckNumberType(ReadNumber()));
//
//	return 0;
//}





























