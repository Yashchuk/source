/**
* Using only bit and arithmetic operations, write a function that returns 
* the unsigned long integer that contains the block of 1 bits of length n, 
* starting from the p-th bits (bits numbered from 0 from right to left).
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
*@brief		This function returns the unsigned long integer that contains 
*			the block of 1 bits of length n, starting from the p-th bits
*/
ULI BlockOf1Bits(US pos, US len);

int _tmain(int argc, _TCHAR* argv[])
{
	using std::cin;
	const int MAX_POS = sizeof(ULI) * 8 - 1;
	US position, length;
	cout << "Enter the position to start: ";
	cin >> position;
	while(position > MAX_POS)
	{
		cout << "Position can't be > " << MAX_POS << ", try again: ";
		cin >> position;
	}
	cout << "Enter block length: ";
	cin >> length;
	while(length > MAX_POS - position)
	{
		cout << "Length can't be > " << MAX_POS - position << ", try again: ";
		cin >> length;
	}
	DecToBin(BlockOf1Bits(position, length));
	system("@pause");
	return 0;
}

ULI BlockOf1Bits(US pos, US len)
{
	len += pos;
	ULI number = (ULI) ( ( (ULI) ~0 >> pos) << pos) ^ ( (ULI) 0x1 << len);
	len = ~len;
	return ( (number << len) >> len);
}