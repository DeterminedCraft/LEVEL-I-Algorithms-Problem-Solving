
#include <iostream>
#include <cmath>
using namespace std;

/*
 Problem #18:

 Write a program to calculate the circle area then print it on the screen.

 The user should enter:
 r

 Formula:
 Area = π * r^2

 Example Inputs:
 5

 Output:
 78.54

*/

float ReadFloatNumber(const string& message)   // pass by constant ref.
{
	float number;  // what's returned.

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}


bool ValidateRadiusRange(const float& radius)    // pass by constaant ref.
{
	return (radius > 0);
}



float ReadRadius(const string& message)   // passs bc constatn reference
{
	float radius;  // what's returned  // declared outside 'do' so it can be returned

	do
	{
		radius = ReadFloatNumber(message);  // 'radius' is to be IMMEDIATELY validated against the range, in the while condition

	} while (!ValidateRadiusRange(radius));   // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

	return radius; 
}

double CalculateAreaOfCircle(float radius)   // pass by value
{
	const double PI = 3.14159265358979323846;
	return (PI * radius * radius);      // avoid using pow() for squares as it's slower. (PI * pow(radius, 2)); 

	// multiplying different data types (float and double)
   // smaller data type is promoted to bigger type (no data loss). This is why the function's return type is double (instead of float where I have to again convert the area result to float before returning).
}

void PrintCircleArea(const float& radius)  // pass by constant ref.
{
	cout << "The Circle's area = " << CalculateAreaOfCircle(radius) << endl;
}

int main()
{
	// Initializing the below variable via reading user input (Using Function since ONE variable in initialized and returned):
	float radius =  ReadRadius("Enter radius: ");  // ranges is NOT included as its value is not intrinsic.
/*         |
           |---> to be typed at the end, after finishing typing the "return" keyword in the implementing function.
*/

	PrintCircleArea(radius);  // this line is written so that, the printing procedure will have, in its implementation, the function CalculateCircleArea()
	                          // this is the standard approach. Additionaly, this printing procedure can reference / has access to the 'radius' value entered 
	                          // by the user.

	return 0;
}











//
////////////////////////////////  some old UNOPTIMIZED solution //////////////////////////////////////
//
//float ReadCircleRadius()
//{
//	float radius;  // what's returned.
//
//	cout << "Enter The Circle's radius: ";
//	cin >> radius;
//	cout << endl;
//
//	return radius; 
//}
//
//double CalculateCircleArea(float radius) // passing by value
//{
//	const double PI = 3.141592653589793;
//	return PI * radius * radius;   // avoid using pow() for squares as it's slower. 
//	
//	// multiplying different data types (float and double)
//   // smaller data type is promoted to bigger type (no data loss). This is why the function's return type is double (instead of float where I have to again convert the area result to float).
//}
//
//
//void PrintCircleArea(const double &CircleRadius) // passing by constant reference.
//{
//	cout << "The cirlcle's radius = " << CircleRadius << endl;
//}
//
//int main()
//{
//	
//	PrintCircleArea(CalculateCircleArea(ReadCircleRadius()));
//
//
//	return 0;
//}




























