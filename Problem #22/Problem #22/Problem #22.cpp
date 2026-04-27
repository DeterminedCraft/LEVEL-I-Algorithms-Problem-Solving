
#include <iostream>
using namespace std;

/*
==============================================================
 Problem:
 Write a program to calculate circle area inscribed in an
 Isosceles Triangle, then print it on the screen.

            
           / \
      a   /   \  a
         /  ○  \
        /       \
       /_________\
            b

 The user should enter:
 a
 b

 Where:
 a = length of the two equal sides of the triangle
 b = base of the triangle

 Formula:

 Circle Area = π * (b^2 / 4) * ((2 * a - b) / (2 * a + b))

 Example Inputs:
 20
 10

 Output:
 47.124
==============================================================

*/



float ReadTriangleLength()
{
    float length; // what's returned.

    cout << "Enter the length of the triangle: ";
    cin >> length;
    cout << endl;

    return length;
}

float ReadTriangleBase()
{
    float base; // what^s returned.
    
    cout << "Enter the base of the triangle: ";
    cin >> base;
    cout << endl;

    return base;
}

double CalculateCircleArea(float length, float base) // passing by value
{
    const double PI = 3.14159265358979323846;
    return PI * (  base * base / 4  ) * (    ((2 * length) - base) / ((2 * length) + base)     ); //  NO integer division for the two '/'
}

void PrintCircleArea(const double &CircleArea) // pass by constant ref.
{
    cout << "The Circle's area = " << CircleArea << endl;
}

int main()
{
   
    PrintCircleArea(CalculateCircleArea(ReadTriangleLength(), ReadTriangleBase()));

	return 0;

    /* Instead of:
       
       // Initializing the below variable via reading user input (Using function) //since ONE variable is initialized.

       float // Initializing the below variable via reading user input (Using function) //since ONE variable is initialized.

       float TriangleLength =   ReadTriangleLength(); 
       |
       |
       |-------> The last thing to type. Type after writing "return" keyword in the implementing function. =   ReadTriangleLength(); 
       |
       |
       |-------> The last thing to type. Type after writing "return" keyword in the implementing function.
    
      
      // Initializing the below variable via reading user input (Using function) //since ONE variable is initialized.

       float TriangleBase =   ReadTriangleBase();
       |
       |
       |-------> The last thing to type. Type after writing "return" keyword in the implementing function.
    

       PrintCircleArea(CalculateCircleArea(TriangleLength, TriangleBase));

    */
}

/////////////////////////////////////////////////////////////////////////////////

// OR: solve this problem by initializing the two variables declared in main() via reading user input using a procedure.




double CalculateCircleArea(float length, float base) // passing by value
{
    const double PI = 3.14159265358979323846;
    return PI * (base * base / 4) * (((2 * length) - base) / ((2 * length) + base));   // there will be NO integer division.
}

void PrintCircleArea(const double& CircleArea) // pass by constant ref.
{
    cout << "The Circle's area = " << CircleArea << endl;
}

void ReadTriangleInfo(float& TriangleLength, float& TriangleBase)  // passing by reference. 
{
    cout << "Enter Triangle's length: ";
    cin >> TriangleLength;
    cout << endl;

    cout << "Enter Triangle's Base: ";
    cin >> TriangleBase;
    cout << endl;
}

int main()
{
    float TriangleLength, TriangleBase; 
    // Initializing the two variables via reading user input:

    ReadTriangleInfo(TriangleLength, TriangleBase);
    // the two variables 'TriangleLength'  &  'TriangleBase' are now initialized.

    PrintCircleArea(CalculateCircleArea(TriangleLength, TriangleBase));

    return 0;
}