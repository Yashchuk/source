/**
* @file			P_server mini project (task 9)
* 
* Copyright 2012 by Oleg Kiss,
*
* This software is confidental and proprietary information
* of Oleg Kiss. You shall not disclose such
* confidental information and shall use it only in
* accordance with terms of the license agreement
* you entered into with Oleg Kiss.
*/

#include "stdafx.h"
#include <Windows.h>
#include <WinSock.h>
#include "InfCh.h"
#include <iostream>

using namespace std;

#pragma comment(lib,"ws2_32.lib")

/*
* @brief	This function return little letter
* return	int * 
*/

char ToLow(char s)
{
	s |= 0x20; 
	return s;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Keys * pK = new Keys;
	cout << "D: " << pK->GetD() << endl;
	cout << "E: " << pK->GetE() << endl;
	cout << "N: " << pK->GetN() << endl;
	Server * pSer;
	try
	{
		pSer = new Server;
	}
	catch(...)
	{
		delete pK;
		exit(EXIT_FAILURE);
	}
	if( !(pSer->Binding() ) )
	{
		delete pK;
		delete pSer;
		exit(EXIT_FAILURE);
	}
	if( !(pSer->Listing() ) )
	{
		delete pK;
		delete pSer;
		exit(EXIT_FAILURE);
	}
	Client * pCl;
	try
	{
		pCl = new Client;
	}
	catch(...)
	{
		delete pK;
		delete pSer;
		exit(EXIT_FAILURE);
	}
	char con = 'y';
	while('y' == ToLow(con))
	{
		pSer->Accept(pCl);
		InfCh * pIC;
		try
		{
			pIC = new InfCh;
		}
		catch(...)
		{
			delete pK;
			delete pCl;
			delete pSer;
			exit(EXIT_FAILURE);
		}
		pIC->SendKey(pCl, pK);
		while( pIC->PathRec(pCl) )
		{
			while( !pIC->CreatePath() )
			{
				/*NULL*/
			}
			pIC->Ready(pCl);
			if( !pIC->SizeRec(pCl) )
			{
				delete pIC;
				pCl->CloseSock();
				break;
			}
			pIC->Ready(pCl);
			if( pIC->DataRec(pCl, pK) )
			{
				continue;
			}
			else
			{
				break;
			}
		}
		delete pIC;
		pCl->CloseSock();
		cout << "Do you want continue? Y " << endl;
		cin >> con;
	}
	delete pK;
	delete pCl;
	delete pSer;
	return 0;
}
