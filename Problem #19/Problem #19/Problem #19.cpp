
#include <iostream>
using namespace std;

/*
 Problem #19:
 Write a program to calculate circle area through diameter, then print it on the screen.

 The user should enter:
 D (diameter)

 Formula:
 Area = (π * D^2) / 4

 Example Inputs:
 10

 Output:
 78.54

*/





float ReadFloatNumber(const string& message)  // pass by constant reference.
{
	float number;  // what's returned.

	cout << message;
	cin >> number;
	cout << endl;

	return number; 
}

bool ValidateCircleDiameterRange(const float& diameter)  // pass by constant ref. since we only comparing against it.
{
	return (diameter > 0);
}

float ReadCircleDiameter(const string& message)   // pass by constant reference.
{
	float diameter;  // what's returned.

	do
	{
		diameter = ReadFloatNumber(message); // 'diameter' is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateCircleDiameterRange(diameter));   // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

	return diameter; 
	
	// The above block of code is to be sequentially composed line by line
	// and at the end, implement the functions of:
	//  ReadFloatNumber()  &  ValidateCircleDiameterRange()
}


double CalculateAreaOfCircle(float diameter)   // pass by value
{
	const double PI = 3.14159265358979323846;
	return (PI * diameter * diameter / 4); // will NOT be an integer division since the divided value will be stored as double.  // using pow() is slower for squaring.
	// since different data types are mixed together, an implicit conversion will ensue where the smallest data type (float) will be converted to the larger data type (double)
	// thus in this case, no data loss occurs.
	// I changed the return type to double (from float) so that no other implicit conversion, just before returning, occurs resulting in data loss.
}

void PrintCircleArea(const float& diameter)   // pass by constant ref.
{
	cout << "The area of the circle = " << CalculateAreaOfCircle(diameter) << endl;
}

int main()
{
	// Initializing the below variable via reading user input (Using Function since one variable will be initialized and returned):
	float diameter = ReadCircleDiameter("Enter Diameter: "); // range(s) NOT included as their values is not intrinsic.

	PrintCircleArea(diameter);  // this procedure will have, in its implementation, the function CalculateCircleArea()
	                            // this is the standard way of coding. This also contributes to the procedure having the 
	                            // ability to reference / havs access to the original value that the user entered (the diameter).



	return 0;
}








////////////////////////////////////////////////////// some old UNOPTIMIZED solution ///////////////////////////////////////////
//float ReadCircleDiameter()
//{
//	float diameter;// what's returned
//
//	cout << "Enter Circle's diameter: ";
//	cin >> diameter;
//	cout << endl;
//
//	return diameter;
//}
//
//double CalculateCircleAreaByDiameter(float diameter) // passing by value.
//{
//	const double PI = 3.141592653589793;
//	return (PI * diameter * diameter) / 4;  // calculations are mix of float and double. Therefore, floats are automatically promoted to double (to the larger data type) = no data loss occurs.
//	// NOT an integer division since what's divided by 4 is some double value.
//}
//
//void PrintCircleArea(const double &CircleArea)  // passing by constant reference.
//{
//	cout << "Circle's Area = " << CircleArea << endl;
//}
//
//int main()
//{
//	
//	PrintCircleArea(CalculateCircleAreaByDiameter(ReadCircleDiameter()));
//
//	return 0;
//}

