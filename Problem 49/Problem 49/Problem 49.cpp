
#include <iostream>
#include <string>
using namespace std;

/*

 Problem #48:

 Write a program to read the ATM PIN code from the user, then check if PIN Code = 1234, then show the
 balance to user, otherwise print "Wrong PIN" and ask the user to enter the PIN again.

 Assume User Balance is 7500.

 Input:

 1234
 5151

 Outputs:

 Your Balance is: 7500
 Wrong PIN

*/




string ReadStringValue(const string& message)    // pass by constant reference.
{
	string value;   // what's returned.

	cout << message;
	getline(cin, value);
	cout << "\n";

	return value;
}

bool ValidateEnteredPinCode(const string& EnteredPinCode, string PinCode)   // passed by const. ref. becasue 'EnteredPinCode' is ONLY used for comparison against the range.   // Range is ALWAYS passed by value.
{
	return (EnteredPinCode == PinCode);
}

 
 
bool login(const string& message, string PinCode)  // pass by constant reference.   // Ranges ALWAYS passed by value.
{
	int counter = 0;   // only & only for including the error message prompting the user to re-enter the value.
	string EnteredPinCode;    // NOT what's returned. What's returned should be a boolean.

	do
	{
		counter++;
		if (counter > 1)
		{
			cout << "Error. Wrong PIN. ";
			system("color 4F");    // added just for fun.
		}

		EnteredPinCode = ReadStringValue(message);   // 'EnteredPinCode' is IMMEIDATELY validated against the range, in the while condition

	} while (!ValidateEnteredPinCode(EnteredPinCode, PinCode));   // the argument is written so that, it evalautes to TRUE when the condition is INVALID.

	return true;  // or  return 1
	// either the correct password is entered, so that this function returns true
	// or the program gets stuck at the do while loop as the user keeps on entering the wrong password.

	/*Note: The above lines of code are to be sequentially  composed line by line & at the end, implement the functions of 
	        ReadStringValue()   &    ValidateEnteredPinCode()  */

}


int main()
{
	double balance = 7500; 

	string PinCode = "1234";

	if (login("Enter your PIN: ", PinCode))  // Range is included as it's value in intrinsic.       // EITHER function returns true OR the program stuck @ the do..while loop for keeping on entering the wrong pincode.                                                 
	{                                                                                               // if true, then move to the next lines of code to show the balance.
		system("color 2F"); 
		cout << "The balance is " << balance << endl;
	}


	return 0;
}








 //////Below: A different way of including the re-prompting error message
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


string ReadStringValue(const string& message)    // pass by constant reference.
{
	string value;   // what's returned.

	cout << message;
	cin >> value;
	cout << "\n";

	return value;
}

bool ValidateEnteredPinCode(const string& EnteredPinCode, string PinCode)   // passed by const. ref. becasue 'EnteredPinCode' is ONLY used for comparison against the range.   // Range is ALWAYS passed by value.
{
	return (EnteredPinCode == PinCode);
}


 
bool login(const string& message, string PinCode)  // pass by constant reference.   // Ranges ALWAYS passed by value.
{
	
	string EnteredPinCode;    // NOT what's returned. What's returned should be a boolean.

	bool validate; 
	do
	{
		EnteredPinCode = ReadStringValue(message);   // 'EnteredPinCode' is IMMEIDATELY validated against the range, in the while condition

		validate = ValidateEnteredPinCode(EnteredPinCode, PinCode);

		if (!validate)   // only & only for including the error message prompting the user to re-enter the value.
		{
			cout << "Error. Wrong PIN Code. ";
			system("color 4F");    // added just for fun.
		}

	} while (!validate);   // the argument is written so that, it evalautes to TRUE when the condition is INVALID.

	return true;  // or  return 1
	// either the correct password is entered, so that this function returns true
	// or the program gets stuck at the do while loop as the user keeps on entering the wrong password.

	/*Note: The above lines of code are to be sequentially  composed line by line & at the end, implement the functions of
			ReadStringValue()   &    ValidateEnteredPinCode()  */

}


int main()
{
	double balance = 7500;

	string PinCode = "1234";

	if (login("Enter your PIN: ", PinCode))  // Range is included as it's value in intrinsic.       // EITHER function returns true when the user enters the correct pincode OR the program stuck @ the do..while loop for keeping on entering the wrong pincode.                                                 
	{                                                                                               // if true, then move to the next lines of code to show the balance.
		system("color 2F");
		cout << "The balance is " << balance << endl;
	}


	return 0;
}










 //////Below: Another different way of including the re-prompting error message
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


