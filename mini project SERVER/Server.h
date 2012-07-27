
#ifndef SERVER_H_
#define SERVER_H_

#include <WinSock.h>
#include "Client.h"
#include <iostream>

/**
* @class	Server
* @brief	This class realize initialization wsadata and server socket.
*
* Copyright 2012 by Oleg Kiss,
* 
* This software is confidental and proprietary information
* of Oleg Kiss. You shall not disclose such
* confidental information and shall use it only in
* accordance with terms of the license agreement
* you entered into with Oleg Kiss.
*/

class Server
{
private:
	enum {Ver = 2};
	WSADATA wsadata;
	SOCKET sS;
	sockaddr_in serv;
	unsigned int size;
	Server(const Server & ss) {}
	Server & operator=(const Server & ss) {}
public:
	Server();

	/*
	* @brief	This method binding socket
	* return	bool
	*/

	bool Binding();

	/*
	* @brief	This method listen socket
	* return	bool
	*/

	bool Listing();

	/*
	* @brief	This method wait connect
	* return	bool
	*/

	void Accept(Client * cC);
	~Server();
};

#endif