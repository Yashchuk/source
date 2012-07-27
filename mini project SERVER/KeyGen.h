
#ifndef KEYGEN_H_
#define KEYGEN_H_

#include <iostream>

typedef unsigned short US;
typedef unsigned char UC;

/**
* @class	Keys
* @brief	This class realize generation of keys.
*
* Copyright 2012 by Oleg Kiss,
* 
* This software is confidental and proprietary information
* of Oleg Kiss. You shall not disclose such
* confidental information and shall use it only in
* accordance with terms of the license agreement
* you entered into with Oleg Kiss.
*/

class Keys
{
private:
	US n, e;
	UC d;
	Keys(const Keys & k) {}
	Keys & operator=(const Keys & k) {}

	/*
	* @brief	This method return loacal time milisseconds
	* return	unsigned short
	*/

	US Random();

	/*
	* @brief	This method realize the sieve of Sundaram and return 
	*			the nearest simple number to in param
	* @param	[in]		n - number
	* return	unsigned char
	*/

	UC sundaram(UC n);

	/*
	* @brief	This method returns greatest common divisor
	* @param	[in]		m - number
	* @param	[in]		n - number
	* return	unsigned short
	*/

	US GCD(UC m, US n);

	/*
	* @brief	This method returns open exponents (modular inverse)
	* @param	[in]		d - secret exponnent
	* @param	[in]		n - one of the key components
	* return	unsigned short
	*/

	US ModInv(US d, US fn);
public:
	Keys();

	/*
	* @brief	This method returns open exponents
	* return	unsigned short
	*/

	US GetE() const;

	/*
	* @brief	This method returns one of the key components (p * q)
	* return	unsigned short
	*/

	US GetN() const;

	/*
	* @brief	This method returns secret exponents
	* return	unsigned short
	*/

	US GetD() const;
	~Keys();
};

#endif