/**
* @file			9.cpp
* @brief		task 6.9
*				There are N black and white cards, stacked in a pile. 
*				Cards are arranged on a table in one line as follows: 
*				the first is placed on the table, the second - down the stack, 
*				requiring ¬ Rule - on the table, the fourth - down the stack, and so on, 
*				until all the cards are laid on the table. Write a program that determines 
*				what should be the original location in the stack of cards to spread out 
*				on the table cards Th ¬ redovalis by color: white, black, white, black, etc.
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
#include "Cards.h"

using std::cin;
using std::cout;
using std::endl;

/*
* @brief	This function ask user to enter some data and return it
* return	unsigned int
*/

UI DE();

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Enter number of white cards: ";
	UI w = DE();
	cout << "Enter number of black cards: ";
	UI b = DE();
	Cards * pC;
	try
	{
		pC = new Cards(b, w);
	}
	catch( ... )
	{
		exit(EXIT_FAILURE);
	}
	cout << "Cards must be in this order: " << endl;
	if( pC->DO() )
	{
		UI sum = w + b;
		for(UI i = 0; i < sum; ++i)
		{
			cout << pC->operator[](i) << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "No combination." << endl;
	}
	delete pC;
	system("@pause");
	return 0;
}

UI DE()
{
	double tmp = 0;
	while( tmp < 1 )
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
		if( tmp < 1 )
		{
			cout << "Wrong data. Re-enter: ";
		}
	}
	return (UI)tmp;
}