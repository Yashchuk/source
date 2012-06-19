/**
* @file		DeleteWord.h
* @brief	Develop a function that removes from the sentence the word, 
*			given its serial number (if the word is in sentence). Based 
*			on the developed functions to remove the second and fifth word 
*			in the sentence imposed. Print the result.
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

#include "DeleteWord.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Enter some test:\n";
	string str;
	getline(cin, str);
	US first = 2, second = 5;	/*this words must be to delete*/

	/*The code between, if user enter words*/

/*	while(first < 1)
	{
		if(!cin)
		{
			cin.clear();
			while(cin.get() != '\n')
			{
				;
			}
		}
		cout << "Enter first word to delete ( > 0): ";
		cin >> first;
	}
	while(cin.get() != '\n')
	{
		;
	}
	while(second < 1)
	{
		if(!cin)
		{
			cin.clear();
			while(cin.get() != '\n')
			{
				;
			}
		}
		cout << "Enter second word to delete ( > 0): ";
		cin >> second;
	}
	while(cin.get() != '\n')
	{
		;
	}*/
	SearchWord(str, first, second);
	cout << "Result: " << str << endl;
	system("@pause");
	return 0;
}