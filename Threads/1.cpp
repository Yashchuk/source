/**
* @file			1.cpp
* @brief		task Threads
*				The Main Thread is the manager, one of the threads generate "gen" 1000 numbers, 
*				after "gen" was generated 1000 numbers, thread "sort" sorts that numbers after thread "gen"
*				generate new 1000 numbers and add it to old numbers, after thread "sort" sorts 2000 numbers...
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
#include <iostream>
#include <fstream>
#include <ctime>
#include <list>

using namespace std;

typedef unsigned int UI;

const UI MAX = 10000;

const UI SWITCH = 100;

/*
* @brief	This thread function sort numbers
* @param	[in, out]	wmParam - some container
* return	DWORD
*/

DWORD WINAPI Sorting(void * wmParam);

/*
* @brief	This thread function generate 10000 numbers
* @param	[in, out]	wmParam - some container
* return	DWORD
*/

DWORD WINAPI Generic(void * wmParam);

/*
* @brief	This thread function write to the file numbers
* @param	[in, out]	wmParam - some container
* return	DWORD
*/

DWORD WINAPI Show(void * wmParam);

HANDLE hMG,			/*handle mutex gen*/
		hMS;		/*handle mutex sort*/

int _tmain(int argc, _TCHAR* argv[])
{
	srand( time(0) );
	HANDLE hTG,		/*Handle gen thread*/
		hTS;		/*Handle sort thread*/
	DWORD code;
	hMG = CreateMutex( NULL, true, NULL );
	if( !hMG )
	{
		return -1;
	}
	hMS = CreateMutex( NULL, true, NULL );
	if( !hMS )
	{
		return -1;
	}
	list<int> MyL;
	hTG = CreateThread( NULL, NULL, &Generic, (void *) &MyL, NULL, NULL );
	if( !hTG )
	{
		return -1;
	}	
	hTS = CreateThread( NULL, NULL, &Sorting, (void *) &MyL, NULL, NULL );
	if( !hTS )
	{
		CloseHandle( hTG );
		return -1;
	}	
	for( UI i = 0; i < SWITCH; ++i)
	{
		ReleaseMutex(hMG);
		SwitchToThread();
		WaitForSingleObject(hMG, INFINITE);
		ReleaseMutex(hMS);
		SwitchToThread();
		WaitForSingleObject(hMS, INFINITE);
	}
	ReleaseMutex(hMS);
	WaitForSingleObject(hMS, INFINITE);
	HANDLE hS = CreateThread( NULL, NULL, &Show, (void *) &MyL, NULL, NULL );
	WaitForSingleObject(hS, INFINITE);
	CloseHandle( hTG );
	CloseHandle( hTS );
	CloseHandle( hMG );
	CloseHandle( hMS );
	CloseHandle( hS );
	return 0;
}

DWORD WINAPI Sorting(void * wmParam)
{
	list<int> * pL = (list<int> *) wmParam;
	while( 1 )
	{
		WaitForSingleObject(hMS, INFINITE);
		if( MAX == pL->size() )
		{
			break;
		}
		pL->sort();
		ReleaseMutex( hMS );
		SwitchToThread();
	}
	pL->sort();
	ReleaseMutex( hMS );
	return 0;
}

DWORD WINAPI Generic(void * wmParam)
{
	list<int> * pL = (list<int> *) wmParam;
	int * buff;
	try
	{
		buff = new int[SWITCH];
	}
	catch( std::bad_alloc )
	{
		return -1;
	}
	for( UI ct = 0; ct < SWITCH; ++ct )
	{
		WaitForSingleObject(hMG, INFINITE);
		for( UI i = 0; i < SWITCH; ++i )
		{
			buff[i] = rand() % 10000 + 1;
		}
		for( UI i = 0; i < SWITCH; ++i )
		{
			pL->push_back(buff[i]);
		}
		ReleaseMutex(hMG);
		SwitchToThread();
	}
	delete []buff;
	return 0;
}

DWORD WINAPI Show(void * wmParam)
{
	ofstream fout;
	fout.open("1.txt");
	list<int> * pL = (list<int> *) wmParam;
	fout << "size: " << pL->size() << '\n';
	fout.flush();
	UI ct = 0;
	for( auto i = pL->begin(); i != pL->end(); ++i, ++ct )
	{
		fout << *i << '\n';
		if( !(ct % 100) )
		{
			fout.flush();
		}
	}
	fout.close();
	return 0;
}