#ifndef INVALIDVALUE_H
#define INVALIDVALUE_H
#include <sstream>
#include <string>

class invalidValue
{
public:
	invalidValue() {
		message = "There is an invalid value in the array";
	}
	invalidValue(string arrayName, int indx, int val)
	{
		std::stringstream ss;
		ss << "Array: " << arrayName << " at index i: " << indx << " is invalid: " << val << '\n';

		message = ss.str();
	}
	string what(){ return message; }

private:
	string message;
};

#endif // INVALIDVALUE_H
