// 8.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "List.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	List<int> * a = new List<int>;
	int zm;
	cout << "ZM: ";
	cin >> zm;
	while( zm )
	{
		a->PushBack(zm);
		cout << "ZM: ";
		cin >> zm;
	}
	cout << "a size: " << a->Size() << endl;
	a->Sort();
	a->Show();
/*	a->Show();
	a->PopBack();
	a->Show();
	a->PopFront();
	a->Show();
	cout << "ADD ZM: ";
	cin >> zm;
	int index;
	cout << "Index: ";
	cin >> index;
	a->Insert(zm, index);
	a->Show();
	cout << "size: " << a->Size() << endl;
	cout << "DEL Index: ";
	cin >> index;
	a->Erase(index);
	a->Show();
	cout << "size: " << a->Size() << endl;
	cout << "!!!!!!!!!!!!!!!!!!" << endl;
	List<int> * b = new List<int>(*a);
	cout << "B:" << endl;
	b->Show();
	cout << "b size: " << a->Size() << endl;
	List<int> * c = new List<int>;
	cout << "ZM: ";
	cin >> zm;
	while( zm )
	{
		c->PushBack(zm);
		cout << "ZM: ";
		cin >> zm;
	}
//	b->MergeAND(*c);
	b->MergeNOT2List(*c);
	cout << "B after MergeNOT2List" << endl;
	b->Show();
	cout << "b size: " << b->Size() << endl;*/
	system("@pause");
	return 0;
}

