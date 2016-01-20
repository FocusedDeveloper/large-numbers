#include <iostream>
#include "AddLargeNumbers.h"

using namespace std;



int main()
{
    // making these strings static fixes the crash
    // and it crashes upon exit.
    // also crashes on the 2nd pass through when setting the string.
    static string numString1;
    static string numString2;

    Adden number1;
    Adden number2;
    Adden mySum;

    number1.num = new int[MAX_SIZE];
    number2.num = new int[MAX_SIZE];
    mySum.num = new int[MAX_SIZE+1];

    int num1[MAX_SIZE];
    int num2[MAX_SIZE];
    int sum[MAX_SIZE+1];

    bool overFlow;
    bool bigger;

    Operation myOp;

    do{

        // recursive loop now fully functional
        //recursiveLoop();
        numString1 = getNumberString();
        numString2 = getNumberString();

        //stringToIntArray(numString1, num1);
        //stringToIntArray(numString2, num2);
        number1.sign = stringToIntArray(numString1,number1.num);
        number2.sign = stringToIntArray(numString2,number2.num);
        //initSum(mySum.num);

        myOp = getOperation(number1,number2,mySum.sign);

        //displaySum(number1.num,false);

       // displaySum(number2.num,false);
//        bigger = isGreater(number1.num,number2.num);
//        if(bigger)
//            cout<<"First number is greater."<<endl;
//        else
//            cout<<"2nd number is greater."<<endl;

//        if(number1.sign == positive)
//            cout<<"Number1 is positive"<<endl;
//        else
//            cout<<"Number1 is negative"<<endl;
//        if(number2.sign == positive)
//            cout<<"Number2 is positive"<<endl;
//        else
//            cout<<"Number2 is negative"<<endl;


        if(myOp == add)
        {
//            cout<<"about to add numbers"<<endl;
            addNumbers(number1.num, number2.num, mySum.num);
        }
        else if(myOp = subtract)
        {
//            cout<<"OP is subtraction"<<endl;
            subNumbers(number1.num, number2.num, mySum.num);
        }

        //else
            //subNumbers(number1.num, number2.num, mySum.num);

        overFlow = isOverflow(mySum.num);
        displaySum(mySum.num,overFlow, mySum.sign);

        //addNumbers(num1, num2, sum);
        //overFlow = isOverflow(sum);
        //displaySum(sum,overFlow);

    }while(toContinue());

    return 0;
}

string getNumberString()
{
    string numString;
    bool isValid;
    do{
        cout<<"Please enter a positive number with no more than "<<MAX_SIZE<<" digits: "<<endl;
        cin>>numString;
        isValid = isNumStringValid(numString);
    }while(!isValid);
    return numString;
}

bool isNumStringValid(string numString)
{
    int isValid = 0;
    int myMax = MAX_SIZE;
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
            for(int i = 1; i < numString.length(); i++)
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
            cout<<num[i];
    }
    if(mostSigDig == 0)
        cout<<'0';
    cout<<endl;
    if(overFlow)
        cout<<"The sum of the numbers is out of range!!"<<endl<<endl;
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
    int numAddens;
    int** addensArray;
    int sum[MAX_SIZE+1];
    bool overflow;
    int counter = 0;
    int carry = 0;
    Sign sign;

    numAddens = howManyAddens();

    addensArray = new int*[numAddens];
    getAddens(numAddens, addensArray);
    initSum(sum);
    recursiveAdd(addensArray, sum, numAddens,carry, counter);
    overflow = isOverflow(sum);
    displaySum(sum,overflow, sign);

}

int howManyAddens()
{
    int addens;
    cout<<"How many numbers would you like to add together? ";
    cin>>addens;
    if(addens < 2)
        addens = 2;
    else if(addens > MAX_ADDENS)
        addens = MAX_ADDENS;
    return addens;
}

void getAddens(int numAddens, int** addens)
{
    string numString;
    for(int i = 0; i < numAddens; i++)
    {
        addens[i] = new int[MAX_SIZE];
        numString = getNumberString();
        stringToIntArray(numString,addens[i]);
    }
}

// was functional before adding subtraction.
void recursiveAdd(int** addensArray,int sum[], int numAddens, int& carry, int& counter)
{

    bool overflow = false;
    Operation myOp;

    if(carry != 0 || counter == numAddens)
        return;
    else
    {
        //myOp = getOperation(addensArray[counter],sum,sum.sign)
        addNumbers(addensArray[counter],sum,sum);
        counter++;
        overflow = isOverflow(sum);
        carry = sum[MAX_SIZE+1];
        recursiveAdd(addensArray, sum, numAddens, carry, counter);
    }
}

void initSum(int sum[])
{
    for(int i = 0; i < MAX_SIZE+1; i++)
        sum[i] = 0;
}


Operation getOperation(Adden num1,Adden num2,Sign& sumSign)
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
    bool found = false;

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
