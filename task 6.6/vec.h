/**
* @file		Vec.h
* @brief	This file contains source code of Task 6.6.
*			It contains declarations of class Vector.
*
* Copyright 2012 by Oleg Kiss,
*
* This software is confidental and proprietary information
* of Oleg Kiss. You shall not disclose such
* confidental information and shall use it only in
* accordance with terms of the license agreement
* you entered into with Oleg Kiss.
*/

#ifndef VEC_H_
#define VEC_H_

/**
* @class	MyStack
* @brief	This class realize vector.
*
* Copyright 2012 by Oleg Kiss,
* 
* This software is confidental and proprietary information
* of Oleg Kiss. You shall not disclose such
* confidental information and shall use it only in
* accordance with terms of the license agreement
* you entered into with Oleg Kiss.
*/

class Vector
{
private:
	int * num;						/*array of number of human*/
	int size;						/*size of array*/
	Vector(const Vector & v) {};
	Vector & operator=(const Vector & v) {};
public:
	Vector() {size = 0;}
	~Vector();

	/*
	* @brief	This method add back new ellement
	* return	void
	*/

	void PushBack(int n);

	/*
	* @brief	This method erase some element
	* return	void
	*/

	void Erase(int i);

	/*
	* @brief	This method returns the data that is on this index
	* @param	[in]		i - index
	* return	int
	*/

	int operator[](int i) const;

	/*
	* @brief	This method give the data that is on this index
	* @param	[in]		i - index
	* return	int
	*/

	int & operator[](int i);
};

#endif /*VEC_H_*/