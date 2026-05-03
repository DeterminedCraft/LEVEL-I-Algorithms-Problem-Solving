
#include <iostream>
using namespace std;

/*
==============================================================
 Problem #24

 Write a program to ask the user to enter:

 • Age

 If age is between 18 and 45 print "Valid Age"
 otherwise print "Invalid Age".


 Sample Input:

 Please enter age:
 17


 Output:

 17 is an INVALID age.
==============================================================
*/

// this is NOT FINAL & an UNOPTIMIZED solution: 
//  in C++ Level II we're going to learn how build utilities.




unsigned short ReadAge(unsigned short InputRangeValidation) // ranges ALWAYS passed by value.
{
    unsigned short age; // what's returned. //should be outside the do, so that it's returned by the function.
    do
    {                                
        cout << "Please enter age: ";  // 👈  to move to a function from now and on  = the DO block (along with what's returned line above)
        cin >> age;  // range validated IMMEDIATELY in the while condition (as for positive number, "unsigned" is the hint)
        cout << endl;

    } while(age > InputRangeValidation);   // 👈  to move to a function from now and on (The while argument)
    // Written so that it's TRUE when condition is INVALID // IMPERATIVE user-input validation (independent of the problem's specific age validity ranges)
      
    return age;
}

bool IsAgeValid(unsigned short age, unsigned short MinAge, unsigned short toAge) // passing by value. // ranges are ALWAYS passed by value.
{
    return(age >= MinAge && age <= toAge);
}

void PrintAgeValidity(const unsigned short &age, unsigned short MinAge, unsigned short toAge) // passing by constant reference.As for ranges, always by value.
{
    if (IsAgeValid(age, MinAge, toAge)) //   IsAgeValid() has to be a function, as procedures return void = exception thrown on this line.
    {
        cout << age << " is a valid age" << endl;
    }
    else
    {
        cout << age << " is an INVALID age" << endl;
    }
}


int main()
{
    unsigned short InputRangeValidation = 150; // Instead of hardcoding it in the called function below.
    unsigned short MinAge = 18;
    unsigned short toAge = 45;

    PrintAgeValidity(ReadAge(InputRangeValidation), MinAge, toAge);  // first line to ever think of.
   

    return 0;
}

/* Tips: The nested functions line should be:

    PrintValidOrInvalidAge(readAge());

    becasue inside the printing procedure we call a boolean function inside an if statement (if this can be done, then this
    is how it SHOULD BE DONE (for enums, this rule does not apply = try to solve 'naturally' with enums))
    
    NEW RULE: 👉 And also, THIS boolean function inside the if statement is supposed 
                 to be a utility ( as will be illustrated in C++ level II course). 
                 Therefore, the naming should change from the specific 

                 IsAgeValid((unsigned short age, unsigned short MinAge, unsigned short toAge)) 

                 to the general 
                 
                 ValidateNumberInRange(unsigned short Number, unsigned short From, unsigned short To)



    and this is why, one should NOT have a nested functions line such as:

    PrintValidOrInvalidAge(IsAgeValid(age));

    becasue the boolean function IsAgeValid() should be called inside the printing procedure (a standard pattern).
    and with this line, we could never achieve that.

    this standard pattern could be found in Problem #4 and #5.

*/

/* 100 pecent validated and correct:

  MinAge and toAge are declared in main() instead of inside the printing
  procedure so that if their values change, they only need to be modified
  in one place (main()). This makes the procedure reusable.

  If the values were declared inside the printing procedure and the age
  range later needed to change (for example to 21–65), the function itself
  would have to be modified. This reduces reusability.

  It would also violate the SRP (Single Responsibility Principle), since
  the printing procedure should only handle printing, not define the
  business rule for valid age ranges.

     */

     /* Tips: The nested functions line should be:

         PrintValidOrInvalidAge(readAge());

         becasue inside the printing procedure we call a boolean function inside an if statement (if this can be done, then this
         is how it SHOULD BE DONE (for enums, this rule does not apply = try to solve 'naturally' with enums))

         and this is why, one should NOT have a nested functions line such as:

         PrintValidOrInvalidAge(IsAgeValid(age));

         becasue the boolean function IsAgeValid() should be called inside the printing procedure (a standard pattern).
         and with this line, we could never achieve that.

         this standard pattern could be found in Problem #4 and #5.

     */





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// The INCORRECT  way of solving it: 
// 
// Where you have the following nested functions line:     PrintValidOrInvalidAge(IsAgeValid(age));
// 
//unsigned short ReadAge()
//{
//    unsigned short age; // what's returned.
//  
//    cout << "Enter age: ";
//    cin >> age;
//    cout << endl;
//
//    return age;
//}
//
//
//
//bool IsAgeValid(unsigned short age)  // pass by value.    // instead of returning a string "Valid" or "Invalid", I'll return a boolean. 
//{                                                          // This renders the function having broader use (more useful & not limited by returning string "valid" or "invalid"). 
//                                                           // For example, if it returns 'true', then I can later print "valid" or maybe something else ! instead of editing the function !!
//                                                           // , or have true or false as an argument of many many functions/ procedures..and much more.
//    return (age >= 18 && age <= 45);                                                               
//}
//
//void PrintValidOrInvalidAge(const bool& AgeValidity)  // pass by constant reference.
//{
//    if (IsAgeValid)
//    {
//        cout << "Valid age. \n";
//    }
//    else
//    {
//        cout << "Invalid age. \n";
//    }
//}
//
//int main()
//{
//    // initializing the below variable via reading user input (Using function) // since ONE variable is initialize:
//    unsigned short age = ReadAge();/*
//    |
//    |
//    |---------->   Only right at the end after typing the RETURN keyword in the implementing function */
//
//
//    PrintValidOrInvalidAge(IsAgeValid(age));
//
//    return 0;
//}





