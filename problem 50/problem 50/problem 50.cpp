
#include <iostream>
#include <string>
using namespace std;

/*

  Problem #50:

  Write a program to read the ATM PIN code from the user, then check if PIN Code = 1234, then show the
  balance to user, otherwise print "Wrong PIN" and ask the user to enter the PIN again.

 ** ONLY allow the user to enter the wrong PIN 3 times & print "Card is locked !"

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
    string value;   /// what's returned.

    cout << message;
    getline(cin, value);      // #include <string>
    cout << "\n";

    return value;
}


bool ValidateEnteredPinCode(const string& EnteredPinCode, string PinCode)    // pass by constant ref. since 'EnteredPinCode' is ONLY used for comparison against the range that's PinCode    // Ranges ALWAYS passed by value.
{
    return (EnteredPinCode == PinCode);
} 




bool login(const string& message, const string& password)
{
    int counter = 3;
    string EnteredPinCode;

    do
    {
       
        EnteredPinCode = ReadStringValue(message);

        if (ValidateEnteredPinCode(EnteredPinCode, password))  // pay attention, no ! is added to the argument.
        {
            return true;  // this exists the login function and returns true.
        }

        counter--;    // decrement on the failed password attempt.
        if (counter > 0)     // without wrapping the cout with this if statement, then on the last failed message we'll have "Wrong Password. You have 0 tries left."
        {
            cout << "Wrong Password. You have " << counter << " tries left.\n";
            system("color E0"); // Just for fun.
        }

    } while (counter > 0);

    return false;    // if the program reaches here, then login failed.
}


int main()
{
    double balance = 7500; 

    string PinCode = "1234";

    // This function returns true when the user enters the correct pin code. 
    // Otherwise - The function gets stuck at the do..while loop as the user keeps on entering the wrong pin code.
    // or that it could return false so that the user gets locked out as the number of failed attemps exceeds , for example, 3 attempts.

    if (login("Enter your PIN code: ", PinCode))  // The Range (PinCode) is included as its value is INTRINSIC. 
    {
        cout << "The balance is: " << balance << endl;
        system("color 2F");   // just for fun.
    }
    else
    {
        system("color 4F");   // just for fun.
        cout << "Account LOCKED OUT for entering the wrong pin code 3 times \n";
    }


    return 0;
}






//// Old UNOPTIMIZED solution
/*
bool login(const string& message, string PinCode)
{
    int counter = 3;
    string EnteredPincode;

    do
    {
        counter--;

        EnteredPincode = ReadStringValue(message);
        if (EnteredPincode == PinCode)
        {
            return true;    // or return 1
        }

        else
        {
            cout << "Wrong Password. You have " << counter << " tries left. \n";
        }


    } while (!ValidateEnteredPinCode(EnteredPincode, PinCode) && counter >= 1);

    return false;
}
*/