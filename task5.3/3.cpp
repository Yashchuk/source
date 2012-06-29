/**
* @file			3.cpp
* @brief		task 5.3
*				Create a library for realization the stack.
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

/*
* @brief	This function clears input stream
* return	void
*/

void ClsInp();

int _tmain(int argc, _TCHAR* argv[])
{
	Stack stc;
	char ch = '0';
	while(ch != '5')
	{
		cout << "1 - to add character to stack;" << endl
			<< "2 - to remove characters from stack;" << endl
			<< "3 - to return the element at the top of the stack;"  << endl
			<< "4 - to check is the stack empty;" << endl
			<< "5 - to delete stack." << endl;
		cout << "Your choice: ";
		cin >> ch;
		ClsInp();
		switch(ch)
		{
		case '1':
			cout << endl << "Enter character: ";
			cin.get(ch);
			stc.add(ch);
			ch = '0';
			cout << endl;
			ClsInp();
			break;
		case '2':
			if( ! (stc.isempty() ) )
			{
				cout << endl << "You removed: " << stc.top() << endl << endl;
				stc.pop();
			}
			else
			{
				cout << endl << "You can't do that. Stack is empty!\n" << endl;
			}
			break;
		case '3': 
			if( ! (stc.isempty() ) )
			{
				cout << endl << stc.top() << endl << endl;
			}
			else
			{
				cout << endl << "You can't do that. Stack is empty!\n" << endl;
			}
			break;
		case '4':
			if( stc.isempty() )
			{
				cout << endl << "Stack is empty!\n" << endl;
			}
			else
			{
				cout << endl << "Stack isn't empty!\n" << endl;
			}
			break;
		case '5': stc.~Stack();
			break;
		default : cout << "Re-enter ";
			break;
		}
	}
	system("@pause");
	return 0;
}

void ClsInp()
{
	while(cin.get() != '\n')
	{
		/*NULL*/
	}
}