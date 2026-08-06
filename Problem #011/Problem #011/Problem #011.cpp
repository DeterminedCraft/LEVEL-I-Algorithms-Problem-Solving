

#include <iostream>
using namespace std;
#include <string>

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



/*  solution: 

 enums will be used to solve this example. But since enums isn't the standard approach of solving
 this problem (used in this example to hon in our enum applying skills)
 then, the enum mental model won't fully apply here (for example- the declared variable of the enum user
 defined data type won't be used.

 Now, since enums will be used in this example then it's to be coded first !
 it's always coded first to the point where, if structures are used then the enum data type
 is created first and the structures created below it.


 Secondly, this example should be solved using vectors. Nevertheless, since the concept 
 of vectors hasn't yet been introduced, then we'll solve it using arrays (fixed-length data type):


*/

const unsigned short NumberOfMarks = 3; // turned out it was needed to be declared globally.


enum enPassOrFail { Pass = 1, Fail =0 }; //The enumeration constants (enumerators) that are Pass & Fail act as labels for the raw integral values they represent
// so from now and on FOREVER FORGET about these raw values and always deal with their labels.

// so far nothing has been created but the enum user-defined data type.
// the next natural step is declaring a variable of this enum user defined data type inside main()


float ReadFloatNumber(const string& message)   // pass by constant reference.
{
	float number; // what's returned

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}

bool ValidateMark(const float &mark, float min, float max) // pass by constant ref (adding &, renders exception)  // ranges ALWAYS passed by value.
{
	return (min <= mark && mark <= max);
}

void ReadMarks(const string& message, float min, float max, float marks[NumberOfMarks]) // passed by constant ref.  //ranges ALWAYS passed by val. // arrays AUTOMATICALLY passed by ref (including & renders exception)
{
	for (int i = 0; i < NumberOfMarks; i++)
	{
		do
		{
			marks[i] = ReadFloatNumber(message);  // 'marks[i]' is to be IMMEDIATELY validated against the range, in the while condition.

		} while (!ValidateMark(marks[i], min, max)); 
		
		// Note: The above block is to be sequentially composed line by line, and
		//       at the end, implement the functions of: 
		//       ReadFloatNumber()  & ValidateMark()
    }
}

float CalculateSumOfMarks(float marks[NumberOfMarks]) // automatically passed by reference
{
	float sum = 0; // routine  // what's returned.

	for (int i = 0; i < NumberOfMarks; i++)
	{
		sum = sum + marks[i];
	}

	return sum;
}

float CastToFloatFromUnsignedShort(unsigned short NumberOfMarks)
{
	return float(NumberOfMarks); 
}

float CalculateAverageMark(float sum, unsigned short NumberOfMarks) // pass by value
{
	return sum / CastToFloatFromUnsignedShort(NumberOfMarks);   // this is NOT integer division since both (one value is enough) values store floats.
}

void PrintPassOrFail(const float& AverageMark)  // pass by constant reference.
{

}

bool IsPass(const float& AverageMark)   // pass by constant reference
{
	return (AverageMark >= 50);
}

enPassOrFail DeterminePassOrFail(const float& AverageMark)  // pass by constant reference.
{
	if (IsPass(AverageMark))    // farrik tasud/ Divide & conquer - no matter , how simple this single line is (AverageMark >= 50) , ALWAYS wrap it, in its own function   
	{
		return enPassOrFail::Pass;  // returns 1 of datatype enPassOrFail.
	}
	else
	{
		return enPassOrFail::Fail; // returns 0 of datatype enPassOrFail.
	}
}

void PrintPassOrFail(const float& AverageMark)  // pass by constant reference.
{
	if (DeterminePassOrFail(AverageMark) == enPassOrFail::Pass)  // NOTE: ❌❌ WARNING ❌❌: Having if (DeterminePassOrFail(average)) is WRONG because this argument is of enum user-defined data type													 // whe/re if enum enPassOrFail { Pass = 1, Fail = 0}  has integral values other than 0 and 1 then both are converted to 1
	{                                                            //        and not a bool.
		cout << "Pass \n";
	}
	else
	{
		cout << "Fail \n";
	}
}

