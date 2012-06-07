/**
* Using only bit operation, write a function that returns 
* the next even number for a given unsigned long integer.
*/

#include "stdafx.h"

/**
* This file has a function that converts decimal to binary and show it
* (include <iostream>, using std::cout, using std::endl).
*/
#include "binaryoutput.h"

/**
*@brief		This function return next even number
*/
unsigned long NextEvenNumber(unsigned long int uNum);

int _tmain(int argc, _TCHAR* argv[])
{
	using std::cin;
	unsigned long int uNumber;
	cout << "Enter number: ";
	cin >> uNumber;
	cout << "You entered: ";
	DecToBin(uNumber);
	uNumber = NextEvenNumber(uNumber);
	cout << "Next even number: " 
		<< uNumber << " (dec) ";
	DecToBin(uNumber);
	system("@pause");
	return 0;
}

unsigned long NextEvenNumber(unsigned long int uNum)
{
	return ( (uNum & (ULONG_MAX & ~0x1) ) + 2);
}
