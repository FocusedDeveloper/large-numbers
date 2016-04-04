
#include "LargeNum.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "invalidValue.h"

using namespace::std;

//Overload the stream insertion operator <<
ostream& operator<< (ostream& outObj, const LargeNum& myNum)
{
	outObj << myNum.toString();
	return outObj;
}
//Overload the stream extraction operator >>
istream& operator>> (istream& inObj, LargeNum& myNum)
{
	string myNumberString;
	inObj >> myNumberString;
	myNum.updateNumber(myNumberString);
	return inObj;
}

//Overload the arithmetic operators
// POST: integer converted to LargeNum, operation performed, print and return answer
LargeNum operator+ (int& myInt, const LargeNum& myNum)
{
	std::stringstream ss;
	string myString;

	ss << myInt;
	ss >> myString;

	LargeNum num2(myString);
	LargeNum answer;
	answer = num2 + myNum;

	return answer;

}
LargeNum operator-(int& myInt, const LargeNum& myNum)
{
	std::stringstream ss;
	string myString;

	ss << myInt;
	ss >> myString;

	LargeNum num2(myString);
	LargeNum answer;
	answer = num2 - myNum;
	return answer;
}
LargeNum operator*(int& myInt, const LargeNum& myNum)
{
	std::stringstream ss;
	string myString;

	ss << myInt;
	ss >> myString;

	LargeNum num2(myString);
	LargeNum answer;
	answer = num2*myNum;
	return answer;
}
LargeNum operator/(int& myInt, const LargeNum& myNum)
{
	std::stringstream ss;
	string myString;

	ss << myInt;
	ss >> myString;

	LargeNum num2(myString);
	LargeNum answer;
	answer = num2 / myNum;
	return answer;
}
LargeNum operator%(int& myInt, const LargeNum& myNum)
{
	std::stringstream ss;
	string myString;

	ss << myInt;
	ss >> myString;

	LargeNum num2(myString);
	LargeNum answer;
	answer = num2%myNum;
	return answer;
}

//Overload the arithmetic operators
// POST: integer converted to LargeNum, operation performed, print and return answer
LargeNum LargeNum::operator+(int& myInt)
{
	std::stringstream ss;
	string myString;

	ss << myInt;
	ss >> myString;

	LargeNum num2(myString);
	LargeNum answer;
	answer = *this + num2;
	return answer;
}
LargeNum LargeNum::operator-(int& myInt)
{
	std::stringstream ss;
	string myString;

	ss << myInt;
	ss >> myString;

	LargeNum num2(myString);
	LargeNum answer;
	answer = *this - num2;
	return answer;
}
LargeNum LargeNum::operator*(int& myInt)
{
	std::stringstream ss;
	string myString;

	ss << myInt;
	ss >> myString;

	LargeNum num2(myString);
	LargeNum answer;
	answer = *this * num2;
	return answer;
}
LargeNum LargeNum::operator/(int& myInt)
{
	std::stringstream ss;
	string myString;

	ss << myInt;
	ss >> myString;

	LargeNum num2(myString);
	LargeNum answer;
	answer = *this / num2;
	return answer;
}
LargeNum LargeNum::operator%(int& myInt)
{
	std::stringstream ss;
	string myString;

	ss << myInt;
	ss >> myString;

	LargeNum num2(myString);
	LargeNum answer;
	answer = *this % num2;
	return answer;
}

// reassign number value of obj based on integer string
// PRE: string must be valid integer
// POST: obj stores new number
void LargeNum::updateNumber(string myNumberString)
{
	if (isNumStringValid(myNumberString))    // if string is valid
	{
		numString = myNumberString;         // reassign the object value
		stringToIntArray();
	}
}

// Default Constructor, coverts string to object
LargeNum::LargeNum(string myNumString)
{
	if (isNumStringValid(myNumString))
		numString = myNumString;
	else
		numString = "0";
	stringToIntArray();
}

// creates a LargeNum from integer array, with size and sign
LargeNum::LargeNum(const int* myNum, int mySize, Sign mySign)
{
	//cout<<"In custom constructor"<<endl;
	num = new int[mySize];

	for (int i = 0; i < mySize; i++)
	{
		num[i] = myNum[i];
	}
	sign = mySign;
	arraySize = mySize;
	numString = toString();
}

