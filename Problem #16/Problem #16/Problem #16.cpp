
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




float ReadFloatNumber(string message)
{
    float number; // what's returned.

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}

bool ValidateWidthRange(const float& width)  // pass by constant reference
{
    return (width > 0);
}

float ReadWidth(string message)
{
    float width;  // what's returned.   // declared outside the do statement so that it can be returned (declaring it inside the 'do', renders it's scope/visibility to only that of the 'do').
    do
    {
        width = ReadFloatNumber(message);  // 'width' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateWidthRange(width)); // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

    return width;

    /* Note:
       The above block of code is to be sequenmtially composed line by line
       , and at the end implement the functions of:
       ReadFloatNumber()  &  ValidateWidthRange()
    
    */
}


bool ValidateDiagonalRange(const float& diagonal, float width) // pass by constant ref.  // Ranges (width) ALWAYS passed by value
{
    return (diagonal > width);
}

float ReadDiagonal(const string& message, float width)  // ranges (width) ALWAYS passed by value
{
    float diagonal;  //what's returned.

    do
    {
        diagonal = ReadFloatNumber(message);  // ' diagonal' is to be IMMEDIATELY validated against the range, in the whil condition.

    } while (!ValidateDiagonalRange(diagonal, width));

    return diagonal;

    /* Note:
      The above block of code is to be sequenmtially composed line by line
      ,and at the end implement the functions of:
      ReadFloatNumber()  &  ValidateDiagonalRange()

   */
}

float CalculateAreaOfRectangle(float width, float diagonal)   // pass by value
{
    return (width * sqrt(pow(diagonal,2) - pow(width,2)));    // same as: (width * sqrt((diagonal * diagonal) - (width * width)));
}


void PrintAreaOfRectangle(const float& width, const float& diagonal)   // pass by constant reference.
{
    cout << "The Area of the Rectangle = " << CalculateAreaOfRectangle(width, diagonal) << endl;
}


int main()
{
    // Initiating the below variable via reading user input (Using function - since ONE variable is initialized and returned):
    float width = ReadWidth("Enter width: ");  // range(s) not included as their value is NOT intrinsic.
/*        |
          |---> to be typed at the end, after typing the "return" keyword of the implementing function.
*/


    //Initializing the below variable via reading user input (Using function - since ONE variable is initialized and returned):
    float diagonal = ReadDiagonal("Enter diagonal: ", width);  // range is included (width) as it's value is intrinsic (diagonal should be > width)
/*        |
          |---> to be typed at the end, after typing the "return" keyword of the implementing function.
*/

    PrintAreaOfRectangle(width, diagonal);  // this line is constructed so that, this printing procedure contains the function CalculateAreaOfRectangle()
                                            // this is the standard approach. Separately / as a 'side effect', this printing procedure can reference / has
                                           // an access to the values of 'width' & 'length' the user entered.

    return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Solving this example, using a procedure that initialized both 'width' & 'length'





float ReadFloatNumber(string message)
{
    float number; // what's returned.

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}


bool ValidateWidthRange(const float& width) // pass by constant reference.
{
	return (width > 0);
}


void ReadWidth(const string& WidthMessage, float& width) // pass width by ref. so its declared variables in main can be initialized.
{
	do
	{
		width = ReadFloatNumber(WidthMessage);   // 'width' is IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateWidthRange(width)); // the argument isd written so that, it evaluates to TRUE when the condition is INVALID.
	
	/* Note:
         The above block of code is to be sequenmtially composed line by line
        ,and at the end implement the functions of:
         ReadFloatNumber()  &  ValidateWidthRange()
     */
}

bool ValidateDiagonalRange(const float& diagonal, float width)   // pass by constant reference.  // Ranges ALWAY passed by value (in this sepcific scenario, the range happens to be 'width')
{
	return (diagonal > width);
}

void ReadDiagonal(const string& DiagonalMessage, float& diagonal, float width) //'diagonal' passed by ref. so its declared values in main() can be initialized.  // Range (width) ALWAYS passed by value.
{
	do
	{
		diagonal = ReadFloatNumber(DiagonalMessage); // 'diagonal' is to be IMMEDIATELY validated against the range, in the while condition

	} while (!ValidateDiagonalRange(diagonal, width)); // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

	/* Note:
		 The above block of code is to be sequentially composed line by line
		,and at the end implement the functions of:
		 ReadFloatNumber()  &  ValidateDiagonalRange()
	 */
}


void ReadWidthAndDiagonal(const string& WidthMessage, const string& DiagonalMessage, float& width, float& diagonal) // pass width & diagonal by ref. so their declared variables in main can be initialized.
{
	ReadWidth(WidthMessage, width);
	ReadDiagonal(DiagonalMessage, diagonal, width);
}

float CalculateAreaOfRectangle(float width, float diagonal)   // pass by value
{
    return (width * sqrt(pow(diagonal,2) - pow(width,2)));    // same as: (width * sqrt((diagonal * diagonal) - (width * width)));
}


void PrintAreaOfRectangle(const float& width, const float& diagonal)   // pass by constant reference.
{
    cout << "The Area of the Rectangle = " << CalculateAreaOfRectangle(width, diagonal) << endl;
}

int main()
{
	float width, diagonal;
	// Initializing the above variables via reading user input (Using Procedure - since MORE than one variable will be initialized):

	ReadWidthAndDiagonal("Enter width: ", "Enter Diagonal: ", width, diagonal); // range for width not included as it's value is NOT intrinsic // range for diagonal is that, diagonal will have to be > width
	// the variables 'width' & 'diagonal' are now initialized.

    
	PrintAreaOfRectangle(width, diagonal);  // this line is constructed so that, this printing procedure contains the function CalculateAreaOfRectangle()
                                            // this is the standard approach. Separately / as a 'side effect', this printing procedure can reference / has
                                           // an access to the values of 'width' & 'length' the user entered.

	return 0;
}



//////////////////////////////////////////////////////////////////////////// BELOW: An old UNOPTMIZED solution ////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//
//
//void ReadRectangleInfo(float& width, float& diagonal) // pass by ref.
//{
//    cout << "Enter rectangle's width: ";
//    cin >> width;
//    cout << endl;
//
//    cout << "Enter Rectangle's diagonal length: ";
//    cin >> diagonal;
//    cout << endl;
//}
//
//float CalculateRectangleAreaBySideAndDiagonal(float width, float diagonal) //  pass by value
//{
//    return width * sqrt(pow(diagonal,2) - pow(width,2))    // better with the use of pow() function.
//    //return width * sqrt((diagonal * diagonal) - (width * width)); 
//}
//
//void PrintRectangleArea(const float& area)  // pass by const. reference
//{
//    cout << "Rectangle's area = " << area << endl;
//}
//
//
//int main()
//{
//    float width, diagonal;
//    // Initializing via reading user input:
//
//    ReadRectangleInfo(width, diagonal);
//    // The two variables width & diagonal are now initialized.
//
//    PrintRectangleArea(CalculateRectangleAreaBySideAndDiagonal(width, diagonal));
//
//
//
//
//    return 0;
//}

