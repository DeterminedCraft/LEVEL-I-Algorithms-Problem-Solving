
#include <iostream>
using namespace std;

/*
 Problem #29:

 Write a program to sum EVEN numbers from 1 to N.

 Input
 10

 Outputs →
 30

*/

/*
  Solving it utilizing enums. 
  Therefore, we ALWAYS start this program with coding enums.
  Since the use of enum isn't the typical approach, some of the enum workflows (mental model) may NOT apply.

*/


enum enEvenOrOdd{ Even = 0, Odd = 1}; // the enumeration constants (enumerators) that are Even & Odd, act as labels for the integral raw values they represent.
// so far, only an enum user-defined data type has been created and nothing else.
// the enxt natural step is creating a variable of this enum user-defined data type.


int ReadNumber()
{
	int number; // what's returned

	cout << "Enter a positive integer: ";
	cin >> number;

	return number;

}

bool ValidatePositiveInteger(int number) // passing by value
{
	return (number > 0);
}


int ReadPositiveInteger()
{
	int number; // whats returned
	do
	{
		number = ReadNumber(); // to be IMMEDIATELY  validated against the range in the condition.

	} while (!ValidatePositiveInteger(number));

	return number;
	// ALL of the above lines of code are written sequentially step by step.
	// now, you implement the functions: ReadNumber() & ValidatePositiveInteger()
}

enEvenOrOdd CheckEvenOrOdd(const int &i) // pass by constant reference
{
	if (i % 2 == 0)
	{
		return enEvenOrOdd::Even;
	}
	else
	{
		return enEvenOrOdd::Odd;
	}
}

int CalculateSumOfEvenNumbersFrom1ToN(int number) // passing by value
{
	int sum = 0; // routine

	for (int i = 1; i <= number; i++)  // for-loops is the BEST solution since the number of iterations is know beforehand.
	{
		if (CheckEvenOrOdd(i) == enEvenOrOdd::Even)
		{
			sum += i;
		}
	}

	return sum;
}


//int CalculateSumOfEvenNumbersFrom1ToN(int number) // passing by value
//{
//	int sum = 0; //routine
//
//	int i = 1;      // 1st line to write
//	while (i <= number)    // 2nd line to write
//	{
//
//		if (CheckEvenOrOdd(i) == enEvenOrOdd::Even)   // LAST line to compose.
//		{
//			sum += i;
//		}
//
//		i++;   // 3rd line to write
//	}
//
//	return sum;
//}
 
//int CalculateSumOfEvenNumbersFrom1ToN(int number) // passing by value
//{
//	int sum = 0; // routine.
//
//	int i = 1;   // 1st line to compose
//	do
//	{
//		if (CheckEvenOrOdd(i) == enEvenOrOdd::Even)    // LAST line to compose.
//		{
//			sum += i;
//		}
//
//		i++;  //2nd line to compose 
//
//	} while (i <= number); // 3rd line to compose.
//
//	return sum;
//}


void PrintSumOfEvenNumberFrom1ToN(const int& sum) // pass by constant reference.
{
	cout << "The sum of all EVEN numbers from 1 to N is: " << sum << endl;
}

