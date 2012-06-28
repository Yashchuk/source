/**
* @file		DataInput.cpp
* @brief	This file contains source code of Task 4.1.
*			It contains  realized of AD, AN functions.
*			It's main purpose - to enter data.
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
#include "DataInput.h"

const int MAX_VAL = 1000000000;

void AN(std::istream & is, int * num, int n, int r, bool b)
{
	for(int i = 1; i < n + 1; ++i)
	{
		if(b)
		{
			std::cout << "Enter number (must be > 0 and <= " << r << "): ";
		}
		is >> num[i];
		while( !(num[i] > 0) || num[i] > r)
		{
			if(!is)
			{
				is.clear();
				while(is.get() != '\n')
				{
					/*NULL*/
				}
			}
			if( !(num[i] > 0) || num[i] > r)
			{
				std::cout << "Re-enter: ";
				is >> num[i];
			}
		}
	}
}

void AD(std::istream & is, int * range, int * n, bool b)
{
	if(b)
	{	
		std::cout << "Enter maximal search value (must be > 0 and <= " << MAX_VAL << "): ";
	}
	while( !(*range > 0) || *range > MAX_VAL)
	{
		if(!is)
		{
			is.clear();
			while(is.get() != '\n')
			{
				/*NULL*/
			}
		}
		is >> *range;
		if( !(*range > 0) || *range > MAX_VAL)
		{
			std::cout << "Re-enter: ";
		}
	}
	if(b)
	{
		std::cout << "Enter how much number (must be > 0 and <= " << *range << "): ";
	}
	while( !(*n > 0) || *n > *range)
	{
		if(!is)
		{
			is.clear();
			while(is.get() != '\n')
			{
				/*NULL*/
			}
		}
		is >> *n;
		if( !(*n > 0) || *n > *range)
		{
			std::cout << "Re-enter: ";
		}
	}
}