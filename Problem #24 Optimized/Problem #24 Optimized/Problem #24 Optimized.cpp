
#include <iostream>
using namespace std;

// This is A MORE OPTIMIZED version that the previous problem #24.
// 
// But still, NOT the final solution as of now (There might be a room for improvement)
// 
// This will be cleared up in C++ Level II where utilities will be built.



unsigned short ReadAge(unsigned short MaxNumberValue)
{
    unsigned short age;   // what's returned.

    do
    {

        cout << "Enter Age: \n";
        cin >> age; // to be IMMEDIATELY range validated.

    } while (age > MaxNumberValue);   // 👈 argument written so that it evaluates to TRUE when the condition is INVALID
    // no need to include a positive number check as, unsigned short has a positive range.
    return age;
}


bool ValidateNumberInRange(unsigned short number, unsigned short from, unsigned short to) // passing by value
{
    return (number >= from && number <= to);
}

void PrintAgeValidity(const unsigned short& age, unsigned short from, unsigned short to) // passing by constant reference.
{
    if (ValidateNumberInRange(age, from, to))  //instead of IsAgeValid() ... change the name so that it accomodates a UNIVERSAL BOOLEAN UTILITY: ValidateNumberInRange() (applies to the argument(s) too)
    {
        cout << "Valid Age \n";
    }
    else
    {
        cout << "INVALID age \n";
    }
}

int main()
{
    unsigned short MaxNumberValue = 140;  // I wrote them all when I needed them later in the program.
    unsigned short from = 18;
    unsigned short to = 45;

    PrintAgeValidity(ReadAge(MaxNumberValue), from, to);

    return 0;
}


/*  TO improve on the below notes later: 
  
   Based on this solution, it is concluded that there are 
   two types of UNIVERSAL UTILITIES:

   - UNIVERSAL INPUT UTILITIES (Elaborated on in the do..while mental model of the C++ course)
   - UNIVERSAL BOOLEAN UTILITIES: 
        Ex: called as an argument of the if-statement inside the printing procedure.



*/