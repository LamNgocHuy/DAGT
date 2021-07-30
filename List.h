#pragma once
#include "vattu.h"
#include<fstream>
class List :public vattu
{
public:
	int size;
	vattu* a;
public:
	void printGoods(); // in danh sach vat tu
	void updateAGoods(); // cap nhat 1 vat tu
	bool searchAGoods(); // tim kiem 1 vat tu
	void menu(); // thuc don chuong trinh
	void insertAGoods(); // chen 1 vat tu
	void addAGoods(); // them 1 vat tu
	void insAGoods(); // chen 1 vat tu
	void delAGoods(); // xoa 1 vat tu
	void printStatisticalTables(); // in bang thong ke
	void sortGoods(); // sap xep vat tu
	void deleteMultiple(); // xoa nhung vat tu co so luong > 100
	void printLine(int n);
	~List();
};

