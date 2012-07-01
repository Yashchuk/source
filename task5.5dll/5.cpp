/**
* @file			5.cpp
* @brief		task 5.5
*				Create a game tic Tac Toe .
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
#include "XO.h"

int _tmain(int argc, _TCHAR* argv[])
{
	if (!LDll())
	{
		std::cout << "Can't load DLL" << std::endl;
		return 1;
	}


	char ** ar = new char * [*CELL];	/*ar - this array have all moves. It is interface to user*/
	try
	{
		ar = new char * [*CELL];	
	}
	catch(std::bad_alloc & ba)
	{
		std::cout << ba.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	ar[0] = "Left-up cell";
	ar[1] = "Up cell";
	ar[2] = "Right-up cell";
	ar[3] = "Left cell";
	ar[4] = "Middle cell";
	ar[5] = "Right cell";
	ar[6] = "Left-down cell";
	ar[7] = "Down cell";
	ar[8] = "Right-down cell";
	char game = 'y';				/*choice 'y' - play game, other exit*/
	char * field;					/*playing field*/
	try
	{
		field = new char[*CELL];	
	}
	catch(std::bad_alloc & ba)
	{
		std::cout << ba.what() << std::endl;
		delete [] ar;
		exit(EXIT_FAILURE);
	}
	char ct = 0;					/*number of move*/
	while(game == 'y')
	{
		system("cls");
		for(char i = 0; i < *CELL; ++i)
		{
			field[i] = ' ';
		}
		Show(field);
		while(ct < 9)
		{
			if(ct == 0 || !(ct % 2) )
			{
				PlMv(field, ar);
			}
			else
			{
				CMv(field, ct);
			}
			++ct;
			system("cls");
			Show(field);
			if( Win(field) )
			{
				break;
			}
		}
		ct = 0;
		std::cout << "Game Over\n";
		std::cout << "Play again? y: ";
		std::cin >> game;
	}
	delete [] ar;
	ULDll();
	system("@pause");
	return 0;
}