// copy constructor, makes a deep copy of given object
LargeNum::LargeNum(const LargeNum& orgNum)
{
	//    cout<<"In copy constuctor"<<endl;
	//    cout<<"Will be: ";
	//    orgNum.print();
	//    cout<<endl;
	// if num does not equal null

	// if there is data in the int array of the object passed in
	if (orgNum.num)
	{
		sign = orgNum.sign;                 // copy the data directly into this object

		arraySize = orgNum.arraySize;
		num = new int[arraySize];

		for (int i = 0; i < arraySize; i++)
		{
			num[i] = orgNum.num[i];
		}

	}
	else {                                // else, create an object based on the same number string that created the original object

		numString = orgNum.numString;
		stringToIntArray();
	}
}

// overload the assignment operator
const LargeNum& LargeNum::operator=(const LargeNum& orgNum)
{
	// if this is the same object passed, return this object
	if (this == &orgNum)
		return *this;

	//if (num){
		delete[] num;       // delete whatever dynamic memory the current object is holding
		num = NULL;
	//}

	if (orgNum.num!=NULL)                          // copy the data from int array directly into this object
	{
		sign = orgNum.sign;
		arraySize = orgNum.arraySize;
		num = new int[arraySize];

		for (int i = 0; i < arraySize; i++)
			num[i] = orgNum.num[i];
	}
	else {

		numString = orgNum.numString;       // or use the string the original is based on
		stringToIntArray();
	}
	return *this;
}

// destructor
LargeNum::~LargeNum()
{
	delete[] num;                       // free's up dynamic memory
}

// converts numString into integer array
// PRE: numString is set and valid
// POST: numString, arraySize, and sign are all set
void LargeNum::stringToIntArray()
{
	Sign mySign = positive;                   // initialize the sign to positive
	string newString;
	int j;
	*this;
	this->numString;

	if (numString[0] == '-')                 // if the first character is a negative sign...
	{
		mySign = negative;                    // set the sign to negative
		numString[0] = '0';                 // and change the character to a zero
		newString = numString.substr(1, numString.length() - 1);

	}
	else
		newString = numString;

	arraySize = newString.length();             // Set the size = to the length of the number string
	num = new int[arraySize];               // Dynamically allocate space for the array

	for (int i = 0; i < arraySize; i++)       // for the entire array...
	{
		j = arraySize - (1 + i);     // start at the back of the array, store the number backwards
		if (j >= 0)                          // If the number string is still in index...
			num[i] = newString[j] - '0';    // translate the the character of the string to the corresponding int
		else
			num[i] = 0;                     // Else, place a zero in the array
	}
	sign = mySign;
}

// Checks if the number string is valid
// PRE: numString has been set
// POST: returns true if the string contains an integer within the limit MAX_SIZE
bool LargeNum::isNumStringValid(string myNumString) const
{
	int isValid = 0;                    // if not zero, string is invalid

	char firstChar = myNumString[0];

	if (firstChar != '-')                                        // is the first character is valid...
		if (firstChar < '0' || firstChar > '9')
			isValid = 2;                                        // if not set error code to 2
	if (isValid == 0)
	{
		// made i unsigned to simply get rid of the warnings
		for (unsigned int i = 1; i < myNumString.length(); i++)    // from the 2nd character to the last..
		{
			if (myNumString[i] < '0' || myNumString[i] > '9')        // are they all valid...
			{
				isValid = 2;                                    // if not, set the error code
				break;                                          // if not valid, no need to check any further
			}
		}
	}
	if (isValid != 0)                                                // if not valid...
	{
		printInvalid(isValid);                                      // print the error message
		return false;                                               // and return false
	}
	return true;                                                    // else, return true
}

// prints error message for invalid strings
// PRE: get error code from isNumStringValid
// POST: Error code displayed
void LargeNum::printInvalid(int errCode) const
{
	switch (errCode)
	{
	case 1:
		cout << "You entered too many characters." << endl;     // in this version of LargeNum, this should never be reached
		break;
	case 2:
		cout << "Unrecognized character in number." << endl;
		break;
	default:
		cout << "Unknown error." << endl;
	}
	cout << "Setting number equal to zero." << endl << endl;
}

