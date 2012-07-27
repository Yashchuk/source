#include "stdafx.h"
#include "Client.h"

Client::Client()
{
	sizeAC = sizeof(aC);
}

sockaddr_in * Client::GetSA()
{
	return &aC;
}

int * Client::GetSizeSA()
{
	return &sizeAC;
}

SOCKET & Client::GetSC()
{
	return sC;
}

SOCKET Client::GetSCL() const
{
	return sC;
}

void Client::CloseSock()
{
	closesocket(sC);
}

Client::~Client()
{
	closesocket(sC);
}
