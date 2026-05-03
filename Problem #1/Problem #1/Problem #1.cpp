// Level 1- Algorithms & Problem-Solving Series.cpp 

#include <iostream>
using namespace std;

/*
Problem #1

 Write a program to print your name on screen.

*/




// The note below, from now on, will NOT be included in the next examples ⇒
// (it will always apply, but will not be pointed out again): ⇒
// 
// When implementing a procedure/function (implementing is outside main()), do so IN ACCORDANCE WITH the called function/ procedure in main().

void PrintName(const string &name) // passing by constant reference.
{
	cout << "\n" << name << "\n";
}

int main()
{
	PrintName("Ahmad El-Aina");   // Divide& conquer فَرِّقْ تَسُدْ

	return 0;
}

/* Yes, one could have instead used:
   
   string name = "Ahmad El-Aina";
   PrintName(name);

   // but think about it this way:
      Since the program is so simple, then the other way of coding deems our code more optimized.
	  But no difference really.
	  

*/

