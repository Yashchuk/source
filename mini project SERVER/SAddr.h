#ifndef SADDR_H_
#define SADDR_H_

#include <WinSock.h>
#include <iostream>

/**
* @class	SAddr
* @brief	This class fill struct sockaddr_in to server.
*
* Copyright 2012 by Oleg Kiss,
* 
* This software is confidental and proprietary information
* of Oleg Kiss. You shall not disclose such
* confidental information and shall use it only in
* accordance with terms of the license agreement
* you entered into with Oleg Kiss.
*/

class SAddr
{
private:
	sockaddr_in serv;
	SAddr(const SAddr & sa) {}
	SAddr & operator=(const SAddr & sa) {}
public:
	SAddr();

	/*
	* @brief	This method return pointer to sockaddr_in
	* return	pointer to sockaddr_in
	*/

	sockaddr_in * GetSA();

	/*
	* @brief	This method return size of struct sockaddr_in
	* return	int
	*/

	int Size() const;
	virtual ~SAddr();
};

#endif