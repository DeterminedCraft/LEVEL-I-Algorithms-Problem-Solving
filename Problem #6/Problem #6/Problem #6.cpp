
#include <iostream>
#include <string>
using namespace std;

/*
 Problem:

 Write a program to ask the user to enter:
 - First Name
 - Last Name

 Then print Full Name on screen.

 Example Input:
 Mohammed
 Abu Hadhoud

 Output:
 Mohammed Abu-Hadhoud
*/



struct stFirstAndLastName
{
	string FirstName;
	string LastName;
};
// so far, only a structure user-defined data type has been created and nothing more.
// the next natural step, is creating a variable of this structure user-defind data type
// it's either going to be a normal variable (ONE record) or an array variable (MORE than one record).
//
// But the most important question is - Where to declare this variable ?
// - if it's going to be initialized directly, then declare it inside main()
// - if it's going to be initialized via reading user-input, then declare it inside a reading function of this structure user-defined data type that returns this variable.
// since it's the latter, then IMMEDIATELY implement this function NOW below:


string ReadName(const string &message) // pass by constant reference
{
	string name; // what's returned

	cout << message;
	getline(cin, name);    // for string // so one needs to include, on top, #include <string>
	cout << endl;

	return name;
}

bool ValidateFirstAndLastName(const string &name, unsigned short MinNameLength, unsigned short MaxNameLength) // passing by constant value  // ranges ALWAYS passed by value.
{
	return (name.length() >= MinNameLength && name.length() <= MaxNameLength); 
}

stFirstAndLastName ReadFirstAndLastName(const string &MessageFirstName, const string &MessagelastName, unsigned short MinNameLength, unsigned short MaxNameLength) // passing by constant reference.  // ranges ALWAYS passed by value.
{
	stFirstAndLastName FirstAndLastName; // what's returned   // the next natural step of declaring a variable of the structure user-defined data type.
	                                     //AS SOON AS you view such a line, ALWAYS envision the access of the variable to all member variables inside the structure.
	do
	{
		FirstAndLastName.FirstName = ReadName(MessageFirstName); // "FirstAndLastName" is to be IMMEDIATELY validated against the range, in the while condition.

	} while(!ValidateFirstAndLastName(FirstAndLastName.FirstName, MinNameLength, MaxNameLength)); // 👉👉the argument is written so that, it evaluates to TRUE when the condition is INVALID. Hence the ! sign.

	do
	{
		FirstAndLastName.LastName = ReadName(MessagelastName); // "FirstAndLastName.LastName" is to be IMMEDIATELY validated against the range, in the while condition

	} while (!ValidateFirstAndLastName(FirstAndLastName.LastName, MinNameLength, MaxNameLength));  // 👉👉the argument is written so that, it evaluates to TRUE when the condition is INVALID. Hence the ! sign.

	return FirstAndLastName;
	
	 //NOTE: The above lines of code are to be sequentially composed line by line
	//      and at the end, implement the functions of:
   //      ReadName(), ValidateFirstAndLastName()
}

string ConcatenateFirstAndLastName(stFirstAndLastName FirstAndLastName)  // pass by value.
{
	return FirstAndLastName.FirstName + " " + FirstAndLastName.LastName;
}

void PrintFullName(const stFirstAndLastName &FirstAndLastName) // pass by constant reference. // WHENEVER you see this line, IMMEDIATELY envision the variable having access to all member variables inside the structure.
{
	cout << "The full name is: " << ConcatenateFirstAndLastName(FirstAndLastName) << endl; 
}

int main()
{
	// instead of declaring 'FirstName' & 'LastName' as variables in main(),
	// declare them as member variables inside a structure since they're related amongst eath other.

	unsigned short MinNameLength = 2; // added at the very end when it was needed.
	unsigned short MaxNameLength = 15; //added at the very end when it was needed.

	PrintFullName(ReadFirstAndLastName(" Enter the first name: ", " Enter the second name: ", MinNameLength, MaxNameLength));   // composed with the concept in mind that the printing procedure's implementation will containt the function ConcatenateFirstAndLastName()
	// thereafter, the string messages and ranges are added.


	return 0;

	/* CRUCIAL NOTE:

	   If possible, STRIVE to have a printing procedure, that contains an if statement with an argument calling a boolean function
	   (it has to be a function returning a boolean data type anyway).
	   (Only if possible & when it's logical to do so).

		or:

	   -a called function/procedure.

	   Atotally separate not: 
	   If it turns out, at the very end and after running the program, that the printing procedure references the value of a variable that it prints out
	   then,
	   in the nested functions line inside main(), replace the printing procedur with a:  cout <<
	   statement since we're only printing one variable as opposed to, for example, a structure comprised of multiple variables.

	*/
}





                   /////////////////////////Below: First-attempt unoptimized solution ////////////////////////////////////////
                  /////////////////////////Below: First-attempt unoptimized solution ////////////////////////////////////////
                 /////////////////////////Below: First-attempt unoptimized solution ////////////////////////////////////////