string ReadStringValue(const string& message)    // pass by constant reference.
{
	string value;   // what's returned.

	cout << message;
	cin >> value;
	cout << "\n";

	return value;
}

bool ValidateEnteredPinCode(const string& EnteredPinCode, string PinCode)   // passed by const. ref. becasue 'EnteredPinCode' is ONLY used for comparison against the range.   // Range is ALWAYS passed by value.
{
	return (EnteredPinCode == PinCode);
}



bool login(const string& message, string PinCode)  // pass by constant reference.   // Ranges ALWAYS passed by value.
{
	string EnteredPinCode;    // NOT what's returned. What's returned should be a boolean.

		   EnteredPinCode = ReadStringValue(message);   // 'EnteredPinCode' is IMMEIDATELY validated against the range, in the while condition

		   while (!ValidateEnteredPinCode(EnteredPinCode, PinCode))   // the argument is written so that, it evalautes to TRUE when the condition is INVALID.
		   {
			   system("color 4F");    // added just for fun.

			   cout << "Error. Wrong Pin. ";
			   EnteredPinCode = ReadStringValue(message);
	       }

	return true;  // or  return 1
	 ////either the correct password is entered, so that this function returns true
	 ////or the program gets stuck at the do while loop as the user keeps on entering the wrong password.

	/*Note: The above lines of code are to be sequentially  composed line by line & at the end, implement the functions of 
	        ReadStringValue()   &    ValidateEnteredPinCode()  */

}


int main()
{
	double balance = 7500; 

	string PinCode = "1234";

	if (login("Enter your PIN: ", PinCode))  // Range is included as it's value in intrinsic.       // EITHER function returns true OR the program stuck @ the do..while loop for keeping on entering the wrong pincode.                                                 
	{                                                                                               // if true, then move to the next lines of code to show the balance.
		system("color 2F"); 
		cout << "The balance is " << balance << endl;
	}


	return 0;
}





