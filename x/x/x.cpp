
#include <iostream>
using namespace std;



/*
 Problem:

 Write a program to ask the user to enter his/her:
 • Age
 • Driver license
 • Has Recommendation!

 Then Print "Hired" if his\her age is greater than 21 and s/he has a driver license, otherwise Print "Rejected"

 Or If they have recommendation, then Hire him\her without conditions! (regardless of age and whether they have a driver license)
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

bool ValidateApplicantInfoAge(const unsigned short &age, unsigned short min, unsigned short max)   // this is a user-input range validation that has NOTHING to do with the question requiremt of age value/ number.
{
	return ( min <= age && age <= max); // I type min, max, & age variables. At the very very end before finalizing this program, I implemented the parameters and this is when this was needed.
}

bool ReadApplicantInfo_HasDriverLicense()
{
	bool HasDriverLicense; // what's returned.

	cout << "Do you have a Driver's License ? (Enter  1 for Yes / 0 for No): ";
	cin >> HasDriverLicense;
	cout << endl;

	return HasDriverLicense;
}

bool ValidateReadApplicantInfo_HasDriverLicense(const bool &HasDriverLicense) // pass by constant reference // this is a user-input range validation.
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

bool ValidateReadApplicantInfo_HasRecommendation(const bool &HasRecommendation)  //passing by constant reference. this is a user-input range validation.
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
}

bool IsHired(stApplicantInfo ApplicantInfo) // passing by value // WHENEVER you see this argument, ALWAYS envision the variable having access to ALL member variables inside the structure.
{
	return ((ApplicantInfo.age > 21 && ApplicantInfo.HasDriverLicense) || ApplicantInfo.HasRecommendation);
}

void PrintHiredOrNot(const stApplicantInfo& ApplicantInfo)  // passing by constant reference.
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

	return 0;
}



