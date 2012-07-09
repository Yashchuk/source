// 8.cpp: определяет точку входа для консольного приложения.
//

/**
* @file			8.cpp
* @brief		task 6.8
*				Located on a circle of coins N arms up and down the arms
*				of M coins. Walking around the circle clockwise, each fifth
*				coin flips. For the first time by starting with a coin laying
*				up arms. Write a program that will determine in what order to
*				place the coin, that after the moves to become I. coins, coats
*				of arms lying up.
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
#include "Coins.h"

using namespace std;

typedef unsigned int UI;

/*
* @brief	This function ask user to enter some data and return it
* return	unsigned int
*/

UI DE(UI cmp = UINT_MAX);

/*
* @brief	This function shows coins (1 - arms up, 0 - arms down)
* @param	[in]			pC - pointer of class Coins
* return	void
*/

void Show(const Coins * pC);

int _tmain(int argc, _TCHAR* argv[])
{
	UI t,				/*tails*/
		e,				/*eagle*/
		m,				/*number of moves*/
		rE;				/*show Eagle*/
	cout << "Enter how much coins show eagle (must be > 0): ";
	e = DE();
	cout << "Enter how much coins show tails (must be > 0): ";
	t = DE();
	cout << "Enter how much moves must be (must be > 0): ";
	m = DE();
	cout << "Enter how much coins must shows eagle after " << m << " moves: ";
	rE = DE(t + e);
	Coins * pC = new Coins(t, e);
	pC->Move(m);
	if( pC->Order(m, e, rE) )
	{
		cout << "In this order must be placed coins:" << endl;
		Show(pC);
		cout << "After " << m << " moves it will be:" << endl;
		pC->Move(m);
		Show(pC);
	}
	else
	{
		cout << "No combination" << endl;
	}
	delete pC;
	system("@pause");
	return 0;
}

void Show(const Coins * pC)
{
	UI tS = pC->Size();
	for(UI i = 0; i < tS; ++i)
	{
		cout << pC->operator[](i) << ' ';
	}
	cout << endl;
}

UI DE(UI cmp)
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
			cout << "Wong data. Re-enter: ";
		}
	}
	return tmp;
}
