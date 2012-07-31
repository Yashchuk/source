/**
* @file		Cards.h
* @brief	This file contains source code of Task 6.9.
*			It contains declarations of class Cards.
*
* Copyright 2012 by Oleg Kiss,
*
* This software is confidental and proprietary information
* of Oleg Kiss. You shall not disclose such
* confidental information and shall use it only in
* accordance with terms of the license agreement
* you entered into with Oleg Kiss.
*/

#ifndef CARDS_H_
#define CARDS_H_

typedef unsigned int UI;

class Cards
{
private:
	enum {BITS = 8};
	UI b;								/*black cards*/
	UI w;								/*white cards*/
	UI s;								/*average cards*/
	char * deck;						/*deck of cards*/
	Cards(const Cards & c);
	Cards & operator=(const Cards & c);

	/*
	* @brief	This method exponentiat 2 to exponent e and return result
	* @param	[in]		e - exponent
	* return	UI
	*/

	UI Pow2(UI e);
	/*
	* @brief	This method set black cards (1) in some index
	* @param	[in]		i - index of array
	* return	bool
	*/	

	bool Set(UI i);
public:
	explicit Cards(UI b, UI w);

	/*
	* @brief	This method set cards in some order
	* return	bool
	*/

	bool DO();

	/*
	* @brief	This method return bits of index
	* @param	[in]		i - index of array
	* return	bool
	*/

	bool operator[](UI i);
	~Cards();
};

#endif /*CARDS_H_*/