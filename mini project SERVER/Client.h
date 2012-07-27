
#ifndef CONNECT_H_
#define CONNECT_H_

#include <WinSock.h>
#include <iostream>

/**
* @class	Client
* @brief	This class realize client.
*
* Copyright 2012 by Oleg Kiss,
* 
* This software is confidental and proprietary information
* of Oleg Kiss. You shall not disclose such
* confidental information and shall use it only in
* accordance with terms of the license agreement
* you entered into with Oleg Kiss.
*/

class Client
{
private:
	SOCKET sC;
	sockaddr_in aC;
	int sizeAC;
	Client(const Client & c) {}
	Client & operator=(const Client & c) {}
public:
	Client();

	/*
	* @brief	This method return reference by Socket
	* return	SOCKET &
	*/

	SOCKET & GetSC();

	/*
	* @brief	This method return Socket
	* return	SOCKET
	*/

	SOCKET GetSCL() const;

	/*
	* @brief	This method return pointer to struct sock_addr
	* return	sockaddr_in *
	*/

	sockaddr_in * GetSA();

	/*
	* @brief	This method return size of sockaddr_in
	* return	int * 
	*/

	int * GetSizeSA();

	/*
	* @brief	This method close socket
	* return	void 
	*/

	void CloseSock();
	~Client();
};

#endif