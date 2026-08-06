
#include <iostream>
using namespace std;

/*
 Problem #27:

 Write a program to print numbers from N to 1.

 Input
 10

 Outputs →
 10
 9
 8
 7
 6
 5
 4
 3
 2
 1

 */





int ReadIntegerNumber(const string& message)    // pass by constant reference.
{
    int number;   // what's returned

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}

bool ValidateNRange(const int& n)   // pass by constant reference since n is used for comparison only.
{
    return (n > 0); 
}

int ReadN(const string& message)  // pass by constant reference.
{
    int n; // what's returned.   // declared outside the do statement so that it can be retrurned by the function

    do
    {
        n = ReadIntegerNumber(message);  // 'N' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateNRange(n)); // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

    return n;

    // Note: The above block of code is to be sequentially
    //       composed line by line, 
    //       and at the end implement
    //       the functions of: ReadIntegerNumber & ValidateNRange
   }



void PrintNumbersFromNto1_UsingForLoops(const int& n)   // pass by constant reference.
{
    cout << "Solving this problem using For-Loops: \n";


    for (int i = n; i >= 1; i--)    // using for-loops is the best solution since the number of iterations is known before hand.
    {
        cout << i << endl;
    }

    cout << "\n";
}




void PrintNumbersFromNto1_UsingWhileLoops(const int& n)   // pass by constant reference.
{
    cout << "Solving this problem using While-Loops: \n";

     
    int i = n;       // 1st line to compose
    while (i >= 1)  // 2nd line to compose
    {
        cout << i << endl;  // The LAST line to compose.

        i--;  // 3rd line to compose.
    }
    cout << "\n";
}



void PrintNumbersFromNto1_UsingDoWhileLoops(const int& n)    // pass by constant reference.
{
    cout << "Solving this problem using Do..While Loops: \n";


    int i = n;        //1st line to compose 
    do
    {
        cout << i << endl;  // The LAST line to compose.
       
        i--;        // 2nd line to compose

    } while (i >= 1);   // 3rd line to compose.

    cout << "\n";
}

int main()
{
    int n = ReadN("Enter a positive number: ");  // range NOT included as its value is NOT intrinsic.
/*      |
        |---> to be typed at the end, after finishing typing the "return" keyword.*/

    PrintNumbersFromNto1_UsingForLoops(n); 
    PrintNumbersFromNto1_UsingWhileLoops(n);
    PrintNumbersFromNto1_UsingDoWhileLoops(n);

                                                  

    return 0;
}



/* READ& UNDERSTAND line by line :

 A:
============================================================
🔼 Mo3alem's
============================================================  */

void PrintRangeFromNto1_UsingWhile(int N)
{
    int Counter = N + 1;

    cout << "Range printed using While Statement:\n";

    while (Counter > 1)
    {
        Counter--;
        cout << Counter << endl;
    }
}
/*
------------------------------------------------------------
🔍 Key Idea:
- Starts from N + 1
- Decrements BEFORE printing
- Condition: Counter > 1
→ Output: N → 1

============================================================
🔽 My Style
============================================================   */

void PrintRangeFromNTo1(const int& number)
{
    int i = number;   // Start directly from N

    while (i >= 1)   // Loop until reaching 1
    {
        cout << i << endl;
        i--;   // Decrement AFTER printing
    }
}

/*
------------------------------------------------------------
🔍 Key Differences (Important Mental Model):

1) Initialization:
   - Image: Counter = N + 1 → decrement first
   - Yours:  i = number → print directly

2) Loop Condition:
   - Image: Counter > 1
   - Yours: i >= 1

3) Order of Operations:
   - Image:
        Counter--
        print
   - Yours:
        print
        i--

👉 Both produce IDENTICAL output, just different logic flow.

============================================================
*/

/*
*
*
*
*
* B:
============================================================
🔼 Mo3alem's
============================================================ */

void PrintRangeFromNto1_UsingDoWhile(int N)
{
    int Counter = N + 1;

    cout << "Range printed using Do..While Statement:\n";

    do
    {
        Counter--;
        cout << Counter << endl;

    } while (Counter > 1);
}

/*
------------------------------------------------------------
🔍 Key Idea:
- Starts from N + 1
- Decrements BEFORE printing
- Condition checked AFTER execution
→ Output: N → 1
→ Guarantees at least ONE iteration

============================================================
🔽  My version:
============================================================ */

void PrintRangeFromNTo1(const int& number)
{
    int i = number;   // Start directly from N

    do
    {
        cout << i << endl;
        i--;   // Decrement AFTER printing

    } while (i >= 1);
}

/*
------------------------------------------------------------
🔍 Key Differences (Important Mental Model):

1) Initialization:
   - Mo3alem's : Counter = N + 1 → decrement first
   - Yours:  i = number → print directly

2) Loop Condition:
   - Mo3alem's: Counter > 1
   - Yours: i >= 1

3) Order of Operations:
   - Mo3alem's:
        Counter--
        print
   - Yours:
        print
        i--

4) Do-While Behavior:
   ✔ Always executes at least once

👉 Both implementations produce IDENTICAL output for valid inputs.


============================================================
*/







/////////////////////////////////// Below: Some OLD UNOPTIMIZED solutions //////////////////////////
/////////////////////////////////// Below: Some OLD UNOPTIMIZED solutions //////////////////////////
/////////////////////////////////// Below: Some OLD UNOPTIMIZED solutions //////////////////////////



int ReadInteger()
{
    int number; // what's returned.

    cout << "Enter a positive integer: ";
    cin >> number;
    cout << endl;

    return number;
}

bool ValidatePositiveInteger(int number) // passing by value.
{
    return (number > 0);
}

int ReadPositiveInteger()
{
    int number;
    do
    {
        number = ReadInteger(); // 'number' to be IMMEDIATELY validated against the range in the condition of the while.

    } while (!ValidatePositiveInteger(number)); // the argument is written so that it evaluates to TRUE when the condition is invalid (hence, the !)

    return number;
    // Note: write the ENTIRE above structure line by line. At the end, implement the two functions
}


void  PrintNumbersFromNTo1(const int &number)    // passing by constant reference
{
    for (int i = number; i >= 1; i--)    // using for-loops is the best solution since the number of iterations is known before hand.
    {
        cout << i << endl;
    }

}

//// or:
//void PrintNumbersFromNTo1(const int &number)
//{
//    int i = number;   //1st step to write
//    while (i >= 1)   // 2nd step to write
//    {
//        cout << i << endl;
//        i--;            // 3rd step to write
//    }
//}

//// or:
//void PrintNumbersFromNTo1(const int &number)
//{
//    int i = number;
//    do
//    {
//        cout << i << endl;
//        i--;   
//
//    } while (i >= 1);
//
//}

int main()
{
    
    PrintNumbersFromNTo1(ReadPositiveInteger());

    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Or a solution showcasing the use of the three different loops types: For-Loos, The While-Loop, & the Do..While-Loop:

int ReadInteger()
{
    int number; // what's returned.

    cout << "Enter a positive integer: ";
    cin >> number;
    cout << endl;

    return number;
}

bool ValidatePositiveInteger(int number) // passing by value.
{
    return (number > 0);
}

int ReadPositiveInteger()
{
    int number;
    do
    {
        number = ReadInteger(); // 'number' to be IMMEDIATELY validated against the range in the condition of the while.

    } while (!ValidatePositiveInteger(number)); // the argument is written so that it evaluates to TRUE when the condition is invalid (hence, the !)

    return number;
    // Note: write the ENTIRE above structure line by line. At the end, implement the two functions
}


void  PrintFromNto1_UsingForLoops(const int& number)    // passing by constant reference
{
    cout << "Solving utilizing the for-loops (Best solution as the number of iterations is known beforehand): \n";

    for (int i = number; i >= 1; i--)    // using for-loops is the best solution since the number of iterations is known before hand.
    {
        cout << i << endl;
    }

    cout << "\n";
}


void PrintFromNto1_UsingWhileLoop(const int &number)
{
    cout << "Solving utilizing the While-Loop: \n";

    int i = number;   //1st step to write
    while (i >= 1)   // 2nd step to write
    {
        cout << i << endl;
        i--;            // 3rd step to write
    }

    cout << "\n";
}


void PrintFromNto1_UsingDoWhileLoop(const int &number)
{
    cout << "Solving utilizing the DO..While Loop: \n";

    int i = number;
    do
    {
        cout << i << endl;
        i--;   

    } while (i >= 1);

}


int main()
{
    int N = ReadPositiveInteger();

    PrintFromNto1_UsingForLoops(N);
    PrintFromNto1_UsingWhileLoop(N);
    PrintFromNto1_UsingDoWhileLoop(N);

    return 0;
}



















