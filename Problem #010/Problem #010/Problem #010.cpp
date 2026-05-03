
#include <iostream>
using namespace std;

/*
 Problem #10:

 Write a program to ask the user to enter:
 - Mark1, Mark2, Mark3

 Then print the Average of entered Marks

 Example Inputs:
 90
 80
 70

 Outputs:
 80
*/



// Solving this example, SHOULD be done utilizing Arrays Instead of structures (Primitive way of handling this SPECIFIC problem).
// This is 100 percent correct and validated ✅💯✔️🔥

// However- In this example, we will solve using: 1- variables instead of an array  2- Array (How it should be)   3- Structures .

   // solving it using mere variables instead of array:
void ReadMarks(float& Mark1, float& Mark2, float& Mark3)  // passing by reference.
{
	cout << "Enter Mark1: ";
	cin >> Mark1;
	cout << endl;

	cout << "Enter Mark2: ";
	cin >> Mark2;
	cout << endl;

	cout << "Enter Mark3: ";
	cin >> Mark3;
	cout << endl;
}


float CalculateMarksSum(float Mark1, float Mark2, float Mark3)  // passing by value
{
	return Mark1 + Mark2 + Mark3;
}

float CalculateAverageMark(float Mark1, float Mark2, float Mark3) // pass by value
{
	return   CalculateMarksSum(Mark1, Mark2, Mark3) / 3;      // NOT an integer division as 'sum' stores a float value (ex: 7.0f,  7.4f, etc.)
}

void PrintAverageMark(const float& average) // passing by constant reference.
{
	cout << "Average is " << average << endl;
}

int main()
{
	float Mark1, Mark2, Mark3;
	// Initializing via reading user input:

	ReadMarks(Mark1, Mark2, Mark3);
	// The variables Mark1, Mark2, & Mark3 are now initialized.

	PrintAverageMark(CalculateAverageMark(Mark1, Mark2, Mark3));
	// Because inside the CalculateAverageMark() func, I'll have CalculateMarksSum() /3  [ this is why Mark1,Mark2, Mark3 are the arguments passed in the called func]
	// and this is superior to having 
	// PrintAverageMark(CalculateAverageMark(CalculateMarksSum(Mark1, Mark2, Mark3)));
	// as solved in my initial solution below:


	return 0;
}




// My initial solution using mere variables:
void ReadMarks(float& Mark1, float& Mark2, float& Mark3)  // passing by reference.
{
	cout << "Enter Mark1: ";
	cin >> Mark1;
	cout << endl;

	cout << "Enter Mark2: ";
	cin >> Mark2;
	cout << endl;

	cout << "Enter Mark3: ";
	cin >> Mark3;
	cout << endl;
}


float CalculateMarksSum(float Mark1, float Mark2, float Mark3)  // passing by value
{
	return Mark1 + Mark2 + Mark3;
}

float CalculateAverageMark(float sum) // pass by value
{
	return sum / 3;      // NOT an integer division as 'sum' stores a float value (ex: 7.0f,  7.4f, etc.)
}

void PrintAverageMark(const float& average) // passing by constant reference.
{
	cout << "Average is " << average << endl;
}

int main()
{
	float Mark1, Mark2, Mark3;
	// Initializing via reading user input:

	ReadMarks(Mark1, Mark2, Mark3);
	// The variables Mark1, Mark2, & Mark3 are now initialized.

	PrintAverageMark(CalculateAverageMark(CalculateMarksSum(Mark1, Mark2, Mark3)));


	return 0;
}


unsigned const short NumberOfElements = 3; // along the way, one finds out that this const variable has to be set globally.

void ReadMarks(float marks[NumberOfElements]) // arrays are AUTOMATICALLY ALWAYS passed by reference. Including the & sign renders an exception.
{
	for (int i = 0; i < NumberOfElements; i++)
	{
		cout << "Enter Mark " << i + 1 << " : ";
		cin >> marks[i];
		cout << "\n";
	}
}

float CalculateSumOfMarks(float marks[NumberOfElements])   // Divide& Conquer strategy / فَرِّقْ تَسُدْ    so that this could be a universal utility
{
	float sum = 0;
	for (int i = 0; i < NumberOfElements; i++)
	{
		sum += marks[i];
	}

	return sum;
}

float CalculateAverageMark(float sum)  // pass by value          //Divide & Conquer strategy / فَرِّقْ تَسُدْ    so that this could be a universal utility
{
	return sum / 3;  // is NOT integer division as stored floats are invloved in the calculations.   // NOTE: 3 should NOT be hardcoded.
}


void PrintMarksAverage(float marks[NumberOfElements])
{
	cout << "The average = " << CalculateAverageMark(CalculateSumOfMarks(marks)) << endl;
}

