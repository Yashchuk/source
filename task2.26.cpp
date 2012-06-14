/*
* Entered from the keyboard sequence of records containing
* data on the results of the session students groups: <first name>,
* <last name> <rating>. Print your entries in a table, sorting them
* in descending order of rating score of the student. Determine the
* percentage of students rating score greater than 70.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

typedef unsigned short US;
typedef unsigned int UI;

const US MAX_LEN_NAME = 24;

const US MIN_RATING = 70;

/*
* This structure describes the student: <Last Name>, <First Name>, <rating>
*/

struct Student
{
	char lName[MAX_LEN_NAME], fName[MAX_LEN_NAME];
	US rating : 7;
};

/*
* @brief	This function fills the structure
* @param	[in. out]		st - struct type Student
* @return	void
*/

void Insert(Student * st);

/*
* @brief	This function displays the field structure 
* @param	[in, out]		st - struct type Student
* @param	[in]			size of array
* @return	void
*/

void Show(Student ** st, UI size);

/*
* @brief	This function sorts the array in descending 
*			order of rating score of the student
* @param	[in. out]		st - struct type Student
* @param	[in]			size of array
* @return	void
*/

void Sort(Student ** st, UI size);

/*
* @brief	This function fills the array of structures
* @param	[in. out]		st - struct type Student
* @param	[in]			size of array
* @return	void
*/

void Fill(Student ** st, UI size, UI * f);

/*
* @brief	This function determines the percentage
*			of students rating score greater than 70.
* @param	[in. out]		st - struct type Student
* @param	[in]			size of array
* @return	float
*/

float PerStu(Student ** st, UI size);

int _tmain(int argc, _TCHAR* argv[])
{
	UI HMS = 0;				/*how much student*/
	UI fact = 0;
	cout << "How much Student: ";
	cin >> HMS;
	/*checking for Insert*/
	while(!cin)
	{
		cin.clear();
		while(cin.get() != '\n')
		{
			//NULL
		}
		cin >> HMS;
	}
	while(cin.get() != '\n')
	{
			//NULL
	}
	try
	{
		Student ** ppS = new Student * [HMS];
		for(UI i = 0; i < HMS; i++)
		{
			ppS[i] = NULL;
		}
		Fill(ppS, HMS, &fact);
		Sort(ppS, fact);
		Show(ppS, fact);
		cout << showpoint << fixed << right << setprecision(2) << PerStu(ppS, fact) << "% of "
			"students had rating > 70." << endl;
		for(UI i = 0; i < fact; i++)
		{
			delete ppS[i];
		}
		delete [] ppS;
	}
	catch(bad_alloc & ba)
	{
		cout << ba.what() << endl;
		exit(EXIT_FAILURE);
	}
	system("@pause");
	return 0;
}

void Insert(Student * st)
{
	int iTmp = 0;
	cout << "If you want to end input enter \"0\"\n";
	cout << "Enter last name: ";
	cin >> st->lName;
	st->lName[MAX_LEN_NAME - 1] = '/0';
	if(st->lName[0] == '0')
		memcpy(st->lName, "No name\0", 8);
	cout << "Enter first name: ";
	cin >> st->fName;
	st->lName[MAX_LEN_NAME - 1] = '/0';
	if(st->fName[0] == '0')
		memcpy(st->lName, "No name\0", 8);
	/*checking for Insert*/
	while( !((iTmp >= 50) && (iTmp <= 100)) )
	{
		if(!cin)
		{
			cin.clear();
			while(cin.get() != '\n')
			{
				/*NULL*/
			}
		}
		cout << "Enter rating score: ";
		cin >> iTmp;
	}
	st->rating = iTmp;
	while(cin.get() != '\n')
	{
		/*NULL*/
	}
}

void Show(Student ** st, UI size)
{
	for(UI i = 0; i < size; i++)
	{
		cout << " ===================================================== " << endl;
		cout << "|" << setfill('.') << setw(MAX_LEN_NAME) << st[i]->fName;
		cout << "|" << setfill('.') << setw(MAX_LEN_NAME) << st[i]->lName;
		cout << "|" << setfill('.') << setw(3) << st[i]->rating;
		cout << "|" << endl;
		cout << " ===================================================== " << endl;
	}
}

void Sort(Student ** st, UI size)
{
	int min;			/*index for min elements*/
	Student * temp;			/*for change values*/
	for(UI j = 0; j < size; j++)
	{
		min = j;
		for(UI i = j; i < size; i++)
		{
			if(st[min]->rating < st[i]->rating)
			{
				min = i;
			}
		}
		temp = st[j];
		st[j] = st[min];
		st[min] = temp;
	}
}

void Fill(Student ** st, UI size, UI * f)
{
	Student stu;
	for(UI i = 0; i < size; i++)
	{
		Insert(&stu);
		if( ( !(strcmp(stu.lName, "No name") ) ) || ( !(strcmp(stu.fName, "No name") ) ) )
		{
			break;
		}
		st[i] = new Student;
		*st[i] = stu;
		++(*f);
	}
}

float PerStu(Student ** st, UI size)
{
	UI counter = 0;
	for(UI i = 0; i < size; i++)
	{
		if(st[i]->rating > MIN_RATING)
		{
			++counter;
		}
	}
	float percent = counter;
	percent = (percent * 100) / size;
	return percent;
}