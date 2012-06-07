#ifndef BINAY_OUTPUT_H_
#define BINAY_OUTPUT_H_

#include <iostream>

using std::cout;
using std::endl;

/**
*@brief		This function return how much bits of number are using
*/

int HowMuchBitsUsing(unsigned long int uNum)
{
	int count = 1;
	while(uNum > 1)
	{
		uNum >>= 1;
		++count;
	}
	return count;
}

/**
*@brief		This function converts a number from decimal to binary number system and show its
*/

void DecToBin(unsigned long int uNum)
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

#endif /*BINAY_OUTPUT_H_*/