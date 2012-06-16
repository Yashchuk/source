/**
* Entered from the keyboard sequence data on monthly results of the craft: 
* <Number of the month> <Plan> <Actual production>. Print your entries in a table,
* sorting them in descending order of percentage of the plan. The table numbers to 
* replace names of their months.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

typedef unsigned short US;

const US MONTH_NAME_LEN = 10;

const US MAX_MONTH = 12;

/*
* This structure describes the craft effectiveness
*/

struct Craft 
{
	char mouth[MONTH_NAME_LEN];
	US plane, fact;
	float percent;
};

/*
* @brief	This function fills the array of structure
* @param	[in. out]		c - array of structure
* @return	void
*/

void Fill(Craft * c);

/*
* @brief	This function displays the field structure 
* @param	[in]			c - array of structure
* @return	void
*/

void Show(const Craft * c);

/*
* @brief	This function sorts the array in descending 
*			order of percentage of the plan
* @param	[in. out]		c - array of structure
* @return	void
*/

void Sort(Craft * c);

int _tmain(int argc, _TCHAR* argv[])
{
	Craft c[MAX_MONTH];
	Fill(c);
	Sort(c);
	Show(c);
	system("@pause");
	return 0;
}

void Fill(Craft * c)
{
	short temp;					/*this change is used for data entry and check their accuracy*/
	bool bNEnter = false;		/*this flag is used to know or wants to end the input user*/
	int counter = 0;			/*counter for counting the months imposed*/
	int masM[MAX_MONTH] = {0};	/*This array is used in order to know which months have introduced user*/
	while( counter < MAX_MONTH && !(bNEnter) )
	{
		temp = -1;
		while( !(temp > 0 && temp <= MAX_MONTH) )
		{
			if(!cin)
			{
				cin.clear();
				while(cin.get() != '\n')
				{
					/*NULL*/
				}
			}
			if(temp == 0)
			{
				bNEnter = true;
				break;
			}
			cout << "Enter number of month: ";
			cin >> temp;
			for(int i = 0; i < counter; ++i)
			{
				if(masM[i] == temp)
				{
					temp = -1;
					cout << "This month was entered. ";
					break;
				}
			}
		}
		if(bNEnter)
		{
			memcpy(c[counter].mouth, "NO\0", MONTH_NAME_LEN);
			c[counter].plane = 0;
			c[counter].fact = 0;
			c[counter].percent = 0;
			break;
		}
		masM[counter] = temp;
		switch(temp)
		{
			case 1: memcpy(c[counter].mouth, "January\0", MONTH_NAME_LEN);
				break;
			case 2: memcpy(c[counter].mouth, "February\0", MONTH_NAME_LEN);
				break;
			case 3: memcpy(c[counter].mouth, "March\0", MONTH_NAME_LEN);
				break;
			case 4: memcpy(c[counter].mouth, "April\0", MONTH_NAME_LEN);
				break;
			case 5: memcpy(c[counter].mouth, "May\0", MONTH_NAME_LEN);
				break;
			case 6: memcpy(c[counter].mouth, "June\0", MONTH_NAME_LEN);
				break;
			case 7: memcpy(c[counter].mouth, "July\0", MONTH_NAME_LEN);
				break;
			case 8: memcpy(c[counter].mouth, "August\0", MONTH_NAME_LEN);
				break;
			case 9: memcpy(c[counter].mouth, "September\0", MONTH_NAME_LEN);
				break;
			case 10: memcpy(c[counter].mouth, "October\0", MONTH_NAME_LEN);
				break;
			case 11: memcpy(c[counter].mouth, "November\0", MONTH_NAME_LEN);
				break;
			case 12: memcpy(c[counter].mouth, "December\0", MONTH_NAME_LEN);
				break;
		}
		temp = 0;
		while(temp < 1)
		{
			if(!cin)
			{
				cin.clear();
				while(cin.get() != '\n')
				{
					/*NULL*/
				}
			}
			cout << "Enter plane: ";
			cin >> temp;
		}
		c[counter].plane = temp;
		temp = -1;
		while(temp < 0)
		{
			if(!cin)
			{
				cin.clear();
				while(cin.get() != '\n')
				{
					/*NULL*/
				}
			}
			cout << "Enter facts: ";
			cin >> temp;
		}
		c[counter].fact = temp;
		c[counter].percent = c[counter].fact;
		c[counter].percent = c[counter].percent * 100 / c[counter].plane;
		++counter;
	}
}

void Show(const Craft * c)
{
	for(US i = 0; i < MAX_MONTH; i++)
	{
		if( 0 == (strcmp(c[i].mouth, "NO") ) )
			break;
		cout << " ============================================ " << endl;
		cout << "|" << setfill('.') << setw(MONTH_NAME_LEN) << c[i].mouth;
		cout << "|" << setfill('.') << setw(MONTH_NAME_LEN) << c[i].plane;
		cout << "|" << setfill('.') << setw(MONTH_NAME_LEN) << c[i].fact;
		cout << "|" << setfill('.') << setw(MONTH_NAME_LEN - 1) << showpoint
			<< fixed << right << setprecision(2) << c[i].percent << "%";
		cout << "|" << endl;
		cout << " ============================================ " << endl;
	}
}

void Sort(Craft * c)
{
	US max;				/*index for max elements*/
	Craft temp;				/*for change values*/
	for(US j = 0; j < MAX_MONTH; j++)
	{
		max = j;
		for(US i = j; i < MAX_MONTH; i++)
		{
			if(c[max].percent < c[i].percent)
			{
				max = i;
			}
		}
		temp = c[j];
		c[j] = c[max];
		c[max] = temp;
	}
}