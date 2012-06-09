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

const int ULI_BITS = sizeof(ULI) * 8;
/**
*@brief		This function swaps all adjacent bits and return unsigned long integer number.
*/
ULI SwapsAdjacentBits(ULI uNumber, ULI mask1, ULI mask2);
/**
*@brief		This function create two masks
*/
void DefineMask(ULI & mask1, ULI & mask2);

int _tmain(int argc, _TCHAR* argv[])
{
	using std::cin;
	ULI uNumber, mask1 = 0, mask2 = 0;
	DefineMask(mask1, mask2);
	cout << "Enter number: ";
	cin >> uNumber;
	cout << "You entered: ";
	DecToBin(uNumber);
	DecToBin(SwapsAdjacentBits(uNumber, mask1, mask2) );
	system("@pause");
	return 0;
}

ULI SwapsAdjacentBits(ULI uNumber, ULI mask1, ULI mask2)
{
	return uNumber = ( ( (uNumber & mask1) << 1) | ( (uNumber & mask2) >> 1) );
}

void DefineMask(ULI & mask1, ULI & mask2)
{
	for(int i = 0; i < ULI_BITS - 2; i += 2)
		mask1 = ((mask1 | 0x1) << 2);
	mask1 = mask1 | 0x1;
	for(int i = 0; i < ULI_BITS - 2; i += 2)
		mask2 = ((mask2 | 0xA) << 2);
	mask2 = mask2 | 0xA;
}