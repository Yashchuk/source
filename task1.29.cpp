/**
* Using only bit and arithmetic operations, write a function that performs cyclic shift 
* give an unsigned long integer to r bits to the right.
*/

#include "stdafx.h"

/**
* This file has a function that converts decimal to binary and show it
* (include <iostream>, using std::cout, using std::endl).
*/
#include "binaryoutput.h"

/**
*@brief		This function does cyclic shift to the right
*/
void CyclicShift(unsigned long int & uNumber, unsigned short & HMB);

const int BITS_IN_U_LONG_INT = sizeof(unsigned long int) * 8;

int _tmain(int argc, _TCHAR* argv[])
{
	using std::cin;
	unsigned long int uNumber;
	unsigned short HowManyBits;
	cout << "Enter number: ";
	cin >> uNumber;
	cout << "You entered: ";
	DecToBin(uNumber);
	cout << "How many bits move: ";
	cin >> HowManyBits;
	CyclicShift(uNumber, HowManyBits);
	cout << "Number after shift: ";
	DecToBin(uNumber);
	system("@pause");
	return 0;
}

void CyclicShift(unsigned long int & uNumber, unsigned short & HMB)
{
	unsigned long int utemp = (uNumber << (BITS_IN_U_LONG_INT - HMB));
	uNumber >>= HMB;
	uNumber |= utemp;
}