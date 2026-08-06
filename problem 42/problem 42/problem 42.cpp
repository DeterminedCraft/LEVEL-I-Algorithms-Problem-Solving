

#include <iostream>
using namespace std;

/*

 Problem 42:

 Write a program to calculate the total task duration in seconds and print it on screen.

 ➔ Given the time duration of a task in the number of days, hours, minutes, and seconds.

 Input

 2
 5
 45
 35

 Outputs ➔

 193,535 Seconds

*/


// The correct solution utilizes structures:

struct stDuration
{
	double days;
	double hours;
	double minutes;
	double seconds;
};
// so far, only a structure user-defined data type has been created and nothing more.
// the next natural step is creating a variable of this structure user-defined data type.
//
// But the main question is, where to create this variable ?
// - If it's going to be initialized directly, then declare it in main()
// - If it's going to be initialized via reading user input, then declare it inside a reading function of the structure user-defined data type, that returns this variable
// since it's the latter, then IMMEDIATELY start implementing this function NOW below:




double ReadDoubleNumber(const string& message)   // passing by constant ref.
{
	double number; // what's returned

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}

bool ValidateDuration(const double& duration)   // pass by constant reference. since 'duration' is goint to be compared against the range, in the while condition.
{
	return (duration >= 0);
}




stDuration ReadDuration(const string& MessageDays, const string& MessageHours, const string& MessageMinutes, const string& MessageSeconds)
{
	int counter = 0;
	stDuration duration;  // what's returned.   // AS SOON AS you see this line, ALWAYS envision the variable 'duration' having access to all member variable inside the structure

	do
	{
		counter++;
		if (counter > 1)
		{
			cout << "Error. Day values must be zero or positive. ";
		}

		duration.days = ReadDoubleNumber(MessageDays);   // 'duration.days' is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateDuration(duration.days));   // the condition is written so that, it evaluates to TRUE when the condition is INVALID.



	counter = 0;
	do
	{
		counter++;
		if (counter > 1)
		{
			cout << "Error. Hour values must be zero or positive. ";
		}

		duration.hours = ReadDoubleNumber(MessageHours); // 'duration.hours' is to be IMMEDIATELY validated against the range, in the while condition

	} while (!ValidateDuration(duration.hours));   // the condition is written so that, it evaluates to TRUE when the condition is INVALID.



	counter = 0;
	do
	{
		counter++;
		if (counter > 1)
		{
			cout << "Error. Minute values must be zero or positive. ";
		}

		duration.minutes = ReadDoubleNumber(MessageMinutes);  // 'duration.minutes' is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateDuration(duration.minutes));  // the condition is written so that, it evaluates to TRUE when the condition is INVALID.



	counter = 0;
	do
	{
		counter++;
		if (counter > 1)
		{
			cout << "Error. Second values must be zero or positive. ";
		}

		duration.seconds = ReadDoubleNumber(MessageSeconds);  // 'duration.seconds' is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateDuration(duration.seconds));   // the condition is written so that, it evaluates to TRUE when the condition is INVALID.



	return duration;

	/*  Note: The above block of code is to be sequentially composed line by line
			  & at the end, implement the functions of:
			   ReadDoubleNumber()   &   ValidateDuration()
	*/
}


double FromDaysToSeconds(double days)   // pass by value
{
	const int SecondsPerday = 24 * 60 * 60;
	return (days * SecondsPerday);
}

double FromHoursToSeconds(double hours)   // pass by value.
{
	const int SecondsPerHour = 60 * 60;
	return (hours * SecondsPerHour);
}

double FromMinutesToSeconds(double minutes)  // pass by value.
{
	const int SecondsPerMinute = 60;
	return (minutes * SecondsPerMinute);
}

void PrintTotalDurationInSeconds(const stDuration& duration)   // pass by constant reference. // AS SOON AS you see such line in argument, ALWAYS envision 'duration' having access to all member variables defined inside the structure.
{
	cout << "Total Number of Seconds = " << duration.seconds +
		FromDaysToSeconds(duration.days) +
		FromHoursToSeconds(duration.hours) +
		FromMinutesToSeconds(duration.minutes)
		<< " seconds. " << endl;
}

int main()
{
	// Instead of declaring these variables in main, I'm going to declare them
	// as member variables inside a structure since they're are related amongst each other.

	PrintTotalDurationInSeconds(ReadDuration("Enter Number of Days: ",
		"Enter Number of hours: ",
		"Enter Number of minutes: ",
		"Enter number of seconds: ")); // Ranges NOT included as their values are NOT intrinsic.

	//ReadDuration() has to be a function as procedures return void which renders an exception here.
	// This printing procedure will contain the functions: FromDaysToSeconds(), FromHoursToSeconds(), FromMinutesToSeconds() all added up together plus the variable for the number of seconds.
	// this is a standard coding procedure
	// that's also conducive to this printing procedure having access / can reference the original variables entered by the user.

	return 0;
}








/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                     // A previous less optimized solution PLUS  WITHOUT utilizing structures
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//
//double ReadDoubleNumber(const string& message)    // pass by constant reference.
//{
//	double number;   // what's returned.
//
//	cout << message;
//	cin >> number;
//	cout << endl;
//
//	return number;
//}
//
//
//bool ValidateDuration(const double& duration)    // passing by const ref. since 'duration' is only used for comparison against the range.
//{
//	return (duration > 0);
//}
//
//
//double ReadDuration(const string& message)
//{
//	int counter = 0;
//
//	double duration;   // what's returned.
//
//	do
//	{
//		counter++;
//		if (counter > 1)
//		{
//			cout << "Error. Duration must be positive. ";
//		}
//		duration = ReadDoubleNumber(message);   // 'duration' is IMMEDIATELY validated against the range, in the while condition.
//
//	} while (!ValidateDuration(duration));     // the argument is written so that it evaluates to TRUE when the condition is INVALID.
//
//	return duration;   
//	// the above block of code is to be composed line by line and at the end, implement the functions of ReadDoubleNumber()  && ValidateDuration()
//}
//
//
//double FromMinutesToSeconds(double DurationInMinutes, double SecondsInAMinute)   // pass by value
//{
//	return (DurationInMinutes * SecondsInAMinute);
//}
//
//double FromHoursToSeconds(double DurationInHours, double SecondsInAnHour)  // pass by value
//{
//	return (DurationInHours * SecondsInAnHour); 
//}
//
//double FromDaysToSeconds(double  DurationInDays, double SecondsInADay)   // pass by value
//{
//	return  (DurationInDays * SecondsInADay);
//}
//
//
//void PrintDurationInSeconds(const double& DurationInSeconds, const double& DurationInMinutes, const double& DurationInHours, const double& DurationInDays,
//	                        const double &SecondsInAMinute, const double &SecondsInAnHour, const double &SecondsInADay)     // pass by constant reference.
//{
//	cout << "Total Duration is Seconds = " << DurationInSeconds 
//		                                    + FromMinutesToSeconds(DurationInMinutes, SecondsInAMinute)
//		                                    + FromHoursToSeconds(DurationInHours, SecondsInAnHour) 
//		                                    + FromDaysToSeconds(DurationInDays, SecondsInADay) << " seconds." << endl;
//}
//
//
//
//int main()
//{
//	const double SecondsInAMinute = 60;
//	const double SecondsInAnHour = 60 * 60; 
//	const double SecondsInADay = 24 * 60 * 60;
//
//
//   // Initializing the below variable via reading user input (Using function - since ONE variable is initialized and returned)
//	double DurationInDays = ReadDuration("Enter the duration in days: "); // Range(s) NOT included as the value is NOT intrinsic.
///*           |
//             |---> to be typed at the end, after finishing typing the "return" keyword        */
//	double DurationInHours = ReadDuration("Enter the duration in hours: "); // Range(s) NOT included as the value is NOT intrinsic.
///*           |
//			 |---> to be typed at the end, after finishing typing the "return" keyword        */
//	double DurationInMinutes = ReadDuration("Enter the duration in minutes: "); // Range(s) NOT included as the value is NOT intrinsic.
///*           |
//			 |---> to be typed at the end, after finishing typing the "return" keyword        */
//	double DurationInSeconds = ReadDuration("Enter the duration in seconds: "); // Range(s) NOT included as the value is NOT intrinsic.
///*           |
//			 |---> to be typed at the end, after finishing typing the "return" keyword        */
//
//	PrintDurationInSeconds(DurationInSeconds, DurationInMinutes, DurationInHours, DurationInDays, 
//		                   SecondsInAMinute, SecondsInAnHour, SecondsInADay);
//	// this printing procedure contains the methods: FromMinutesToSeconds(), FromHoursToSeconds(), FromDaysToSeconds() all added up along with the variable DurationInSeconds.
//	// this is a standard coding practice.
//	// It's also conducive to the printing procedure having  direct access / the ability to reference the original variables entered by the user.
// 
//
//	return 0;
//}
//
//






