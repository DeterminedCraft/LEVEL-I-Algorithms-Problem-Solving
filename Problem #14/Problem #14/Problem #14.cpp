
#include <iostream>
using namespace std;

/*
===========================================================
Problem #14:

 Write a program to ask the user to enter:

    Number1
    Number2

 Then print the two numbers, then swap the two numbers
 and print them again.

 Example Inputs:
    10
    20

 Outputs:
    10
    20

    20
    10
===========================================================
*/



void ReadNumbers(float& Num1, float& Num2)  // passing by ref.
{
    cout << "Enter the first number: ";
    cin >> Num1;
    cout << endl;

    cout << "Enter the second number: ";
    cin >> Num2;
    cout << endl;
}

void PrintNumbers(const float &Num1, const float &Num2) // pass by constant ref.
{
    cout << "The first entered number: " << Num1 << endl;
    cout << "The second entered number: " << Num2 << endl;
    cout << "--------------------------\n";
}


void SwapNumbers(float &Num1, float &Num2)
{
    float temp;

    temp = Num1;
    Num1 = Num2;
    Num2 = temp;

}

int main()
{
    float Num1, Num2;
    // Initializing via reading user input:
    ReadNumbers(Num1, Num2);
    // Num1 & Num2 are now initialized.

    PrintNumbers(Num1, Num2);
    SwapNumbers(Num1, Num2); // SWAP the two numbers in main ! // HAS to be a procedure as we're SWAPPING two numbers and not returning one value.
    // Now,  Num1 & Num2  values IN MAIN() are reversed.
    PrintNumbers(Num1, Num2);
    

    return 0;
}


