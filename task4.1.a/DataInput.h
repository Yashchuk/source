/**
* @file		DataInput.h
* @brief	This file contains source code of Task 4.1.
*			It contains  declarations of AD, AN functions.
*
* Copyright 2012 by Oleg Kiss,
*
* This software is confidental and proprietary information
* of Oleg Kiss. You shall not disclose such
* confidental information and shall use it only in
* accordance with terms of the license agreement
* you entered into with Oleg Kiss.
*/

#ifndef DATAINPUT_H_
#define DATAINPUT_H_

#include <iostream>
#include <fstream>

/*
* @brief	This function ask users enter range and 
*			how much numbers must be in array 
* @param	[in]			is - object of istream
* @param	[in, out]		range - range of value
* @parem	[in, out]		n - how much numbers
* @param	[in]			b - if read from file 0, else handle input
* return	void
*/

void AD(std::istream & is, int * range, int * n, bool b = 1);

/*
* @brief	This function fills an array 
* @param	[in]			is - object of istream
* @param	[in, out]		num - array
* @parem	[in, out]		n - how much numbers must be in array
* @param	[in, out]		r - range of value
* @param	[in]			b - if read from file 0, else handle input
* return	void
*/

void AN(std::istream & is, int * num, int n, int r, bool b = 1);

#endif