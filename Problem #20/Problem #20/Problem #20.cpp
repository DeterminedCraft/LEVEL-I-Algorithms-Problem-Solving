
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


float ReadFloatNumber(const string& message)   // pass by constant ref.
{
    float number;   // what's returned

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}

bool ValidateSquareSideRange(const float& SquareSide)    // passing by constant ref. since we only want to compare
{
    return (SquareSide > 0);
}

float ReadSquareSide(const string& message)   // pass by constant reference.
{
    float SquareSide;   // what's returned    // declared outside the 'do' statement so that it can be returned by the function.
    
    do
    {
        SquareSide = ReadFloatNumber(message);  // 'SquareSide' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateSquareSideRange(SquareSide));  // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

    return SquareSide; 
    /*
     Note: The above lines of code are to be sequentially composed line by line and
           at the end, implement the functions of:  ReadFloatNumber()   &   ValidateSquareSideRange()
    
    */
}

double CalculateAreaOfTheCircle(float SquareSide)   // pass by value
{
    const double PI = 3.141592653589793;
    return (PI * SquareSide * SquareSide) / 4;     // this is NOT an integer division - double is divided by 4
    // implicit conversion occurs here - float (smalled data type) is promoted to double by the compiler (no dat loss occurs).
    // so a final double value is ready to be returned - and this is why the functîon's return type is double (because if it were float, then another implicit conversion takes place
    // from double to float, resulting in data loss.
}


void PrintCircleArea(const float& SquareSide)   // pass by constant ref.
{
    cout << "The Area of the Circle is: " << CalculateAreaOfTheCircle(SquareSide) << endl;
}


int main()
{
    //Initializing the below variable via reading user input (Using Function since ONE variable is initialized and returned):
    float SquareSide = ReadSquareSide("Enter square side length: "); // range(s) not included as the value(s) is not intrinsic.
/*         |
           |---> to be typed at the end, after typing the "return" keyword in the implementing function. */
 
    PrintCircleArea(SquareSide);  // this procedure will contain the CalculateCircleArea() function, instead of having this function as an argument in this procedure
                                  // this is the standard way of coding. Plus, it will result in this procedure having the ability to reference the original value
                                 //^SquareSide^  the user entered.



    return 0;
}



                     /////////////////////////// Some old unoptimized solution //////////////////////////////////
                    /////////////////////////// Some old unoptimized solution //////////////////////////////////
                   /////////////////////////// Some old unoptimized solution //////////////////////////////////
//
//float ReadSquareInfo()
//{
//    float SquareSideLength; // what's returned.
//
//    cout << "Enter the Length of the Square Side: ";
//    cin >> SquareSideLength;
//    cout << endl;
//
//    return SquareSideLength;
//}
//
//double CalculateCircleArea(float SquareLength) // passing by value
//{
//    const double PI = 3.141592653589793;
//    return (PI * SquareLength * SquareLength) / 4;  // calculation involving a mix of float & double values. The smaller data type will be automatically promoted to the larger one (to double)
//                                                    // Therefore, the return type of the function is double (instead of designating it as float where the area of value double is converted 
//                                                    // to float again, just before returning.
//      
//}
//
//void PrintCircleArea(const double& CircleArea)  //passing by constant reference.
//{
//    cout << "The Circle Area inscribed in a square = " << CircleArea << endl;
//}
//
//int main()
//{
//
//    PrintCircleArea(CalculateCircleArea(ReadSquareInfo()));
//
//    return 0;
//}