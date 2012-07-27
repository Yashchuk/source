
#include "stdafx.h"
#include "SAddr.h"

SAddr::SAddr()
{
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
			strcpy( host,inet_ntoa( *( ( in_addr * )lphost->h_addr_list[0] ) ) );  
		}
	}  
	serv.sin_family = AF_INET;
	serv.sin_port = htons(7500);
	serv.sin_addr.s_addr = inet_addr(host);
	delete [] pHN;
	delete [] host;
}

sockaddr_in * SAddr::GetSA()
{
	return &serv;
}

int SAddr::Size() const
{
	return sizeof(serv);
}

SAddr::~SAddr()
{
	std::cout << "SAddr Destruct" << std::endl;
}