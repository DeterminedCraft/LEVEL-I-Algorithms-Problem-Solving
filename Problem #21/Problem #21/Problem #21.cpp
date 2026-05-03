

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



float ReadCircleInfo()
{
	float Circumference; // what's returned.

	cout << "Enter Circle's Circumference: ";
	cin >> Circumference;
	cout << endl;

	return Circumference;
}

 double CalculateCircleArea(float circumference) // passing by value
{
	const double PI = 3.141592653589793;
	return (circumference * circumference) / (4 * PI); // doubles and floats. So, the compiler promotes the smallest data types (float) to double (no data loss).
	// and this is why the return type of this function is double. At the very end we could decide if the final result is rounded or not (that is the only time 
	// rounding is performed so the result is as accurate as possible.
}

 void PrintCircleArea(const double &CircleArea) // pass by constant reference.
 {
	 cout << "The Circle's area = " << CircleArea << endl;
 }

int main()
{
  
	PrintCircleArea(CalculateCircleArea(ReadCircleInfo())); // Both CalculateCircleArea() & ReadCircleInfo() HAVE to be functions.





	return 0;
}



