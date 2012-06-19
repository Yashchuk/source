/**
* @file		Sorting.cpp
* @brief	This file contains source code of Task 3.26.
*			It contains declarations of Sort functions.
*			It's main purpose - to sort array.
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
#include "Sorting.h"

void Sort(SI * row, SI Size)
{
	SI max;			/*index for min elements*/
	SI temp;
	for(int j = 0; j < Size; j++)
	{
		max = j;
		for(int i = j; i < Size; i++)
		{
			if(row[max] < row[i])
			{
				max = i;
			}
		}
		temp = row[j];
		row[j] = row[max];
		row[max] = temp;
	}
}