// returns object as a string for easy output
string LargeNum::toString() const
{
	std::stringstream ss;
	string myString;

	int mostSigDig = 0;                     // tracks the most significant digit
	//    cout<<endl;                             // once found, it will no longer be zero
	//    cout<<"The number is: ";
	if (sign == negative)                    // if the sign is negative...
		ss << '-';                          // print a negative sign
	for (int i = arraySize - 1; i >= 0; i--)    // start at the back of the array...
	{
		mostSigDig = mostSigDig + num[i];   // adds the current number to the MSD
		if (mostSigDig)                      // If the MSD has been found...
		{
			ss << num[i];                   // print the number
			if (i % 3 == 0 && i > 0)             // places a comma every 3 spaces
				ss << ',';
		}
	}
	if (mostSigDig == 0)                     // If no MSD was ever found...
		ss << '0';                          // print a zero

	ss >> myString;
	return myString;

}

// Prints obj to display device
void LargeNum::print() const
{

	int mostSigDig = 0;                     // tracks the most significant digit
	//    cout<<endl;                             // once found, it will no longer be zero
	//    cout<<"The number is: ";
	if (sign == negative)                    // if the sign is negative...
		cout << '-';                          // print a negative sign
	for (int i = arraySize - 1; i >= 0; i--)    // start at the back of the array...
	{
		mostSigDig = mostSigDig + num[i];   // adds the current number to the MSD
		if (mostSigDig)                      // If the MSD has been found...
		{
			cout << num[i];                   // print the number
			if (i % 3 == 0 && i > 0)             // places a comma every 3 spaces
				cout << ',';
		}
	}
	if (mostSigDig == 0)                     // If no MSD was ever found...
		cout << '0';                          // print a zero
}

// checks if this object is greater than the parameter
// POST: returns true if this object is greater
bool LargeNum::isGreater(const LargeNum& num2) const
{
	int mostSigDig1 = 0;
	int mostSigDig2 = 0;

	bool bigger = true;             // setting this variable to true will return true for greater or equal
	// false results in greater than comparison
	bool found = false;

	int largestSize;

	largestSize = ((arraySize >= num2.arraySize) ? arraySize : num2.arraySize);      // find which array has the largest size
	// which should mean, this array is the larger value.
	// but i'm checking in case an array is full with zeros

	int i = largestSize - 1;
	while (!found && i >= 0)                     // while contrasting MSDs has not been found
	{                                               // and we are still in index...
		if (i > arraySize - 1)        // if the array is out of index...
		{
			mostSigDig1 = 0;            // use a zero
		}
		else{
			mostSigDig1 = num[i];
		}

		if (i > num2.arraySize - 1)   // if the array is out of index...
		{
			mostSigDig2 = 0;            // use a zero
		}
		else{
			mostSigDig2 = num2.num[i];
		}

		if (mostSigDig1 != mostSigDig2)          // Looking for the 1st MSD that differs amongst the two numbers
		{
			if (mostSigDig1 > mostSigDig2)       // Once found, if 1 is greater than 2 then, 1 is greater
				bigger = true;
			else
				bigger = false;
			found = true;                       // We have found contrasting MSDs, set flag to break loop
		}
		i--;                                    // Decrement i because we're starting at the back of the int array
	}
	return bigger;

}

// functions to perform arithmetic on objects
//   PRE: This object and parameter have their integer arrays set
//   POST: all functions print answer, and return the value as a largeNum
LargeNum LargeNum::addNum(const LargeNum& num2)
{
	LargeNum sum;
	sum = performMath(num2, add);
	cout << "The sum of " << *this << " + " << endl << num2 << " is: " << endl << sum << endl;
	return sum;
}

LargeNum LargeNum::subtractNum(const LargeNum& num2)
{
	LargeNum diff;
	diff = performMath(num2, subtract);
	cout << "The difference of " << *this << " - " << endl << num2 << " is: " << endl << diff << endl;
	return diff;
}

LargeNum LargeNum::muliplyNum(const LargeNum& num2)
{
	LargeNum product;
	product = performMath(num2, multiply);
	cout << "The product of " << *this << " * " << num2 << " is: " << product << endl;
	return product;
}

LargeNum LargeNum::divideNum(const LargeNum& num2)
{
	LargeNum quotient;
	quotient = performMath(num2, divide);
	cout << "The quotient of " << *this << " / " << num2 << " is: " << quotient << endl;
	return quotient;
}

