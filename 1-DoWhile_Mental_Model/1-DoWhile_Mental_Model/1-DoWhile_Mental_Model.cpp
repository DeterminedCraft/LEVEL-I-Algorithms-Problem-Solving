// DoWhile_Mental_Model.cpp 

#include <iostream>
using namespace std;

/*

 In the previous pre-requisite (not final) mental model, the UNIVERSAL INPUT UTILITIES,
 have implementations where the Divide and Conquer strategiy isn't fully taken advantage of.

 It should and will be applied on:
  - The do statement's body.
  - The while's argument.

 */


 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* ////////////////////////////////////////////////////////////////  Reading Functions Mental Model :  ////////////////////////////////////////////////////////////////////////////////////*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
   Functions called are:

   ReadPositiveInt("string message"),
   ReadNegativeInt("string message"),
   ReadIntegerInRange("string message",  from,to),
   ReadIntWithRestriction("string message",  restricted),
   ReadIntEqualOrBiggerThanZero("string message"),
   ReadIntEqualOrSmallerThanZero("string message")


    Each called function MUST accept a string message (when applicable).

   This is the BEST approach,
   because the function inside the `do` block must remain a reusable, generic utility.

   Hardcoding the message inside that function:
   → makes it non-reusable
  

   Passing the message as a parameter:
   → keeps the function reusable and generic
   → allows the caller to define the message based on the specific problem or scenario
   
   */


   /*
                                            Calling the function INSIDE MAIN():
                                        ----------------------------------------------

  A-  Either in nested functions line: Example:      */
PrintPositiveInteger(ReadPositiveInt(" Some string message"));

/*
B-  OR independently :  Example:  */

// Initializing the below variable via reading user input (Using Function- Since ONE variable is initialized and returned).

int number = ReadPositiveInt(" Some string message");
/*  |
    |
    |-------> The last thing to type. Type after writing "return" keyword in the implementing function.      */



    /*--------------------------------------------------------------------------------
   Again- In either A or B, include the prompting string message in the calling function:  */


// remove ReadPositiveInt(" Enter a positive integer"); // range argument(s) not included as their values are intrinsic.


/* Implementing the function outside main() on top:  */

int ReadPositiveInt(const string& msg)  // passing by constant reference.
{
    int number;     // what's returned.

    do
    {
        number = ReadIntNumber(msg);     // 'number' is IMMEDIATELY validated against the range, in the while condition

    } while (!ValidatePositiveInt(number)); // 👈 👈the argument is written so that, it's TRUE when the condition is invalid
    // and if ranges are included then:
    // 
    // A- while (!ValidatePositiveInt(number), min, max);    
    // Or B- while (!ValidatePositiveInt(number), restricted);    etc. etc.
    return number;

    // Note: The above lines of code are to be written sequentially line by line,
    // and at the end, implement the functions of:     ReadPositiveInt()   &    ValidatePositiveInt() :

}



int ReadIntNumber(const string& msg) // passing by constant reference 
{
    int number;  // what's returned.

    cout << msg << endl;   // instead of hardcoding the message prompting the user to enter a value ( = deems out function un-reusable).
    cin >> number;
    cout << endl;

    return number;
}


bool ValidatePositiveInt(const int& number)  // pass by constant reference.
{
    return (number > 0);
}
   // and if ranges were included in the called function then:
   /*
   // For A:
   bool ValidatePositiveInt(const int& number, int min, int max)  // pass by constant reference.  // Ranges ALWAYS passed by value
   {
      return (min <= number && number <= max);   // [min, max].......but, if: (min,max)  then only remove all the equal signs.
   }

   // For B:
   bool ValidatePositiveInt(const int& number, int restricted)  // pass by constant reference.  // Ranges ALWAYS passed by value
   {
       return (number != restricted);   // [min, max].......but, if: (min,max)  then only remove all the equal signs.
   }
   */

   
       /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


       /*                                                              Calling the function inside main():
                                                                  ---------------------------------------------- */
// As mentioned above - The function called inside main,
// A- will either be in a nested functions line
// Or B- Independent.

