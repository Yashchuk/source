/**
* @file		Numeral.cpp
* @brief	This file contains source code of Task 3.4.
*			It contains  declarations of Numeral functions.
*			It's main purpose - to form the numeral on the number.
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
#include "Numeral.h"

std::string Numeral(US num)
{
	std::string str;
	if(num < 20)
	{
		switch(num)
		{
			case 10: str = "Ten";
				break;
			case 11: str = "Eleven";
				break;
			case 12: str = "Twelve";
				break;
			case 13: str = "Thirteen";
				break;
			case 14: str = "Fourteen";
				break;
			case 15: str = "Fifteen";
				break;
			case 16: str = "Sixteen";
				break;
			case 17: str = "Seventeen";
				break;
			case 18: str = "Eighteen";
				break;
			case 19: str = "Nineteen";
				break;
		}
		return str;
	}
	else
	{
		switch( (num/10) * 10)
		{
			case 20: str = "Twenty";
				break;
			case 30: str = "Thirty";
				break;
			case 40: str = "Forty";
				break;
			case 50: str = "Fifty";
				break;
			case 60: str = "Sixty";
				break;
			case 70: str = "Seventy";
				break;
			case 80: str = "Eighty";
				break;
			case 90: str = "Ninety";
				break;
		}
		switch(num % 10)
		{
			case 1: str += "-one";
				break;
			case 2: str += "-two";
				break;
			case 3: str += "-tree";
				break;
			case 4: str += "-four";
				break;
			case 5: str += "-five";
				break;
			case 6: str += "-six";
				break;
			case 7: str += "-seven";
				break;
			case 8: str += "-eight";
				break;
			case 9: str += "-nine";
				break;
			default: break;
		}
		return str;
	}
}