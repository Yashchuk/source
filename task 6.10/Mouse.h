/**
* @file		Mouse.h
* @brief	This file contains source code of Task 6.10.
*			It contains declarations of class Mouse.
*
* Copyright 2012 by Oleg Kiss,
*
* This software is confidental and proprietary information
* of Oleg Kiss. You shall not disclose such
* confidental information and shall use it only in
* accordance with terms of the license agreement
* you entered into with Oleg Kiss.
*/

#ifndef MOUSE_H_
#define MOUSE_H_

typedef unsigned int UI;

typedef unsigned short US;

typedef unsigned char UC;

class Mouse
{
private:
	UI size;					/*average mice*/
	UC * m;						/*pointer to array*/
	UI * iE;					/*ate index*/
	UI sE;

	/*
	* @brief	This method set grey mouse (1) in some index
	* @param	[in]		i - index of array
	* return	void
	*/	

	void Set(UI i);

	Mouse(const Mouse & M) {}
	Mouse & operator=(const Mouse & M) {}
public:
	Mouse(US g, US w, UI rE);

	/*
	* @brief	This method return 1 if possible the combination of mice
	*			and 0 in other 
	* @param	[in]		g - number of grey mice
	* @param	[in]		aG - number of grey mice after diner
	* return	bool
	*/

	bool Order(US g, US aG);

	/*
	* @brief	This method returns 1 if the data that is on this index is 1,
	*			and 0 if the data that is on this index is 0.
	* @param	[in]		i - index
	* return	bool
	*/

	bool operator[](UI i) const;

	~Mouse();

	/*
	* @brief	This method determines which indexes ate mice
	* @param	[in]		n - each mouse
	* return	void
	*/

	void EI(UI n);

	/*
	* @brief	This method determines which begin indexes ate mice
	* return	void
	*/

	void BIE();

	/*
	* @brief	This method show order of mice
	* return	void
	*/

	void Show() const;
};

#endif