int main()
{

	float marks[NumberOfElements];
	// Initializing the array variable 'marks' via reading user input:

	ReadMarks(marks), // In this called procedure- The passed argument 'marks' is always/ by default passed along with its address in memory.
		// thus, the implementing function passes this parameter by reference without the inclusion of the '&' sign.

// The array variable 'marks' is now initialized.

PrintMarksAverage(marks);

	return 0;
}




/////////////////////////////////////////////  Now Solving it the primitive way Using structures (instead of arrays):  //////////////////////////////////////////////////////

// #1: The unoptimized solution (See why unoptimized at the very end of this solution).
struct stMarks
{
	float Mark1;
	float Mark2;
	float Mark3;
};
// so far only a structure user-defined data type has been created.
// The next natural step is declaring a variable of this structure user defined data type.
// that is either a normal variable (One record) or an array variable (more than one record)
//
// But the question is: WHERE to declare this variable ?
	// If it's going to be initialized directly, then declare the variable inside main()
	// if it's going to be initialized via reading user input, then declare the variable inside a reading function
	// of data type structure becasue this structure user-defined data type variable is what will be returned.
	// since it is the former that implement this function IMMEDIATELY NOW below:

stMarks ReadMarks()
{   // Are we going to declare a normal variable (one record) OR an array variable [(more than one record)  where each element of the array represents an entire record] ?
	stMarks Marks; // ONLY declare a variable of the nesting structure (not the nested one(s)) and/or the independent structure(s).
	// declared a normal variable (since ONE record is needed). // It now has access to all member variables defined inside the structure user-defined data type.

	cout << "Enter the first mark: ";
	cin >> Marks.Mark1;
	cout << endl;

	cout << "Enter the second mark: ";
	cin >> Marks.Mark2;
	cout << endl;

	cout << "Enter the third mark: ";
	cin >> Marks.Mark3;
	cout << endl;

	return Marks;
	// The variable 'Marks' has been fully initialized with all member variables and THEN returned.
	// It is returned to the called function that evaluates to produce a value of type stMarks (which initializes the object in the called function)
	// The lifetime of the local variable Marks end when the program exits the curly brackets of this function.
}
// Now, write the nested functions line in main().

float CalculateMarksAverage(stMarks Marks) // passing by value
{
	return (Marks.Mark1 + Marks.Mark2 + Marks.Mark3) / 3; // is NOT integer division as stored floats are invloved in the calculations.
}

void PrintAverageMark(const float& average) // passing by const reference.
{
	cout << "The average = " << average << endl;
}

int main()
{
	//Instead of declaring these variables here. I will declare them as member variables inside a structure

	PrintAverageMark(CalculateMarksAverage(ReadMarks())); // this construction suffices as there is no need to reference the original three marks in the printing procedure.

	return 0;

	// why this code could be more optimized ?
	 //Answer: Even though this solution is considered a good one, it does not capitalize on the Divie & Conquer / Farrik Tasud strategy
	 // because- Instead of having a single function that calculates the average by adding up the 3 numbers and dividing them by 3
	 // We could split it into 2 functions: a sum function (that adds up the 3 numbers) and an average function ( one that takes the sum and divides it by 3).

	 // If you start implementing this strategy, then INSIDE the printing procedure, we would have:

	 /*

	   cout << "The average = " << AverageOfmarks(SumOfMarks()) << endl;

	 */
}


//***************************** It follows that- A more optimized approach capitalizing on the Divide & Conquer strategy / فَرِّقْ تَسُدْ is: ************************************
// 
// #2: The optimized solution with structures( But still primitive as compared to solving the example with ARRAYS)
struct stMarks
{
	float Mark1;
	float Mark2;
	float Mark3;
};


stMarks ReadMarks()
{   // Are we going to declare a normal variable (one record) OR an array variable [(more than one record)  where each element of the array represents an entire record] ?
	stMarks marks; // ONLY declare a variable of the nesting structure (not the nested one(s)) and/or the independent structure(s).


	cout << "Enter the first mark: ";
	cin >> marks.Mark1;
	cout << endl;

	cout << "Enter the second mark: ";
	cin >> marks.Mark2;
	cout << endl;

	cout << "Enter the third mark: ";
	cin >> marks.Mark3;
	cout << endl;

	return marks;

}
// Now, write the nested functions line in main().

float CalculateMarksSum(stMarks marks) // passing by value       Divide & Conquer strategy / فَرِّقْ تَسُدْ    so that this could be a universal utility
{
	return marks.Mark1 + marks.Mark2 + marks.Mark3; // is NOT integer division as stored floats are invloved in the calculations.
}

