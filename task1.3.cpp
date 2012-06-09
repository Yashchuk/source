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

typedef unsigned long int ULI;
typedef unsigned short US;

/**
*@brief		This function return 1 if two bits are different and 0 if they are equal
*/
bool BitsEqual(ULI uNum, US bit1, US bit2);

int _tmain(int argc, _TCHAR* argv[])
{
	using std::cin;
	const short MAX_BIT = sizeof(ULI) * 8 - 1;
	ULI uNumber;
	US bit1, bit2;
	cout << "Enter number: ";
	cin >> uNumber;
	cout << "You entered: ";
	DecToBin(uNumber);
	cout << "The bits numeretion begin from 0\n"
		"(example dec - 14, bit - 1110. bit #0 - 0, bit #1 - 1, etc.)\n"
		"Enter first bit (max 31): ";
	cin >> bit1;
	while(bit1 > MAX_BIT)
	{
		cout << "Try again, enter first bit (max " << MAX_BIT <<"): ";
		cin >> bit1;
	}
	cout << "Enter second bit (max 31): ";
	cin >> bit2;
	while(bit2 > MAX_BIT)
	{
		cout << "Try again, enter second bit (max " << MAX_BIT <<"): ";
		cin >> bit2;
	}
	if(BitsEqual(uNumber, bit1, bit2))
		cout << "Bits are different!\n";
	else
		cout << "Bits are equal!\n";
	return 0;
}

bool BitsEqual(ULI uNum, US bit1, US bit2)
{
	bit1 = (US)( (uNum >> bit1) & (ULI) 0x1);
	cout << "First entered bit = " << bit1 << endl;
	bit2 = (US)( (uNum >> bit2) & (ULI) 0x1);
	cout << "Second entered bit = " << bit2 << endl;
	return (bool) bit1 ^ (bool) bit2;
}