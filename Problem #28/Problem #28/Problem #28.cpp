
#include <iostream>
using namespace std;

/*
 Problem #28:
 Write a program to sum odd numbers from 1 to N.

 Input
 10

 Outputs →
 25

*/


 //A- The UNOPTMIZED approach:
 //
 //
 //If enums are to be used, then they coded FIRST on top & before anything else.
 //the utiliztation of enums, in here, may not necessarily follow the regular enum workflow mental model.
enum enEvenOrOdd { Even = 0, Odd =1};  // Even & Odd are enumeration constants (enumerators) acting as labels for the raw integers.
// so far we've created nothing but an enum user-defined data type. That's all.

int ReadNumber()
{
	int number; // what's returned.

	cout << "Enter a positive integer: ";
	cin >> number;
	cout << endl;

	return number;
}

bool ValidatePositiveInteger(int number) // passing by value.
{
	return (number > 0);
}

int ReadPositiveInteger()
{
	int number; // what's returned
	do
	{
		number = ReadNumber(); // 'number' to be IMMEDIATELY validated against the range in the condition.

	} while (!ValidatePositiveInteger(number)); // 👈 argument is written so that it evaluates to TRUE when the condition is INVALID. Hence, the ! sign.

	return number;
	// Note: the lines above are to be sequentially written line by line. 
	// at the end implement the two functions: ReadNumber() & ValidatePositiveInteger()
}

int CalculateSumOfOddNumbers(int number) // passing by value.
{
	int sum = 0;

	for (int i = 1; i <= number; i++)
	{
		if (i % 2 == enEvenOrOdd::Odd)  // 👈👈👈 unoptimized as the "i % 2" portion should be placed in a function of its own (no matter how small it is).. Divide & Conquer / فرق تسد
		{
			sum = sum + i;
		}	
	}

	return sum;
}


void PrintSumOfOddNumbers(const int &sum) // passing by constant reference.
{
	cout << "The sum of the odd numbers for 1 to N is " << sum << endl;
}

