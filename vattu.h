#pragma once
#include<iostream>
#include"Date.h"
using namespace std;
class vattu :public Date
{
public:
	string mvt;
	int sl;
	string ten, loai, DV, nsx;
	int DG;
public:
	void inputNumber(int &number, string title, int max_length, int max, int min);
	void input();
	void output();
	void update();
	friend istream& operator>>(istream&, vattu&);
	friend ostream& operator<<(ostream&, const vattu&);
	~vattu();
};
