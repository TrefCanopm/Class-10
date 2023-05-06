#pragma once

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Money
{
private:
	int rubles;
	int kopecks;
public:
	Money();
	Money(string str);
	Money(int r, int k);
	Money(const Money&);

	int GetR();
	int GetK();

	void SetR(int r);
	void SetK(int k);

	void PlusR(int r);
	void PlusK(int k);

	bool operator == (const Money&);
	bool operator != (const Money&);

	Money& operator --();
	Money& operator --(int);

	friend std::ostream& operator << (std::ostream& out, const Money&);
	friend std::istream& operator >> (std::istream& in, Money&);

	~Money() {};
};