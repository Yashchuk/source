/**
* @file		XO.cpp
* @brief	This file contains source code of Task 5.5.
*			It contains  realized of Show, PlMv, Win, CMv, CanWin, Move, 
*			plus1plus2, plus1minus1, plus3plus6, plus3minus3 functions.
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
#include "XO.h"

void Show(char * f)
{
	for(char i = 0; i < CELL / 3; ++i)
	{
		for(char j = 0; j < CELL / 3; ++j)
		{
			if(j < CELL / 3 - 1)
			{
				std::cout << f[i * CELL / 3 + j] << '|';
			}
			else
			{
				std::cout << f[i * CELL / 3 + j] << std::endl;
			}
		}
		if(i < CELL / 3 - 1)
		{
			std::cout << "-----" << std::endl;
		}
	}
}

void PlMv(char * f, char ** ar)
{
	std::cout << "Your can move to:\n";
	for(char i = 0; i < CELL; ++i)
	{
		if(f[i] == ' ')
		{
			std::cout << "Enter " << i + 1 << " to move " 
				<< ar[i] << std::endl;
		}
	}
	short ch;
	std::cout << "Your choice: ";
	std::cin >> ch;
	while(ch > 9 || ch < 1 || f[ch - 1] != ' ')
	{
		if(!std::cin)
		{
			std::cin.clear();
			while(std::cin.get() != '\n')
			{
				/*NULL*/
			}
		}
		std::cout << "Re-enter: ";
		std::cin >> ch;
	}
	f[ch - 1] = 'X';
}	

void CMv(char * f, char a)
{
	if(a == 9)
	{
		return;
	}
	char c = 'O';
	/*Can CPU win in the next move*/
	if( CanWin(f, c) )
	{
		return;
	}
	c = 'X';
	/*Can user win in the next move*/
	if( CanWin(f, c) )
	{
		return;
	}
	Move(f, a);
}

bool Win(char * f)
{
	char i = 0;
	for(; i < 9; i += 3)
	{
		if(f[i] != ' ')
		{
			if(f[i] == f[i + 1] && f[i] == f[i + 2])
			{
				return true;
			}
		}
	}
	for(i = 0; i < 3; ++i)
	{
		if(f[i] != ' ')
		{
			if(f[i] == f[i + 3] && f[i] == f[i + 6])
			{
				return true;
			}
		}
	}
	if(f[0] != ' ' && f[0] == f[4] && f[0] == f[8])
	{
		return true;
	}
	if(f[6] != ' ' && f[6] == f[4] && f[6] == f[2])
	{
		return true;
	}
	return false;
}

bool CanWin(char * f, char c)
{
	short sign = 1;
	bool m = false;
	for(char i = 0; i < 9; ++i)
	{
		if(f[i] == c)
		{
			if(i == 0 || i == 8)
			{
				if(i != 0)
				{
					sign = ~sign + 1;
				}
				if( plus1plus2(f, i, c, sign) )
				{
					m = true;
					break;
				}
				if(plus3plus6(f, i, c, sign) )
				{
					m = true;
					break;					
				}
				if(f[i] == f[i + 4 * sign] && f[i + 8 * sign] == ' ')
				{
					f[i + 8 * sign] = 'O';
					i = 9;
					m = true;
					break;
				}
				if(f[i + 8 * sign] == c && f[i + 4 * sign] == ' ')
				{
					f[i + 4 * sign] = 'O';
					i = 9;
					m = true;
					break;
				}
				break;
			}
			if(i == 1 || i == 7)
			{
				if(i != 1)
				{
					sign = ~sign + 1;
				}
				if( plus1minus1(f, i, c, sign) )
				{
					m = true;
					break;
				}
				if( plus3plus6(f, i, c, sign) )
				{
					m = true;
					break;					
				}
				break;
			}
			if(i == 2 || i == 6)
			{
				if(i != 2)
				{
					sign = ~sign + 1;
				}
				if(f[i] == f[i - 1 * sign] && f[i - 2 * sign] == ' ')
				{
					f[i - 2 * sign] = 'O';
					i = 9;
					m = true;
					break;
				}
				if(plus3plus6(f, i, c, sign) )
				{
					m = true;
					break;					
				}
				if(f[i] == f[i + 2 * sign] && f[i + 4 * sign] == ' ')
				{
					f[i + 4 * sign] = 'O';
					i = 9;
					m = true;
					break;
				}
				break;
			}
			if(i == 3 || i == 5)
			{
				if(i != 3)
				{
					sign = ~sign + 1;
				}
				if(plus3minus3(f, i, c, sign) )
				{
					m = true;
					break;
				}
				if( plus1plus2(f, i, c, sign) )
				{
					m = true;
					break;
				}
				break;
			}
			if(i == 4)
			{
				if( plus1minus1(f, i, c, sign) )
				{
					m = true;
					break;
				}
				if(plus3minus3(f, i, c, sign) )
				{
					m = true;
					break;
				}
				if(f[i] == f[i + 4 * sign] && f[i - 4 * sign] == ' ') 
				{
					f[i - 4 * sign] = 'O';
					i = 9;
					m = true;
					break;
				}
				if(f[i] == f[i - 4 * sign] && f[i + 4 * sign] == ' ')
				{
					f[i + 4 * sign] = 'O';
					i = 9;
					m = true;
					break;
				}
				if(f[i] == f[i + 2 * sign] && f[i - 2 * sign] == ' ') 
				{
					f[i - 2 * sign] = 'O';
					i = 9;
					m = true;
					break;
				}
				if(f[i] == f[i - 2 * sign] && f[i + 2 * sign] == ' ')
				{
					f[i + 2 * sign] = 'O';
					i = 9;
					m = true;
					break;
				}
			}
		}
	}
	return m;
}

