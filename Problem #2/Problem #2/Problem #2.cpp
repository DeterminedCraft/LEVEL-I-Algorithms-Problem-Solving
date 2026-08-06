

#include <iostream>
#include <string>
using namespace std;


/*
 Problem #2

 Write a program to ask the user to enter his/her name and
 print it on screen.

*/


bool ValidateName(const string& name)  // passing by constant reference
{
	return (name.length() > 1);
}

string ReadSomeName(const string& message) // passing by constant reference.
{
	string SomeName; // what's returned

	cout << message;
	getline(cin, SomeName); // for string inputs ALWAYS + ONLY use this line, so that a string with space(s) is take as one whole value. #include<string>  library is needed for this.
	cout << endl;             // ONLY use:  cin >> x for integers.

	return SomeName;
	 // The variable 'SomeName' was initialized and then returned.
	 // The calling function, ReadSomeName(),  evaluates to produce a value of type string (which initializes an object in the calling function),
     // the lifetime of the local variable 'SomeName' inside this function ends when the program exists the curly brackets of this function.
	 // 🔥🔥🔥 correct !
}


string ReadName(const string& message)    // passing by constant reference.
{
	string name; // what's returned
	do
	{
		name = ReadSomeName(message); // 'name' is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateName(name));  // 👈👈 the argument is written so that it's TRUE, when the condition is INVALID.

	return name;

	// the above lines of code are to be written line by line
	// and at the end, implement the functions of:  ReadSomeName() & ValidateName()

	 // The variable 'name' was initialized and then returned.
	 // The calling function, ReadName(), in main(), evaluates to produce a value of type string (which initializes an object in the calling function),
     // the lifetime of the local variable 'name' inside this function ends when the program exists the curly brackets of this function.
	 // 🔥🔥🔥 correct !
}



void PrintName(const string& name)   // passing by constant reference.
{
	cout << "\n Your name is: " << name << "\n";
}

int main()
{

	PrintName(ReadName("Enter your name: ")); // ReadName() HAS to be a function; as procedure returns void which can never be an argument = renders an exception.

	return 0;
}








///////////////////////////////////////////////////////// FIRST ATTEMPT SOLUTION IS BELOW: ///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////// FIRST ATTEMPT SOLUTION IS BELOW: ///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////// FIRST ATTEMPT SOLUTION IS BELOW: ///////////////////////////////////////////////////////////////////////////

// Note: This is NOT the final solution. 
// As, soon, we're going to include input validation.
// the point is to focus on logic now and then input validation will be added.


string ReadName()
{
	string name; // What is returned.
    
	cout << "Enter your name: ";
	getline(cin, name); // for string inputs ALWAYS + ONLY use this line, so that a string with space(s) is take as one whole value. #include<string>  library is needed for this.
	                    // ONLY use:  cin >> x for integers.
	return name;
	 // The variable 'name' was initialized and then returned.
	 // The calling function, ReadName(), in main(), evaluates to produce a value of type string (which initializes an object in the calling function),
     // the lifetime of the local variable 'name' inside this function ends when the program exists the curly brackets of this function.
	 // 🔥🔥🔥 correct !
}                      
// The note below, from now on, will NOT be included in the next examples ⇒
// (it will always apply, but will not be pointed out again): ⇒
// 
// When implementing a function/ procedure (done outside of main()), do so IN ACCORDANCE WITH the called function/ procedure in main().

void PrintName(const string &name)     // passing by constant ref. the parameter 'name' could be any other name.  
{                                     // when constructing the parameter argument, do so IN ACCORDANCE WITH the called function.
	cout << "Your name is: " << name << endl;
}   
int main()
{

	PrintName(ReadName());   // ReadName() has to be a function, as a procedure returns null. Null can not be an argument of any function or procedure.

	return 0;
}










