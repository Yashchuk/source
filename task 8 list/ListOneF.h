#ifndef LISTONEF_H_
#define LISTONEF_H_

#include <iostream>

typedef unsigned int UI;

template <typename T>
class List
{
private:
	UI size;
	struct Node
	{
		T item;
		Node * next;
	};
	Node * first;
	Node * last;
	void ClearList();								/*видаляє всі елементи спику*/
	void Delete(Node * node);						/*видалення елементу по вказівнику*/
public:
	List();
	List(const List & l);
	List & operator=(const List & l);
	UI Size() const;
	bool Empty() const;
	bool PushBack(const T & item);					/*вставка в кінець*/
	bool PushFront(const T & item);					/*вставка на початок*/
	void PopBack();									/*видалення з кінця*/
	void PopFront();								/*видалення з початку*/
	void Show() const;								/*Вивід інформації*/
	bool Insert(const T & val, const T & item);		/*вставка після певного значення*/
	bool Delete(UI i);								/*видалення елементу по індексу*/
	bool Delete(const T & item);					/*видалення елементу по значенню*/
	const T * MaxMin(bool max = true) const;		/*шукати максимальни / мінімальний елемент*/
	void SortMaxMin(bool max = true);				/*сортувати поспаданню / по зростанню*/
	bool SortMinToMax() const;						/*чи відсортовано по зростанню*/
	List & Positive(const List & l);				/*заповнення списку тільки позитивними значеннями*/
	List & Negative(const List & l);				/*заповнення списку тільки негативними значеннями*/
	bool MergeOneEl(const List & l);				/*обєднаня 2-х списків, елементи унікальні*/
	bool MergeAndEl(const List & l);				/*обєднаня 2-х списків, елементи унікальні і тільки ті що є в 1 і 2 списках*/
	bool MergeNot2ListEl(const List & l);			/*обєднаня 2-х списків, елементи унікальні і тільки ті що є в 1 і немає 2 списках*/
	void DelDublicate();							/*видаляє подвоєння*/
	bool Dublicate();								/*дублікує кожен елемент*/
	void ShowRangeMinMax() const;					/*вивести діпазон між максимальним і мінімальним елементом*/
	UI NeighborEqual() const;						/*рахує кількість елементів в який сусіди одинакові*/
	void DelNeighborEqual();						/*видаляє елемент якщо в нього сусіди одинакові*/
	~List();
};

template <typename T>
void List<T>::ClearList()
{
	Node * tmp = first;
	while( first != last )
	{
		first = first->next;
		delete tmp;
		tmp = first;
	}
	delete last;
	first = last = NULL;
	size = 0;
}

template <typename T>
UI List<T>::Size() const
{
	return size;
}

template <typename T>
bool List<T>::Empty() const
{
	return (bool)size;
}

template <typename T>
List<T>::List() : size(0)
{
	first = last = NULL;
}

template <typename T>
List<T>::List(const List & l)
{
	size = 0;
	Node * tmp = l.first;
	while( tmp )
	{
		if( !PushBack(tmp->item) )
		{
			throw;
		}
		tmp = tmp->next;
	}
}

template <typename T>
List<T> & List<T>::operator=(const List & l)
{
	if( !(this == &l) )
	{
		ClearList();
		Node * tmp = l.first;
		while( tmp )
		{
			if( !PushBack(tmp->item) )
			{
				throw;
			}
			tmp = tmp->next;
		}
		size = l.size;
	}
	return *this;
}

template <typename T>
bool List<T>::PushBack(const T & item)
{
	Node * tmp;
	try
	{
		tmp = new Node;
	}
	catch( std::bad_alloc )
	{
		return false;
	}
	tmp->item = item;
	tmp->next = NULL;
	if( size )
	{
		last->next = tmp;
		last = tmp;
	}
	else
	{
		first = last = tmp;
	}
	++size;
	return true;
}

template <typename T>
bool List<T>::PushFront(const T & item)
{
	Node * tmp;
	try
	{
		tmp = new Node;
	}
	catch( std::bad_alloc )
	{
		return false;
	}
	tmp->item = item;
	if( size )
	{
		tmp->next = first;
		first = tmp;
	}
	else
	{
		tmp->next = NULL;
		first = last = tmp;
	}
	++size;
	return true;
}

template <typename T>
void List<T>::PopBack()
{
	Node * tmp = first;
	while( !(tmp->next == last) )
	{
		tmp = tmp->next;
	}
	delete last;
	last = tmp;
	last->next = NULL;
	--size;
}

template <typename T>
void List<T>::PopFront()
{
	Node * tmp = first;
	first = first->next;
	delete tmp;
	--size;
}

template <typename T>
void List<T>::Show() const
{
	Node * tmp = first;
	while( tmp )
	{
		std::cout << tmp->item << std::endl;
		tmp = tmp->next;
	}
}

