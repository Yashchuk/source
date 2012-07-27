
#include "stdafx.h"
#include "KeyGen.h"
#include <Windows.h>

US Keys::Random()
{
	SYSTEMTIME t;
	GetLocalTime(&t);
	return t.wMilliseconds;
}

UC Keys::sundaram(UC n)
{
	UC * tmp;
	tmp = new UC [n];
	if( !tmp ) 
	{
		return -1;
	}
	UC i, j, k;
	memset( tmp, 0, n );
	for( i = 1; 3 * i + 1 < n; ++i )	// цикл проходу по всьому массиву з 1
	{ 
		for( j = 1; ( k = i + j + 2 * i * j ) < n && j <= i; ++j )	// викреслювання всіх складових чисел
		{
			tmp[k] = 1;
		}
	}
	for( i = n / 2; i >= 1; --i )
	{
		if( tmp[i] == 0 )
		{
			delete [] tmp;
			return ( 2 * i + 1 );
		}
	}
}
	
US Keys::GCD(UC m, US n)
{
	UC shift;
	/* if m, n pairs, GCD(m, n) = 2 * GCD(m / 2, n / 2).*/ 
	for ( shift = 0; ( ( m | n ) & 0x1 ) == 0; ++shift ) 
        {
            m >>= 1;
            n >>= 1;
        }
 
	// If m pair, GCD(m, n) = GCD(m / 2, n).
    while ( ( m & 0x1 ) == 0 )
	{
	    m >>= 1;
	}
 
    do 
    {
		while ( ( n & 1 ) == 0 )  /* if n pair, GCD(m, n) = GCD(m, n / 2). */
		{
	        n >>= 1;
		}
	    if (m < n) /* if m, n odd and m < n, GCD(m, n) = GCD(n - m, m). */
        {
	        n -= m;
		} 
        else /* if m, n odds and m > n, GCD(m, n) = GCD(m - n, m). */
		{
			int diff = m - n;
            m = n;
            n = diff;
        }
 
		n >>= 1;
     } 
     while (n != 0);
     return m << shift;
 }

US Keys::ModInv(US d, US fn)
{
	for(US i = 1; 1; ++i)
	{
		if( ( (i * d) % fn ) == 1 )
		{
			return i;
		}
	}
}

Keys::Keys()
{
	US p, q;
	srand( Random() );
	do
	{
		while( (p = sundaram( rand() % 98 + 2 ) ) == USHRT_MAX )
		{
			/*NULL*/
		}
		while( (q = sundaram( rand() % 98 + 2 ) ) == USHRT_MAX )
		{
				/*NULL*/
		}
	}
	while( (n = p * q) <= UCHAR_MAX );
	do
	{
		d = rand() % 98 + 2;
	}
	while ( GCD (d, ( ( p - 1 ) * ( q - 1 ) ) ) != 1 );
	e = ModInv(d, ( ( p - 1 ) * ( q - 1 ) ) );
}

US Keys::GetE() const
{
	return e;
}

US Keys::GetN() const
{
	return n;
}

US Keys::GetD() const
{
	return d;
}

Keys::~Keys()
{
	std::cout << "Keygen Destruct" << std::endl;
}
