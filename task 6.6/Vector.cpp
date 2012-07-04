#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include "vec.h"

void Vector::PushBack(int n)
{
	if(size == 0)
	{
		if( !(num = (int *) malloc( sizeof(int) ) ) )
		{
			std::cerr << "Can't add ellements.\n";
		}
		else
		{
			++size;
			num[size - 1] = n;
		}
	}
	else
	{
		if(num = (int *) realloc(num, sizeof(int) * (size + 1) ) )
		{
			++size;
			num[size - 1] = n;
		}
		else
		{
			std::cerr << "Error memory allocation. All data are lost.\n";
			size = 0;
		}
	}
}

int Vector::operator[](int i) const
{
	if(i >= size && i < 0)
	{
		std::cerr << "Out of bount!\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		return *(num + i);
	}
}

int & Vector::operator[](int i)
{
	if(i >= size && i < 0)
	{
		std::cerr << "Out of bount!\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		return *(num + i);
	}
}

void Vector::Erase(int i)
{
	if(i < size && i > 0)
	{
		memmove(num + i, num + i + 1, sizeof(int) * (size - (i + 1) ) );
		if( num = (int *) realloc(num, sizeof(int) * (size - 1) ) )
		{
			--size;
		}
		else
		{
			std::cerr << "Error memory allocation. All data are lost.\n";
			size = 0;
		}
	}
	else
	{
		std::cerr << "This vector haven't so many elements.\n";
	}
}

Vector::~Vector()
{
	if(size)
	{
		free(num);
	}
}