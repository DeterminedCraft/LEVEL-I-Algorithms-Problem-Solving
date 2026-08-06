
#include <iostream>
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


double ReadDoubleNumber(const string& message)    // pass by constant reference
{
	double number; // what's returned.

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}

bool ValidateValueInRange(const float value, double min, double max)   // pass by constant reference.    // ranges ALWAYS passed by value.
{
	return (min <= value && value <= max);
}



double ReadValue(const string& message, double Min, double Max) // pass by constant reference.    // ranges ALWAYS passed by value
{
	double value;   // what's returned.

	do
	{
		value = ReadDoubleNumber(message); // 'value' is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateValueInRange(value, Min, Max)); // the argument is written so that it evaluates to TRUE when the condition is INVALID.

	return value; 

	/*
	 The above block of code is to be sequentially composed line by line
	 and at the end, implement the functions of:
	 ReadDoubleNumber()   &   ValidateValueInRange()

	*/
}

double CalculateNumberToExponent(double number, double exponent)  // pass by value
{
	return pow(number, exponent); // remember: this built-in function returns double.
	// Hence, the return type of this function must be a double. Otherwise, an implicit coversion takes place resulting esulting in data loss (if you set the return type to float).
}

void PrintNumberToExponent(const double& number, const double& exponent)      // pass by constant reference.
{
	cout << "The number " << number << " to " << exponent << " = " << CalculateNumberToExponent(number, exponent) << endl;
}



int main()
{

	double MinNumber = -1000000;
	double MaxNumber =  1000000;

	double MinExponent = 0;
	double MaxExponent = 10;

	// Initializing the below variable via reading user input (Using Function - since ONE variable will be initialized and returned):
	double number = ReadValue("Enter a number: ", MinNumber, MaxNumber);
/*        |
          |---> // to be typed at the end, after finishing typing the "return" keyword.*/

	double exponent = ReadValue("Enter an exponent: ", MinExponent, MaxExponent);
/*        |
		  |---> // to be typed at the end, after finishing typing the "return" keyword.*/

	
	PrintNumberToExponent(number, exponent); // this pringing procedure contains  CalculateNumberToExponent() function


	return 0;
}







////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Now, solving this problem using procedure:


double ReadDoubleNumber(const string& message)   // pass by constant reference.
{
	double number;  // what's returned.

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}

bool ValidateValueInRange(const double& value, double min, double max)  // pass by constant ref.   // ranges ALWAYS passed by value.
{
	return (min <= value && value <= max);
}

void ReadValue(const string& message, double min, double max, double& value) // passing by constant reference // ranges ALWAYS passed by value  // passing number & expotential by ref (otherwise, how can one initialize them in main() ?)
{
	do
	{
		value = ReadDoubleNumber(message);   // 'value' is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateValueInRange(value, min, max));
    
	// the above lines of code are to be sequentially composed line by line
	// and at the end, implement the functions of: ReadFloatNumber()  & ValidateValueInRange()
}


void ReadNumberAndExpotential(const string& MessageNumber, const string& MessageExpotential, double MinNumber, double MaxNumber, double MinExpotential, double MaxExpotential, double &number, double &expotential) 
// passing by constant reference // ranges ALWAYS passed by value  // passing number & expotential by ref (otherwise, how can one initialize them in main() ?)
{
	ReadValue(MessageNumber, MinNumber, MaxNumber, number);
	ReadValue(MessageExpotential, MinExpotential, MaxExpotential, expotential);
}

double CalculateExpotentialToNumber(double number, double expotential)   // pass by value
{
	return pow(number, expotential); // ALWAYS remember that the pow function returns double, so the return type must be double and not float. otherwise, one risks losing data via implicit conversion
}

void PrintExpotentialToNumber(const double& number, const double& expotential)   // pass by constant reference.
{
	cout << number << " to the power " << expotential << " = " << CalculateExpotentialToNumber(number, expotential) << endl;
}

int main()
{
	double number, expotential;
	
	double MinNumber = -1000000;
	double MaxNumber = 1000000;

	double MinExpotential = 0;
	double MaxExpotential = 10;


	//Initializing the above variables via reading user input (Using Procedure - since MORE than one variable is initialized):
	ReadNumberAndExpotential("Enter number: ", "Enter its expotential: ", MinNumber, MaxNumber, MinExpotential, MaxExpotential, number, expotential); // as you notice: way too many parameters, effecting readability.
	// this is why, two reading functions is the appropriate solution.

	// number & expotential are now initialized.

	PrintExpotentialToNumber(number, expotential);  // this printing procedure contains the function CalculateExpotentialToNumber()
	                                                // this is a standard coding practice. 
	                                                // also, as a 'side effect' the printing procedure can reference/ has access to
	                                                // the original values of number & expotential that the user enters.


	return 0;
}














//
////////////////////////////////// Below: Some OLD UNOPTIMIZED SOLUTIONS ///////////////////////////////////////////////////
////////////////////////////////// Below: Some OLD UNOPTIMIZED SOLUTIONS ///////////////////////////////////////////////////
////////////////////////////////// Below: Some OLD UNOPTIMIZED SOLUTIONS ///////////////////////////////////////////////////
//
//
//
//
//
//
//struct stNumberToPowerM
//{
//	int number; // why not unsigned short ?  well, that's a very correct thinking. However-examine the 1st solution attempt to grasp why.
//	int power;
//};
//// a structure user-defined data type has been created and nothing more.
//// the next natural step is declaring a variable of it.
//// that's either going to be a normal variable (ONE record) or an array variable (MORE than one record).
//// But the most important questions is:
////
//// where is this variable going to be declared ?
//// if it's going to be initialized directly, then declare it in main()
//// if it's going to^be initialized via reading user-input, then declare it inside a function of the structure data-type that returns this variable.
//// since it is the latter, then we IMMEDIATELY start implementing this function NOW BELOW:
//
//bool ValidatePositiveInteger(const int &value) 
//{
//	return (value > 0);
//}
//
//int ReadNumber(const string &message)
//{
//	int number;   // what's returned.
//
//	cout << message;
//	cin >> number;
//	cout << endl;
//
//	return number;
//
//}
//
//stNumberToPowerM ReadNumberToPowerM(const string &NumberMessage, const string &PowerMessage) // passing be const. ref.  the parameters part was implemented later during the program when it turned out at some point, that I had to do so.
//{
//	stNumberToPowerM NumberToPowerM; // what's returned.  //declared as normal variable (ONE record). // the next natural step of declaring the variable of this structure user-defined data type.
//	
//	do
//	{ 
//		NumberToPowerM.number = ReadNumber(NumberMessage);  // 'NumberToPowerM.number'   is to be IMMEDIATELY validated against the range in the while condition.
//
//	}while (!ValidatePositiveInteger(NumberToPowerM.number));
//
//
//	do
//	{ 
//		NumberToPowerM.power = ReadNumber(PowerMessage);  // 'NumberToPowerM.power'   is to be IMMEDIATELY validated against the range in the while condition.
//
//	} while (!ValidatePositiveInteger(NumberToPowerM.power));  //👈 argument is written so that, it evaluates to TRUE when the condition is INVALID (hence the ! sign).
//
//	return NumberToPowerM;
//
//	// Note: ALL ALL the above lines of code are to be written step by step/ line by line
//	// and at the end, implement the functions of: ReadNumber(), ValidatePositiveInteger()
//}
//
//double CalculateNumberToPowerM(const stNumberToPowerM &NumberToPowerM) // passing by  const. ref.  // changing the function's return type to double since number ^power can get large VERY QUICKLY
//{
//	return pow(NumberToPowerM.number, NumberToPowerM.power);  //👈 argument is written so that, it evaluates to TRUE when the condition is INVALID (hence the ! sign).
//}
//
//
//int main()
//{
//  // Instead of declaring number & m as variables in main(),
//  // I'm going to declare them as member vasriables inside a structure since they^re related to each other.
//
//
//	cout << "The result of Number ^ Power is: " << CalculateNumberToPowerM(ReadNumberToPowerM("Enter a positive integer number: ", "Enter a positive integer power to this number: ")) << endl;
//
//	return 0;
//}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




//
//// Examine this first attempt  PLUS  the good intention of assigning the member variables, declared inside the structure, an unsigned short data type 
//// has a disastrous effect. As in:
//// -5 → converted to unsigned short → becomes a LARGE positive number
//struct stNumberToPowerM
//{
//	unsigned short number;
//	unsigned short power;
//};
//// a structure user-defined data type has been created and nothing more.
//// the next natural step is declaring a variable of it.
//// that's either going to be a normal variable (ONE record) or an array variable (MORE than one record).
//// But the most important questions is:
////
//// where is this variable going to be declared ?
//// if it's going to be initialized directly, then declare it in main()
//// if it's going to^be initialized via reading user-input, then declare it inside a function of the structure data-type that returns this variable.
//// since it is the latter, then we IMMEDIATELY start implementing this function NOW BELOW:
//
//bool ValidatePositiveInteger(const unsigned short& value) // pasing by const ref.
//{
//	return (value > 0);
//}
//
//stNumberToPowerM ReadNumberToPowerM(const string &NumberMessage, const string &PowerMessage) // passing be const. ref.  the parameters part was implemented later during the program when it turned out at some point, that I had to do so.
//{
//	stNumberToPowerM NumberToPowerM; // what's returned.  //declared as normal variable (ONE record). // the next natural step of declaring the variable of this structure user-defined data type.
//	
//	do
//	{ 
//	cout << NumberMessage;
//	cin >> NumberToPowerM.number; // to be IMMEDIATELY validated against the range in the while condition.
//	cout << endl;
//
//	}while (!ValidatePositiveInteger(NumberToPowerM.number));
//
//
//	do
//	{ 
//	cout << PowerMessage;
//	cin >> NumberToPowerM.power; // to be IMMEDIATELY validated against the range in the while condition.
//	cout << endl;
//
//	} while (!ValidatePositiveInteger(NumberToPowerM.power));
//
//	return NumberToPowerM;
//}
//
//double CalculateNumberToPowerM(const stNumberToPowerM &NumberToPowerM) // passing by  const. ref.  // changing the function's return type to double since number ^power can get large VERY QUICKLY
//{
//	return pow(NumberToPowerM.number, NumberToPowerM.power);
//}
//
//
//int main()
//{
//  // Instead of declaring number & m as variables in main(),
//  // I'm going to declare them as member vasriables inside a structure since they^re related to each other.
//
//
//	cout << "The result of Number ^ Power is: " << CalculateNumberToPowerM(ReadNumberToPowerM("Enter a positive integer number: ", "Enter a positive integer power to this number: ")) << endl;
//
//	return 0;
//}
//
//
//// CRUCIAL NOTE TO BUILD UPON LATER:
//// -5 → converted to unsigned short → becomes a LARGE positive number