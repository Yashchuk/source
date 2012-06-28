/**
* @file		BinTree.cpp
* @brief	This file contains source code of Task 4.1.
*			It contains  realized of Insert, Search, 
*			CrtTr, RootN, LNode, RNode, Del functions.
*			It's main purpose - to create and delete node in tree.
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
#include "BinTree.h"

BinTree * Insert(BinTree *pp, BinTree *v) 
{
	if (pp == NULL) 
	{									
		BinTree *q = new BinTree;		
		q->val = v->val;
		q->pL = q->pR = NULL;
		return q;
	}
	if (pp->val == v->val) 
	{
		return pp;
	}
	if (pp->val > v->val)                          
	{
		pp->pL=Insert(pp->pL,v);                   
	}
	else
	{
		pp->pR=Insert(pp->pR,v);
	}
	return pp;
}

int Search(BinTree *p, int v, int n) 
{
	if (p==NULL) 
		return --n;								
	if (p->val == v) 
		return n;								
	if (p->val > v)								
		return (Search(p->pL, v, ++n) );		
	else
		return(Search(p->pR, v, ++n) );			
}

void CrtTr(int * ar, BinTree * r, BinTree * v, int Max, int Min, int RN)
{
	int ind;
	/*left branch*/
	if(RN > Min + 1)
	{
		ind = LNode(RN, ar, Min);
		v->val = ar[ind];
		r = Insert(r, v);
		CrtTr(ar, r, v, RN, Min, ind);
	}

	/*right branch*/
	if(Max > RN + 1)
	{
		ind = RNode(RN, ar, Max);
		v->val = ar[ind];
		r = Insert(r, v);
		CrtTr(ar, r, v, Max, RN, ind); 
	}
}

int RootN(int Max, int * ar)
{
	int h = Max / 2;
	int ct;
	for(ct = 0; (ar[ct] < h) && (ar[ct] < Max); ++ct)
	{
		;
	}
	if(ar[ct] == h || ar[ct] == Max)
	{
		return ct;
	}
	else
	{
		int RofM = ar[ct];
		for(ct = 1; ar[ct] < h; ++ct) 
		{
			;
		}
		int LofM = ar[ct - 1];
		if(LofM + h > RofM)
		{
			return ct - 1;
		}
		else
		{
			return ct;
		}
	}
}

int LNode(int iNVal, int * ar, int iMin)
{
	int h = ( (double) ( ar[iNVal] - ar[iMin] ) / 2 + 0.5 + ar[iMin] );
	int ct;
	for(ct = iMin; (ar[ct] <= h) && (ar[ct] < ar[iNVal]); ++ct)
	{
		;
	}
	if(ar[ct - 1] == h || ct == iNVal)
	{
		return ct - 1;
	}
	else
	{
		int RofM = ar[ct];
		for(ct = iMin + 1; ar[ct] < h; ++ct) 
		{
			;
		}
		int LofM = ar[ct - 1];
		if(LofM + h > RofM)
		{
			return ct - 1;
		}
		else
		{
			return ct;
		}
	}
}

int RNode(int iNVal, int * ar, int iMax)
{
	int h = ( (double) ( ar[iMax] - ar[iNVal] ) / 2 + 0.5 + ar[iNVal] );
	int ct;
	for(ct = iNVal; (ar[ct] <= h) && (ar[ct] < ar[iMax]); ++ct)
	{
		;
	}
	if(ar[ct - 1] == h || ct == iNVal)
	{
		return ct - 1;
	}
	else
	{
		int RofM = ar[ct];
		for(ct = iNVal + 1; ar[ct] < h; ++ct) 
		{
			;
		}
		int LofM = ar[ct - 1];
		if(LofM + h > RofM)
		{
			return ct - 1;
		}
		else
		{
			return ct;
		}
	}
}

BinTree * Del(BinTree * pp)
{
	if(pp->pL)
	{
		delete Del(pp->pL);
	}
	if(pp->pR)
	{
		delete Del(pp->pR);
	}
	return pp;
}