int main()
{
	//enEvenOrOdd EvenOrOdd; // the natural step of creating a variable of the enum user-defined daya type. // commenting it out as it turned out that this step was never needed.



	PrintSumOfEvenNumberFrom1ToN(CalculateSumOfEvenNumbersFrom1ToN(ReadPositiveInteger()));

	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Solution showcasing the 3 different types of loops:


enum enEvenOrOdd { Even = 0, Odd = 1 }; // the enumeration constants (enumerators) that are Even & Odd, act as labels for the integral raw values they represent.
// so far, only an enum user-defined data type has been created and nothing else.
// the enxt natural step is creating a variable of this enum user-defined data type.


int ReadNumber()
{
	int number; // what's returned

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
	int number; // whats returned
	do
	{
		number = ReadNumber(); // to be IMMEDIATELY  validated against the range in the condition.

	} while (!ValidatePositiveInteger(number));

	return number;
	// ALL of the above lines of code are written sequentially step by step.
	// now, you implement the functions: ReadNumber() & ValidatePositiveInteger()
}

enEvenOrOdd CheckEvenOrOdd(const int& i) // pass by constant reference
{
	if (i % 2 == 0)
	{
		return enEvenOrOdd::Even;
	}
	else
	{
		return enEvenOrOdd::Odd;
	}
}

int CalculateSumOfEvenNumbersFrom1ToN_UsingForLoops(int number) // passing by value
{
	cout << "Solving it using For-Loops \n";



	int sum = 0; // routine

	for (int i = 1; i <= number; i++)  // for-loops is the BEST solution since the number of iterations is know beforehand.
	{
		if (CheckEvenOrOdd(i) == enEvenOrOdd::Even)
		{
			sum += i;
		}
	}

	return sum;
}


int CalculateSumOfEvenNumbersFrom1ToN_UsingWhileLoops(int number) // passing by value
{
	cout << "Solving it using While-Loop \n";



	int sum = 0; //routine

	int i = 1;      // 1st line to write
	while (i <= number)    // 2nd line to write
	{

		if (CheckEvenOrOdd(i) == enEvenOrOdd::Even)
		{
			sum += i;
		}

		i++;   // 3rd line to write
	}

	return sum;
}

int CalculateSumOfEvenNumbersFrom1ToN_UsingDoWhileLoops(int number) // passing by value
{
	cout << "Solving it using Do-While-Loop \n";




	int sum = 0; // routine.

	int i = 1;   // 1st line to compose
	do
	{
		if (CheckEvenOrOdd(i) == enEvenOrOdd::Even)
		{
			sum += i;
		}

		i++;  //2nd line to compose 

	} while (i <= number); // 3rd line to compose.

	return sum;
}


void PrintSumOfEvenNumberFrom1ToN(const int& sum) // pass by constant reference.
{
	cout << "The sum of all EVEN numbers from 1 to N is: " << sum << endl <<endl;
}

int main()
{
	// enEvenOrOdd EvenOrOdd; // the natural step of creating a variable of the enum user-defined daya type. // commenting it out as it turned out that this step was never needed.


	int N = ReadPositiveInteger();

	PrintSumOfEvenNumberFrom1ToN(CalculateSumOfEvenNumbersFrom1ToN_UsingForLoops(N));
	PrintSumOfEvenNumberFrom1ToN(CalculateSumOfEvenNumbersFrom1ToN_UsingForLoops(N));
	PrintSumOfEvenNumberFrom1ToN(CalculateSumOfEvenNumbersFrom1ToN_UsingDoWhileLoops(N));

	return 0;
}


/******************************************************************************************************************************************************************************************
 ******************************************************************************************************************************************************************************************
 ******************************************* In the case that you're NOT using enums which is DISCOURAGED, then continue below ************************************************************
 ******************************************************************************************************************************************************************************************
 ******************************************************************************************************************************************************************************************/

// The optimized solution:
int ReadNumber()
{
	int number; // what's returned

	cout << "Enter a positive integer: \n";
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
	int number; // what's returned
	do
	{
		number = ReadNumber(); // 'number' is IMMEDIATELY validated in the condition against the range.

	} while (!ValidatePositiveInteger(number)); // the argument is written so that it evaluates to TRUE when the condition is INVALID

	return number;
	//Note: the above lines of code are to be entirely written line by line. At the end, start implementing the ReadNumber() & the ValidatePositiveInteger() functions.
}

int CalculateSumOfEvenNumbers(int number) // pass by value
{
	int sum = 0;

	for (int i = 2; i <= number; i += 2)   // I could^ve started with int i=0 which is correct. However, the agreement or preference is that i=0 is to be used for indexes of arrays, etc.
	{
		sum += i;
	}

	return sum;
}

void PrintSumOfEvenNumbers(const int& sum) // passing by constant reference.
{
	cout << "The sum of the even numbers from 1 to N is: " << sum << endl;
}

int main()
{
  

	PrintSumOfEvenNumbers(CalculateSumOfEvenNumbers(ReadPositiveInteger()));

	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Solution showcasing the 3 different types of loops:

int ReadNumber()
{
	int number; // what's returned

	cout << "Enter a positive integer: \n";
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
	int number; // what's returned
	do
	{
		number = ReadNumber(); // 'number' is IMMEDIATELY validated in the condition against the range.

	} while (!ValidatePositiveInteger(number)); // the argument is written so that it evaluates to TRUE when the condition is INVALID

	return number;
	//Note: the above lines of code are to be entirely written line by line. At the end, start implementing the ReadNumber() & the ValidatePositiveInteger() functions.
}

int CalculateSumOfEvenNumbers_UsingForLoops(int N) // pass by value
{
	cout << "Solving using For-Loops: \n";


	int sum = 0;

	for (int i = 2; i <= N; i += 2)   // I could^ve started with int i=0 which is correct. However, the agreement or preference is that i=0 is to be used for indexes of arrays, etc.
	{
		sum += i;
	}

	return sum;
}

int CalculateSumOfEvenNumbers_UsingWhileLoops(int N) // pass by value
{
	cout << "Solving using While-Loop: \n";



	int sum = 0;

	int i = 2;        // 1st step to write
	while (i <= N)   // 2nd step to write
	{
		sum+= i;         // the LAST step to write.
		i += 2;    // 3rd step to write
	}

	return sum;
}



int CalculateSumOfEvenNumbers_UsingDoWhileLoops(int N)// pass by value
{
	cout << "Solving using Do-While Loop: \n";


	int sum = 0;

	int i = 2;
	do
	{
		sum = sum + i;
		i += 2;

	} while (i <= N);

	return sum;
}


void PrintSumOfEvenNumbers(const int& sum) // passing by constant reference.
{
	cout << "The sum of the even numbers from 1 to N is: " << sum << endl << endl;;
}
int main()
{
	int N= ReadPositiveInteger();

	PrintSumOfEvenNumbers(CalculateSumOfEvenNumbers_UsingForLoops(N));
	PrintSumOfEvenNumbers(CalculateSumOfEvenNumbers_UsingWhileLoops(N));
	PrintSumOfEvenNumbers(CalculateSumOfEvenNumbers_UsingDoWhileLoops(N));

	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 //Unoptimized approach:
 //Iterates through all numbers from 1 to N and performs a modulo check
 //at each step to determine if the number is even.
 //This results in unnecessary iterations and conditional checks.

/*
 for (int i = 1; i <= N; i++)
 {
     if (i % 2 == 0)   // 👈 the [i % 2] portion STILL needs to be wrapped in its own function- Divide & Conquer.
     {
         sum += i;
     }
 }
 */

 //Optimized approach (used above):
 //Iterates only through even numbers by incrementing by 2, where i is initially set to 2 (i = 2)
 //eliminating the need for conditional checks and reducing iterations by half.

	

