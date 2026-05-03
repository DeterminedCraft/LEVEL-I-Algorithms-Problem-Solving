

#include <iostream>
using namespace std;

/*
 Problem #11:

 Write a program to ask the user to enter:
 - Mark1, Mark2, Mark3

 Then print the Average of entered Marks, and print "PASS" if average >= 50,
 otherwise print "FAIL".

 Example Inputs:
 90
 80
 70

 Outputs:
 80
 PASS

*/

/* Solution:
   This problem is solved utilizing arrays. The utilization of structures would be considered primitive in comparison.
   For practice purposes, I'll incorporate enums in solving this problem. Thus, the workflow might not reflect the enums mental model documented in the C++ course.

*/



// Nonetheless- I will start solving this problem utilizing mere variables instead of the correct solution with arrays.
//  CRUCIAL: This way (my way) of solving this problem is the CORRECT one as comapred to that of the mo3alem becasue I've made use of فَرِّقْ تَسُدْ/ Divide & conquer to the MAX, logically.
// If enums are to be utilized in any program, then ALWAYS code them first.

enum enPassOrFail { Pass = 1, Fail = 0 }; //Enumeration constants (enumerators) acting as labels for the integral raw numbers they represent.
// so from now and on, forget about these raw numbers.
// so far, nothing has been created but an enum user-defined data type. The next natural step is declaring a variable of it.


void ReadMarks(float& Mark1, float& Mark2, float& Mark3) // pass by reference.
{
	cout << "Enter the first mark: ";
	cin >> Mark1;
	cout << endl;

	cout << "Enter the second mark: ";
	cin >> Mark2;
	cout << endl;

	cout << "Enter the third mark: ";
	cin >> Mark3;
	cout << endl;
}

float CalculateMarksSum(float Mark1, float Mark2, float Mark3)
{
	return Mark1 + Mark2 + Mark3;
}

float CalculateAverageMark(float Mark1, float Mark2, float Mark3) // pass by value.
{
	return CalculateMarksSum(Mark1, Mark2, Mark3) / 3;   // NOT an integer divisions as marks are floats.
}

enPassOrFail PassOrFail(const float& average)  // pass by constant reference.
{
	if (average >= 50)
	{
		return enPassOrFail::Pass;  // 1 of data type enPassOrFail is what's returned.
	}
	else
	{
		return enPassOrFail::Fail;  // 0 of data type enPassOrFail is what's returned.
	}
}

string DetermineResult(const enPassOrFail& result) // pass by const reference.
{
	if (result == enPassOrFail::Pass)
	{
		return "PASS";
	}
	else
	{
		return "FAIL";
	}
}

void PrintResult(const float& average) // pass by constant reference.
{
	cout << "The average is " << average << " . The result is: " << DetermineResult(PassOrFail(average));
}

int main()
{
	//enPassOrFail PassorFail; // the natural step of declaring a variable of this enum user-defined data type. // commented out as it turned out it's not needed.

	float Mark1, Mark2, Mark3;
	// Initializing these 3 variables via reading user input:

	ReadMarks(Mark1, Mark2, Mark3);
	// theese 3 variables are now initialized


	PrintResult(CalculateAverageMark(Mark1, Mark2, Mark3)); // as the CalculateAverageMark() function contains CalculateSum()/3. Hence, Mark1, Mark2, Mark3 are passed as arguments.

	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Solution utilizing arrays:
unsigned const short NumberOfElements = 3; // It was later discovered that this variable has to be a global one.

// If enums are to be utilized in any program, then it's to be coded first and is always on top.
//enum enPassOrFail { Pass = 1, Fail = 0}; // enumeration constants (enumerators) acting as labels for the raw data they represent
                                         // thus, no need to remember the integral values of these raw data as only labels are dealt with.
// so far, only an enum user-defined data type has been created. Nothing else.
// The next natural step is creating a variable of this enum user-defined data type.


void ReadMarks(float marks[NumberOfElements]) // array are ALWAYS + ONLY passed by reference. Also, Including the '&' renders an exception.
{
	for (int i = 0; i < NumberOfElements; i++)
	{
		cout << "Enter Mark " << i + 1 << " : ";
		cin >> marks[i];
		cout << endl;
	}
}

float CalculateSumOfMarks(const float marks[NumberOfElements]) // passing by value  //CRUCIAL: the added 'const' is because:  Look at the calling function in main() (that simple)
{
	float sum = 0;
	for (int i = 0; i < NumberOfElements; i++)
	{
		sum += marks[i];
	}
	return sum;
}

float CalculateAverageMark(float sum) // passing by value.
{
	return sum / 3; // will NOT be an integer division since 'sum' stores a float value (ex: 80.0f)
}



void PrintPassOrFail(const float marks[NumberOfElements]) // passing by const ref.  Also, Including the '&' renders an exception.
{

}

bool IsPassed(float AverageMark)
{
	return (AverageMark >= 50);
}


void PrintAverageMark(float AverageMark)
{
	
	cout << "The average = " << AverageMark << endl;
}


void PrintPassOrFail(float AverageMark)  // passing by constant reference.
{
	if (IsPassed(AverageMark))
	{
		cout << "Passed \n";
	}
	else
	{
		cout << "Failed \n";
	}
}


void PrintResults(const float marks[NumberOfElements]) // passing by ref.  Also, Including the '&' renders an exception. // inside we could have a printing structure.
{
	float AverageMark = CalculateAverageMark(CalculateSumOfMarks(marks));

	PrintAverageMark(AverageMark);
	PrintPassOrFail(AverageMark);

}

int main()
{
	//enPassOrFail PassOrFail; // Declaring a variable of this enum user-defined data type.

	float marks[NumberOfElements];
	// Initializing this array variable 'marks' via reading user-input. (remember, no array can be returned by a function as a function returns ONE value ONLY).
		//This has to be done via a reading procedure, where the param is passed by reference,
	    //so that the variable declared in main() in initialized so that we are able to continue coding in main().

	ReadMarks(marks); // In this called procedure, the passed argument is an array. Arrays are passed automatically along with their address in memory
	                  // thus, the param in the implementing function is ALWAYS passed by reference. And the & sign in not included.

	// The array variable 'marks' has been initialized.


	PrintResults(marks);
	return 0;

	
	

}


