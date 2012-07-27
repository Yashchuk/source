#ifndef INFCH_H_
#define INFCH_H_

#include "Server.h"
#include "KeyGen.h"
#include <iostream>

/**
* @class	InfCh
* @brief	This class realize communication with the client.
*
* Copyright 2012 by Oleg Kiss,
* 
* This software is confidental and proprietary information
* of Oleg Kiss. You shall not disclose such
* confidental information and shall use it only in
* accordance with terms of the license agreement
* you entered into with Oleg Kiss.
*/

class InfCh
{
private:
	enum {MAX_DATA = 65514};
	char * buf;
	wchar_t * path;
	union 
	{
		char cfs[sizeof(DWORD)];
		DWORD64 dfs;

	} fsu;
	unsigned short b_recv;
	InfCh(const InfCh & ic) {}
	InfCh & operator=(const InfCh & ic) {}

	/*
	* @brief	This method decrypt data (RSA)
	* @param	[in]		val - data
	* @param	[in]		d - exponent
	* @param	[in]		n - one of the key components
	* return	unsigned char
	*/

	unsigned char Decrypt(unsigned short val, unsigned short d, unsigned short n);

public:
	InfCh();

	/*
	* @brief	This method receive path to file
	* return	bool
	*/

	bool PathRec(Client * cl);

	/*
	* @brief	This method create folders
	* return	bool
	*/

	bool CreatePath() const;

	/*
	* @brief	This method receive size
	* return	bool
	*/

	bool SizeRec(Client * cl);

	/*
	* @brief	This method receive data
	* return	bool
	*/

	bool DataRec(Client * cl, Keys * k);

	/*
	* @brief	This method send 1 to client (this means ready to receive next data)
	* return	void
	*/

	void Ready(Client * cl);

	/*
	* @brief	This method send to client open keys
	* return	void
	*/

	void SendKey(Client * cl, Keys * k) const;
	~InfCh();
};

#endif