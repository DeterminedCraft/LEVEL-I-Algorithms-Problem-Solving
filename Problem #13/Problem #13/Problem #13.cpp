

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



/* Solution:
   A- Declare 3 variables and initialize them via reading user input.
   B- Solve this problems using vectors.

*/



 //////A- using a procedure.

float ReadFloatNumber(const string& message)  // pass by constant ref.
{
    float number;  // what's returned

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}

bool ValidateNumber(const float &number, float min, float max) // pass by constant ref.  // ranges ALWAYS passed by value
{
    return (min <= number && number <= max);
}

void ReadNumber(const string& message, float min, float max, float& number) // pass by constant ref.  // ranges ALWAYS passed by value.  // number passed by ref. Otherwise, how can one initialize its declared value in main ?
{
    do
    {
        number = ReadFloatNumber(message); // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateNumber(number, min, max)); // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

    /* Note:
       The above block of code is to be sequentially composed line by line and
       at the end, implement the functions of:

       ReadFloatNumber()  &  ValidateNumber()
    
    
    
    */
}

void ReadNumbers(const string& message, float min, float max, float& Number1, float& Number2, float& Number3)  //  Number1, Number2, & Number3 passed by ref. (Otherwise, one won't be able to initialized their declaed values in main())
{
    ReadNumber(message, min, max, Number1);
    ReadNumber(message, min, max, Number2);
    ReadNumber(message, min, max, Number3);
}

float DetermineMaxNumber(const float& Number1, const float& Number2, const float& Number3)     // pass by constant reference
{
    float max = Number1; // declare 'max' variable and initialize it with the value of one of the numbers. // this approach minimizes the number of the subsequent if statements:

    if (Number2 > max)
    {
        max = Number2;
    }
    if (Number3 > max)
    {
        max = Number3;
    }

    return max;
}

void PrintMaxNumber(const float &Number1, const float &Number2, const float &Number3)   // pass by constant reference.
{
    cout << "The max number is: " << DetermineMaxNumber(Number1, Number2, Number3) << endl;
}



int main()
{
    float min = -1000000;   // flaot is declared as min & max will be compared to the float value the user enters (never compare different data types together as this invokes implicit conversion).
    float max = 1000000; 

    float Number1, Number2, Number3;
    // Initializing the above variables via reading user input (Using a procedure - since more than one variable is initialized):

    ReadNumbers("Enter number: ", min, max, Number1, Number2, Number3);
    // Number1, Number2, Number3 are now initialized.

    PrintMaxNumber(Number1, Number2, Number3);  // this line is composed so that, the printing procedure's implementation contains DetermineMaxNumber()
                                                // this is the standard thinking of going about these problems.
                                               // also, as a side effect, the printing procedure will have access/ can reference the 3 variables (Number1, Number2, & Number2) that the user entered.
    return 0;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////// B- using functions:



float ReadFloatNumber(const string& message)    // passing by constant ref.
{
    float number; //what's returned.

    cout << message;
    cin >> number;
    cout << endl;

    return number; 
}


bool ValidateNumber(const float& number, float min, float max)  // pass by constant ref.    // ranges ALWAYS passed by value.
{
    return (min <= number && number <= max);
}


float ReadNumber(const string& message, float min, float max)  // pass by constant reference.   // Ranges ALWAYS passed by value.
{
    float number; // what's returned   // declared outside the do statement so that it can be returned.

    do
    {
        number = ReadFloatNumber(message);  // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateNumber(number, min, max));  // the condition is written so that, it evaluates to TRUE  when the condition is INVALID.

    return number;

    /* Note: 
       The above block of code is to be sequentially composed line by line,
       and at the end - Implement the functions of:   readFloatNumber()  & ValidateNumber()
    
    */
}

float DetermineMaxNumber(const float& Number1, const float& Number2, const float& Number3) // pass by constant ref. since we're just comparing. & alone implies mutation
{
    float max = Number1; // declare max as a variable and initialize it with the value of one of the numbers. This approach minimizes the number of if statements-

    if (Number2 > max)
    {
        max = Number2;
    }
    if (Number3 > max)
    {
        max = Number3; 
    }

    return max;
}

void PrintMaxNumber(const float& Number1, const float& Number2, const float& Number3)    // pass by constant reference
{
    cout << "The maximum number is: " << DetermineMaxNumber(Number1, Number2, Number3) << endl;
}

int main()
{
    float min = -1000000;   // declaring as floats, as they'll be compared to the user entered float values.
    float max = 1000000; 


   // Initializing the below variable via reading user input (Using Function - since ONE value will be returned):
    float Number1 = ReadNumber("Enter number: ", min, max);
/*        |
          |---> type it at end, after typing the 'return' keyword.
*/

   // Initializing the below variable via reading user input (Using Function - since ONE value will be returned):
    float Number2 = ReadNumber("Enter number: ", min, max);
/*        |
          |---> type it at end, after typing the 'return' keyword.
*/

   // Initializing the below variable via reading user input (Using Function - since ONE value will be returned):
    float Number3 = ReadNumber("Enter number: ", min, max);
/*            |
              |---> type it at end, after typing the 'return' keyword.
*/

    PrintMaxNumber(Number1, Number2, Number3); // this line is written so that the implementation of the printing procedure contains DetermineMaxNumber() function
                                            // this is the standard way in programming.
                                           // and, separately, as a side effect - the printing procedure can reference Number1, Number2, & Number3 that the user entered because it has acess to them.

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



// B- Solving this example using vectors:
//    Nonetheless, this concept hasn't been yet introduced.
//    Hence, it'll be solved using an array (fixed-length data structure):


const unsigned short NumberOfArrayElements = 3;


float ReadFloatNumber(const string& message)    // pass by constant reference.
{
    float number; // what's returned.

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}

bool ValidateNumber(const float& number, float min, float max) // passing by constant reference.   // ranges ALWAYS passed by value.
{
    return (min <= number && number <= max);
}

void ReadNumbers(const string& message, float min, float max, float numbers[NumberOfArrayElements]) // array AUTOMATICALLY passed by ref. Including the & sign renders exception.
{
    for (int i = 0; i < NumberOfArrayElements; i++)
    {
        do
        {
            numbers[i] = ReadFloatNumber(message);  // 'numbers[i]' is to be IMMEDIATELY validated against the range, in the while condition.

        } while (!ValidateNumber(numbers[i], min, max)); // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

        // Note: The above lines are to be sequentially composed line by line
        // and at the end, implement the functions of: ReadFloatNumber()   & ValidateNumber()
    }
}

float DetermineMaxNumber(const float numbers[NumberOfArrayElements])    // passing by constant ref.   Including the & sign, will render exception
{
    float max = numbers[0];   // declare the variable 'max' and initialized it with the value of any element in the array.  This approach reduces the number of the if statements (makes it simpler !).

    if (numbers[1] > max)
    {
        max = numbers[1];
    }
    if (numbers[2] > max)
    {
        max = numbers[2];
    }

    return max;
}

void PrintMaxNumber(const float numbers[NumberOfArrayElements])   
{
    cout << "The maximum number is: " << DetermineMaxNumber(numbers) << endl;
}


int main()
{
    float min = -1000000;
    float max =  1000000;

    float numbers[NumberOfArrayElements];
    // Initializing the above array variable via reading user input (Using Procedure - since an array contains more than one value):

    ReadNumbers("Enter number: ", min, max, numbers); // the array variable 'numbers' is the argument that is, by default, sent along with its memory in address to the implementing procedure.
                                                     // Therefore, it's always passed by ref without the & sign.

    // the variable array 'numbers' is now initialized.

    PrintMaxNumber(numbers); // the array variable 'numbers' is the argument that is, by default, sent along with its memory in address to the implementing procedure.
                                  // this line is written so that the implementation of the printing procedure contains DetermineMaxNumber() function
                                  // this is the standard way in programming.
                                  // and, separately, as a side effect - the printing procedure can reference the array variable 'numbers' that was initialized by the user.
     

    return 0;
}





//////////////////////////////////////////////////////////////////BELOW: OLD UNOPTIMIZTED SOLUTIONS//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//void ReadNumber(float& Num1, float& Num2, float& Num3) // pass by reference
//{
//    cout << "Enter first number: ";
//    cin >> Num1;
//    cout << endl;
//
//    cout << "Enter second number: ";
//    cin >> Num2;
//    cout << endl;
//
//    cout << "Enter third number: ";
//    cin >> Num3;
//    cout << endl;
//}
//
//float DetermineMaxNumber(const float& Num1, const float& Num2, const float& Num3) // passing by const ref. (since we're just comparing). & alone implies mutation. Hence the 'const'.
//{
//    float max = Num1; // assign the value of any of Num1 or Num2 or Num3 to a variable named max [conducive to only having 2 comparisons instead of 3].
//
//    if (Num2 > max)
//    {
//        max = Num2;
//    }
//    if (Num3 > max)
//    {
//        max = Num3;
//    }
//
//    return max;
//
//}  
//
//
//void PrintMaxNumber(const float& MaxNum) // pass by constant ref.
//{
//    cout << "The MAXIMUM number is " << MaxNum << endl;
//}
//
//int main()
//{
//    float Num1, Num2, Num3;
//    // Initializing via reading user input
//    ReadNumber(Num1, Num2, Num3);
//
//    // the 3 variables are now initialized.
//
//    PrintMaxNumber(DetermineMaxNumber(Num1, Num2, Num3));
//
//    return 0;
//}
//
//
//
//
//
//
//// Initial solution: using 3 comparisons (not optimized)
//
//void ReadNumber(float& Num1, float& Num2, float& Num3) // pass by reference
//{
//    cout << "Enter first number: ";
//    cin >> Num1;
//    cout << endl;
//
//    cout << "Enter second number: ";
//    cin >> Num2;
//    cout << endl;
//
//    cout << "Enter third number: ";
//    cin >> Num3;
//    cout << endl;
//}
//
//float DetermineMaxNumber(const float& Num1, const float& Num2, const float& Num3) // passing by const ref. (since we're just comparing). & alone implies mutation. Hence the 'const'.
//{
//    if (Num1 > Num2)
//    {
//        if (Num1 > Num3)
//        {
//            return Num1;
//        }
//        else
//        {
//            return Num3;
//        }
//    }
//    else
//    {
//        if (Num2 > Num3)
//        {
//            return Num2;
//        }
//        else
//        {
//            return Num3;
//        }
//    }
//}
//
//
//void PrintMaxNumber(const float& MaxNum) // pass by constant ref.
//{
//    cout << "The MAXIMUM number is " << MaxNum << endl;
//}
//
//int main()
//{
//    float Num1, Num2, Num3;
//    // Initializing via reading user input
//    ReadNumber(Num1, Num2, Num3);
//
//    // the 3 variables are now initialized.
//
//    PrintMaxNumber(DetermineMaxNumber(Num1, Num2, Num3));
//
//	return 0;
//}
//
//
