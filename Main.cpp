#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "Money.h"

using namespace std;

const char* F = "Main File.txt";

int CoutFile() 
{
    fstream stream(F, ios::out | ios::trunc);
	if (!stream) return -1;
	int n;
	cout << "How many items to add to the stream" << endl;
	cin >> n;
	Money m;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the data" << endl;
		cin >> m;
		stream << m;
	}
	stream.close();
}
void Chek(string str, Money& m)
{
	string a;
	int k = 0;
	while (str[k] != ',')
	{
		a += str[k];
		k++;
	}
	k ++;
	int i = stoi(a);
	m.SetR(i);
	a = "";
	for (int n = k; n < str.size(); n++)
	{
		a += str[n];
	}
	i = stoi(a);
	m.SetK(i);
	a = "";
}
int CinFile()
{
	string str;
	fstream stream(F, ios::in);
	if (!stream) return -1;
	Money m;
	while (stream >> str)
	{
		Chek(str ,m);
		cout << m << '\n';
	}
	stream.close();
}


int DelFile(int r, int k) 
{
	string str;
	fstream temp("temp.txt", ios::out);
	fstream stream(F , ios::in);
	if (!stream) return -1;
	int i = 0;
	Money m;
	while (getline(stream, str))
	{
		Chek(str, m);
		if (m.GetR() == r + k / 100)
			if (m.GetK() < k % 100)
				temp << m;
			else
				cout << "Del" << endl;
		else
			if (m.GetR() < r + k / 100)
				temp << m;
			else
				cout << "Del" << endl;
	}
	stream.close();
	temp.close();
	remove(F );
	rename("temp.txt", F );
	return 1;
}

int AddF(int k, Money m1)
{
	int i = 0;
	fstream temp("temp.txt", ios::out);
	fstream stream(F, ios::in);
	if (!stream) return -1;
	Money m;
	string str;
	while (getline(stream, str))
	{
		if (stream.eof())break;
		i++;
		if (k == i)
		{
			temp << m1;
		}
		temp << str << endl;
	}
	stream.close();
	temp.close();
	remove(F );
	rename("temp.txt", F );
	return 1;
}

int ChangeF()
{
	string str;
	fstream temp("temp.txt", ios::out);
	fstream stream(F, ios::in);
	if (!stream) return -1;
	Money m;
	while (getline(stream, str))
	{
		Chek(str, m);
		if (m.GetK() + 50 > 100)
		{
			m.SetK((m.GetK() + 50) % 100);
			m.PlusR(2);
		}
		else
		{
			m.PlusK(50);
			m.PlusR(1);
		}
		temp << m;
	}
	stream.close();
	temp.close();
	remove(F );
	rename("temp.txt", F );
	return 1;
}

int main()
{
	CoutFile();
	CinFile();
	DelFile( 100, 30);
	CinFile();
	Money z(100, 20);
	AddF(1, z);
	CinFile();
	ChangeF();
	CinFile();

}