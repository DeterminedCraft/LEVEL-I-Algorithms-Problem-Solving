// Problem #5.cpp

#include <iostream>
using namespace std;

/*
 Problem:

 Write a program to ask the user to enter his/her:
 • Age
 • Driver license
 • Has Recommendation!

 Then Print "Hired" if his\her age is grater than 21 and s/he has a driver license, otherwise Print "Rejected"

 Or If they have recommendation, thenm Hire him\her without conditions! (regardless of age and whether they have a driver license)
*/



struct stApplicantInfo
{
	unsigned short age;
	bool HasDriverLicense;
	bool HasRecommendation;
};
// so far, only a structure user-defined data type has been created. That's all.
// the next natural step is creating a variable of this structure user-defined data type.
// that's either a normal variable (ONE record) or an array variable (MORE than one record)
// 
// But the main questions is - Where to create this variable ?
// If it's going to be initialized directly, then declare it in main()
// If it's going to be initialized via reading user input, then declare it inside a function of the structure user-defined data type, that returns this variable.
// Since it's the latter, then IMMEDIATELY start implementing this function NOW below:


unsigned short ReadApplicantInfoAge()
{
	unsigned short age; // what's returned.

	cout << "Enter age: ";
	cin >> age;
	cout << endl;

	return age;
}

bool ValidateApplicantInfoAge(const unsigned short& age, unsigned short min, unsigned short max)   // this is a user-input range validation that has NOTHING to do with the question requiremt of age value/ number.
{
	return (min <= age && age <= max); // I type min, max, & age variables. At the very very end before finalizing this program, I implemented the parameters and this is when this was needed.
}

bool ReadApplicantInfo_HasDriverLicense()
{
	bool HasDriverLicense; // what's returned.

	cout << "Do you have a Driver's License ? (Enter  1 for Yes / 0 for No): ";
	cin >> HasDriverLicense;
	cout << endl;

	return HasDriverLicense;
}

bool ValidateReadApplicantInfo_HasDriverLicense(const bool& HasDriverLicense) // pass by constant reference // this is a user-input range validation.
{
	return  1; // "Skipping this part as we'll learn how to do user-input range validation for booleans in the upcoming Level 2 C++ course;
	// Any non-zero value assigned to a bool in C++ is automatically converted to true. so if the user enters 3, then 1 (true) will be stored in the boolean variable.";
}

bool ReadApplicantInfo_HasRecommendation()
{
	bool HasRecommendation;  // what's returned.

	cout << "Do you have a recommendation ? (Enter 1 for Yes / 0 for No): ";
	cin >> HasRecommendation;
	cout << endl;

	return HasRecommendation;
}

bool ValidateReadApplicantInfo_HasRecommendation(const bool& HasRecommendation)  //passing by constant reference. this is a user-input range validation.
{
	return 1;
	//"Skipping this part as we'll learn how to do user-input range validation for booleans in the upcoming Level 2 C++ course";
}


