
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

// for an arbitrary triangle, in addition to the fact that any side should be > 0; The sum of any two sides must be greater than the remaining side.


struct stTriangleSides
{
    float SideA;
    float SideB;
    float SideC; 
};
// so far, only a structure user-defined data type has been created and nothing else.
// the next natural step is creating a variable of this structure user-defined data type-
// But the main questions is - Where to create this variable ?
//
// -If it's going to be initialized directly, then declare it inside main().
// -If it's going to be initialized via reading user input, then declare it inside a reading function of the structure user-defined data type.
// 
// since it's the latter, then IMMEDIATELY start implementing this function NOW BELOW:
// 



float ReadFloatNumber(const string& message)    // pass by constant reference.
{
    float number;  // what's returned.

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}

bool ValidateSideRange(const float& side)   // pass by constant reference since this value is only used for comparing against the ranges
{
    return (side > 0);
}

bool ValidateThirdSideRange(const float& SideC, float SideA, float SideB)  // passing by constant reference as it's only used for comparing against the ranges.  // ranges (float SideA, float SideB) ALWAYS passed by value
{
    return (SideC > 0   &&   (SideC < (SideA + SideB))  &&  (SideB < (SideC + SideA))  && (SideA < (SideC + SideB)));

    /* if it were a right-angled triangle (where c is the hypotenuse)
       
       return (SideC * SideC == (SideA * SideA) + (SideB * SideB));   faster than pow( , 2) for squares.
    
    */
}


stTriangleSides ReadTriangleSides(const string &SideAMessage, const string &SideBMessage, const string &SideCMessage)   // passing by constant reference.
{
    stTriangleSides TriangleSides;   // the next natural step of declaring a variable of the structure user-defined data type. // AS SOOS AS you see such a line, ALWAYS envision the variable having access to all member variables declared inside the structure

    do
    {
        TriangleSides.SideA = ReadFloatNumber(SideAMessage);  // 'TriangleSides' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateSideRange(TriangleSides.SideA));

    do
    {
        TriangleSides.SideB = ReadFloatNumber(SideBMessage); //'TriangleSides.SideB' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateSideRange(TriangleSides.SideB));

    do
    {
        TriangleSides.SideC = ReadFloatNumber(SideCMessage); // 'TriangleSides.SideC' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateThirdSideRange(TriangleSides.SideC, TriangleSides.SideA, TriangleSides.SideB));

    return TriangleSides;

    /* Note: The above block of code is to be sequentially composed line by line
             and at the end, implement the functions of:
             ReadFloatNumber()  &  ValidateSideRang()  & ValidateThirdSideRange()  */
}


float CalculateAreaOfCircle(float ParameterOfCircle, stTriangleSides TriangleSides)  // pass by value  // AS SOON AS you see such line (the argument in this case), ALWAYS ENVISIOn the variable having access to all member variables declared inside the structure.
{  
  
    const double PI = 3.141592653589793;

    return  PI * pow((TriangleSides.SideA * TriangleSides.SideB * TriangleSides.SideC) / (4 * sqrt(ParameterOfCircle * (ParameterOfCircle - TriangleSides.SideA) * (ParameterOfCircle - TriangleSides.SideB) * (ParameterOfCircle - TriangleSides.SideC))),2);
}

float CalculateSemiParameter(stTriangleSides TriangleSides)   // pass by value.  // AS SOON AS you see such line (the argument in this case), ALWAYS ENVISIOn the variable having access to all member variables d
{
    return (TriangleSides.SideA + TriangleSides.SideB + TriangleSides.SideC) / 2; // is NOT an integer division as the devided by is of a float data type.
        
}


void PrintCircleArea(const stTriangleSides& TriangleSides)   // pass by constant reference.  // AS SOON AS you see such line (the argument in this case), ALWAYS ENVISIOn the variable having access to all member variables declared inside the structure.
{
    cout << "The Area of the Circle = " << CalculateAreaOfCircle(CalculateSemiParameter(TriangleSides), TriangleSides) << endl;
}


int main()
{
    // Instead of declaring base, height, and hypotenuse as variables in main,
    // I am going to declare them as member variables inside a structure
    // since they're related amongst each other.

    PrintCircleArea(ReadTriangleSides("Enter side A: ", "Enter side B: ", "Enter side C: ")); 
    // this printing procedure will have CalculateCircleArea() function in its implementation
    // this is the standard approach. Additionally, as a 'side effect', 
    // this printing procedure will have access / can reference all the values inputed by the user 


    return 0;
}





                      ////////////////////////////  some old UNOPPTIMIZED solution below ////////////////////////////
                      ////////////////////////////  some old UNOPPTIMIZED solution below ////////////////////////////
                      ////////////////////////////  some old UNOPPTIMIZED solution below ////////////////////////////





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



