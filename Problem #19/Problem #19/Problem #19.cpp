
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


float ReadCircleDiameter()
{
	float diameter;// what's returned

	cout << "Enter Circle's diameter: ";
	cin >> diameter;
	cout << endl;

	return diameter;
}

double CalculateCircleAreaByDiameter(float diameter) // passing by value.
{
	const double PI = 3.141592653589793;
	return (PI * diameter * diameter) / 4;  // calculations are mix of float and double. Therefore, floats are automatically promoted to double (to the larger data type) = no data loss occurs.
	// NOT an integer division since what's divided by 4 is some double value.
}

void PrintCircleArea(const double &CircleArea)  // passing by constant reference.
{
	cout << "Circle's Area = " << CircleArea << endl;
}

int main()
{
	
	PrintCircleArea(CalculateCircleAreaByDiameter(ReadCircleDiameter()));

	return 0;
}

