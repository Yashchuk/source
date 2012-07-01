/**
* @file			3.cpp
* @brief		task 5.3
*				Create a library for realization the stack.
*				Do inverting input sequence of characters
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
#include "MyStack.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Stack stc;
	char ch;
	cout << "Enter sequence of characters: ";
	cin.get(ch);
	while(ch != '\n')
	{
		stc.add(ch);
		cin.get(ch);
	}
	while( !(stc.isempty() ) )
	{
		cout << stc.top();
		stc.pop();
	}
	cout << endl;
	system("@pause");
	return 0;
}
