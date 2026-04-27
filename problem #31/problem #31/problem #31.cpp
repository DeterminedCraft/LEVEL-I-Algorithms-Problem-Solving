
#include <iostream>
#include <cmath>
using namespace std;

/* Problem #31:

 Write a program to ask the user to enter:
 - Number

 Then print: Number^2, Number^3, Number^4

 Example Inputs:
 3

 Outputs:
 9
 27
 81


*/


int ReadNumber()
{
    int number; // what's returned.

    cout << "Enter a positive integer: ";
    cin >> number;
    cout << endl;

    return number;
}

bool ValidatePositiveInteger(int number) // passing by value
{
    return (number > 0);
}

int ReadPositiveInteger()
{
    int number; // what's returned.
    do
    {
        number = ReadNumber();  // 'number' to be IMMEDIATELY validated in the condition against the range.
        
    } while (!ValidatePositiveInteger(number));  // 👈 👈 argument is written so that, it evaluates to TRUE when the condition is INVALID (hence the ! sign).

    return number;

    //Note: ALL of the above is written line-by-line. at the end, implement the two functions that are: ReadNumber() & ValidatePositiveInteger()
}


double CalculatePowerOf_2_3_4(int number, int i) // pass by value   // returns double ad the value of  number^power can get large VERY QUICKLY
{
    return pow(number, i);
}

void  PrintPowerOf_2_3_4(int number) // passing by value
{
    for (int i = 2; i <= 4; i++)
    {
        cout << "The power of " << i << " is: " << CalculatePowerOf_2_3_4(number, i) << endl;

        // cout << "The power of " << i << " is: " << pow(number, i) << endl;  // Divide and conquer /فرّق تسد     even if it's:   pow(number, i) , ALWAYS wrap it in a function.     
    }
}




int main()
{
    

    PrintPowerOf_2_3_4((ReadPositiveInteger()));
   
    return 0;
}


