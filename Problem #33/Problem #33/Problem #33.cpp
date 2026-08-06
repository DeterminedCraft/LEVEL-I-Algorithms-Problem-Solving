
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

short ReadShortNumber(const string& message)   // pass by constant reference
{
	short number; // what's returned.

	cout << message;
	cin >> number;
	cout << "\n";

	return number;
}


bool ValidateGradeRange(const short& grade, short min, short max)  // pass by constant ref. since grade is only used for comparison against ranges.   // ranges ALWAYS passed by value
{
	return (min <= grade && grade <= max);
}


short ReadGrade(const string& message, short min, short max)   // pass by constant ref.   // ranges ALWAYS passed by value.
{
	short grade;  // what's returned.

	do
	{
		grade = ReadShortNumber(message);   // 'grade' is to be IMMEDIATELY validated against the range, in the while condition

	} while (!ValidateGradeRange(grade, min, max));  // the argument is written so that, it evaluates to TRUE when the condition is INVALID.
	
	return grade;
	
	// the above block of code is to be sequentially composed line by line
	// & at the end, implement the functions of ReadShortNumber()  & ValidateGradeInRange()
}



string EvaluateGrade(short grade)   // pass by value
{
	if (grade >= 90)
	{
		return "A";
	}
	else if (grade >= 80)
	{
		return "B";
	}
	else if (grade >= 70)
	{
		return "C";
	}
	else if (grade >= 60)
	{
		return "D";
	}
	else if (grade >= 50)
	{
		return "E";
	}
	else
	{
		return "F";
	}
}


void PrintGradeEvaluation(const short& grade)    // pass by constant reference.
{
	cout << grade << " is " << EvaluateGrade(grade) << endl;   // has to be a function: as procedure returns void ( rendering an exception on this line).
}

int main()
{
	short min = 0;
	short max = 100;

	PrintGradeEvaluation(ReadGrade("Enter grade: ", min, max));

	return 0; 
}










/////////////////////////////////// Below: Some OLD UNOPTIMIZED solutions /////////////////////////////////////////////////////
/////////////////////////////////// Below: Some OLD UNOPTIMIZED solutions /////////////////////////////////////////////////////
/////////////////////////////////// Below: Some OLD UNOPTIMIZED solutions /////////////////////////////////////////////////////

//
//
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
//int ReadIntegerInRange(const unsigned short& min, const unsigned short& max, const string& message) // pass by constant ref.
//{
//    int number; // what's returned
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
//    // PrintGrade(CalculateGrade(ReadIntegerInRange(min, max, "Enter a grade [Between 0 & 100]"))); // commented out- no need to a printing procedure as we're only printing one line instead of a structure.
//
//    cout << "The grade is: " << CalculateGrade(ReadIntegerInRange(min, max, "Enter an integer between 0 and 100: ")) << endl;
//
//
//    return 0;
//}
//
//
//
//
//
//
// //this is the first attempt: Not good as unsigned short variable can only store positive numebrs to start with. so if the user enters a negative number
// //then, 👉 It gets converted to a large positive number (overflow behavior).
// //the fix: Just use integer as illustrated in the correct solution above.
//
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