LargeNum LargeNum::modNum(const LargeNum& num2)
{
	LargeNum remainder;
	remainder = performMath(num2, mod);
	cout << *this << " % " << num2 << " is: " << remainder << endl;
	return remainder;
}

// Overload arithmetic operators
LargeNum LargeNum::operator+(const LargeNum& num2)
{
	return addNum(num2);
}
LargeNum LargeNum::operator-(const LargeNum& num2)
{
	return subtractNum(num2);
}
LargeNum LargeNum::operator*(const LargeNum& num2)
{
	return muliplyNum(num2);
}
LargeNum LargeNum::operator/(const LargeNum& num2)
{
	return divideNum(num2);
}
LargeNum LargeNum::operator%(const LargeNum& num2)
{
	return modNum(num2);
}

// This// Given 2nd object and operation, calculates answer
// PRE: 2nd object is valid, Answer has been initialized
// POST: third parameter contains answer of operation with the 2nd object
LargeNum LargeNum::performMath(const LargeNum& num2, Operation myOp)
{
	Sign newSign;
	int newSize;
	int numNegatives = 0;
	bool num1Greater;

	int* intArray1;
	int* intArray2;
	int* intArray3;

	int size1;
	int size2;
	Sign sign1;

	int size3;
	Sign sign3;
	LargeNum remainder;

	num1Greater = isGreater(num2);      // which number is lager

	// decide which number has the greater absolute value and set a 2nd array, intArray1 to point to it.
	if (num1Greater)                     // if this number is larger...
	{
		//cout << "Number 1 has a greater ABS than Number 2" << endl;
		intArray1 = new int[arraySize];
		//initArray(intArray1, arraySize);
		for (int i = 0; i < arraySize; i++)
			intArray1[i] = num[i];
		// intArray1 = num;                // array1 = this number
		size1 = arraySize;
		sign1 = sign;

		//intArray2 = num2.num;           // array2 = the other
		intArray2 = new int[num2.arraySize];
		//initArray(intArray2, num2.arraySize);
		for (int i = 0; i < num2.arraySize; i++)
			intArray2[i] = num2.num[i];
		size2 = num2.arraySize;
	}
	else{                              // if array1 is not greater
		//cout << "Number 2 has a greater ABS than Number 1" << endl;
		//intArray2 = num;                // array2 = this number
		intArray2 = new int[arraySize];
		//initArray(intArray2, arraySize);
		for (int i = 0; i < arraySize; i++)
			intArray2[i] = num[i];
		size2 = arraySize;


		//intArray1 = num2.num;           // array1 = the other
		intArray1 = new int[num2.arraySize];
		//initArray(intArray1, num2.arraySize);
		for (int i = 0; i < num2.arraySize; i++)
			intArray1[i] = num2.num[i];
		size1 = num2.arraySize;
		sign1 = num2.sign;
	}

	if (sign == negative)                   // increase the number of negatives if one is found
		numNegatives++;
	if (num2.sign == negative)
		numNegatives++;

	// determine the sign and size of the answer
	newSign = determineSign(num2, myOp, numNegatives, num1Greater);
	newSize = determineSize(myOp, num2.arraySize);

	// initialize the answer with the new sign, size, and init num array by filling it with zeros
	sign3 = newSign;
	size3 = newSize + 1;
	//        if(answer.num)
	//            delete[] answer.num;
	intArray3 = new int[size3];
	initArray(intArray3, size3);
	try
	{

	}
	catch (bad_alloc myBad)
	{
		cout << "Cannot allocate memory for answer. what(): " << myBad.what() << endl;
	}
	catch (exception e)
	{
		cout << "Something went wrong with num. what(): " << e.what() << endl;
	}
	catch (...)
	{
		cout << "Error thrown! " << endl;
	}

	//cout<<"Answer Size: "<<answer.arraySize<<endl<<answer.num[answer.arraySize-1]<<endl;

	// Perform function based on given operation
	switch (myOp)
	{
		case add:
			if (numNegatives != 1)       // the number of negatives is divisible by 2, add the numbers
			{
				addition(intArray1, size1, intArray2, size2, intArray3, newSize);
			}
			else{                          // If the number of negatives is not divisible by 2, subtract the numbers
				subtraction(intArray1, size1, sign1, intArray2, size2, intArray3, newSize);
			}
			break;
		case subtract:
			if (numNegatives == 1)       // If there is one negative and one positive sign, the operation is determined by the order of the operands
			{
				addition(intArray1, size1, intArray2, size2, intArray3, newSize);

			}
			else{
				subtraction(intArray1, size1, sign1, intArray2, size2, intArray3, newSize);
			}
			break;
		case multiply:
			multiplication(intArray1, size1, intArray2, size2, intArray3, newSize);
			break;
		case divide:
			division(num, arraySize, sign, num2.num, num2.arraySize, intArray3, newSize);
			break;
		case mod:
			remainder = division(num, arraySize, sign, num2.num, num2.arraySize, intArray3, newSize);
			break;
		default:
			cout << "Error in performMath()" << endl;
			break;
	}

	LargeNum answer(intArray3, size3, sign3);

	if (myOp == mod)
		answer = remainder;

	answer.reSizeArray();   // resize the answer array to get rid of any wasted space

	delete[] intArray1;
	delete[] intArray2;
	delete[] intArray3;
	return answer;

}

