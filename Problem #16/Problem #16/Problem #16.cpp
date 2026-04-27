
#include <iostream>
#include <cmath>
using namespace std;

/*
 Problem #16:

 Write a program to calculate rectangle area through diagonal and side of the rectangle
 and print it on the screen.

 The user should enter:
 a (width)
 d (diagonal)

 Formula:
 Area = a * √(d² - a²)

 Example Inputs:
 5
 40

 Output:
 198.431

*/



void ReadRectangleInfo(float& width, float& diagonal) // pass by ref.
{
    cout << "Enter rectangle's width: ";
    cin >> width;
    cout << endl;

    cout << "Enter Rectangle's diagonal length: ";
    cin >> diagonal;
    cout << endl;
}

float CalculateRectangleAreaBySideAndDiagonal(float width, float diagonal) //  pass by value
{
    return width * sqrt(pow(diagonal,2) - pow(width,2))    // better with the use of pow() function.
    //return width * sqrt((diagonal * diagonal) - (width * width)); 
}

void PrintRectangleArea(const float& area)  // pass by const. reference
{
    cout << "Rectangle's area = " << area << endl;
}


int main()
{
    float width, diagonal;
    // Initializing via reading user input:

    ReadRectangleInfo(width, diagonal);
    // The two variables width & diagonal are now initialized.

    PrintRectangleArea(CalculateRectangleAreaBySideAndDiagonal(width, diagonal));




    return 0;
}

