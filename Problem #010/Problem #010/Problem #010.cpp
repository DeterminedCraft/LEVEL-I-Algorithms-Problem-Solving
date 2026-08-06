
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


/* Solution:
   A- The correct solution is using vectors. But since this concept hasn't yet been introduced, 
      it will be solved using arrays (fixed-length data structure).

   B- A primitive way of solving this problem is by declaring three variables and initializing them.
   

*/



// solution with B:

//float ReadFloatNumber(const string &message)  // pass by constant reference.
//{
//	float number; // what's returned
//
//	cout << message;
//	cin >> number;
//	cout << endl;
//
//	return number;
//}
//
//bool ValidateMark(const float& mark, float min, float max)  // pass by cosntant reference  // ranges ALWAYS passed by value. 
//{
//	return (min <= mark && mark <= max);
//}
//
//void ReadMark(const string& message, float min, float max, float& mark)
//{
//	do
//	{
//		mark = ReadFloatNumber(message);  // 'mark' is to be IMMEDIATELY validated against the range, in the while condition.
//
//	} while (!ValidateMark(mark, min, max)); // the argument is written so that, it evaluates to TRUE when the condition is INVALID.
//}
//
//
//void ReadMarks(const string& message, float min, float max,  float& Mark1, float& Mark2, float& Mark3) // pass by constant reference // ranges ALWAYS passed by value
//{                                                                                                     // Mark1, mark2, mark3 passed by ref. so that their declaration in main is initialized.
//	ReadMark(message, min, max, Mark1);
//	ReadMark(message, min, max, Mark2);
//	ReadMark(message, min, max, Mark3);
//}
//
//float CalculateSum(float Mark1, float Mark2, float Mark3)   // pass by value.
//{
//	return (Mark1 + Mark2 + Mark3);
//}
//
//float CalculateAverage(float sum) // pass by value
//{
//	return sum / 3;     // this is NOT an integer division, as the 'sum' value is in float (the value in sum is stored as 270.0f , 265.0f, etc.)
//}
//
//void PrintAverage(const float& Mark1, const float& Mark2, const float& Mark3)   // passing by constant reference.
//{
//	cout << "The average mark is: " << CalculateAverage(CalculateSum(Mark1, Mark2, Mark3)) << endl;
//}
//
//
//int main()
//{
//	float min = 0;   //instead of hardcoding them into the called function. // declared as float as they'll be compared against the mark entered which is float (avoid mixing data types when comparing)
//	float max = 100; 
//
//	float Mark1, Mark2, Mark3;
//	// Initializing the above variables via reading user input using a procedure (since MORE than one value is initialized):
//
//	ReadMarks(" Enter Mark: ", min, max, Mark1, Mark2, Mark3);
//	// Mark1, Mark2, & Mark3 are now initialized.
//
//
//	PrintAverage(Mark1, Mark2, Mark3); // the nested functions line is written so that, the printing procedure contains CalculateAverage() function
//	                                   // this is the standared. As a 'side effect', the printing procedure will have access to Mark1, Mark2, Mark3.
//
//
//	return 0;
//}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// /*Now, another solution version without the user of vectors as of yet :
//
// separate: also, consider the following note:
// 
// if you examine:
//
// ReadMarks(" Enter Mark: ", min, max, Mark1, Mark2, Mark3);
//
// It's not readable as we have 3 variables: Mark1, Mark2, Mark3
// */
//
//
//
//const unsigned short NumberOfMarks = 3;
//
//float ReadFloatNumber(const string& message)   // pass by constant reference.
//{
//	float number; // what's returned.
//
//	cout << message;
//	cin >> number;
//	cout << endl;
//
//	return number;
//}
//
//bool ValidateMark(const float& mark, float min, float max)   // pass by cosntant reference
//{
//	return (min <= mark && mark <= max);
//}
//
//float ReadMark(const string& message, float min, float max)  // pass by constant ref.  // ranges ALWAYS passed by value.
//{
//	float mark; // what's returned.
//	do
//	{
//		mark = ReadFloatNumber(message); // 'mark' is to be immediately valiated against the range, in the while condition.
//
//	} while (!ValidateMark(mark, min, max)); // the argument is composed so that, it evaluates to TRUE when the condition is INVALID.
//
//	return mark;
//	// Note: the above block of code is to be sequentially composed line by line
//	//       and at the end, implement the functions of:  ReadFloatNumber()  & ValidateMark()
//}
//
//
//float CastToFloatNumberOfMarks(unsigned short NumberOfMarks)
//{
//	return float(NumberOfMarks);
//}
//
//float CalculateAverageMark(float sum, unsigned short NumberOfMarks)  // pass by value
//{
//	return (sum / CastToFloatNumberOfMarks(NumberOfMarks)); 
//}
//
//float CalculateSum(float Number1, float Number2, float Number3)   // pass by value
//{
//	return (Number1 + Number2 + Number3);
//}
//
//void PrintAverageMark(const float& Number1, const float& Number2, const float& Number3)   //passing by constant reference.
//{
//	cout << "The average mark is: " << CalculateAverageMark(CalculateSum(Number1, Number2, Number3), NumberOfMarks) << endl;   // instead of hardcoding number of marks in the CalculateAverage()
//}
//
//
//int main()
//{
//	float min = 0;
//	float max = 100;
//
//	// Initializing the below variable via reading user input (using function - since one value is initialized and returned):
//	float Number1 = ReadMark("Enter mark: ", min, max);
///*        |
//          |
//          |---->  to be typed at the end, after typing the 'return' keyword in the implementing function.*/
//
//	float Number2 = ReadMark("Enter Mark: ", min, max);
///*        |
//	      |
//	      |---->  to be typed at the end, after typing the 'return' keyword in the implementing function.*/
//
//	float Number3 = ReadMark("Enter Mark: ", min, max);
///*        |
//		  |
//		  |---->  to be typed at the end, after typing the 'return' keyword in the implementing function.*/
//
//
//
//	PrintAverageMark(Number1, Number2, Number3);  // this nested functions line is written so that, it contains CalculateAverageMark
//	                                              // this is the standard way of programming. As a by-product, the printing procedure
//	                                             // will have access to Number1, Number2, & Number3 entered by the user.
//
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Now solving using arrays, since the concept of vectors has not been introduced yet:

