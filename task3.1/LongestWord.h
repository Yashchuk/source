/**
* @file		LongestWord.h
* @brief	This file contains source code of Task 3.1.
*			It contains  declarations of LongWord, Length functions.
*
* Copyright 2012 by Oleg Kiss,
*
* This software is confidental and proprietary information
* of Oleg Kiss. You shall not disclose such
* confidental information and shall use it only in
* accordance with terms of the license agreement
* you entered into with Oleg Kiss.
*/

#ifndef LONGESTWORD_H_
#define LONGESTWORD_H_

#include <iostream>
#include <string>

typedef unsigned int UI;

/**
* @brief	This function return length of the longest word
* @param	[in]			instr - input string
* return	unsigned int	length of the longest word
*/

UI LongWord(std::string & instr);

/*
* @brief	This function set length and set begin and end of the longest word
*			if word longest than present word
* @param	[in, out]		len - length of the present longest word
* @param	[in]			wB - word begin
* @param	[in]			wE - word end
* @param	[in, out]		lWB - longest word begin
* @param	[in, out]		lWE - longest word end
* return	void
*/

void Length(UI * l, UI wB, UI wE, UI * lWB, UI * lWE);

#endif  /*LONGESTWORD_H_*/