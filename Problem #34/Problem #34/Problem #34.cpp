
#include <iostream>
using namespace std;


/*
 * Problem #34:
 
 *   Write a program to ask the user to enter:
 *     - TotalSales
 *
 *   The commission is calculated as one percentage * the total sales amount.
 * 
 *   All you need is to decide which percentage to use of the following:
 *
 *     - > 1,000,000        → Percentage is 1%
 *     - > 500K to 1M       → Percentage is 2%
 *     - > 100K - 500K      → Percentage is 3%
 *     - > 50K to 100K      → Percentage is 5%
 *     - Otherwise          → Percentage is 0%
 *
 *   Example Inputs:  110,000
 *   Outputs:         The commission amount is 3,300
 */



double ReadDoubleNumber(const string& message)   // pass by constant reference
{
    double number;  // what's returned

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}

bool ValidateTotalSalesRange(const double& TotalSales)  // passing by constant ref, since TotalSales is only going to be compared against some range
{
    return (TotalSales > 0);
}


double ReadTotalSales(string message)
{
    double TotalSales;   // what's returned
    
    do
    {
        TotalSales = ReadDoubleNumber(message);  // 'TotalSales' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateTotalSalesRange(TotalSales)); // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

    return TotalSales;

    /* Note: The above block of code is to be sequentially composed line by line
             and at the end, implement the functions of:  ReadDoubleNumber()  &  ValidateTotalSalesRange()
    
    */
}

double DetermineCommissionPercentage(double TotalSales)   // pass by value
{
    if (TotalSales > 1000000)
    {
        return 0.01; 
    }
    else if (TotalSales > 500000)
    {
        return 0.02;
    }
    else if (TotalSales > 100000)
    {
        return 0.03;
    }
    else if (TotalSales > 50000)
    {
        return 0.05;
    }
    else
    {
        return 0;
    }
}

double CalculateCommissionAmount(double TotalSales)   // pass by value
{
    return DetermineCommissionPercentage(TotalSales) * TotalSales;
}

void PrintCommissionAmount(const double& TotalSales)   // passing by constant reference.
{
    cout << " The commission amount = " << CalculateCommissionAmount(TotalSales) << endl;   // Divide and conquer  farrik tasud !!

    /* The line below is not good for readability with the second argument (TotalSales) present 
    cout << " The commission amount = " << CalculateCommissionAmount(DetermineCommissionPercentage(TotalSales), TotalSales) << endl;   
    */

    // instead of: (below solution does not capitalize of the Divide & conquer stratgey.)
    //cout << " The commission amount = " << DetermineCommissionPercentage(TotalSales) * TotalSales << endl;

}



int main()
{
    
    PrintCommissionAmount(ReadTotalSales("Enter Total Sales amount: ")); // Range(s) NOT provided as its value is NOT intrinsic.
    // the printing procedure is written so that, it contains the function CalculateCommissionAmount()
    // this is a standard coding approach.
    // separately and as a 'side effect', the printing procedure will have access to the original Sales Amount value entered by the user

    return 0;
}





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// However- if it's required to print out the comission rate and then the commision amount as in:  

/*
 * Problem #34:

 *   Write a program to ask the user to enter:
 *     - TotalSales
 *
 *   The commission is calculated as one percentage * the total sales amount.
 *
 *   All you need is to decide which percentage to use of the following:
 *
 *     - > 1,000,000        → Percentage is 1%
 *     - > 500K to 1M       → Percentage is 2%
 *     - > 100K - 500K      → Percentage is 3%
 *     - > 50K to 100K      → Percentage is 5%
 *     - Otherwise          → Percentage is 0%
 *
 *   Example Inputs:  110,000
 * 
 *   Outputs:         The commision %  is: 3%
                      The commission amount is; 3,300
 */


double ReadDoubleNumber(const string& message)    // pass by constant reference.
{
    double number;

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}

bool ValidateTotalSalesRange(const double& TotalSales)
{
    return (TotalSales > 0);
}


double ReadTotalSales(const string& message)   // pass by constant reference.
{
    double TotalSales; // what's returned.

    do
    {
        TotalSales = ReadDoubleNumber(message);

    } while (!ValidateTotalSalesRange(TotalSales));

    return TotalSales;
}


double CalculateCommissionPercentage(double TotalSales)
{
    if (TotalSales > 1000000)
        return 0.01;

    else if (TotalSales > 500000)
        return 0.02;

    else if (TotalSales > 100000)
        return 0.03;

    else if (TotalSales > 50000)
        return 0.05;

    else
        return 0;
}




void PrintCommissionAmount(const double &CommissionPercentage, const double& TotalSales)
{
    cout << "The commission amount = " << CommissionPercentage * TotalSales << endl;
}

void PrintCommissionPercentageAndAmount(const double& TotalSales)
{
    double CommissionPercentage = CalculateCommissionPercentage(TotalSales);

    cout << "The commission percentage is " << CommissionPercentage * 100 << " %" << endl;

    PrintCommissionAmount(CommissionPercentage, TotalSales);
}


int main()
{

    PrintCommissionPercentageAndAmount(ReadTotalSales("Enter your Total Sales: "));   // Range(s) NOT included as their value is NOT intrinsic.

    return 0;
}