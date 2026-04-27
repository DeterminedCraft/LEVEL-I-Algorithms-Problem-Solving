
#include <iostream>
#include <string>   // to user to_string() method
using namespace std;

/*
 Problem 7:

 Write a program to ask the user to enter:
 - Number

 Then print:
 "Half of the <Number> is ???"

 Example Inputs:
 60
 50

 Outputs:
 Half of 60 is 30
 Half of 50 is 25 


 */

float ReadNumber()   // فَرِّقْ تَسُدْ/ Divide & conquer 
{
	float number; // what's returned.

	cout << "Enter a number: ";
	cin >> number;
	cout << "\n";

	return number;
}


bool ValidatePositiveFloat(const float &number)    // passing by constant reference
{
	return (number > 0);
}

float ReadPositiveFloat()
{
	float number; // what^s returned
	do
	{
		number = ReadNumber(); // 'number' is to be IMMEDIATELY evaluated against the range, in the while condition

	} while (!ValidatePositiveFloat(number));

	return number;

	//Note: the above block of code is to be sequentially composed
	// line by line. At the end, implement the 2 functions of:      ReadNumber()  &    ValidatePositiveFloat()

}

float CalculateHalfTheNumber(float number) // passing by value   فَرِّقْ تَسُدْ/ Divide & conquer 
{
	return  number / 2;       // no integer division will be performed as variable 'number'stores float (for example, stores as 3.0f)
}

void PrintHalfTheNumber(const float& number) //passing by constant reference.
{
	// the easy way: 
	/*cout << "Half of " << number << " is " << CalculateHalfTheNumber(number) << endl;*/

	// using concatenation instead: 
	string message = "Half of " + to_string(number) + " is: " + to_string(CalculateHalfTheNumber(number));   // #include <string>   // to user to_string() method
	cout << message << endl;


}


int main()
{
	PrintHalfTheNumber(ReadPositiveFloat()); 
	// ALWAYS construct the nested line functions in a way where the implementation of the printing function calls some function (when possible, correct, & logical).
		// A by-product of the above not is that:
		  // Nesting this way is conducive to the printing procedure having access to the original number the user enters. 
		  // 
	// The other way, is to strive to have an if statement whose argument is a called function (that returns boolean off course) inside the implementation of the printing procedure.

	return 0;
}


////////////////////////////////////////////////////////      BELOW: OLD & UNOPTIMIZED ways of solving this problem ////////////////////////////////////////////////////////
//
//
//float ReadNumber()   // فَرِّقْ تَسُدْ/ Divide & conquer 
//{
//	float number; // what's returned by this function
//
//	cout << "Enter number: ";
//	cin >> number;
//	cout << endl;
//
//	return number;
//}
//
//float HalvingNumber(float number) // pass by value    // pass by value.  فَرِّقْ تَسُدْ/ Divide & conquer 
//{
//	return  number / 2;   // no integer division will be performed as variable 'number'stores float (for example, stores as 3.0f)
//}
//
//void PrintHalfTheNumber(const float& number) // pass by constant reference.    // pass by value.  فَرِّقْ تَسُدْ/ Divide & conquer 
//{
//	cout << "Half of the number: " << number << " = " << HalvingNumber(number) << endl;
//}
//
//int main()
//{
//
//
//	PrintHalfTheNumber(ReadNumber()); // Nesting this way is conducive to the printing procedure having access to the original number the user enters. 
//	//PrintHalfTheNumber(CalculateHalfNumber(ReadNumber())), //nesting this way, will not enable the printing procedure to reference the original number the user inputs
//
//	return 0;
//}
//
//
//
//
//
//
//
//// ANOTHER WAY to solve this question (Instructors's way): 
//
//float ReadUserInput()
//{
//	float number;
//
//	cout << "Enter a number: ";
//	cin >> number;
//	cout << endl;
//
//	return number;
//
//}
//
//float CalculateHalfTheNumber(float number) // pass by value.  فَرِّقْ تَسُدْ/ Divide & conquer 
//{
//	return number / 2;  // This will not be an integer division because nuber will be stored, for example, as 3.0f
//}
//
//void PrintResult(const float &number) // passing by constant reference.
//{
//	// It's good to resort to concatenation:  INSTEAD of always doing so with COUT:
//	
//	string result = "Half of " + to_string(number) + " is " + to_string(CalculateHalfTheNumber(number);
//	cout << result << endl;
//
//	 // If I use to_string(float), the number will be formatted with 6 decimal places by default, 
//	 // which may not be desirable. Therefore, in this specific example, it is better to use cout.
//
//	 // WE WILL ADDRESS THE FORMATTING FUNCTIONS IN: LEVEL II C ++. 
//
//}
//
//
//int main()
//{
//	PrintResult(ReadUserInput()); // The argument has to be function; as procedure returns void which can never be an argument for the PrintResult procedure.
//
//	return 0;
//}
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// BAD initial solution:
//
//float ReadUserInput()
//{
//    float number;
//
//    cout << "Enter a number: ";
//    cin >> number;
//    cout << endl;
//
//    return number;
//    // when the variable number is returned, it will be initialized.
//    // the lifecycle of this variable ends when the program exists this function.
//}
//
//float DivideByTwo(float number) // return by value
//{
//    return number / 2;    // no need to say 2.0 because number even if entered as "5" by user, it is stored as 5.0f. So this will not be an integer division.
//}
//
//void PrintResult(const float &DivisionResult, int number) // passing by const reference.  CRUCIAL: Avoid a variable name that is the same as a function in the code ( = avoid: float DivideByTwo)
//{
//    cout << "The division by " << number << " is = " << DivisionResult << endl;
//}
//
//int main()
//{
//    /* Attempt #2:
//    int number = ReadUserInput();
//
//    PrintResult(DivideByTwo(number), number);
// 
//     // But this is unoptimized attempt- This first line where we catch the returned value in a variable makes reading and understanding difficult
//     // so that line must be removed.
//     // so the final optimized attempt turns out to be: PrintResult(ReadUserInput) so that PrintResult has the needed origial number argument.
//     // 
//    */
//   
// 
//  // Attempt #1: PrintResult(DivideByTwo(ReadUserInput())); // where I could not reference the original number inputed by the user in the printing procedure. so I tried attempt 2
//  // because in the above line, the argument for the printing procedure is a returned value of division (only ONE value is returned). Hence, the printing procedure has
//  // no knowledge of the number entered by the user.
// 
//    return 0;
//}
//
