
#include <iostream>
using namespace std;

/*
==============================================================
 Problem:
 Write a program to calculate CIRCLE AREA inscribed in an
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

/* NOTE: In an isosceles triangle the conditions are :
         - a & b > 0
         - b < 2a
 
*/
       

float ReadFloatNumber(const string& LengthMessage)    // pass by constant ref. 
{
    float number;  /// what's returned.

    cout << LengthMessage;
    cin >> number;
    cout << endl;

    return number;
}

bool ValidateLengthOrBaseRange(const float& LengthOrBase)    // pass by constant ref since we are using it just to compare.
{
    return (LengthOrBase > 0);
}


void ReadLengthOrBase(const string& LengthOrBaseMessage, float& LengthOrBase)   // passing length by ref (otherwise, how can you initialized its declared variable in main() ? )
{
    do
    {
        LengthOrBase = ReadFloatNumber(LengthOrBaseMessage);  // ' length' is to be IMMEDIATELY validated against the range, in the while condition

    } while (!ValidateLengthOrBaseRange(LengthOrBase)); // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

    // Note:  The above lines of code are to be sequentially composed line by line and
    //        at the end, implement the functions of: ReadFloatNumber()  &    ValidateLengthRange()
}


bool ValidateBaseRange(const float& base, float length)   // pass by constant ref. since base is used for comparison   // Range (length in this specific case) ALWAYS passed by value.
{
    return (base < 2 * length); 
}

void ReadLengthAndBase(const string& LengthMessage, const string& BaseMessage, float& length, float& base)  // passing length & base by ref, (otherwise, how can one initialize their declared variables inside main() ?)
{
    ReadLengthOrBase(LengthMessage, length);
    do                                        // do- while statement to satisfy the range base < 2length
    {
        ReadLengthOrBase(BaseMessage, base);

    } while (!ValidateBaseRange(base, length));    // base must be < 2*length
   
}

double CalculateAreaOfCircle(float length, float base)   // pass by value
{
    const double PI = 3.141592653589793;
    return  PI * ((base * base) / 4) * ((2 * length) - base) / ((2 * length) + base);     // NOT an integer division          //  π * (b^2 / 4) * ((2 * a - b) / (2 * a + b))
}

void PrintCircleArea(const float& length, const float& base)    // pass by constant ref.
{
    cout << "The Circle's Area = " << CalculateAreaOfCircle(length, base) << endl;
}

int main()
{
    float length, base;
    // Initializing the above variables via reading user input (Using Procedure - Since MORE than one variable will be initialized):
    ReadLengthAndBase("Enter length: ", "Enter base: ", length, base); // ranges NOT included as their values are NOT intrinsic.
    // length & base are now initialized.

    PrintCircleArea(length, base);  // this printing procedure's implementation will have inside it the function CalculateAreaOfCircle.
	                                  // this is the standard coding approach. Moreover and separately, this printing procedure
	                                 // will have access / can reference the original values the user entered (length and base).


    return 0;
}






//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Solving it using 2 reading functions: 



float ReadFloatNumber(const string& message)   // pass by constant reference.
{
    float number; // what's returned

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}

bool ValidateBaseRange(const float& base)  // pass by constant ref. since base is only used for comparison.
{
    return (base > 0);
}



