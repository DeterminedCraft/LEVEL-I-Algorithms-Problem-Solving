
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



// this is the OPTIMIZED CORRECT VERSION:

// This problem is solved using enums
// since the remainer will either be 0 or something else.
// where 0 indicates an even number & any other value that's not zero represents an odd number.
// where this 0 and the other value are not involved in any other arithmetic operations.

// since enums are used, then they are to BE CODED FIRST in the program.
// since the use of enums here is not conventional, then the enum work flows or mental model
// may not all apply.





enum enEvenOrOdd { Even = 0, Odd = 1 };   // the enumeration constants (enumerators) that are Even & Odd, act as labels for the raw integral values they represent
// so from now and on, FOREVER forget about these raw values and ALWAYS deal with the enumration constants (enumerators) acting as labels.
// 
// so far, only an enum user-defined data type has been created and nothing else !
// the enxt natural step is creating a variable of this enum user-defined data type inside main()




int ReadIntegerNumber(const string& message)   // pass by constant reference
{
	int number;  // what's returned

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}

bool ValidatePositiveInteger(const int& number)    // pass by constant reference since wee^re comparing
{
	return (number > 0);
}


int ReadPositiveInteger(const string& message)    // pass by constant reference.
{
	int number; // what's returned     // declared outside the do statement and on the function level/scope so that it can be returned by the function

	do
	{
		number = ReadIntegerNumber(message); // 'number' is to be IMMEDIATELY compared against the range, in the while condition.

	} while (!ValidatePositiveInteger(number));   // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

	return number;
	// The above block of code is to be sequentially composed line by line
	// and at the end, implement the functions of:   ReadIntegerNumber()   &    ValidatePositiveInteger()
}

enEvenOrOdd RemainderOfI(int i)  // pass by value
{
	if (i % 2 == 0)
	{
		return enEvenOrOdd::Even;    // returns 0 (of data type enEvenOrOdd).
	}
	else
	{
		return enEvenOrOdd::Odd;   // returns 1 (of data type enEvenOrOdd)
	}
}


int CalculateSumOfOddNumbers(int number)   // pass by value
{
	int sum = 0;   // routine   // what's returned.

	for (int i = 1; i <= number; i++)     // using the i+=2 concept, will not enable us to take advantage of the enums concept.
	{
		if (RemainderOfI(i) == enEvenOrOdd::Odd)    // i % 2   
		{
			sum = sum + i;
		}
	}

	return sum;
}  //The cleanest and the most optimized approach is utilizing the for - loops:

//// using while loop:
//int CalculateSumOfOddNumbers(int number)   // pass by value
//{
//	int sum = 0;   // routine   // what's returned.
//
//
//	int i = 1;     // 1st step to write
//	while (i <= number)    // 2nd step to write
//	{
//		if (RemainderOfI(i) == enEvenOrOdd::Odd)
//		{
//			sum = sum + i;
//		}
//
//		i++;     //3rd step to write  (using the i+=2 won't enable us to take advantage of the enum concept).
//	}
//
//	return sum;
//}

////  using do..while loop:
//int CalculateSumOfOddNumbers(int number)   // pass by value
//{
//	int sum = 0;  //routine   // what's returned.
//
//	int i = 1;     /// 1st step to write
//	do
//	{
//		if (RemainderOfI(i) == enEvenOrOdd::Odd)       // the last step to write.
//		{
//			sum = sum + i;
//		}
//
//		i++;   // 2nd step to write    // the use of i+=2 won't enable us to take advantage of the enum concept.    
//
//	} while (i <= number);      // the 3rd step to write
//
//	return sum;
//}



void PrintSumOfOddNumbers(const int& number)    // pass by constant reference.
{
	cout << "The sum of all odd numbers from 1 to " << number << " = " << CalculateSumOfOddNumbers(number) << endl;
}


int main()
{

	//enEvenOrOdd EvenOrOdd; // the next natural step of creating a variable of the enum user-defined data type.  // commented out as it turned out later that it was not needed.

	PrintSumOfOddNumbers(ReadPositiveInteger("Enter a positive integer: "));   // range(s) NOT included as their value is NOT intrinsic.   //ReadPositiveNumber() HAS to be a function as procedure returns void = renders exception here.
	// this printing procedure is designed so that it contains CalculateSumOfOddNumber(). 
	// this is the standard way of coding. Also, separately, the printing procedure will have access to the positive integer the user prompted to enter.


	return 0;
}









