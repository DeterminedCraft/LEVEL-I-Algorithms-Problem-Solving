
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



float ReadFloatNumber(const string &message)   // passed by constant reference.
{
    float number; // what's returned.

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}

bool ValidateWidth(const float& width)   // pass by constant reference.
{
    return (width > 0);
}

float ReadWidth(const string& message)  // pass by constant ref.
{
    float width; // what's returned.  // declared outside the do statement, so that it can be returned
    do
    {
        width = ReadFloatNumber(message);  // 'width' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateWidth(width)); // the condition is written so that, it evaluates to TRUE when the condition is INVALID.

    return width;

   
}

bool ValidateLength(const float& length, float width)    // pass by constant refernce   // range (width) ALWAYS passed by value.
{
    return (length > width);
}

float ReadLength(const string& message, float width)  // passing by constant reference.   // Range ALWAYS passed by value
{
    float length; // what's returned   // declared outside the do statement so that it can be returned.
    do
    {
        length = ReadFloatNumber(message);  // 'length' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateLength(length, width));  // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

    return length;


    /* Note: The above block of code is to be sequentially composed line by line
             and at the end, implement the functions of:
             ReadFloatNumber()   &    ValidateLength()
    */
}

float CalculateRectangleArea(float width, float length)   // pass by value
{
    return (width * length);
}

void PrintAreaOfRectangle(const float& width, const float& length)   // pass by constant reference
{
    cout << "The Rectangle's area = " << CalculateRectangleArea(width, length) << endl;
}

int main()
{
    // Initializing the below variable via reading user input( Using Function - since one variable will be initialized and returned):
    float width = ReadWidth("Enter width: "); // no range(s) includes as it's value in NOT intrinsic.
/*        |
          |--> to be typed at the end, after typing the 'return' keyword of the implementing function..
*/

    float length = ReadLength("Enter Length: ", width);  // the argument 'width' is the range, where the value entered (for length) has to be larger than width.
/*        |
          |--> to be typed at the end, after typing the 'return' keyword of the implementing function..
*/


    PrintAreaOfRectangle(width, length);  // this line is written so that, the printing procedure's implementation with have the function CalculateAreaOfTriangle()
                                          // this is the standard coding practice. As a side effect, this printing procedure will have access / can reference the
                                           // values of width and length that the user entered.

    return 0;
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// solving by initializing via reading user input using procedure:



float ReadFloatNumber(const string& WidthMessage)   // pass by constant ref.
{
    float number;   // what's returned.

    cout << WidthMessage;
    cin >> number;
    cout << endl;

    return number;
}

bool ValidateWidth(const float& width)   // pass by constant ref.
{
    return (width > 0);
}

void ReadWidth(const string& WidthMessage, float& width)  // pass by constant ref.   // width is passd by ref. Otherwise, how can you initialized it's already declared value in main() ?
{
    do
    {
        width = ReadFloatNumber(WidthMessage);   // 'width' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateWidth(width));  // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

    /*  Note: the above block of code is to be sequentially composed line by line 
              and at the end, implement the functions of:
              ReadFloatNumber()   &   ValidateWidth()
    */
}

bool ValidateLength(const float& length, float width)  // pass by constant ref.   // ranges (it's width in this particualr case) ALWAYS passed by value.
{
    return (length > width);
}

void ReadLength(const string& LengthMessage, float& length, float width)   // length is passed by ref. (otherwise, how to initialize its declared variable in main() ?)  // Range (width here) ALWAYS passed by value
{
    do
    {
        length = ReadFloatNumber(LengthMessage);  // 'length' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateLength(length, width));  // the argument is written so that, it evaluates to TRUE  when the condition is INVALID.

    /*  Note: the above block of code is to be sequentially composed line by line
              and at the end, implement the functions of:
              ReadFloatNumber()   &   ValidateLength()
    */
}


void ReadWidthAndLength(const string& WidthMessage, const string& LengthMessage, float& width, float& length)  // width & length are passed by ref. Otherwise, how can you initialize their already declared values in main() ?
{
    ReadWidth(WidthMessage, width);
    ReadLength(LengthMessage, length, width);   // the raw value of 'width' here represents the range, for which the length will be compared against (where length has to be > width)
}

float CalculateAreaOfRectangle(float width, float length)   // pass by value
{
    return (width * length);
}

void PrintAreaOfRectangle(const float& width, const float& length)   // pass by constant ref.
{
    cout << "The Area of the rectangle = " << CalculateAreaOfRectangle(width, length) << endl; 
}

int main()
{
    float width,length;
    // Initializing the above variables via reading user input (Using Procedure - since MORE than one variable will be initialized):

    ReadWidthAndLength("Enter width: ", "Enter Length: ", width, length);  // ranges NOT included as their value for width is not intrinsic & their value for length is the width itself (length has to be larger than the width).
    // the variables 'width' & 'length' are now initialized.

    PrintAreaOfRectangle(width, length);  // this called procedure is expressed so that, it's implementation contains the method CalculateAreaOfRectangle()
                                           // this is a standard approach. Separately / as a 'side effect', it can reference / has direct access to the 
                                           // original values of 'length' and 'width' that the user entered.


    return 0;
}







//////////////////////////////////////////////// Some first-attempt UNOPTIMIZED SOLUTIONS: //////////////////////////////////////////////
//////////////////////////////////////////////// Some first-attempt UNOPTIMIZED SOLUTIONS: //////////////////////////////////////////////
//////////////////////////////////////////////// Some first-attempt UNOPTIMIZED SOLUTIONS: //////////////////////////////////////////////
//
//
//
//void ReadRectangleInfo(float& length, float& width)  // pass by ref.
//{
//    cout << "Enter Rectangle's length: ";
//    cin >> length;
//    cout << endl;
//
//    cout << "Enter Rectangle's width: ";
//    cin >> width;
//    cout << endl;
//}
//
//float CalculateRectangleArea(float length, float width) // pass by value
//{
//    return length * width;
//}
//
//void PrintRectangleArea(const float& area)  // pass by const ref.
//{
//    cout << "Area of Rectangle = " << area << endl;
//}
//
//int main()
//{
//    float length, width;
//    // Initializing via reading user input:
//
//    ReadRectangleInfo(length, width);
//    // the variables 'length' abd 'width' are now initialized.
//
//
//    PrintRectangleArea(CalculateRectangleArea(length, width));
//
//    return 0;
//}
//
// 
// 
// 
// 
// 
// 
//                           //// Another way of coding below:
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Another way of coding, 
//// where the two variables are initialized via reading user input BUT this time by two functions:
// 
// 
//
//
//float ReadRectangleLength()
//{
//    float length; //what's returned.
//
//    cout << "Enter the Rectangle's length: ";
//    cin >> length;
//    cout << endl;
//
//    return length; 
//}
//
//float ReadRectangleWidth()
//{
//    float width;
//
//    cout << "Enter the Rectangle's width: ";
//    cin >> width;
//    cout << endl;
//
//    return width;
//}
//
//
//float CalculateRectangleArea(float length, float width) // pass by value
//{
//    return length * width;
//}
//
//void PrintRectangleArea(const float& area)  // pass by const ref.
//{
//    cout << "Area of Rectangle = " << area << endl;
//}
//
//int main()
//{
//    // Initializing the below variable via reading user input (Using function)  // function because one variable is initialized via reading user input.
//    float length = ReadRectangleLength(); /*
//    |
//    |-------> The last thing to type. Type after writing "return" keyword in the implementing function */
//
//
//
//    // Initializing the below variable via reading user input (Using function)  // function because one variable is initialized via reading user input.
//    float width = ReadRectangleWidth(); /*
//    |
//    |-------> The last thing to type. Type after writing "return" keyword in the implementing function */
//
//
//    // The variables 'length' and 'width' are now initialized
//
//    PrintRectangleArea(CalculateRectangleArea(length, width));
//
//    return 0;
//}