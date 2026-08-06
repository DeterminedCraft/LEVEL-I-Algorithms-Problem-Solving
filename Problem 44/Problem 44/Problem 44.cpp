
#include <iostream>
using namespace std;

/*

 Problem #44:

 Write a program to ask the user to enter:

     • Day

 Then print the day as follows:

     • 1 Print Sunday
     • 2 Print Monday
     • 3 Print Tuesday
     • 4 Print Wednesday
     • 5 Print Thursday
     • 6 Print Friday
     • 7 Print Saturday
     • Otherwise print "Wrong Day" and ask the user to enter the day again.

 Example Input:
     6

 Output:
     It's Friday


*/


// since integer values represent an idea or concept (in this case the days of the week) in the program,
// where these values are not involved in any arithmetic operations (/ * + _), then enums are used in this program.

// since enums are used in this program,
// then enums are to BE CODED FIRST and before anything else.

enum enWeekDays { Sunday = 1, Monday = 2, Tuesday = 3, Wednesday = 4, Thursday = 5, Friday = 6, Saturday = 7 };
// the enumeration constants (enumerators) that are Sunday, Monday, etc. act as labels for the raw integral values they represent
// so from now and on, FOREVER FORGET about these raw values and ONLY deal with their labels.

// so far, only an enum user-defined data type has been created and nothing more.
// the next natural step, is creating a variable of this enum user-defined data type in main().


int ReadIntegerNumber(const string& message)   // pass by constant reference.
{
    int number;  // what's returned.

    cout << message;
    cin >> number;
    cout << "\n";

    return number;
}


bool ValidateDayInRange(const int& day, int min, int max)   // pass by cosntant ref. since day is ONLY used for comparison against the ranges.
{
    return (min <= day && day <= max);
}

int ReadDay(const string& message, int min, int max)    // pass by constant reference.    // Ranges ALWAYS passed by value.
{
    bool validation;
    int day; // what's returned.

    do
    {
        day = ReadIntegerNumber(message);   // 'day' is to be IMMEDIATELY validated against the range, in the while condition.

        validation = ValidateDayInRange(day, min, max);
        if (!validation)
        {
            cout << "Error. Only enter a number between " << min << " & " << max << " .\n";
        }

    } while (!validation); // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

    return day;

    /* Note: The above block of code is to be sequentially composed line by line & at the end, implement the functions of:
             ReadIntegerNumber()   &   ValidateDayInRange()  */
}


enWeekDays CastToEnumFromInteger(int day)   // pass by value
{
    return enWeekDays(day);
}


string DetermineDayName(enWeekDays WeekDay)   // pass by value.
{
    switch (WeekDay)
    {
    case enWeekDays::Sunday:
        return "Sunday";       // no need to include break statements as they will never execute after "return"

    case enWeekDays::Monday:
        return "Monday";

    case enWeekDays::Tuesday:
        return "Tuesday";

    case enWeekDays::Wednesday:
        return "Wednesday";

    case enWeekDays::Thursday:
        return "Thursday";

    case enWeekDays::Friday:
            return "Friday";

    case enWeekDays::Saturday:
        return "Saturday"; 

    default:
        return "Invalid Week Days";
    }
}


void PrintDayName(const enWeekDays &WeekDay)   // pass by constant reference.
{
    cout << "It's " << DetermineDayName(WeekDay) << endl;
}

int main()
{
    // enWeekDays WeekDays; // the next natural step of creating a variable of the enum user-defined data type.  // commented out as it turned out that it was not needed.


    int min = 1;
    int max = 7; 

    // Initializing the below variable via reading user input (Using Function - since ONE variable is initialized & returned):
    int day = ReadDay("Enter number for day [ For Sunday = 1, Monday = 2, Tuesday = 3, Wednesday = 4, Thursday = 5, Friday = 6, Saturday = 7]: ", min, max);
/*      |
        |--> // to be typed at the end, after finishing typing the "return" keyword of the implementing function.
*/
    enWeekDays WeekDay =  CastToEnumFromInteger(day);   // so the integer value that the user entered (for example, 4 for Wednesday) is not converted to 4 of enWeekDays data type // has to be done cleanly on a separate line and cautch the returned value that's ONLY used from now and on.
    
    PrintDayName(WeekDay);


    return 0;
}








