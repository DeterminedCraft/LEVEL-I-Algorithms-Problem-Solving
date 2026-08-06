
#include <iostream>
using namespace std;

/*
 Problem #8:

  Write a program to ask the user to enter:
  - Mark

  Then print the "PASS" if mark >= 50, otherwise print "Fail"



  Example Inputs:

  45

  Outputs ➔

  Fail


*/
 



enum enPassOrFail{ Pass = 1, Fail = 0 }; // the enumeration constants (enumerators) that are Pass & Fail act as labels for the raw integral values they represent.
// Therefore, from now and on FOREVER forget about these raw values and only deal with their labels.

//so far, only an enum user-defined data type has been created and nothing else.
// the next natural step, is declaring a variable of this enum user-defined data type INSIDE MAIN()



float ReadNumber(const string &message)  // passing by constant reference
{
	float number; // what's returned

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}

bool ValidateFloatInRange(const float& number, float min, float max)  // pass by constant reference   // Ranges are ALWAYS passed by value.
{
	return (min <= number && number <= max);
}



float ReadFloatInRange(const string& message, float min, float max) // pass by constant ref. // range is ALWAYS passed by value.
{
	float number; // what's returned
	do
	{
		number = ReadNumber(message); // 'number' is to be IMMEDIATELY evaluated against the range, in the while condition.

	} while (!ValidateFloatInRange(number, min, max));

	return number;

	// NOTE: The above block is to be composed line by line
	// and at the end, implement the functions of:
	//  ReadNumber()  &  ValidateFloatInRange()
}

bool IsPass(float number)  // pass by value
{
	return (number >= 50);
}

enPassOrFail DeterminePassOrFail(const float &number) // passing by constant reference.
// as soon as you see a function with enum data type, then it will contain: return enPassOrFail::Pass , return enPassOrFail::Fail in conditonal statements
{
	if (IsPass(number))  // no matter how small this line is, always wrap it inside a function.
	{
		return enPassOrFail::Pass; // returns 1 (of data type enPassOrFail::Pass)
	}
	else
	{
		return enPassOrFail::Fail; // returns 0 (of data type enPassorFail)
	}
}



void PrintPassorFail(const float &number)   // passing by constant reference.
{
	if (DeterminePassOrFail(number) == enPassOrFail::Pass)
	{
		cout << "\n Pass \n";
	}
	else
	{
		cout << "\n Failed \n";
	}

}


int main()
{
	// enPassOrFail PassorFail; // commented out- turned out, it was never needed  //the next natural step of declaring a variable of the enum user-defined data type.


	float min = 0;   // write it here so not to hardcode it.
	float max = 100; // write it here so not to hardcode it.

	PrintPassorFail(ReadFloatInRange(" Enter mark: "   ,min, max)); // including the ranges as arguments as their values are NOT intrinsic.
	// composing the nested functions line as show above, so that the printing procedure's implementation contains DeterminePassOrFail()

	return 0;
}





                  ////////////////////////////////// BELOW: Some UNOPTIMIZED first attempt solutions //////////////////////////////////////////
				  ////////////////////////////////// BELOW: Some UNOPTIMIZED first attempt solutions //////////////////////////////////////////
