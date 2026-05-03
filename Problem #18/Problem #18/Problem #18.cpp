
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



float ReadCircleRadius()
{
	float radius;  // what's returned.

	cout << "Enter The Circle's radius: ";
	cin >> radius;
	cout << endl;

	return radius; 
}

double CalculateCircleArea(float radius) // passing by value
{
	const double PI = 3.141592653589793;
	return PI * radius * radius;   // avoid using pow() for squares as it's slower. 
	
	// multiplying different data types (float and double)
   // smaller data type is promoted to bigger type (no data loss). This is why the function's return type is double (instead of float where I have to again convert the area result to float).
}


void PrintCircleArea(const double &CircleRadius) // passing by constant reference.
{
	cout << "The cirlcle's radius = " << CircleRadius << endl;
}

int main()
{
	
	PrintCircleArea(CalculateCircleArea(ReadCircleRadius()));


	return 0;
}




























