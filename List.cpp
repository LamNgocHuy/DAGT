#include "List.h"
#include "fileio.h"
#include "MyString.h"
#include "sort.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void List::printGoods()
{
	cout << setw(60) << right << "\n|--------------------|";
	cout << setw(60) << right << "\n|  Danh sach vat tu  |";
	cout << setw(60) << right << "\n|--------------------|\n";

	printLine(115);
	cout << setw(5) << left <<"STT" 
		<< setw(10) << left <<"MA SO" 
		<< setw(20) << left <<"TEN"
		<< setw(15) << left <<"LOAI" 
		<< setw(12) << left <<"DON VI" 
		<< setw(15) << left <<"NGAY NHAP" 
		<< setw(15) << left <<"NSX" 
		<< setw(7)  << left <<"SL" 
		<< setw(10) << left <<"DON GIA(vnd)";
	printLine(115);

	for (int i = 0; i < this->size; i++) {
		cout << setw(5) << left << i + 1
		    << setw(10) << left << a[i].mvt
		    << setw(20) << left << a[i].ten
		    << setw(15) << left << a[i].loai
		    << setw(12) << left << a[i].DV;
		stringstream ngaynhap;
		if (a[i].ngay < 10 && a[i].thang < 10) 
		{
			ngaynhap<< "0" << a[i].ngay << "/" 
					<< "0" << a[i].thang << "/" 
					<< a[i].nam ;
		} else if (a[i].ngay < 10) {
			ngaynhap<< "0" << a[i].ngay << "/" 
					<< a[i].thang << "/" 
					<< a[i].nam ;
		} else if (a[i].thang < 10) {
			ngaynhap<< a[i].ngay << "/" 
					<< "0" << a[i].thang << "/" 
					<< a[i].nam ;
		} else {
			ngaynhap<< a[i].ngay << "/" 
					<< a[i].thang << "/" 
					<< a[i].nam ;
		}
		cout << setw(15) << left << ngaynhap.str()
		    << setw(15) << left << a[i].nsx
		    << setw(7) << left << a[i].sl
		    << setw(10) << left << a[i].DG
		    << endl;
	}
	printLine(115);
	cout << endl;
}

void List::updateAGoods()
{
	printGoods();
	int c;
	cout << "-Nhap vi tri can cap nhat:";
	cin >> c;
	system("cls");
	a[c - 1].update();
	cout << "\n|--------------------------------------|";
	cout << "\n|                                      |";
	cout << "\n|        Cap nhat thanh cong <3        |";
	cout << "\n|                                      |";
	cout << "\n|--------------------------------------|";
	writeGoodsToFile(a, this->size);
	printGoods();
}