void Move(char * f, char a)
{
	if(a == 1)
	{
		if(f[4] == ' ')
		{
			f[4] = 'O';
			return;
		}
		else
		{
			f[0] = 'O';
			return;
		}
	}
	else if(a == 3)
	{
		if(f[4] == 'O')
		{
			if( (f[0] == ' ') && (f[8] == ' ') )
			{
				f[0] = 'O';
				return;
			}
			if( (f[1] == ' ') && (f[7] == ' ') )
			{
				if(f[8] == 'X')
				{
					f[6] = 'O';
				}
				else if(f[5] == 'X')
				{
					f[3] = 'O';
				}
				else 
				{
					f[1] = 'O';
				}
				return;
			}
			if( (f[2] == ' ') && (f[6] == ' ') )
			{
				if(f[8] == 'X')
				{
					f[6] = 'X';
				}
				else
				{
					f[2] = 'O';
				}
				return;
			}
			if( (f[3] == ' ') && (f[5] == ' ') )
			{
				f[3] = 'O';
				return;
			}
		}
		else
		{
			f[2] = 'O';
			return;
		}
	}
	else
	{
		for(char i = CELL - 1; i > -1; --i)
		{
			if(f[i] == ' ')
			{
				f[i] = 'O';
				break;
			}
		}
	}
}

bool plus1plus2(char * f, char i, char c, short s)
{
	if(f[i] == f[i + 1 * s] && f[i + 2 * s] == ' ')
	{
		f[i + 2 * s] = 'O';
		i = 9;
		return true;
	}
	if(f[i + 2 * s] == c && f[i + 1 * s] == ' ')
	{
		f[i + 1 * s] = 'O';
		i = 9;
		return true;
	}
	return false;
}

bool plus1minus1(char * f, char i, char c, short s)
{
	if(f[i] == f[i + 1 * s] && f[i - 1 * s] == ' ') 
	{
		f[i - 1 * s] = 'O';
		i = 9;
		return true;
	}
	if(f[i] == f[i - 1 * s] && f[i + 1 * s] == ' ')
	{
		f[i + 1 * s] = 'O';
		i = 9;
		return true;
	}
	return false;
}

bool plus3plus6(char * f, char i, char c, short s)
{
	if(f[i] == f[i + 3 * s] && f[i + 6 * s] == ' ')
	{
		f[i + 6 * s] = 'O';
		i = 9;
		return true;
	}
	if(f[i + 6 * s] == c && f[i + 3 * s] == ' ')
	{
		f[i + 3 * s] = 'O';
		i = 9;
		return true;
	}
	return false;
}

bool plus3minus3(char * f, char i, char c, short s)
{
	if(f[i] == f[i + 3 * s] && f[i - 3 * s] == ' ') 
	{
		f[i - 3 * s] = 'O';
		i = 9;
		return true;
	}
	if(f[i] == f[i - 3 * s] && f[i + 3 * s] == ' ')
	{
		f[i + 3 * s] = 'O';
		i = 9;
		return true;
	}
	return false;
}