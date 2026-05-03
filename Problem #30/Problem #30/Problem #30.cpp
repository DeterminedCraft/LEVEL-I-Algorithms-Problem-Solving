
#include <iostream>
using namespace std;

/*
 Problem #30:

 Write a program to calculate factorial of N!

 Example:
 factorial of 6 → 6 × 5 × 4 × 3 × 2 × 1 = 720

 Note: User should only enter a positive number, otherwise reject it and ask to enter again.

 Input
 6

 Outputs →
 720

*/

// The optimized solution:

int ReadNumber(string message) // passing by value
{
	int number; // what's returned

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}

bool ValidatePositiveNumber(int number) // pass by value
{
	return (number > 0);
}

int ReadPositiveInteger(const string &message) // passing by cosntant reference 
{

	int number; // what's returned
	do
	{
		number = ReadNumber(message); // to be IMMEDIATELY validated against the range in the condition.

	} while (!ValidatePositiveNumber(number));  // the argument is written so that, it evaluates to TRUE when the condition is invalid (hence- the ! sign).

	return number; 

	// Note: wrie all the above, line by line/ sequentially
	// and at the end, implement the functions of: ReadNumber() & ValidatePositiveNumber()

}

long long CalculateFactorialOfN(int number) // passing by value // the return type is NOT int. as factorial results GROW VERY LARGE VERY QUICKLy (Ex 12! is so huge that it surpasses the range for int)
{
	long long multiply = 1; // routine

	for (int i = number; i >= 1; i--)  // for-loops is the ebst solution as the number of iterations is known beforehand.
	{
		multiply = multiply * i; 
	}

	return multiply;
}


//long long CalculateFactorialOfN(int number) // passing by value // the return type is NOT int. as factorial results GROW VERY LARGE VERY QUICKLy (Ex 12! is so huge that it surpasses the range for int)
//{
//	long long  multiply = 1; // routine
// 
//
//	int i = number;   // 1st line to compose
//	while (i >= 1)  // 2nd line to compose
//	{
//		multiply = multiply * i;   // LAST line to compose.
//
//		i--;  // third line to compose.
//	}
//
//	return multiply;
//}

//long long CalculateFactorialOfN(int number) // passing by value // the return type is NOT int. as factorial results GROW VERY LARGE VERY QUICKLy (Ex 12! is so huge that it surpasses the range for int)
//{
//
//	long long multiply = 1; //routine
//
//    
//	int i = number;   // 1st line to compose
//	do
//	{
//		multiply = multiply * i;   // LAST line to compose.
//
//		i--;       // 2nd line to compose
//
//	} while (i >= 1);   // 3rd line to compose.
//
//	return multiply; 
//
//}


/*  commented out = just for demonstrating how the cout version in main() is more optimizing, for the reasons elaborated below:
void PrintFactorialOfN(const long long &multiply)  // passing by constant reference.
{
	cout << "The factorial is: " << multiply << endl;
}
*/

int main()
{

	//PrintFactorialOfN(CalculateFactorialOfN(ReadPositiveInteger("Enter a positive integer: ")));
    
	// The line above is commented out as the
	// cout command is more optimizing, since one numerical result is printed out
	// instead of a printing more structure/ more than one line where a printing procedure is justified.
	cout << "The factorial is: " << CalculateFactorialOfN(ReadPositiveInteger("Enter a positive integer: ")) << endl;

	/* Note: The above line should be written more cleanly as in:
	 
	  cout << "The factorial is: " 
	       << CalculateFactorialOfN(ReadPositiveInteger("Enter a positive integer: ")) << endl;
	
	
	*/

	return 0;
}

// CRUCIAL NOTE:
// The above solution is the OPTIMIZED VERSION and its 100 correct !
// Nonetheless,
// 
// The instructor's version, in my opinion, does not maximize on the Divide & Conquer strategy (= a lower quality code than the one documented above)
// his exact solution can be found here: https://www.youtube.com/watch?v=UcvvRplXhoQ&list=PL3X--QIIK-OEwPmZVfltqCYy6_RuwXr4A&index=8 
// In conclusion, so far- I do NOT recommend how he went about solving it = the aboce solution is the MOST OPTIMIZED & sane version.


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////   My very first/ initial solution 
int ReadNumber()
{
	int number; // what's returned.

	cout << "Enter a positive integer: ";
	cin >> number;
	cout << endl;

	return number;
}

bool ValidatePositiveInteger(int number) // passing by value
{
	return (number > 0);
}

int ReadPositiveInteger()
{
	int number; // what's returned.
	do
	{
		number = ReadNumber(); // to be IMMEDIATELY validated in the condition against the range.

	} while (!ValidatePositiveInteger(number)); // 👈 the argument is written so that it evaluates to TRUE when the condition is INVALID (Hence the ! sign).

	return number;
	// Note: all of the above lines are to be written sequentially in order. line by line.
	// & at the end, implement the 2 functions of:  ReadNumber()  &  ValidatePositiveInteger()
}

long long CalculateFactorialOfN(int number) // passing by value    // return type is long long, because the factorial value GROWS VERY LARGE very quickly. (13! = 6,227,020,800 ❌ (overflow))
{                                                                  // (int would overflow starting at 13!)
	long long  multiply = 1; // routine

	for (int i = number; i >= 1; i--)
	{
		multiply = multiply * i; // i is automatically promoted to the larger data type (no data loss from small to big = from int to long long (long long int))
	}

	return multiply;

}

void PrintFactorialOfN(const long long &multiply) // passing by constant reference. 
{
	cout << "The factorial is: " << multiply << endl;
}

int main()
{
   

	PrintFactorialOfN(CalculateFactorialOfN(ReadPositiveInteger())); 

	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////








