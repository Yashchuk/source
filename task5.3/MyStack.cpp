#include "stdafx.h"
#include "MyStack.h"

Stack::Stack()
{
	items = 0;
	ptop = NULL;
}

Stack::~Stack()
{
	Node * temp;
	while(ptop != NULL)
	{
		temp = ptop;
		ptop = ptop->prev;
		delete temp;
	}
}

bool Stack::isempty() const
{
	return items ? 0 : 1;
}

bool Stack::add(char c)
{
	Node * add = new Node;
	if(!add)
	{
		return false;
	}
	add->item = c;
	add->prev = ptop;
	ptop = add;
	++items;
	return true;
}

const char Stack::top() const
{
	return ptop->item;
}

bool Stack::pop()
{
	if(!ptop)
	{
		return false;
	}
	Node * temp;
	temp = ptop;
	ptop = ptop->prev;
	delete temp;
	--items;
	return true;
}