stApplicantInfo ReadApplicantInfo(unsigned short min, unsigned short max) // pass by
{
	stApplicantInfo ApplicantInfo; // what's returned // the next natural step of declaring a variable of the structure user-defined data type. 
	// WHENEVER you see this line, ALWAYS envision the fact that this variable has access to all member variables declared inside the structure.
	do
	{
		ApplicantInfo.age = ReadApplicantInfoAge(); // "ApplicantInfo.age" is to be IMMEDIATELY validated against the range in the while condition

	} while (!ValidateApplicantInfoAge(ApplicantInfo.age, min, max)); // the argument is written so that it evaluates to TRUE when the condition is INVALID (hence the ! character).

	do
	{
		ApplicantInfo.HasDriverLicense = ReadApplicantInfo_HasDriverLicense(); // "ApplicantInfo.HasDriverLicense" is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateReadApplicantInfo_HasDriverLicense(ApplicantInfo.HasDriverLicense)); // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

	do
	{
		ApplicantInfo.HasRecommendation = ReadApplicantInfo_HasRecommendation(); // "ApplicantInfo.HasRecommendation" is to be evaluated against the range in the while condition.

	} while (!ValidateReadApplicantInfo_HasRecommendation(ApplicantInfo.HasRecommendation)); // the argument is written so that it evaluates to TRUE  when the condition is INVALID.

	return ApplicantInfo;

	// Note: The above lines of code, are to be written sequentially/ line-by-line
	// & at the end, start implementing the 6 functions of: 
	// ReadApplicantInfoAge(), ValidateApplicantInfoAge(), ReadApplicantInfo_HasDriverLicense(), ValidateReadApplicantInfo_HasDriverLicense(),
	// ReadApplicantInfo_HasRecommendation(), & ValidateReadApplicantInfo_HasRecommendation().


	// Note:
	// the variable 'PersonalInfo' WAS fully initialized with all member variables (PersonalInfo. age,   PersonalInfo.HasDriverLicense,  & PersonalInfo.HasRecommendation)
	// and THEN returned to the calling function.
	// The calling function evaluates to produce value of type stPersonalInfo (which initialized the object in the calling function)
	//
	// The lifetime of the local variable PersonalInfo ends when the program exists the curly brackets of this function.
}


// Divide & conquer /فَرِّقْ تَسُدْ   alway include inside a function. No matter how smaller this line could be.
bool IsHired(stApplicantInfo ApplicantInfo) // passing by value // WHENEVER you see this argument, ALWAYS envision the variable having access to ALL member variables inside the structure.
{
	return ((ApplicantInfo.age > 21 && ApplicantInfo.HasDriverLicense) || ApplicantInfo.HasRecommendation);
}

void PrintHiredOrNot(const stApplicantInfo& ApplicantInfo)  // passing by constant reference. // WHENEVER you see this argument, ALWAYS envision the variable having access to ALL member variables inside the structure.
{
	if (IsHired(ApplicantInfo))
	{
		cout << "Hired !\n";
	}
	else
	{
		cout << "Not hired \n";
	}
}


int main()
{

	// instead of declaring 'age', 'HasDriverLicense', & 'HasRecommendation' as variables in main(),
	// declare them as member variables inside a structure since they're related amongst each other.

	unsigned short min = 1;
	unsigned short max = 120;

	PrintHiredOrNot(ReadApplicantInfo(min, max));
	

	/* CRUCIAL NOTE:

	   If possible, STRIVE to have a printing procedure, that contains an if statement with an argument calling a boolean function
	   (it has to be a function returning a boolean data type anyway).
	   (Only if possible & when it's logical to do so).

	   Now when you do that, you'll have:
	   PrintHiredOrNot(ReadApplicantInfo());       Instead of:   

	   PrintHiredOrNot(DecideHiredorNot(ReadApplicantInfo());
	   which is an inferior design.


		   OR:

	   -a called function/procedure.

	   If it turns out, at the very end and after running the program, that the printing procedure references the value of a variable that it prints out
	   then,
	   in the nested functions line inside main(), replace the printing procedur with a:  cout <<
	   statement since we're only printing one variable as opposed to, for example, s structure comprised of multiple variables.
	
	*/
	return 0;
}



///////////////////////////////////////// Below: some first attempt solutionS//////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct stPersonalInfo
{
	unsigned int age;
	bool HasDriverLicense;
	bool HasRecommendation;
};
// so far only a structure user-defined data type has been created and nothing else.
// the next natural step is to declare a variable of this structure user-defined data type.
// It could be a normal variable (one record)  or  an array variable (more than one record)-
//
// But the main question is, WHERE should this variable be declared ?
	 // If it's going to be initialized directly, then declare the variable in main()
    // If it's going to be initialized via reading user input, then declare it in a reading function of type structure, that returns this declared variable
		// since it's the former, then start implementing this reading function IMMEDIATELY NOW:

stPersonalInfo ReadPersonalInfo()
{
	stPersonalInfo PersonalInfo;  //the natural step of declaring a variable of this structure user-defined data type. // what's returned.

	cout << "Enter age: ";
	cin >> PersonalInfo.age;
	cout << endl;

	cout << "Do you have a driver license ? (Enter 1 for Yes / Enter 0 for No): ";
	cin >> PersonalInfo.HasDriverLicense;
	cout << endl;

	cout << "Do you have a recommendation ? (Enter 1 for Yes / Enter 0 for No): ";
	cin >> PersonalInfo.HasRecommendation;
	cout << endl;

	return PersonalInfo; 
	// the variable 'PersonalInfo' WAS fully initialized with all member variables (PersonalInfo. age,   PersonalInfo.HasDriverLicense,  & PersonalInfo.HasRecommendation)
	// and THEN returned to the calling function.
	// The calling function evaluates to produce value of type stPersonalInfo (which initialized the object in the calling function)
	//
	// The lifetime of the local variable PersonalInfo ends when the program exists the curly brackets of this function.

	// Now. we write the nested functions line in main()
}

bool IsHired(stPersonalInfo PersonalInfo) // pass by value
{
	return ((PersonalInfo.age > 21 && PersonalInfo.HasDriverLicense) || PersonalInfo.HasRecommendation);  // Divide & conquer /فَرِّقْ تَسُدْ   alway include inside a function. No matter how smaller this line could be.
}

void PrintHiredOrNot(const stPersonalInfo& PersonalInfo) // passing by const reference. // again remember- The argument line helps us envision the access to all member variables.
{                                                        // The name of the variable PersonalInfo could've been anything really !.
	if (IsHired(PersonalInfo))
	{
		cout << "Hired ! \n";
	}
	else
	{
		cout << "Not Hired... \n";
		cout << endl;
	}


}
int main()
{
 /*
    Since these variables are related amongst each other, I will not declare them in main().
	Instead, I will declare them as member variables inside a structure.
 */

	PrintHiredOrNot(ReadPersonalInfo()); // the function argument must be a function. As procedures return void which can NEVER be the argument of a function/ procedure.
	// This is how trhe instructor solved it using this line.


	// Maybe as an exercise try:      PrintHiredOrNot(IsHired(ReadPersonalInfo()));

	return 0;
}





//
///* Old Solution:
//   Instead of declaring these 3 as variables in main(), I will declare them as member variables
//   inside a structure since they are related amongst each other.
// 
// */
//
//struct stUserInfo
//{
//    unsigned short age;
//    bool HasDriverLicense;
//    bool HasRecommendation;
//};
//// so far we have created a structure user-defined data type and that's all.
//// the next natural step is to declare a variable of this structure user-defined data type.
//// that is either a normal variable (for one record) or an array variable (for more than one record).
////
//// but the question is, how is it going to be initialized ?
//// directly ?, then declare this variable in main()
//// or via reading user input ?, then declare this variable in a reading function of this structure data type
//// that returns this variable.
//
//// now, we start by creating a nested function line in main().
//
//
//
//stUserInfo ReadUserInput()
//{
//    stUserInfo UserInfo; // ONLY declare a variable of the nesting structure (never the nested one(s))   and/or   independent structure(s).
//
//    cout << "Enter Age: ";
//    cin >> UserInfo.age;
//    cout << endl;
//
//    cout << "Do you have a Driver License (Enter 1 for Yes / Enter 0 for No): ";
//    cin >> UserInfo.HasDriverLicense;
//    cout << endl;
//
//    cout << "Do you have a recommendation (Enter 1 for Yes / Enter 0 for No): ";
//    cin >> UserInfo.HasRecommendation;
//    cout << endl;
//
//    return UserInfo;
//    // The variable 'UserInfo' will be returned FULLY initialized with: 
//    // age, HasDriverLisence, & HasRecommendation.
//    // 
//    // Note: The lifetime of this variable ends when the function scope ends.
//}
//
//bool IsHired(const stUserInfo& UserInfo)  //فَرِّق تسُد / Divide & conquor   // Also useful because the returned value can be reused in other functions if needed.
//
//{
//    return ((UserInfo.age > 21 && UserInfo.HasDriverLicense) || UserInfo.HasRecommendation);
//}
//
//void PrintHiringDecision(const stUserInfo& UserInfo) // passing by constant reference : means the procedure receives a reference to the existing object rather than copying it into a new memory space within the function’s scope.
//{
//    if (IsHired(UserInfo)) // فَرِّق تسُد  / Divide & conquor  ( why write the code here while you can apply divided & conquer as much as you can ?)
//    {
//        cout << "Hired  \n";
//    }
//    else
//    {
//        cout << "Rejected ! \n";    
//    }
//}
//
//
//int main()
//{
//    
//    PrintHiringDecision(ReadUserInput());
//
// /*
//  ReadUserInput() evaluates to a fully initialized object of type stUserInfo
//  that contains the values of:
//  - UserInfo.age
//  - UserInfo.HasDriverLicense
//  - UserInfo.HasRecommendation.
//
//  The fully initialized object is then passed directly to PrintHiringDecision().
//*/
//
//
//    return 0;
//}
//
