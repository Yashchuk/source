
#include "stdafx.h"
#include "MinPas.h"

int MP(int * ar, int * num, int i, int j, int size)
{
	int fs = INT_MAX, s;
	if(ar[i * size + j] < 0)
	{
		if(i > j)
		{
			ar[i * size + j] = 0;
		}
		else
		{
			for(s = i; s <= j; ++s)
			{
				fs = Min(fs, MP(ar, num, i, s - 1, size) + MP(ar, num, s + 1, j, size) );
			}
			ar[i * size + j] = num[j + 1] - num[i - 1] - 1 + fs;
		}
	}
	return ar[i * size + j];
}

int Min(int a, int b)
{
	if(a < b)
		return a;
	return b;
}