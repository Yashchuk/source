/**
* @file		Coins.h
* @brief	This file contains source code of Task 6.8.
*			It contains declarations of class Coins.
*
* Copyright 2012 by Oleg Kiss,
*
* This software is confidental and proprietary information
* of Oleg Kiss. You shall not disclose such
* confidental information and shall use it only in
* accordance with terms of the license agreement
* you entered into with Oleg Kiss.
*/

#ifndef COINS_H_
#define COINS_H_

typedef unsigned int UI;

typedef unsigned char UC;

/**
* @class	Coins
* @brief	This class realize Coins. This class stores the 
*			state of all the coins and the number of coins
*
* Copyright 2012 by Oleg Kiss,
* 
* This software is confidental and proprietary information
* of Oleg Kiss. You shall not disclose such
* confidental information and shall use it only in
* accordance with terms of the license agreement
* you entered into with Oleg Kiss.
*/

class Coins
{
private:
	UC * c;								/*pointer to array*/
	UI size;							/*average coins*/
	void CV(UI i);						/*change value*/
	UI CB() const;						/*Count significant bits*/
	Coins(const Coins & s) {};
	Coins & operator=(const Coins & s) {};
public:
	Coins(UI t, UI e);
	UI Size() const;

	/*
	* @brief	This method does number of moves (m)
	* @param	[in]		m - number of moves
	* return	void
	*/

	void Move(UI m);								

	/*
	* @brief	This method return 1 if possible the combination of coins
	*			and 0 in other 
	* @param	[in]		m - number of moves
	* @param	[in]		e - number of up arms coins in start
	* @param	[in]		rE - number of up arms coins in end
	* return	bool
	*/

	bool Order(UI m, UI e, UI rE);			

	/*
	* @brief	This method returns 1 if the data that is on this index is 1,
	*			and 0 if the data that is on this index is 0.
	* @param	[in]		i - index
	* return	int
	*/

	bool operator[](UI i) const;
	~Coins();
};

#endif