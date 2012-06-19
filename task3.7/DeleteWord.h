/**
* @file		DeleteWord.h
* @brief	This file contains source code of Task 3.7.
*			It contains  declarations of SearchWord, DelWord functions.
*
* Copyright 2012 by Oleg Kiss,
*
* This software is confidental and proprietary information
* of Oleg Kiss. You shall not disclose such
* confidental information and shall use it only in
* accordance with terms of the license agreement
* you entered into with Oleg Kiss.
*/

#ifndef DELETEWORD_H_
#define DELETEWORD_H_

#include <iostream>
#include <string>

typedef unsigned short US;

/**
* @brief	This function search words to be delete
* @param	[in, out]			instr - input string
* @param	[in]				fWord - number of the first word to be delete
* @param	[in]				sWord - number of the second word to be delete
* return	void
*/

void SearchWord(std::string & instr, US fWord, US sWord);

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

void DelWord(US ct, US wB, US wE, US * fW, US * sW, std::string & instr);

#endif  /*DELETEWORD_H_*/