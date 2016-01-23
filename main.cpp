//*****************************************************
//  Charles Darnell Johnson
//  01/23/2016
//  Adding Large Numbers
//  This program adds large integers (positive or negative)
//  that would normally be out of range.
//
//*****************************************************
#include <limits>
#include <iostream>
#include "AddLargeNumbers.h"

using namespace std;



int main()
{
    int option;

    cout << "*** Adding Large Numbers ***"<< endl << endl;
    do
    {
        cout << "Select an option:" << endl
             << "  1) Add two numbers" << endl
             << "  2) Add a list of numbers " << endl
             << "  3) Exit" << endl;
        cin >> option;

        if (!cin){
            cin.clear();
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << endl;

        switch (option)
        {
        case 1:
            iterativeLoop();
            break;
        case 2:
            recursiveLoop();
            break;
        case 3:
            cout << "Exiting." << endl;
            break;
        default:
            cout << "Invalid option entered" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    } while (option != 3);

    return 0;
}

// Adds two numbers together
void iterativeLoop()
{
    // When this code was in the main function these strings would cause
    // The program to crash upon exit, or on the 2nd loop through when
    // trying to set numString2 for a 2nd time.
    string numString1;                          // Strings hold the integers input from the user
    string numString2;

    Addend number1;                             // Addend contains integers and their sign
    Addend number2;
    Addend mySum;                               // Contains the sum of the addends

    number1.num = new int[MAX_SIZE];            // Integer array to store large numbers
    number2.num = new int[MAX_SIZE];
    mySum.num = new int[MAX_SIZE+1];            // Sum size+1 to store the carry digit

    bool overFlow;                              // tracks whether sum overflows

    Operation myOp;                             // tracks what operation (add or subtract) to be performed


        numString1 = getNumberString();                             // get strings from user
        numString2 = getNumberString();

        number1.sign = stringToIntArray(numString1,number1.num);    // turns strings to int arrays
        number2.sign = stringToIntArray(numString2,number2.num);    // and sets the sign of the integer via return value

        myOp = getOperation(number1,number2,mySum.sign);            // gets the operation to be performed
                                                                    // and returns the sign of their sum
        if(myOp == add)
        {
            addNumbers(number1.num, number2.num, mySum.num);        // calculate the sum via adding
        }
        else if(myOp == subtract)
        {
            subNumbers(number1.num, number2.num, mySum.num);        // calculate the sum via subtracting
        }
        overFlow = isOverflow(mySum.num);                           // Check if sum overflowed
        displaySum(mySum.num,overFlow, mySum.sign);                 // Displays sum to screen

}

// Prompts user for number string
// PRE: Calling function ready to store string
// POST: Returns valid string depending on MAX_SIZE
string getNumberString()
{
    string numString;
    bool isValid;
    do{
        cout<<"Please enter a number (positive or negative), with no more than "<<MAX_SIZE<<" digits: "<<endl;
        cin>>numString;
        isValid = isNumStringValid(numString);
    }while(!isValid);
    return numString;
}

bool isNumStringValid(string numString)
{
    int isValid = 0;
    // made myMax unsigned to simply get rid of the warnings
    unsigned int myMax = MAX_SIZE;
    char firstChar = numString[0];

    if(firstChar == '-')
        myMax++;


    if(numString.length() > myMax)
    {
        isValid = 1;
    }
    else{
        if(firstChar != '-')
            if(firstChar < '0' || firstChar > '9')
                isValid = 2;
        if(isValid == 0)
        {
            // made i unsigned to simply get rid of the warnings
            for(unsigned int i = 1; i < numString.length(); i++)
            {
                if(numString[i] < '0' || numString[i] > '9')
                {
                    isValid = 2;
                    break;
                }
            }
        }
    }
    if(isValid != 0)
    {
        printInvalid(isValid);
        return false;
    }
    return true;
}

void printInvalid(int errCode)
{
    switch(errCode)
    {
        case 1:
            cout<<"You entered too many characters."<<endl;
            break;
        case 2:
            cout<<"Unrecognized character in number."<<endl;
            break;
        default:
            cout<<"Unknown error."<<endl;
    }
    cout<<"Please try again."<<endl;
}

Sign stringToIntArray(string numString, int num[])
{
    Sign sign = positive;
    int j;
    if(numString[0] == '-')
    {
        sign = negative;
        numString[0] = '0';
    }

    for(int i = 0; i < MAX_SIZE; i++)
    {
        j = numString.length() - (1+i);
        if(j >= 0)
            num[i] = numString[j] - '0';
        else
            num[i] = 0;
    }
    return sign;
}

void addNumbers(int num1[], int num2[], int sum[])
{
    int carryDig = 0;
    int sumDig;

    for(int i = 0; i < MAX_SIZE; i++)
    {
        sumDig = num1[i] + num2[i] + carryDig;

        carryDig = sumDig / 10;

        sumDig = sumDig % 10;

        sum[i] = sumDig;


    }
    sum[MAX_SIZE+1] = carryDig;

}

bool isOverflow(int carry[])
{
    return carry[MAX_SIZE+1];
}

void displaySum(int num[], bool overFlow, Sign sign)
{
    int mostSigDig = 0;
    cout<<endl;
    cout<<"The sum is: ";
    if(sign == negative)
        cout<<'-';
    for(int i = MAX_SIZE-1; i >= 0; i--)
    {
        mostSigDig = mostSigDig + num[i];
        if(mostSigDig)
        {
            cout<<num[i];
            if(i%3==0 && i > 0)
                cout<<',';
        }
    }
    if(mostSigDig == 0)
        cout<<'0';
    cout<<endl;
    if(overFlow)
        cout<<"The sum of the numbers is out of range!!"<<endl;
    cout<<endl;
}

bool toContinue()
{
    char choice;
    cout<<endl<<"Would you like to continue (y or n)? ";
    cin>>choice;
    cin.ignore(100,'\n');
    choice = toupper(choice);
    if(choice == 'Y')
        return true;
    return false;
}

void recursiveLoop()
{
    int numAddends;
    Addend* addendsArray;
    Addend sum;

    sum.num = new int[MAX_SIZE+1];
    sum.sign = positive;
    int counter = 0;
    int carry = 0;

    numAddends = howManyAddends();

    addendsArray = new Addend[numAddends];
    getAddends(numAddends, addendsArray);
    initSum(sum);
    if(sum.sign == positive)
        cout<<"initial sum sign is positive"<<endl;
    if(sum.sign == negative)
        cout<<"initial sum sign is negative"<<endl;
    recursiveAdd(addendsArray, sum, numAddends,carry, counter);

    delete addendsArray;
    delete sum.num;

}

int howManyAddends()
{
    int addends;
    cout<<"How many numbers would you like to add together? ";
    cin>>addends;
    if(addends < 2)
        addends = 2;
    else if(addends > MAX_ADDENDS)
        addends = MAX_ADDENDS;
    return addends;
}

void getAddends(int numAddends, Addend addends[])
{
    string numString;
    for(int i = 0; i < numAddends; i++)
    {
        addends[i].num = new int[MAX_SIZE];
        numString = getNumberString();
        addends[i].sign = stringToIntArray(numString,addends[i].num);
    }
}


void recursiveAdd(Addend* addendsArray, Addend sum, int numAddends, int& carry, int& counter)
{

    bool overflow = false;
    Operation myOp;

    if(carry != 0 || counter == numAddends)
    {
        overflow = isOverflow(sum.num);
        displaySum(sum.num,overflow, sum.sign);
        return;
    }
    else
    {
        myOp = getOperation(addendsArray[counter] ,sum ,sum.sign);

        if(myOp == add)
        {
            addNumbers(addendsArray[counter].num ,sum.num ,sum.num);
        }
        else if(myOp == subtract)
        {
            subNumbers(addendsArray[counter].num ,sum.num ,sum.num);
        }
        counter++;
        carry = sum.num[MAX_SIZE+1];
        recursiveAdd(addendsArray, sum, numAddends, carry, counter);
    }
}

void initSum(Addend sum)
{
    sum.sign = positive;
    for(int i = 0; i < MAX_SIZE+1; i++)
        sum.num[i] = 0;
}


Operation getOperation(Addend num1,Addend num2,Sign& sumSign)
{
    int numNegatives = 0;
    Operation myOp;

    if(num1.sign == negative)
        numNegatives++;
    if(num2.sign == negative)
        numNegatives++;

    if(numNegatives == 0)
    {
        myOp = add;
        sumSign = positive;
    }
    else if(numNegatives == 2)
    {
        myOp = add;
        sumSign = negative;
    }
    else{
        myOp = subtract;
        if(isGreater(num1.num,num2.num))
        {
            if( num1.sign == positive)
                sumSign = positive;
            else
                sumSign = negative;
        }
        else if(num2.sign == positive)
            sumSign = positive;
        else
            sumSign = negative;
    }
    return myOp;
}

void subNumbers(int num1[], int num2[], int diff[])
{
    if(isGreater(num1,num2))
        complementIntArray(num2, num1);
    else
        complementIntArray(num1, num2);

    addNumbers(num1,num2,diff);
    dropMostSigDig(diff);
}

bool isGreater( int num1[], int num2[])
{
    int mostSigDig1 = 0;
    int mostSigDig2 = 0;

    bool bigger = false;
    bool found = false;

    int i = MAX_SIZE-1;
    while(!found && i >= 0)
    {
        mostSigDig1 =  num1[i];
        mostSigDig2 =  num2[i];

        if(mostSigDig1 != mostSigDig2)
        {
            if(mostSigDig1 > mostSigDig2)
                bigger = true;
            else
                bigger = false;
            found = true;
        }
        i--;
    }
    return bigger;
}

void complementIntArray(int num1[], int num2[])
{
    int mostSigDig = 0;

    for(int i = MAX_SIZE-1; i > 0; i--)
    {
        mostSigDig = mostSigDig + num2[i];
        if(mostSigDig)
            num1[i]= 9 - num1[i];
    }
    num1[0] = 10 - num1[0];
}

void dropMostSigDig(int num[])
{
    int mostSigDig = 0;

    int i = MAX_SIZE-1;
    while(!mostSigDig && i >= 0)
    {
        mostSigDig = mostSigDig + num[i];
        if(mostSigDig)
        {
            num[i]= 0;
        }
        i--;
    }
}
