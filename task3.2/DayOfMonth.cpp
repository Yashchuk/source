/**
* @file		LongestWord.cpp
* @brief	This file contains source code of Task 3.1.
*			It contains  declarations of DayAndMonth functions.
*			It's main purpose - to determines the appropriate date <Day> <Month>.
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
#include "DayOfMonth.h"

void DayAndMonth(US day, US * DM)
{
	US i = 0;
	for(; day > DM[i]; ++i)
	{
		day -= DM[i];
	}
	cout << "Day: " << day << "\tMonth: ";
	switch(i)
	{
		case 0: cout << "January" << endl;
				break;
		case 1: cout << "February" << endl;
				break;
		case 2: cout << "March" << endl;
				break;
		case 3: cout << "April" << endl;
				break;
		case 4: cout << "May" << endl;
				break;
		case 5: cout << "June" << endl;
				break;
		case 6: cout << "July" << endl;
				break;
		case 7: cout << "August" << endl;
				break;
		case 8: cout << "September" << endl;
				break;
		case 9: cout << "October" << endl;
				break;
		case 10: cout << "November" << endl;
				break;
		case 11: cout << "December" << endl;
				break;
	}
}