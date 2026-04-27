// problem #9.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>
using namespace std;

/*
Problem #9:

 Write a program to ask the user to enter:
 - Number1, Number2, Number3

 Then print the Sum of the entered numbers.

 Example Inputs:
 10
 20
 30

 Output:
 60

*/

/* Solution:
	
   This problem is solved using a collection class instead of the fixed-length data structure that's an array.
   If the 3 numbers are hardcoded, then an array is suitable. However, since the 3 inputs are via user input,
   then a collection class is the way to go and especially since the number of elements can be increased or decreased
   . Meaning, if we decide to enter 4 or 5, etc. numbers instead of 3 then the code will remain the same.

   But, the issue is that - we've not gotten to that stage yet. 
   Therefore- we can only: 
   - Either declare three variables
   - OR declare an array that's a fixed-length data structure and find our away around it to make the program work

*/


// #1 - The UNOPTIMIZED solution of declaring 3 variables.    CRUCIAL: CREATE A MENTAL MODEL out of this example

float ReadNumber(const string &msg) // passing by reference.
{
	float Number; // what's returned.

	cout << msg;
	cin >> Number; 
	cout << endl;

	return Number;
}

bool ValidateFloatNumberInRange(const float& Num, int min, int max)   // passing by constant reference. // ranges ALWAYS passed by value.
{
	return (min <= Num && Num <= max);
}
	


