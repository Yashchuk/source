
#ifndef LIST_H_
#define LIST_H_

typedef unsigned int UI;

#include <iostream>

template<typename Any>
class List
{
private:
	UI size;
	struct Node
	{
		Any item;
		Node * next;
		Node * prev;
	};
	Node * first;
	Node * last;
public:
	List();
	List(const List & l);
	List & operator=(const List & l);
	UI Size() const;
	bool IsEmpty() const;
	bool PushFront(const Any & item);
	bool PushBack(const Any & item);
	bool PopFront();
	bool PopBack();
	bool Insert(const Any & item, unsigned int i);
	bool Erase(int i);
	bool MergeAll(const List & l);
	bool MergeAND(const List & l);
	bool MergeNOT2List(const List & l);
	void Sort();
	void Show() const;
	~List();
};

template<typename Any>
List<Any>::List() : size(0)
{
	first = last = NULL;
}

template<typename Any>
List<Any>::List(const List & l)
{
	size = 0;
	Node * tmp = l.first;
	for( UI i = 0; i < l.size; ++i )
	{
		if( !PushBack(tmp->item) )
		{
			throw;
		}
		tmp = tmp->next;
	}
 }

template<typename Any>
List<Any> & List<Any>::operator=(const List & l)
{
	size = 0;
	if( this == &l)
	{
		return *this;
	}
	Node * tmp = l.first;
	for( UI i = 0; i < size; ++i, ++size )
	{
		if( !PushBack(tmp->item) )
		{
			return NULL;
		}
		tmp = tmp->next;
	}
	return *this;
}

template<typename Any>
UI List<Any>::Size() const
{
	return size;
}

template<typename Any>
bool List<Any>::IsEmpty() const
{
	return size;
}

template<typename Any>
bool List<Any>::PushFront(const Any & item)
{
	Node * el = new Node;
	if( !el )
	{
		return false;
	}
	el->item = item;
	if( !size )
	{
		el->next = el->prev = NULL;
		first = last = el;
	}
	else
	{
		el->next = first;
		first->prev = el;
		el->prev = NULL;
		first = el;
	}
	++size;
	return true;
}

template<typename Any>
bool List<Any>::PushBack(const Any & item)
{
	Node * el = new Node;
	if( !el )
	{
		return false;
	}
	el->item = item;
	if( !size )
	{
		el->next = el->prev = NULL;
		first = last = el;
	}
	else
	{
		el->prev = last;
		last->next = el;
		el->next = NULL;
		last = el;
	}
	++size;
	return true;
}

template<typename Any>
bool List<Any>::PopFront()
{
	if( size )
	{
		first = first->next;
		delete first->prev;
		first->prev = NULL;
		--size;
		return true;
	}
	return false;
}

template<typename Any>
bool List<Any>::PopBack()
{
	if( size )
	{
		last = last->prev;
		delete last->next;
		last->next = NULL;
		--size;
		return true;
	}
	return false;
}

template<typename Any>
bool List<Any>::Insert(const Any & item, unsigned int i)
{
	if( size > i || !i )
	{
		Node * el = new Node;
		if( !el )
		{
			return false;
		}
		el->item = item;
		if( !i )
		{
			el->next = first;
			first->prev = el;
			el->prev = NULL;
			if( !last )
			{
				last = el;
			}
		}
		else
		{
			Node * tmp;
			if( size / 2 > i )
			{
				tmp = first;
				while( i )
				{
					tmp = tmp->next;
					--i;
				}
			}
			else
			{
				i = size - i - 1;
				tmp = last;
				while( i )
				{
					tmp = tmp->prev;
					--i;
				}
			}
			el->prev = tmp->prev;
			tmp->prev->next = el;
			tmp->prev = el;
			el->next = tmp;
		}
		++size;
		return true;
	}
	return false;
}

template<typename Any>
bool List<Any>::Erase(int i)
{
	if( size > i )
	{
		Node * tmp = first;
		if( !i )
		{
			if( size == 1 )
			{
				first = last = NULL;
			}
			else
			{
				first = tmp->next;
				tmp->next->prev = NULL;
			}
		}
		else if( size - 1 == i )
		{
			tmp = last;
			last = tmp->prev;
			last->next = NULL;
		}
		else
		{
			if( size / 2 > i )
			{
				while( i )
				{
					tmp = tmp->next;
					--i;
				}
			}
			else
			{
				i = size - i - 1;
				tmp = last;
				while( i )
				{
					tmp = tmp->prev;
					--i;
				}
			}
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
		}
		delete tmp;
		--size;
		return true;
	}
	return false;
}

template<typename Any>
bool List<Any>::MergeAll(const List & l)
{
	Node * tmp = l.first;
	for( UI i = 0; i < l.size; ++i )
	{
		if( PushBack(tmp->item) )
		{
			tmp = tmp->next;
			++size;
		}
		else
		{
			return NULL;
		}
	}
	return true;
}

template<typename Any>
bool List<Any>::MergeAND(const List & l)
{
	Node * t, * tmp;
	t = first;
	bool f = false;
	for( UI i = 0; i < size; ++i )
	{
		tmp = l.first;
		for( UI j = 0; j < l.size; ++j )
		{
			if( t->item == tmp->item )
			{
				f = true;
				break;
			}
			tmp = tmp->next;
		}
		t = t->next;
		if( !f )
		{
			if( !Erase(i) )
			{
				return false;
			}
			f = false;
			--i;
		}
	}
	return true;
}

template<typename Any>
bool List<Any>::MergeNOT2List(const List & l)
{
	Node * t, * tmp;
	t = first;
	bool f = false;
	for( UI i = 0; i < size; ++i )
	{
		tmp = l.first;
		for( UI j = 0; j < l.size; ++j )
		{
			if( t->item == tmp->item )
			{
				f = true;
				break;
			}
			tmp = tmp->next;
		}
		t = t->next;
		if( f )
		{
			if( !Erase(i) )
			{
				return false;
			}
			f = false;
			--i;
		}
	}
	return true;
}

template<typename Any>
void List<Any>::Sort()
{
	Any tmp;
	Node * min, * ti = first, * tj;
	for( UI i = 0; i < size; ++i )
	{
		min = ti;
		tj = ti->next;
		for( UI j = i + 1; j < size; ++j )
		{
			if( min->item > tj->item )
			{
				min = tj;
			}
			tj = tj->next;
		}
		if( min != ti )
		{
			tmp = ti->item;
			ti->item = min->item;
			min->item = tmp;
		}
		ti = ti->next;
	}
}

template<typename Any>
List<Any>::~List()
{
	if( size )
	{
		while( first->next != NULL )
		{
			first = first->next;
			delete first->prev;
		}
		delete first;
	}
}

template<typename Any>
void List<Any>::Show() const
{
	if( size )
	{
		Node * tmp = first;
		while( tmp->next != NULL )
		{
			tmp = tmp->next;
			std::cout << tmp->prev->item <<endl;
		}
		std::cout << tmp->item <<endl;
	}
}

#endif
