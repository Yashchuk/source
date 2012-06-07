/**
* Using only bits operation, write a function that swaps all adjacent bits 
* and return unsigned long integer number.
*/

#include "stdafx.h"

/**
* This file have a function that converts decimal to binary and show it
* (include <iostream>, using std::cout, using std::endl).
*/
#include "binaryoutput.h"

typedef unsigned long int ULI;

/**
*@brief		This function swaps all adjacent bits and return unsigned long integer number.
*/
ULI & SwapsAdjacentBits(ULI & uNumber);

int _tmain(int argc, _TCHAR* argv[])
{
	using std::cin;
	ULI uNumber;
	cout << "Enter number: ";
	cin >> uNumber;
	cout << "You entered: ";
	DecToBin(uNumber);
	DecToBin(SwapsAdjacentBits(uNumber) );
	system("@pause");
	return 0;
}

ULI & SwapsAdjacentBits(ULI & uNumber)
{
	return uNumber = ( ( (uNumber & 0x11111111) << 1) | ( (uNumber & 0xaaaaaaaa) >> 1) );
}