struct stFullName
{
	string FirstName;
	string LastName;
};
// so far only a structure user-defined data type has been created and nothing more.
// the next natural step is declaring a variable of this structure user-defined data type.
// that's either going to be a normal variable (ONE record) or an array variable (MORE than one record)
//
// The main question is - Where are you going to declare this variable ?
//  - if it's going to be initialized directly, then declare it inside main()
//  - if it's going to be initialized via reading user input, then declare it inside a function of this structure data type, that will return this variable.
// since it's the latter, then IMMEDIATLEY start by implementing this function NOW below:

string ReadFirstName()
{
	string FirstName;  // what's returned.

	cout << "Enter First Name: ";
	getline(cin, FirstName); // ALWAYS user getline(cin,x) for strings where #include <string> is needed. // Note: cin << x is only for non-string numerical values.
	cout << endl;

	return FirstName;
}

bool ValidateFirstName(const string& FirstName)  // pass by constant reference.
{
	return (FirstName.length() <= 15);  // first name shoud not exceed 15 characters.
}

string ReadLastName()
{
	string LastName; // what's returned

	cout << "Enter Last Name: ";
	getline(cin, LastName);
	cout << endl;

	return LastName;
}

bool ValidateLastName(const string& LastName)  // passing by constant reference
{
	return (LastName.length() <= 15);  // last name should not exceed 15 characters.
}

stFullName ReadFullName()
{
	stFullName FullName;  // what's returned. // the next natural step of creating a variable of this structure user-defined data type.
	                      // WHENEVER you see such line, ALWAYS envision the variable having access to all member variables declared inside the structure.
	do
	{
		FullName.FirstName = ReadFirstName(); // "FullName.FirstName" to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateFirstName(FullName.FirstName )); // 👈 👈 the argument is written so that, it evaluates tp TRUE when the condition is INVALID. (hence the ! character).

	do
	{
		FullName.LastName = ReadLastName(); // "FullName.LastName" is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateLastName(FullName.LastName)); // 👈 👈 the argument is written so that it evaluates to TRUE when the condition is INVALID (hence the ! character).

	return FullName;

	// the above block of code is to be sequentially composed line by line
	// & at the end, implement the 4 functions of:
	// ReadFirstName(), ValidateFirstName(), ReadLastName(), ValidateLastName(), 
}

string ConcatenateFirstLastNames(stFullName FullName)  // pass by value  // WHENEVER you see such line, ALWAYS envision the variable having access to all member variables declared inside the structure.
{
	return (FullName.FirstName + " " + FullName.LastName); // no matter how simple or small this line is, ALWAYS wrap it in a function/ procedure    Divide & Conquer/ فرّق تسد
}



void PrintFullName(const stFullName &FullName) // pass by constant reference.  // ensure that the name of the param variable is NOT the same name as the function above it = throws exception / renders error.
{
	cout << "The full name is: " << ConcatenateFirstLastNames(FullName) << endl,
}


int main()
{

	// Instead of declaring "FirstName" & "LastName" as variables inside main()
	//, declare them as member variables inside a structure.

	PrintFullName(ReadFullName());  

	/* CRUCIAL NOTE:

	   If possible, STRIVE to have a printing procedure, that contains an if statement with an argument calling a boolean function
	   (it has to be a function returning a boolean data type anyway).
	   (Only if possible & when it's logical to do so).

	    or:

	   -a called function/procedure.

	   If it turns out, at the very end and after running the program, that the printing procedure references the value of a variable that it prints out
	   then,
	   in the nested functions line inside main(), replace the printing procedur with a:  cout <<    
	   statement since we're only printing one variable as opposed to, for example, s structure comprised of multiple variables.

    */
	return 0;
}










