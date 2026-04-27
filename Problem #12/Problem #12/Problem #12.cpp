
#include <iostream>
using namespace std;


/*
 Problem #12:

 Write a program to ask the user to enter:
 • Number1, Number2

 Then print the Max Number.

 Example Inputs:
 10
 20

 Output:
 20
*/


void ReadNumbers(float &Number1, float &Number2) // passing by reference
{
    cout << "Enter first number: ";
    cin >> Number1;
    cout << endl;

    cout << "Enter second number: ";
    cin >> Number2;
    cout << endl;
}


float DetermineMaxNumber(const float& Number1, const float& Number2) // pass by constant reference.
{
    if (Number1 > Number2)
    {
        return Number1;
    }
    else 
    {
        return Number2;
    }
    
}

void PrintMaxNumber(const float &MaxNumber)   // pass by constant reference.
{
        cout << MaxNumber << " is bigger" << endl;  
}

int main()
{
    float Number1, Number2;
    // Intitializing via reading user input:

    ReadNumbers(Number1, Number2);
    // Number1 & Number2 are now initialized.

    PrintMaxNumber(DetermineMaxNumber(Number1, Number2)); // the argument has to be a function. As procedures return void.

    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



// or if you want:

float ReadFirstNumber()
{
    float number; // what's returned.

    cout << "Enter the first number: ";
    cin >> number;
    cout << endl;

    return number;
}

float ReadSecondNumber()
{
    float number; // what's returned.

    cout << "Enter the second number: ";
    cin >> number;
    cout << endl;

    return number;
}


float DetermineMaxNumber(const float& Num1, const float& Num2) // pass by const. ref.
{
    if (Num1 > Num2)
    {
        return Num1;
    }
    else
    {
        return Num2;
    }
}

void PrintMaxNumber(const float& MaxNumber) // pass by const ref.
{
    cout << MaxNumber << " is the biggest number" << endl;
}

int main()
{
    //Initializing the below variable via reading user input:
    float Num1 = ReadFirstNumber(); /*
    |
    |------->The last thing to type.Type after writing "return" keyword in the implementing function. */

    // Initializing the below variable via reading user input:
    float Num2 = ReadSecondNumber();/*
    |
    |------->The last thing to type.Type after writing "return" keyword in the implementing function. */

    PrintMaxNumber(DetermineMaxNumber(Num1, Num2)); // the argument HAS to be a function as procedures return void, which in this specific it'd throw an exception.

    return 0; 
}