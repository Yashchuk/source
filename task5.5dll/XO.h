/**
* @file		XO.h
* @brief	This file contains source code of Task 5.5.
*			It contains  declarations of Show, PlMv, Win, CMv, CanWin, Move, 
*			plus1plus2, plus1minus1, plus3plus6, plus3minus3 functions.
*
* Copyright 2012 by Oleg Kiss,
*
* This software is confidental and proprietary information
* of Oleg Kiss. You shall not disclose such
* confidental information and shall use it only in
* accordance with terms of the license agreement
* you entered into with Oleg Kiss.
*/

#ifndef XO_H_
#define XO_H_

#include <Windows.h>
#include <iostream>

typedef short * cell;

typedef void (*Fun0)(char *);						/*show*/
typedef void (*Fun1)(char * , char ** );			/*plmv*/
typedef bool (*Fun2)(char *);						/*win*/
typedef void (*Fun3)(char * , char);				/*cmv, move*/
typedef bool (*Fun4)(char * , char);				/*canwin*/
typedef bool (*Fun5)(char *, char, char, short);	/*HELP FUN*/	

HINSTANCE hLib;

cell CELL;

/*
* @brief	This function show playing field
* @param	[in]		f - array playing field
* return	void
*/

Fun0 Show;

/*
* @brief	This function offers the user to make their move
* @param	[in, out]	f - array playing field
* @param	[in]		ar - this array has help that move is possible
* return	void
*/

Fun1 PlMv;

/*
* @brief	This function checks if victory
* @param	[in]		f - array playing field
* return	void
*/

Fun2 Win;

/*
* @brief	This function to do CPU move
* @param	[in, out]	f - array playing field
* @param	[in]		a - move number
* return	void
*/

Fun3 CMv;

/*
* @brief	This function calculates the next move
* @param	[in, out]	f - array playing field
* @param	[in]		a - move number
* return	void
*/

Fun3 Move;

/*
* @brief	This function checks if user or CPU can win the next move
* @param	[in, out]	f - array playing field
* @param	[in]		c - flags 'X' - can user win, 'O' - can CPU win
* return	void
*/

Fun4 CanWin;

/*
* @brief	This function checks if user of CPU can win the next move
*			if c == cell 0 or 8 or 3 or 5
* @param	[in, out]	f - array playing field
* @param	[in]		i - number of cell
* @param	[in]		c - 'X' or 'O'
* @param	[in]		s - sign
* return	void
*/

Fun5 plus1plus2;

/*
* @brief	This function checks if user of CPU can win the next move
*			if c == cell 1 or 7 or 4
* @param	[in, out]	f - array playing field
* @param	[in]		i - number of cell
* @param	[in]		c - 'X' or 'O'
* @param	[in]		s - sign
* return	void
*/

Fun5 plus1minus1;

/*
* @brief	This function checks if user of CPU can win the next move
*			if c == cell 0 or 8 or 1 or 7 or 2 or 6
* @param	[in, out]	f - array playing field
* @param	[in]		i - number of cell
* @param	[in]		c - 'X' or 'O'
* @param	[in]		s - sign
* return	void
*/

Fun5 plus3plus6;

/*
* @brief	This function checks if user of CPU can win the next move
*			if c == cell 3 or 5 or 4
* @param	[in, out]	f - array playing field
* @param	[in]		i - number of cell
* @param	[in]		c - 'X' or 'O'
* @param	[in]		s - sign
* return	void
*/

Fun5 plus3minus3;

/**
  * @brief		Load fucntions from dll
  * @return		Flase if error occured
  */
bool LDll();

/**
  * @brief		Unload dll
  * @return		void
  */
void ULDll();

bool LDll()
{
	hLib = LoadLibrary("XOdll.dll");
	if (!hLib)
	{
		return false;
	}
	CELL = (cell)GetProcAddress(hLib, "CELL");\
	if (!CELL)
	{
		return false;
	}
	Show = (Fun0)GetProcAddress(hLib, "Show");
	if (!Show)
	{
		return false;
	}
	PlMv = (Fun1)GetProcAddress(hLib, "PlMv");
	if (!PlMv)
	{
		return false;
	}
	Win = (Fun2)GetProcAddress(hLib, "Win");
	if (!Win)
	{
		return false;
	}
	CMv = (Fun3)GetProcAddress(hLib, "CMv");
	if (!CMv)
	{
		return false;
	}
	Move = (Fun3)GetProcAddress(hLib, "Move");
	if (!Move)
	{
		return false;
	}
	CanWin = (Fun4)GetProcAddress(hLib, "CanWin");
	if (!CanWin)
	{
		return false;
	}
	plus1plus2 = (Fun5)GetProcAddress(hLib, "plus1plus2");
	if (!plus1plus2)
	{
		return false;
	}
	plus1minus1 = (Fun5)GetProcAddress(hLib, "plus1minus1");
	if (!plus1minus1)
	{
		return false;
	}
	plus3plus6 = (Fun5)GetProcAddress(hLib, "plus3plus6");
	if (!plus3plus6)
	{
		return false;
	}
	plus3minus3 = (Fun5)GetProcAddress(hLib, "plus3minus3");
	if (!plus3minus3)
	{
		return false;
	}

	return true;
}

void ULDll()
{
	if (hLib)
	{
		FreeLibrary(hLib);
	}
}

#endif /*XO_H_*/