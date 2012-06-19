/**
* @file		DeleteWord.h
* @brief	This file contains source code of Task 3.7.
*			It contains  declarations of SearchWord, DelWord functions.
*			It's main purpose - to find and delete given words.
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

/**
* @brief	This function search words to be delete
* @param	[in, out]			instr - input string
* @param	[in]				fWord - number of the first word to be delete
* @param	[in]				sWord - number of the second word to be delete
* return	void
*/

void SearchWord(std::string & instr, US fWord, US sWord)
{
	US	wB,						/*this variable indicates the begin of next word*/
		wE;						/*this variable indicates the end of next word*/
	US ct = 0;					/*this variable count words*/
	for(US i = 0; i < instr.size(); ++i)
	{
		if( isalpha(instr[i]) )
		{
			if(i && !isspace(instr[i - 1]) )
			{
				continue;
			}
			wB = i;
			++i;
			if( ! (i < instr.size() ) )
			{
				wE = i - 1;
				++ct;
				DelWord(ct, wB, wE, &fWord, &sWord, instr);
				break;
			}
			while( isalpha(instr[i]) )
			{
				++i;
				if( ! (i < instr.size() ) )
				{
					wE = i;
					++ct;
					DelWord(ct, wB, wE, &fWord, &sWord, instr);
					break;
				}
			}
			if( ! (i < instr.size() ) )
			{
				break;
			}
			if( !isspace(instr[i]) && !ispunct(instr[i]) )
			{
				wB = wE = i;
				continue;
			}
			wE = i;
			++ct;
			DelWord(ct, wB, wE, &fWord, &sWord, instr);
			i = wB;
		}
	}
	if(fWord)
	{
		std::cout << "This string doesn't have word #" << fWord << std::endl;
	}
	if(sWord)
	{
		std::cout << "This string doesn't have word #" << sWord << std::endl;
	}
}

/**
* @brief	This function delete words
* @param	[in]				ct - number of word
* @param	[in]				wB - position where word begin
* @param	[in]				wE - position where Word end
* @param	[in, out]			fWord - number of the first word to be delete
* @param	[in, out]			sWord - number of the second word to be delete
* @param	[in, out]			instr - input string
* return	void
*/

void DelWord(US ct, US wB, US wE, US * fW, US * sW, std::string & instr)
{ 
	std::string::iterator iWB, iWE;
	if(ct == *fW)
	{
		if(wB == wE)
		{
			iWB = instr.begin() + wB;
			instr.erase(iWB);
			*fW = 0;
		}
		else
		{
			iWB = instr.begin() + wB;
			iWE = instr.begin() + wE;
			instr.erase(iWB, iWE);
		}
		*fW = 0;
	}
	if(ct == *sW)
	{
		if(wB == wE)
		{
			iWB = instr.begin() + wB;
			instr.erase(iWB);
			*fW = 0;
		}
		else
		{
			iWB = instr.begin() + wB;
			iWE = instr.begin() + wE;
			instr.erase(iWB, iWE);
		}
		*sW = 0;
	}
}