/**
* @file			task3.1
* @brief		Develop a function that determines the longest word in the set of character strings
*				and returns the length of the word. Based on the developed functions to define and
*				print the longest word among all groups of words typed sentences.
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

/**
* This file include <iostream>, <string> and declarations of LongWord, Length functions.
*/

#include "LongestWord.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Enter some text:\n";
	string instr;
	getline(cin, instr);
	if(instr.empty() )
	{
		cout << "You don't enter any characters!\n";
	}
	else
	{
		cout << "It has " << LongWord(instr) << " characters.\n";
	}
	system("@pause");
	return 0;
}