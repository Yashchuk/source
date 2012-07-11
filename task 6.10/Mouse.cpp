/**
* @file		Mouse.cpp
* @brief	This file contains source code of Task 6.10.
*			It contains realization of class Mouse.
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
#include "Mouse.h"
#include <stdlib.h>
#include <iostream>

const char BITS = 8;

void Mouse::Set(UI i)
{
	UC temp = 1;
	UI ct = 0;
	temp <<= (i % BITS);
	while(i > (BITS - 1) )
	{
		i -= BITS;
		++ct;
	}
	m[ct] ^= temp;
}

Mouse::Mouse(US g, US w, UI rE) : size(g + w), sE(rE)
{
	UI tmp;
	if(size % 8)
	{
		m = (UC *) malloc(size / BITS + 1);
		tmp = size / BITS + 1;
	}
	else
	{
		m = (UC *) malloc(size / BITS);
		tmp = size / BITS;
	}
	if(!m)
	{
		exit(EXIT_FAILURE);
	}
	for(UI i = 1; i < tmp; ++i)
	{
		m[i] = 0;
	}
	m[0] = 1;
}

bool Mouse::Order(US g, US aG)
{
	--g;
	--aG;
	for( UI i = 0; i < sE; ++i)
	{
		if( !iE[i] )
		{
			++aG;
			i = sE;
		}
	}
	if(aG > g)
	{
		return false;
	}
	bool ok;
	for( UI i = 1; g; ++i )
	{
		ok = true;
		for( UI c = 0; c < sE && ok; ++c )
		{
			if( i == iE[c] )
			{
				ok = false;
			}
		}
		if( ok && aG )
		{
			Set(i);
			--aG;
			--g;
		}
		else if( aG < g && !ok)
		{
			Set(i);
			--g;
		}
	}
	return true;
}

bool Mouse::operator[](UI i) const
{
	return (bool)( *(m + i / BITS) & (1 << (i % BITS) ) );
}

Mouse::~Mouse()
{
	if( m )
	{
		free(m);
		m = NULL;
	}
	if( iE )
	{
		free(iE);
		iE = NULL;		
	}
}

void Mouse::EI(UI n)
{
	iE = (UI *) malloc( sizeof(UI) * sE);
	UI rE = sE;
	UI ts = size;
	for(UI ct = 0, i = 0; rE; ++ct)
	{
		i += n - 1;
		while(ts <= i)
		{
			i -= ts;
		}
		iE[ct] = i;
		--ts;
		if(i > ts)
		{
			i = 0;
		}
		--rE;
	}
}

void Mouse::BIE()
{
	UI * tmp = (UI *) malloc( sizeof(UI) * sE);
	memmove(tmp, iE, sizeof(UI) * sE);
	for( UI i = 0, ct; i < sE; ++i )
	{
		if( i )
		{
			ct = 0;
			for( UI c = 0; c < i; ++c )
			{
				if( tmp[c]  <= tmp[i] )
				{
					++ct;
				}
			}
			iE[i] = tmp[i] + ct;
		}
	}
	free(tmp);
}

void Mouse::Show() const
{
	for(UI i = 0; i < size; ++i)
	{
		std::cout << operator[](i) << ' ';
	}
	std::cout << std::endl;
}