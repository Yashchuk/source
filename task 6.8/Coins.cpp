/**
* @file		Coins.cpp
* @brief	This file contains source code of Task 6.8.
*			It contains realization of class Coins.
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
#include "Coins.h"
#include <stdlib.h>
#include <iostream>

const char BITS = 8;

const char MOVE = 5;

Coins::Coins(UI t, UI e) : size(t + e)
{
	UI tmp;
	if(size % 8)
	{
		c = (UC *) malloc(size / BITS + 1);
		tmp = size / BITS + 1;
	}
	else
	{
		c = (UC *) malloc(size / BITS);
		tmp = size / BITS;
	}
	for(UI i = 1; i < tmp; ++i)
	{
		c[i] = 0;
	}
	c[0] = 1;
}

void Coins::CV(UI i)
{
	UC temp = 1;
	UI ct = 0;
	temp <<= (i % BITS);
	while(i > (BITS - 1) )
	{
		i -= BITS;
		++ct;
	}
	c[ct] ^= temp;
}

UI Coins::CB() const
{
	UI ct = 0;
	for(UI i = 0; i < size; ++i)
	{
		if( operator[](i) )
		{
			++ct;
		}
	}
	return ct;
}

void Coins::Move(UI m)
{
	for(UI ct = 0, ind = -1; ct < m; ++ct)
	{
		ind += MOVE;
		if(ind >= size)
		{
			ind -= size;
		}
		CV(ind);
	}
}

bool Coins::Order(UI m, UI e, UI rE)
{
	UI h = e + CB();	/*possible coins that show eagle*/
	--e;				/*how much tails change to eagle*/
	--h;				
	if(rE > h)
	{
		return false;
	}
	else if( rE == h )
	{
		for(UI i = 1; i < size; ++i)
		{
			if( operator[](i) )
			{
				CV(i);
			}
			else if(e)
			{
				CV(i);
				--e;
			}
		}
	}
	else if(rE < h)
	{
		bool ok = false;
		UC min = CB() - e;
		if( min > CB() )
		{
			min = ~min + 1;
		}
		UI miss = 0;	/*miss eagle*/
		while(h > min)
		{
			h -= 2;
			++miss;
			--e;
			if( h == rE )
			{
				ok = true;
				break;
			}

		}
		if(!ok)
		{
			return false;
		}
		else
		{
			for(UI i = 1; i < size; ++i)
			{
				if( operator[](i) && miss )
				{
					--miss;
				}
				else if( !operator[](i) && e )
				{
					CV(i);
					--e;
				}
				else if( operator[](i) )
				{
					CV(i);
				}
			}
		}
	}
	c[0] |= 1;
	return true;
}

bool Coins::operator[](UI i) const
{
	return ( *(c + i / BITS) & (1 << (i % BITS) ) );
}

UI Coins::Size() const
{
	return size;
}

Coins::~Coins()
{
	free(c);
	c = NULL;
}