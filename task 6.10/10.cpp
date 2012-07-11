/**
* @file			10.cpp
* @brief		task 6.10
*				N are grey and M are white mice sitting in a circle. 
*				The cat walks around the circle clockwise and eats every S-th mouse.
*				The first time through n begins with a grey mouse. Make the algorithm
*				that determines the order in which sat a mouse, if some time is left K grey and white L mice.
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
#include "Mouse.h"

using namespace std;

typedef unsigned short US;

/*
* @brief	This function ask user to enter some data and return it
* return	unsigned int
*/

US DE(US cmp = USHRT_MAX);

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Enter number of grey mice (must be > 0): ";
	US g = DE();
	cout << "Enter number of white mice (must be > 0): ";
	US w = DE();
	cout << "Enter that each mouse eats cat (must be > 0): ";
	US e = DE();
	cout << "Enter number of grey mice after cat dinner (must be <= " << g << "): ";
	US aG = DE(g);
	cout << "Enter number of white mice after cat dinner (must be <= " << w << "): ";
	US aW = DE(w);
	UI rE = (g + w) - (aG + aW);
	Mouse * pM;
	try
	{
		pM = new Mouse(g, w, rE);
	}
	catch(bad_alloc)
	{
		cerr << "Can't allocat memory to objet Mouse!" << endl;
		exit(EXIT_FAILURE);
	}
	pM->EI(e);
	pM->BIE();
	if( !( pM->Order(g, aG) ) )
	{
		cout << "No combinations!" << endl;
	}
	else
	{
		cout << "In beginning mice should sit as (1 - grey mouse, 0 - white):" << endl;
		pM->Show();
	}
	system("@pause");
	return 0;
}

US DE(US cmp)
{
	double tmp = 0;
	while( (tmp < 1) || (tmp > cmp) )
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
		if( (tmp < 1) || (tmp > cmp) )
		{
			cout << "Wrong data. Re-enter: ";
		}
	}
	return (US)tmp;
}

