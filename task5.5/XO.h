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

#include <iostream>

const short CELL = 9;	/*field size*/

/*
* @brief	This function show playing field
* @param	[in]		f - array playing field
* return	void
*/

void Show(char * f);

/*
* @brief	This function offers the user to make their move
* @param	[in, out]	f - array playing field
* @param	[in]		ar - this array has help that move is possible
* return	void
*/

void PlMv(char * f, char ** ar);

/*
* @brief	This function checks if victory
* @param	[in]		f - array playing field
* return	void
*/

bool Win(char * f);

/*
* @brief	This function to do CPU move
* @param	[in, out]	f - array playing field
* @param	[in]		a - move number
* return	void
*/

void CMv(char * f, char a);

/*
* @brief	This function checks if user of CPU can win the next move
* @param	[in, out]	f - array playing field
* @param	[in]		c - flags 'X' - can user win, 'O' - can CPU win
* return	void
*/

bool CanWin(char * f, char c);

/*
* @brief	This function calculates the next move
* @param	[in, out]	f - array playing field
* @param	[in]		a - move number
* return	void
*/

void Move(char * f, char a);

/*
* @brief	This function checks if user of CPU can win the next move
*			if c == cell 0 or 8 or 3 or 5
* @param	[in, out]	f - array playing field
* @param	[in]		i - number of cell
* @param	[in]		c - 'X' or 'O'
* @param	[in]		s - sign
* return	void
*/

bool plus1plus2(char * f, char i, char c, short s);

/*
* @brief	This function checks if user of CPU can win the next move
*			if c == cell 1 or 7 or 4
* @param	[in, out]	f - array playing field
* @param	[in]		i - number of cell
* @param	[in]		c - 'X' or 'O'
* @param	[in]		s - sign
* return	void
*/

bool plus1minus1(char * f, char i, char c, short s);

/*
* @brief	This function checks if user of CPU can win the next move
*			if c == cell 0 or 8 or 1 or 7 or 2 or 6
* @param	[in, out]	f - array playing field
* @param	[in]		i - number of cell
* @param	[in]		c - 'X' or 'O'
* @param	[in]		s - sign
* return	void
*/

bool plus3plus6(char * f, char i, char c, short s);

/*
* @brief	This function checks if user of CPU can win the next move
*			if c == cell 3 or 5 or 4
* @param	[in, out]	f - array playing field
* @param	[in]		i - number of cell
* @param	[in]		c - 'X' or 'O'
* @param	[in]		s - sign
* return	void
*/

bool plus3minus3(char * f, char i, char c, short s);

#endif