#ifndef LARGENUM_H
#define LARGENUM_H
#include <string>
#include <iostream>

 using std::ostream;
 using std::istream;

using std::string;

class LargeNum
{
    //Overload the stream insertion and extraction operators
    friend ostream& operator << ( ostream&, const LargeNum& );
    friend istream& operator >> ( istream&, LargeNum& );

    // Overload arithmetic operations to function with integers
    friend LargeNum operator+ (int&, const LargeNum&);
    friend LargeNum operator- (int&, const LargeNum&);
    friend LargeNum operator* (int&, const LargeNum&);
    friend LargeNum operator/ (int&, const LargeNum&);
    friend LargeNum operator% (int&, const LargeNum&);

    public:
        // Variable to keep track of sign of the number
        enum Sign{negative, positive};
        // type to track arithmetic operations
        enum Operation{add, subtract, multiply, divide, mod};

        // Constructors
        // Default constructor, creates LargeNum type from a string
        LargeNum(string myNumString = "0");
        // creates a LargeNum from integer array, with size and sign
        LargeNum(const int*, int, Sign);
        // copy constructor, makes a deep copy of given object
        LargeNum(const LargeNum& orgNum);

        // Override  assignment operator, sets this object equal to param
        const LargeNum& operator=(const LargeNum& orgNum);
        // destructor, deletes dynamic memory
        ~LargeNum();

        // returns the sign of the LargeNum
        Sign Getsign() const { return sign; }
        int getSize() const { return arraySize; }

        // reassign number value of obj based on integer string
        // PRE: string must be valid integer
        // POST: obj stores new number
        void updateNumber(string = "0") ;

        // functions to perform arithmetic on objects
        //   all functions print answer, and return the value as a largeNum
        LargeNum addNum(const LargeNum&) ;
        LargeNum subtractNum(const LargeNum&);
        LargeNum muliplyNum(const LargeNum&);
        LargeNum divideNum(const LargeNum&);
        LargeNum modNum(const LargeNum&);

        // Overload arithmetic operations to function with integers
        //   when the int is on the right of the operator
        LargeNum operator+(int& );
        LargeNum operator-(int& );
        LargeNum operator*(int& );
        LargeNum operator/(int& );
        LargeNum operator%(int& );

        // Overload arithmetic operations
        //    all functions print answer, and return the value as a largeNum
        LargeNum operator+(const LargeNum&) ;
        LargeNum operator-(const LargeNum&);
        LargeNum operator*(const LargeNum&);
        LargeNum operator/(const LargeNum&);
        LargeNum operator%(const LargeNum&);

        // Compare this obj to param, return true if greater
        bool isGreater(const LargeNum&) const;

        // Prints obj to display device
        void print() const;
        // returns object as a string for easy output
        string toString() const;


    private:
        int* num;               // integer array to store number
        Sign sign;              // tracks sign of number
        string numString;       // used to set integer array
        int arraySize;          // size of integer array

        // checks if string passed is a valid integer
        // post: return true if valid
        bool isNumStringValid(string numString) const;
        // prints error message for invalid strings
        void printInvalid(int) const;

        // converts numString into integer array
        // PRE: numString is set and valid
        // POST: numString, arraySize, and sign are all set
        void stringToIntArray();

        // Given 2nd object and operation, calculates answer
        // PRE: 2nd object is valid, Answer has been initialized
        // POST: third parameter contains answer of operation with the 2nd object
        LargeNum performMath(const LargeNum&, Operation);

        // determines the sign of the answer operation given the two objects
        // PRE: Sign must be set for this object and parameter
        // POST: appropriate sign returned for the answer of the operation
        Sign determineSign(const LargeNum&, Operation, int, bool) const;

        //determines the size needed for the answer of the operation
        // PRE: 2nd param contains the size of the larger of the two int arrays
        // POST: size of answer array is returned
        int determineSize( Operation, int) const;
        // Initializes array  to all zeros
        // PRE: size is correct
        // POST: int array set to all zeros
        void initArray(int*, int) const;

        // Performs arithmetic on given parameters
        // PRE: first array is the larger of the two, answer has been initialized with the correct size
        // POST: answer int array contains the calculated significant
        void addition(const int*, const int, const int*, const int, int*, const int) const;
        void subtraction(const int*, const int, Sign, int*, const int, int*, const int) const;
        void multiplication(const int*, const int, const int*, const int, int*, const int) const;
            // returns the remainder of the division function
        LargeNum division(const int*, const int, Sign, int*, const int, int*, const int) const;

        // Array manipulation functions
        void complementIntArray(int*,int, const int*,const int, Sign) const;
        // drops the most significant digit from the int array
        // PRE: size must be correct
        // POST: MSD dropped from int array
        void dropMostSigDig(int* , int ) const;
        // resize the array by getting rid of preceding zeros
        // PRE: object initialized
        // POST: preceding zeros have been removed, array size is updated
        void reSizeArray();


};

#endif // LARGENUM_H
