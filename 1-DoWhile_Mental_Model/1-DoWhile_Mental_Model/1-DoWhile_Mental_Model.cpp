// DoWhile_Mental_Model.cpp 

#include <iostream>
using namespace std;

/*

 In the previous pre-requisite (not final) mental model, the UNIVERSAL INPUT UTILITIES,
 have implementations where the Divide and Conquer strategiy isn't fully taken advantage of.

 It should and will be applied on:
  - The do statement's body.
  - The while's argument.

 */


 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* ////////////////////////////////////////////////////////////////  Reading Functions Mental Model :  ////////////////////////////////////////////////////////////////////////////////////*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
   Functions called are:
   ReadPositiveInt("string message"),
   ReadNegativeInt("string message"),
   ReadIntegerInRange("string message",  from,to),
   ReadIntWithRestriction("string message",  restricted),
   ReadIntEqualOrBiggerThanZero("string message"),
   ReadIntEqualOrSmallerThanZero("string message")

   // Each called function takes one string message.

   // This is the BEST approach, as the string msg becomes highly customizable / flexible depending on the problem itself,
   // instead of embedding it within the implementation of the utility where it's deemed one size fits all
   // example: "Enter a positive integer " in the implementation, instead of "Enter temerature in Celcius"      */


   /*
                                            Calling the function INSIDE MAIN():
                                        ----------------------------------------------

  A-  Either in nested functions line: Example:      */
PrintPositiveInteger(ReadPositiveInt(" Some string message"));

/*
B-  OR independently :  Example:  */

// Initializing the below variable via reading user input (Using Function- Since ONE variable is initialized and returned).

int number = ReadPositiveInt(" Some string message");
/*  |
    |
    |-------> The last thing to type. Type after writing "return" keyword in the implementing function.      */



    /*--------------------------------------------------------------------------------
   In either A or B, include the prompting string message in the calling function:  */


ReadPositiveInt(" Enter a positive integer"); // range argument(s) not included as their values are intrinsic.


/* Implementing the function outside main() on top:  */

int ReadPositiveInt(const string& msg)  // passing by constant reference.
{
    int number;     // what's returned.

    do
    {
        number = ReadNumber(msg);     // 'number' is IMMEDIATELY validated against the range, in the while condition

    } while (!ValidatePositiveInt(number)); // 👈 👈the argument is written so that, it's TRUE when the condition is invalid

    return number;

    // Note: The above lines of code are to be written sequentially line by line,
    // and at the end, implement the functions of:     ReadPositiveInt()   &    ValidatePositiveInt() :

}




int ReadNumber(const string& msg) // passing by constant reference 
{
    int number;  // what's returned.

    cout << msg << endl;
    cin >> number;
    cout << endl;

    return number;
}


bool ValidatePositiveInt(const int& number)  // pass by constant reference.
{
    return (number > 0);
}
   }


   */
       /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


       /*                                                              Calling the function inside main():
                                                                  ---------------------------------------------- */

       int min = 1;   // Include here. Never hardcode.
   int max = 10;  // Include here. Never hardcode.

   ReadIntInRange(" Enter an integer between " + to_string(min) + " & " + to_string(max), min, max);  // ranges are included as their values are NOT intrinsic. 


   //Implementing this function outside main() on top:

   int ReadIntInRange(const string& msg, int min, int max) // pass by constant reference. // also- ranges ALWAYS passed by value.
   {

       int number; // what's returned.

       do
       {
           number = ReadNumber(msg); // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

       } while (!ValidateIntRange(number, min, max));  //👈 👈 the argument is written so that, it's TRUE when the condition is INVALID.

       return number;

       // NOTE: The above lines of code are to be sequentially written step by step
       // and at the end, implement the functions of: 
       // ReadNumber()   &   ValidateIntRange()

   }

   int ReadNumber(const string& msg)  // pass by constant reference.
   {
       int number; // what's returned;

       cout << msg << endl;
       cin >> number;

       return number;
   }


   bool ValidateIntRange(const int& number, int min, int max)   // pass by constant reference. // ranges are ALWAYS passed by value.
   {
       return  (min <= number && number <= max);
   }


   // Avoid:    ReadPositiveIntInRange() or ReadnegativeIntInRange(), etc.
   // and only use: ReadIntInRange() 
   // so that any of the two ranges can be positive or negative.
   // otherwise, we'll be creating more utilities / less optimization.

 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



                                                 /* Calling the function inside main():
                                               ----------------------------------------------*/

   int RestrictedNumber = 42; // declare and initialize here (Never hardcode in the calling function)

   ReadIntWithRestriction(" Enter an Integer (Except for the value of " + to_string(RestrictedNumber) + " )", RestrictedNumber); // passing the range argument as its value is NOT intrinsic.



   // Implementing this function outside main(), on top:

   int ReadIntWithRestriction(const string& message, int restricted) // passing by constant reference // range values ALWAYS passed by value
   {
       int number;  // what's returned.

       do
       {
           number = ReadNumber(message); // passing by constant reference. // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

       } while (!ValidateIntWithRestriction(number, restricted))  // 👈👈 the argument is written so that, it's TRUE when the condition is INVALID.

           return number;


       // NOTE: The above lines of code are to be sequentially written line by line
       // and at the end, implement the functions of:   ReadNumber()     &     ValidateIntWithrestriction():


       int ReadNumber(const string & message) // passing by constant reference.
       {
           int number;  // what's returned

           cout << message << endl;
           cin >> number;
           cout << endl;

           return number;
       }


       bool ValidateIntWithRestriction(const int& number, int restricted);  // passing by reference  // ranges ALWAYS passed by value.
       {
           return (number != restricted);
       }




       // to do:
       // AND THE ABOVE 3 UNIVERSAL INPUT UTILITIES COULD BE OF: float, double, unsigned short, long long, etc. data types.
       // add more notes if possible / list all possible utilities's names


      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     /* ////////////////////////////////////////////////////////////////  Reading Procedures Mental Model :  ////////////////////////////////////////////////////////////////////////////////////*/
     //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

       /* Calling the procedure INSIDE MAIN() :
       ---------------------------------------------- */
       int x, y;
       // Initializing via reading user input using a proceure (since MORE than one variable will be initialized):

       ReadTwoPositiveInt("Enter a positive integer: ", x, y);
       // x & y are now initialized


      // Where the implementation is:

       void ReadTwoPositiveInt(const string & message, int& x, int& y)
       {

           do
           {
               x = ReadNumber(message); //x is to be IMMEDIATELY validated against the range, in the while condition.

           } while (!ValidatePositiveInt(x));  //👈 👈 the argument is written so that it's TRUE when the condition is INVALID.


           do
           {
               y = ReadNumber(message); // 'y' is to be IMMEDIATELY validated against the range, in the while condition

           } while (!ValidatePositiveInt(y)); //👈 👈 the argument is written so that it's TRUE when the condition is INVALID.

       }

       // NOTE: the above lines of code are to be sequentially written line by line
       // and at the end, implement the functions of ReadNumber()  &  ValidatePositiveInt():

       int ReadNumber(const string & message)  // pass by constant reference.
       {
           int number; // what's returned.

           cout << message;
           cin >> number;
           cout << endl;

           return number;
       }



       bool ValidatePositiveInt(const int& number) // pass by constant reference.
       {
           return (number > 0);
       }









