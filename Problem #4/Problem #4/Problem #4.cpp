
#include <iostream>
using namespace std;

/*
 Problem #4:

 Write a program to ask the user to enter his/her:
 - Age
 - Driver license

 Then print "Hired" if his/her age is greater than 21 and he/she has a driver license,
 otherwise print "Rejected".

*/


struct stUserInfo
{
	unsigned short age;
	bool HasDriverLicense;
};
// so far, only a structure user-defined data type has been created. That's all.
// the next natural step is declaring a variable of this structure user-defined data type.
// It's either a normal variable (ONE record) or an array variable (MORE than one record).
//
//but the question is- where to declare this variable ?
// -If it's going to be initialized directly, then declare it inside main().
// -If it's going to be initialized via reading user input, then declare it inside a function of the structure data type that returns this variable.
// since it's the latter, then IMMEDIATELY implement this function below NOW:



unsigned short ReadUserInfoAge(const string& Message1)  // pass by constant reference.
{
	unsigned short number; // what's returned

	cout << Message1;
	cin >> number;
	cout << endl;

	return number;
}

bool ValidateUserInfo_HasDriverLicense(const int &number)  // pass by constant reference.
{
	return (number == 0 || number == 1);
}

// Below is a user-input range validation that has NOTHING to do with the age of 21 requirement mentioned in the question.
bool ValidateUserInfo_age(const unsigned short& age, unsigned short max)   // pass by constant reference  // validating the range of the number entered for age- IT HAS NOTHING TO DO with the requirementof 21 in the problem 
{
	return (age < max); 
}

bool ReadUserInfo_HasDriverLicense(const string &Message2)
{
	int number; // what's returned   // bool number;    is problematic as inputing any value other than 0, will be stored as 1 (true) before validation even begins. 
	                                // Example, entering 3 will be stored as 1 before validation even begins.
	do
	{ 
	cout << Message2;
	cin >> number;  // to be IMMEDIATELY validated against the range, in the while condition.
	cout << endl;

	} while (!ValidateUserInfo_HasDriverLicense(number));  // 👈 👈 the argument is written so that, it evaluates tp TRUE when the condition is INVALID. (hence the ! character).


	return number; // number (that's either 1 or 0) will have to be converted to boolean before it's returned.
}

stUserInfo ReadUserInfo(const string &Message1, const string &Message2, unsigned short max)  // argument 'max' was added at the very end when writing the program was almost complete //pass by constant reference. // ranges ALWAYS passed by value.
{
	
	stUserInfo UserInfo; // what's returned  //the next natural step of declaring a variable of this structure user defined data type.
	// Tip: whenever you see a similar line ANYWHERE in this or other program, ALWAYS envision that UserInfo has access to all member variables within the structure.
	do
	{ 
		UserInfo.age = ReadUserInfoAge(Message1);  // 'UserInfo.age' is to be IMMEDIATELY evaluated against the range, in the while condition.
		
	} while (!ValidateUserInfo_age(UserInfo.age, max));


	// wrapping the below boolean function in a do while statement is conducive to one MAJOR bug. 
	// Because if the user enters a non 0 or 1 value, then this value will be stored as 1 (true) in the boolean variable BEFORE the range validation even begins.
	UserInfo.HasDriverLicense = ReadUserInfo_HasDriverLicense(Message2);                                                                    
	                                                                  
	return UserInfo;

	// NOTE: The above lines of code are to be written line by line
	// and at the end, implement the functions of: 
	// ReadUserInfo_age(), ValidateUserInfo_age(), ReadUserInfo_HasDriverLicense(), ValidateUserInfo_HasDriverLicense()


	/* The variable 'UserInfo' WAS initialized with all member variables(UserInfo.age & UserInfo.HasDriverLicense) and THEN returned to the calling function.
	 The called function, ReadPersonalInfo(), evaluates to produce a value of type stPersonalInfo (which initializes the object in the called function).

	 The lifetime of the local variable 'PersonalInfo' ends when the program exists the curly functions of this function.
	 🔥🔥🔥 correct !
	 Now is the time to construct the nested functions line in main() */
}

