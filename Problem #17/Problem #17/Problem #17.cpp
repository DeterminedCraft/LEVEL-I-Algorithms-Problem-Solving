
#include <iostream>
using namespace std;

/*
 Problem #17:
 Write a program to calculate the triangle area then print it on the screen.

 The user should enter:
 a
 h

 Formula:
 Area = 1/2 * a * h

 Example Inputs:
 10
 8

 Output:
 40

*/



void ReadTriangleInfo(float &base, float &height) // passing be reference.
{
    cout << "Enter Triangle's base: ";
    cin >> base;
    cout << endl;

    cout << "Enter Triangle's height: ";
    cin >> height;
    cout << endl;
}

float CalculateTriangleAreaByBaseAndHeight(float base, float height)  // passing by value
{
    return (1.0 / 2) * base * height;  // CRUCIAL: (1/2) denotes integer division, meaning that zero is what will be returned. 0.5 is even better than (1.0/2) 0r (1/2.0)
}
 
void PrintTriangleArea(const float &area)   //pass by constant reference.
{
    cout << "The triangle's area = " << area << endl;
}

int main()
{
    
    float base, height;
    // Initializing via reading user input:

    ReadTriangleInfo(base, height);
    // the variables 'base' & 'height' are now initialized.

    PrintTriangleArea(CalculateTriangleAreaByBaseAndHeight(base, height));
    
    
    
    
    return 0;
}


