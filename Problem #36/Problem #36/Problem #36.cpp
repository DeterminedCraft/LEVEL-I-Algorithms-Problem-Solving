
#include <iostream>
#include <string>
using namespace std;


/*
  Problem #36:
 
  Write a program to ask the user to enter:

    - Number1
    - Number2
    - OperationType
 
  Then perform the calculation according to the Operation Type as follows:
 
    - "+" : Add the two numbers.
    - "-" : Subtract the two numbers.
    - "*" : Multiply the two numbers.
    - "/" : Divide the two numbers.


   Example Input:
   10
   20
   *

   Output:
   200

 */





// since enums are utilized here - they are THE FIRST TO BE CODED before anything else.

enum enOperationType { Addition = '+', Subtraction = '-', Multiplication = '*', Division = '/' };
// the enumeration constants (enumerators) act as labels, (that are Addition, Subtraction, Multiplication, & Division), 
// for the raw integral values they represent (the raw integral values in this case are characters).
// so from now and on, FOREVER FORGET about these raw values and ALWAYS use their labels instead.

// so far, only an enum user-defined data type has been created and nothing more.
// the next natural step, is declaring a variable of this enum user-defined data type in main().


struct stCalculation
{
    double Number1;
    double Number2;
    enOperationType OperationType;
};
// so far, only a structure user-defined data type has been created and nothing more.
// the next natural step is creating a variable of this structure user-defined data type.
// But the main question is - where to create this variable ?
//
// - If it's going to be initialized directly, then declare it in main()
// - If it's going to be initialized via reading user input, then create it inside a reading procedure of the enum user-defined data type,
//   that returns this variable.
//  since it's the latter, then IMMEDIATELY start implementing this function NOW below:


double ReadDoubleNumber(const string &message)   // pass by constant reference.
{
    double number;  // what^s returned

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}

bool ValidateNumberRange(const double& number, double min, double max)   // pass by const. ref. since 'number' is only used for comparison against the range.
{
    return (min <= number && number <= max);
}


char ReadCharacter(const string &message)     // pass by constant reference.
{
    char character;  // what's returned

    cout << message;
    cin >> character;
    cout << endl;

    return character;  
}

enOperationType CastToEnumFromCharacter(char character)   // pass by value
{
    return enOperationType(character);
}



bool ValidateOperationSymbol(const enOperationType& OperationType)   // pass by constant ref. since 'OperationType' is only used for comparison against range.
{
    return  (OperationType == enOperationType::Addition ||        // To the left of the operand is the character that the user entered that was stored in a char variable, that then casted into an enum user-defined data type.   
        OperationType == enOperationType::Subtraction ||
        OperationType == enOperationType::Multiplication ||
        OperationType == enOperationType::Division);

        // A quick explanation: 
        // To the left of the operand is the character that the user entered that was stored in a char variable, that then casted into an enum user-defined data type.
        // To the right of the operand (enOperationType::Addition )  equates to '+' as shown in the enum creation step AT THE VERY TOP.
}


