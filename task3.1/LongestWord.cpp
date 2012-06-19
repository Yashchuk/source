/**
* @file		LongestWord.h
* @brief	This file contains source code of Task 3.1.
*			It contains  declarations of LongWord, Length functions.
*			It's main purpose - to find the longest word and return it length.
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
#include "LongestWord.h"

/**
* @brief	This function return length of the longest word
* @param	[in]			instr - input string
* return	unsigned int	length of the longest word
*/

UI LongWord(std::string & instr)
{
	UI wordBegin,			/*this variable indicates the begin of next word*/
		wordEnd,			/*this variable indicates the end of next word*/
		len = 0,			/*this variable have length of the longest word*/
		longWordB,			/*this variable indicates the begin of the longest word*/
		longWordE;			/*this variable indicates the end of the longest word*/
	for(UI i = 0; i < instr.size(); ++i)
	{
		if( isalpha(instr[i]) )
		{
			if(i && !isspace(instr[i - 1]) )
			{
				continue;
			}
			wordBegin = i;
			++i;
			if( ! (i < instr.size() ) )
			{
				wordEnd = wordBegin;
				Length(&len, wordBegin, wordEnd, &longWordB, &longWordE);
				break;
			}
			while( isalpha(instr[i]) )
			{
				++i;
				if( ! (i < instr.size() ) )
				{
					wordEnd = i - 1;
					Length(&len, wordBegin, wordEnd, &longWordB, &longWordE);
					break;
				}
			}
			if( ! (i < instr.size() ) )
			{
				break;
			}
			if( !isspace(instr[i]) && !ispunct(instr[i]) )
			{
				wordBegin = wordEnd = i;
				continue;
			}
			wordEnd = i - 1;
			Length(&len, wordBegin, wordEnd, &longWordB, &longWordE);
		}
	}
	if(!len)
	{
		std::cout << "You don't enter any word!\n";
		return 0;
	}
	std::cout << "The longest word is \"";
	for(UI i = longWordB; i <= longWordE; ++i)
	{
		std::cout << instr[i];
	}
	std::cout << "\".\n";
	return (longWordE - longWordB + 1);
}

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

void Length(UI * l, UI wB, UI wE, UI * lWB, UI * lWE)
{
	if(*l < (wE - wB + 1) )
	{
		*l = wE - wB + 1;
		*lWB = wB;
		*lWE = wE;
	}
}