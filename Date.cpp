#include "Date.h"
#include<iostream>
using namespace std;


Date::Date(int dd, int yy, int mm) :ngay(dd), thang(mm), nam(yy)
{
}

Date::~Date()
{
}

ostream& operator<<(ostream& o, const Date& p)
{
	o << p.ngay << "/" << p.thang << "/" << p.nam;
	return o;
	// TODO: insert return statement here
}
