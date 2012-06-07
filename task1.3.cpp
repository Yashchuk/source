/**
* Using only bit operation, write a function that returns 1, 
* if two bits that are selected by different and 0 if equal.
*/

#include "stdafx.h"

/**
* This file has a function that converts decimal to binary and show it
* (include <iostream>, using std::cout, using std::endl).
*/
#include "binaryoutput.h"		

/**
*@brief		This function return 1 if two bits are different and 0 if they are equal
*/
unsigned long BitsEqual(unsigned long int uNum, unsigned short bit1, unsigned short bit2);

int _tmain(int argc, _TCHAR* argv[])
{
	using std::cin;
	unsigned long int uNumber;
	unsigned short bit1, bit2;
	cout << "Enter number: ";
	cin >> uNumber;
	cout << "You entered: ";
	DecToBin(uNumber);
	cout << "The bits numeretion begin from 0\n"
		"(example dec - 14, bit - 1110. bit #0 - 0, bit #1 - 1, etc.)\n"
		"Enter first bit: ";
	cin >> bit1;
	cout << "Enter second bit: ";
	cin >> bit2;
	cout << BitsEqual(uNumber, bit1, bit2) << endl;
	system("@pause");
	return 0;
}

unsigned long BitsEqual(unsigned long int uNum, unsigned short bit1, unsigned short bit2)
{
	bit1 = (uNum >> bit1) & 0x1;
	cout << "First entered bit = " << bit1 << endl;
	bit2 = (uNum >> bit2) & 0x1;
	cout << "Second entered bit = " << bit2 << endl;
	return bit1 ^ bit2;
}