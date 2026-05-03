
#include <iostream>
using namespace std;

/*
==============================================================
Problem #15:
 Write a program to calculate the area of a rectangle.

 Formula:
 Area = a * b

 Example Input:
 10
 20

 Example Output:
 200
==============================================================
*/



void ReadRectangleInfo(float& length, float& width)  // pass by ref.
{
    cout << "Enter Rectangle's length: ";
    cin >> length;
    cout << endl;

    cout << "Enter Rectangle's width: ";
    cin >> width;
    cout << endl;
}

float CalculateRectangleArea(float length, float width) // pass by value
{
    return length * width;
}

void PrintRectangleArea(const float& area)  // pass by const ref.
{
    cout << "Area of Rectangle = " << area << endl;
}

int main()
{
    float length, width;
    // Initializing via reading user input:

    ReadRectangleInfo(length, width);
    // the variables 'length' abd 'width' are now initialized.


    PrintRectangleArea(CalculateRectangleArea(length, width));

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Another way of coding, 
// where the two variables are initialized via reading user input BUT this time by two functions


float ReadRectangleLength()
{
    float length; //what's returned.

    cout << "Enter the Rectangle's length: ";
    cin >> length;
    cout << endl;

    return length; 
}

float ReadRectangleWidth()
{
    float width;

    cout << "Enter the Rectangle's width: ";
    cin >> width;
    cout << endl;

    return width;
}


float CalculateRectangleArea(float length, float width) // pass by value
{
    return length * width;
}

void PrintRectangleArea(const float& area)  // pass by const ref.
{
    cout << "Area of Rectangle = " << area << endl;
}

int main()
{
    // Initializing the below variable via reading user input (Using function)  // function because one variable is initialized via reading user input.
    float length = ReadRectangleLength(); /*
    |
    |-------> The last thing to type. Type after writing "return" keyword in the implementing function */



    // Initializing the below variable via reading user input (Using function)  // function because one variable is initialized via reading user input.
    float width = ReadRectangleWidth(); /*
    |
    |-------> The last thing to type. Type after writing "return" keyword in the implementing function */


    // The variables 'length' and 'width' are now initialized

    PrintRectangleArea(CalculateRectangleArea(length, width));

    return 0;
}