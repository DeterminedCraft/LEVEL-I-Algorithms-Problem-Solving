
#include <iostream>
#include <cmath>
using namespace std;

/*
==============================================================
 Problem #23:

 Write a program to calculate the CIRCLE AREA of a circle
 described around an arbitrary triangle, then print it
 on the screen.

 The user should enter (sides of the triangle):
 a
 b
 c

 Formulas:

 1) Calculate the semi-perimeter of the triangle:

   p = (a + b + c) / 2

 2) Use the circumcircle area formula:

                                a * b * c
   Area = π * ( ---------------------------------------------- )^2
                  4 * √( p * (p - a) * (p - b) * (p - c) )

 Example Inputs:
 5
 6
 7

 Output:
 40.088
==============================================================
*/



struct stCircleInfo
{
    float length;
    float base;
    float hypotenuse;
};
// So far we've only created a structure user-defined data type and nothing more.
// The next natural step is declaring a variable of this user-defined data type
// that's either going to be a normal variable (ONE record) or an array variable (MORE than one record)
//
// Howerver, the most important question is- where should this variable be declared ?
    // If it's going to be initialized directly, then declare it inside main()
   //  If it's going to be initialized via reading user input, then declare it in a READING FUNCTION of TYPE STRUCTURE since it'll return this variable
        // since its the former, I will start by IMMEDIATELY implement this function NOW below (100 % correct & validated):


stCircleInfo ReadCircleInfo()
{
    stCircleInfo CircleInfo; // The next natural step of declaring a variable, thats's a normal variable (one record) of the structure user-defined data type what's returned.
    // 'CircleInfo' has access to all member variables defined in the structure user-defined data type (ALWAY remember this whenever you see it ANYWHERE in the program).
   // now TrianlgeInfo will have access to all member variables (ALWAYS envision this when you see such line ANYWHERE in the program)
    cout << "Enter Length of the triangle inside the circle: ";
    cin >> CircleInfo.length;
    cout << endl;

    cout << "Enter Base of the triangle inside the circle: ";
    cin >> CircleInfo.base;
    cout << endl;

    cout << "Enter Hypotenuse of the triangle inside the circle: ";
    cin >> CircleInfo.hypotenuse;
    cout << endl;
    
    return CircleInfo;
} // now the next immediate step involved contemplating the nested functions line in main().



float CalculateCircleCircumference(stCircleInfo CircleInfo) // passing by value.
{
    return (CircleInfo.length + CircleInfo.base + CircleInfo.hypotenuse) / 2;  // NOT an integer division since the divided will be of float data type.
}

double CalculateCircleArea(stCircleInfo CircleInfo, float CircleCircumf) // by value
{
    const double PI = 3.141592653589793;
    return PI * pow( ((CircleInfo.length * CircleInfo.base * CircleInfo.hypotenuse) / (4 * sqrt(CircleCircumf * (CircleCircumf - CircleInfo.length) * (CircleCircumf - CircleInfo.base) * (CircleCircumf - CircleInfo.hypotenuse)))),2);
    // NO integer division here // since floats are calculated with doubles, floats are promoted automatically to doubles (no data loss).
    // also the return type of the function should be double (rendering it float, will convert the final calculation result from double to float ( data loss). also we would like
    // the answer to be double ( and not rounded to function) so that the final answer is as accurate as possible. Also, if any rounding is performed, then it MUST be for the LAST & FINAL answer only.
}

void PrintCircleArea(const double& CircleArea) // passing by constant reference
{
    cout << "The Circle's Area = " << CircleArea << endl;
}

int main()
{
    // Instead of declaring a,b,c, & p as variables in main(),
    // we declare them as member variables inside a structure(s) since they're related amongst each other
    // 
    // separate (also related): 
    // Initializing variables via reading user input, using a procedure with 3-4 + arguments denotes an unoptimized approach ( and in real-time you'll deal wuth much more variables).
    // Initializing each of the 4 variables via reading user input (using function), means that the calling function will have that many arguments (3+) which = unoptimized approach.

    stCircleInfo CircleInfo = ReadCircleInfo();   // storing the returned value in a variable that could have any othe name.

 

    PrintCircleArea(CalculateCircleArea(CircleInfo, CalculateCircleCircumference(CircleInfo)));

    // unoptimal solution:
    // PrintCircleArea(CalculateCircleArea(ReadCircleInfo(), CalculateCircleCircumference(ReadCircleInfo()))); 
    // you are executing the Reading function twice ! Just do it once and store the value !
    // on top opf being hard to read (comprehend).

    return 0;

    /*    considered 'cleaner' for the function above: 

    double CalculateCircleArea(stCircleInfo CircleInfo, float p)
    {
        const double PI = 3.141592653589793;

        double R =
            (CircleInfo.length * CircleInfo.base * CircleInfo.hypotenuse) /
            (4 * sqrt(p *
                (p - CircleInfo.length) *
                (p - CircleInfo.base) *
                (p - CircleInfo.hypotenuse)));

        return PI * R * R;
        */
    }



