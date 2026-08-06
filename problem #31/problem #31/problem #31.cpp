
#include <iostream>
#include <cmath>
using namespace std;

/* Problem #31:

 Write a program to ask the user to enter:
 - Number

 Then print: Number^2, Number^3, Number^4

 Example Inputs:
 3

 Outputs:
 9
 27
 81


*/

float ReadFloatNumber(const string& message)   // pass by constant reference.
{
	float number;  // what's returned

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}

bool ValidateNumberInRange(const float& number, float min, float max)  // pass by const. ref. since it's compared against the range that's min and max  // ranges ALWAYS passed by value.
{
	return (min <= number && number <= max);
}

float ReadNumberInRange(const string& message, float min, float max)    //pass by constant reference  // ranges ALWAYS passed by value.
{
	float number;  // what's returned.
    
	do
	{
		number = ReadFloatNumber(message); // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateNumberInRange(number, min, max));  // the argument is written so that, it evaluates to TRUE when the condition is INVALID

	return number;
	// Note: The above block of code is to be sequentially composed line by line
	// and at the end, implement the functions of:  ReadFloatNumber()  & ValidateNumberInRange()
}

float CalculateNumberToPower(float number, int i)   // pass by value
{
	return pow(number, i);  // you need to know that  pow() & sqrt() functions return DOUBLE (their library implementations return double).
	                        // so the return type of CalculateNumberToPower() must be double, as to avoid data loss via implicit conversion from double to float.
}


void PrintNumberToPowers(const float& number)   // pass by constant reference.
{
	for (int i = 2; i <= 4; i++)
	{
		cout << number << " to power " << i << " = " << CalculateNumberToPower(number, i) << endl;
	}
}

int main()   
{
	float min = -5000000;
	float max =  5000000;

	PrintNumberToPowers(ReadNumberInRange("Enter a number: ", min, max));   // the printing procedure contains the function CalculateNumberToPowers

	

	return 0;
}







/////////////////////// some OLD UNOPTIMIZED solution below: ////////////////////////////////////
/////////////////////// some OLD UNOPTIMIZED solution below: ////////////////////////////////////
/////////////////////// some OLD UNOPTIMIZED solution below: ////////////////////////////////////

//
//
//int ReadNumber()
//{
//    int number; // what's returned.
//
//    cout << "Enter a positive integer: ";
//    cin >> number;
//    cout << endl;
//
//    return number;
//}
//
//bool ValidatePositiveInteger(int number) // passing by value
//{
//    return (number > 0);
//}
//
//int ReadPositiveInteger()
//{
//    int number; // what's returned.
//    do
//    {
//        number = ReadNumber();  // 'number' to be IMMEDIATELY validated in the condition against the range.
//        
//    } while (!ValidatePositiveInteger(number));  // 👈 👈 argument is written so that, it evaluates to TRUE when the condition is INVALID (hence the ! sign).
//
//    return number;
//
//    //Note: ALL of the above is written line-by-line. at the end, implement the two functions that are: ReadNumber() & ValidatePositiveInteger()
//}
//
//
//double CalculatePowerOf_2_3_4(int number, int i) // pass by value   // returns double ad the value of  number^power can get large VERY QUICKLY
//{
//    return pow(number, i);
//}
//
//void  PrintPowerOf_2_3_4(int number) // passing by value
//{
//    for (int i = 2; i <= 4; i++)
//    {
//        cout << "The power of " << i << " is: " << CalculatePowerOf_2_3_4(number, i) << endl;
//
//        // cout << "The power of " << i << " is: " << pow(number, i) << endl;  // Divide and conquer /فرّق تسد     even if it's:   pow(number, i) , ALWAYS wrap it in a function.     
//    }
//}
//
//
//
//
//int main()
//{
//    
//
//    PrintPowerOf_2_3_4((ReadPositiveInteger()));
//   
//    return 0;
//}


