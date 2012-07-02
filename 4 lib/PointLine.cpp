#include "stdafx.h"
#include "PointLine.h"
#include <cmath>
#include <iostream>

void ShowP(const Point * pP)
{
	std::cout << "X: " << pP->x << ", Y: " << pP->y << std::endl;
}

Point * GetP(unsigned int ind, std::vector<Point> & vP)
{
	if(ind >= vP.size() )
	{
		return NULL;
	}
	return &vP[ind];
}

void AddP(const Point * pP, std::vector<Point> & vP)
{
	vP.push_back(*pP);
}

void SetP(Point * pP, int x, int y)
{
	pP->x = x;
	pP->y = y;
}

Line * GetL(unsigned int ind, std::vector<Line> & vL)
{
	if(ind >= vL.size() )
	{
		return NULL;
	}
	return &vL[ind];
}

void AddL(const Line * pL, std::vector<Line> & vL)
{
	vL.push_back(*pL);
}

void ShowP(const Line * pL)
{
	std::cout << "This line is at coordinates: ";
	std::cout << "X: " << pL->a.x << ", Y: " << pL->a.y << std::endl;
	std::cout << "X: " << pL->b.x << ", Y: " << pL->b.y << std::endl;
}

void SetL(Line * pL, const Point * a, const Point * b)
{
	pL->a.x = a->x;
	pL->a.y = a->y;
	pL->b.x = b->x;
	pL->b.y = b->y;
}

double LengthL(Line * pL)
{
	return sqrt(pow( (double)(pL->b.x - pL->a.x) , 2) + pow( (double)(pL->b.y - pL->a.y) , 2) );
}

bool PInL(Line * pL, Point * pP)
{
	double l1, l2, l3;
	l1 = ( (int)( (sqrt(pow( (double)(pP->x - pL->a.x) , 2) + pow( (double)(pP->y - pL->a.y) , 2) ) ) * 100 + 0.5) / 100);
	l2 = ( (int)( (sqrt(pow( (double)(pP->x - pL->b.x) , 2) + pow( (double)(pP->y - pL->b.y) , 2) ) ) * 100 + 0.5) / 100);
	l3 = ( (int)( (sqrt(pow( (double)(pL->b.x - pL->a.x) , 2) + pow( (double)(pL->b.y - pL->a.y) , 2) ) ) * 100 + 0.5) / 100);
	if( !( (pP->x - pL->a.x) * (pL->b.y - pL->a.y) - (pL->b.x - pL->a.x) * (pP->y - pL->a.y) ) )
	{
		if( l3 == l1 + l2 )
		{
			return true;
		}
	}
	return false;
}

bool PInML(Line * pL, Point * pP)
{
	if( pP->x == ( (pL->a.x + pL->b.x) / 2) )
	{
		if( pP->y == ( (pL->a.y + pL->b.y) / 2) )
		{
			return true;
		}
	}
	return false;
}

double AOfT(Line * pL, Point * pP)
{
	return ( ( (double)(pL->a.x * pP->y - pL->a.x * pL->b.y + pL->b.x * pL->a.y + pL->b.x * pP->y + pP->x * pL->b.y - pP->x * pL->a.y) ) / 2 );
}

