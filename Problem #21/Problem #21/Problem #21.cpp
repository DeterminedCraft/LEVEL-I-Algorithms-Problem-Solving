

#include <iostream>
using namespace std;

/*
==============================================================
 Problem #21:
 Write a program to calculate CIRCLE AREA along the circumference,
 then print it on the screen.

 The user should enter:
 L

 Where:
 L = Length of the circle circumference

 Formula:
 Area = L^2 / (4 * π)

 Example Input:
 20

 Output:
 31.831
==============================================================
*/

float ReadFloatNumber(const string& message)   // pass by constant reference.
{
	float number;   // what's returned.

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}

bool ValidateCircumferenceRange(const float& circumference)  // passed by constant reference since it's used for only comparing
{
	return (circumference > 0);
}

float ReadCircumference(const string& message)
{
	float circumference;   // what's returned.

	do
	{
		circumference = ReadFloatNumber(message);  // 'circumference' is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateCircumferenceRange(circumference));   // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

	return circumference; 
	/* The above lines of code are to be sequentially composed line by line 
	   and at the end, implement the functions of:
	   ReadFloatNumber()  &   ValidateCircumferenceRange()     */

}

double CalculateAreaOfCircle(float circumference) // pass by value
{
	const double PI = 3.141592653589793;      //  Area = L^2 / (4 * π)
	return (circumference * circumference) / (4 * PI);    // NOT an integer division - as eventually you will have  double divided by double.
	// POW method isn't used as for squaring, it's deemed slower.
	// in here we're mixing data types. So the smallest data type (float) will be implicitly converted by the compiler to the larger one (double)
	// thus, no data loss occurs. and just before returning, I notice that the return type is float. So, I change it to double so that no implicit conversion
	// process takes place just before returning (which causes data loss as it's from double to float, resulting in loss of precision)
}

void PrintAreaOfCircle(const float& circumference)  // passing by constant reference.
{
	cout << "The Circle's area = " << CalculateAreaOfCircle(circumference) << endl;
}

int main()
{
	// Initiating the below variable via reading user input (Using Function since ONE variable is initialized and returned):
	float circumference = ReadCircumference("Enter Circumference: ");   // Range(s) NOT included since the value is not intrinsic.

	PrintAreaOfCircle(circumference); // this printing procedure's implementation will have inside it the function CalculateAreaOfCircle.
	                                  // this is the standard coding approach. Moreover and separately, this printing procedure
	                                 // will have access / can reference the original value the user entered (circumeference).


	return 0;
}


























//////////////////////////////////////   OLD UNOPTIMIZED SOLUTION   ////////////////////////////////////////
//float ReadCircleInfo()
//{
//	float Circumference; // what's returned.
//
//	cout << "Enter Circle's Circumference: ";
//	cin >> Circumference;
//	cout << endl;
//
//	return Circumference;
//}
//
// double CalculateCircleArea(float circumference) // passing by value
//{
//	const double PI = 3.141592653589793;
//	return (circumference * circumference) / (4 * PI); // doubles and floats. So, the compiler promotes the smallest data types (float) to double (no data loss).
//	// and this is why the return type of this function is double. At the very end we could decide if the final result is rounded or not (that is the only time 
//	// rounding is performed so the result is as accurate as possible.
//}
//
// void PrintCircleArea(const double &CircleArea) // pass by constant reference.
// {
//	 cout << "The Circle's area = " << CircleArea << endl;
// }
//
//int main()
//{
//  
//	PrintCircleArea(CalculateCircleArea(ReadCircleInfo())); // Both CalculateCircleArea() & ReadCircleInfo() HAVE to be functions.
//
//
//
//	return 0;
//}



