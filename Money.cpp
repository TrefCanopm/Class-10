#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include "Money.h"

using namespace std;

Money::Money()
{
	rubles = 0;
	kopecks = 0;
}
Money::Money(int r, int k)
{
	if (k < 100)
	{
		kopecks = k;
		rubles = r;
	}
	else
	{
		rubles = r + k / 100;
		kopecks = k % 100;
	}
}
Money::Money(const Money& m)
{
	rubles = m.rubles;
	kopecks = m.kopecks;
}
Money::Money(string str)
{
	string a;
	int i = 0;
	while (str[i] != ',')
	{
		i++;
		a += str[i];
	}
	i++;
	rubles = stoi(a) ;
	a = "";
	for (i = i; i < str.size(); i++)
	{
		a += str[i];
	}
	kopecks = stoi(a);
}

int Money::GetR()
{
	return rubles;
}
int Money::GetK()
{
	return kopecks;
}

void Money::SetR(int r)
{
	rubles = r;
}
void Money::SetK(int k)
{
	kopecks = k;
}

void Money::PlusR(int r)
{
	rubles += r;
}
void Money::PlusK(int k)
{
	kopecks += k;
}

bool Money::operator!=(const Money& m)
{
	if (this->rubles != m.rubles)
	{
		return 1;
	}
	else
	{
		if (this->kopecks != m.kopecks)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
bool Money::operator==(const Money& m)
{
	if (this->rubles == m.rubles)
	{
		if (this->kopecks == m.kopecks)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

Money& Money::operator -- ()
{
	kopecks = kopecks - 1;
	return *this;
}
Money& Money::operator--(int)
{
	kopecks = kopecks - 1;
	return *this;
}

ostream& operator << (ostream& out, const Money& p)
{
	return(out << p.rubles << "," << p.kopecks<< endl);
}
istream& operator >> (istream& in, Money& p)
{
	in >> p.rubles;
	in >> p.kopecks;
	return in;
}