// In EITHER case (whether A or B), here is the called function inside main & also later it's implementation:

   int min = 1;   // Include here. Never hardcode.
   int max = 10;  // Include here. Never hardcode.

   ReadIntInRange(" Enter an integer between " + to_string(min) + " & " + to_string(max), min, max);  // ranges are included as their values are NOT intrinsic. 
   // or the string argument could simply be any other string message with no reference to the min & max variables.


   //Implementing this function outside main() on top:

   int ReadIntInRange(const string& msg, int min, int max) // pass by constant reference. // also- ranges ALWAYS passed by value.
   {

       int number; // what's returned.

       do
       {
           number = ReadIntNumber(msg); // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

       } while (!ValidateIntRange(number, min, max));  //👈 👈 the argument is written so that, it's TRUE when the condition is INVALID.

       return number;

       // NOTE: The above lines of code are to be sequentially written step by step
       // and at the end, implement the functions of: 
       // ReadNumber()   &   ValidateIntRange()

   }

   int ReadIntNumber(const string& msg)  // pass by constant reference.
   {
       int number; // what's returned;

       cout << msg << endl; // instead of hardcoding the message prompting the user to enter a value ( = deems out function un-reusable)).
       cin >> number;

       return number;
   }


   bool ValidateIntRange(const int& number, int min, int max)   // pass by constant reference. // ranges are ALWAYS passed by value.
   {
       return  (min <= number && number <= max);   // [min, max].......but, if: (min,max)  then only remove all the equal signs.
   }


   // Avoid:    ReadPositiveIntInRange() or ReadnegativeIntInRange(), etc.
   // and only use: ReadIntInRange() 
   // so that any of the two ranges can be positive or negative.
   // otherwise, we'll be creating more utilities / less optimization.

 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   // As mentioned above - The function called inside main,
    // A- will either be in a nested functions line
    // Or B- Independent.

