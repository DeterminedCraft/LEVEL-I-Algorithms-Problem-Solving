
#include <iostream>
using namespace std;


/*
 Problem #12:

 Write a program to ask the user to enter:
 • Number1, Number2

 Then print the Max Number.

 Example Inputs:
 10
 20

 Output:
 The maximum number is 20
*/



/* A- The correct solution is via using vectors.
   B- Declaring two variables and initializing them via reading user input.



*/


//// B:
////
float ReadFloatNumber(string message)   // pass by constatn reference.
{
	float number; // what's returned.

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}

bool ValidateNumber(const float& number, float min, float max) // pass by constant reference.  // ranges ALWAYS passed by value.
{
	return (min <= number && number <= max);
}

void ReadNumber(const string& message, float min, float max, float& number) //pass by const. ref. // ranges ALWAYS passed by value. // Number1 & Number2 passed by ref. Otherwise, how could the declared Number1 & Number2, inside main, be initialized ?
{
	do
	{
		number = ReadFloatNumber(message);  // 'number' is to be IMMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateNumber(number, min, max));   // the argument is written so that, it evaluates to TRUE when the condition is invalid

	/* Note: 
	   The above block of code is to be sequentially composed line by line. 
	   And at the end, implement the functions of: ReadFloatNumber()  & ValidateNumber()
	
	*/

}


void ReadTwoNumbers(const string& message, float min, float max, float& Number1, float& Number2) //pass by const. ref. // ranges ALWAYS passed by value. // Number1 & Number2 passed by ref. Otherwise, how could the declared Number1 & Number2, inside main, be initialized ?
{
	ReadNumber(message, min, max, Number1);
	ReadNumber(message, min, max, Number2);
}

bool IsFirstGreater(const float& Number1, const float& Number2)   // pas by constant reference.
{
	return (Number1 > Number2);
}

float DetermineMaxNumber(const float& Number1, const float& Number2)    // pass by constant reference.
{
	if (IsFirstGreater(Number1, Number2))
	{
		return Number1;
	}
	else
	{
		return Number2;
	}
}

void PrintMaxNumber(const float& Number1, const float& Number2)   // pass by constant reference.
{
	cout << "The maximum number is: " << DetermineMaxNumber(Number1, Number2) << endl;
}

int main()
{
	float min = -1000000; // instead of hardcoding them in the called function.  // declaring them as floats, as they'll be compared to the float value entered (never mix data types even when comparing)
	float max = 1000000;

	float Number1, Number2;
	// Initializing the above variables via reading user input (Using a procedure - since more than one variable will be initialized):

	ReadTwoNumbers("Enter number: ", min, max, Number1, Number2);
	// Number1  &  Number2 are now initialized.

	PrintMaxNumber(Number1, Number2);  // this line is written so that, the printing procedure's implementation contain the DeteminemaxNumber()
	                                   // this is the standard. And separately (as a side effect), the printing procedure will have access to
	                                  // the original Number1 & Number2 entered by the user.
	                           

	return 0;
}




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////B - But using two functions this time:



float ReadFloatNumber(const string& message)     // pass by constant reference
{
	float number; // what's returned

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}

bool ValidateNumber(const float& number, float min, float max)  // pass by constant reference.  // ranges ALWAYS passed by value
{
	return (min <= number && number <= max);
}

float ReadNumber(const string& message, float min, float max) // pass by constant reference.  // ranges ALWAYS passed by value.
{
	float number;  // what's returned. // declared outside the do statement so that it can be returned.
	do
	{
		number = ReadFloatNumber(message);  // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateNumber(number, min, max)); // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

	return number;
    
	/* Note:
	   The above block of code is sequentially composed line by line
	   and at the end, implement the functions of:
	   ReadFloatNumber()  & ValidateNumber()

	*/
}

bool IsFirstNumberLarger(const float& Number1, const float& Number2) // pass by constant reference.
{
	return (Number1 > Number2);
}

float DetermineMaxNumber(float Number1, float Number2)   // pass by value
{ 
	if (IsFirstNumberLarger(Number1, Number2))       // (Number1 > Number2) Always wrap it inside a separate function even if it's a one liner and no matter how small such line is.
	{
		return Number1;
	}
	else
	{
		return Number2;
	}
}


void PrintMaxNumber(const float& Number1, const float& Number2)     // pass by constant reference
{
	cout << "The maximum number is: " << DetermineMaxNumber(Number1, Number2) << endl;
}

int main()
{
	float min = -1000000;
	float max = 1000000;

  //Initiating the below variable via reading user input (Using Function - since ONE variable will be initialized and returned):
	float Number1 = ReadNumber("Enter a number: ", min, max);
/*        |
          |----> to be typed at the end, after typing the 'return' keyword of the implementing function.
*/
	float Number2 = ReadNumber("Enter a number: ", min, max);
/*        |
		  |----> to be typed at the end, after typing the 'return' keyword of the implementing function.
*/

	PrintMaxNumber(Number1, Number2); // this line is written so that, the printing procedure's implementation contains DetermineMaxNumber();
	                                 // this is the standard approach. Also, as a 'side effect', this printing procedure will have access to
	                                 // original Number1 & Number2 values entered by the user.

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//A- Using vectors:
// But since this concept has not been introduced yet
// , it will be solved using an array (fixed-length data structure):

const unsigned short NumberOfElementsInArray = 2;


float ReadFloatNumber(const string& message)   // pass by constant reference
{
	float number;  // what's returned

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}

bool ValidateNumber(const float& number, float min, float max)   // pass by constant reference.
{
	return (min <= number && number <= max);
}


void ReadNumbers(const string& message, float min, float max, float numbers[NumberOfElementsInArray]) //array AUTOMATICALLY passed by ref.
{
	for (int i = 0; i < NumberOfElementsInArray; i++)
	{
		do
		{
			numbers[i] = ReadFloatNumber(message);  // ' numbers[i]' is to be IMMEDIATELY validated against the range, in the while condition.

		} while (!ValidateNumber(numbers[i], min, max));  //  // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

		/* Note:	   The above block of code is to be sequentially composed line by line.	  
		               And at the end, implement the functions of: 
					   ReadFloatNumber()  & ValidateNumber()	*/
	}
}

bool IsFirstNumLarger(float numbers[NumberOfElementsInArray])   // automatically passed by reference.
{
	return (numbers[0] > numbers[1]);
}

float DetermineMaxNumber(float numbers[NumberOfElementsInArray])   // pass by value.     //array ALWAYS passed be reference. Including the & sign will render an exception.
{
	if (IsFirstNumLarger(numbers))    // numbers[0] > numbers[1]   Farrik Tasud / Divide & conquer -  no matter how small this line is, ALWAYS wrap it in its own function.
	{
		return numbers[0];
	}
	else
	{
		return numbers[1];
	}
}

void PrintMaxNumber( float numbers[NumberOfElementsInArray]) // pass by ref.   //array ALWAYS passed be reference. Including the & sign will render an exception.
{
	cout << "The max number is: " << DetermineMaxNumber(numbers) << endl;
}

int main()
{
	float min = -1000000;
	float max = 1000000;

	float numbers[NumberOfElementsInArray];
	// initializing the above array variable via reading user input (Using Procedure- since an array contains more than one element):

	ReadNumbers("Enter a number: ", min, max, numbers); // the array variable 'numbers' is passed as the argument. it will be automatically sent along with its address memory to the implementing function. This is why it's
		                 // always passed by reference in the implementing procedure without including the & sign.
	                     // crucial: if the argument is numbers[2].. WRONG (the argument in this case is the third element in the array which does not exist = out of bound).

	// the array variable 'numbers' is now fully initialized.

	PrintMaxNumber(numbers);   // the array variable 'number' is sent along its address in memory to the implementing function. Therefore, it's AWYAYS passed by ref. in the implemetation without '&'
	                           // this line is written so that, the printing procedure^s implementation has the function DetermineMaxNumber(). this is the standard
	                          // and as a 'side effect', the printing procedure will have access / can reference the array variable whose elements were entered by the user.


	return 0;
}









/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  BELOW ARE SOME OLD SOLUTION









// solving this problem by declaring two variables and initializing them via reading user input by:
	//     A- Using a procedure (this solution)
    // or  B- using two functions



//float ReadFloatNumber(const string& message)   // pass by constant reference
//{
//	float number; // what's returned.
//
//	cout << message;
//	cin >> number;
//	cout << endl;
//
//	return number;
//}
//
//bool ValidateNumber(const float& number, int min, int max) //passing by constant reference.  // ranges ALWAYS passed by value.
//{
//	return (min <= number && number <= max);
//}
//
//void ReadTwoNumbers(const string& message, int min, int max, float& Number1, float& Number2)
//{
//	do
//	{
//		Number1 = ReadFloatNumber(message); // 'Number1' is to be IMMEDIATELY validated against the range, in the while condition.
//
//	} while (!ValidateNumber(Number1, min, max));
//
//	do
//	{
//		Number2 = ReadFloatNumber(message); // 'Number2' is to be IMMEDIATELY validated against the range, in the while condition.
//
//	} while (!ValidateNumber(Number2, min, max)); // the argument is written so that, it evaluates to TRUE when the condition is INVALID (hence, the ! sign).
//
//	/* Note: The above block of code is to be sequentially composed line by line
//	         and at the end implement the functions of: ReafFloatNumber() & ValidateNumber()
//	
//	
//	*/
//}
//
//bool IsFirstBigger(const float& Number1, const float& Number2)  // passing by constant reference.  // passing by constant reference since we are just comparing (no need to copy the values of Number1 & Number2 
//                                                               // to store these copied values into a new memory space whose scope is this function) //  Divide and conquer فَرِّق تَسُد
//{
//	return (Number1 > Number2);
//}
//
//float DetermineMaxNumber(const float& Number1, const float& Number2) // passing by cosntant reference
//                                                                    // passing by constant reference since we are just comparing (no need to copy the values of Number1 & Number2 
//	                                                                // to store these copied values into a new memory space whose scope is this function) 
//{
//	if (IsFirstBigger(Number1, Number2))  // Divide and conqeur  (Number1 > Number2) should be wrapped in it's own function.
//	{
//		return Number1;
//	}
//	else
//	{
//		return Number2; 
//	}
//}
//
//
//void PrintMaxNumber(const float& Number1, const float& Number2) // passing by constant reference.
//{
//	cout << "The maximum number is " << DetermineMaxNumber(Number1, Number2) << endl;   // DetermineMaxNumber() has to return  the max number of type float. Therefore the function is of type float in the implementation.
//}
//
//int main()
//{
//	int min = -1000000;
//	int max = 1000000;
//
//	float Number1, Number2;
//	// initializing the above variables via reading user input (using a procedure since MORE than one value is initialized):
//
//	ReadTwoNumbers("Enter number: ", min, max, Number1, Number2); 
//	// Number1 & Number 2 are now initialized.
//
//	PrintMaxNumber(Number1, Number2); // This nested functions line is written so that, the implementation of the printing procedure contains the function DetermineMaxNumber(.
//	                                  // this is how the design SHOULD BE ( & as a 'side effect'/ result, the printing procedure will have access to the original values
//	                                  // the user entered that are Number1 & Number2.
//
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// The above A code is unoptimized:
// here is the optimized version:

//float ReadFloatNumber(const string& message)   // pass by constant reference
//{
//	float number; // what's returned.
//
//	cout << message;
//	cin >> number;
//	cout << endl;
//
//	return number;
//}
//
//bool ValidateNumber(const float& number, int min, int max) //passing by constant reference.  // ranges ALWAYS passed by value.
//{
//	return (min <= number && number <= max);
//}
//
//
//
//
//
//
//
//
//
//
//
//void ReadNumber(const string& message, int min, int max, float& number)
//{
//	do
//	{
//		number = ReadFloatNumber(message); // 'Number' is to be IMMEDIATELY validated against the range, in the while condition.
//
//	} while (!ValidateNumber(number, min, max));  // the argument is written so that, it evaluates to TRUE when the condition is INVALID (hence, the ! sign).
//
//	
//	/* Note: The above block of code is to be sequentially composed line by line
//			 and at the end implement the functions of: ReafFloatNumber() & ValidateNumber()
//	*/
//}
//
//
//
//
//
//
//
//void ReadTwoNumbers(const string& message, int min, int max, float& Number1, float& Number2)
//{
//	ReadNumber(message, min, max, Number1);
//	ReadNumber(message, min, max, Number2);
//
//	
//}
//
//bool IsFirstBigger(const float& Number1, const float& Number2)  // passing by constant reference.  // passing by constant reference since we are just comparing (no need to copy the values of Number1 & Number2 
//// to store these copied values into a new memory space whose scope is this function) //  Divide and conquer فَرِّق تَسُد
//{
//	return (Number1 > Number2);
//}
//
//float DetermineMaxNumber(const float& Number1, const float& Number2) // passing by cosntant reference
//// passing by constant reference since we are just comparing (no need to copy the values of Number1 & Number2 
//// to store these copied values into a new memory space whose scope is this function) 
//{
//	if (IsFirstBigger(Number1, Number2))  // Divide and conqeur  (Number1 > Number2) should be wrapped in it's own function.
//	{
//		return Number1;
//	}
//	else
//	{
//		return Number2;
//	}
//}
//
//
//void PrintMaxNumber(const float& Number1, const float& Number2) // passing by constant reference.
//{
//	cout << "The maximum number is " << DetermineMaxNumber(Number1, Number2) << endl;   // DetermineMaxNumber() has to return  the max number of type float. Therefore the function is of type float in the implementation.
//}
//
//int main()
//{
//	int min = -1000000;
//	int max = 1000000;
//
//	float Number1, Number2;
//	// initializing the above variables via reading user input (using a procedure since MORE than one value is initialized):
//
//	ReadTwoNumbers("Enter number: ", min, max, Number1, Number2);
//	// Number1 & Number 2 are now initialized.
//
//	PrintMaxNumber(Number1, Number2); // This nested functions line is written so that, the implementation of the printing procedure contains the function DetermineMaxNumber(.
//	// this is how the design SHOULD BE ( & as a 'side effect'/ result, the printing procedure will have access to the original values
//	// the user entered that are Number1 & Number2.
//
//	return 0;
//}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





// B- Using two functions :

//
//float ReadFloatNumber(const string& message)   // pass by constant reference.
//{
//	float number; // what's returned
//
//	cout << message;
//	cin >> number;
//	cout << endl;
//
//	return number;
//}
//
//bool ValidateNumber(const float &number, int min, int max)   // passing by constant reference   // ranges ALWAYS passed by value.
//{
//	return (min <= number && number <= max); 
//}
//
//
//float ReadNumber1(const string &message, int min, int max) // passing by constant reference.  // ranges ALWAYS passed by value.
//{
//	float Number1; // what's returned;
//	do
//	{
//		Number1 = ReadFloatNumber(message);  // 'Number1' is to be IMMEDIATELY validated against the range, in the while condition.
//
//	} while (!ValidateNumber(Number1, min, max)); // the argument is written so that, it evaluates to TRUE when the condition is INVALID.
//
//	return Number1;
//	
//	// NOTE: The above block of code is to be sequentially written line by line
//	//       & at the end, implement the functions of: ReadFloatNumber & ValidateNumber().
//}
//
//
//float ReadNumber2(const string &message, int min, int max) // passing by constant reference.  // ranges ALWAYS passed by value.
//{
//	float Number2; // what's returned.
//	do
//	{
//		Number2 = ReadFloatNumber(message); // 'Number2' is to be IMMEDIATELY validated against the range, in the while condition.
//
//	} while (!ValidateNumber(Number2, min, max));
//
//	return Number2;
//
//}
//
//bool IsFirstBigger(const float& Number1, const float& Number2)    // passing by constant reference
//{
//	return (Number1 > Number2);
//}
//
//
//float DetermineMaxNumber(const float& Number1, const float& Number2)  // pass by constant reference.
//{
//	if (IsFirstBigger(Number1, Number2))  // Number1 > Number2
//	{
//		return Number1; 
//	}
//	else
//	{
//		return Number2;
//	}
//}
//
//
//void PrintMaxNumber(const float& Number1, const float& Number2)  // passing by constant reference.
//{
//	cout << "The maximum number is: " << DetermineMaxNumber(Number1, Number2) << endl; 
//}
//
//int main()
//{
//	int min = -1000000;
//	int max = 1000000;
//
//	// Initializing the below variable via reading user input (using function, since ONE value will be initialized and returned):
//	float Number1 = ReadNumber1("Enter the first number: ", min, max);
///*      |
//	    |
//	    |-----> to be written at the end after typing the 'return' keyword in the imlementation of the function.
//*/
//	
//	// Initializing the below variable via reading user input (using function, since ONE value is initialized and returned):
//	float Number2 = ReadNumber2("Enter the second number: ", min, max);
///*      |
//		|
//		|-----> to be written at the end after typing the 'return' keyword in the imlementation of the function.
//*/
//
//	PrintMaxNumber(Number1, Number2);   // This nested functions line is written so that, the implementation of the printing procedure contains the function DetermineMaxNumber(.
////	                                  // this is how the design SHOULD BE ( & as a 'side effect'/ result, the printing procedure will have access to the original values
////	                                  // the user entered that are Number1 & Number2.
//
//	return 0;
//}
//
//
//
//


////// The above B code is unoptimized
// Below is the optimized version:

//
//float ReadFloatNumber(const string& message)   // pass by constant reference.
//{
//	float number; // what's returned
//
//	cout << message;
//	cin >> number;
//	cout << endl;
//
//	return number;
//}
//
//bool ValidateNumber(const float &number, int min, int max)   // passing by constant reference   // ranges ALWAYS passed by value.
//{
//	return (min <= number && number <= max);
//}
//
//
//float ReadNumber(const string& message, int min, int max) // passing by constant reference.  // ranges ALWAYS passed by value.
//{
//	float Number; // what's returned;
//	do
//	{
//		Number = ReadFloatNumber(message);  // 'Number1' is to be IMMEDIATELY validated against the range, in the while condition.
//
//	} while (!ValidateNumber(Number, min, max)); // the argument is written so that, it evaluates to TRUE when the condition is INVALID.
//
//	return Number;
//
//	// NOTE: The above block of code is to be sequentially written line by line
//	//       & at the end, implement the functions of: ReadFloatNumber & ValidateNumber().
//}
//
//
//
//bool IsFirstBigger(const float& Number1, const float& Number2)    // passing by constant reference
//{
//	return (Number1 > Number2);
//}
//
//
//float DetermineMaxNumber(const float& Number1, const float& Number2)  // pass by constant reference.
//{
//	if (IsFirstBigger(Number1, Number2))  // Number1 > Number2
//	{
//		return Number1;
//	}
//	else
//	{
//		return Number2;
//	}
//}
//
//
//void PrintMaxNumber(const float& Number1, const float& Number2)  // passing by constant reference.
//{
//	cout << "The maximum number is: " << DetermineMaxNumber(Number1, Number2) << endl;
//}
//
//int main()
//{
//	int min = -1000000;
//	int max = 1000000;
//
//	// Initializing the below variable via reading user input (using function, since ONE value will be initialized and returned):
//	float Number1 = ReadNumber("Enter number: ", min, max);
//	/*      |
//			|
//			|-----> to be written at the end after typing the 'return' keyword in the imlementation of the function.
//	*/
//
//	// Initializing the below variable via reading user input (using function, since ONE value is initialized and returned):
//	float Number2 = ReadNumber("Enter number: ", min, max);
//	/*      |
//			|
//			|-----> to be written at the end after typing the 'return' keyword in the imlementation of the function.
//	*/
//
//	PrintMaxNumber(Number1, Number2);   // This nested functions line is written so that, the implementation of the printing procedure contains the function DetermineMaxNumber(.
//	//	                                  // this is how the design SHOULD BE ( & as a 'side effect'/ result, the printing procedure will have access to the original values
//	//	                                  // the user entered that are Number1 & Number2.
//
//	return 0;
//}








































////////////////////////////// BELOW: UNOPTIMIZED first attempt solutions /////////////////////////////////////////
//
//
//void ReadNumbers(float &Number1, float &Number2) // passing by reference
//{
//    cout << "Enter first number: ";
//    cin >> Number1;
//    cout << endl;
//
//    cout << "Enter second number: ";
//    cin >> Number2;
//    cout << endl;
//}
//
//
//float DetermineMaxNumber(const float& Number1, const float& Number2) // pass by constant reference.
//{
//    if (Number1 > Number2)
//    {
//        return Number1;
//    }
//    else 
//    {
//        return Number2;
//    }
//    
//}
//
//void PrintMaxNumber(const float &MaxNumber)   // pass by constant reference.
//{
//        cout << MaxNumber << " is bigger" << endl;  
//}
//
//int main()
//{
//    float Number1, Number2;
//    // Intitializing via reading user input:
//
//    ReadNumbers(Number1, Number2);
//    // Number1 & Number2 are now initialized.
//
//    PrintMaxNumber(DetermineMaxNumber(Number1, Number2)); // the argument has to be a function. As procedures return void.
//
//    return 0;
//}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//// or if you want:
//
//float ReadFirstNumber()
//{
//    float number; // what's returned.
//
//    cout << "Enter the first number: ";
//    cin >> number;
//    cout << endl;
//
//    return number;
//}
//
//float ReadSecondNumber()
//{
//    float number; // what's returned.
//
//    cout << "Enter the second number: ";
//    cin >> number;
//    cout << endl;
//
//    return number;
//}
//
//
//float DetermineMaxNumber(const float& Num1, const float& Num2) // pass by const. ref.
//{
//    if (Num1 > Num2)
//    {
//        return Num1;
//    }
//    else
//    {
//        return Num2;
//    }
//}
//
//void PrintMaxNumber(const float& MaxNumber) // pass by const ref.
//{
//    cout << MaxNumber << " is the biggest number" << endl;
//}
//
//int main()
//{
//    //Initializing the below variable via reading user input:
//    float Num1 = ReadFirstNumber(); /*
//    |
//    |------->The last thing to type.Type after writing "return" keyword in the implementing function. */
//
//    // Initializing the below variable via reading user input:
//    float Num2 = ReadSecondNumber();/*
//    |
//    |------->The last thing to type.Type after writing "return" keyword in the implementing function. */
//
//    PrintMaxNumber(DetermineMaxNumber(Num1, Num2)); // the argument HAS to be a function as procedures return void, which in this specific it'd throw an exception.
//
//    return 0; 
//}