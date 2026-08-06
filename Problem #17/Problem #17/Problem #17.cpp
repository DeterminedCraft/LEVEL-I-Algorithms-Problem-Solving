
#include <iostream>
using namespace std;

/*
 Problem #17:
 Write a program to calculate the triangle area then print it on the screen.

 The user should enter:
 a (base)
 h (height)

 Formula:
 Area = 1/2 * a * h

 Example Inputs:
 10
 8

 Output:
 40

*/





float ReadFloatNumber(const string& message)   // pass by constant reference.
{
	float number;  // what's returned.

	cout << message;
	cin >> number;
	cout << endl;
	return number;
}

bool ValidateBaseRange(const float& base)  // pass by constant ref.
{
	return (base > 0);
}


float ReadBase(const string& message)  // pass by constant reference.
{
	float base;  //what's returned.   // declared outside 'do' so that its scope allows it to be returned.

	do
	{
		base = ReadFloatNumber(message);  // 'base' to be IMMEDIATELY validated againsr the range, in the whil condition

	} while (!ValidateBaseRange(base));   // the argument is written so that, it evaluates to TRUE when the condition is INVALID

	return base;

	// the above lines of code are to be sequentially composed line by line
	// and at the end, implement the functions of:
	// ReadFloatNumber()  &  ValidateBaseRange()
}

bool ValidateHeightRange(const float& height)    // pass by constant reference.
{
	return (height > 0);
}

float ReadHeight(const string& message)    // pass by constant reference.
{
	float height;   // what's returned.   // declared outside the do, so that its scope is at the function level so that it can be returned.

	do
	{
		height = ReadFloatNumber(message);  // 'height' is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateHeightRange(height));  // the argument is written so that, it evaluates to TRUE when the condition is INVALID

	return height; 
	// the above lines of code are to be sequentially composed line by line
	// and at the end, implement the functions of:
	// ReadFloatNumber()  &  ValidateHeightRange()
}

float CalculateTriangleArea(float base, float height)   // pass by value.
{
	return ((1/2.0) * base * height);   // be careful here - (1/2) alone will perform INTEGER DIVISION deeming it equal to ZERO. To overcome that, add .0 to 1 or 2 or both.
}

void PrintTriangleArea(const float& base, const float& height)    // passing by constant reference.
{
	cout << "The Triangle's area is: " << CalculateTriangleArea(base, height) << endl;
}

int main()
{
	// Initializing the below variable via reading user input (Using Function since ONE variable will be initialized):
	float base = ReadBase("Enter base: ");  // range NOT included as its value is NOT intrinsic.
/*         |
           |--> to be typed at the end, after finishing typing the "return" keyword.
*/

	// Initializing the below variable via reading user input (Using function since ONE variable will be initialized and returned):
	float height = ReadHeight("Enter height: ");
/*         |
		   |--> to be typed at the end, after finishing typing the "return" keyword.
*/


	PrintTriangleArea(base, height);   //this line is constructed so that, the procedure contains the CalculateTriangleArea() function
	                                   // this is the standard approach in programming. Additionally, as a result, 
	                                  // this procedure will have access / can reference the 'base' & 'height' values entered by the user.

	return 0;
}






/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Another way of solving it:


float ReadFloatNumber(const string& BaseMessage)    // pass by constant ref.
{
	float number;  // what's returned.

	cout << BaseMessage;
	cin >> number;
	cout << endl;

	return number;
}

bool ValidateBaseRange(const float& base)   // pass by constant ref.
{
	return (base > 0);
}


void ReadInfo(const string& BaseMessage, float& BaseOrHeight)  // pass base by ref. otherwise, how can it's declared variable in main() be initialized ?
{
	do
	{
		BaseOrHeight = ReadFloatNumber(BaseMessage);  // 'base' is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateBaseRange(BaseOrHeight));

    // the above lines of code are to be sequentially composed line by line
	// and at the end, implement the functions of:
	// ReadFloatNumber()  &  ValidateHeightRange()
}


void ReadBaseAndHeight(string BaseMessage, string HeightMessage, float& base, float& height)  // passing base & height by ref. Otherwise, how can their declared variables in main() be initialized ?
{
	ReadInfo(BaseMessage, base);
	ReadInfo(HeightMessage, height);
}



float CalculateTriangleArea(float base, float height)   // pass by value.
{
	return ((1 / 2.0) * base * height);   // be careful here - (1/2) alone will perform INTEGER DIVISION deeming it equal to ZERO. To overcome that, add .0 to 1 or 2 or both.
}

void PrintTriangleArea(const float& base, const float& height)    // passing by constant reference.
{
	cout << "The Triangle's area is: " << CalculateTriangleArea(base, height) << endl;
}


int main()
{
	float base, height; 
	// Initializing the above variables via reading user input (Using Procedure since MORE than one variable is initialized):

	ReadBaseAndHeight("Enter base: ", "Enter height: ", base, height);  // ranges NOT included as their values are NOT intrinsic.
	// 'base' & 'height' are now initialized.

 
	PrintTriangleArea(base, height);   //this line is constructed so that, the procedure contains the CalculateTriangleArea() function
	// this is the standard approach in programming. Additionally, as a result, 
   // this procedure will have access / can reference the 'base' & 'height' values entered by the user.

	return 0;
}








//                          /////////////////////////////// Old first-attempt UNOPTIMIZED solution ////////////////////////////
//                         /////////////////////////////// Old first-attempt UNOPTIMIZED solution ////////////////////////////
//                        /////////////////////////////// Old first-attempt UNOPTIMIZED solution ////////////////////////////
//
//void ReadTriangleInfo(float &base, float &height) // passing be reference.
//{
//    cout << "Enter Triangle's base: ";
//    cin >> base;
//    cout << endl;
//
//    cout << "Enter Triangle's height: ";
//    cin >> height;
//    cout << endl;
//}
//
//float CalculateTriangleAreaByBaseAndHeight(float base, float height)  // passing by value
//{
//    return (1.0 / 2) * base * height;  // CRUCIAL: (1/2) denotes integer division, meaning that zero is what will be returned. 0.5 is even better than (1.0/2) 0r (1/2.0)
//}
// 
//void PrintTriangleArea(const float &area)   //pass by constant reference.
//{
//    cout << "The triangle's area = " << area << endl;
//}
//
//int main()
//{
//    
//    float base, height;
//    // Initializing via reading user input:
//
//    ReadTriangleInfo(base, height);
//    // the variables 'base' & 'height' are now initialized.
//
//    PrintTriangleArea(CalculateTriangleAreaByBaseAndHeight(base, height));
//    
//    
//    
//    
//    return 0;
//}