const unsigned short NumberOfArrayElements = 3;

float ReadFloatNumber(const string& message)
{
    float number; // what's returned

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}

bool ValidateMark(const float &mark, float min, float max)
{
    return (min <= mark && mark <= max);
}




void ReadMarks(const string &message, float min, float max, float marks[NumberOfArrayElements])
{
    for (int i = 0; i < NumberOfArrayElements; i++)
    {
        do
        {
            marks[i] = ReadFloatNumber(message); // 'Marks[i]' is to be IMMEDIATELY validated against the range, in the while condition.

        } while (!ValidateMark(marks[i], min, max)); //👈 👈 the argument is written so that, it's TRUE when the condition is INVALID.
    }
    
}

float CalculateSumOfMarks(float marks[NumberOfArrayElements]) // passing is ALWAYS by ref.
{
	float sum = 0; // routine  // what's returned

	for (int i = 0; i < NumberOfArrayElements; i++)
	{
		sum = sum + marks[i];
	}

	return sum;
}

float CastToFloatFromUnsignedShort(unsigned short NumberOfArrayElements)
{
	return float(NumberOfArrayElements);
}

float CalculateAverageMark(float sum, unsigned short NumberOfArrayElements) // pass by value
{
	return sum / CastToFloatFromUnsignedShort(NumberOfArrayElements);   // this is NOT an integer division.
}

