#include "stdafx.h"
#include "ClassServer.h"
#include <fstream>
//#include <iostream>

using namespace std;

Server::Server() : sS(INVALID_SOCKET)
{}

bool Server::WsaStart(unsigned int bLow, unsigned int bHigh)
{
	if( WSAStartup( MAKEWORD( bLow, bHigh), &wsadata) != NULL )
	{
		return false;
	}
	return true;
}

bool Server::InitSA(const char * fileName)
{
	ifstream fin;
	fin.open(fileName, ios_base::in );
	if( !fin.is_open() )
	{
		closesocket(sS);
		sS = INVALID_SOCKET;
		WSACleanup();
		return false;
	}
	char * p;
	char * ip = (char *) malloc(MAX_IP); 
	if( !ip )
	{
		closesocket(sS);
		WSACleanup();
		return false;
	}
	US port;
	fin >> port;
	fin.get();
	fin.read( ip, MAX_IP );
	p = ip + 15;
	while( !( *p >= '0' && *p <= '9' ) )
	{
		--p;
	}
	*(++p) = '\0';
	realloc(ip, p - ip + 1);
	sa.sin_family = AF_INET;
	sa.sin_port = htons(port);
	sa.sin_addr.S_un.S_addr = inet_addr(ip);
	free(ip);
	return true;
}

bool Server::InitS()
{
	if( ( sS = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP) ) == INVALID_SOCKET )
	{
		WSACleanup();
		return false;
	}
	return true;
}

bool Server::Binding()
{
	if( bind( sS, (sockaddr *) &sa, sizeof(sa) ) == SOCKET_ERROR )
	{
		closesocket(sS);
		sS = INVALID_SOCKET;
		WSACleanup();
		return false;
	}
	return true;
}

bool Server::Listen()
{
	if( listen( sS, 10 ) == SOCKET_ERROR )
	{
		closesocket(sS);
		sS = INVALID_SOCKET;
		WSACleanup();
		return false;
	}
	return true;
}

SOCKET Server::GetSock() const
{
	return sS;
}

Server::~Server()
{
	if( sS != INVALID_SOCKET )
	{
		closesocket(sS);
	}
}

US Server::GetPort() const
{
	return sa.sin_port;
}

unsigned long Server::GetIP() const
{
	return (unsigned long)sa.sin_addr.S_un.S_addr;
}