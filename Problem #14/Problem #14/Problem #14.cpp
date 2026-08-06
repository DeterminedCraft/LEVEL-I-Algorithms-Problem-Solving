
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

float ReadFloatNumber(const string& message)   // pass by constant reference.
{
    float number; // what's returned

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}

bool ValidateNumber(const float& number, float min, float max)   // passing by constant ref. since w're just comparing    // ranges ALWAYS passed by value
{
    return (min <= number && number <= max);
}


void ReadNumber(const string& message, float min, float max, float& number) // pass by constant ref.  // ranges ALWAYS passed by value  // Number1 & Number2 passed by ref. (otherwise, how can one initialize these declared variables in main ?)
{
    do
    {
        number = ReadFloatNumber(message);  // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateNumber(number, min, max));  //  the argument is written so that, it evaluates to TRUE when the condition is INVALID.

    /* Note: The above block of code is to be aequentially composed line by line
             and at the end, implement the functions of:
             ReadFloatNumber()   &   ValidateNumber()
    */
}

void ReadTwoNumbers(const string& message, float min, float max, float& Number1, float& Number2) // pass by constant ref.  // ranges ALWAYS passed by value  // Number1 & Number2 passed by ref. (otherwise, how can one initialize these declared variables in main ?)
{
    ReadNumber(message, min,max,Number1);
    ReadNumber(message, min, max, Number2);
}

void PrintTwoNumbers(const float& Number1, const float& Number2)   // pass by constant reference.
{
    cout << "The first entered number is: " << Number1 << "\n";
    cout << "The second entered number is: " << Number2 << "\n \n";
}

void SwapTwoNumbers(float& Number1, float& Number2)      // it means you swap then inside main()
{
    float temp;

    temp = Number1;
    Number1 = Number2; 
    Number2 = temp;
}


int main()
{
    
    float Number1, Number2;
    // initializing the above variables via reading user input (Using a procedure - since MORE than one variable is initialized):

    float min = -1000000; // declared as floats, as they will be compared to each float value entered by the user for range validation.
    float max = 1000000;

    ReadTwoNumbers(" Enter number: ", min, max, Number1, Number2);
    // Number1 & Number2 are now initialized.

    PrintTwoNumbers(Number1, Number2);

    SwapTwoNumbers(Number1, Number2);
    cout << "-----The two numbers inside main have been swapped !" << endl << endl;

    PrintTwoNumbers(Number1, Number2);



    return 0;
}








//////////////////////////////// Some old unoptimizted solution: ///////////////////////////////////////
//////////////////////////////// Some old unoptimizted solution: ///////////////////////////////////////
//////////////////////////////// Some old unoptimizted solution: ///////////////////////////////////////


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


