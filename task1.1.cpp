/**
* Using only bit operation, write a function that returns 
* the next even number for a given unsigned long integer.
*/

#include "stdafx.h"

/**
* This file have a function that converts decimal to binary and show it
* (include <iostream>, using std::cout, using std::endl).
*/
#include "binaryoutput.h"

typedef unsigned long int ULI;

/**
*@brief		This function return next even number
*/
ULI NextEvenNumber(ULI uNum);

int _tmain(int argc, _TCHAR* argv[])
{
	using std::cin;
	ULI uNumber;
	cout << "Enter number: ";
	cin >> uNumber;
	cout << "You entered: ";
	DecToBin(uNumber);
	uNumber = NextEvenNumber(uNumber);
	cout << "Next even number: " 
		<< uNumber << " (dec) ";
	DecToBin(uNumber);
	return 0;
}

ULI NextEvenNumber(ULI uNum)
{
	return ( (uNum & (ULONG_MAX & (ULI) (~0x1)) ) + 2);
}
