/**
* @file			4.cpp
* @brief		task 5.4
*				Implement operations on points:
*				1)take the point t;
*				2)put the point t equal to (x, y);
*				3)show the point t.
*				Implement actions of the segments:
*				1)take the segment s;
*				2)Show segment s;
*				3)put segment s equal to a, b;
*				4)length of the segment s;
*				5)or t is a point on a straight line with a segment s;
*				6)or is the point t in the interval s;
*				7)area of ​​the triangle formed by point t and segment s.
*				The file recorded sequence of points. Using the module to 
*				work with points and segments in the plane find:
*				a) triangle of largest area formed by points of order;
*				b) the smallest circle radius, within which lie all points of order;
*				c) segment, which is the highest number of points of order;
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
#include "PointLine.h"
#include <iostream>
#include <fstream>

using namespace std;

/*
* @brief	This function find most remote point from the point
* @param	[in]		vP - container of points
* @param	[in, out]	vL - container of lines
* @param	[in]		P - point from which to search
* return	Point *
*/

Point * FMRP(vector<Point> & vP, vector<Line> & vL, const Point * P);

/*
* @brief	This function calculate area of the largest triangle
*			and returns pointer to last point of triangle
* @param	[in]		L - pointer to line
* @param	[in, out]	vP - container of Points
* @param	[in, out]	area - area of the largest triangle
* return	Point *
*/

Point * AOfLT(Line * L, vector<Point> & vP, double * area);

/*
* @brief	This function returns the smallest circle radius, 
*			within which lie all points of order
* @param	[in]		p1 - pointer to first point of triangle
* @param	[in]		p2 - pointer to second point of triangle
* @param	[in]		p3 - pointer to third point of triangle
* @param	[in]		area - area of the largest triangle
* return	double
*/

double CR(const Point * p1, const Point * p2, const Point * p3, double area);

/*
* @brief	This function returns pointer segment, which is the highest number of points of order;
* @param	[in]		vP - container of Points
* @param	[in, out]	vL - container of lines
* @param	[in, out]	mp - number of point
* return	Line *
*/

Line * MPInL(vector<Point> & vP, vector<Line> & vL, unsigned int * mp);

int _tmain(int argc, _TCHAR* argv[])
{
	vector<Point> vP;
	vector<Line> vL;
	ifstream fin;
	fin.open("Data.txt");
	if(!fin)
	{
		cout << "Can't open file!" << std::endl;
		exit(EXIT_FAILURE);
	}
	int x, y;
	Point * p ;
	try
	{
		p = new Point;
	}
	catch(std::bad_alloc & ba)
	{
		cout << ba.what() << endl;
		exit(EXIT_FAILURE);
	}
	while( !fin.eof() )
	{
		fin >> x;
		fin >> y;
		SetP(p, x, y);
		AddP(p, vP);
	}
	fin.close();
	delete p;
	Point ** pp;
	try
	{
		pp = new Point * [3];
	}
	catch(std::bad_alloc & ba)
	{
		cout << ba.what() << endl;
		exit(EXIT_FAILURE);
	}
	pp[0] = FMRP(vP, vL, NULL);
	vL.clear();
	pp[1] = FMRP(vP, vL, pp[0]);
	Line * l;
	try
	{
		l = new Line;
	}
	catch(std::bad_alloc & ba)
	{
		cout << ba.what() << endl;
		delete [] pp;
		exit(EXIT_FAILURE);
	}
	SetL(l, pp[0], pp[1]);
	double MAT = 0;
	pp[2] = AOfLT(l, vP, &MAT);
	cout << "The tringle with max area - " << MAT << endl;
	cout << "The tirangle coordinates: " << endl << "Ax - " << pp[0]->x << ", Ay - " << pp[0]->y << endl
		<< "Bx - " << pp[1]->x << ", By - " << pp[1]->y << endl
		<< "Cx - " << pp[2]->x << ", Cy - " << pp[2]->y << endl;
	double CRad;
	CRad = CR(pp[0], pp[1], pp[2], MAT);
	cout << "The circle of smallest radius, inside are all point of sequence: " << CRad << endl;
	delete [] pp;
	vL.clear();
	unsigned int mp = 0;
	l = MPInL(vP, vL, &mp);
	cout << "The line that has most point has next coordinats:" << endl
		<< "Ax - " << l->a.x << ", Ay - " << l->a.y << endl
		<< "Bx - " << l->b.x << ", By - " << l->b.y << endl
		<< "And it has " << mp << " points." << endl;
	system("@pause");
	return 0;
}

Point * FMRP(vector<Point> & vP, vector<Line> & vL, const Point * P)
{
	double max = 0;
	int ct = -1;
	Line L;
	if(!P)
	{
		Point temp;
		temp.x = 0;
		temp.y = 0;
		P = &temp;
	}
	for(unsigned int i = 0; i < vP.size(); ++i)
	{
		SetL(&L, P, &vP[i]);
		AddL(&L, vL);
	}
	for(unsigned int i = 0; i < vL.size(); ++i)
	{
		if( max < LengthL(&vL[i]) )
		{
			max = LengthL(&vL[i]);
			ct = i;
		}
	}
	if(max >= 0)
	{
		return &vL[ct].b;
	}
	return NULL;
}

double CR(const Point * p1, const Point * p2, const Point * p3, double area)
{
	Line tL[3];
	SetL(&tL[0], p1, p2);
	SetL(&tL[1], p1, p3);
	SetL(&tL[2], p2, p3);
	return ( ( LengthL(&tL[0]) * LengthL(&tL[1]) * LengthL(&tL[2]) ) / (area * 4) );
}

Point * AOfLT(Line * L, vector<Point> & vP, double * area)
{
	double maxArea = -1;
	int maxP = -1;
	for(unsigned int i = 0; i < vP.size(); ++i)
	{
		if(maxArea < AOfT(L, &vP[i]) )
		{
			maxArea = AOfT(L, &vP[i]);
			maxP = i;
		}
	}
	*area = maxArea;
	return &vP[maxP];
}

Line * MPInL(vector<Point> & vP, vector<Line> & vL, unsigned int * mp)
{
	Line tL;
	for(unsigned int i = 0; i < vP.size() - 1; ++i)
	{
		for(unsigned int j = i + 1; j < vP.size(); ++j)
		{
			SetL(&tL, &vP[i], &vP[j]);
			AddL(&tL, vL);
		}
	}
	unsigned int maxL;
	int ct;
	unsigned int j;
	for(unsigned int i = 0; i < vL.size(); ++i)
	{
		ct = 0;
		for(j = 0; j < vP.size(); ++j)
		{
			if(PInL(&vL[i], &vP[j]) )
			{
				++ct;
			}
		}
		if(*mp < ct)
		{
			maxL = i;
			*mp = ct;
		}
	}
	if(!(*mp) )
	{
		return NULL;
	}
	return &vL[maxL];
}