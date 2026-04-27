
#include <iostream>
using namespace std;

/*
 Problem #33:

 Write a program to ask the user to enter:
 - Grade

 Then print the grade as follows:
 - 90 - 100 → Print A
 - 80 - 89  → Print B
 - 70 - 79  → Print C
 - 60 - 69  → Print D
 - 50 - 59  → Print E
 - Otherwise → Print F

 Example Inputs:
 95

 Outputs:
 A

*/

unsigned short ReadNumber(string message) // passing by value.
{
    unsigned short number; // what's returned

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}

bool ValidateIntegerInRange(const unsigned short& number, const unsigned short& min, const unsigned short& max) // passing by constant reference.
{
    return (min <= number && number <= max);
}


int ReadIntegerInRange(const unsigned short& min, const unsigned short& max, const string& message) // pass by constant ref.
{
    int number; // what's returned
    do
    {
        number = ReadNumber(message); // 'number' is to be IMMEDIATELY validated against the range in the while condition.

    } while (!ValidateIntegerInRange(number, min, max)); // the argument should be written so that it evaluates to TRUE when the condition is invalid (Hence the ! sign)

    return number;

    // Note: the above block is to be literally written line by line
    // where at the end, we implement the functions of: ReadNumber() & ValidateIntegerInRange()
}

string CalculateGrade(unsigned short number) // passing by value
{
    if (number >= 90)
    {
        return "A";
    }
    else if (number >= 80)
    {
        return "B";
    }
    else if (number >= 70)
    {
        return "C";
    }
    else if (number >= 60)
    {
        return "D";
    }
    else if (number >= 50)
    {
        return "E";
    }
    else
    {
        return "F";
    }
}

/*
void PrintGrade(const string &grade) // passing by constant reference.
{
    cout << "The grade is: " << grade << endl;
}
*/

int main()
{
    unsigned short min = 0;
    unsigned short max = 100;

    // PrintGrade(CalculateGrade(ReadIntegerInRange(min, max, "Enter a grade [Between 0 & 100]"))); // commented out- no need to a printing procedure as we're only printing one line instead of a structure.

    cout << "The grade is: " << CalculateGrade(ReadIntegerInRange(min, max, "Enter an integer between 0 and 100: ")) << endl;


    return 0;
}






// this is the first attempt: Not good as unsigned short variable can only store positive numebrs to start with. so if the user enters a negative number
// then, 👉 It gets converted to a large positive number (overflow behavior).
// the fix: Just use integer as illustrated in the correct solution above.

//unsigned short ReadNumber(string message) // passing by value.
//{
//    unsigned short number; // what's returned
//
//    cout << message;
//    cin >> number;
//    cout << endl;
//
//    return number;
//}
//
//bool ValidateIntegerInRange(const unsigned short& number, const unsigned short& min, const unsigned short& max) // passing by constant reference.
//{
//    return (min <= number && number <= max);
//}
//
//
//unsigned short ReadIntegerInRange(const unsigned short &min, const unsigned short &max, const string &message) // pass by constant ref.
//{
//    unsigned short number; // what's returned
//    do
//    {
//        number = ReadNumber(message); // 'number' is to be IMMEDIATELY validated against the range in the while condition.
//
//    } while (!ValidateIntegerInRange(number, min, max)); // the argument should be written so that it evaluates to TRUE when the condition is invalid (Hence the ! sign)
//
//    return number;
//
//    // Note: the above block is to be literally written line by line
//    // where at the end, we implement the functions of: ReadNumber() & ValidateIntegerInRange()
//}
//
//string CalculateGrade(unsigned short number) // passing by value
//{
//    if (number >= 90)
//    {
//        return "A";
//    }
//    else if (number >= 80)
//    {
//        return "B";
//    }
//    else if (number >= 70)
//    {
//        return "C";
//    }
//    else if (number >= 60)
//    {
//        return "D";
//    }
//    else if (number >= 50)
//    {
//        return "E";
//    }
//    else
//    {
//        return "F";
//    }
//}
//
///*       
//void PrintGrade(const string &grade) // passing by constant reference.
//{
//    cout << "The grade is: " << grade << endl;
//}
//*/
//
//int main()
//{
//    unsigned short min = 0;
//    unsigned short max = 100;   
//
//  // PrintGrade(CalculateGrade(ReadIntegerInRange(min, max, "Enter a grade [Between 0 & 100]"))); // commented out- no need to a printing procedure as we're only printing one line instead of a structure.
//
//    cout << "The grade is: " << CalculateGrade(ReadIntegerInRange(min, max, "Enter an integer between 0 and 100: ")) << endl;
//
//
//    return 0;
//}