// Initialize myNum to all zeros
// PRE: myNum has been declared
// POST: myNum has been set to zero
void LargeNum::initArray(int* myNum, int mySize) const
{

	int x = 0;
	for (int i = 0; i < mySize; i++)
	{
		myNum[i] = x;
	}
	//cout << "exit init" << endl;
}

// determines the sign of the answer operation given the two objects
// PRE: Sign must be set for this object and parameter
// POST: appropriate sign returned for the answer of the operation
LargeNum::Sign LargeNum::determineSign(const LargeNum& num2, Operation myOp, int numNegatives, bool num1Greater) const
{
	Sign mySign;


	if (numNegatives == 0 || myOp == mod)                       // If there are no negatives... OR if the operation is mod
	{
		if (myOp != subtract)
			mySign = positive;                     // and the answer must be positive
		else if (num1Greater)
			mySign = positive;
		else
			mySign = negative;
	}
	else if (numNegatives == 2)                  // If both numbers are negative...
	{
		if (myOp == add){
			mySign = negative;
		}
		else if (myOp == multiply || myOp == divide){
			mySign = positive;
		}
		else{                                  // myOp = subtraction with 2 negatives
			if (num1Greater)
				mySign = negative;
			else
				mySign = positive;
		}
	}
	else{                                           // One negative and one positive number...
		if (myOp == multiply || myOp == divide)              // if multiply or divide...
		{
			mySign = negative;                              // sign is negative
		}
		else if (myOp == subtract){                  // Subtraction with one negative and one positive will result in the difference sign
			mySign = sign;                                      // being the same as number 1  for ex: (1) - (-1) = 2  ex2: (-1) - (2) = -3
		}
		else{                                      // Operation is add with one negative and one positive
			if (num1Greater)                         // if number 1 is greater
			{
				mySign = sign;                          // the sum sign will equal the sign of number1
			}
			else{
				mySign = num2.sign;
			}
		}
	}

	return mySign;
}

//determines the maximum size needed for the answer of the operation
// PRE: 2nd param contains the size of the larger of the two int arrays
// POST: size of answer array is returned
int LargeNum::determineSize(Operation myOp, int size2) const
{
	int largerSize;
	int mySize;
	largerSize = ((arraySize > size2) ? arraySize : size2);

	switch (myOp)
	{
	case(add) :
	case(subtract) :
	case(divide) :
	case(mod) :
			  mySize = largerSize + 1;
		break;
	case(multiply) :
		mySize = largerSize * 2;
		break;
	default:
		cout << "Error determining size of answer." << endl;
	}

	return mySize;
}

