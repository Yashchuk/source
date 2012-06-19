/**
* @file		Numeral.h
* @brief	This file contains source code of Task 3.4.
*			It contains  declarations of Numeral functions.
*
* Copyright 2012 by Oleg Kiss,
*
* This software is confidental and proprietary information
* of Oleg Kiss. You shall not disclose such
* confidental information and shall use it only in
* accordance with terms of the license agreement
* you entered into with Oleg Kiss.
*/


#ifndef NUMERAL_H_
#define NUMERAL_H_

#include <string>

typedef unsigned short US;

/*
* @brief	This function returns the numeral two-digit number
* @param	[in]			num - number (10 - 99)
* return	string			numeral
*/

std::string Numeral(US num);

#endif /*NUMERAL_H_*/