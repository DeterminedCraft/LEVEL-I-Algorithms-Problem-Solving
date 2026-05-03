
#include <iostream>
using namespace std;

/*
 Problem #26:
 Write a program to print numbers from 1 to N.

 Input
 10

 Outputs →
 1
 2
 3
 4
 5
 6
 7
 8
 9
 10

*/

int ReadNumber()
{
	int number; // what's returned

	cout << "Enter a positive Integer: ";
	cin >> number;
	cout << endl;

	return number;
}

bool ValidatePositiveInt(int number) // passing by value.
{
	return (number > 0);
}


int ReadPositiveInt()
{
	int number; // what's returned       // written outside the 'do' so that it can be returned.
	do
	{
		number = ReadNumber();  // number is IMMEDIATELY range validated in the while condition

	} while (!ValidatePositiveInt(number)); // the argument is written so that it evaluates to TRUE when the condition is INVALID (hence the !)

	return number;
	// Note: Write the entire above function's lines and later, implement the functions:     ReadNumber() & ValidatePositiveNumber()
}

void PrintFrom1ToN(const int &number)  //passing by constant reference.
{
	for (int i = 1; i <= number; i++)   // ENCOURAGED: start from i=0 when you are utilizing indexes in the body such as x[i]
	{
		cout << i  << endl;
	}
}

//// or: (Note that, the for-loops is the BEST way to solve this question as range or number of repititions is ALREADY KNOWN)
//void PrintFrom1ToN(const int &number)  //passing by constant reference.
//{
//	int i = 1;            // 1st step to write
//	while (i <= number)  // 2nd step to write
//	{
//		cout << i << endl;
//
//		i++;      // 3rd step to write
//	}
//}
//
//
//// or:
//void PrintFrom1ToN(const int &number)  //passing by constant reference.
//{
//	int i = 1; 
//	do
//	{
//		
//		cout << i << endl;
//		i++;
//
//	} while(i <= number);
//}


int main()
{
  
	PrintFrom1ToN(ReadPositiveInt()); // ReadNumber() HAS to be a function. As procedures return void; rendering an exception on this nested functions line.

	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// so you solve it just as shown above.
// 
// 
// 
// 
// Nonetheless, 
// to clearly show the solution using the for-loops, while-loop, & do..while() loop:

int ReadNumber()
{
	int number; // what's returned

	cout << "Enter a positive Integer: ";
	cin >> number;
	cout << endl;

	return number;
}

bool ValidatePositiveInt(int number) // passing by value.
{
	return (number > 0);
}


int ReadPositiveInt()
{
	int number; // what's returned       // written outside the 'do' so that it can be returned.
	do
	{
		number = ReadNumber();  // number is IMMEDIATELY range validated in the while condition

	} while (!ValidatePositiveInt(number)); // the argument is written so that it evaluates to TRUE when the condition is INVALID (hence the !)

	return number;
	// Note: Write the entire above function's lines and later, implement the functions:     ReadNumber() & ValidatePositiveNumber()
}

void PrintFrom1ToN_UsingForLoops(const int &N)  //passing by constant reference.
{
	cout << "Printing from 1 to " << N << " using for-loops: \n";

	for (int i = 1; i <= N; i++)   // start from i=0 when you are utilizing indexes in the body such as x[i]
	{
		cout << i << endl;
	}
	
	cout << "\n";
}


void PrintFrom1ToN_UsingWhileLoop(const int &N)  //passing by constant reference.
{
	cout << "Printing for 1 to " << N << " using the While loop: \n";


	int i = 1;            // 1st step to write       
	while (i <= N)  // 2nd step to write
	{
		cout << i << endl;   // LAST step to write.

		i++;      // 3rd step to write
	}

	cout << "\n";
}


void PrintFrom1ToN_UsingDoWhileLoop(const int &N)  //passing by constant reference.
{
	cout << "Printing for 1 to " << N << " Using the Do..While loop: \n";


	int i = 1; 
	do
	{
		
		cout << i << endl;
		i++;

	} while(i <= N);

	cout << "\n";
}


int main()
{
	// so I just want to read the number one time ONLY, and generate the exact solution 3 times consecutively
	// first solution is outputed with for-loops, and the rest with while-loop and do..while() loop
	int N = ReadPositiveInt();

	PrintFrom1ToN_UsingForLoops(N);  // the for-loops is the BEST way to solve this question as range or number of repititions is ALREADY KNOWN
	PrintFrom1ToN_UsingWhileLoop(N);
	PrintFrom1ToN_UsingDoWhileLoop(N);

	return 0;

	/* unoptimized version (UNLESS you want to be asked to enter a number 3 times, 
	   with each time displaying 1 to N using a different type of loop
	
	 PrintFrom1ToN_UsingForLoops(ReadPositiveInt()); 
	 PrintFrom1ToN_UsingWhileLoop(ReadPositiveInt());
	 PrintFrom1ToN_UsingDoWhileLoop(ReadPositiveInt());

	 
	
	*/
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  Foundational Notes:

  The goal is to READ LINE BY LINE: ALL of these 4 code snippets are 100 % CORRECT & VALID:

  #######1 The do..while loop:                   */


   
 void PrintRangeFrom1toN_UsingDoWhile(int N)
 {
	 int Counter = 0;

	 cout << "Range printed using Do..While Statement:\n";

	 do
	 {
	 	Counter++;
	 	cout << Counter << endl;

	 } while (Counter < N);
 }

 // VS :

 void PrintFrom1ToN_UsingDoWhileLoop(const int &N)
 {
	 cout << "Printing for 1 to " << N << " Using the Do..While loop: \n";

	 int i = 1;
	 do
	 {
	 	cout << i << endl;
	 	i++;

	 } while(i <= N);

	 cout << "\n";
 }



 /*

 #######2 The While loop:                   */


void PrintRangeFrom1toN_UsingWhile(int N)
{
	int Counter = 0;

	cout << "Range printed using While Statement:\n";

	while (Counter < N)
	{
		Counter++;
		cout << Counter << endl;
	}
}

// VS:

void PrintFrom1ToN_UsingWhileLoop(const int &N)
{
	cout << "Printing for 1 to " << N << " using the While loop: \n";

	int i = 1;
	while (i <= N)
	{
		cout << i << endl;
		i++;
	}

	cout << "\n";
}
















