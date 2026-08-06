
#include <iostream>
#include <cmath>
using namespace std;

/* Problem #46:
   
   Print out the letters from A to Z

*/

// A 65   to Z 90     in the ASCII table

void PrintLettersFromAToZ()
{
    for (int i = 65; i <= 90; i++)
    {
        cout << char(i) << "\n";
    }
}


int main()
{
    
    PrintLettersFromAToZ();

    return 0;
}







//////////////////////// Another Solution ///////////
//////////////////////// Another Solution ///////////


void PrintLettersFromAToZ()
{
    for (char c = 'A'; c <= 'Z'; c++)
    {
        cout << c << "\n";
    }
}


int main()
{

    PrintLettersFromAToZ();

    return 0;
}