//				  ////////////////////////////////// BELOW: Some UNOPTIMIZED first attempt solutions //////////////////////////////////////////
//
///* Solution:
//   I will START this program by creating an enum user-defined data type.
//	The enum workflow will not be the regular standard one according to the mental model.
//		where the common theme in THIS CASE is:
//
//		- NO variable declared of this enum user-defined data type.
//			Meaning, the variable is neither initialized directly by assigning it to an enumeration constant (enumerator)
//		  present in the enum data type creation step.
//
//			nor initialized via reading user input, so that it is compared
//			in a switch statement against the existing enumration constants (enumerators)
//			present in the enum data type creation step.
//
//
//	This is intentional in order to hon in your skill utilizing enums.
//	PLUS we are going to improve on this program as we proceed- where the use
//	of enum will be realized as necessary.
//*/
//
//// If enums are to be used in a program, then it SHOULD be the first to EVER code in the program:
//enum enPassOrFail { Pass = 1, Fail = 0}; // the enumeration constants (enumerators), that are 'Pass' & 'Fail',  act as labels for the raw integral values they represent.
//// so from now and on FOREVER FORGET about these integral values ( 1 & 0).
//
//// so far, only an enum user-defined data type has been created and nothing else.
//// the next natural step is declaring a variable of this enum user-defined data type.
//
//
//unsigned short ReadNumber()
//{
//	unsigned short number; // what's returned.
//
//	cout << "Enter the grade (0-100): ";
//	cin >> number; 
//	cout << endl;
//
//	return number;
//}
//
//bool ValidateUnsignedShortIntegerInRange(const unsigned short& number, unsigned short min, unsigned short max) // pass by const. ref.  //ranges are ALWAYS passed by value.
//{
//	return (min <= number && number <= max);
//}
//
//
//unsigned short ReadUnsignedShortIntegerInRange(unsigned short min, unsigned short max) // ranges are ALWAYS passed by value.
//{
//	unsigned short number; // what's returned
//	do
//	{
//		number = ReadNumber(); // 'number' is to be IMMEDIATELY evaluated against the range, in the while condition
//
//	} while (!ValidateUnsignedShortIntegerInRange(number, min, max)); // the argument is written so that, it evaluates to TRUE  when the condition is INVALID (Hence the ! character).
//
//	return number;
//
//	// NOTE: The above lines of code are to be written sequentially line by line 
//	// & at the end, implement the 2 functions of ReadNumber() & ValidatePositiveIntegerInRange()
//}
//
//bool IsPassed(unsigned short number) // passing by value  // Divide & Conquer.
//{
//	return (number >= 50); // no matter how small or simple such a line is, ALWAYS wrap it in a function/ procedure.
//}
//
//enPassOrFail DeterminePassOrFail(const unsigned short &number)  // passing by constant reference.
//{
//	if (IsPassed(number))
//	{
//		return enPassOrFail::Pass;
//	}
//	else
//	{
//		return enPassOrFail::Fail;
//	}
//}
//
//
//void PrintPassOrFail(const unsigned short &number)  // passing by cosntant reference
//{
//	if (DeterminePassOrFail(number) == enPassOrFail::Pass) // enPassOrFail::Pass   equals 1 of data type enPassOrFail. SO, DeterminePassOrFail() has to return/ to be of  enPassOrFail data type (by returning enPassOrFail:: Pass   or  enPassOrFail::Fail)
//	{                                                      // because only same data types can be compared against each other.
//		cout << "Pass ! \n";
//	}
//	else
//	{
//		cout << "Failed \n";
//	}
//}
//
//int main()
//{
//	//enPassOrFail PassOrFail; // declaring a variable of the enum user-defined data type. // commented out as it turned out that we never needed it.
//   // let us start by composing the nested functions line.
//
//	unsigned short min = 0;
//	unsigned short max = 100;
//
//	PrintPassOrFail(ReadUnsignedShortIntegerInRange(min, max)); 
//	// this nested functions line is written in a way so that
//	// the implementation of the printing procedure
//	// contains an if statement with EITHER: a condition that ONLY contains a called function of return type boolean off course / 
//	//                                   OR:  a condition that contains a called function (such as in this example).
//	// 
//	// another possibility which doesn't apply to this example is to have a called function in the implementation of the printing procedure.
//
//	// Whichever case, as a by product, enables the printing procedure to reference the original mark the user enters.
//
//
//
//	return 0
//
//
//
//
///////////////////////////////////////////////// Below are some OLD UNOPTIMIZED first-attempts solutions //////////////////////////////////////////////////////////////////////////
//
//
//
///* Solution:
//   I will START this program by creating an enum user-defined data type.
//	The enum workflow will not be the regular standard one according to the mental model.
//		where the common theme in THIS CASE is:
//
//		- No variable declared of this enum user-defined data type.
//			Meaning, the variable is neither initialized directly by assigning it to an enumeration constant (enumerator) 
//          present in the enum data type creation step.
// 
//			nor initialized via reading user input, so that it is compared
//			in a switch statement against the existing enumration constants (enumerators)
//			present in the enum data type creation step.
//
//
//	This is intentional in order to hon in your skill utilizing enums.
//	PLUS we are going to improve on this program as we proceed- where the use
//	of enum will be realized as necessary.
//*/
//
//// If enums are to be used in a program, then it SHOULD be the first to EVER code in the program:
//
//enum enPassOrFail { Pass = 1, Fail = 0}; // the enumeration constants (enumerators) act as labels for the raw integral values they represent.
//// so from now and on, FORGET about these raw integral values
//
//// So far only an enum user-definded data type has been created. Nothing else
//// the next natural step is declaring a variable of this enum user-defined data type.
//
//
//float ReadMark()
//{
//	float mark; // what's returned.
//
//	cout << "Enter mark: ";
//	cin >> mark;
//	cout << endl;
//
//	return mark;
//	// The variable 'mark' WAS initialized, and THEN returned.
//	// It was returned to the called function that evaluates to produce a value of float type (which initializes the object in the called function).
//	//
//	// The lifetime of the local variable 'mark' ends when the program exists the curly brackets of this function.
//}
//
//
//enPassOrFail DeterminePassOrFail(float mark) // pass by value    //  فَرِّقْ تَسُدْ/Divide & conquer:   Passing by constant reference as we're just comparing.
//{                                                                // I can now use this function anywhere in my code- for ex: to be an argument for a future function/procedure etc.
//	if (mark >= 50)
//	{
//		return enPassOrFail::Pass;     // = 1 ( of data type enPassOrFail)
//	}
//	else
//	{
//		return enPassOrFail::Fail;   // = 0 ( of data type enPassOrFail)
//	}
//}
//
//void PrintPassOrFail(const float &mark)   // passing by const ref.      // فَرِّقْ تَسُدْ  / Dive & conquer.
//{
//	if (enPassOrFail::Pass == DeterminePassOrFail(mark))  // "enPassOrFail::Pass" returns 1 & is in and by itself of type enPassOrFail  // فَرِّقْ تَسُدْ  / Dive & conquer.
//	
//	{
//		cout << mark << " is " << "Pass \n";
//	}
//	else
//	{
//		cout << mark << " is " << "Fail \n";
//	}
//}
//
//
//
//int main()
//{
//	//enPassOrFail PassOrFail; // declaring a variable of the enum user-defined data type. // commented out as it turned out that we never needed it.
//	// let us start by composing the nested functions line.
//
//	PrintPassOrFail(ReadMark()); // Nesting this way, enables the printing procedure to reference the original mark the user enters.
//
//	/* whereas:
//	 
//	 PrintPassOrFail(DeterminePassOrFail(Readmark))); 
//	// will not enable the printing procedure to reference the mark the user entered unless we complicate this line further by having:
//	   
//	   PrintPassOrFail(DeterminePassOrFail(Readmark), mark));  
//	   // which is unoptimized.
//
//	
//	*/
//
//	return 0;
//}
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// My first solution:
//float ReadGrade()
//{
//	float grade; // what is returned
//
//	cout << "Enter a grade: ";
//	cin >> grade;
//	cout << endl;
//
//	return grade;
//
//}
//
//string GradingResult(const float &grade) // passing by const reference 
//{
//	if (grade >= 50)
//	{
//		return "Pass";   // always try to return something instead of printing. As printing (= a procedure) would make the use of this procedure limited.
//	}                    // Instead, make this function returns a value and then we could do MANY things with this returned value such as printing 
//	
//	else 
//	{
//		return "Fail";
//	}
//}
//
//void PrintResult(const float &grade) // pass by constant reference (creating an alias to the value existing in main())
//{
//	cout << grade << " is " << GradingResult(grade) << endl;
//}
//
//
//int main()
//{
//  
//	PrintResult(ReadGrade()); // the argument must be a function that returns ONE value. a procedure returns void which can never be an argument of  this procedure.
//
//	return 0;
//}
//
//

