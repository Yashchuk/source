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
	char month[MONTH_NAME_LEN];
	US plane, fact;
	float percent;
};

/*
* @brief	This function fills the array of structure
*			and sorting them during input
* @param	[in. out]		c - array of structure
* @return	void
*/

void Fill(Craft * c);

/*
* @brief	This function displays the field structure 
* @param	[in]			c - array of structure
* @return	void
*/

void Show(Craft * c);

/*
* @brief	This function displays table begin 
* @return	void
*/

inline void Table();

int _tmain(int argc, _TCHAR* argv[])
{
	Craft c[MAX_MONTH];
	Fill(c);
	Show(c);
	system("@pause");
	return 0;
}

void Fill(Craft * c)
{
	short temp;					/*this change is used for data entry and check their accuracy in tC*/
	Craft tC;					/*this struct is used for data entry and check their accuracy*/
	bool bNEnter = false;		/*this flag is used to know wants user to end the input*/
	bool bChange = false;		/*this flag is used to know was the shift block memory*/
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
			cout << "Enter number of month: ";
			cin >> temp;
			if(temp == 0)
			{
				bNEnter = true;
				break;
			}
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
			memcpy(c[counter].month, "NO\0", MONTH_NAME_LEN);
			c[counter].plane = 0;
			c[counter].fact = 0;
			c[counter].percent = 0;
			break;
		}
		masM[counter] = temp;
		switch(temp)
		{
			case 1: memcpy(tC.month, "January\0", MONTH_NAME_LEN);
				break;
			case 2: memcpy(tC.month, "February\0", MONTH_NAME_LEN);
				break;
			case 3: memcpy(tC.month, "March\0", MONTH_NAME_LEN);
				break;
			case 4: memcpy(tC.month, "April\0", MONTH_NAME_LEN);
				break;
			case 5: memcpy(tC.month, "May\0", MONTH_NAME_LEN);
				break;
			case 6: memcpy(tC.month, "June\0", MONTH_NAME_LEN);
				break;
			case 7: memcpy(tC.month, "July\0", MONTH_NAME_LEN);
				break;
			case 8: memcpy(tC.month, "August\0", MONTH_NAME_LEN);
				break;
			case 9: memcpy(tC.month, "September\0", MONTH_NAME_LEN);
				break;
			case 10: memcpy(tC.month, "October\0", MONTH_NAME_LEN);
				break;
			case 11: memcpy(tC.month, "November\0", MONTH_NAME_LEN);
				break;
			case 12: memcpy(tC.month, "December\0", MONTH_NAME_LEN);
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
		tC.plane = temp;
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
		tC.fact = temp;
		tC.percent = tC.fact;
		tC.percent = tC.percent * 100 / tC.plane;
		/*if the first value it writes to the array, else do check if the structure is greater % than put before it, 
		if so then inserts it into a position that is less than it shifts block of memory, if not record in the last entry in the array*/
		if(counter)
		{
			for(int i = 0; i < counter; ++i)
			{
				if(tC.percent >  c[i].percent)
				{
					memmove( (&c[i] + 1), &c[i], (sizeof(*c) * (MAX_MONTH - i - 1) ) );
					memcpy(c[i].month, tC.month, MONTH_NAME_LEN);
					c[i].plane = tC.plane;
					c[i].fact = tC.fact;
					c[i].percent = tC.percent;
					bChange = true;
					break;
				}
			}
			if(!bChange)
			{
				memcpy(c[counter].month, tC.month, MONTH_NAME_LEN);
				c[counter].plane = tC.plane;
				c[counter].fact = tC.fact;
				c[counter].percent = tC.percent;
				c[counter] = tC;
			}
			bChange = false;
		}
		else
		{
			memcpy(c[counter].month, tC.month, MONTH_NAME_LEN);
			c[counter].plane = tC.plane;
			c[counter].fact = tC.fact;
			c[counter].percent = tC.percent;
		}
		++counter;
	}
}

void Show(Craft * c)
{
	Table();
	for(US i = 0; i < MAX_MONTH; i++)
	{
		if( 0 == (strcmp(c[i].month, "NO") ) )
			break;
		cout << "|" << setfill('.') << setw(MONTH_NAME_LEN) << c[i].month;
		cout << "|" << setfill('.') << setw(MONTH_NAME_LEN) << c[i].plane;
		cout << "|" << setfill('.') << setw(MONTH_NAME_LEN) << c[i].fact;
		cout << "|" << setfill('.') << setw(MONTH_NAME_LEN - 1) << showpoint
			<< fixed << right << setprecision(2) << c[i].percent << "%";
		cout << "|" << endl;
		cout << " =========================================== " << endl;
	}
}

inline void Table()
{
	cout << " =========================================== " << endl;
	cout << "|" << setfill('.') << setw(MONTH_NAME_LEN) << "Month";
	cout << "|" << setfill('.') << setw(MONTH_NAME_LEN) << "Plane";
	cout << "|" << setfill('.') << setw(MONTH_NAME_LEN) << "Fact";
	cout << "|" << setfill('.') << setw(MONTH_NAME_LEN) << "Persent";
	cout << "|" << endl;
	cout << " =========================================== " << endl;
}