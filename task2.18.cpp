/**
* Entered from the keyboard sequence data with the results of the teams this week: 
* <Day> <Plan> <Actual output>. Print your entries in a table, sorting them in 
* ascending order plan. Identify the days of highest and lowest percentages of the plan.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

typedef unsigned short US;

const US DAY_NAME_LEN = 10;

const US MAX_DAYS = 7;

/*
* This structure describes the working team effectiveness
*/

struct Team 
{
	char day[DAY_NAME_LEN];
	US plane, fact;
	float percent;
};

/*
* @brief	This function fills the array of structure
* @param	[in. out]		pT - array of structure
* @return	void
*/

void Fill(Team * pT);

/*
* @brief	This function displays the field structure 
* @param	[in]			pT - array of structure
* @return	void
*/

void Show(const Team * pT);

/*
* @brief	This function sorts the array in descending 
*			order of the plan
* @param	[in. out]		pT - array of structure
* @return	void
*/

void Sort(Team * pT);

/*
* @brief	This function find highest percentage and lowest
*			percentage of work performed
* @param	[in]		pT - array of structure
* @param	[in, out]	min - highest percentage
* @param	[in, out]	max - lowest percentage
* @return	void
*/

void MinMax(const Team * pT, US & min, US & max);

US Min();

US Max();

int _tmain(int argc, _TCHAR* argv[])
{
	US min, max;
	Team T[MAX_DAYS];
	Fill(T);
	Sort(T);
	Show(T);
	MinMax(T, min, max);
	cout << "The day with the highest percentage of work performed: " << T[max].day << endl;
	cout << "The day with the worst percentage of work performed: " << T[min].day << endl;
	system("@pause");
	return 0;
}

void Fill(Team * pT)
{
	short temp;					/*this change is used for data entry and check their accuracy*/
	bool bNEnter = false;		/*this flag is used to know or wants to end the input user*/
	int counter = 0;			/*counter for counting the days imposed*/
	int masD[MAX_DAYS] = {0};	/*This array is used in order to know which days have introduced user*/
	while( counter < MAX_DAYS && !(bNEnter) )
	{
		temp = -1;
		while( !(temp > 0 && temp <= MAX_DAYS) )
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
			cout << "Enter number of day: ";
			cin >> temp;
			for(int i = 0; i < counter; ++i)
			{
				if(masD[i] == temp)
				{
					temp = -1;
					cout << "This day was entered. ";
					break;
				}
			}
		}
		if(bNEnter)
		{
			memcpy(pT[counter].day, "NO\0", DAY_NAME_LEN);
			pT[counter].plane = 0;
			pT[counter].fact = 0;
			pT[counter].percent = 0;
			break;
		}
		masD[counter] = temp;
		switch(temp)
		{
			case 1: memcpy(pT[counter].day, "Monday\0", DAY_NAME_LEN);
				break;
			case 2: memcpy(pT[counter].day, "Tuesday\0", DAY_NAME_LEN);
				break;
			case 3: memcpy(pT[counter].day, "Wednesday\0", DAY_NAME_LEN);
				break;
			case 4: memcpy(pT[counter].day, "Thursday\0", DAY_NAME_LEN);
				break;
			case 5: memcpy(pT[counter].day, "Friday\0", DAY_NAME_LEN);
				break;
			case 6: memcpy(pT[counter].day, "Saturday\0", DAY_NAME_LEN);
				break;
			case 7: memcpy(pT[counter].day, "Sunday\0", DAY_NAME_LEN);
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
		pT[counter].plane = temp;
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
		pT[counter].fact = temp;
		pT[counter].percent = pT[counter].fact;
		pT[counter].percent = pT[counter].percent * 100 / pT[counter].plane;
		++counter;
	}
}

void Show(const Team * pT)
{
	for(US i = 0; i < MAX_DAYS; i++)
	{
		if( 0 == (strcmp(pT[i].day, "NO") ) )
			break;
		cout << " ============================================ " << endl;
		cout << "|" << setfill('.') << setw(DAY_NAME_LEN) << pT[i].day;
		cout << "|" << setfill('.') << setw(DAY_NAME_LEN) << pT[i].plane;
		cout << "|" << setfill('.') << setw(DAY_NAME_LEN) << pT[i].fact;
		cout << "|" << setfill('.') << setw(DAY_NAME_LEN - 1) << showpoint
			<< fixed << right << setprecision(2) << pT[i].percent << "%";
		cout << "|" << endl;
		cout << " ============================================ " << endl;
	}
}

void Sort(Team * pT)
{
	US max;						/*index for max elements*/
	Team temp;					/*for change values*/
	for(US j = 0; j < MAX_DAYS; j++)
	{
		max = j;
		for(US i = j; i < MAX_DAYS; i++)
		{
			if( (pT[max].plane > pT[i].plane) && (0 != strcmp(pT[i].day, "NO") ) )
			{
				max = i;
			}
		}
		temp = pT[j];
		pT[j] = pT[max];
		pT[max] = temp;
	}
}

void MinMax(const Team * pT, US & min, US & max)
{
	min = max = 0;
	for(US j = 0; j < MAX_DAYS; j++)
	{
		if(0 == strcmp(pT[j].day, "NO") )
			break;
		if(pT[max].percent < pT[j].percent)
			{
				max = j;
			}
		if(pT[min].percent > pT[j].percent)
			{
				min = j;
			}

	}
}