////// SOME OLD SOLUTION but  ALL VALID & 100 percent correct solutions:
//int ReadIntegerNumber(const string& message)   // pass by constant reference.
//{
//    int number;  // what's returned.
//
//    cout << message;
//    cin >> number;
//    cout << "\n";
//
//    return number;
//}
//
//bool ValidateEnteredPinCode(const int& EnteredPinCode, int PinCode)   // passed by const. ref. since 'EnteredPinCode' is ONLY used for camparison against the range   // Ranges ALWAYS passed by value
//{
//    return (EnteredPinCode == PinCode);
//}
//
//
//int ReadPinCode(const string& message, int PinCode)   // pass by constant reference.   // Ranges ALWAYS passed by value
//{
//    int counter = 0;
//    int EnteredPinCode; // waht's returned
//
//    do
//    {
//        counter++;
//        if (counter > 1)
//        {
//            cout << "Wrong Pin. ";
//        }
//
//        EnteredPinCode = ReadIntegerNumber(message);  // 'PinCode' is validated against the range, in the while condition.
//
//    } while (!ValidateEnteredPinCode(EnteredPinCode, PinCode));   // the argument is written so that, it evaluates to TRUE when the condition is INVALID.
//
//
//    return EnteredPinCode;
//    /* The above block of code is to be sequentially composed line by line & at the end, implement the functions of: ReadIntegrNumber()   &   ValidateEnteredPinCode()   */
//}
//
///*   // turned out that no need for a printing procedue unless it contains at least one function.
//void PrintBalance(const int& EnteredPinCode)   // pass by constant ref.    // the program ONLY reaches here after the user enters the correct Pin Code.
//{
//    cout << "Your balance is: 7500" << endl;
//}
//*/
//
//
//int main()
//{
//    double balance = 7500;  // written at the very very end, when it turned out that it was needed.
//
//    int PinCode = 1234;  // SHOULD BE DECLARED AS STRING // int instead of, for example, short. Reason is, what if I want to change the PinCode value to my phone number ? (In this case, the range for short is much smaller)
//
//    ReadPinCode("Enter your PIN Code: ", PinCode); // The Range (PinCode) is included as its value IS INTRINSIC.
//
//    cout << "Your balance is: " << balance << endl;     // the program reaches this line ONLY after the user enters the CORRECT PIN CODE.
//
//    return 0;
//}
//
//
//
////////OR:
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//int ReadIntegerNumber(const string& message)   // pass by constant reference.
//{
//    int number;  // waht's returned.
//
//    cout << message;
//    cin >> number;
//    cout << "\n";
//
//    return number;
//}
//
//bool ValidateEnteredPinCode(const int& EnteredPinCode, int PinCode)   // passed by const. ref. since 'EnteredPinCode' is ONLY used for camparison against the range   // Ranges ALWAYS passed by value
//{
//    return (EnteredPinCode == PinCode);
//}
//
//
//int ReadPinCode(const string& message, int PinCode)   // pass by constant reference.   // Ranges ALWAYS passed by value
//{
//    bool validation;
//    int EnteredPinCode; // waht's returned
//
//    do
//    {
//        EnteredPinCode = ReadIntegerNumber(message);  // 'PinCode' is validated against the range, in the while condition.
//
//        validation = ValidateEnteredPinCode(EnteredPinCode, PinCode);
//        if (!validation)
//        {
//            cout << "Wrong Pin. ";
//        }
//
//    } while (!validation);   // the argument is written so that, it evaluates to TRUE when the condition is INVALID.
//
//
//    return EnteredPinCode;
//    /* The above block of code is to be sequentially composed line by line & at the end, implement the functions of: ReadIntegrNumber()   &   ValidateEnteredPinCode()   */
//}
//
///*   // turned out that no need for a printing procedue unless it contains at least one function.
//void PrintBalance(const int& EnteredPinCode)   // pass by constant ref.    // the program ONLY reaches here after the user enters the correct Pin Code.
//{
//    cout << "Your balance is: 7500" << endl;
//}
//*/
//
//
//int main()
//{
//    double balance = 7500;  // written at the very very end, when it turned out that it was needed.
//
//    int PinCode = 1234;   // SHOULD BE DECLARED AS STRING  // int instead of, for example, short. Reason is, what if I want to change the PinCode value to my phone number ? (In this case, the range for short is much smaller)
//
//    ReadPinCode("Enter your PIN Code: ", PinCode); // The Range (PinCode) is included as its value IS INTRINSIC.
//
//    cout << "Your balance is: " << balance << endl;     // the program reaches this line ONLY after the user enters the CORRECT PIN CODE.
//
//    return 0;
//}
//
//
//
//
////////// OR:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//int ReadIntegerNumber(const string& message)   // pass by constant reference.
//{
//    int number;  // waht's returned.
//
//    cout << message;
//    cin >> number;
//    cout << "\n";
//
//    return number;
//}
//
//bool ValidateEnteredPinCode(const int& EnteredPinCode, int PinCode)   // passed by const. ref. since 'EnteredPinCode' is ONLY used for camparison against the range   // Ranges ALWAYS passed by value
//{
//    return (EnteredPinCode == PinCode);
//}
//
//
//int ReadPinCode(const string& message, int PinCode)   // pass by constant reference.   // Ranges ALWAYS passed by value
//{
//
//    int EnteredPinCode; // what's returned
//
//    EnteredPinCode = ReadIntegerNumber(message);
//
//    while (!ValidateEnteredPinCode(EnteredPinCode, PinCode)) // the argument is written so that, it evaluates to TRUE when the condition is INVALID.
//    {
//        cout << "Wrong Pin. ";
//        EnteredPinCode = ReadIntegerNumber(message);
//    }
//
//    return EnteredPinCode;
//
//    /* The above block of code is to be sequentially composed line by line & at the end, implement the functions of: ReadIntegrNumber()   &   ValidateEnteredPinCode()   */
//}
//
///*   // turned out that no need for a printing procedue unless it contains at least one function.
//void PrintBalance(const int& EnteredPinCode)   // pass by constant ref.    // the program ONLY reaches here after the user enters the correct Pin Code.
//{
//    cout << "Your balance is: 7500" << endl;
//}
//*/
//
//
//int main()
//{
//    double balance = 7500;  // written at the very very end, when it turned out that it was needed.
//
//    int PinCode = 1234;  // SHOULD BE DECLARED AS STRING // int instead of, for example, short. Reason is, what if I want to change the PinCode value to my phone number ? (In this case, the range for short is much smaller)
//
//    ReadPinCode("Enter your PIN Code: ", PinCode); // The Range (PinCode) is included as its value IS INTRINSIC.
//
//    cout << "Your balance is: " << balance << endl;     // the program reaches this line ONLY after the user enters the CORRECT PIN CODE.
//
//    return 0;
//}