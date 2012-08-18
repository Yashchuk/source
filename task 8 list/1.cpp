// 1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ListOneF.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	List<int> * a = new List<int>;
	a->PushBack(12);
	a->PushBack(13);
	a->PushFront(11);
	a->PushFront(10);
	a->PushBack(12);
	a->PushBack(12);
	a->DelNeighborEqual();
	a->Show();
	std::cout << "size: " << a->Size() << std::endl;
//	cout << "Equal neighbor: " << a->NeighborEqual() << endl;
/*	a->PopBack();
	a->PopFront();
	a->Show();
	std::cout << "size: " << a->Size() << std::endl;
	a->Insert(11, 6);
	a->Show();
	std::cout << "size: " << a->Size() << std::endl;
	a->Delete((UI)1);
	a->Show();
	std::cout << "size: " << a->Size() << std::endl;
	a->Delete(11);
	a->Show();
	std::cout << "size: " << a->Size() << std::endl;
	std::cout << "max: " << a->MaxMin() << std::endl;
	std::cout << "min: " << a->MaxMin(false) << std::endl;
	a->SortMaxMin();
	std::cout << "sortminmax: " << a->SortMinToMax() << std::endl;
	a->Show();
	a->SortMaxMin(false);
	std::cout << "sortminmax: " << a->SortMinToMax() << std::endl;
	a->Show();
	std::cout << "b: " << std::endl;
	List<int> * b = new List<int>;
	b->PushBack(1111);
	*b = *a;
	b->Show();
	std::cout << "size b: " << b->Size() << std::endl;
	b->PushFront(1);
	b->PushFront(2);
	b->PushBack(2);
	std::cout << "Range max min" << std::endl;
	b->ShowRangeMinMax();
	b->DelDublicate();
	std::cout << "MergeOneEl: " << std::endl;
	a->MergeOneEl(*b);
	a->Show();
	std::cout << "size a: " << a->Size() << std::endl;
	b->PopFront();
	b->PopBack();
	b->Show();
	std::cout << "MergeAndEl: " << std::endl;
	a->PushBack(10);
	a->MergeAndEl(*b);
	a->Show();
	std::cout << "size a: " << a->Size() << std::endl;
	std::cout << "MergeNot2ListEl: " << std::endl;
	a->PushBack(11111);
	a->MergeNot2ListEl(*b);
	a->Show();
	std::cout << "size a: " << a->Size() << std::endl;
	a->Dublicate();
	a->Show();
	std::cout << "size a: " << a->Size() << std::endl;*/
	system("@pause");
	return 0;
}

