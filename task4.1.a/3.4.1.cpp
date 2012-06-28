/**
* @file			task4.1.cpp
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
#include "BinTree.h"

using namespace std;

/*Max length of file name*/
const unsigned short MAX_FN = 256;

/*
* @brief	This function sort array in ascending order 
* @param	[in,out]		ar - array
* @param	[in]			size - size of array
* return	void
*/

void sort(int * ar, int size);

/*
* @brief	This function allocates memory
* @param	[in]			size - how much memory  must be allocate
* return	int *			pointer to the allocated memory
*/

int * CreateP(int size);

/*
* @brief	This function make the letter in lower case
* @param	[in]			code - letter
* return	char			letter in lower case
*/

char toLow(char code);

/*Написати:
3. Коментарі
*/

int _tmain(int argc, _TCHAR* argv[])
{
	char c = 'o';				/*choice to enter data handle or from file*/
	int * numbers = NULL;		/*array*/
	int * nums = CreateP(1);	/*how much nums must be in tree*/
	/*test or separated memory*/
	if(nums == NULL)
	{
		exit(EXIT_FAILURE);
	}
	int * range = CreateP(1);	
	if(range == NULL)
	{
		exit(EXIT_FAILURE);
	}
	*range = 0;
	while(toLow(c) != 'h' && toLow(c) != 'f')
	{
		cout << "Enter 'h' - to handle enter date of 'f' - to load from file: ";
		cin >> c;
		while(cin.get() != '\n')
			;
	}
	if(toLow(c) == 'h')
	{
		AD(cin, range, nums);
		numbers = CreateP(*nums + 2);
		if(numbers == NULL)
		{
			delete range;
			delete nums;
			exit(EXIT_FAILURE);
		}
		numbers[0] = 0;
		numbers[*nums + 1] = *range + 1;
		AN(cin, numbers, *nums, *range);
		delete range;
	}
	else
	{
		ifstream fin;
		cout << "Enter file name: ";
		char * pF= new char[MAX_FN];
		cin >> pF;
		fin.open(pF);
		if(!fin)
		{
			cout << "file can't be open!\n";
			exit(EXIT_FAILURE);
		}
		AD(fin, range, nums, 0);
		numbers = CreateP(*nums + 2);
		if(nums == NULL)
		{
			delete range;
			delete nums;
			exit(EXIT_FAILURE);
		}
		numbers[0] = 0;
		numbers[*nums + 1] = *range + 1;
		AN(fin, numbers, *nums, *range, 0);
		delete range;
		fin.close();
	}
	sort(numbers + 1, *nums);
	/*Create root node*/
	BinTree * root = NULL;
	BinTree node;
	int index = RootN(numbers[*nums + 1], numbers);
	node.val = numbers[index];
	root = Insert(root, &node);
	/*Create all nodes*/
	CrtTr(numbers, root, &node, *nums + 1, 0, index);
	int MP = 0;				/*min path*/
	for(int i = 1; i < numbers[*nums + 1]; ++i)
	{
		MP += Search(root, i);
	}
	delete nums;
	delete [] numbers;
	delete [] Del(root);
	cout << "Minimal path: " << MP << endl;
	system("@pause");
	return 0;
}

void sort(int * ar, int size)
{
	int min = 0 , temp;
	for(int j = 0; j < size; j++)
	{
		min = j;
		for(int i = j; i < size; i++)
		{
			if(ar[min] > ar[i])
			{
				min = i;
			}
		}
		temp = ar[j];
		ar[j] = ar[min];
		ar[min] = temp;
	}
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