// In EITHER case (whether A or B), here is the called function inside main & also later it's implementation:

                                                 /* Calling the function inside main():
                                               ----------------------------------------------*/

   int RestrictedNumber = 42; // declare and initialize here (Never hardcode in the calling function)

   ReadIntWithRestriction(" Enter an Integer (Except for the value of " + to_string(RestrictedNumber) + " )", RestrictedNumber); // passing the range argument as its value is NOT intrinsic.
   // or the string argument could simply be any other string message with no reference to the min & max variables.


   // Implementing this function outside main(), on top:

   int ReadIntWithRestriction(const string& message, int restricted) // passing by constant reference // range values ALWAYS passed by value
   {
       int number;  // what's returned.

       do
       {
           number = ReadIntNumber(message); // passing by constant reference. // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

       } while (!ValidateIntWithRestriction(number, restricted))  // 👈👈 the argument is written so that, it's TRUE when the condition is INVALID.

           return number;


       // NOTE: The above lines of code are to be sequentially written line by line
       // and at the end, implement the functions of:   ReadNumber()     &     ValidateIntWithrestriction():
   }

       int ReadIntNumber(const string & message) // passing by constant reference.
       {
           int number;  // what's returned

           cout << message << endl;   // instead of hardcoding the message prompting the user to enter a value ( = deems out function un-reusable)).
           cin >> number;
           cout << endl;

           return number;
       }


       bool ValidateIntWithRestriction(const int& number, int restricted);  // passing by reference  // ranges ALWAYS passed by value.
       {
           return (number != restricted);
       }




       // to do:
       // AND THE ABOVE 3 UNIVERSAL INPUT UTILITIES COULD BE OF: float, double, unsigned short, long long, etc. data types.
       // add more notes if possible / list all possible utilities's names






             //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     /* ////////////////////////////////////////////////////////////////  Reading structures Mental Model :  ////////////////////////////////////////////////////////////////////////////////////*/
     //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  Pre-requitiste: 

  You always start writing your program by coding the enum part.
  If enums are not applicable, then check if you could start coding with structures (an enum is coded above the structure, if the two are to exist in a program).

  
  Reading structures Mental Model :  */        // the validation is restricted to range validation in this mental model as the correct broader validation approach will be discussed in the upcoming C++ Level II course.

       struct stPersonalInfo
       {
           string FirstName;
           string LastName;
           bool HasMiddleName;
           bool HasNickName;
           unsigned short age;
       };
       // so far, only a structure user-defined data type has been created. That's all !
       // the next natural step is declaring a variable of this structure user-defined data type
       // that's either a normal variable (ONE record) or an array variable (MORE than one record)
       //
       // But the main questions is - Where to create this variable ?
       // - If it's going to be initialized directly, then declare in inside main()
       // - if it's going to be initialized via reading user-input, then declate it inside a reading procedure of the structure data type, that returns this variable.
       // since it's the latter, then IMMEDIATELY start implementing this function below NOW:

       stPersonalInfo ReadPersonalInfo()
       {
           stPersonalInfo PersonalInfo; // what's returned.  // the next natural step of creating a variable of the structure user-defined data type.
           // WHENEVER you see such line, ALWAYS envision the variable 'PersonalInfo' having access to all member variables defined in the structure.
           do
           {
               PersonalInfo.FirstName = ReadName(); // 'PersonalInfo.FirstName' is to be IMMEDIATELY validated against the range, in the while condition.
               // & not ReadFirstName() as it's a function for reading both- first & last names as both are declared as strings inside the structure.

           } while (!ValidatePersonalInfo_NameRange(PersonalInfo.FirstName)); // 👈👈 The argument is written so that it evaluates to TRUE when the condition is INVALID.
              // & not  ValidatePersonalInfo_FirstNameRange() as this func. will be used to range validate both first and last names
           
           do
           {
               PersonalInfo.LastName = ReadName();  // 'PersonalInfo.LastName' is to be IMMEDIATELY validated against the range, in the while condition.

           } while (!ValidatePersonalInfo_NameRange(PersonalInfo.LastName)); // 👈👈 The argument is written so that it evaluates to TRUE when the condition is INVALID.

           //do
          // {
               PersonalInfo.HasMiddleName = ReadBoolValue(); // REMOVE: //'PersonalInfo.HasMiddleName' is to be IMMEDIATELY validated against the range, in the while condition.

           //} while (!ValidatePersonalInfo_BoolRange(PersonalInfo.HasMiddleName)); //  👈👈 the argument is written so that it evaluates to TRUE when the condition is INVALID.

           //do
           //{
               PersonalInfo.HasNickName = ReadBoolValue() //Remove: // ' PersonalInfo.HasNickName' is to be IMMEDIATELY validated against the range, in the while condition.

           //} while (!ValidatePersonalInfo_BoolRange(PersonalInfo.HasNickName)); //  👈👈 the argument is written so that it evaluates to TRUE when the condition is INVALID.

           do
           {
               PersonalInfo.age = ReadAge(); // 'PersonalInfo.age' is to be IMMEDIATELY validated against the range, in the while condition.

           } while (!ValidatePersonalInfo_AgeRange(PersonalInfo.age)); //  👈👈 the argument is written so that it evaluates to TRUE when the condition is INVALID.

           return PersonalInfo;

           //NOTE: The above block of code, is to be sequantially written line by line
           // & at the end, implement the functions of: ReadName(), ValidatePersonalInfo_NameRange(), ReadHasMiddleName(), ValidatePersonalInfo_BoolRange()
           // ReadHasNickName(), ReadAge(), ValidatePersonalInfo_AgeRange():                                            
       }
      
       // so here are the implementations (They should be above the reading function):
       string ReadName()
       {
           string name; // what's returned.

           cout << message; 
           getline(cin, name);    // requires the library: #include <string>
           cout << endl;

           return name;
       }


       bool ValidateStringLength(const string& name)  //pass by constant reference.
       {
           return (min <= name && name <= max);
       }


       bool ReadBoolValue()
       {
           int number; // what's returned

           do
           { 
           cout << message; // a message to the effect of:    Enter 1 for yes / 0 for no
           cin >> number;
           cout << endl; 

           } while (number == 0 || number == 1);

           return number; // before number is returned, it's implicitly converted from int to bool. Afterwards, it's returned.
       }

       unsigned short ReadAge()
       {
           unsigned short number; // what's returned

           cout << message;
           cin >> number;
           cout << endl;

           return number;
       }


       bool ValidatePersonalInfo_AgeRange(const unsigned short& age)  // pass by constant reference.
       {
           return (min <= age && age <= max);
       }

       int main()
       {
           // instead of creating variables for 'FirstName', 'LastName', 'HasMiddleName', 'HasNickName', 'age', 'HasDriverLicense', 'HasCertificate'
           // in main(), I'm going to declare them as member variables inside a structure, 
           // since they're related amongst each other.

           return 0;
       }








      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     /* ////////////////////////////////////////////////////////////////  Reading Procedures Mental Model :  ////////////////////////////////////////////////////////////////////////////////////*/
     //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

       /* Calling the procedure INSIDE MAIN() :
       ---------------------------------------------- */
       int x, y;
       // Initializing via reading user input using a procedure (since MORE than one variable will be initialized):

       ReadTwoPositiveInt("Enter a positive integer: ", x, y);   // & just as explained above: It could be TwoIntInRange(), TwoIntWithRestriction(), etc. will all possible combinations.
       // x & y are now initialized


      // Where the implementation is:

       void ReadTwoPositiveInt(const string & message, int& x, int& y)
       {

           do
           {
               x = ReadIntNumber(message); //x is to be IMMEDIATELY validated against the range, in the while condition.

           } while (!ValidatePositiveInt(x));  //👈 👈 the argument is written so that it's TRUE when the condition is INVALID.
           

           do
           {
               y = ReadIntNumber(message); // 'y' is to be IMMEDIATELY validated against the range, in the while condition

           } while (!ValidatePositiveInt(y)); //👈 👈 the argument is written so that it's TRUE when the condition is INVALID.

       }

       // NOTE: the above lines of code are to be sequentially written line by line
       // and at the end, implement the functions of ReadNumber()  &  ValidatePositiveInt():
       
       //CRUCIAL: One reading function only is the OPTIMIZATION approach here BECAUSE x and y are of the EXACT SAME DATA TYPE.
       //         Also, in this specific example- both user inputs HAVE THE EXACT range validation: Both have to be positive.
       //         if, for example, but not exclusively: one input has to be positive and the other negative, then two different validation functions are used.

       int ReadIntNumber(const string & message)  // pass by constant reference.
       {
           int number; // what's returned.

           cout << message;  // instead of hardcoding the message prompting the user to enter a value ( = deems out function un-reusable)).
           cin >> number;
           cout << endl;

           return number;
       }



       bool ValidatePositiveInt(const int& number) // pass by constant reference.
       {
           return (number > 0);
       }
     
  






       //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /* ////////////////////////////////////////////////////////////////  Reading Strings Mental Model :  ////////////////////////////////////////////////////////////////////////////////////*/
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       
                           /* This mental model is based on range validation; that's the length of the string value entered by the user */

       // at this level - the only type of user-input validation that we've been exposed to, is the range validation,
       // and NOT data type validation. For example:
       // the user is supposed to enter a numerical value that we range-validate. But what happens if they enter a string instead ?
       // and vice-versa ( where the user is supposed to enter a string that's composed of alphabetical characters (for example their last name)
       // but instead, they enter a string composed of numerical values.


       // this mental model is based on a specific scenario related to reading name. The goal is udnerstanding the structure and the lines of code:
       // 
       // 
       // Calling in main():
       unsigned short MinChar = 1;
       unsigned short MaxChar = 20;

       ReadNameInRange("Enter your name: ", MinChar, MaxChar);

       //Implementing:

       string ReadNameInRange(const string& message, unsigned short MinChar, unsigned short MaxChar)
       {
           string value;  // what's returned.
           do
           {
               value = ReadStringValue(message); // 'value' is to be IMMEDIATELY validated against the range, in the while condition.

           } while (!ValidateNameInRange(value, MinChar, MaxChar));

           // (for example- both first and last names' inputs must be more than one character, or both less than 15 characters, 
           // or first name must be less than 10 charc. & last name less than 15, etc


           return value;

           // NOTE: the above lines of code are to be sequentially written line by line
          // and at the end, implement the functions of ReadStringValue  &  ValidateStringLength():

       }



       string ReadStringValue(const string& message)
       {
           string value;   // what's returned.

           cout << message;
           getline(cin, value);
           cout << endl;

           return value;
       }


       bool ValidateNameInRange(const string& value, unsigned short MinChar, unsigned short MaxChar)
       {
           return (MinChar < value.length() && value.length() <= MaxChar);  // (MinChar, maxChar]
           // mixing data types (unsigned short and int returned by length()) is problematic. In Course II C++, it will be resolved.
       }