template <typename T>
bool List<T>::Insert(const T & val, const T & item)
{
	Node * tmp, * ct = first;
	try
	{
		tmp = new Node;
	}
	catch( std::bad_alloc )
	{
		return false;
	}
	tmp->item = item;
	while( (ct) && (ct->item != val) )
	{
		ct = ct->next;
	}
	if( !ct )
	{
		return false;
	}
	tmp->next = ct->next;
	ct->next = tmp;
	++size;
	return true;
}

template <typename T>
bool List<T>::Delete(UI i)
{
	if( !i )
	{
		PopFront();
		return true;
	}
	else if( size - 1 == i )
	{
		PopBack();
		return true;
	}
	else if( size > i )
	{
		Node * tmp = first, *pt;
		if( !(i - 1) ) 
		{
			pt = tmp;
		}
		while( i-- )
		{
			tmp = tmp->next;
			if( !(i - 1) ) 
			{
				pt = tmp;
			}
		}
		pt->next = tmp->next;
		delete tmp;
		--size;
		return true;
	}
	return false;
}

template <typename T>
bool List<T>::Delete(const T & item)
{
	Node * tmp = first, * del;
	if( first->item == item )
	{
		PopFront();
	}
	else if( last->item == item )
	{
		PopBack();
	}
	else
	{
		while( ( tmp->next != NULL ) && ( tmp->next->item != item ) )
		{
			tmp = tmp->next;
		}
		if( !tmp->next )
		{
			return false;
		}
		del = tmp->next;
		tmp->next = del->next;
		delete del;
		--size;
	}
	return true;
}

template <typename T>
void List<T>::Delete(Node * node)
{
	if( node == first )
	{
		PopFront();
	}
	else if( node == last )
	{
		PopBack();
	}
	else
	{
		Node * tmp = node->next;
		if( tmp == last )
		{
			last = node;
		}
		memcpy( node, tmp, sizeof(Node) );
		delete tmp;
		--size;
	}
}

template <typename T>
const T * List<T>::MaxMin(bool max = true) const
{
	Node * ret = first, * ct = first->next;
	while( ct )
	{
		if( max )
		{
			if( ret->item < ct->item )
			{
				ret = ct;
			}
		}
		else
		{
			if( ret->item > ct->item )
			{
				ret = ct;
			}
		}
		ct = ct->next;
	}
	return &ret->item;
}

template <typename T>
void List<T>::SortMaxMin(bool max = true)
{
	Node * m,			/*макс або мін*/
		* pm,			/*елемент перед m*/
		* nm,			/*елемент пеісля m*/
		* ti = first,	/*лічильник для 1-го циклу*/
		* tj,			/*лічильник для 2-го циклу*/
		* pti = NULL,	/*елемент перед ti*/
		* tmp,			/*для обміну*/
		* ptj;			/*елемент перед tj*/
	for( UI i = 0; i < size - 1; ++i )
	{
		tj = ti->next;
		for( tj = ti->next, m = ti, ptj = ti; tj; tj = tj->next )
		{
			if( max )
			{
				if( m->item < tj->item )
				{
					pm = ptj;
					m = tj;
					nm = tj->next;
				}
			}
			else
			{
				if( m->item > tj->item )
				{
					pm = ptj;
					m = tj;
					nm = tj->next;
				}
			}
			ptj = tj;
		}
		tmp = ti;
		if( ti->next != m )
		{
			ti = ti->next;
		}
		if( m != tmp )
		{
			if( pti )
			{
				pti->next = m;
			}
			else
			{
				first = m;
			}
			if( m != tmp->next )
			{
				m->next = tmp->next;
				pm->next = tmp;
			}
			else
			{
				m->next = tmp;
			}
			tmp->next = nm;
			pti = m;
		}
		else
		{
			pti = tmp;
		}
	}
	tmp = first;
	while( tmp->next )
	{
		tmp = tmp->next;
	}
	last = tmp;
}

template <typename T>
bool List<T>::SortMinToMax() const
{
	Node * tmp = first;
	while( tmp->next )
	{
		if( !(tmp->item < tmp->next->item) )
		{
			return false;
		}
		tmp = tmp->next;
	}
	return true;
}

template <typename T>
List<T> & List<T>::Positive(const List & l)
{
	Node * tmp;
	if( this == &l )
	{
		tmp = first;
		while( tmp )
		{
			if( tmp->item < 0 )
			{
				tmp->item = ~tmp->item + 1;
			}
			tmp = tmp->next;
		}
	}
	else
	{
		ClearList();
		tmp = l.first;
		while( tmp )
		{
			if( tmp->item < 0 )
			{
				if( !PushBack( ~tmp->item + 1 ) )
				{
					throw;
				}
			}
			else
			{
				if( !PushBack(tmp->item) )
				{
					throw;
				}
			}
			tmp = tmp->next;
		}
	}
	return *this;
}

