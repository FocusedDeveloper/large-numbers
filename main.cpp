//#include "stdafx.h"
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
LargeNum testArrayConstructor();
LargeNum testAdd();
LargeNum testSubtract();

int main()
{
	LargeNum obj1;
	LargeNum obj2;

	obj1 = testAdd();
	obj2 = testSubtract();

	//obj1 = testArrayConstructor();
	cout << "Print object from main: ";
	obj1.print();
	cout << endl;

	//cout << "Addition answer was: " << obj1 << endl;
	//out << "Subtraction answer was: " << obj2 << endl;
	//    testDefaultConstructor();
	//    cout<<endl;
	//    LargeNum obj1;
	//    obj1 = testStringConstructor();
	//    cout<<endl;
	//
	//    testToString(obj1);
	//    cout<<endl;
	//
	 //   testEqualOperator();
	//   cout<<endl;
//
	//    LargeNum obj2;
	//
	//    string numString1;
	//    string numString2;
	//
	//    cout << "Input a number" << endl;
	//    cin>>numString1;
	//    cout<<"Input a number"<<endl;
	//    cin>>numString2;
	//
	//    cout<<endl;
	//    obj1.updateNumber(numString1);
	//    obj2.updateNumber(numString2);



	//    testPrint(obj1);
	//    testPrint(obj2);
	//

	//    testToString(obj2);
	//
	   string fin;
	   cout << "finished" << endl;
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
	LargeNum sum;
	// do{
	cout << "Input a number (enter 'q' to quit)" << endl;
	cin >> numString1;
	cout << "Input a number" << endl;
	cin >> numString2;

	LargeNum obj1(numString1);
	LargeNum obj2(numString2);

	sum = obj1.subtractNum(obj2);

	//}while(numString1!="q" && numString2!= "q");

	return sum;
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