bool IsHired(stUserInfo UserInfo) // pass by value.
{
	return (UserInfo.age > 21 && UserInfo.HasDriverLicense);
}

void PrintHiredOrNot(const stUserInfo& UserInfo) // pass by constant reference. // as soon as you see this argument line, envision access to all member variables defined in the structure.
{
	if (IsHired(UserInfo))
	{
		cout << "Hired ! \n";
	}
	else
	{
		cout << "Not hired \n";
	}
}


int main()
{
	// Instead of declaring 'age' & 'HasDriverLicense' as variables inside main(),
	// I'm going to declare them as member variables inside a structure since they're related amongst each other.

	unsigned short max = 160; // added it near the end when I needed it.

	PrintHiredOrNot(ReadUserInfo(" Enter your age: ", " Do you have a driver license ? (Enter 1 for yes  /  Enter 0 for no): "   ,max));

	return 0;
}

/* CRUCIAL NOTE:

   - If possible, STRIVE to have a printing procedure, that contains an if statement with an argument calling a BOOLEAN FUNCTION
   (it has to be a function returning a boolean data type anyway).
   (Only if possible & when it's logical to do so).

   Now when you do that, you'll have:

   PrintHiredOrNot(ReadApplicantInfo())       Instead of:

   PrintHiredOrNot(DecideHiredorNot(ReadApplicantInfo());   which is an inferior design as shown in the UNOPTIMIZED VERSION of this code below.


	   OR:

   -a called function/procedure.

   ***totally separate note:

   If it turns out, at the very end and after running the program, that the printing procedure references the value of a variable that it prints out
   then,
   in the nested functions line inside main(), replace the printing procedur with a:  cout <<
   statement since we're only printing one variable as opposed to, for example, s structure comprised of multiple variables.








/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// BELOW: first-attempt UNOPTIMIZED solutions: ///////////////////////////////////////////////////////////////////


//struct stApplicantInfo
//{
//	unsigned short age;
//	bool HasDriverLicense;
//};
//// so far, only a structure user defined data type has been declared and nothing more.
//// The next natural step is declaring a variable of this structure user-defined data type
//// that's either going to be a normal variable (ONE record) or an array variable (MORE than one record).
////
//// But the main questions is- Where to declare this variable ?
////  - if it's going to be initialized directly, then declare it inside main().
////  - if it's going to be initialized via reading user-input, then declare it inside a function of the structure data type, that'll return this declared variable.
//// 
//// Since it's the latter, then IMMEDIATELY implement this function NOW below:
//
//
//
//unsigned short ReadApplicantInfoAge()
//{
//	unsigned short age; // what's returned.
//
//	cout << "Enter age: ";
//	cin >> age;
//	cout << endl;
//
//	return age;
//}
//
//
//bool ValidateApplicantInfoAge(const unsigned short& age, unsigned short min, unsigned short max) // passing by constant reference.  // this is a user-input range validation that has NOTHING to do with the question requiremt of age value/ number.
//{
//	return (min <= age && age <= max);  // I type min, max, & age variables. At the very very end before finalizing this program, I implemented the parameters and this is when this was needed.
//}
//
//
//bool ReadApplicantInfo_HasDriverLicense()
//{
//	bool HasDriverLicense; // what's returned.
//
//	cout << "Do you have a driver license ? ( Enter:  1 for Yes / 0 for No): ";
//	cin >> HasDriverLicense;
//	cout << endl;
//
//	return HasDriverLicense;
//}
//
//bool ValidateReadApplicantInfo_HasDriverLicense(const bool& HasDriverLicense) // passing by constant reference.
//{
//	return  1; // "Skipping this part as we'll learn how to do user-input range validation for booleans in the upcoming Level 2 C++ course;
//	// Any non-zero value assigned to a bool in C++ is automatically converted to true. so if the user enters 3, then 1 (true) will be stored in the boolean variable.";
//}
//
//
//
//stApplicantInfo ReadApplicantInfo(unsigned short min, unsigned short max)  // ALL of the arguments were added at the very end of writing this program when it turned out that they were needed.
//{
//	stApplicantInfo ApplicantInfo; // what's returned // the next natural step of declaring a variable of this structure user defined data type.
//	// Tip: whenever you see a similar line ANYWHERE in this or other program, ALWAYS envision that ApplicantInfo has access to all member variables within the structure.
//	do
//	{
//		ApplicantInfo.age = ReadApplicantInfoAge(); // 'ApplicantInfo.age' to be IMMEDIATELY evaluated against the range in the while condition.
//
//	} while (!ValidateApplicantInfoAge(ApplicantInfo.age, min, max));  // the argument is written so that it evaluates to TRUE when the condition is INVALID (hence the ! character). 
//	 // this is input range validation that HAS NOTHING to do with 21 or any other number that changes in the question for securing the job.
//
//
//	do
//	{
//		ApplicantInfo.HasDriverLicense = ReadApplicantInfo_HasDriverLicense(); // 'ApplicantInfo.HasDriverLicense' to be IMMEDIATELY validated against the range in the while condition.
//
//	} while (!ValidateReadApplicantInfo_HasDriverLicense(ApplicantInfo.HasDriverLicense));     // the argument is written so that it evaluates to TRUE  when the condition is INVALID.
//
//	return ApplicantInfo;
//	// Note: The above block of code is to be sequentially composed line-by-line
//	// & at the end, implement the 4 functions of:  ReadApplicantInfoAge(),  ValidateApplicantInfoAge(),  ReadApplicantInfo_HasDriverLicense(),  ValidateReadApplicantInfo_HasDriverLicense()
//
//
//	/* The variable 'PersonalInfo' WAS initialized with all member variables(PersonalInfo.age & PersonalInfo.HasDriverLicense) and THEN returned to the calling function.
//	 The called function, ReadPersonalInfo(), evaluates to produce a value of type stPersonalInfo (which initializes the object in the called function).
//
//	 The lifetime of the local variable 'PersonalInfo' ends when the program exists the curly functions of this function.
//	 🔥🔥🔥 correct !
//	 Now is the time to construct the nested functions line in main() */
//}
//
//
////  فَرِّقْ تَسُدْDivide & Conquer 
//bool IsHired(stApplicantInfo ApplicantInfo) // passing by value // Tip: whenever you see a similar line ANYWHERE in this or other program, ALWAYS envision that ApplicantInfo has access to all member variables within the structure.
//{
//	return (ApplicantInfo.age > 21 && ApplicantInfo.HasDriverLicense);
//}
//
//
//void PrintHiringDecision(const stApplicantInfo& ApplicantInfo)  // passing by constant reference. // WHENEVER you see this argument, ALWAYS envision the variable having access to ALL member variables inside the structure.
//{
//	if (IsHired(ApplicantInfo))
//	{
//		cout << "Hired ! \n";
//	}
//	else
//	{
//		cout << "Not hired \n";
//	}
//}
//
//
//int main()
//{
//	/*  Instead of declaring "age" & "HasDrivingLicense" as variables in main(),
//		declare them as member variables in a structure, since they're related
//		amongst each other.
//
//
//
//	*/
//	unsigned short min = 1;
//	unsigned short max = 120;
//
//	PrintHiringDecision(ReadApplicantInfo(min, max));
//
//	return 0;
//}
	
	

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////// Below are some first attempt UNOPTIMIZED SOLUTIONS //////////////////////////////////////////////////////////////////
/////////////////////////////////////////// Below are some first attempt UNOPTIMIZED SOLUTIONS //////////////////////////////////////////////////////////////////
/////////////////////////////////////////// Below are some first attempt UNOPTIMIZED SOLUTIONS //////////////////////////////////////////////////////////////////
//
//struct stPersonalInfo
//{
//	unsigned short age;
//	bool HasDriverLicense;
//};
//// so far only a structure user-defined data type has been created. That's all.
//// The next natural step is declaring a variable of this structure user-defined data type.
//// It's going to be either a normal variable (one record)  or  an array variable (more than one record).
////
//// But the question is, where should this variable be declared ?
////   if it's going to be initialized directly, then declare it in main()
////   it it's going to be initialized via reading user input, then declare it in a reading function of type structure that returns this declared variable.
// // since it's the former, then start by implementing this function IMMEDIATELY NOW:
//
//stPersonalInfo ReadPersonalInfo()
//{
//	stPersonalInfo PersonalInfo; // The next natural step of declaring a variable of the structure user-defined data type // What's returned.
//	// (you SHOULD immediately envision that personalInfo has access to all member variables inside this stPersonalInfo structure user-defined data type
//	// as in PersonalInfo.age,     PersonalInfo.HasDriverLicense   ANYWHERE in the program when you encounter such a line)
//	
//	cout << "Enter your age: ";
//	cin >> PersonalInfo.age;
//	cout << endl;
//
//	cout << "Do you have a driver license ? ( Enter 1 for Yes  /  0 for No): ";
//	cin >> PersonalInfo.HasDriverLicense;
//	cout << endl;
//
//	return PersonalInfo;
//	// The variable 'PersonalInfo' WAS initialized with all member variables (PersonalInfo.age   &   PersonalInfo.HasDriverLicense) and THEN returned to the calling function.
//	// The called function, ReadPersonalInfo(), evaluates to produce a value of type stPersonalInfo (which initializes the object in the called function).
//	//
//	// The lifetime of the local variable 'PersonalInfo' ends when the program exists the curly functions of this function.
//	// 🔥🔥🔥 correct !
//	// Now is the time to construct the nested functions line in main()
//}
//
//
//     //  فَرِّقْ تَسُدْDivide & Conquer 
//bool IsHired(stPersonalInfo PersonalInfo) // pass by value. // the name of the variable PersonalInfo could've been anything.
//{
//	return (PersonalInfo.age > 21 && PersonalInfo.HasDriverLicense);   // Divide & conquer / فَرِّقْ تَسُدْ -you ALWAYS put this inside a function even if it is a tinier line ! 
//}
//
//void PrintHiringDecision(const bool &HiredOrNot) // pass by const ref.  // avoid naming the variable 'IsHired' as this is the name of an existing function in this program.
//{                                                                       // this is not ideal and may cause confusion even though our program will still work.
//	if (HiredOrNot)
//	{
//		cout << "Hired! \n";
//	}
//	else
//	{
//		cout << "Not Hired... \n";
//	}
//}
//
//
//int main()
//{
// // These variables will not be declared in main(),
// // but instead, they will be declared as member variables in a structure since they are related amongst each other.
//
//
//	PrintHiringDecision(IsHired(ReadPersonalInfo())); // The arguments have to be functions. As procedures return void which can NEVER be the argument of a function/procedure.
//
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////S