void PrintResults(float marks[NumberOfMarks])   // passing by reference. Including the &, yields an exception.
{
	
	float AverageMark = CalculateAverageMark(CalculateSumOfMarks(marks));

	cout << "The average mark is: " << AverageMark << endl;
	
	PrintPassOrFail(AverageMark);
	
	 /*   Not unoptimized solution below:
	 
	  float AverageMark = CalculateAverageMark(CalculateSumOfMarks(marks));
  
	  PrintAverageMark(AverageMark);  // this will contain:     cout << "The average mark is: " << AverageMark << endl;  (It's just a cout referencing a variable; not a function) 
	                                                            , so no need to be inside a printing procedure (that's a convention / rule).
	  PrintPassOrFail(AverageMark);
	 
	 
	 */
}

int main()
{
	enPassOrFail PassOrFail; // the next natural step of declaring a variable of the enum user defined data type.

	float min = 0;  // declared as floats as they will be compared against the entered mark which is of float data type (avoid mixing diff. data types when comparing)
	float max = 100;
	// declare min & max above so that they're not hardcoded in the called function.

	float marks[NumberOfMarks];
	// Initializing the above variable via reading user input (Using a procedure since an array contains more than one element):

	ReadMarks("Enter mark: ", min, max, marks);  // the variable array 'marks' is sent along with its memory address. Therefore, it's implementation will have passing by reference without the & sign.
	// the array variable 'marks' is now initialized.

	PrintResults(marks); // the array variable argument is sent along with its address in memory. Therefore, it's implementation passes by ref without including the & sign.
	                     // this line is written so that, it contains the procedures: printAverage()  & PrintPassOrFail() 
	                     // this is the standard practice. As a by-product, the implementing procedure will have access to the array variable containing the marks that the user entered.


	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////              Below: Older solutions §////////////////////////////////////////////////////////////////////////////////////
//
//
//// solution: solved using vectors instead of declaring three variables.
////           but since the concept of vectors hasn't been introduced yet,
////           I will solve this examples using arrays.
//
//// enums will be used to solve this example. But since enums isn't the standard approach of solving
//// this problem (used in this example to hon in our enum applying skills)
//// then, the enum mental model won't fully apply here (for example- the declared variable of the enum user
//// defined data type won't be used.
//
//// Now, since enums will be used in this example then it's to be coded first !
//// it's always coded first to the point where, if structures are used then the enum data type
//// is created first and the structures created below it.
//
//
//
//
//
//const unsigned short NumberOfMarks = 3; // turned out, at some point, that it has to be global
//
//enum enPassOrFail { Pass = 1, Fail = 0 }; // the enumeration constants (enumerators) that are Pass & Fail act as lables for the raw integral values they represent 
//// so forever forget about these raw integral values and ALWAYS deal with their labels.
//// 
//// so far, only an enum user-defined data type has been created and that's all.
//// the next natural step is declaring a variable of this enum user defined data type INSIDE MAIN().
//
//int counter = 0;
//
//float ReadMark(const string& message)  // pass by constant reference
//{
//	counter++; // turned out it was needed at the end.
//	float number; // what's returned
//
//	cout << message + to_string(counter) + " : ";
//	cin >> number;
//	cout << endl;
//
//	return number;
//}
//
//bool ValidateMarksInRange(float mark, unsigned short min, unsigned short max)
//{
//	return (min <= mark && mark <= max);
//}
//
//void ReadMarksInRange(const string& message, float marks[NumberOfMarks], unsigned short min, unsigned short max) // array automatically passed by reference. Including the & sign renders an exception.
//{                                                                                                                 // ranges AWAYS passed by value.
//	for (int i = 0; i < NumberOfMarks; i++)
// +
//	{
//		do
//		{
//			marks[i] = ReadMark(message); // marks[i] to be IMMEDIATELY validated against the range, in the while condition.
//
//		} while (!ValidateMarksInRange(marks[i], min, max));
//
//	}
//}
//
//float CalculateSum(float marks[NumberOfMarks])
//{
//	float sum = 0;   // routine  // also what's returned.
//	for (int i = 0; i < NumberOfMarks; i++)
//	{
//		sum = sum + marks[i];
//	}
//
//	return sum;
//}
//
//float CalculateAverage(float marks[NumberOfMarks]) // automatically passed by ref. Including the & sign, will render exception.
//{
//	return  CalculateSum(marks) / NumberOfMarks; // is NOT an integer division as CalculateSum() returns float (formatted as, for example, 16.0f, etc.)
//}
//
//
//bool IsPass(float average)  // pass by value
//{
//	return (average >= 50);
//}
//
//enPassOrFail DeterminePassOrFail(float average)   // pass by value as soon as you notice an enum return type, then you will have a line(s) inside, such as:  return enPassOrFail::pass/fail
//{
//	if (IsPass(average)) // pass by value.  // DIVDE & Conqer instead of having :   if(average >= 50)
//	{
//		return enPassOrFail::Pass; // returns 1 of the enPassOrFail data type.
//	}
//	else
//	{
//		return enPassOrFail::Fail; // returns 0 of the enPassOrFail data type.
//	}
//}
//
//void PrintPassOrFail(const float& average)  // passing by constant ref. 
//{
//	if (DeterminePassOrFail(average) == enPassOrFail::Pass)  // NOTE: ❌❌ WARNING ❌❌: Having if (DeterminePassOrFail(average)) is BAD DESIGN on so many many level,
//	{                                                        //  as 1- the argument returns an enum data type while if statement expects bool. so an implicit conversion takes place
//															 // whe/re if enum enPassOrFail { Pass = 1, Fail = 0}  has integral values other than 0 and 1 then both are converted to 1.
//		cout << "Pass \n";
//	}
//	else
//	{
//		cout << "Fail \n";
//	}
//}
//
//
//
//void PrintResults(float marks[NumberOfMarks])
//{
//	float average = CalculateAverage(marks);
//
//	cout << "The average is: " << average << endl;
//	PrintPassOrFail(average); // marks is sent along with its memory address. hence , it's always passed by reference. 
//	// designed so that it contains, in the implementation, DeterminePassOrFail
//// Below- a less optimized solution
///*
//float AverageMark = CalculateAverageMark(CalculateSumOfMarks(marks));
//
//	PrintAverageMark(AverageMark); //the implementation has:  a cout referencing a variable 'AverageMark' so just use a cout on this line instead of creating the procedure.
//	PrintPassOrFail(AverageMark);
//*/
//}
//
//
//int main()
//{
//	enPassOrFail PassOrFail; // the next natural step of declaring a variable of this enum user-defined data type.
//
//	unsigned short min = 0;
//	unsigned short max = 100;
//
//	float marks[NumberOfMarks];
//	// Initializing the array variable 'marks' via reading user input (Using a procedure since MORE than one variable is initialized):
//
//	ReadMarksInRange("Enter mark ", marks, min, max); // marks is sent along with its memory address. Therefore, it's ALWAYS passed by reference automatically without including the & sign.
//	// the array variable 'marks' is now initialized.
//
//
//	PrintResults(marks); // 'marks' (the array argument) is sent along with its memory address. hence, it's always passed by reference.
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
//////////////////////////////////////////    BELOW ARE OLD UNOPTIMIZED SOLUTIONS ///////////////////////////////////////////////////////////////////
///* Solution:
//   This problem is solved utilizing arrays. The utilization of structures would be considered primitive in comparison.
//   For practice purposes, I'll incorporate enums in solving this problem. Thus, the workflow might not reflect the enums mental model documented in the C++ course.
//
//*/
//
//
//
//// Nonetheless- I will start solving this problem utilizing mere variables instead of the correct solution with arrays.
////  CRUCIAL: This way (my way) of solving this problem is the CORRECT one as comapred to that of the mo3alem becasue I've made use of فَرِّقْ تَسُدْ/ Divide & conquer to the MAX, logically.
//// If enums are to be utilized in any program, then ALWAYS code them first.
//
//enum enPassOrFail { Pass = 1, Fail = 0 }; //Enumeration constants (enumerators) acting as labels for the integral raw numbers they represent.
//// so from now and on, forget about these raw numbers.
//// so far, nothing has been created but an enum user-defined data type. The next natural step is declaring a variable of it.
//
//
//void ReadMarks(float& Mark1, float& Mark2, float& Mark3) // pass by reference.
//{
//	cout << "Enter the first mark: ";
//	cin >> Mark1;
//	cout << endl;
//
//	cout << "Enter the second mark: ";
//	cin >> Mark2;
//	cout << endl;
//
//	cout << "Enter the third mark: ";
//	cin >> Mark3;
//	cout << endl;
//}
//
//float CalculateMarksSum(float Mark1, float Mark2, float Mark3)
//{
//	return Mark1 + Mark2 + Mark3;
//}
//
//float CalculateAverageMark(float Mark1, float Mark2, float Mark3) // pass by value.
//{
//	return CalculateMarksSum(Mark1, Mark2, Mark3) / 3;   // NOT an integer divisions as marks are floats.
//}
//
//enPassOrFail PassOrFail(const float& average)  // pass by constant reference.
//{
//	if (average >= 50)
//	{
//		return enPassOrFail::Pass;  // 1 of data type enPassOrFail is what's returned.
//	}
//	else
//	{
//		return enPassOrFail::Fail;  // 0 of data type enPassOrFail is what's returned.
//	}
//}
//
//string DetermineResult(const enPassOrFail& result) // pass by const reference.
//{
//	if (result == enPassOrFail::Pass)
//	{
//		return "PASS";
//	}
//	else
//	{
//		return "FAIL";
//	}
//}
//
//void PrintResult(const float& average) // pass by constant reference.
//{
//	cout << "The average is " << average << " . The result is: " << DetermineResult(PassOrFail(average));
//}
//
//int main()
//{
//	//enPassOrFail PassorFail; // the natural step of declaring a variable of this enum user-defined data type. // commented out as it turned out it's not needed.
//
//	float Mark1, Mark2, Mark3;
//	// Initializing these 3 variables via reading user input:
//
//	ReadMarks(Mark1, Mark2, Mark3);
//	// these 3 variables are now initialized
//
//
//	PrintResult(CalculateAverageMark(Mark1, Mark2, Mark3)); // as the CalculateAverageMark() function contains CalculateSum()/3. Hence, Mark1, Mark2, Mark3 are passed as arguments.
//
//	return 0;
//}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//
//// Solution utilizing arrays:
//unsigned const short NumberOfElements = 3; // It was later discovered that this variable has to be a global one.
//
//// If enums are to be utilized in any program, then it's to be coded first and is always on top.
////enum enPassOrFail { Pass = 1, Fail = 0}; // enumeration constants (enumerators) acting as labels for the raw data they represent
//										 // thus, no need to remember the integral values of these raw data as only labels are dealt with.
//// so far, only an enum user-defined data type has been created. Nothing else.
//// The next natural step is creating a variable of this enum user-defined data type.
//
//
//void ReadMarks(float marks[NumberOfElements]) // array are ALWAYS + ONLY passed by reference. Also, Including the '&' renders an exception.
//{
//	for (int i = 0; i < NumberOfElements; i++)
//	{
//		cout << "Enter Mark " << i + 1 << " : ";
//		cin >> marks[i];
//		cout << endl;
//	}
//}
//
//float CalculateSumOfMarks(const float marks[NumberOfElements]) // passing by value  //CRUCIAL: the added 'const' is because:  Look at the calling function in main() (that simple)
//{
//	float sum = 0;
//	for (int i = 0; i < NumberOfElements; i++)
//	{
//		sum += marks[i];
//	}
//	return sum;
//}
//
//float CalculateAverageMark(float sum) // passing by value.
//{
//	return sum / 3; // will NOT be an integer division since 'sum' stores a float value (ex: 80.0f)
//}
//
//
//
//void PrintPassOrFail(const float marks[NumberOfElements]) // passing by const ref.  Also, Including the '&' renders an exception.
//{
//
//}
//
//bool IsPassed(float AverageMark)
//{
//	return (AverageMark >= 50);
//}
//
//
//void PrintAverageMark(float AverageMark)
//{
//
//	cout << "The average = " << AverageMark << endl;
//}
//
//
//void PrintPassOrFail(float AverageMark)  // passing by constant reference.
//{
//	if (IsPassed(AverageMark))
//	{
//		cout << "Passed \n";
//	}
//	else
//	{
//		cout << "Failed \n";
//	}
//}
//
//
//void PrintResults(const float marks[NumberOfElements]) // passing by ref.  Also, Including the '&' renders an exception. // inside we could have a printing structure.
//{
//	float AverageMark = CalculateAverageMark(CalculateSumOfMarks(marks));
//
//	PrintAverageMark(AverageMark);
//	PrintPassOrFail(AverageMark);
//
//}
//
//int main()
//{
//	//enPassOrFail PassOrFail; // Declaring a variable of this enum user-defined data type.
//
//	float marks[NumberOfElements];
//	// Initializing this array variable 'marks' via reading user-input. (remember, no array can be returned by a function as a function returns ONE value ONLY).
//		//This has to be done via a reading procedure, where the param is passed by reference,
//		//so that the variable declared in main() in initialized so that we are able to continue coding in main().
//
//	ReadMarks(marks); // In this called procedure, the passed argument is an array. Arrays are passed automatically along with their address in memory
//	// thus, the param in the implementing function is ALWAYS passed by reference. And the & sign in not included.
//
//// The array variable 'marks' has been initialized.
//
//
//	PrintResults(marks);
//	return 0;
//
//
//
//
//}
