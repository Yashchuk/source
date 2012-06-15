/**
* Entered from the keyboard to enter data set of books in the form 
* <author> <name>, <Year> <Notes>. Print your entries in a table, 
* sorting them in alphabetical order by author's name. Print a list 
* of books published in 1970.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

typedef unsigned short US;

const US MAX_LEN_AUTHOR = 20;

const US MAX_LEN_NAME = 34;

const US MAX_LEN_NOTE = 15;

const US MAX_YEAR = 2012; 

const US MIN_YEAR = 1920; 

struct Book
{
	char author[MAX_LEN_AUTHOR], name[MAX_LEN_NAME], note[MAX_LEN_NOTE];
	unsigned int year : 11;
};

/*
* @brief	This function fills the structure
* @param	[in. out]		bk - struct type Book
* @return	void
*/

void Insert(Book & bk);

/*
* @brief	This function sorts an array of structures in alphabetical order by Author
* @param	[in, out]		mas array sort elements 0...size
* @param	[in]			Size of array
* @return	void
*/

void Sort(Book *& mas, int size);

/*
* @brief	This function displays the field structure 
* @param	[in]			bk - struct type Book
* @return	void
*/

void Show(const Book & bk);

/*
* @brief	This function displays table
* @param	[in]		mas array of struct book
* @param	[in]		how much book
* @return	void
*/

void Table(Book *& mas, int HB);

int _tmain(int argc, _TCHAR* argv[])
{
	int HB = 0;				/*How much book*/
	cout << "How much book: ";
	cin >> HB;
	/*checking for Insert*/
	while(!cin)
	{
		cin.clear();
		cin.get();
		cin >> HB;
	}
	while(cin.get() != '\n')
	{
			/*NULL*/
	}
	Book * pB = new Book[HB];
	int i;						/*counter for cycle "for"*/
	/*filling an array of structures*/
	for(i = 0; i < HB; ++i)
	{
		Insert(bk);
		pB[i] = bk;
		cout << "Next:\n";
	}
	/*sort and displays result*/
	Sort(pB, HB);
	Table(pB, HB);
	cout << "Book publicated before 1970:\n";
	for(i = 0; i < HB; ++i)
	{
		if(pB[i].year < 1970)
		{
			Show(pB[i]);
		}
	}
	delete [] pB;
	cout << " ============================================================================= " << endl;
	system("@pause");
	return 0;
}

void Insert(Book & bk)
{
	int iTmp = 0;
	cout << "Enter Author (Ex.: Prata S.): ";
	cin.getline(bk.author, MAX_LEN_AUTHOR);
	cout << "Enter book name: ";
	cin.getline(bk.name, MAX_LEN_NAME);
	/*checking for Insert*/
	while( !((iTmp >= MIN_YEAR) && (iTmp <= MAX_YEAR)) )
	{
		if(!cin)
		{
			cin.clear();
			while(cin.get() != '\n')
			{
				/*NULL*/
			}
		}
		cout << "Enter publication year ( min - 1920, max - 2012): ";
		cin >> iTmp;
	}
	bk.year = iTmp;
	while(cin.get() != '\n')
	{
		 /*NULL*/
	}
	cout << "Enter note: ";
	cin.getline(bk.note, MAX_LEN_NOTE);
}

void Sort(Book *& mas, int size)
{
	int min;			/*index for min elements*/
	Book temp;			/*for change values*/
	for(int j = 0; j < size; j++)
	{
		min = j;
		for(int i = j; i < size; i++)
		{
			if(0 < (strcmp(mas[min].author, mas[i].author) ) )
			{
				min = i;
			}
		}
		temp = mas[j];
		mas[j] = mas[min];
		mas[min] = temp;
	}
}

void Show(const Book & bk)
{
	cout << " ============================================================================= " << endl;
	cout << "|" << setfill('.') << setw(MAX_LEN_AUTHOR) << bk.author;
	cout << "|" << setfill('.') << setw(MAX_LEN_NAME) << bk.name;
	cout << "|" << setfill('.') << setw(4) << bk.year;
	cout << "|" << setfill('.') << setw(MAX_LEN_NOTE) <<bk.note;
	cout << "|" << endl;
}

void Table(Book *& mas, int HB)
{
	cout << " ============================================================================= " << endl;
	cout << "|" << setfill('.') << setw(13) << "Author" << setw(8) << setfill('.') 
		<< "|" << setfill('.') << setw(20) << "Name" << setw(15) << setfill('.')
		<< "|" << setfill('.') << setw(4) << "Year" << setw(0) << setfill('.')
		<< "|" << setfill('.') << setw(10) << "Note" << setw(6) << setfill('.');
	cout << "|" << endl;
	for(int i = 0; i < HB; ++i)
	{
		Show(mas[i]);
	}
	cout << " ============================================================================= " << endl;
}