//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// BELOW IS THE SAME SOLUTION but using while loop instead of do while loop:


// Since numbers in the program represents an idea / concept, where these numbers are NOT involved in any arithmetic operation
// then, enums are utilized.

// Since enums are used, then they are the FIRST THING TO EVER CODE in the program:

enum enWeekDays { Sunday = 1, Monday = 2, Tuesday = 3, Wednesday = 4, Thursday = 5, Friday = 6, Saturday = 7}; 
// the enumeration constants / enumerators (that are Sunday, Moday, ..etc) act as labels for the raw integral values they represent.
// so from now and on, FOREVER FORGET about these raw values and ALWAYS use their labels.
// 
// 
// So far, only an enum user-defined data type has been created and nothing more.
// The next natural step, is creating a variable of the enum user-defined data type in main()


int ReadIntegerNumber(const string& message)    // pass by constant reference.
{
    int number;  // what's returned.

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}


bool ValidateDayInRange(const int& day, int min, int max) // pass by constant reference as 'day' is only used for comparison against range    // Ranges ALWAYS passed by value.
{
    return (min <= day && day <= max);   
}


int ReadDayInRange(const string& message, int min, int max)   // pass by const. ref.    // Rages ALWAYS passed by value.
{
    int day;   // what's returned

    day = ReadIntegerNumber(message);  // 'day' is IMMEDIATELY validated against the range, in the while condition.

    while (!ValidateDayInRange(day, min, max))
    {
        cout << "Wrong Day. Number for day must be between " << min << " & " << max << "\n";
        day = ReadIntegerNumber(message);
    }

    return day;
}

enWeekDays CastToEnumFromInteger(int day)  // pass by value
{
    return enWeekDays(day);
}

string DetermineDay(const enWeekDays &DayOfWeek)    // pass by constant reference.
{
    switch (DayOfWeek)    
    {
    case enWeekDays::Sunday:        // equivalent to 1 (of data type enWeekDays)
        return "Sunday";   

    case enWeekDays::Monday:
        return "Monday";

    case enWeekDays::Tuesday:
        return "Tuesday";

    case enWeekDays::Wednesday:
        return "Wednesday";

    case enWeekDays::Thursday:
        return "Thursday";

    case enWeekDays::Friday:
        return "Friday";

    case enWeekDays::Saturday:
        return "Saturday";

    default: 
        return "Not a valid day";
    }
}




void PrintDay(enWeekDays DayOfWeek)  // pass by constant reference.
{
    cout << " It's " << DetermineDay(DayOfWeek) << endl;
}

int main()
{
    
    //enWeekDays WeekDays;        // The next natural step of creating a variable of the enum user-defined data type.  // Commented out as it turned out that it was not needed.
    int min = 1;
    int max = 7;


    // Initializing the below variable via reading user input (Using function - since a variable will be initialized and returned:
    int day = ReadDayInRange("Enter number for day [Enter 1 for Sunday, 2 for Monday, 3 for Tuesday, 4 for Wednesday, 5 for Thursday, 6 for Friday, 7 for Saturday]: ", min, max);
/*       |
         |---> // to be typed at the end, after finishing typing the "return" keywprd of the implementing function. */

    enWeekDays DayOfWeek = CastToEnumFromInteger(day);

    PrintDay(DayOfWeek);
    // The printing procedure contains the function DetermineDay()
    // This is a standard coding practice. 
    // As a side effect, the printing procedure will have access to the original variable entered by the user which is the integer number, that's later on casted into an enum user-defined
    // data type and used as the argument in a switch statement that's compared against the enumeration constants (enumerators) acting as labels for the raw integral values they represent.


    return 0;
}











