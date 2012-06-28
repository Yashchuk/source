/**
* @file		BinTree.h
* @brief	This file contains source code of Task 4.1.
*			It contains  declarations of struct BinTree and Insert,
*			Search, CrtTr, RootN, LNode, RNode, Del functions.
*
* Copyright 2012 by Oleg Kiss,
*
* This software is confidental and proprietary information
* of Oleg Kiss. You shall not disclose such
* confidental information and shall use it only in
* accordance with terms of the license agreement
* you entered into with Oleg Kiss.
*/

#ifndef BINTREE_H_
#define BINTREE_H_

struct BinTree
{
	int val;
	BinTree * pL;
	BinTree * pR;
};

/*
* @brief	This function insert new node to tree 
* @param	[in,out]		pp - pointer to node
* @param	[in]			v - new node
* return	BinTree *		pointer on node
*/

BinTree * Insert(BinTree *pp, BinTree *v);

/*
* @brief	This function search some value in tree and
*			count path
* @param	[in,out]		p - pointer to node
* @param	[in]			v - search value
* @param	[in]			n - weight path
* return	int				path
*/

int Search(BinTree *p, int v, int n = 1);

/*
* @brief	This function create node of tree
* @param	[in]			ar - array of value to the add tree
* @param	[in]			r - pointer to the add node
* @param	[in]			Max - index of maximal value
* @param	[in]			Min - index of minimal value
* @param	[in]			RN - index of preview node
* return	void
*/

void CrtTr(int * ar, BinTree * r, BinTree * v, int Max, int Min, int RN);

/*
* @brief	This function create root node
* @param	[in]			iMax - index of maximal value
* @param	[in]			ar - pointer to the add node
* return	int				index of added Node
*/

int RootN(int iMax, int * ar);

/*
* @brief	This function create left branch
* @param	[in]			NVal - index of preview node
* @param	[in]			ar - array of value to the add tree
* @param	[in]			iMin -  index of minimal value
* return	int				index of added Node
*/

int LNode(int NVal, int * ar, int iMin);

/*
* @brief	This function create left branch
* @param	[in]			NVal - index of preview node
* @param	[in]			ar - array of value to the add tree
* @param	[in]			iMax -  index of maximal value
* return	int				index of added Node
*/

int RNode(int NVal, int * ar, int iMax);

/*
* @brief	This function delete node
* @param	[in]			pp - pointer to node
* return	BinTree *		pointer to the node. it must be delete
*/

BinTree * Del(BinTree * pp);

#endif