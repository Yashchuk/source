/**
* Using only bit operation, write a function that returns a value 
* (0 - with a negative value of the parameter x, the value x - otherwise); 
* x - long integer.
*/

#include "stdafx.h"
#include <iostream>
#include "binaryoutput.h"

typedef long int LI;

/*
*@ brief	This function return "0" if number is negative or your number in other case
*/
LI MaxValue (const LI & number);

const short MAX_BITS = sizeof(LI) * 8 - 1;

int _tmain(int argc, _TCHAR* argv[])
{
	using std::cin;
	cout << "Enter number: ";
	LI number;
	cin >> number;
	cout << "You entered: ";
	DecToBin( (unsigned long int) number);
	cout << "Result: ";
	DecToBin( (unsigned long int) MaxValue(number) );
	system ("@pause");
	return 0;
}

LI MaxValue (const LI & number)
{
	LI sign = number & (0x1 << MAX_BITS); /*the sign of number*/
	sign |= sign >> MAX_BITS;
	return (number & ~sign);
}
