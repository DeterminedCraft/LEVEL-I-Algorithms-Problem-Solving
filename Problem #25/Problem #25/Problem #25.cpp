
 #include <iostream>
 using namespace std;

/*
 Problem #25:
==============================================================

 Write a program to ask the user to enter:

 • Age

 If age is between 18 and 45 print "Valid Age".

 otherwise print "Invalid Age" and re-ask user to enter a valid age.

 Note: You should keep asking user to enter a valid age until
 s/she enters it.

==============================================================



*/


 // Solution A: Solving it with the CORRECT OPTMIZED way (= still the final solution that will be presented in C++ level II course).
 // Solution B: Solving it with the usual UNoptimized way.
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 


 //Solution A: (The optimized solution - But NOT the final one (the final solution that will be presented in C++ level II course).

 unsigned short ReadAge(unsigned short MinAge, unsigned short MaxAge)
 {
     unsigned short age;  // what's returned
     do         // 👈 👈 The code inside the "do" statement + the "what's returned" line:  are to be wrapped in a function (shown in the optimized version)
     {
         cout << "Enter Age: ";
         cin >> age;   // to be IMMEDIATELY validated in the condition against the range
         cout << endl;

     } while (age >= MinAge && age <= MaxAge); // written so that- condition evaluates to TRUE when the condition is INVALID.
                                             // 👈 👈 The argument of while is to be wrapped in a function.  (shown in the optimized version)

     return age;
 }


 void PrintAgeValidity(const unsigned short &age) // passing by constant reference.
 {
     cout << "Valid age \n";  // if the program reaches here, then the entered number is between 18 and 45. very simple = no need for comlications.
 }


 int main()
 {
     unsigned short MinAge = 18;
     unsigned short MaxAge = 45,
     PrintAgeValidity(ReadAge(MinAge, MaxAge));

     // CRUCIAL: remember (from the do..while()) mental model:
     // The UNIVERSAL INPUT UTILITIES were: 
     // ReadPositiveInt(), ReadNegativeInt, ReadIntBiggerThanOrEqualZero, ReadIntLessThanOrEqualZero, ReadPositiveIntInRange, ReadNegativeIntInRange, ReadIntWithRestriction
     // ReadPositiveFloat, etc ( = and repeat the cycle).
     //
     // Nonetheless, 
     // In this example- I used ReadAge() 
     // and not for example, ReadUnsignedIntLessThanSomeValue
     //
     // The reason is that- ReadAge() function, will contain cout << "Enter age: "
     // whereas, a universal utility such as anyone of the aforementioned above,
     // can ONLY contain a general (since it's a utility): cout statement such as : cout << "Enter a number: " or "Enter a positive number" etc.
     // 
     // attempting to modify one of these utilities' cout line to "Enter age" is a bad practice
     // as utilities are to be multi-purpose/ general. Hence, should never be modified to accomodate a program, for common-sence reasons.


     return 0;
 }
 // The do.. while() statement is the optimized & CORRECT way of handling these problems. 
 //     It's give precedence over while() loops even if it does not exactly match the desired output.
 // 
// Nonetheless, if the instructor INSISTS on an output identical to exactly what he asked for, 
// 
// then utilize the UNOPTIMIZED approach of the while statement which replicates the lines of code.
// here it is: (Simply add it above instead of the do..while() loop WITHOUT changing anything else in the program).

/*
    unsigned short ReadAge(unsigned short MinAge, unsigned short MaxAge) // pass by value.
 {
     unsigned short age; // what's returned

     cout << "Enter age: (Must be between " << MinAge << " & " << MaxAge << "): ";
     cin >> age;  // this is IMMEDIATELY validated.
     cout << endl;

     while (age < MinAge || age > MaxAge)
     {
         cout << "Invalid age. \n";

         cout << "Enter age: (Must be between " << MinAge << " & " << MaxAge << "): ";
         cin >> age;  // this is IMMEDIATELY validated.
         cout << endl;
     }

     return age;
 }

}
*/
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
  //Solution B: (The VERY UNOPTIMIZED version of the ABOVE , which is in turn, NOT final solution). 
  // Hint: Notice how the [MaxInputValue] variable introduces redundancy + complexity, instead of simply using the min & max age range

 unsigned short ReadAge(unsigned short MaxInputValue)
 {
     unsigned short age;  // what's returned
     do
     {
         cout << "Enter Age: ";
         cin >> age;   // to be IMMEDIATELY validated in the condition against the range
         cout << endl;

     } while (age > MaxInputValue); // written so that- condition evaluates to TRUE when the condition is INVALID.

     return age;
 }

 
 bool IsAgeValid(unsigned short age)  // passing by value.
 {
     return (age >= 18 && age <= 45);
 }

 void PrintAgeValidity(const unsigned short &age) // passing by constant reference.
 {
     if(IsAgeValid(age))
     {
         cout << "Valid age \n";
     }
     else
     {
         cout << "Age Invalid \n";
         ReadAge(age);
     }
 }

 int main()
 {
     unsigned short MaxInputValue = 150; // wrote it later when I needed it
     PrintAgeValidity(ReadAge(MaxInputValue));

     return 0;
 }