void PrintAverageMark(float marks[NumberOfArrayElements])  //the array is ALWAYS passed by ref. Including the & will render exception.
{
	cout << "The average mark is: " << CalculateAverageMark(CalculateSumOfMarks(marks), NumberOfArrayElements) << endl; // again- the array is sent along with its address in memory.
}

int main()
{
    float min = 0;
    float max = 100;

    float marks[NumberOfArrayElements];
    // Initializing the above variable via reading user input (Using a procedure- since an array hold more than one value):

    ReadMarks("Enter mark: ", min, max, marks);  //the argument, that's an array variable is automatically sent along with its memory address. Hence, the implementing function will always pass by ref without the & sign.
	// The array variable 'Marks' is now fully initialized.

	PrintAverageMark(marks); // the argument, that's an array is sent along with its memory address. Hence, in the implementation of the printing procedure the passing will always be by ref. without the & sign
	                        // the printing procedure will include the function CalculateAverageMark(). this is a standard practice instead of including CalculateAveragMark as a nested function
	                       // in the nested functions line above.
	                       // as a 'side effect', the printing procedure will have access to the marks array (the marks the user enters)
    return 0;
}







/////////////////////////////////////////ALL examples below ARE SOME FIRST ATTEMPT BAD SOLUTIONS/////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