void ReadFloatNumbersInRange(float& Num1, float& Num2, float& Num3, int min, int max) // pass by reference.  // ranges ALWAYS passed by value.
{
	do
	{
		Num1 = ReadNumber("Enter Number 1: "); // 'Num1' is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateFloatNumberInRange(Num1, min, max));


	do
	{
		Num2= ReadNumber("Enter Number 2: "); // 'Num2' is to be IMMEDIATELY validated against the range, in the while conditon.

	} while (!ValidateFloatNumberInRange(Num2, min, max));


	do
	{
		Num3 = ReadNumber("Enter Number 3: ");   // 'Num3' is to be IMMEDIATELY validated against the range, in the while conditon.

	} while (!ValidateFloatNumberInRange(Num3, min, max));

	// Note: The above lines of code are to be written sequentially line-by-line
	// and at the end. implement the 6 functions of: 
	// ReadNumber1(), ValidateFloatNum1InRange(), ReadNumber2(), ValidateFloatNum2InRange(), ReadNumber3(), ValidateFloatNum3InRange(),
}

float CalculateSumOfThreeNumbers(float Num1, float Num2, float Num3) // passing by value
{
	return Num1 + Num2 + Num3;
}

void PrintSumOfThreeNumbers(const float& Num1, const float& Num2, const float& Num3)   // pass by constant reference.
{
	cout << "The sum is " << CalculateSumOfThreeNumbers(Num1, Num2, Num3) << endl;
}


int main()
{
	// PrintSumOfThreeNumbers(ReadFloatNumberSInRange());  //❌❌❌ 🚫🚫🚫 Invalid nested functions line:
	// // as the argument that's ReadFloatNumberSInRange() can only be a procedure [as function can only return one value] that returns void = throwing an exception.
	// 
	// The 3 variables are to be declared inside main() 
	// and initialized via reading user input
    // where the implementing function passess params by reference.
    // Otherwise, How would one be able to continue writing the program inside main() ?
    // where they'll have to continue coding inside that procedure which is ridiculous and violates the SRP.
    // 
    // PLUS- This can only be done utilizing a procedure that will have 3 cin statements. 
    // A function can only return ONE value.
	float Num1, Num2, Num3;

	int min = -1000000; // instead of hardcoding them
	int max =  1000000; // instead of hardcoding them

	ReadFloatNumbersInRange(Num1, Num2, Num3, min, max);  
	// Num1, Num2, Num3 are NOW initialized.

	PrintSumOfThreeNumbers(Num1, Num2, Num3); // this nested functions line is written so that the printing procedure references the CalculateSumOfThreeNumbers() function (adhering to design standards)

	

	return 0;
}




//// #2- The UNOPTIMIZED solution of using an array (that's a fixed-length data structure).
//
const int NumberOfElements = 3; // Instead of hardcoding it in the fixed-length data structure array. // later I discovered that I ought to render it as gloal variable.

void ReadFloatNumbersInRange(float numbers[NumberOfElements])  // arrays are ALWAYS passed by reference & Including the & sign, renders an exception.
{
	for( int i = 0; i < NumberOfElements; i++)
	{
		cout << "Enter number " << i + 1 << " : ";
		cin >> numbers[i];
		cout << endl;
	}
}

float CalculateSumOfNumbers(float numbers[NumberOfElements]) // arrays are ALWAYS passed by reference & Including the & sign, renders an exception.
{
	float sum = 0;  // routine  // what's returned.

	for (int i = 0; i < NumberOfElements; i++)
	{
		sum = sum + numbers[i];
	}

	return sum;
}

void PrintSumOfNumbers(float numbers[NumberOfElements]) // arrays are ALWAYS passed by reference & Including the & sign, renders an exception
                                                         // one can NOT include const in here (will render an error).
	// trace it: CalculateSumOfNumbers(float numbers[NumberOfElements])    has the argument of float data type and NOT const float.
{
	cout << "The sum is: " << CalculateSumOfNumbers(numbers) << endl;
}

int main()
{ 
	
	float numbers[NumberOfElements];

	ReadFloatNumbersInRange(numbers); // the array is, by default, passed along with its address in memory. 
	                                 // Hence, the implementing function will pass params by ref. without the & sign
	                                // it has to be a procedure as an array can NOT be returned (contains more that one element).
								  
	// the array 'numbers' has been initialized.
	PrintSumOfNumbers(numbers);// the array 'numbers' passed as an argument along with its address memory.
	// this nested line function is written so that, the implementation of the printing procedure contains another function that is CalculateSumOfNumbers() and this is the correct approach.
	// as a by-product per say, this printing procedure can still reference the 'numbers' array.

	return 0;
}















































      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         ///////////////////////////////////////////  Below are some first attempt VERY OLD UNOPTIMIZED SOLUTIONs ////////////////////////////////////////////////////////////////////
          //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
           ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
///* Solution:
//
//   Only having:
//
//   #include <iostream>
//   using namespace std;
//
//   while using the array fixed-length data structure,
//   means that an array can NEVER be returned by a function.
//
//*/
//const int NumberOfElements = 3; // Instead of hardcoding it in the fixed-length data structure array. // later I discovered that I ought to render it as gloal variable.
//
//void ReadNumbers(float numbers[NumberOfElements]) // arrays are ALWAYS passed by reference & Including the & sign, renders an exception.
//{
//    for (int i=0; i < NumberOfElements; i++)
//    {
//        cout << "Enter Number " << i + 1 << " : ";
//        cin >> numbers[i];
//        cout << endl;
//    }
//}
//
//float CalculateSumOfArrayElements(float numbers[NumberOfElements]) // arrays are ALWAYS passed by reference & Including the & sign, renders an exception.
//{
//    float sum = 0;
//    for (int i = 0; i < NumberOfElements; i++)
//    {
//        sum += numbers[i];  
//    }
//
//    return sum;
//}
//
//void PrintSumOfArrayElements(const float &sum) // arrays are ALWAYS passed by reference & Including the & sign, renders an exception.
//{
//    cout << "Their sum is: " << sum << endl; // here I will NOT be able to reference the 3 numbers (& no need for it really!) 
//}                                              // because of the current nested functions line construction in main()
// 
//int main()
//{
//    // a function can NOT return an array that is a fixed-length data structure. And given that only    #include <iostream> library    is utilized.
//    float numbers[NumberOfElements];
//    // initializing the array variable via reading user-input:
//
//
//    ReadNumbers(numbers);   // passing the array variable as an argument. It's passed along with its memory address. 
//                            // hence, it's always passed by reference in the implementing function.
////                         //  Including & in the implementing function will render an exception.
//   // CRUCIAL: Passing the argument: numbers[3] means you are passing the element in the 4th index which does NOT exist.
//                           
//    // The array variable 'numbers' is now fully initialized.
//   
//
//    PrintSumOfArrayElements(CalculateSumOfArrayElements(numbers));  // Where the 'numbers' array argument is passed along its address in memory. 
//                                                                    // Hence, the implementing function will pass params by ref. without the & sign.
//                                                                    // 
//    // I chose this line of nested functions becasue there is no need to reference the 
//    // original 3 numbers that the user just entered, when I want to print the sum onto the screen.
//    return 0;
//}
//
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Now, what if I want to reference the original 3 numbers the user just entered when I want to display the sum ?
//
///* For example:
//
// Write a program to ask the user to enter:
// - Number1, Number2, Number3
//
// Then print the Sum of entered numbers.
//
// Example Inputs:
// 10
// 20
// 30
//
// Output:
// The three numbers entered that are 10, 20, & 30 has a sum of 60  👈👈 If this is what I want to display (referencing the original entered 3 numbers)
//
//
//*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
///* Primitive solutions 3 variables instead of an array:
// 
//*/
//
//
//void ReadNumbers(float& Num1, float& Num2, float& Num3) // Passing by reference. So that the variables declared in main are initialized so that we continue
//                                                        // writing our code in main(). Otherwise, we have to continue coding inside this procedure which
//                                                        // violates the SRP.
//{
//    cout << "Enter First Number: ";
//    cin >> Num1;
//    cout << endl;
//
//    cout << "Enter Second Number: ";
//    cin >> Num2;
//    cout << endl;
//
//    cout << "Enter Third Number: ";
//    cin >> Num3;
//    cout << endl;
//}
//
//float CalculateSum(float Num1, float Num2, float Num3) // passing by value.
//{
//    return (Num1 + Num2 + Num3);
//}
//
//void PrintResult(const float& Num1, const float& Num2, const float& Num3)
//{
//    cout << "The sum of the numbers: " << Num1 << " & " << Num2 << " & " << Num3 << " = " << CalculateSum(Num1, Num2, Num3) << endl;
//}
//
//int main()
//{
//    
//    float Num1, Num2, Num3;
//    // Initializing these variables via reading user input:
//
//    ReadNumbers(Num1, Num2, Num3);
//    // the variables Num1, Num2, & Num3 are now initialized.
//
//    // Now:
//    /*
//
//    PrintResult(CalculateSum(Num1, Num2, Num3)); // works but the printing procedure won't have reference to Num1, Num2, & Num3 (Ex: the sum of Num1, Numb2,.. is =) wont be possible.
//    //unless you state:
//    PrintResult(CalculateSum(Num1, Num2, Num3),  Num1, Num2, Num3); // works ! BUT- don't you think it looks hard to read?
//
//    */
//
//    // so instead, try:
//    PrintResult(Num1, Num2, Num3);
//
//    return 0;
//
//
//    /* In this SPECIFIC example, any of the following is NOT going to work:
//
//     PrintSum(CalculateSum(ReadNumbers()));
//     PrintSum(ReadNumber());
//
//     because, again, in this SPECIFIC example:
//     
//     ReadNumbers() can only be a procedure that initializes 3 numbers.
//
//     If it was to initialize one number only
//     then that one number is to be returned using a function instead.
//
//    */
//}
//   
//
//    
//
