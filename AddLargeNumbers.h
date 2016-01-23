#ifndef ADDLARGENUMBERS_H_INCLUDED
#define ADDLARGENUMBERS_H_INCLUDED

const int MAX_SIZE = 20;
const int MAX_ADDENDS = 5;

enum Sign{negative, positive};

enum Operation{add, subtract};

struct Addend
{
    int* num;
    Sign sign;
};

std::string getNumberString();
bool isNumStringValid(std::string);
void printInvalid(int);
Sign stringToIntArray(std::string, int[]);
void addNumbers(int[], int[], int[]);
bool isOverflow(int[]);
void displaySum(int[], bool, Sign);
bool toContinue();
void iterativeLoop();

// functions for recursive adding
void recursiveLoop();
int howManyAddends();
void getAddends(int, Addend[]);
void recursiveAdd(Addend[],Addend,int, int&, int&);
void initSum(Addend);

//functions for subtracting
Operation getOperation(Addend,Addend,Sign&);
void subNumbers(int[], int[], int[]);
bool isGreater( int[], int[]);
void complementIntArray(int[], int[]);
void dropMostSigDig(int[]);

#endif // ADDLARGENUMBERS_H_INCLUDED
