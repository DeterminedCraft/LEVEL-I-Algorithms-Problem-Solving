

#include <iostream>
using namespace std;

/*

 Problem #45:

 Write a program to ask the user to enter:

     • Month

 Then print the month as follows:

     • 1  Print January
     • 2  Print February
     • 3  Print March
     • 4  Print April
     • 5  Print May
     • 6  Print June
     • 7  Print July
     • 8  Print August
     • 9  Print September
     • 10 Print October
     • 11 Print November
     • 12 Print December

     • Otherwise print "Wrong Month" and ask the user to enter the Month again.

 Example Input:

 11

 Output:

 November

*/





// Since raw integer values are going to be used in the code to represent a concept / idea (in this case numbers representing their perspective months),
// Then, enums are to be used. 
// Therefore, enums are to be CODED FIRST in the program BEFORE ANYTHING ELSE.

enum enYearMonths { January = 1, February = 2, March = 3, April = 4, May = 5, June = 6, July = 7, August = 8, September = 9, October = 10, November = 11, December = 12 };
// The enumeration constants (enumerators) act as labels for the raw integral values they represent.
// Therefore- From Now and on FOREVER FORGET about these raw values and ALWAYS DEAL WITH THEIR LABELS.

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

bool ValidateMonthInRange(const int& month, int min, int max)   // pass by constant ref since 'mont' is ONLY compared against the range.   // Ranges ALWAYS passed by value.
{
    return (min <= month && month <= max);
}



int ReadMonth(const string& message, int min, int max)   // pass by constant reference.   // ranges ALWAYS passed by value.
{
    int month;   // what's returned

    month = ReadIntegerNumber(message);   // 'month' is to be IMMEDIATELY validated against the range, in the while condition.

    while (!ValidateMonthInRange(month, min, max))
    {
        cout << "Wrong number entered. Enter a value between " << min << " & " << max << "\n";
        month = ReadIntegerNumber(message);
    }

    return month;

    /* The above block of code is to be sequentially composed line by line, & at the end implement the functions of:
       ReadIntegerNumber(9   &   ValidateMonthInRange()  */
}



enYearMonths CastToEnumFromInteger(int month)   // pass by value.
{
    return enYearMonths(month);
}


string DetermineNameOfTheMonth(enYearMonths MonthOfTheYear)   // pass by value.
{
    switch (MonthOfTheYear)
    {
    case enYearMonths::January:
        return "January";

    case enYearMonths::February:
        return "February";

    case enYearMonths::March:
        return "March";

    case enYearMonths::April:
        return "April";

    case enYearMonths::May:
        return "May";

    case enYearMonths::June:
        return "June";

    case enYearMonths::July:
        return "July";

    case enYearMonths::August:
        return "August";

    case enYearMonths::September:
        return "September";

    case enYearMonths::October:
        return "October";

    case enYearMonths::November:
        return "November";

    case enYearMonths::December:
        return "December";

    default:
        return "Invalid Month";
    }
}


void PrintNameOfTheMonth(const enYearMonths& MonthOfTheYear)    // pass by constant reference
{
    cout << "It's " << DetermineNameOfTheMonth(MonthOfTheYear) << "\n";
}


int main()
{
    enYearMonths YearMonths; // The next natural step of declaring a variable of the enum user-defined data type.

    int min = 1;
    int max = 12;


    int month = 
        ReadMonth(
        "Enter the number of the month:\n"
        "[1] January\n"
        "[2] February\n"
        "[3] March\n"
        "[4] April\n"
        "[5] May\n"
        "[6] June\n"
        "[7] July\n"
        "[8] August\n"
        "[9] September\n"
        "[10] October\n"
        "[11] November\n"
        "[12] December : \n\n"
        , min, max);

    enYearMonths MonthOfTheYear = CastToEnumFromInteger(month);   // the numerical value the user entered (for example:   2) is now of the enum user-defined data type that's enYearMonth
    // this is what's used from now and on.
   // It will be the argument of a switch statement that^s compared against the enumeration constants (enumerators) that are present in the enum creation step above
    // we will return a string, that's the name of the month and then do something with it such as printing it to the screen (or send it to the backend somewhere).


    PrintNameOfTheMonth(MonthOfTheYear);




	return 0;
}