bool List::searchAGoods()
{
	int ch;
	bool isExist = false;
	while (1)
	{   
		cout << "\n|--- MENU ---------------------------------------------|";
		cout << "\n|          Chon cong viec can thuc hien :              |";
		cout << "\n|          1. Tim kiem theo ten vat tu .               |";
		cout << "\n|          2. Tim kiem theo ma vat tu .                |";
		cout << "\n|          3. Tim kiem theo loai vat tu .              |";
		cout << "\n|------------------------------------------------------|";
		cout << "\n chon : ";
		cin >> ch;
		string ast;
		if (ch < 1 || ch > 3)
			cout << "\nchon chua hop le, chon lai.";
		switch (ch)
		{
		case 1:
		{
			string input_name;
			cout << setw(20) << right << "-Nhap ten vat tu can tim: ";
			cin.ignore();
			//cin >> tn;
			getline(cin, input_name);
			input_name = To_upper(input_name);
			string goods_name;
			printLine(115);
			cout<< setw(10) << left <<"MA SO" 
				<< setw(20) << left <<"TEN"
				<< setw(15) << left <<"LOAI" 
				<< setw(12) << left <<"DON VI" 
				<< setw(15) << left <<"NGAY NHAP" 
				<< setw(15) << left <<"NSX" 
				<< setw(7)  << left <<"SL" 
				<< setw(10) << left <<"DON GIA(vnd)";
			printLine(115);
			for (int i = 0; i < this->size; i++)
			{
				goods_name = To_upper(a[i].ten);
				goods_name = removeSpaceSE(goods_name);
				if (input_name.compare(goods_name) == 0)
				{
					a[i].output();
					isExist = true;
				}
			}
			break;
		}
		case 2:
		{
			string code_input;
			cout << setw(20) << right << "-Nhap ma vat tu can tim: ";
			cin >> code_input;
			code_input = To_upper(code_input);
			string goods_code;
			printLine(115);
			cout<< setw(10) << left <<"MA SO" 
				<< setw(20) << left <<"TEN"
				<< setw(15) << left <<"LOAI" 
				<< setw(12) << left <<"DON VI" 
				<< setw(15) << left <<"NGAY NHAP" 
				<< setw(15) << left <<"NSX" 
				<< setw(7)  << left <<"SL" 
				<< setw(10) << left <<"DON GIA(vnd)";
			printLine(115);
			for (int i = 0; i < this->size; i++)
			{
				goods_code = To_upper(a[i].mvt);
				goods_code = removeSpaceSE(goods_code);
				if (code_input.compare(goods_code)==0)
				{
					a[i].output();
					isExist = true;
				}
			}
			break;
		}
		case 3:
		{
			string type_input;
			cout << setw(20) << right << "-Nhap loai vat tu can tim: ";
			cin.ignore();
			getline(cin, type_input);
			type_input = To_upper(type_input);
			string goods_type;
			printLine(115);
			cout<< setw(10) << left <<"MA SO" 
				<< setw(20) << left <<"TEN"
				<< setw(15) << left <<"LOAI" 
				<< setw(12) << left <<"DON VI" 
				<< setw(15) << left <<"NGAY NHAP" 
				<< setw(15) << left <<"NSX" 
				<< setw(7)  << left <<"SL" 
				<< setw(10) << left <<"DON GIA(vnd)";
			printLine(115);
			int d = 0;
			for (int i = 0; i < this->size; i++)
			{
				goods_type = To_upper(a[i].loai);
				goods_type = removeSpaceSE(goods_type);
				d = i;
				if (type_input.compare(goods_type) == 0)
				{
					a[i].output();
					isExist = true;
				}
			}
			break;
		}
		}
		return isExist;
	}
}

void List::addAGoods() 
{
	vattu h;
	cout << setw(20) << right << "Them mot vat tu:\n";
	h.input();
	vattu *b = new vattu[this->size + 1];
	for (int i = 0; i < this->size; i++)
	{
		b[i] = a[i];
	}
	b[this->size] = h;
	this->size++;
	writeGoodsToFile(b, this->size);
	cout << "\n|--- vvv ------------------|";
	cout << "\n|                          |";
	cout << "\n|      Them thanh cong     |";
	cout << "\n|                          |";
	cout << "\n|--------------------------|\n";
}

void List::insAGoods() 
{
	vattu *b = new vattu[this->size + 1];
	vattu h;
	printGoods();
	int index;
	ins_index:
	cin.ignore();
	cout << "-Nhap vi tri can chen: ";
	cin >> index;
	index--;
	if (index > this->size || index < 0) 
	{
		cout << "Vi tri can chen khong ton tai. Moi nhap lai >>\n";
		goto ins_index;	
	}
	cout << setw(20) << right << "Nhap vat tu can chen:\n";
	h.input();
	int j = 0;
	for (int i = 0; i < this->size; i++)
	{
		if (index!=i) {
			b[j] = a[i];
		} else {
			b[j] = h;
			i--;
		}
		j++;
	}
	this->size++;
	writeGoodsToFile(b, this->size);
}

void List::delAGoods()
{
	vattu *b = new vattu[this->size - 1];
	printGoods();
	int index;
	del_index:
	cin.ignore();
	cout << "-Nhap vi tri can xoa: ";
	cin >> index;
	index--;
	if (index > this->size || cin.fail() || index < 0) 
	{
		cout << "Vi tri can xoa khong ton tai. Moi nhap lai >>\n";
		goto del_index;	
	}
	int j = 0;
	for (int i = 0; i < this->size; i++)
	{
		if (index!=i) {
			b[j] = a[i];
			j++;
		}
	}
	this->size--;
	writeGoodsToFile(b, this->size);
	cout << "\n|--- vvv ------------------|";
	cout << "\n|                          |";
	cout << "\n|      Xoa thanh cong      |";
	cout << "\n|                          |";
	cout << "\n|--------------------------|\n";
}

