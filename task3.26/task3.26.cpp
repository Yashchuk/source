/**
* @file			task3.26
* @brief		Develop a function that performs one-dimensional 
*				array sorting integers in descending order. Based
*				on the developed functions to sort in descending order
*				of values ​​of the elements of each row of the matrix 
*				imposed by the integers.
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
#include "Sorting.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Show(SI ** M, SI rows, SI columns);

int _tmain(int argc, _TCHAR* argv[])
{
	SI rows = 0, columns = 0;
	while(rows < 1)
	{
		if(!cin)
		{
			cin.clear();
			while(cin.get() != '\n')
			{
				/*NULL*/
			}
		}
		cout << "Enter the dimension of the matrix. Enter the number of rows ( > 0): ";
		cin >> rows;
	}
	while(cin.get() != '\n')
	{
		/*NULL*/
	}
	while(columns < 1)
	{
		if(!cin)
		{
			cin.clear();
			while(cin.get() != '\n')
			{
				/*NULL*/
			}
		}
		cout << "Enter the number of columns ( > 0): ";
		cin >> columns;
	}
	while(cin.get() != '\n')
	{
		/*NULL*/
	}
	try
	{
		SI ** M = new SI * [rows];
		for(SI i = 0; i < rows; ++i )  
		{
			M[i] = new SI [columns];
		}
		for(SI i = 0; i < rows; ++i )
		{
			for(SI j = 0; j < columns; ++j )
			{
				M[i][j] = rand();
			}
		}
		cout << "Before sorting:\n";
		Show(M, rows, columns);
		for(SI i = 0; i < rows; ++i)
		{
			Sort(M[i], columns);
		}
		cout << "After sorting:\n";
		Show(M, rows, columns);
		for(SI i = 0; i < rows; ++i)
		{
			delete []M[i];
		}
		delete [] M;
	}
	catch(bad_alloc & ba)
	{
		cout << ba.what() << endl;
		system("@pause");
		return(EXIT_FAILURE);
	}
	
	system("@pause");
	return 0;
}

void Show(SI ** M, SI rows, SI columns)
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
			std::cout << M[i][j] << '\t';
		std::cout << '\n';
	}
}