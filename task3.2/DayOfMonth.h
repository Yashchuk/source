/**
* @file		DayOfMonth.h
* @brief	This file contains source code of Task 3.2.
*			It contains  declarations of DayAndMonth functions.
*
* Copyright 2012 by Oleg Kiss,
*
* This software is confidental and proprietary information
* of Oleg Kiss. You shall not disclose such
* confidental information and shall use it only in
* accordance with terms of the license agreement
* you entered into with Oleg Kiss.
*/


#ifndef DAYOFMONTH_H_
#define DAYOFMONTH_H_

#include <iostream>

using std::cout;
using std::endl;

typedef unsigned short US;

/*
* @brief	This function given numbered day of the year determines 
*			the appropriate date <Day> <Month> (you know, that not a leap year).
* @param	[in]			day - day of the year
* @param	[in]			DM - this array has a number of days In each month
* return	void
*/

void DayAndMonth(US day, US * DM);

#endif /*DAYOFMONTH_H_*/