
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
 Problem #32:

 Write a program to ask the user to enter:
 - Number
 - M

 Then print: Number^M

 Example Inputs:
 2
 4

 Outputs:
 16

*/

struct stNumberToPowerM
{
	int number; // why not unsigned short ?  well, that's a very correct thinking. However-examine the 1st solution attempt to grasp why.
	int power;
};
// a structure user-defined data type has been created and nothing more.
// the next natural step is declaring a variable of it.
// that's either going to be a normal variable (ONE record) or an array variable (MORE than one record).
// But the most important questions is:
//
// where is this variable going to be declared ?
// if it's going to be initialized directly, then declare it in main()
// if it's going to^be initialized via reading user-input, then declare it inside a function of the structure data-type that returns this variable.
// since it is the latter, then we IMMEDIATELY start implementing this function NOW BELOW:

bool ValidatePositiveInteger(const int &value) 
{
	return (value > 0);
}

int ReadNumber(const string &message)
{
	int number;   // what's returned.

	cout << message;
	cin >> number;
	cout << endl;

	return number;

}

stNumberToPowerM ReadNumberToPowerM(const string &NumberMessage, const string &PowerMessage) // passing be const. ref.  the parameters part was implemented later during the program when it turned out at some point, that I had to do so.
{
	stNumberToPowerM NumberToPowerM; // what's returned.  //declared as normal variable (ONE record). // the next natural step of declaring the variable of this structure user-defined data type.
	
	do
	{ 
		NumberToPowerM.number = ReadNumber(NumberMessage);  // 'NumberToPowerM.number'   is to be IMMEDIATELY validated against the range in the while condition.

	}while (!ValidatePositiveInteger(NumberToPowerM.number));


	do
	{ 
		NumberToPowerM.power = ReadNumber(PowerMessage);  // 'NumberToPowerM.power'   is to be IMMEDIATELY validated against the range in the while condition.

	} while (!ValidatePositiveInteger(NumberToPowerM.power));  //👈 argument is written so that, it evaluates to TRUE when the condition is INVALID (hence the ! sign).

	return NumberToPowerM;

	// Note: ALL ALL the above lines of code are to be written step by step/ line by line
	// and at the end, implement the functions of: ReadNumber(), ValidatePositiveInteger()
}

double CalculateNumberToPowerM(const stNumberToPowerM &NumberToPowerM) // passing by  const. ref.  // changing the function's return type to double since number ^power can get large VERY QUICKLY
{
	return pow(NumberToPowerM.number, NumberToPowerM.power);  //👈 argument is written so that, it evaluates to TRUE when the condition is INVALID (hence the ! sign).
}


int main()
{
  // Instead of declaring number & m as variables in main(),
  // I'm going to declare them as member vasriables inside a structure since they^re related to each other.


	cout << "The result of Number ^ Power is: " << CalculateNumberToPowerM(ReadNumberToPowerM("Enter a positive integer number: ", "Enter a positive integer power to this number: ")) << endl;

	return 0;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





// Examine this first attempt  PLUS  the good intention of assigning the member variables, declared inside the structure, an unsigned short data type 
// has a disastrous effect. As in:
// -5 → converted to unsigned short → becomes a LARGE positive number
struct stNumberToPowerM
{
	unsigned short number;
	unsigned short power;
};
// a structure user-defined data type has been created and nothing more.
// the next natural step is declaring a variable of it.
// that's either going to be a normal variable (ONE record) or an array variable (MORE than one record).
// But the most important questions is:
//
// where is this variable going to be declared ?
// if it's going to be initialized directly, then declare it in main()
// if it's going to^be initialized via reading user-input, then declare it inside a function of the structure data-type that returns this variable.
// since it is the latter, then we IMMEDIATELY start implementing this function NOW BELOW:

bool ValidatePositiveInteger(const unsigned short& value) // pasing by const ref.
{
	return (value > 0);
}

stNumberToPowerM ReadNumberToPowerM(const string &NumberMessage, const string &PowerMessage) // passing be const. ref.  the parameters part was implemented later during the program when it turned out at some point, that I had to do so.
{
	stNumberToPowerM NumberToPowerM; // what's returned.  //declared as normal variable (ONE record). // the next natural step of declaring the variable of this structure user-defined data type.
	
	do
	{ 
	cout << NumberMessage;
	cin >> NumberToPowerM.number; // to be IMMEDIATELY validated against the range in the while condition.
	cout << endl;

	}while (!ValidatePositiveInteger(NumberToPowerM.number));


	do
	{ 
	cout << PowerMessage;
	cin >> NumberToPowerM.power; // to be IMMEDIATELY validated against the range in the while condition.
	cout << endl;

	} while (!ValidatePositiveInteger(NumberToPowerM.power));

	return NumberToPowerM;
}

double CalculateNumberToPowerM(const stNumberToPowerM &NumberToPowerM) // passing by  const. ref.  // changing the function's return type to double since number ^power can get large VERY QUICKLY
{
	return pow(NumberToPowerM.number, NumberToPowerM.power);
}


int main()
{
  // Instead of declaring number & m as variables in main(),
  // I'm going to declare them as member vasriables inside a structure since they^re related to each other.


	cout << "The result of Number ^ Power is: " << CalculateNumberToPowerM(ReadNumberToPowerM("Enter a positive integer number: ", "Enter a positive integer power to this number: ")) << endl;

	return 0;
}


// CRUCIAL NOTE TO BUILD UPON LATER:
// -5 → converted to unsigned short → becomes a LARGE positive number