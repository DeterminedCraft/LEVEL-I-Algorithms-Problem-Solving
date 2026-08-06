
#include <iostream>
using namespace std;

/*
     Problem #40:
     A restaurant charges 10% services fee and 16% sales tax.

     Write a program to read a BillValue and add:
     
     - Service fee
     - Sales tax 

     and print the TotalBill on the screen.

     Input
     100

     Outputs ->
     127.6 ( The sales tax is applied against the bill amount plus the service fee). 


*/

double ReadDoubleNumber(const string& message)    // pass by constant reference.
{
    double number;  // what's returned.

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}



bool ValidateBillValue(const double& BillValue)    // pass by constant reference, since it's ONLY used for comparison against the range
{
    return (BillValue >= 0);
}



double ReadBillValue(const string& message)   // pass by constant reference.
{
    double BillValue;   // what's returned.

    BillValue = ReadDoubleNumber(message);  // 'BillValue' is to be IMMEDIATELY validated against the range, in the while condition.

    while (!ValidateBillValue(BillValue))    // the condition is written so that, it evaluates to TRUE when the condition is INVALID.
    {
        cout << "Error. Bill value can't be negative. ";
        BillValue = ReadDoubleNumber(message);
    }

    return BillValue;

    /* Note: The above block of code is to be sequentially composed line by line
             ,and at the end implement the functions of:  ReadDoubleNumber()  & ValidateBillValue()    */
}


double CalculateServiceFeeAmount(double BillValue)   // pass by value.
{
    return (BillValue * 0.10);
}

double CalculateTaxAmount(double BillValuePlusServiceFeeAmount)  // pass by value.
{
    return (BillValuePlusServiceFeeAmount * 0.16);
}

double CalculateTotalBill(double BillValue)   // pass by value
{
    double BillValuePlusServiceFeeAmount = BillValue + CalculateServiceFeeAmount(BillValue);

    return (BillValuePlusServiceFeeAmount + CalculateTaxAmount(BillValuePlusServiceFeeAmount));
}

void PrintTotalBillAfterServiceAndTax(const double& BillValue)    // pass by constant reference.
{
    cout << "Total Bill After Service and Tax = " << CalculateTotalBill(BillValue) << endl;
}

void PrintMenu()
{
    cout << "****************************************************************************** \n";
    cout << "                         Service Tax = % 10 \n";
    cout << "                         Sales Tax   = % 16 \n \n";
    cout << " Sales Tax is applied on the Total Amount of the amount plus the service tax.\n";
    cout << "****************************************************************************** \n\n\n";
   
    
}

int main()
{
    double BillValue = ReadBillValue("Enter the bill value: ");

    PrintMenu();

    PrintTotalBillAfterServiceAndTax(BillValue);   // Ranges not included as its value is NOT intrinsic. 
    // this printing procedure will have the function CalculateTotalBill()
    // this is a standard coding practice where it's also conducive to the printing procedure
    // having access or can reference the original value entered by the user which is the bill value.


    return 0;
}