// Adds the two integers arrays
// PRE: int1 and int2 are the integers to be added
// and they have been set.  sum[] has been declared
// POST: sum[] contains the sum of the integers, with the carry bit
void LargeNum::addition(const int num1[], const int size1, const int num2[], const int size2, int sum[], const int size3) const
{
	//cout << "In addition" << endl;
	int carryDig = 0;                               // initialize carry digit to zero
	int sumDig;
	int totalSum;
	int x;
	int y;

	try
	{
		for (int i = 0; i < size1; i++)               // For the entire array...
		{
			if (i >= size1){         // if i is greater than the size of the array... should never reach this point
				x = 0;
			}
			else
			{
				x = num1[i];        // x is equal to the digit at i index of array1
			}

			if (i >= size2){         // if i is greater than the size of the array.  Will reach this condition of size1 is greater than size2
				y = 0;
			}
			else
			{
				y = num2[i];        // y is equal to the digit at i index of array2
			}
			totalSum = x + y + carryDig;      // combine the 2 integers with the carry to get the sum
			if (totalSum > 9)
			{
				sumDig = totalSum - 10;
				carryDig = totalSum - (9 + sumDig);
			}
			else{
				sumDig = totalSum;
				carryDig = 0;
				if (sumDig< 0 || sumDig >= 10)                   // this statement should always evaluate to true, could use assertion...
					cout << "ERROR with SumDig in ADDITION" << endl;
			}

			sum[i] = sumDig;
			//cout << sumDig << ", ";
		}


		if (carryDig >= 0 && carryDig<10){          // this statement should always evaluate to true, could use assertion...
			if (size1 < size3)						// the sum array must be bigger than the addends in order to set the carry bit
				sum[size1] = carryDig;
			//cout << "Sum[size1] = " << sum[size1] << endl;
			//cout << "size1: " << size1 << endl;
		}
		else
			cout << "ERROR IN ADDITION!" << endl;
	}
	catch (out_of_range oorObj)
	{
		cout << "Out of range addition: " << oorObj.what() << endl;
	}
	catch (invalidValue invalidObj)
	{
		cout << invalidObj.what() << endl;
	}
	catch (...)
	{
		cout << "Error.  Something wrong in addition!" << endl;
	}
}

// Subtracts the smaller number from the larger
// PRE: num1 is the larger of the two numbers
// POST: diff contains the difference of the two numbers
void LargeNum::subtraction(const int num1[], const int size1, Sign sign1, int num2[], const int size2, int diff[], const int size3) const
{
	//cout << "In subtraction" << endl;
	int* arrayBuffer;
	int x;
	arrayBuffer = new int[size1];
	for (int i = 0; i< size1; i++)
	{
		if (size2 <= i)
			x = 0;
		else{
			x = num2[i];
		}
		arrayBuffer[i] = x;
	}

	complementIntArray(arrayBuffer, size1, num1, size1, sign1);     // complement num2 with num1
	addition(num1, size1, arrayBuffer, size1, diff, size3);             // Add the two numbers
	dropMostSigDig(diff, size3);                   // and drop the most significant digit

	delete[] arrayBuffer;
}

// multiplies two int arrays
// PRE: larger int stored in the first array
// all arrays are set and size is correct
// POST: product[] contains the product of the two arrays
void LargeNum::multiplication(const int num1[], const int size1, const int num2[], const int size2, int product[], const int size3) const
{
	int factor;
	int* tempSum;

	try{
		tempSum = new int[size3];                   // create a temp array for summing

		for (int i = 0; i < size2; i++)            // for each number in the 2nd array...
		{
			factor = num2[i];                      // get the factor for the current digit

			initArray(tempSum, size3);               // initialize the temp sum to zeros

			for (int j = 0; j < factor; j++)
			{
				addition(tempSum, size3-1, num1, size1, tempSum, size3); // add num1 to temp sum factor amount of times
			}
			if (i > 0)       // if this is not the first digit in the 2nd array we're working with...
			{
				for (int k = size3 - 1; k >= i; k--)    // shift the temp sum digits over i number of spaces
					tempSum[k] = tempSum[k - i];
				for (int l = 0; l < i; l++)          // fill the spaces with zeros
					tempSum[l] = 0;
			}
			addition(product, size3, tempSum, size3, product, size3);      // combine the temp sum with the product
		}
		delete[] tempSum;
		tempSum = NULL;
	}
	catch (out_of_range oorObj)
	{
		cout << "Out of range: " << oorObj.what() << endl;
	}
	catch (bad_alloc badAlObj)
	{
		cout << "Bad Alloc: " << badAlObj.what() << endl;
	}
	catch (exception myExcept)
	{
		cout << "EXCEPTION in multiplication! what(): " << myExcept.what() << endl;
	}
	catch (...)
	{
		cout << "I caught something!" << endl;
	}

}

