/**
* @file			1.cpp
* @brief		task 4.1
*				According to the input numbers n, k, A1, ..., Ak
*				determine the minimum value of binary tree search
*				for a set of keys A1, A2, ..., Ak, and the search range from 1 to n.
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

#include "DataInput.h"
#include "MinPas.h"

using namespace std;

char toLow(char code);

int * CreateP(int size);

void main(void)
{
	char c = 'o';
	int * fa = NULL;
	int * numbers = NULL;
	int * range = CreateP(1);
	if(range == NULL)
	{
		exit(EXIT_FAILURE);
	}
	*range = 0;
	int * size = CreateP(1);
	if(size == NULL)
	{
		delete range;
		exit(EXIT_FAILURE);
	}
	*size = 0;
	while(toLow(c) != 'h' && toLow(c) != 'f')
	{
		cout << "Enter 'h' - to handle enter date of 'f' - to load from file: ";
		cin >> c;
		while(cin.get() != '\n')
			;
	}
	if(toLow(c) == 'h')
	{
		AD(cin, range, size);
		numbers = CreateP(*size);
		if(size == NULL)
		{
			delete range;
			delete size;
			exit(EXIT_FAILURE);
		}
		numbers[0] = 0;
		numbers[*size - 1] = *range + 1;
		delete range;
		AN(cin, numbers, size);
	}
	else
	{
		ifstream fin;
		cout << "Enter file name: ";
		char * pF= new char[256];
		cin >> pF;
		fin.open(pF);
		if(!fin)
		{
			cout << "file can't be open!\n";
			exit(EXIT_FAILURE);
		}
		AD(fin, range, size);
		numbers = CreateP(*size);
		if(size == NULL)
		{
			delete range;
			delete size;
			exit(EXIT_FAILURE);
		}
		numbers[0] = 0;
		numbers[*size - 1] = *range + 1;
		delete range;
		AN(fin, numbers, size);
		fin.close();
	}
	fa = CreateP((*size) * (*size));
	if(fa == NULL)
	{
		delete size;
		delete [] numbers;
		exit(EXIT_FAILURE);
	}
	for(int i = 0; i < (*size) * (*size); ++i)
	{
		fa[i] = -1;
	}
	
	cout << "\nMinimum passing: " << MP(fa, numbers, 1, *size - 2, *size) << endl;
	delete size;
	delete [] numbers;
	delete [] fa;
	system("@pause");
}

int * CreateP(int size)
{
	return new int[size];
}

char toLow(char code)
{
	code |= 0x20;
	return code;
}