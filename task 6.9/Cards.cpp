
#include "stdafx.h"
#include <memory.h>
#include "Cards.h"

Cards::Cards(UI b, UI w) : b(b), w(w), s(w + b)
{
	UI tmp = ( ( (b + w) / BITS) + (bool)( (b + w) % BITS) );		/*how much bites alloc*/
	deck = new char[tmp];
	if( !deck )
	{
		throw 1; 
	}
	memset(deck, 0, tmp);
}

bool Cards::operator[](UI i)
{
	return (bool)( *(deck + i / BITS) & (1 << (i % BITS) ) );
}

bool Cards::Set(UI i)
{
	if( (i) > ( s - 1) )
	{
		return false;
	}
	deck[i / BITS] |= ( 1 << ( i % BITS ) );
	return true;
}

bool Cards::DO()
{
	UI sum = s / 2;
	if( !( ( w == sum ) || 
		( ( w == ( sum ) ) && ( b == ( sum + 1 ) ) ) ||
		( ( b == ( sum ) ) && ( w == ( sum + 1 ) ) ) ) )
	{
		return false;
	}
	UI wt = w, 
		bl = b, 
		ct,
		sc;
	bool lb = false;
	if( wt > bl )
	{
		lb = true;
	}
	for(UI i = 0; bl; ++i)
	{
		sum = s - Pow2(i) + 1;  /*sum = s - (start next minimal position)*/
		sc = ( sum / ( Pow2(i + 1) ) ) + (bool)( sum % ( Pow2(i + 1) ) );
		/*begin white card*/
		if( lb )
		{
			/*end white card*/
			if( sc % 2 )
			{
				wt = wt - sc / 2 -  1;
				lb = false;
			}
			/*end black card*/
			else
			{
				wt = wt - sc / 2;
				lb = true;
			}
			bl = bl - sc / 2;
			ct = Pow2(i) + Pow2( i + 1 ) - 1;
		}
		/*begin black card*/
		else
		{
			/*end black card*/
			if( sc % 2 )
			{
				bl = bl - sc / 2 - 1;
				lb = true;
			}
			/*end white card*/
			else
			{
				bl = bl - sc / 2;
				lb = false;
			}
			wt = wt - sc / 2;
			ct = Pow2(i) - 1;
		}
		for(; ct < s; ct += Pow2(i + 2) )
		{
			Set(ct);
		}
	}
	return true;
}

Cards::~Cards()
{
	delete [] deck;
}

UI Cards::Pow2(UI e)
{
	if( !e )
	{
		return 2 >> 1;
	}
	else if ( e == 1 )
	{
		return 2;
	}
	else
	{
		return ( 2 << ( e - 1 ) );
	}
}