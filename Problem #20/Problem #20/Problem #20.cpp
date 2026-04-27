
#include <iostream>
using namespace std;

/*
 Problem #20:
 Write a program to calculate CIRCLE AREA inscribed in a square, then print it on the screen.

        ┌─────────────┐
        │      ○      │
        │   (circle)  │
        │             │
        └─────────────┘

 The user should enter:

 Square Side Length (A)

 Formula:
 Area = π * (A / 2)^2 = (π * A^2) / 4


 Example Inputs:
 10

 Output:
 78.54
*/



float ReadSquareInfo()
{
    float SquareSideLength; // what's returned.

    cout << "Enter the Length of the Square Side: ";
    cin >> SquareSideLength;
    cout << endl;

    return SquareSideLength;
}

double CalculateCircleArea(float SquareLength) // passing by value
{
    const double PI = 3.141592653589793;
    return (PI * SquareLength * SquareLength) / 4;  // calculation involving a mix of float & double values. The smaller data type will be automatically promoted to the larger one (to double)
                                                    // Therefore, the return type of the function is double (instead of designating it as float where the area of value double is converted 
                                                    // to float again.
      
}

void PrintCircleArea(const double& CircleArea)  //passing by constant reference.
{
    cout << "The Circle Area inscribed in a square = " << CircleArea << endl;
}

int main()
{

    PrintCircleArea(CalculateCircleArea(ReadSquareInfo()));

    return 0;
}