stCalculation ReadCalculation(const string &MessageNumber1, const string &MessageNumber2, const string &MessageSymbol, double min, double max) // passing by constant reference.  // Ranges ALWAYS passed by value.
{
    stCalculation calculation; // what's returned  // AS SOON AS you see this line, ALWAYS envision 'calculation' having access to all member variables inside the structure.

    do
    {
        calculation.Number1 = ReadDoubleNumber(MessageNumber1);  // 'calculation.Number1' is to be IMMEDIATELY validated against the range, in the while condition

    } while (!ValidateNumberRange(calculation.Number1, min, max));  // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

    do
    {
        calculation.Number2 = ReadDoubleNumber(MessageNumber2);  // 'calculation.Number2' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateNumberRange(calculation.Number2, min, max));  // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

    do
    {
        calculation.OperationType = CastToEnumFromCharacter((ReadCharacter(MessageSymbol)));  // ' calculation.OperationType' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateOperationSymbol(calculation.OperationType));   // the argument is written so that, it evaluates to TRUE when the condition is INVALID.


    return calculation;

    // Note: The above block of code is to be sequentially composed line by line
    //       and at then end, implement the functions of:
    //       ReadDoubleNumber(), ValidateNumberRange()
    //       ReadCharacter() , CastToEnumFromCharacter()
    //       !ValidateOperationSymbol
}


double CalculateAddition(const stCalculation& calculation)   // ALWAYS pass structures by constant reference ( as passing by reference consumes too much memory as structures are heavy in nature).
{
    return calculation.Number1 + calculation.Number2;
}

double CalculateSubtraction(const stCalculation& calculation)   // ALWAYS pass structures by constant reference ( as passing by reference consumes too much memory as structures are heavy in nature).
{
    return calculation.Number1 - calculation.Number2;
}

double CalculateMultiplication(const stCalculation& calculation)   // ALWAYS pass structures by constant reference ( as passing by reference consumes too much memory as structures are heavy in nature).
{
    return calculation.Number1 * calculation.Number2;
}

double CalculateDivision(const stCalculation& calculation)   // ALWAYS pass structures by constant reference ( as passing by reference consumes too much memory as structures are heavy in nature).
{
    if (calculation.Number2 == 0)                             // this touches on some advanced topics in the upcoming C++ Level II
    {
        cout << "Undefined Error: Division By Zero \n";
        return 0;
    }

        return calculation.Number1 / calculation.Number2;    // NOT an integer division as Number1 & Number2 (one of them is enough) are doubles.
 }
   




double PerformCalculation(const stCalculation& calculation)  // ALWAYS pass structures by constant reference ( as passing by reference consumes too much memory as structures are heavy in nature).
{ // AS SOON AS you notice this argument line, ALWAYS envision 'calculation' having access to ALL member variables defined in the structure.

    switch (calculation.OperationType)  //argument is the character that the user entered that got stored into a character variable, THEN CASTED INTO AN ENUM-USER DEFINED DATA TYPE.
    {                                   // for example, the argument = + (of data type enOperationType) [ but in reality, it's stored as 43 in memory]

    case enOperationType::Addition:   // One can NOT use '+' because we ONLY use the labels (enumeration constants/enumerators) = FOREVER FORGET. Plus, only identical data types should be compared.
        return CalculateAddition(calculation);      //   calculation.Number1 + calculation.Number2      no matter how small and simple-looking this line is, always wrap it in a function.
        // no need for a break statement here as the return keyword, if executed, causes the controller to exit the switch statement.

    case enOperationType::Subtraction:
        return CalculateSubtraction(calculation);

    case enOperationType::Multiplication:
        return CalculateMultiplication(calculation);

    case enOperationType::Division:
        return CalculateDivision(calculation);

    default:
        return 0;

    }
}

void PrintResult(const stCalculation& calculation)     // pass by constant reference.
{ 
    cout << calculation.Number1 << " " << static_cast<char> (calculation.OperationType) << " " << calculation.Number2 << " = " << PerformCalculation(calculation) << endl;
    
    // Below will print + or - or * or / symbols as numeric values
    //cout << calculation.Number1 << " " << calculation.OperationType  << " " << calculation.Number2 << " = " << PerformCalculation(calculation) << endl;  
}

int main()
{
    enOperationType OperationType; // the next natural step of declaring a variable of this enum user-defined data type.

    // Instead of declaring Number1, Number2, & OperationType as variables in main(),
    // I'm going to declare them as member variables inside a structure since they're
    // related amongst each other.

    double min = -5000000;
    double max =  5000000;
    double restricted = 0;    // Number 2 should not equal to ZERO (ONLY when dividing).

    PrintResult(ReadCalculation("Enter Number 1: ", "Enter Number 2: ", "Enter Operation Symbol (Type + for Adding   - for Subtracting   * for Multiplying   / for Dividing): ", min, max));

    return 0;
}





    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Now if I want to prompt the user to re-enter the second number ONLY if it were used for division, where its value = 0,



enum enOperationType { Addition = '+', Subtraction = '-', Multiplication = '*', Division = '/' };


struct stCalculation
{
    double Number1;
    double Number2;
    enOperationType OperationType;
};


double ReadDoubleNumber(const string& message)  
{
    double number;  // what^s returned

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}

bool ValidateNumberRange(const double& number, double min, double max)   
{
    return (min <= number && number <= max);
}


char ReadCharacter(const string& message)    
{
    char character;  // what's returned

    cout << message;
    cin >> character;
    cout << endl;

    return character;
}

enOperationType CastToEnumFromCharacter(char character)   
{
    return enOperationType(character);
}



bool ValidateOperationSymbol(const enOperationType& OperationType)   
{
    return  (OperationType == enOperationType::Addition || 
             OperationType == enOperationType::Subtraction ||
             OperationType == enOperationType::Multiplication ||
             OperationType == enOperationType::Division);

 
}

bool ValidateNonZero(const double& Number2)
{
    return (Number2 != 0);
}

stCalculation ReadCalculation(const string& MessageNumber1, const string& MessageNumber2, const string& MessageSymbol, double min, double max) 
{
    int counter = 0;

    stCalculation calculation; 

    do
    {
        calculation.Number1 = ReadDoubleNumber(MessageNumber1);  
 
    } while (!ValidateNumberRange(calculation.Number1, min, max));  



    do
    {
        calculation.OperationType = CastToEnumFromCharacter((ReadCharacter(MessageSymbol)));

    } while (!ValidateOperationSymbol(calculation.OperationType));


   
    do
    {
        counter++;
        if (counter > 1)
        {
            cout << "Division By Zero - Undefined. ";
        }

        calculation.Number2 = ReadDoubleNumber(MessageNumber2);  

    } while (!ValidateNumberRange(calculation.Number2, min, max)  ||  (calculation.OperationType == enOperationType::Division && !ValidateNonZero(calculation.Number2)));
    
    
    // Below- a 'cleaner' approach as counter is not declared.
    /*
    calculation.Number2 = ReadDoubleNumber(MessageNumber2);
    while (!ValidateNumberRange(calculation.Number2, min, max) || (calculation.OperationType == enOperationType::Division && !ValidateNumLargerThanZero(calculation.Number2)))
    {
        cout << "Division By Zero - Undefined. ";
        calculation.Number2 = ReadDoubleNumber(MessageNumber2);
    }
    */


    return calculation;

}


double CalculateAddition(const stCalculation& calculation)   
{
    return calculation.Number1 + calculation.Number2;
}

double CalculateSubtraction(const stCalculation& calculation)   
{
    return calculation.Number1 - calculation.Number2;
}

double CalculateMultiplication(const stCalculation& calculation)   
{
    return calculation.Number1 * calculation.Number2;
}

double CalculateDivision(const stCalculation& calculation) 
{
    return calculation.Number1 / calculation.Number2;    
}





double PerformCalculation(const stCalculation& calculation)  
{ 

    switch (calculation.OperationType)  
    {                                   

    case enOperationType::Addition:  
        return CalculateAddition(calculation);    
      

    case enOperationType::Subtraction:
        return CalculateSubtraction(calculation);

    case enOperationType::Multiplication:
        return CalculateMultiplication(calculation);

    case enOperationType::Division:
        return CalculateDivision(calculation);

    default:
        return 0;

    }
}

void PrintResult(const stCalculation& calculation)    
{
    cout << calculation.Number1 << " " << static_cast<char> (calculation.OperationType) << " " << calculation.Number2 << " = " << PerformCalculation(calculation) << endl;

 
}

int main()
{
   // enOperationType OperationType;  // commented out- turned out it was not needed.


    double min = -5000000;
    double max = 5000000;
    double restricted = 0;    

    PrintResult(ReadCalculation("Enter Number 1: ", "Enter Number 2: ", "Enter Operation Symbol (Type + for Adding   - for Subtracting   * for Multiplying   / for Dividing): ", min, max));

    return 0;
}






/* Note:  the BELOW CODE IS WRONG


  if (calculation.OperationType == enOperationType::Addition)  // To the left: is the character the user entered that was stored in a char variable, then casted into an enum user-defined data type.
    {                                                            // to the right, one can not user '+' because we ONLY use the labels (enumeration constants/enumerators) = FOREVER FORGET. Plus, only identical data types should be compared.
        return CalculateAddition(calculation);    // (calculation.Number1 + calculation.Number2)    no matter how small or simple-looking  this line is, always wrap it inside a function.
    }

    else if (calculation.OperationType == enOperationType::Subtraction)
    {
        return CalculateSubtraction(calculation);
    }

    else if (calculation.OperationType == enOperationType::Multiplication)
    {
        return CalculateMultiplication(calculation);
    }

    else if (calculation.OperationType == enOperationType::Division)
    {
        return CalculateDivision(calculation);
    }



    REASON IS THAT:
    A switch statement is to be used when multiple if statements are used to check equality.
}*/