void List::deleteMultiple()
{
	vattu *b = new vattu[this->size];
	int count = 0;
	int j = 0;
	for (int i = 0; i < this->size; i++)
	{
		if (a[i].sl <= 100) {
			b[j] = a[i];
			j++;
		} else {
			count++;
		}
	}
	this->size -= count;
	writeGoodsToFile(b, this->size);
	cout << "\n|--- vvv ------------------|";
	cout << "\n|                          |";
	cout << "\n|      Xoa thanh cong      |";
	cout << "\n|                          |";
	cout << "\n|--------------------------|\n";
}

void List::printStatisticalTables()
{
	string l;
	long total = 0;
	int stt = 0;
	cout << "**************************************************************************************************" << endl;
	cout << setw(25) << right << "BANG THONG KE" << endl;
	cout << " " << endl;
	cout << setw(5) << left << "STT";
	cout << setw(20) << left << "LOAI";
	cout << setw(20) << left << "SO LUONG";
	cout << setw(20) << left << "TONG TIEN";
	cout << endl;

	for (int i = 0; i < this->size; i++)
	{
		bool KT = true;
		for (int j = i - 1; j >= 0; j--) {

			if (a[i].loai == a[j].loai) {
				KT = false;
				break;

			}
		}
		if (KT == true)
		{
			stt++;
			int dem = 0;
			for (int k = 0; k < this->size; k++)
			{
				if (a[i].loai == a[k].loai)
				{
					dem++;
					//phan tinh tien
					if (a[k].sl > 200)
					{

						total = total + a[k].DG * a[k].sl * 0.75;
					}
					else if (a[k].sl > 100 && a[k].sl <= 200)
					{

						total = total + a[k].DG * a[k].sl * 0.9;
					}
					else if (a[k].sl <= 100)
					{

						total = total + a[k].DG * a[k].sl;
					}

				}
			}
			cout << setw(5) << left << stt;
			cout << setw(20) << left << a[i].loai;
			cout << setw(20) << left << dem;
			cout << setw(20) << left << total;
			total = 0;
			cout << endl;
		}

	}
}

void List::sortGoods()
{
	bool t = true;
	while (t)
	{
		int choose;
		cout << "\n|--- MENU ---------------------------------------------|";
		cout << "\n|          Chon loai sap xep can thuc hien :           |";
		cout << "\n|          1. Sap xep theo ngay nhap .                 |";
		cout << "\n|          2. Sap xep theo ten vat tu .                |";
		cout << "\n|          3. Sap xep theo so luong .                  |";
		cout << "\n|          4. Sap xep theo don gia .                   |";
		cout << "\n|          0. Ve menu chinh .                          |";
		cout << "\n|------------------------------------------------------|";
		cout << "\nchon loai sap xep : ";
		cin >> choose;
		system("cls");
		if (choose < 0 || choose > 4)
			cout << "\nchon chua hop le, chon lai .";
		switch (choose)
		{
		case 0:
			t = false;
			break;
		case 1:
		{
			int choose;
			cout << "\n|--- MENU -------------------------------------|";
			cout << "\n|          Sap xep theo so luong :             |";
			cout << "\n|          1. Tang .                           |";
			cout << "\n|          2. Giam .                           |";
			cout << "\n|----------------------------------------------|";
			cout << "\nchon phuong thuc : ";
			cin >> choose;
			system("cls");
			switch (choose)
			{
			case 1:
			{
				sapxeptheongaynhap(this->a, 1, this->size);
				printGoods();
				system("pause");
				system("cls");
				break;
			}
			case 2:
			{
				sapxeptheongaynhap(this->a, 2, this->size);
				printGoods();
				system("pause");
				system("cls");
				break;
			}
			default:
			{
				cout << "chon lai .";
				system("pause");
				break;
			}
			}
			break;
		}
		case 2:
		{

			break;
		}
		case 3:
		{
			int choose;
			cout << "\n|--- MENU ---------------------------------|";
			cout << "\n|          Sap xep theo so luong :         |";
			cout << "\n|          1. Tang .                       |";
			cout << "\n|          2. Giam .                       |";
			cout << "\n|------------------------------------------|";
			cout << "\n chon phuong thuc : ";
			cin  >> choose;
			system("cls");
			switch (choose)
			{
			case 1:
			{
				sapxeptheosl(this->a, 1, this->size);
				printGoods();
				system("pause");
				system("cls");
				break;
			}
			case 2:
			{
				sapxeptheosl(this->a, 2, this->size);
				printGoods();
				system("pause");
				system("cls");
				break;
			}
			default:
			{
				cout << "chon lai .";
				system("pause");
				break;
			}
			}
			break;
		}
		case 4:
		{
			int choose;
			cout << "\n|--- MENU ------------------------------|";
			cout << "\n|          Sap xep theo don gia :       |";
			cout << "\n|          1. Tang .                    |";
			cout << "\n|          2. Giam .                    |";
			cout << "\n|---------------------------------------|";
			cout << "\n chon phuong thuc : ";
			cin >> choose;
			system("cls");
			switch (choose)
			{
			case 1:
			{
				sapxeptheodongia(this->a, 1, this->size);
				printGoods();
				system("pause");
				system("cls");
				break;
			}
			case 2:
			{
				sapxeptheodongia(this->a, 2, this->size);
				printGoods();
				system("pause");
				system("cls");
				break;
			}
			default:
			{
				cout << " Chon lai .";
				system("pause");
				break;
			}
			}
			break;
		}
		default:
		{
			cout << "Khong hop le, chon lai\n";
			system("pause");
			break;
		}
		}
	}
}

