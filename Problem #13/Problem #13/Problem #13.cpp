

#include <iostream>
using namespace std;

/* Problem #13
===========================================================
 Problem:
 Write a program to ask the user to enter 3 numbers:

    A
    B
    C

 Then print the maximum number.

 Example Inputs:
    30
    10
    20

 Output:
    30
===========================================================
*/




#include <iostream>
using namespace std;

/* Problem #13
===========================================================
 Problem:
 Write a program to ask the user to enter 3 numbers:

    A
    B
    C

 Then print the maximum number.

 Example Inputs:
    30
    10
    20

 Output:
    30
===========================================================
*/



void ReadNumber(float& Num1, float& Num2, float& Num3) // pass by reference
{
    cout << "Enter first number: ";
    cin >> Num1;
    cout << endl;

    cout << "Enter second number: ";
    cin >> Num2;
    cout << endl;

    cout << "Enter third number: ";
    cin >> Num3;
    cout << endl;
}

float DetermineMaxNumber(const float& Num1, const float& Num2, const float& Num3) // passing by const ref. (since we're just comparing). & alone implies mutation. Hence the 'const'.
{
    float max = Num1; // assign the value of any of Num1 or Num2 or Num3 to a variable named max [conducive to only having 2 comparisons instead of 3].

    if (Num2 > max)
    {
        max = Num2;
    }
    if (Num3 > max)
    {
        max = Num3;
    }

    return max;

}  


void PrintMaxNumber(const float& MaxNum) // pass by constant ref.
{
    cout << "The MAXIMUM number is " << MaxNum << endl;
}

int main()
{
    float Num1, Num2, Num3;
    // Initializing via reading user input
    ReadNumber(Num1, Num2, Num3);

    // the 3 variables are now initialized.

    PrintMaxNumber(DetermineMaxNumber(Num1, Num2, Num3));

    return 0;
}






// Initial solution: using 3 comparisons (not optimized)

void ReadNumber(float& Num1, float& Num2, float& Num3) // pass by reference
{
    cout << "Enter first number: ";
    cin >> Num1;
    cout << endl;

    cout << "Enter second number: ";
    cin >> Num2;
    cout << endl;

    cout << "Enter third number: ";
    cin >> Num3;
    cout << endl;
}

float DetermineMaxNumber(const float& Num1, const float& Num2, const float& Num3) // passing by const ref. (since we're just comparing). & alone implies mutation. Hence the 'const'.
{
    if (Num1 > Num2)
    {
        if (Num1 > Num3)
        {
            return Num1;
        }
        else
        {
            return Num3;
        }
    }
    else
    {
        if (Num2 > Num3)
        {
            return Num2;
        }
        else
        {
            return Num3;
        }
    }
}


void PrintMaxNumber(const float& MaxNum) // pass by constant ref.
{
    cout << "The MAXIMUM number is " << MaxNum << endl;
}

int main()
{
    float Num1, Num2, Num3;
    // Initializing via reading user input
    ReadNumber(Num1, Num2, Num3);

    // the 3 variables are now initialized.

    PrintMaxNumber(DetermineMaxNumber(Num1, Num2, Num3));

	return 0;
}