int main()
{
	// enEvenOrOdd EvenOrOdd; // the next natural step of creating a variable of this enum user-defined data type.  // commenting it out as it turned out that it has no use.

	PrintSumOfOddNumbers(CalculateSumOfOddNumbers(ReadPositiveInteger()));


	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// B- The OPTMIZED approach:
//
// If enums are to be used, then they coded FIRST on top & before anything else.
// the utiliztation of enums, in here, may not necessarily follow the regular enum workflow mental model.
//enum enEvenOrOdd { Even = 0, Odd = 1 };  // Even & Odd are enumeration constants (enumerators) acting as labels for the raw integers.
// so far we've created nothing but an enum user-defined data type. That's all.

int ReadNumber()
{
	int number; // what's returned.

	cout << "Enter a positive integer: ";
	cin >> number;
	cout << endl;

	return number;
}

bool ValidatePositiveInteger(int number) // passing by value.
{
	return (number > 0);
}

int ReadPositiveInteger()
{
	int number; // what's returned
	do
	{
		number = ReadNumber(); // 'number' to be IMMEDIATELY validated against the range in the condition.

	} while (!ValidatePositiveInteger(number)); // 👈 argument is written so that it evaluates to TRUE when the condition is INVALID. Hence, the ! sign.

	return number;
	 Note: the lines above are to be sequentially written line by line. 
	 at the end implement the two functions: ReadNumber() & ValidatePositiveInteger()
}

enEvenOrOdd CheckEvenOrOdd(const int &i) // passing by constant reference.
{
	if (i % 2 == 1)
	{
		return enEvenOrOdd::Odd;
	}
	else
	{
		return enEvenOrOdd::Even;
	}

}

int CalculateSumOfOddNumbers(int number) // passing by value.
{
	int sum = 0; // routine

	for (int i = 1; i <= number; i++) // for-loops is the best and cleanest approach since the number of iterations is known beforehand.
	{
		if (CheckEvenOrOdd(i) == enEvenOrOdd::Odd)  // 👈👈👈 unoptimized as the "i % 2" portion should be placed in a function of its own (no matter how small it is).. Divide & Conquer / فرق تسد
		{
			sum += i;
		}
	}

	return sum;
}

int CalculateSumOfOddNumbers(int number) // passing by value.
{
	int sum = 0; // routine


	int i = 1;         // 1st step to write.
	while (i <= number)  //2nd step to write.
	{
		if (CheckEvenOrOdd(i) == enEvenOrOdd::Odd)   // LAST step to write along with the body.
		{
			sum += i;
		}

		i++;  // 3rd step to write.
	}
	return sum;
}

int CalculateSumOfOddNumbers(int number) // passing by value.
{
	int sum = 0; // routine

	int i = 1;    // 1st step to write.
	do
	{
		sum += i;          // LAST step to write.
		i++;           // 2nd step to write

	} while (i <= number);  // 3rd step to write

	return sum;
}


void PrintSumOfOddNumbers(const int &sum) // passing by constant reference.
{
	cout << "The sum of the odd numbers for 1 to N is " << sum << endl;
}

int main()
{
	 enEvenOrOdd EvenOrOdd; // the next natural step of creating a variable of this enum user-defined data type.  // commenting it out as it turned out that it has no use.

	PrintSumOfOddNumbers(CalculateSumOfOddNumbers(ReadPositiveInteger()));


	return 0;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// again: The cleanest and the most optimized approach is utilizing the for-loops:
//
//
//// Below- A solution showcasing the utilization of the 3 loops types: The for-loops, the while-loop, & the do..while() loop




// If enums are to be used, then they coded FIRST on top & before anything else.
// the utiliztation of enums, in here, may not necessarily follow the regular enum workflow mental model.
enum enEvenOrOdd { Even = 0, Odd = 1 };  // Even & Odd are enumeration constants (enumerators) acting as labels for the raw integers.
// so far we've created nothing but an enum user-defined data type. That's all.

int ReadNumber()
{
	int number; // what's returned.

	cout << "Enter a positive integer: ";
	cin >> number;
	cout << endl;

	return number;
}

bool ValidatePositiveInteger(int number) // passing by value.
{
	return (number > 0);
}

int ReadPositiveInteger()
{
	int number; // what's returned
	do
	{
		number = ReadNumber(); // 'number' to be IMMEDIATELY validated against the range in the condition.

	} while (!ValidatePositiveInteger(number)); // 👈 argument is written so that it evaluates to TRUE when the condition is INVALID. Hence, the ! sign.

	return number;
	// Note: the lines above are to be sequentially written line by line. 
	// at the end implement the two functions: ReadNumber() & ValidatePositiveInteger()
}

enEvenOrOdd CheckEvenOrOdd(const int& i) // passing by constant reference.
{
	if (i % 2 == 1)
	{
		return enEvenOrOdd::Odd;
	}
	else
	{
		return enEvenOrOdd::Even;
	}

}

int CalculateSumOfOddNumbers_UsingForLoops(int number) // passing by value.
{
	cout << "Solving utilizing For-loops: \n";



	int sum = 0; // routine

	for (int i = 1; i <= number; i++) // for-loops is the best and cleanest approach since the number of iterations is known beforehand.
	{
		if (CheckEvenOrOdd(i) == enEvenOrOdd::Odd)  // 👈👈👈 unoptimized as the "i % 2" portion should be placed in a function of its own (no matter how small it is).. Divide & Conquer / فرق تسد
		{
			sum += i;
		}
	}

	return sum;
}

int CalculateSumOfOddNumbers_UsingWhileLoops(int number) // passing by value.
{
	cout << "Solving utilizing While-Loops: \n";


	int sum = 0; // routine


	int i = 1;         // 1st step to write.
	while (i <= number)  //2nd step to write.
	{
		if (CheckEvenOrOdd(i) == enEvenOrOdd::Odd)   // LAST step to write along with the body.
		{
			sum += i;
		}

		i++;  // 3rd step to write.
	}
	return sum;
}

int CalculateSumOfOddNumbers_UsingDoWhileLoops(int number) // passing by value.
{
	cout << "Solving utilizing Do..While-Loops: \n";


	int sum = 0; // routine

	int i = 1;    // 1st step to write.
	do
	{
		
		if (CheckEvenOrOdd(i) == enEvenOrOdd::Odd)
		{
			sum += i;
		}

		i++;           // 2nd step to write

	} while (i <= number);  // 3rd step to write

	return sum;
}


void PrintSumOfOddNumbers(const int& sum) // passing by constant reference.
{
	cout << "The sum of the odd numbers for 1 to N is " << sum << endl << endl;
}

int main()
{
	// enEvenOrOdd EvenOrOdd; // the next natural step of creating a variable of this enum user-defined data type.  // commenting it out as it turned out that it has no use.

	int N = ReadPositiveInteger();

	PrintSumOfOddNumbers(CalculateSumOfOddNumbers_UsingForLoops(N));
	PrintSumOfOddNumbers(CalculateSumOfOddNumbers_UsingWhileLoops(N));
	PrintSumOfOddNumbers(CalculateSumOfOddNumbers_UsingDoWhileLoops(N));


	return 0;
}



  /******************************************************************************************************************************************************************************************
   ******************************************************************************************************************************************************************************************
   ******************************************* In the case that you're NOT using enums which is DISCOURAGED, then continue below ************************************************************
   ******************************************************************************************************************************************************************************************
   ******************************************************************************************************************************************************************************************/



int ReadNumber()
{
	int number; // what's returned

	cout << "Enter a positive integer: ";
	cin >> number;
	cout << endl;

	return number;
}

bool ValidatePositiveInteger(int number) // passing by value.
{
	return (number > 0);
}

int ReadPositiveInteger()
{
	int number;   // what's returned.
	do
	{
		number = ReadNumber(); // to be IMMEDIATELY validated in the while condition against the range.

	} while (!ValidatePositiveInteger(number)); // the argument is written so that it evaluates to TRUE when the condition is invalid (hence the !)

	return number;
}

// the best and cleanest approach:
int CalculateSumOfOddNumbers(int number) // passing by value.
{
	int sum = 0;

	for (int i = 1; i <= number; i += 2)   
	{
		sum += i;
	}
	return sum;
}

//int CalculateSumOfOddNumbers(int number) // passing by value.
//{
//	int sum = 0;
//	
//	int i = 1;            // 1st step to write.
//	while (i <= number)   // 2nd step to write.
//	{
//		sum += i;   // LAST step 
//		i += 2;         // 3rd step.
//	}
//	
//	return sum;
//}

//int CalculateSumOfOddNumbers(int number) // passing by value.
//{
//	int sum = 0;
//	
//	int i = 1;   // 1st step to write.
//	do
//	{
//		sum += i;;  // LAST step to write.
//		i += 2;         // 2nd step to write.
//
//	} while (i <= number);   // 3rd step to write.
//
//	return sum;
//}

void PrintSumOfOddNumbers(const int &sum) // passing by constant reference.
{
	cout << "The sum of the odd numbers is: " << sum << endl;
}

int main()
{
   
	PrintSumOfOddNumbers(CalculateSumOfOddNumbers(ReadPositiveInteger()));

	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// again: The cleanest and the most optimized approach is utilizing the for-loops:


// Below- A solution showcasing the utilization of the 3 loops types: The for-loops, the while-loop, & the do..while() loop
// BAD FORMATTING- IMPROVE IT.


int ReadNumber()
{
	int number; // what's returned

	cout << "Enter a positive integer: ";
	cin >> number;
	cout << endl;

	return number;
}

bool ValidatePositiveInteger(int number) // passing by value.
{
	return (number > 0);
}

int ReadPositiveInteger()
{
	int number;   // what's returned.
	do
	{
		number = ReadNumber(); // to be IMMEDIATELY validated in the while condition against the range.

	} while (!ValidatePositiveInteger(number)); // the argument is written so that it evaluates to TRUE when the condition is invalid (hence the !)

	return number;
}

// the best and cleanest approach:
int CalculateSumOfOddNumbers_UsingForLoops(int N) // passing by value.
{
	cout << "Solving via For-Loops: \n";


	int sum = 0;

	for (int i = 1; i <= N; i += 2)
	{
		sum += i;
	}
	return sum;

}

int CalculateSumOfOddNumbers_UsingWhileLoop(int N) // passing by value.
{
	cout << "Solving via While-Loops: \n";


	int sum = 0;
	
	int i = 1;            // 1st step to write.
	while (i <= N)   // 2nd step to write.
	{
		sum += i;   // LAST step 
		i += 2;         // 3rd step.
	}
	
	return sum;

}

int CalculateSumOfOddNumbers_UsingDoWhileLoop(int N) // passing by value.
{
	cout << "Solving via Do..While loop: \n";


	int sum = 0;
	
	int i = 1;   // 1st line to write
	do
	{
		sum += i;    // LAST line to write.
		i += 2;    // 2nd line to write

	} while (i <= N);  // 3rd line to write

	return sum;

}

void PrintSumOfOddNumbers(const int& sum) // passing by constant reference.
{
	cout << " \nThe sum of the odd numbers is: " << sum << endl;
}

int main()
{

	int N = ReadPositiveInteger();

	PrintSumOfOddNumbers(CalculateSumOfOddNumbers_UsingForLoops(N));
	PrintSumOfOddNumbers(CalculateSumOfOddNumbers_UsingWhileLoop(N));
	PrintSumOfOddNumbers(CalculateSumOfOddNumbers_UsingDoWhileLoop(N));
	
	

	return 0;
}






// the NON-optimized solution that iterates over ALL numbers (discouraged)
int CalculateSumOfOddNumbers(int number) // passing by value.
{
	int sum = 0;

	for (int i = 1; i <= number; i++)   // the optimized solution instead of utilizing the remainder where i increments by 1.
	{
		if (i % 2 == 1)   // 👈👈👈 nevertheless, i % 2  needs to be wrapped inside a function- Divide & conquer ALWAYS
		{
			sum += i;
		}
	}
	return sum;
}