//
///* The correct solution is storing the user entered values into a vector (using some colection class).
//    Nevertheless, this counts as an advanced approach for out current level.
//	Hence, this opportunity is seized for honing in on our programming skills by:
//	- Solving this example using an array (a fixed-length data structure).
//	- Solving this example by creating three variables that are initialized via reading user input (a much more of a primitive approach).
//
//*/
//const unsigned short ArrayNumberOfElements = 3; // later on, it turned out that it ought to be declared globally.
//
//float ReadFloatNumber(const string& message) // pass by constant reference.
//{
//	float number; // what's returned
//	cout << message;
//	cin >> number;
//	cout << endl;
//
//	return number;
//}
//
//bool ValidateMarksInRange(const float& mark, unsigned short min, unsigned short max) // pass by constant reference. // Ranges are ALWAYS passed by value.
//{
//	return (min <= mark && mark <= max);
//}
//
//void ReadMarksInRange(const string& message, float marks[ArrayNumberOfElements], unsigned short min, unsigned short max) // array passed AUTOMATICALLY be reference without including the & sign ( including it will render an exception)
//{
//	
//	for (int i = 0; i < ArrayNumberOfElements; i++)  // note: in C++  .length() does NOT apply to arrays(fixed-length data strutures) or strings
//	{
//		do
//		{
//			marks[i] = ReadFloatNumber(message); // 'marks[i] to be IMMEDIATELY validated against the range, in the while condition.
//
//		} while (!ValidateMarksInRange(marks[i], min, max));   // 👈👈 the argument is written so that, it evaluates to TRUE when the condition is INVALID.
//	}
//	// Note: The above block os code is to be sequentially composed line by line.
//	// and at the end, implement the functions of: ReadUnsignedShortNumber()  &  ValidateMarksInRange()
//}
//
//float CastToFloatFromUnsignedShort(unsigned short ArrayNumberOfElements) // pass by value
//{
//	return (float)ArrayNumberOfElements;
//}
//
//float CalculateTheAverageMark(float sum)   //passed by value
//{
//	return  sum / CastToFloatFromUnsignedShort(ArrayNumberOfElements);   // this will NOT be an integer division since 'sum' is declared as float ( ex: it's value is stored as 97.0f)
//	
//} 
//
//float CalculateSumOfMarks(float marks[ArrayNumberOfElements]) // by default, passed as a reference
//{
//	float sum = 0; // just a routine
//
//	for (int i = 0; i < ArrayNumberOfElements; i++)
//	{
//		sum = sum + marks[i];
//	}
//
//	return sum;
//}
//
//
//
//void PrintAverageMark(float marks[ArrayNumberOfElements]) // passing by reference. No need to include the & sign (actually, including it will render an exception)
//{
//	cout << "The Average Mark is: " << CalculateTheAverageMark(CalculateSumOfMarks(marks)) << endl;  // Divide & conquer  فَرِّقْ تَسُدْ
//}
//
//
//int main()
//{
//	float marks[ArrayNumberOfElements];
//	// Initializing the above array variable via reading user input, using a procedure (since more than one value is initialized):
//
//	unsigned short min = 0;
//	unsigned short max = 100;
//
//	ReadMarksInRange(" Enter mark: ", marks, min, max); // the array variable 'marks' is passed along with its address in memory (Hence, for the implementation - it's ALWAYS passed by reference without including the & sign)
//	// the array variable 'marks' has been initialized.
//
//	PrintAverageMark(marks); // the array variable is sent along with its address in memory. hence- the implementing function has a pass by reference without including the & sign.
//	// the implementation of the printing procedure will have CalculateAverageMark()
//	// as a 'side effect' the printing procedure, will have access / can reference the marks array.
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
//
//// Solving this example, SHOULD be done utilizing Arrays Instead of structures (Primitive way of handling this SPECIFIC problem).
//// This is 100 percent correct and validated ✅💯✔️🔥
//
//// However- In this example, we will solve using: 1- variables instead of an array  2- Array (How it should be)   3- Structures .
//
//   // solving it using mere variables instead of array:
////void ReadMarks(float& Mark1, float& Mark2, float& Mark3)  // passing by reference.
////{
////	cout << "Enter Mark1: ";
////	cin >> Mark1;
////	cout << endl;
////
////	cout << "Enter Mark2: ";
////	cin >> Mark2;
////	cout << endl;
////
////	cout << "Enter Mark3: ";
////	cin >> Mark3;
////	cout << endl;
////}
////
////
////float CalculateMarksSum(float Mark1, float Mark2, float Mark3)  // passing by value
////{
////	return Mark1 + Mark2 + Mark3;
////}
////
////float CalculateAverageMark(float Mark1, float Mark2, float Mark3) // pass by value
////{
////	return   CalculateMarksSum(Mark1, Mark2, Mark3) / 3;      // NOT an integer division as 'sum' stores a float value (ex: 7.0f,  7.4f, etc.)
////}
////
////void PrintAverageMark(const float& average) // passing by constant reference.
////{
////	cout << "Average is " << average << endl;
////}
////
////int main()
////{
////	float Mark1, Mark2, Mark3;
////	// Initializing via reading user input:
////
////	ReadMarks(Mark1, Mark2, Mark3);
////	// The variables Mark1, Mark2, & Mark3 are now initialized.
////
////	PrintAverageMark(CalculateAverageMark(Mark1, Mark2, Mark3));
////	// Because inside the CalculateAverageMark() func, I'll have CalculateMarksSum() /3  [ this is why Mark1,Mark2, Mark3 are the arguments passed in the called func]
////	// and this is superior to having 
////	// PrintAverageMark(CalculateAverageMark(CalculateMarksSum(Mark1, Mark2, Mark3)));
////	// as solved in my initial solution below:
////
////
////	return 0;
////}
////
////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                             
////// My initial solution using mere variables:
////void ReadMarks(float& Mark1, float& Mark2, float& Mark3)  // passing by reference.
////{
////	cout << "Enter Mark1: ";
////	cin >> Mark1;
////	cout << endl;
////
////	cout << "Enter Mark2: ";
////	cin >> Mark2;
////	cout << endl;
////
////	cout << "Enter Mark3: ";
////	cin >> Mark3;
////	cout << endl;
////}
////
////
////float CalculateMarksSum(float Mark1, float Mark2, float Mark3)  // passing by value
////{
////	return Mark1 + Mark2 + Mark3;
////}
////
////float CalculateAverageMark(float sum) // pass by value
////{
////	return sum / 3;      // NOT an integer division as 'sum' stores a float value (ex: 7.0f,  7.4f, etc.)
////}
////
////void PrintAverageMark(const float& average) // passing by constant reference.
////{
////	cout << "Average is " << average << endl;
////}
////
////int main()
////{
////	float Mark1, Mark2, Mark3;
////	// Initializing via reading user input:
////
////	ReadMarks(Mark1, Mark2, Mark3);
////	// The variables Mark1, Mark2, & Mark3 are now initialized.
////
////	PrintAverageMark(CalculateAverageMark(CalculateMarksSum(Mark1, Mark2, Mark3)));
////
////
////	return 0;
////}
////
////
////unsigned const short NumberOfElements = 3; // along the way, one finds out that this const variable has to be set globally.
////
////void ReadMarks(float marks[NumberOfElements]) // arrays are AUTOMATICALLY ALWAYS passed by reference. Including the & sign renders an exception.
////{
////	for (int i = 0; i < NumberOfElements; i++)
////	{
////		cout << "Enter Mark " << i + 1 << " : ";
////		cin >> marks[i];
////		cout << "\n";
////	}
////}
////
////float CalculateSumOfMarks(float marks[NumberOfElements])   // Divide& Conquer strategy / فَرِّقْ تَسُدْ    so that this could be a universal utility
////{
////	float sum = 0;
////	for (int i = 0; i < NumberOfElements; i++)
////	{
////		sum += marks[i];
////	}
////
////	return sum;
////}
////
////float CalculateAverageMark(float sum)  // pass by value          //Divide & Conquer strategy / فَرِّقْ تَسُدْ    so that this could be a universal utility
////{
////	return sum / 3;  // is NOT integer division as stored floats are invloved in the calculations.   // NOTE: 3 should NOT be hardcoded.
////}
////
////
////void PrintMarksAverage(float marks[NumberOfElements])
////{
////	cout << "The average = " << CalculateAverageMark(CalculateSumOfMarks(marks)) << endl;
////}
////
////int main()
////{
////
////	float marks[NumberOfElements];
////	// Initializing the array variable 'marks' via reading user input:
////
////	ReadMarks(marks), // In this called procedure- The passed argument 'marks' is always/ by default passed along with its address in memory.
////		// thus, the implementing function passes this parameter by reference without the inclusion of the '&' sign.
////
////// The array variable 'marks' is now initialized.
////
////PrintMarksAverage(marks);
////
////	return 0;
////}
////
////
////
////
/////////////////////////////////////////////////  Now Solving it the WRONG way Using structures (instead of arrays):  //////////////////////////////////////////////////////
//  this is  The WRONG  solution with structures( this structure approach is correct only if more than one record is required)
////
////// #1: The unoptimized solution (See why unoptimized at the very end of this solution).
////struct stMarks
////{
////	float Mark1;
////	float Mark2;
////	float Mark3;
////};
////// so far only a structure user-defined data type has been created.
////// The next natural step is declaring a variable of this structure user defined data type.
////// that is either a normal variable (One record) or an array variable (more than one record)
//////
////// But the question is: WHERE to declare this variable ?
////	// If it's going to be initialized directly, then declare the variable inside main()
////	// if it's going to be initialized via reading user input, then declare the variable inside a reading function
////	// of data type structure becasue this structure user-defined data type variable is what will be returned.
////	// since it is the former that implement this function IMMEDIATELY NOW below:
////
////stMarks ReadMarks()
////{   // Are we going to declare a normal variable (one record) OR an array variable [(more than one record)  where each element of the array represents an entire record] ?
////	stMarks Marks; // ONLY declare a variable of the nesting structure (not the nested one(s)) and/or the independent structure(s).
////	// declared a normal variable (since ONE record is needed). // It now has access to all member variables defined inside the structure user-defined data type.
////
////	cout << "Enter the first mark: ";
////	cin >> Marks.Mark1;
////	cout << endl;
////
////	cout << "Enter the second mark: ";
////	cin >> Marks.Mark2;
////	cout << endl;
////
////	cout << "Enter the third mark: ";
////	cin >> Marks.Mark3;
////	cout << endl;
////
////	return Marks;
////	// The variable 'Marks' has been fully initialized with all member variables and THEN returned.
////	// It is returned to the called function that evaluates to produce a value of type stMarks (which initializes the object in the called function)
////	// The lifetime of the local variable Marks end when the program exits the curly brackets of this function.
////}
////// Now, write the nested functions line in main().
////
////float CalculateMarksAverage(stMarks Marks) // passing by value
////{
////	return (Marks.Mark1 + Marks.Mark2 + Marks.Mark3) / 3; // is NOT integer division as stored floats are invloved in the calculations.
////}
////
////void PrintAverageMark(const float& average) // passing by const reference.
////{
////	cout << "The average = " << average << endl;
////}
////
////int main()
////{
////	//Instead of declaring these variables here. I will declare them as member variables inside a structure
////
////	PrintAverageMark(CalculateMarksAverage(ReadMarks())); // this construction suffices as there is no need to reference the original three marks in the printing procedure.
////
////	return 0;
////
////	// why this code could be more optimized ?
////	 //Answer: Even though this solution is considered a good one, it does not capitalize on the Divie & Conquer / Farrik Tasud strategy
////	 // because- Instead of having a single function that calculates the average by adding up the 3 numbers and dividing them by 3
////	 // We could split it into 2 functions: a sum function (that adds up the 3 numbers) and an average function ( one that takes the sum and divides it by 3).
////
////	 // If you start implementing this strategy, then INSIDE the printing procedure, we would have:
////
////	 /*
////
////	   cout << "The average = " << AverageOfmarks(SumOfMarks()) << endl;
////
////	 */
////}
////
////
//////***************************** It follows that- A more optimized approach capitalizing on the Divide & Conquer strategy / فَرِّقْ تَسُدْ is: ************************************
////// 
////// #2:Again this is  The WRONG  solution with structures( this structure approach is correct only if more than one record is required)
////struct stMarks
////{
////	float Mark1;
////	float Mark2;
////	float Mark3;
////};
////
////
////stMarks ReadMarks()
////{   // Are we going to declare a normal variable (one record) OR an array variable [(more than one record)  where each element of the array represents an entire record] ?
////	stMarks marks; // ONLY declare a variable of the nesting structure (not the nested one(s)) and/or the independent structure(s).
////
////
////	cout << "Enter the first mark: ";
////	cin >> marks.Mark1;
////	cout << endl;
////
////	cout << "Enter the second mark: ";
////	cin >> marks.Mark2;
////	cout << endl;
////
////	cout << "Enter the third mark: ";
////	cin >> marks.Mark3;
////	cout << endl;
////
////	return marks;
////
////}
////// Now, write the nested functions line in main().
////
////float CalculateMarksSum(stMarks marks) // passing by value       Divide & Conquer strategy / فَرِّقْ تَسُدْ    so that this could be a universal utility
////{
////	return marks.Mark1 + marks.Mark2 + marks.Mark3; // is NOT integer division as stored floats are invloved in the calculations.
////}
////
////float CalculateMarksAverage(float sum) // pass by value         Divide & Conquer strategy / فَرِّقْ تَسُدْ    so that this could be a universal utility
////{
////	return sum / 3; // will NOT be an int division as sum stores a float value ( ex: 290.0f)
////}
////
////void PrintAverageMark(const stMarks& marks) // passing by const reference.
////{
////	cout << "The average = " << CalculateMarksAverage(CalculateMarksSum(marks)) << endl;
////}
////
////int main()
////{
////	//Instead of declaring these variables here. I will declare them as member variables inside a structure
////
////	PrintAverageMark(ReadMarks()); // this construction suffices as there is no need to reference the original three marks in the printing procedure.
////
////	return 0;
////}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

