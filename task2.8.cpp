/**
* Entered from the keyboard sequence data, which are the coordinates (x, y, z)
* spatial points. Print your entries in a table, sorting them in increasing coordinate z.
* Identify two spatial point, the distance between which is the smallest.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cmath>

using namespace std;

typedef signed short SS;

typedef unsigned int UI;

/*
* This structure describes the coordinates
*/

struct Dot
{
	SS x, y, z;
};

/*
* @brief	This function fills the array of structure
*			and sorting them during input
* @param	[in. out]		d - array of structure
* @param	[in]			ct - how much elements
* @return	void
*/

void Fill(Dot * d, UI ct);

/*
* @brief	This function displays the field structure 
* @param	[in]			d - array of structure
* @param	[in]			ct - how much elements
* @return	void
*/

void Show(const Dot * d, UI ct);

/*
* @brief	This function search two points the distance 
*			between which is the smallest.
* @param	[in]			d - array of structure
* @param	[in]			ct - how much elements
* @param	[in, out]		n1 - first point
* @param	[in, out]		n2 - second point
* @return	void
*/

void SearchNeighbor(const Dot * d, UI ct, UI & n1, UI & n2);

/*
* @brief	This function return distance between points
* @param	[in]			d1 - first points
* @param	[in]			d2 - first points
* @return	float
*/

float Dis(const Dot * d1, const Dot * d2);

/*
* @brief	This function displays table begin 
* @return	void
*/

inline void Table();

int _tmain(int argc, _TCHAR* argv[])
{
	Dot * pD = NULL;
	char choice;
	UI counter = 0, neighbor1, neighbor2;
	cout << "If you want to enter coordinat press 'Y': ";
	cin >> choice;
	while(cin.get() != '\n')
	{
		/*NULL*/
	}
	while(toupper(choice) == 'Y')
	{
		++counter;
		pD = (Dot *) realloc(pD, sizeof(*pD) * counter);
		Fill(pD, counter);
		cout << "If you want to enter koordinat press 'Y': ";
		cin >> choice;
	}
	Show(pD, counter);
	SearchNeighbor(pD, counter, neighbor1, neighbor2);
	cout << "The smallest distance between " << neighbor1 << " and " <<  neighbor2 << endl;
	pD = (Dot *) realloc(pD, 0);
	system("@pause");
	return 0;
}

void Fill(Dot * d, UI ct)
{
	--ct;
	SS temp;						/*this change is used for data entry and check their accuracy in dtemp*/
	Dot dtemp;						/*this struct is used for data entry and check their accuracy*/
	bool bChange = false;			/*this flag is used to know was the shift block memory*/
	cout << "Enter x koordinat: ";
	cin >> temp;
	while(!cin)
	{
		cin.clear();
		while(cin.get() != '\n')
		{
			/*NULL*/
		}
		cout << "Enter x koordinat (only number): ";
		cin >> temp;
	}
	dtemp.x = temp;
	cout << "Enter y koordinat: ";
	cin >> temp;
	while(!cin)
	{
		cin.clear();
		while(cin.get() != '\n')
		{
			/*NULL*/
		}
		cout << "Enter y koordinat (only number): ";
		cin >> temp;
	}
	dtemp.y = temp;
	cout << "Enter z koordinat: ";
	cin >> temp;
	while(!cin)
	{
		cin.clear();
		while(cin.get() != '\n')
		{
			/*NULL*/
		}
		cout << "Enter z koordinat (only number): ";
		cin >> temp;
	}
	dtemp.z = temp;
	while(cin.get() != '\n')
	{
		/*NULL*/
	}
	/*if the first value it writes to the array, else do check if the structure is smaller coordinat z than put before it, 
	if so then inserts it into a position that is less than it shifts block of memory, if not record in the last entry in the array*/
	if(ct)
		{
			for(UI i = 0; i < ct; ++i)
			{
				if(dtemp.z <  d[i].z)
				{
					memmove( (&d[i] + 1), &d[i], (sizeof(*d) * (ct - i) ) );
					d[i] = dtemp;
					bChange = true;
					break;
				}
			}
			if(!bChange)
			{
				d[ct] = dtemp;
			}
			bChange = false;
		}
		else
			*d = dtemp;
}

void Show(const Dot * d, UI ct)
{
	Table();
	for(UI i = 0; i < ct; i++)
	{
		cout << "|" << setfill('.') << setw(3) << i + 1;
		cout << "|" << setfill('.') << setw(3) << d[i].x;
		cout << "|" << setfill('.') << setw(3) << d[i].y;
		cout << "|" << setfill('.') << setw(3) << d[i].z;
		cout << "|" << endl;
		cout << " =============== " << endl;
	}
}

inline void Table()
{
	cout << " =============== " << endl;
	cout << "|" << setfill('.') << setw(3) << "#";
	cout << "|" << setfill('.') << setw(3) << "X";
	cout << "|" << setfill('.') << setw(3) << "Y";
	cout << "|" << setfill('.') << setw(3) << "Z";
	cout << "|" << endl;
	cout << " =============== " << endl;
}

void SearchNeighbor(const Dot * d, UI ct, UI & n1, UI & n2)
{
	float distance = Dis(&d[0], &d[1]);
	n1 = 1;
	n2 = 2;
	for(UI i = 1; i < ct - 1; ++i)
	{
		for(UI j = i + 1; j < ct; ++j)
		{
			if(distance > Dis(&d[i], &d[j]) )
			{
				distance = Dis(&d[i], &d[j]);
				n1 = i + 1;
				n2 = j + 1;
			}
		}
	}
}

float Dis(const Dot * d1, const Dot * d2)
{
	return sqrt( abs( pow( (float)(d2->x - d1->x), 2) + pow( (float)(d2->y - d1->y), 2) + pow( (float)(d2->z - d1->z), 2) ) );
}