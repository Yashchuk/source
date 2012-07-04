/**
* @file			6.cpp
* @brief		task 6.6
*				In the line are N persons. Presenter counts 
*				from 1 to M, starting with the human at number K. 
*				Man, which ended in the Account, it is the end of the line. 
*				Write a program that will determine the starting number 
*				of the person who turned out at the end of the line after the first L-bills.
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
#include <iostream>
#include "vec.h"

using namespace std;

typedef unsigned int UI;

/*
* @brief	This function ask user to enter some data and return it
* return	unsigned int
*/

UI DE(UI cmp = UINT_MAX);

/*
* @brief	This function return starting number 
*			of the person who turned out at the end 
*			of the line after the first L-bills.
* @param	[in,out]		v - object of class vector where are number of human
* @param	[in]			n - number of human
* @param	[in]			c - how much presenter count
* @param	[in]			s - start number of human
* @param	[in]			r - how much repeat
* return	unsigned int
*/

UI SNOfLH(Vector & v, UI n, UI c, UI s, UI r); 

/*
* @brief	This function fills object of class vector
* @param	[in,out]		v - object of class vector where are number of human
* @param	[in]			size - how much add people
* return	void
*/

void FillV(Vector & v, UI size);

int _tmain(int argc, _TCHAR* argv[])
{
	UI numH = 0, ct = 0, sn = 0, rpt = 0;
	Vector v;
	cout << "Enter number of humans: ";
	numH = DE();
	FillV(v, numH);
	cout << "How many is presenter count: ";
	ct = DE();
	cout << "Enter number of human start: ";
	sn = DE(numH);
	cout << "How much repeat it: ";
	rpt = DE();
	cout << "The last now is the human with start number: " << SNOfLH(v, numH, ct, sn, rpt) << endl;
	system("@pause");
	return 0;
}

UI DE(UI cmp)
{
	UI tmp = 0;
	while( (!tmp) || (tmp >= cmp) )
	{
		if(!cin)
		{
			cin.clear();
			while(cin.get() != '\n')
			{
				/*NULL*/
			}
		}
		cin >> tmp;
		if( (!tmp) || (tmp >= cmp) )
		{
			cout << "Re-enter: ";
		}
	}
	return tmp;
}

void FillV(Vector & v, UI size)
{
	for(UI i = 0; i < size; ++i)
	{
		v.PushBack(i + 1);
	}
}

UI SNOfLH(Vector & v, UI n, UI c, UI s, UI r)
{
	UI tmp;
	c += s - 1;
	while(c > n)
	{
		c -= n;
	}
	while(r--)
	{
		tmp = v[c - 1];
		v.Erase(c - 1);
		v.PushBack(tmp);
	}
	return v[n - 1];
}