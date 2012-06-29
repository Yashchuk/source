/**
* @file		MyStack.h
* @brief	This file contains source code of Task 5.3.
*			It contains  declarations of class Stack.
*
* Copyright 2012 by Oleg Kiss,
*
* This software is confidental and proprietary information
* of Oleg Kiss. You shall not disclose such
* confidental information and shall use it only in
* accordance with terms of the license agreement
* you entered into with Oleg Kiss.
*/

#ifndef MYSTACK_H_
#define MYSTACK_H_

typedef char Item;

/**
* @class	MyStack
* @brief	This class realize stack.
*
* Copyright 2012 by Oleg Kiss,
* 
* This software is confidental and proprietary information
* of Oleg Kiss. You shall not disclose such
* confidental information and shall use it only in
* accordance with terms of the license agreement
* you entered into with Oleg Kiss.
*/

class Stack
{
private:
	struct Node
	{
		Item item;				/*char*/
		Node * prev;			/*pointer to prev node*/
	};
	Node * ptop;				/*pointer to the top of the stack*/
	int items;					/*how much items have stack*/
	Stack(const Stack & s) {}	
	Stack & operator=(const Stack & s) {return *this;}
public:
	Stack();
	~Stack();

	/*
	* @brief	This method chek is stack empty
	* return	bool		1 - is empty, 0 - isn't empty
	*/

	bool isempty() const;

	/*
	* @brief	This method add some character to stack
	* @param	[in]		c - some character
	* return	bool		1 - is empty, 0 - isn't empty
	*/

	bool add(char c);

	/*
	* @brief	This method return char on the top int the stack
	* return	const char		
	*/

	const char top() const;

	/*
	* @brief	This method delete node on the top int the stack
	* return	bool		1 - delete complite, 0 - can't delete
	*/

	bool pop();
};

#endif