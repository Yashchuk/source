
#include "stdafx.h"
#include "DataInput.h"

const int MAX_VAL = 1000000000;

void AN(std::istream & is, int * num, int * size)
{
	for(int i = 1; i < *size - 1; ++i)
	{
		std::cout << "Enter number (must be > 0 and <= " << MAX_VAL << "): ";
		is >> num[i];
		while( !(num[i] > 0) )
		{
			if(!is)
			{
				is.clear();
				while(is.get() != '\n')
				{
					/*NULL*/
				}
			}
			is >> num[i];
			if( !(num[i] > 0) )
			{
				std::cout << "Re-enter: ";
			}
		}
	}
}

void AD(std::istream & is, int * range, int * size)
{
		std::cout << "Enter maximal search value (must be > 0): ";
		while( !(*range > 0) )
		{
			if(!is)
			{
				is.clear();
				while(is.get() != '\n')
				{
					/*NULL*/
				}
			}
			is >> *range;
			if( !(*range > 0) )
			{
				std::cout << "Re-enter: ";
			}
		}
		std::cout << "Enter how much number (must be > 0 and <= " << *range << "): ";
		while( !(*size > 0) )
		{
			if(!is)
			{
				is.clear();
				while(is.get() != '\n')
				{
					/*NULL*/
				}
			}
			is >> *size;
			if( !(*size > 0) )
			{
				std::cout << "Re-enter: ";
			}
		}
		*size += 2;
}