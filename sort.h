#include "vattu.h"
#include <fstream>
#include <string>
#include <iostream>

void Swap(vattu &a, vattu &b)
{
	vattu tmp = a;
	a = b;
	b = tmp;
}

void sapxeptheosl(vattu* a,int upOrDown, int size)
{
	vattu tmp;
	int n = size;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (upOrDown == 1)
			{
				if (a[i].sl > a[j].sl)
					Swap(a[i], a[j]);
			}
			else
			{
				if (a[i].sl < a[j].sl)
					Swap(a[i], a[j]);
			}
		}
	}
	writeGoodsToFile(a, size);
}

void sapxeptheodongia(vattu* a,int upOrDown, int size)
{
	vattu tmp;
	int n = size;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (upOrDown == 1)
			{
				if (a[i].DG > a[j].DG)
					Swap(a[i], a[j]);
			}
			else
			{
				if (a[i].DG < a[j].DG)
					Swap(a[i], a[j]);
			}
		}
	}
	writeGoodsToFile(a, size);
}

void sapxeptheongaynhap(vattu* a,int upOrDown, int size)
{
	vattu tmp;
	int n = size;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (upOrDown == 1)
			{
				if (a[i].nam > a[j].nam) Swap(a[i], a[j]);
				else if (a[i].nam == a[j].nam) {
					if (a[i].thang > a[j].thang) Swap(a[i], a[j]);
					else if (a[i].thang == a[j].thang) {
						if (a[i].ngay > a[j].ngay) Swap(a[i], a[j]);
					}
				}
			}
			else
			{
				if (a[i].nam < a[j].nam) Swap(a[i], a[j]);
				else if (a[i].nam == a[j].nam) {
					if (a[i].thang < a[j].thang) Swap(a[i], a[j]);
					else if (a[i].thang == a[j].thang) {
						if (a[i].ngay < a[j].ngay) Swap(a[i], a[j]);
					}
				}
			}
		}
	}
	writeGoodsToFile(a, size);
}