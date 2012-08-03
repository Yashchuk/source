#ifndef LIST_H_
#define LIST_H_

typedef unsigned int UI;

template<typename Any>
class List
{
private:
	UI size;
	Any a;
/*	struct Node
	{
		Any item;
		Node * next;
		Node * prev;
	};
	Node * first;
	Node * last;*/
public:
	List(Any item);
	~List();
};

#endif