// divides the first int array by the 2nd int array
// PRE: all arrays defined and set with appropriate sizes
// POST: quotient contains the answer of integer division
// the remainder gets returned as a LargeNum and can be used for modulus
const LargeNum LargeNum::division(const int num1[], const int size1, Sign sign1, int num2[], const int size2, int quotient[], const int size3) const
// TBD make division more efficient by spitting the quotient and testing with multiplication
// right now x/1 will take x number of calculations...
{
	int divCounter = 0;
	int* divCounterPtr = &divCounter;
	int* diff = new int[size1+1];

	initArray(diff, size1+1);

	// create temp LargeNums for division manipulation to maintain the original operands
	LargeNum tempNum(num1, size1, positive);
	LargeNum tempNum2(num2, size2, positive);


	while (tempNum.isGreater(tempNum2))
	{
		divCounter++;

		subtraction(tempNum.num, size1, sign1, tempNum2.num, tempNum2.arraySize, diff, size3);    // subtract temp2 from temp1 and store the answer in diff

		for (int i = 0; i < size1; i++)          // set temp1 equal to diff
		{
			tempNum.num[i] = diff[i];
		}

		if (divCounter == 9){                    // if the counter reaches 9...
			addition(quotient, size3-1, divCounterPtr, 1, quotient, size3);    // add the counter to the current quotient
			divCounter = 0;                                                     // and reset the counter
			//cout << "Post Shifting" << endl;
		}
	}
	addition(quotient, size3-1, divCounterPtr, 1, quotient, size3);            // add the counter to the quotient
	delete[] diff;
	return tempNum;                                                     // return the remainder

}



// Convert num1 so we can subtract by adding
// PRE: both numbers are defined.  Num1 is to be subtracted
// from num2
// POST: num1 has be complemented
void LargeNum::complementIntArray(int num1[], int size1, const int num2[], const int mySize, Sign sign2) const
{
	int mostSigDig = 0;
	int x;
	try
	{
		for (int i = (mySize - 1); i > 0; i--)             // for the size of the int arrays...
		{
			mostSigDig = mostSigDig + num2[i];          // Find index the MSD of the larger number

			if (mostSigDig){                              // Once we have located the MSG of num2
				x = num1[i];
				num1[i] = 9 - x;                      // convert each digit by subtracting it from 9 until we get to the first digit
			}
		}
		num1[0] = 10 - num1[0];                            // the first digit of the number is subtracted from 10.

	}
	catch (out_of_range& oorObj)
	{
		cout << "Out of range compAry: " << oorObj.what() << endl;
	}



}
// Drops the MSG of the int passed
// PRE: int array num contains an int stored backwards in the array
// POST: MSD has been dropped from num
void LargeNum::dropMostSigDig(int num[], int size1) const
{
	int mostSigDig = 0;

	int i = size1 - 1;                    // start from the back of the array
	try
	{
		while (!mostSigDig && i >= 0)           // until the MSD is found, or out of index...
		{
			mostSigDig = mostSigDig + num[i];       // find the MSD...
			if (mostSigDig)                          // once found...
			{
				num[i] = 0;                          // set MSD equal to zero
			}
			i--;
		}
	}
	catch (out_of_range& oorObj)
	{
		cout << "Out of range dropMSD: " << oorObj.what() << endl;
	}

}

void LargeNum::reSizeArray()
{
	//    if the msd is a zero
	//    count the number of zero's until a non zero digit is found.
	//    subtract that number from the array size
	//    create a temp int array of newSize
	//    copy the original array into the the newArray
	//    delete orignal array
	//    declare orig array of size newSize
	//    copy new array into orig
	//    delete the tempArray
	int mostSigDig = 0;
	int j = 1;

	int* tempArray;
	int myArraysize = arraySize;
	int i = arraySize - 1;                    // start from the back of the array
	while (!mostSigDig && i >= 0)           // until the MSD is found, or out of index...
	{
		mostSigDig = mostSigDig + num[i];       // find the MSD...
		if (mostSigDig)                          // once found...
		{
			j = i + 1;                         // set MSD equal to zero
		}
		i--;
	}
	if (j != arraySize)
	{
		tempArray = new int[j];

		for (int i = 0; i < j; i++)
		{
			tempArray[i] = num[i];
		}

		delete[] num;
		num = NULL;

		arraySize = j;

		num = new int[arraySize];

		for (int i = 0; i < j; i++)
		{
			num[i] = tempArray[i];
		}
		delete[] tempArray;
	}

}