//
///////////////////////////// FIRST OLD ATTEMPT ////////////////////////////////////////////////////////
//////////////// VERY UNOPTIMIZED SOLUTION /////////////////////////////////////////////////////////////
//
//
//#include <iostream>
//using namespace std;
//
//
//
//
//// Since numbers in the program represents an idea / concept, where these numbers are NOT involved in any arithmetic operation
//// then, enums are utilized.
//
//// Since enums are used, then they are the FIRST THING TO EVER CODE in the program:
//
//enum enWeekDays { Sunday = 1, Monday = 2, Tuesday = 3, Wednesday = 4, Thursday = 5, Friday = 6, Saturday = 7 };
//// the enumeration constants / enumerators (that are Sunday, Moday, ..etc) act as labels for the raw integral values they represent.
//// so from now and on, FOREVER FORGET about these raw values and ALWAYS use their labels.
//// 
//// 
//// So far, only an enum user-defined data type has been created and nothing more.
//// The next natural step, is creating a variable of the enum user-defined data type in main()
//
//
//int ReadIntegerNumber(const string& message)    // pass by constant reference.
//{
//    int number;  // what's returned.
//
//    cout << message;
//    cin >> number;
//    cout << endl;
//
//    return number;
//}
//
//
//bool ValidateDayInRange(const int& day, int min, int max) // pass by constant reference as 'day' is only used for comparison against range    // Ranges ALWAYS passed by value.
//{
//    return (min <= day && day <= max);
//}
//
//
//int ReadDayInRange(const string& message, int min, int max)   // pass by const. ref.    // Rages ALWAYS passed by value.
//{
//    int day;   // what's returned
//
//    day = ReadIntegerNumber(message);  // 'day' is IMMEDIATELY validated against the range, in the while condition.
//
//    while (!ValidateDayInRange(day, min, max))
//    {
//        cout << "Wrong Day. Number for day must be between " << min << " & " << max << "\n";
//        day = ReadIntegerNumber(message);
//    }
//
//    return day;
//}
//
//enWeekDays CastToEnumFromInteger(int day)  // pass by value
//{
//    return enWeekDays(day);
//}
//
//string DetermineDay(const int& day)    // pass by constant reference.
//{
//    switch (CastToEnumFromInteger(day))    // (1-7) is now of data type enWeekDays  
//    {
//    case enWeekDays::Sunday:        // equivalent to 1 (of data type enWeekDays)
//        return "Sunday";
//
//    case enWeekDays::Monday:
//        return "Monday";
//
//    case enWeekDays::Tuesday:
//        return "Tuesday";
//
//    case enWeekDays::Wednesday:
//        return "Wednesday";
//
//    case enWeekDays::Thursday:
//        return "Thursday";
//
//    case enWeekDays::Friday:
//        return "Friday";
//
//    case enWeekDays::Saturday:
//        return "Saturday";
//
//    default:
//        return "Not a valid day";
//    }
//}
//
//
//
//
//void PrintDay(const int& day)  // pass by constant reference.
//{
//    cout << " It's " << DetermineDay(day) << endl;
//}
//
//int main()
//{
//
//    enWeekDays WeekDays; // The next natural step of creating a variable of the enum user-defined data type.
//
//    int min = 1;
//    int max = 7;
//
//    PrintDay(ReadDayInRange("Enter number for day [Enter 1 for Sunday, 2 for Monday, 3 for Tuesday, 4 for Wednesday, 5 for Thursday, 6 for Friday, 7 for Saturday]: ", min, max));
//    // The printing procedure contains the function DetermineDay()
//    // This is a standard coding practice. 
//    // As a side effect, the printing procedure will have access to the original variable entered by the user which is the integer number, that's later on casted into an enum user-defined
//    // data type and used as the argument in a switch statement that's compared against the enumeration constants (enumerators) acting as labels for the raw integral values they represent.
//
//
//    return 0;
//}


