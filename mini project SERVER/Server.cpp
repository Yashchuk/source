#include "stdafx.h"
#include "Server.h"

#pragma comment(lib,"ws2_32.lib")

Server::Server()
{
	if ( WSAStartup(MAKEWORD(Ver,Ver), &wsadata) != 0 )
	{
		WSACleanup();
		std::cout << "ERROR WSASTARTUP" << std::endl;
		throw 1;
	}
	if ( (sS = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP) ) == INVALID_SOCKET )
	{
		std::cout << "ERROR SERVER SOCKET" << std::endl;
		throw 1;
	}
	char * pHN;
	pHN = new char[1024]; 
	if( !pHN )
	{
		throw 1;
	}
	char * host = new char [17];
	if( !host )
	{
		delete [] pHN;
		throw 1;
	}
	if(!gethostname(pHN, 1024)) // host name  
	{
		if(LPHOSTENT lphost = gethostbyname(pHN)) // host IP
		{
			memcpy( host,inet_ntoa( *( ( in_addr * )lphost->h_addr_list[0] ) ), 17 );
		}
	}  
	serv.sin_family = AF_INET;
	serv.sin_port = htons(7500);
	serv.sin_addr.s_addr = inet_addr(host);
	delete [] pHN;
	delete [] host;
	size = sizeof(serv);
	std::cout << "WSASTARTUP & SOCKET INITIALIZATION WAS GOOD" << std::endl;
}

bool Server::Binding()
{
	if ( bind(sS, (sockaddr* ) &serv, size ) != 0 )
	{
		std::cout << "ERROR binding" << std::endl;
		return false;
	}
	return true;
}

bool Server::Listing()
{
	if( (listen(sS, 1) ) != 0 )
	{
		return false;
		std::cout << "ERROR listen" << std::endl;
	}
	return true;
}

void Server::Accept(Client * cl)
{
	std::cout << "Waiting accept... " << std::endl;
	cl->GetSC() = accept(sS, (sockaddr *)cl->GetSA(), cl->GetSizeSA());
}

Server::~Server()
{
	closesocket(sS);
	WSACleanup();
}