void List::printLine(int n)
{
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << "-";
	}
	cout << endl;
}

void List::menu()
{
	int chon;
	do
	{
		this->size = numberOfLines();
		this->a = new vattu[this->size];
		readGoodsFromFile(a, this->size);
		system("cls");
		cout << "\n|--- MENU ---------------------------------------------|";
		cout << "\n|          Chuong trinh quan li vat tu                 |";
		cout << "\n|          1. Xuat thong tin vat tu.                   |";
		cout << "\n|          2. Bo sung 1 vat tu.                        |";
		cout << "\n|          3. Tim kiem vat tu.                         |";
		cout << "\n|          4. Cap nhat thong tin vat tu.               |";
		cout << "\n|          5. Sap xep vat tu.                          |";
		cout << "\n|          6. Chen 1 vat tu.                           |";
		cout << "\n|          7. Xoa 1 vat tu.                            |";
		cout << "\n|          8. In bang thong ke theo loai.              |";
		cout << "\n|          9. Xoa vat tu (soluong > 100).              |";
		cout << "\n|          0. Thoat ra.                                |";
		cout << "\n|------------------------------------------------------|";
		cout << "\n\n";

		cout << "Chon cong viec can thuc hien: ";
		cin >> chon;
		switch (chon)
		{
		case 0:
		{
			system("cls");
			cout << "\n|--------------------------------------|";
			cout << "\n|                                      |";
			cout << "\n|     Cam on da su dung dich vu <3     |";
			cout << "\n|                                      |";
			cout << "\n|--------------------------------------|";
			break;
		}
		case 1:
		{
			system("cls");
			printGoods();
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			addAGoods();
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			if (!searchAGoods())
			{
				cout << "\n|--- !!! ----------------------------|";
				cout << "\n|                                    |";
				cout << "\n|      Vat tu nay khong ton tai      |";
				cout << "\n|                                    |";
				cout << "\n|------------------------------------|\n";
			}
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			updateAGoods();
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			sortGoods();
			break;
		}
		case 6:
		{
			system("cls");
			insAGoods();
			break;
		}
		case 7:
		{
			delAGoods();
			system("pause");
			break;
		}
		case 8:
		{
			system("cls");
			printStatisticalTables();
			system("pause");
			break;
		}
		case 9:
		{
			system("cls");
			deleteMultiple();
			system("pause");
			break;
		}
		}
	} while (chon != 0);
}

List::~List()
{
	delete[] this->a;
}
