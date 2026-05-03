
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

bool ValidateNumberInRange(unsigned short age, unsigned short from, unsigned short to)
{
    return (age >= from && age <= to);
}

unsigned short ReadAge(unsigned short from, unsigned short to)
{
    unsigned short age; // what's returned.

    cout << "Enter Age between " << from << " & " << to << endl;
    cin >> age;
    cout << endl;

    return age;
}


unsigned short ReadUntilAgeInRange(unsigned short from, unsigned short to)
{
    unsigned short age = 0;   // ensure you initialize it to 0 

    do
    {
        age = ReadAge(from, to); // age is IMMEDITELY validated in the condition against the range.

    } while (!ValidateNumberInRange(age, from, to)); //why the !: cuz originally, the argument is written so that it evaluates to TRUE when the condition is INVALID  //while (age < from || age > to),  

    return age;
    // hint: write the entire lines of this function. Later start implementing:   ReadAge()  &  ValidateNumberInRange()
}

void PrintAgeValidity(const unsigned short& age)  // passing by constant reference.
{
    cout << "Age is Valid ! \n";     // If the program reaches here, then the user must've entered a value between 18 and 45.
}

int main()
{

    unsigned short from = 18;
    unsigned short to = 45;

    PrintAgeValidity(ReadUntilAgeInRange(from, to));

    return 0;
}


// Insights:
// re-asking the user (in this sepcific case, to enter a valid age) implies a do..while() statement.









