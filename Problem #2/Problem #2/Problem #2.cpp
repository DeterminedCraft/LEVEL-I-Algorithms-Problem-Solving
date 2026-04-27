

#include <iostream>
#include <string>;
using namespace std;


/*
 Problem #2

 Write a program to ask the user to enter his/her name and
 print it on screen.

*/



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