float ReadBase(const string& message)
{
    float base;  // what's returned

    do
    {
        base = ReadFloatNumber(message);  // 'base' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateBaseRange(base));

    return base;

    /* Note: The above lines of code are to be sequentially composed
             line by line, and at the end implement the functions of:
             ReadFloatNumber()   & ValidateBaseRange()
    
    */
}

bool ValidateLengthRange(const float& length, float base) // pass by constant ref. since we are only comparing   // ranges (base in this case) ALWAYS passed by value
{
    return (length > 0 && (2 * length > base));
}

float ReadLength(const string& message, float base)  // Ranges ALWAYS passed by value.
{
    float length;   //what's returned.  // declared outside the 'do'statement so it can be returned as it's scope is at the function level.

    do
    {
        length = ReadFloatNumber(message);  // 'length' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateLengthRange(length, base));

    return length;

}

double CalculateAreaOfCircle(float length, float base)   // pass by value
{
    const double PI = 3.141592653589793;
    return  PI * ((base * base) / 4) * ((2 * length) - base) / ((2 * length) + base);     // NOT an integer division          //  π * (b^2 / 4) * ((2 * a - b) / (2 * a + b))
}

void PrintCircleArea(const float& length, const float& base)    // pass by constant ref.
{
    cout << "The Circle's Area = " << CalculateAreaOfCircle(length, base) << endl;
}


int main()
{
    // Initializing the below variable via reading user input (Using Function since One variable is initialized and returned):
    float base = ReadBase("Enter base: "); // ranges NOT included as their values are NOT intrinsic.
/*       |
         |---> to be typed at the end, when finishing typing the "return" keyword in the implementing function. */

    
    float length = ReadLength("Enter length: ", base);  // 'base' is the range here.
    /*       |
             |---> to be typed at the end, when finishing typing the "return" keyword in the implementing function. */

   
   PrintCircleArea(length, base);  // this printing procedure's implementation will have inside it the function CalculateAreaOfCircle.
                                   // this is the standard coding approach. Moreover and separately, this printing procedure
                                   // will have access / can reference the original values the user entered (length and base).

   return 0;
}































// ///////////////////////////// some OLD UNOPTIMIZED solutions //////////////////////////////////////////
// ///////////////////////////// some OLD UNOPTIMIZED solutions //////////////////////////////////////////
// ///////////////////////////// some OLD UNOPTIMIZED solutions //////////////////////////////////////////
//
//float ReadTriangleLength()
//{
//    float length; // what's returned.
//
//    cout << "Enter the length of the triangle: ";
//    cin >> length;
//    cout << endl;
//
//    return length;
//}
//
//float ReadTriangleBase()
//{
//    float base; // what^s returned.
//    
//    cout << "Enter the base of the triangle: ";
//    cin >> base;
//    cout << endl;
//
//    return base;
//}
//
//double CalculateCircleArea(float length, float base) // passing by value
//{
//    const double PI = 3.14159265358979323846;
//    return PI * (  base * base / 4  ) * (    ((2 * length) - base) / ((2 * length) + base)     ); //  NO integer division for the two '/'
//}
//
//void PrintCircleArea(const double &CircleArea) // pass by constant ref.
//{
//    cout << "The Circle's area = " << CircleArea << endl;
//}
//
//int main()
//{
//   
//    PrintCircleArea(CalculateCircleArea(ReadTriangleLength(), ReadTriangleBase()));
//
//	return 0;
//
//    /* Instead of:
//       
//       // Initializing the below variable via reading user input (Using function) //since ONE variable is initialized.
//
//       float // Initializing the below variable via reading user input (Using function) //since ONE variable is initialized.
//
//       float TriangleLength =   ReadTriangleLength(); 
//       |
//       |
//       |-------> The last thing to type. Type after writing "return" keyword in the implementing function. =   ReadTriangleLength(); 
//       |
//       |
//       |-------> The last thing to type. Type after writing "return" keyword in the implementing function.
//    
//      
//      // Initializing the below variable via reading user input (Using function) //since ONE variable is initialized.
//
//       float TriangleBase =   ReadTriangleBase();
//       |
//       |
//       |-------> The last thing to type. Type after writing "return" keyword in the implementing function.
//    
//
//       PrintCircleArea(CalculateCircleArea(TriangleLength, TriangleBase));
//
//    */
//}
//
///////////////////////////////////////////////////////////////////////////////////
//
//// OR: solve this problem by initializing the two variables declared in main() via reading user input using a procedure.
//
//
//
//
//double CalculateCircleArea(float length, float base) // passing by value
//{
//    const double PI = 3.14159265358979323846;
//    return PI * (base * base / 4) * (((2 * length) - base) / ((2 * length) + base));   // there will be NO integer division.
//}
//
//void PrintCircleArea(const double& CircleArea) // pass by constant ref.
//{
//    cout << "The Circle's area = " << CircleArea << endl;
//}
//
//void ReadTriangleInfo(float& TriangleLength, float& TriangleBase)  // passing by reference. 
//{
//    cout << "Enter Triangle's length: ";
//    cin >> TriangleLength;
//    cout << endl;
//
//    cout << "Enter Triangle's Base: ";
//    cin >> TriangleBase;
//    cout << endl;
//}
//
//int main()
//{
//    float TriangleLength, TriangleBase; 
//    // Initializing the two variables via reading user input:
//
//    ReadTriangleInfo(TriangleLength, TriangleBase);
//    // the two variables 'TriangleLength'  &  'TriangleBase' are now initialized.
//
//    PrintCircleArea(CalculateCircleArea(TriangleLength, TriangleBase));
//
//    return 0;
//}