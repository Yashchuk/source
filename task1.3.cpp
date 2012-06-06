/**
* Using only bit operation, write a function that returns 1, 
* if two bits that are selected by different and 0 if equal.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

/**
*@brief		This function return 1 if two bits are different and 0 if they are equal
*/
unsigned long BitsEqual(unsigned long uNum, unsigned short bit1, unsigned short bit2);

/**
*@brief		This function return how much bits of number are using
*/
int HowMuchBitsUsing(unsigned long uNum);

/**
*@brief		This function converts a number from decimal to binary number system and show its
*/
void DecToBin(unsigned long uNum);

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned long uNumber;
	unsigned short bit1, bit2;
	cout << "Enter number: ";
	cin >> uNumber;
	cout << "You entered: ";
	DecToBin(uNumber);
	cout << "The bits numeretion begin form 0"
		"\n(example dec - 14, bit - 1110. bit #0 - 0, bit #1 - 1, etc.)\n"
		<< "Enter first bit: ";
	cin >> bit1;
	cout << "Enter second bit: ";
	cin >> bit2;
	cout << BitsEqual(uNumber, bit1, bit2) << endl;
	system("@pause");
	return 0;
}

unsigned long BitsEqual(unsigned long uNum, unsigned short bit1, unsigned short bit2)
{
	bit1 = (uNum >> bit1) & 0x1;
	cout << "First entered bit = " << bit1 << endl;
	bit2 = (uNum >> bit2) & 0x1;
	cout << "Second entered bit = " << bit2 << endl;
	return bit1 ^ bit2;
}

int HowMuchBitsUsing(unsigned long uNum)
{
	int count = 1;
	while(uNum != 1)
	{
		uNum >>= 1;
		++count;
	}
	return count;
}

void DecToBin(unsigned long uNum)
{
	
	int count = HowMuchBitsUsing(uNum);
	int bits = count;
	int * ptemp = new int[count];
	while(uNum != 1)
	{
		--count;
		ptemp[count] = (uNum % 2) ;
		uNum /= 2;
	};
	ptemp[--count] = uNum;
	for(int i = 0; i < bits; ++i)
		cout << ptemp[i];
	cout << " (bin)" << endl;
	delete [] ptemp;
}