/**
* entered from the keyboard sequence data on school children - participants of Olympiad: 
* <Last Name>, <First Name>, <City>, <School>, <class>. Print your entries in a table, 
* sorting them by the names of students in alphabetical order. Identify the city where 
* the Olympics came to most school children.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

const unsigned short MAX_LEN_NAME = 24;

const unsigned short MAX_LEN_CITY = 10;

/*
* This structure describes the school child: <Last Name>, <First Name>, <City>, <School>, <class>
*/

struct Schoolchild
{
	char lName[MAX_LEN_NAME], fName[MAX_LEN_NAME], city[MAX_LEN_CITY];
	unsigned int numSchool : 11, numClass : 4;
};

/*
* @brief	This function fills the structure
* @param	[in. out]		sc - struct type Schoolchild
* @return	void
*/

void Input(Schoolchild & sc);

/*
* @brief	This function displays the field structure 
* @param	[in]			sc - struct type Schoolchild
* @return	void
*/

void Show(const Schoolchild & sc);

/*
* @brief	This function displays top of table
* @return	void
*/

void Table();

/*
* @brief	This function sorts an array of structures in alphabetical order by Last name
* @param	[in, out]		mas array sort elements 0...size
* @param	[in]			Size of array
* @return	void
*/

void Sort(Schoolchild *& mas, int size);

/*
* @brief	This function sorts an array of structures in alphabetical order by City
* @param	[in, out]		mas array sort elements 0...size
* @param	[in]			Size of array
* @return	void
*/

void SortCity(Schoolchild *& mas, int size);

/*
* @brief	This function return the city where the Olympics came to most school children.
* @param	[in, out]		mas array sort elements 0...size
* @param	[in]			Size of array
* @return	void
*/

char * HMCity(Schoolchild *& mas, int size);

int _tmain(int argc, _TCHAR* argv[])
{
	Schoolchild sc;
	int HMC = 0;				/*How much contest participants*/
	cout << "How much contest participants: ";
	cin >> HMC;
	/*checking for input*/
	while(!cin)
	{
		cin.clear();
		cin.get();
		cin >> HMC;
	}
	while(cin.get() != '\n')
		;
	Schoolchild * pS = new Schoolchild[HMC];
	int i;						/*counter for cycle "for"*/
	/*filling an array of structures*/
	for(i = 0; i < HMC; ++i)
	{
		Input(sc);
		pS[i] = sc;
		cout << "Next:\n";
	}
	/*sort and displays result*/
	Sort(pS, HMC);
	Table();
	for(i = 0; i < HMC; ++i)
		Show(pS[i]);
	cout << " ============================================================================= " << endl;
	SortCity(pS, HMC);
	cout << "The most active city: " << HMCity(pS, HMC) << endl;
	system("@pause");
	return 0;
}

void Input(Schoolchild & sc)
{
	int iTmp = 0;
	cout << "Enter last name: ";
	cin >> sc.lName;
	cout << "Enter first name: ";
	cin >> sc.fName;
	cout << "Enter city: ";
	cin >> sc.city;
	/*checking for input*/
	while( !((iTmp > 0) && (iTmp < 1500)) )
	{
		if(!cin)
		{
			cin.clear();
			cin.get();
		}
		cout << "Enter school number (max 1500): ";
		cin >> iTmp;
	}
	sc.numSchool = iTmp;
	iTmp = 0;
	/*checking for input*/
	while( !((iTmp > 0) && (iTmp <= 12)) )
	{
		if(!cin)
		{
			cin.clear();
			cin.get();
		}
		cout << "Enter number of class (max 12): ";
		cin >> iTmp;
	}
	sc.numClass = iTmp;
	cin.get();
}

void Show(const Schoolchild & sc)
{
	cout << " ============================================================================= " << endl;
	cout << "|" << setfill('.') << setw(MAX_LEN_NAME) << sc.lName;
	cout << "|" << setfill('.') << setw(MAX_LEN_NAME) << sc.fName;
	cout << "|" << setfill('.') << setw(14) << sc.city;
	cout << "|" << setfill('.') << setw(6) <<sc.numSchool;
	cout << "|" << setfill('.') << setw(5) << sc.numClass;
	cout << "|" << endl;
}

void Table()
{
	cout << " ============================================================================= " << endl;
	cout << "|" << setfill('.') << setw(17) << "Last Name" << setw(8) << setfill('.') 
		<< "|" << setfill('.') << setw(17) << "First Name" << setw(8) << setfill('.')
		<< "|" << setfill('.') << setw(9) << "City" << setw(6) << setfill('.')
		<< "|" << setfill('.') << setw(6) << "School";
	cout << "|" << setfill('.') << setw(2) << "Class";
	cout << "|" << endl;
}

void Sort(Schoolchild *& mas, int size)
{
	int min;			/*index for min elements*/
	Schoolchild temp;	/*for change values*/
	for(int j = 0; j < size; j++)
	{
		min = j;
		for(int i = j; i < size; i++)
		{
			if(0 < (strcmp(mas[min].lName, mas[i].lName) ) )
				min = i;
		}
		temp = mas[j];
		mas[j] = mas[min];
		mas[min] = temp;
	}
}

void SortCity(Schoolchild *& mas, int size)
{
	int min;
	Schoolchild temp;
	for(int j = 0; j < size; j++)
	{
		min = j;
		for(int i = j; i < size; i++)
		{
			if(0 < (strcmp(mas[min].city, mas[i].city) ) )
				min = i;
		}
		temp = mas[j];
		mas[j] = mas[min];
		mas[min] = temp;
	}
}

char * HMCity(Schoolchild *& mas, int size)
{
	/*define how much different city*/
	int howMuch = 1;			/*counter for city*/
	char tCity[MAX_LEN_CITY];
	memcpy(tCity, mas[0].city, MAX_LEN_CITY);
	for(int i = 1; i < size; i++)
	{
		if(0 == (strcmp(tCity, mas[i].city) ) )
			;
		else
		{
			memcpy(tCity, mas[i].city, MAX_LEN_CITY);
			++howMuch;
		}
	}
	
	int * temp = new int[howMuch];	/*create a new array where each repetition of recorded*/
	int cities = howMuch;			/*how much different city*/
	howMuch = 1;					/*now this value to count how much of one city*/
	int count = 0;					/*city counter*/
	memcpy(tCity, mas[0].city, MAX_LEN_CITY);
	/*incorporation of repetitions of each city*/
	for(int i = 1; i < size; i++)
	{
		if(0 == (strcmp(tCity, mas[i].city) ) )
		{
			++howMuch;
			temp[count] = howMuch;
		}
		else
		{
			temp[count] = howMuch;
			++count;
			howMuch = 1;
			memcpy(tCity, mas[i].city, MAX_LEN_CITY);
		}
	}
	temp[count] = howMuch;
	/*determination of which city have entered the most*/
	int max = 0;
	for(int i = 1; i < cities; i++)
	{
		if(temp[max] < temp[i])
			max = i;
	}
	delete [] temp;
	if(max == 0)
		return mas[max].city;
	howMuch = 0;
	for(int i = 1; i < size; i++)
	{
		if(0 == (strcmp(tCity, mas[i].city) ) )
			;
		else
		{
			memcpy(tCity, mas[i].city, MAX_LEN_CITY);
			++howMuch;
			if(howMuch == max)
				break;
		}
	}
	return mas[max].city;
}