float CalculateMarksAverage(float sum) // pass by value         Divide & Conquer strategy / فَرِّقْ تَسُدْ    so that this could be a universal utility
{
	return sum / 3; // will NOT be an int division as sum stores a float value ( ex: 290.0f)
}

void PrintAverageMark(const stMarks& marks) // passing by const reference.
{
	cout << "The average = " << CalculateMarksAverage(CalculateMarksSum(marks)) << endl;
}

int main()
{
	//Instead of declaring these variables here. I will declare them as member variables inside a structure

	PrintAverageMark(ReadMarks()); // this construction suffices as there is no need to reference the original three marks in the printing procedure.

	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



// VERY OLD NOTES: Review them before making a final release for this course and decide what to do with them:
//// solving it the primitive way without arrays:
//
//struct stMarks
//{
//	float Mark1;
//	float Mark2;
//	float Mark3;
//};
//// so far only a structure user-defined data type has been created.
//// The next natural step is to declare a variable of this structure user-defined data type.
//// The question is, WHERE to create this varible?
////
////   -Is this variable going to be initialized directly ? (Then declare the variable in main())
////   -Or is this variable going to be initialized via reading user-input ? (Then declare it inside the reading function of type structure, 
////    since this structure user-defined data type variable is what will be returned).
////     [ .. and inside that function- we will ask whether it is going to be a normal variable or an array variable]
//// 
//// so immediately (100 percent correct !! and do it this way ALWAYS) start with the below immediate lines:
//stMarks ReadMarks()
//{
//	// Are we going to declare a normal variable (one record) or an array variable (more than one record) ? where each element of the array represents an entire record ?
//	stMarks marks; // what is returned
//
//	cout << "Enter First Mark: ";
//	cin >> marks.Mark1;
//	cout << endl;
//
//	cout << "Enter Second Mark: ";
//	cin >> marks.Mark2;
//	cout << endl;
//
//	cout << "Enter Third Mark: ";
//	cin >> marks.Mark3;
//	cout << endl;
//
//	return marks;
//	// When 'marks' is returned, it will by fully initialized with all the member variables inside it.
//}
//
//
//float CalculateAverage(float SumResult) // passing by value
//{
//	return SumResult / 3;   // No int division happens becasue SumResult is of type float.
//}
//
//float CalculateSum(stMarks marks) // passing by value
//{
//	return (marks.Mark1 + marks.Mark2 + marks.Mark3);
//}
//
//void PrintAverageMark(const stMarks& marks)   // passing by const reference.
//{
//	cout << "The average of the marks: " << marks.Mark1 << " & " << marks.Mark2 << " & " << marks.Mark3 << " = " << CalculateAverage(CalculateSum(marks)) << endl;
//}
//
//int main()
//{
//	// Since these variables are related amongst each other,
//	// then declare them as member variables inside a structure.
//     
//
//	// second immediate step:
//	PrintAverageMark(ReadMarks());
//
//	/* Instead of :
//	* 
//	PrintAverageMarks(CalculateAverage(ReadMarks())); // Excellent but doesn't give the printing procedure access to the marks the user entered (= they can't be referenced).
//
//	 */
//	 // and if its to be used then the printin procedure parameters is to change to: const float &average
//	return 0;
//}
//
//
///* So let us start with a general mental model that is to be refined very soon:
//
//   
//   PrintAverageMark(CalculateAverageMark(ReadMarks())
//
//   The nested CalculateAverageMark & ReadMarks,    both HAVE to be functions. Because an argument can never equate to void = compiler error.
//
//   The problem with the current line of nested functions:
//
//   PrintAverageMark(CalculateAverageMark(ReadMarks())
//   is that, the original marks that the user enters can NOT be referenced inside the printing procedure so
//   that, for example, one can not output a message such as " For Mark1 = 80, Mark2 = 90, Mark3 = 100, the average is = ".
//
//   To overcome this issue, we have 2 possible solution:
//
//   PrintAverageMark(ReadMarks())         
//   where inside the Printing Procedure, we could call the function CalculateAverageMark() that is yet to be implemented
//   for example:    cout << "The average for the marks " << marks.Mark1 << "," << marks.Mark2 << "," << marks.Mark3 << " = " << CalculateAverageMark() << endl;
//
//
//   OR 
//
//   The unoptimized solution of:
//
//   stMarks marks = ReadMarks();  // The right operand is written at last ( and this is NOT the declaration of the structure user-defined data type; as this is simply
//                                 // to catch the value returned by the function so it could be used later.
//
// PrintAverageMarks(CalculateAverage(ReadMarks()), marks);
//
//
//*/

