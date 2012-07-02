#ifndef POINTLINE_H_
#define POINTLINE_H_

#include <vector>

struct Point
{
	int x, y;
};

struct Line
{
	Point a, b;
};

/*
* @brief	This function shows coordinates of point
* @param	[in]		pP - pointer to Point
* return	void
*/

void ShowP(const Point * pP);

/*
* @brief	This function returns point by index
* @param	[in]		ind - index of vector 
* return	void
*/

Point * GetP(unsigned int ind, std::vector<Point> & vP);

/*
* @brief	This function adds a point with coordinates (x,y)
* @param	[in]		pP - pointer to Point 
* @param	[in]		x - coordinat x
* @param	[in]		y - coordinat y
* return	void
*/

void SetP(Point * pP, int x, int y);

/*
* @brief	This function adds point to vector
* @param	[in]		pP - pointer to Point 
* return	void
*/

void AddP(const Point * pP, std::vector<Point> & vP);

/*
* @brief	This function returns line by index
* @param	[in]		ind - index of vector 
* return	void
*/

Line * GetL(unsigned int ind, std::vector<Line> & vL);



void AddL(const Line * pL, std::vector<Line> & vL);

/*
* @brief	This function shows coordinates of line
* @param	[in]		pL - pointer to Line
* return	void
*/

void ShowL(const Line * pL);

/*
* @brief	This function adds a line with begin point a, 
*			and end point b
* @param	[in]		pP - pointer to Point 
* @param	[in]		x - coordinat x
* @param	[in]		y - coordinat y
* return	void
*/

void SetL(Line * pL, const Point * a, const Point * b);

/*
* @brief	This function returns length of line
* @param	[in]		pL - pointer to Line 
* return	double		
*/

double LengthL(Line * pL);

/*
* @brief	This function returns true if point is in line
* @param	[in]		pL - pointer to Line 
* @param	[in]		pP - pointer to Point
* return	bool		
*/

bool PInL(Line * pL, Point * pP);

/*
* @brief	This function returns true if point is in middle of line
* @param	[in]		pL - pointer to Line 
* @param	[in]		pP - pointer to Point
* return	bool		
*/

bool PInML(Line * pL, Point * pP);

/*
* @brief	This function returns area of ​​triangle 
* @param	[in]		pL - pointer to Line 
* @param	[in]		pP - pointer to Point
* return	bool		
*/

double AOfT(Line * pL, Point * pP);

#endif /*PointLine_H_*/