///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// This version IS NOT OPTIMIZED as it does NOT USE ENUMS

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int ReadIntegerNumber(const string& message)   // pass by constant reference
{
	int number;  // what's returned

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}

bool ValidatePositiveInteger(const int& number)    // pass by constant reference since wee^re comparing
{
	return (number > 0);
}


int ReadPositiveInteger(const string& message)    // pass by constant reference.
{
	int number; // what's returned     // declared outside the do statement and on the function level/scope so that it can be returned by the function

	do
	{
		number = ReadIntegerNumber(message); // 'number' is to be IMMEDIATELY compared against the range, in the while condition.

	} while (!ValidatePositiveInteger(number));   // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

	return number;
	// The above block of code is to be sequentially composed line by line
	// and at the end, implement the functions of:   ReadIntegerNumber()   &    ValidatePositiveInteger()
}


int CalculateSumOfOddNumbers(int number)  // pass by value
{
	int sum = 0;   // routine   // what's returned

	for (int i = 1; i <= number; i+=2)      // using the optimized version (without utilizing the remainnder aspect).
	{
		sum = sum + i;
	}

	return sum;
}

//// solving with remainders:
/*
int CalculateRemainderOfI(int i)  // pass by value
{
	return (i % 2);
}

int CalculateSumOfOddNumbers(int number)  // pass by value
{
	int sum = 0; // routine   // what's returned.

	for (int i = 1; i <= number; i++)
	{
		if (CalculateRemainderOfI(i) != 0)     // Farrik Tasud !  // (i % 2)     no matter how small and short this line is, ALWAYS wrap it inside a function.
		{
			sum += i;      //sum = sum + i;
		}
	}

	return sum;
}
*/ 


//// using while-loop:
//int CalculateSumOfOddNumbers(int number)  // pass by value
//{
//	int sum = 0; //routine     // what's returned.
//
//	int i = 1;       // 1st to write
//	while (i <= number)  // 2nd to write
//	{
//		sum = sum + i;    // LAST STEP to write.
//
//		i += 2;   // 3rd to write
//	}
//
//	return sum;
//}


//// using do..while loop:
//int CalculateSumOfOddNumbers(int number)  // pass by value
//{
//	int sum = 0;  // routine   // what's returned.
//
//	int i = 1;
//	do
//	{
//		sum = sum + i;
//
//		i += 2;
//
//	} while (i <= number);
//
//	return sum;
//}





// solving with remainders:
/*
int CalculateRemainderOfI(int i)  // pass by value
{
	return (i % 2);
}

int CalculateSumOfOddNumbers(int number)  // pass by value
{
	int sum = 0; // routine   // what's returned.

	for (int i = 1; i <= number; i++)
	{
		if (CalculateRemainderOfI(i) != 0)     // Farrik Tasud !  // (i % 2)     no matter how small and short this line is, ALWAYS wrap it inside a function. 
		{
			sum += i;      //sum = sum + i;
		}
	}

	return sum;
}
*/

void PrintSumOfOddNumbers(const int& number)    // pass by constant reference
{
	cout << "The sum of the odd numbers from 1 to " << number << " is: " << CalculateSumOfOddNumbers(number) << endl;
}

int main()
{

	PrintSumOfOddNumbers(ReadPositiveInteger("Enter a positive integer: "));   // ranges NOT included as their value is NOT intrinsic.    // ReadPositiveInteger() has to be a function as procedures return void ( a void argument renders exception)
	// this printing procedure is designed so that, it contains the function CalculateSumOfOddNumbers()
	// this is the standard way of coding. Also, as a result (a separate aspect), 
	// this printing procedure can reference the original value the user entered.

	return 0;
}












///////////////////////////////////////// SOME OLD & UNOPTIMIZED SOLUTIONS ////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////// SOME OLD & UNOPTIMIZED SOLUTIONS ////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////// SOME OLD & UNOPTIMIZED SOLUTIONS ////////////////////////////////////////////////////////////////////////////


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
