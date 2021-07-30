#pragma once
#include<iostream>
using namespace std;
class Date
{
public:
	int ngay, thang, nam;
public:
	Date(int = 2, int = 1, int = 1);
	~Date();
	friend ostream& operator<<(ostream&, const Date&);
};

