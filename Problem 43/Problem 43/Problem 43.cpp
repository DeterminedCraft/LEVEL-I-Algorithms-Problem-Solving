

#include <iostream>
using namespace std;

/*

 Problem #43:

 Write a program that inputs the number of seconds and changes it to
 days, hours, minutes, and seconds.

 Input
 193,535

 Output
 2:5:45:35

*/



struct stDuration
{
	int days;
	int hours;
	int minutes;
	int seconds;
};
// so far, only a structure user-defined data type has been created and nothing more.

// this time. we^re not initializing these values (whether directly or via reading user input)
// so, still create a function of this structure user-defined data type that returns a variable of this structure user-defined data type.
// implement it IMMEDIATELY now BELOW:

stDuration CalculateDuration( int seconds)   // pass by value
{
	stDuration duration; // what's returned.  // AS SOON AS you see such a line, ALWAYS envision 'duration' having access to all member variables defined inside the structure.

	const int SecondsInADay = 24 * 60 * 60;
	const int SecondsInAnHour = 60 * 60;
	const int SecondsInAMinute = 60;

	int remainder = 0;  // added at the end when it was convenient to do so.

	duration.days = seconds / SecondsInADay;      // an INTEGER division, since both numbers are integers.
	remainder = seconds % SecondsInADay;

	duration.hours = remainder / SecondsInAnHour;
	remainder = remainder % SecondsInAnHour;

	duration.minutes = remainder / SecondsInAMinute;

	duration.seconds = remainder % SecondsInAMinute;

	return duration;

}




int ReadIntegerNumber(const string& message)   // pass by constant reference
{
	int number;   // what's returned.

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}


bool ValidateSeconds(const int& seconds)  // oass by constant ref. since 'seconds' in ONLY used for comparison against the range.
{
	return (seconds >= 0);
}


int ReadSeconds(const string& message)    // pass by cosntant reference.
{
	bool validation;
	int seconds; // what's returned.

	do
	{
		seconds = ReadIntegerNumber(message);   // 'seconds' is IMMEIDATELY validated against the range, in the while condition


		validation = ValidateSeconds(seconds);
		if (!validation)
		{
			cout << "Error. Seconds entered must not be negative. ";
		}


	} while (!validation); // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

	return seconds;

	/* Note:
	   The above lines of code are to be sequentially composed line by line. And at then end, implement the functions of: ReadIntegerNumber() &() ValidateSeconds*/
}

void PrintDaysHoursMinutesAndSeconds(const stDuration& duration)   // pass by constant reference.
{
	cout << duration.days << " days : " << duration.hours << " hours: " << duration.minutes << " minutes : " << duration.seconds << " seconds " << endl;
}


int main()
{



	// Initializing the below variable via reading user input (Using Function - since ONE variable is initialized & returned):
	int seconds = ReadSeconds("Enter the total number of seconds: "); 
/*       |
         |---> to be typoed at the end, after finishing typing the "return" keyword in the implementing function. */


	PrintDaysHoursMinutesAndSeconds(CalculateDuration(seconds));   


	return 0;
}






//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// UNOPTIMIZED OLD SOLITON PLUS without the use of structures
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// UNOPTIMIZED OLD SOLITON PLUS without the use of structures
//// without the use of structures, one ends up with some unoptimized trashy solution as showcased below (Hint: The implementation of the printing procedure): 
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
//bool ValidateSeconds(const int& seconds)     // passing by constant reference since 'seconds' is ONLY used for comparison against the range.
//{
//    return (seconds >= 0);
//}
//
//int ReadSeconds(const string& message)   // pass by constant reference.
//{
//    int seconds;   // what's returned
//
//    seconds = ReadIntegerNumber(message);  // 'seconds' is to be IMMEDIATELY validated against the range, in the while condition.
//
//    while (!ValidateSeconds(seconds))   // the condition is written so that, it evaluates to TRUE when the condition is INVALID.
//    {
//        cout << "Error. Number of seconds must be positive. ";
//        seconds = ReadIntegerNumber(message);
//    }
//
//    return seconds; 
//
//    /* Note: The above block of code is to be sequentially composed line by line
//             and at the end, implement the functions of:
//             ReadIntegerNumber()  & ValidateSeconds()      */
//}
//
//
//
//
//void PrintHoursDaysMinutesAndSeconds(const int& seconds, const int &SecondsInADay, const int& SecondsInAnHour, const int& SecondsInAMinute)   // pass by constant reference
//{
//    int NumberOfDays = seconds / SecondsInADay;
//    int remainder = seconds % SecondsInADay;   // the remaining seconds after the number of days was determined.
//
//    int NumberOfHours = remainder / SecondsInAnHour;
//    remainder = remainder % SecondsInAnHour; // the remaining seconds after determing the number of hours.
//
//    int NumberOfMinutes = remainder / SecondsInAMinute;
//    int NumberOfSeconds = remainder % SecondsInAMinute;
//    
//    cout << NumberOfDays << " : " << NumberOfHours << " : " << NumberOfMinutes << " : " << NumberOfSeconds << endl;
//}
//
//
//int main()
//{
//    const int SecondsInADay = 24 * 60 * 60;
//    const int SecondsInAnHour = 60 * 60;
//    const int SecondsInAMinute = 60;
//
//
//    // Initializing the below variable via reading user input (Using Function - since ONE variable is initialized and returned):
//    int seconds = ReadSeconds("Enter the number of seconds: ");    // Range(s) NOT included as the value is NOT intrinsic
///*        |
//          |--> to be typed at the end, after typing the "return" keyword in the implementing function.    */
//    
//    PrintHoursDaysMinutesAndSeconds(seconds, SecondsInADay, SecondsInAnHour, SecondsInAMinute);
//    // This printing procedure contains the methods CalculateDays(), CalculateHours(), CalculateMinutes(), & calculateSeconds()
//    // this is a standard coding practice that's also conducive to the printing procedure having access / can reference 
//    // the original variable entered by the user that's 'seconds'
//
//
//    return 0;
//}
//