/* Now- what if I replace the above line in main():

  PrintHiringDecision(IsHired(ReadPersonalInfo()));

  with 

   PrintHiringDecision(ReadPersonalInfo());    ?    // This is what the instructor used and this should move to the top of the program with all of the comments.
   // so let us design this program according to this new 'requirement'.   

*/
//
//
//struct stPersonalInfo
//{
//	unsigned int age;
//	bool HasDriverLicense;
//};
//
//
//stPersonalInfo ReadPersonalInfo()
//{
//	stPersonalInfo PersonalInfo;
//
//	cout << "Enter age: ";
//	cin >> PersonalInfo.age;
//	cout << endl;
//
//	cout << "Do you have a driver liscense ? ( Enter 1 for Yes / Enter 0 for No): ";
//	cin >> PersonalInfo.HasDriverLicense;
//	cout << endl;
//
//	return PersonalInfo;
//}
//
//bool IsHired(stPersonalInfo PersonalInfo) // pass by value
//{
//	return (PersonalInfo.age > 21 && PersonalInfo.HasDriverLicense);
//}
//
//void PrintHiredOrNot(const stPersonalInfo &PersonalInfo) // pass by const reference
//{
//	if (IsHired(PersonalInfo))
//	{
//		cout << "Hired !... \n";
//    }
//	else
//	{
//		cout << "Not Hired... \n";
//	}
//}
//
//int main()
//{
//
//
//	PrintHiredOrNot(ReadPersonalInfo());
//
//	return 0;
//}
//
//














































