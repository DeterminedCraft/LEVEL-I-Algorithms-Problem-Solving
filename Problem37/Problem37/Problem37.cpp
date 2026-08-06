

#include <iostream>
using namespace std;

/* Problem #37:

 Write a program to read numbers from the user and sum them.
 Keep reading numbers until the user enters -99,
 then print the sum on the screen.

  Example Input:
  10
  20
  30
  40
  -99

  Output:
  100

*/


int const NumberOfElements = 100;

double ReadDoubleNumber(const string& message)     // pass by constant reference.
{
	double number; // what's returned.

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}

bool ValidateNumberInRange(const double& number, double min, double max)    // pass by constant reference since 'number' is going to only be compared against ranges
{
	return (min <= number && number <= max);
}


void ReadNumbersInRange(const string& message, double min, double max, double numbers[NumberOfElements], int &counter) // the array variable is ALWAYS passed by ref. (Including the & sign renders exception).
{   
	counter = 0; // turned out later that such a thing was needed.

	for (int i = 0; i < NumberOfElements; i++)
	{
	
		bool IsValid;
		do
		{
			numbers[i] = ReadDoubleNumber(message); // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

			if (numbers[i] == -99)
			{
				return;     // controller exists the reading procedure.
			}

			IsValid = ValidateNumberInRange(numbers[i], min, max);
			if (!IsValid)
			{
				cout << "The number entered must be between " << min << " & " << max << ". ";
			}

		} while (!IsValid); // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

		counter++;    // counts the number of saved inputs.
          
	}
	// Note: the above block of code is to be sequentially composed line by line
	//       and at the end, implement the functions of:   ReadDoubleNumber   && ValidateNumberInRang

}

// The solution is via utilizing vectors. 
// Nontheless since vectors haven't been yet introduced, an array (fixed-length data structure) will be used.


double CalculateSum(double numbers[NumberOfElements], int counter)   // automatically passed by ref. (including the & renders exception)
{
	double sum = 0;  // routine  // what's returned

	for (int i = 0; i < counter; i++)
	{
		sum = sum + numbers[i];
	}

	return sum;
}

void PrintSum( double numbers[NumberOfElements], const int &counter)   // passed by constant ref. (Including the & sign renders exception).
{
	cout << "The sum is (excluding -99) is: " << CalculateSum(numbers, counter) << endl;   // numbers is passed along its address in memory. Hence, in the implementation it's always passed by reference
}


int main()
{
	double min = -1000000;
	double max =  1000000;
	int counter = 0;  // turned out later that it was needed.

	double numbers[NumberOfElements] = {};   // initializes the whole array to zero (instead of the elements of the array, each being initialized to a garbage value)
	// without doing this, the sum of the entered numbers will not be correct because all the hundred values will be added together even if the user enters 2 or 10 values 
	// or less than 100 values entered given that the Number of elements of the declared array is 100.
	// Also: when declaring the array, the number of elements is required.
	

	ReadNumbersInRange("Enter number: ", min, max, numbers, counter);  // the array argument is passed along with it's address in memory automatically. Therefore, it's implementing parameter is ALWAYS passed by ref.
	// the array variable 'numbers' is now initialized.

	
	PrintSum(numbers, counter); // 'numbers' is automatically passed along with it's address in memory. Hence, the implementing function's parameter corresponding to 'numbers' is automatically passed by ref.
	                   // this printing procedure contains the function CalculateSum()
	                   // this is a standard coding practice.
	                  // also, as a 'side effect', this printing procedure will have access to the original values entered by the user.
	return 0;
}







/////////////////////////////////////////////////////////////// Another approach to this problem: ///////////////////////////////////////////////
/////////////////////////////////////////////////////////////// Another approach to this problem: ///////////////////////////////////////////////
/////////////////////////////////////////////////////////////// Another approach to this problem: ///////////////////////////////////////////////


int const NumberOfElements = 100;

double ReadDoubleNumber(const string& message)     // pass by constant reference.
{
	double number; // what's returned.

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}

bool ValidateNumberInRange(const double& number, double min, double max)    // pass by constant reference since 'number' is going to only be compared against ranges
{
	return (min <= number && number <= max);
}


void ReadNumbersInRange(const string& message, double min, double max, double numbers[NumberOfElements], int& counter) // the array variable is ALWAYS passed by ref. (Including the & sign renders exception).
{
	counter = 0; // turned out later that such a thing was needed.

	for (int i = 0; i < NumberOfElements; i++)
	{

			numbers[i] = ReadDoubleNumber(message); // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

			if (numbers[i] == -99)
			{
				return;     // controller exists the reading procedure.
			}

			
		   while (!ValidateNumberInRange(numbers[i], min, max)) // the argument is written so that, it evaluates to TRUE when the condition is INVALID.
		   {
			  cout << "Number must be between " << min << " & " << max << " ." << endl;

			  numbers[i] = ReadDoubleNumber(message); // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

			   if (numbers[i] == -99)
			   {
			    	 return;     // controller exists the reading procedure
			   }
		   }

		   counter++;

	}
	// Note: the above block of code is to be sequentially composed line by line
	//       and at the end, implement the functions of:   ReadDoubleNumber   && ValidateNumberInRang

}

// The solution is via utilizing vectors. 
// Nontheless since vectors haven't been yet introduced, an array (fixed-length data structure) will be used.


double CalculateSum(double numbers[NumberOfElements], int counter)   // automatically passed by ref. (including the & renders exception)
{
	double sum = 0;  // routine  // what's returned

	for (int i = 0; i < counter; i++)
	{
		sum = sum + numbers[i];
	}

	return sum;
}

void PrintSum(double numbers[NumberOfElements], const int& counter)   // passed by constant ref. (Including the & sign renders exception).
{
	cout << "The sum is (excluding -99) is: " << CalculateSum(numbers, counter) << endl;   // numbers is passed along its address in memory. Hence, in the implementation it's always passed by reference
}


int main()
{
	double min = -1000000;
	double max = 1000000;
	int counter = 0;  // turned out later that it was needed.

	double numbers[NumberOfElements] = {};   // initializes the whole array to zero (instead of the elements of the array, each being initialized to a garbage value)
	// without doing this, the sum of the entered numbers will not be correct because all the hundred values will be added together even if the user enters 2 or 10 values 
	// or less than 100 values entered given that the Number of elements of the declared array is 100.
	// Also: when declaring the array, the number of elements is required.


	ReadNumbersInRange("Enter number: ", min, max, numbers, counter);  // the array argument is passed along with it's address in memory automatically. Therefore, it's implementing parameter is ALWAYS passed by ref.
	// the array variable 'numbers' is now initialized.


	PrintSum(numbers, counter); // 'numbers' is automatically passed along with it's address in memory. Hence, the implementing function's parameter corresponding to 'numbers' is automatically passed by ref.
	// this printing procedure contains the function CalculateSum()
	// this is a standard coding practice.
   // also, as a 'side effect', this printing procedure will have access to the original values entered by the user.
	return 0;
}
























