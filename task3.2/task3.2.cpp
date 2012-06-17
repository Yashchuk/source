/**
* @file			task3.2
* @brief		Develop a function that for a given numbered
*				day of the year determines the appropriate date
*				<Day> <Month> (you know, that not a leap year). 
*				Generate 5 random numbers that specifies the number 
*				of days of the year. Using the developed function to 
*				print the date corresponding to each of them.
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

/**
* This file include <iostream>, and declarations of DayAndMonth functions.
*/

#include "DayOfMonth.h"
#include <cstdlib>
#include <ctime>

typedef unsigned short US;

const US MAX_DAYS = 365;

const US RANDOM_NUM = 5;

using namespace std;

enum {January = 31, February = 28, March = 31, April = 30, May = 31, June = 30, July = 31, August = 31, September = 30, October = 31, November = 30, December = 31};

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0) );
	US DayMonth[] = {January, February, March, April, May, June, July, August, September, October, November, December};
	US day = 0;
	for(US i = 0; i < RANDOM_NUM; ++i)
	{
		day = rand() % 365 + 1;
		cout << "Day: " << day << endl;
		DayAndMonth(day, DayMonth);
	}
	system("@pause");
	return 0;
}
