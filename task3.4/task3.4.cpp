/**
* @file			task3.4
* @brief		Develop a function that generates string that
*				a verbal account (numerals) given two-digit number. 
*				Generate a sequence of 14-s random two-digit numbers.
*				Using the developed feature to print a table of values 
*				​​of these numbers and verbal records.
* 
* Copyright 2012 by Oleg Kiss,
*
* This software is confidental and proprietary information
* of Oleg Kiss. You shall not disclose such
* confidental information and shall use it only in
* accordance with terms of the license agreement
* you entered into with Oleg Kiss.
*/

#include "stdafx.h"

#include "Numeral.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef unsigned short US;

const US MAX_NUM = 99;

const US RANDOM_NUM = 14;

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0) );
	US num = 0;
	for(US i = 0; i < RANDOM_NUM; ++i)
	{
		num = rand() % 90 + 10;
		cout << i + 1 << ". Number: " << num << " - " << Numeral(num) << endl;
	}
	system("@pause");
	return 0;
}