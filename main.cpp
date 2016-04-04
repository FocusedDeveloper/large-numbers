//*****************************************************
//  Charles Darnell Johnson
//  03/30/2016
//  Adding Large Numbers
//  This program adds, subtracts, multiplies and divides large integers (positive or negative)
//  Created class LargeNum to store integers of unlimited size
//  Overriding all arithmetic operators
//*****************************************************


#include <iostream>
#include <limits>
#include <string>

#include "LargeNum.h"

using namespace std;

void testPrint(const LargeNum&);       // success
void testToString(const LargeNum&);    // success
void testDefaultConstructor();          // success
LargeNum testStringConstructor();           // success
void testEqualOperator();               // success
LargeNum testArrayConstructor();		// success
LargeNum testAdd();						// success
LargeNum testSubtract();				// success
LargeNum testMultiply();				// success
LargeNum testDivide();					// success
LargeNum testMod();						// success

int main()
{
	LargeNum obj1;
	LargeNum obj2;
	LargeNum obj3;
	LargeNum obj4;
	LargeNum obj5;

	obj1 = testAdd();
	obj2 = testSubtract();
	obj3 = testMultiply();
	obj4 = testDivide();
	obj5 = testMod();

	//obj1 = testArrayConstructor();
	cout << "Print object (sum) from main: ";
	obj1.print();
	cout << endl;

	//obj2 = testArrayConstructor();
	cout << "Print object (difference) from main: ";
	obj2.print();
	cout << endl;

	cout << "Print object (product) from main: ";
	obj3.print();
	cout << endl;

	cout << "Print object (quotient) from main: ";
	obj4.print();
	cout << endl;

	cout << "Print object (remainder) from main: ";
	obj5.print();
	cout << endl;


	   string fin;
	   cout << "finished" << endl;
	   cout << "Input string to exit." << endl;
	   cin >> fin;

	return 0;
}

void testPrint(const LargeNum& numObj)
{
	cout << "testing .print()" << endl;
	numObj.print();
	cout << endl << endl;
}
void testToString(const LargeNum& numObj)
{
	cout << "testing toString()" << endl;
	cout << "Obj: " << numObj << endl;
	cout << endl;
}

void testDefaultConstructor()
{
	LargeNum test;
	cout << "Default constructor called." << endl;
	cout << "Printing default values." << endl;
	test.print();
	cout << endl;
	cout << "The sign is: ";
	if (test.Getsign() == LargeNum::positive)
		cout << "positive" << endl;
	else if (test.Getsign() == LargeNum::negative)
		cout << "negative" << endl;
	cout << "The array size is: " << test.getSize() << endl;
	cout << endl;
}

LargeNum testStringConstructor()
{
	cout << "Testing string constructor" << endl;
	string numString;

	cout << "Input a number" << endl;
	cin >> numString;
	LargeNum test(numString);

	cout << "String constructor called." << endl;
	cout << "Printing object values." << endl;
	test.print();
	cout << endl;
	cout << "The sign is: ";
	if (test.Getsign() == LargeNum::positive)
		cout << "positive" << endl;
	else if (test.Getsign() == LargeNum::negative)
		cout << "negative" << endl;
	cout << "The array size is: " << test.getSize() << endl;
	cout << endl;
	return test;
}

void testEqualOperator()
{
	cout << "Testing = operator." << endl;

	string numString;
	LargeNum obj1;
	cout << "Created default object, obj1: ";

	obj1.print();
	cout << endl;

	cout << "Input a number: ";
	cin >> numString;

	LargeNum obj2(numString);
	cout << "Created obj2: ";
	obj2.print();
	cout << endl;
	obj1 = obj2;
	cout << "After, obj1 = obj2;" << endl << "obj1: ";
	obj1.print();
	cout << endl << endl;
}


LargeNum testAdd()
{
	cout << "Testing addition" << endl;
	string numString1;
	string numString2;
	LargeNum sum;
	// do{
	cout << "Input a number (enter 'q' to quit)" << endl;
	cin >> numString1;
	cout << "Input a number" << endl;
	cin >> numString2;

	LargeNum obj1(numString1);
	LargeNum obj2(numString2);

	sum = obj1.addNum(obj2);

	// }while(numString1!="q" && numString2!= "q");

	return sum;
}

LargeNum testSubtract()
{
	cout << "Testing subtraction" << endl;
	string numString1;
	string numString2;
	LargeNum diff;
	// do{
	cout << "Input a number (enter 'q' to quit)" << endl;
	cin >> numString1;
	cout << "Input a number" << endl;
	cin >> numString2;

	LargeNum obj1(numString1);
	LargeNum obj2(numString2);

	diff = obj1.subtractNum(obj2);

	//}while(numString1!="q" && numString2!= "q");

	return diff;
}

LargeNum testMultiply()
{
	cout << "Testing multiplication" << endl;
	string numString1;
	string numString2;
	LargeNum product;
	// do{
	cout << "Input a number (enter 'q' to quit)" << endl;
	cin >> numString1;
	cout << "Input a number" << endl;
	cin >> numString2;

	LargeNum obj1(numString1);
	LargeNum obj2(numString2);

	product = obj1.muliplyNum(obj2);

	//}while(numString1!="q" && numString2!= "q");

	return product;
}

LargeNum testDivide()
{
	cout << "Testing division" << endl;
	string numString1;
	string numString2;
	LargeNum quotient;
	// do{
	cout << "Input a number (enter 'q' to quit)" << endl;
	cin >> numString1;
	cout << "Input a number" << endl;
	cin >> numString2;

	LargeNum obj1(numString1);
	LargeNum obj2(numString2);

	quotient = obj1.divideNum(obj2);

	//}while(numString1!="q" && numString2!= "q");

	return quotient;
}

LargeNum testMod()
{
	cout << "Testing modulus" << endl;
	string numString1;
	string numString2;
	LargeNum remainder;
	// do{
	cout << "Input a number (enter 'q' to quit)" << endl;
	cin >> numString1;
	cout << "Input a number" << endl;
	cin >> numString2;

	LargeNum obj1(numString1);
	LargeNum obj2(numString2);

	remainder = obj1.modNum(obj2);

	//}while(numString1!="q" && numString2!= "q");

	return remainder;
}

LargeNum testArrayConstructor()
{
	int* array;
	int size;

	cout << "Input size: ";
	cin >> size;

	array = new int[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Input a number: ";
		cin >> array[i];
	}
	LargeNum obj1(array, size, LargeNum::positive);
	cout << "Printing obj1: ";
	obj1.print();
	cout << endl;

	delete[] array;
	return obj1;
}
