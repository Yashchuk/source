/**
* Using only bit operation, write a function that returns 
* the next even number for a given unsigned long integer.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

/**
*@brief		This function return next even number
*/
unsigned long NextEvenNumber(unsigned long uNum);

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

unsigned long NextEvenNumber(unsigned long uNum)
{
	return ( (uNum & (ULONG_MAX & ~0x1) ) + 2);
}

int HowMuchBitsUsing(unsigned long uNum)
{
	int count = 1;
	while(uNum > 1)
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
	while(uNum > 1)
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