template <typename T>
List<T> & List<T>::Negative(const List & l)
{
	Node * tmp;
	if( this == &l )
	{
		tmp = first;
		while( tmp )
		{
			if( tmp->item > -1 )
			{
				tmp->item = ~tmp->item + 1;
			}
			tmp = tmp->next;
		}
	}
	else
	{
		ClearList();
		tmp = l.first;
		while( tmp )
		{
			if( tmp->item > -1 )
			{
				if( !PushBack( ~tmp->item + 1 ) )
				{
					throw;
				}
			}
			else
			{
				if( !PushBack(tmp->item) )
				{
					throw;
				}
			}
			tmp = tmp->next;
		}
	}
	return *this;
}

template <typename T>
bool List<T>::MergeOneEl(const List & l)
{
	Node * tmp = l.first;
	while( tmp )
	{
		if( PushBack(tmp->item) )
		{
			tmp = tmp->next;
		}
		else
		{
			return NULL;
		}
	}
	DelDublicate();
	return true;
}

template <typename T>
bool List<T>::MergeAndEl(const List & l)
{
	Node * tmp, * t = first, * pt = NULL, * del;
	bool bW = false;
	while( t )
	{
		tmp = l.first;
		while( tmp )
		{
			if( t->item == tmp->item )
			{
				bW = true;
				break;
			}
			tmp = tmp->next;
		}
		if( !bW )
		{
			del = t;
			if( pt )
			{
				Delete( del );
				t = pt->next;
			}
			else 
			{
				t = t->next;
				Delete( del );
			}
		}
		else
		{
			if( !pt )
			{
				pt = t;
			}
			else
			{
				pt = pt->next;
			}
			bW = false;
			t = t->next;
		}
	}
	DelDublicate();
	return true;
}

template <typename T>
bool List<T>::MergeNot2ListEl(const List & l)
{
	Node * tmp, * t = first, * pt = NULL, * del;
	bool bW = false;
	while( t )
	{
		tmp = l.first;
		while( tmp )
		{
			if( t->item == tmp->item )
			{
				bW = true;
				break;
			}
			tmp = tmp->next;
		}
		if( bW )
		{
			del = t;
			if( pt )
			{
				Delete( del );
				t = pt->next;
			}
			else 
			{
				t = t->next;
				Delete( del );
			}
			bW = false;
		}
		else
		{
			if( !pt )
			{
				pt = t;
			}
			else
			{
				pt = pt->next;
			}
			t = t->next;
		}
	}
	DelDublicate();
	return true;
}

template <typename T>
void List<T>::DelDublicate()
{
	Node * tmp = first, * del, * c;
	while( tmp )
	{
		c = tmp;
		while( c && c->next )
		{
			if( tmp->item == c->next->item )
			{
				del = c->next;
				Delete(del);
				c = c->next;
			}
			else
			{
				c = c->next;
			}
		}
		tmp = tmp->next;
	}
}

template <typename T>
bool List<T>::Dublicate()
{
	Node * tmp = first;
	while( tmp )
	{
		if( !Insert( tmp->item, tmp->item ) )
		{
			return false;
		}
		tmp = tmp->next->next;
	}
	return true;
}

template <typename T>
void List<T>::ShowRangeMinMax() const
{
	Node * tmp = first;
	const T * min = MaxMin(false);
	const T * max = MaxMin();
	while( tmp )
	{
		if( tmp->item == *min )
		{
			std::cout << "Start from minimal: " << *min << std::endl;
			tmp = tmp->next;
			while( tmp->item != *max )
			{
				std::cout << tmp->item << " ";
				tmp = tmp->next;
			}
			std::cout << std::endl << "maximal: " << *max << std::endl;
			break;
		}
		else if( tmp->item == *max )
		{
			std::cout << "Start from maximal: " << *max << std::endl;
			tmp = tmp->next;
			while( tmp->item != *min )
			{
				std::cout << tmp->item << " ";
			}
			std::cout << std::endl << "minimal: " << *min << std::endl;
			break;
		}
		tmp = tmp->next;
	}
}

template <typename T>
UI List<T>::NeighborEqual() const
{
	UI ct = 0;
	Node * prev = first, * tmp = first->next;
	while( tmp && tmp != last )
	{
		if( prev->item == tmp->next->item )
		{
			++ct;
		}
		prev = prev->next;
		tmp = tmp->next;
	}
	return ct;
}

template <typename T>
void List<T>::DelNeighborEqual()
{
	Node * prev = first, * tmp = first->next;
	while( tmp && tmp != last )
	{
		if( prev->item == tmp->next->item )
		{
			Delete(tmp);
		}
		else
		{
			prev = prev->next;
			tmp = tmp->next;
		}
	}
}

template <typename T>
List<T>::~List()
{
	//ClearList();
}
#endif