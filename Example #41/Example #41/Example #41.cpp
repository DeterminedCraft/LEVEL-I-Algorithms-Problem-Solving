

#include <iostream>
using namespace std;

/* problem 41:

   Write a program to read a NumberOfHours in order to calculate:

   - The equivalent number of weeks.
   
   and then:

   - The equivalent number of days.



   Input
   Enter the number of hours: 365 


   Outputs
   2.17 Weeks
   15.20 Days.

*/

double  ReadDoubleNumber(const string& message)   // pass by constant reference.
{
    double number;  // what's returned

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}

bool ValidateHours(const double& hours)    // pass by constant reference.
{
    return (hours > 0);
}


double ReadHours(const string& message)    // pass by constant reference.
{
    double hours;   // what's returned.

    hours = ReadDoubleNumber(message);    // 'hours' is to be IMMEDIATELY validated against the range, in the while condition

    while (!ValidateHours(hours))   // the condition is written so that, it evaluates to TRUE when the condition is INVALID.
    {
        cout << "Error - hours entered must be larger than 0. ";
        hours = ReadDoubleNumber(message);
    }

    return hours;
    
    /* Note: The above block of code is to be sequentially composed
             line by line, & at the end implement the functions of:
             ReadDoubleNumber()   &  ValidateHours()   */
}


double CalculateNumberOfWeeks(double hours, double HoursInAWeek)    // pass by value
{
    return (hours / HoursInAWeek);                 // NOT an integer division, since both values (one of them suffices) are double.          // 1 week = 168 hours
}




double CalculateNumberOfDays(double NumberOfWeeks, double DaysInAWeek)   // pass by value
{
    return (NumberOfWeeks * DaysInAWeek);
}

void PrintNumberOfDays(const double& NumberOfWeeks, const double &DaysInAWeek)
{
    cout << "Number of days = " << CalculateNumberOfDays(NumberOfWeeks, DaysInAWeek) << endl;
}

void PrintNumberOfWeeksAndThenDays(const double& hours, const double &HoursInAWeek, const double &DaysInAWeek)   // pass by constant reference.
{
    double NumberOfWeeks = CalculateNumberOfWeeks(hours, HoursInAWeek);

    cout << "Number of Weeks = " << NumberOfWeeks << endl;

    PrintNumberOfDays(NumberOfWeeks, DaysInAWeek);
}


int main()
{
    const double HoursInAWeek = 168;     
    const double DaysInAWeek = 7;

    PrintNumberOfWeeksAndThenDays(ReadHours("Enter the number of hours: "), HoursInAWeek, DaysInAWeek);  //Range(s) NOT included as it's value is NOT intrinsic.

    return 0;
}


