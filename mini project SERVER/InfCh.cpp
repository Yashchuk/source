#include "stdafx.h"
#include "InfCh.h"
#include <fstream>

InfCh::InfCh()
{
	buf = new char[MAX_DATA];
	if( !buf )
	{
		throw 1;
	}
	path = new wchar_t[MAX_PATH];
	if( !path )
	{
		delete buf;
		throw 1;
	}
	fsu.dfs = 0;
	b_recv = 0;
}

bool InfCh::PathRec(Client * cl)
{
	std::cout << "Waiting path... " << std::endl;
	b_recv = recv(cl->GetSCL(), buf, MAX_DATA - 2, 0); 
	if( (b_recv > 0) && (b_recv != USHRT_MAX) )
	{
		buf[b_recv] = buf[b_recv + 1] = '\0';
		memcpy(path, buf, b_recv + 2);
		std::wcout << "PATH: " << path << std::endl;
		return true;
	}
	std::cout << "Connection canceled" << std::endl;
	return false;
}

unsigned char InfCh::Decrypt(unsigned short val, unsigned short d, unsigned short n)
{
	unsigned int tmp = val;
	while(d - 1)
	{
		tmp *= val;
		if( tmp > n )
		{
			tmp %= n;
		}
		--d;
	}
	return tmp;
}

bool InfCh::CreatePath() const
{
	if ( !path )
	{
		return false;
	}
	if ( wcslen(path) > MAX_PATH )
	{
		return false;
	}
	for (unsigned short i = 0; i <= wcslen(path); i++)
	{
		if ( path[i] == L'\\' )
		{
			wchar_t* directory = (wchar_t*)malloc( ( sizeof(wchar_t) * i ) + sizeof(wchar_t) );
			if ( ! directory )
			{
				return false;
			}
			memcpy( directory,path,sizeof(wchar_t)* i );
			directory[i] = L'\0';
			if ( ! CreateDirectory(directory,NULL) ) 
			{
				continue;
			}
			free(directory);
		}
	}
	return true;
}

bool InfCh::SizeRec(Client * cl)
{
	b_recv = recv(cl->GetSCL(), buf, MAX_DATA, 0);
	if( (b_recv > 0) && (b_recv != USHRT_MAX) ) //connection canceled
	{
		memcpy(fsu.cfs, buf, b_recv);
		std::cout << "file size: " << fsu.dfs << std::endl;
		fsu.dfs *= 2;
		return true;
	}
	else
	{
		std::cout << "Connection canceled" << std::endl;
		return false;
	}
}

bool InfCh::DataRec(Client * cl, Keys * k)
{
	std::ofstream fout;
	fout.open(path, std::ios_base::out | std::ios_base::ate | std::ios_base::binary);
	union
	{
		char tC[2];
		unsigned short tUS;
	} tmpUnion;
	while(1)
	{
		b_recv = recv(cl->GetSCL(), buf, MAX_DATA, 0);
		if( (b_recv == 0) || (b_recv == USHRT_MAX) ) //connection canceled
		{
			fout.close();
			std::cout << "Connection canceled." << std::endl;
			while( !DeleteFile(path) )
			{
				/*NULL*/
			}
			return false;
		}
		US i;
		for(i = 0; (i < b_recv) && (i < fsu.dfs); i += 2)
		{
			memcpy(tmpUnion.tC, buf + i, 2);
			fout << Decrypt( tmpUnion.tUS , k->GetD(), k->GetN() ); 
		}
		if(i >= fsu.dfs)
		{
			fout.close();
			std::cout << "end of file" << std::endl;
			return true;
		}
		else
		{
			Ready(cl);
		}
		fsu.dfs -= b_recv;
	}
}

void InfCh::Ready(Client * cl)
{
	buf[0] = 1;
	send(cl->GetSCL(), buf, 1, 0);	
}

void InfCh::SendKey(Client * cl, Keys * k) const
{
	union 
	{
		char buf[4];
		unsigned int t;
	} keytmp;
	keytmp.t = k->GetE();
	keytmp.t <<= 16;
	keytmp.t |= k->GetN();
	memcpy(buf, keytmp.buf, 4);
	send(cl->GetSCL(), buf, 4, 0);
}
	
InfCh::~InfCh()
{
	delete []buf;
	delete []path;
}