#include "vattu.h"
#include "MyString.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

bool isNumber(string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void printLine(int n)
{
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << "-";
	}
	cout << endl;
}

void vattu::inputNumber(int &number, string title, int max_length, int max, int min) 
{
    string int_number;
    input:
    cout << title;
    getline(cin, int_number);
    if (int_number.length() > max_length) {
        cout << "Error: max size is " << max_length << endl;
        goto input;
    }
    if (!isNumber(int_number)) {
        cout << "Error: is not number\n";
        goto input;
    }
    number = convertStringToInt(int_number);
    if (number < min) {
        cout << "Error: is lesser than " << min << endl;
        goto input;
    }
    if (number > max) {
        cout << "Error: is greater than " << max << endl;
        goto input;
    }
}

void inputString(string &text, string title, int maxlength) 
{
    input:
    cout << title << "(<=" << maxlength << " char):" ;
    getline(cin, text);
    if(text.length()>maxlength){
        cout << "Error: max size is " << maxlength << "char\n";
        goto input;
    }
}

void vattu::input()
{
    cin.ignore();
    inputString(mvt, "-MS vat tu", 10);
    inputString(ten, "-Ten vat tu", 20);
    inputString(loai, "-Loai vat tu", 15);
    inputString(DV, "-Don vi tinh", 12);
    inputString(nsx, "-Nha san xuat", 15);
    cout << "-Nhap ngay nhan vat tu (ngay/thang/nam): " << endl;
    inputNumber(thang, "thang: ", 2, 12, 1);
    err_feb:
    inputNumber(ngay, "ngay: ", 2, 31, 1);
    if (thang==2 && ngay>29) {
        cout << "Error: Day in February not greater than 29\n";
        goto err_feb;
    }
    inputNumber(nam, "nam: ", 4, 3000, 1999);
    inputNumber(sl, "So luong: ", 5, 99999, 1);
    inputNumber(DG, "Don gia: ", 10, 99999999, 1000);
}

void vattu::output()
{
    cout<< setw(10) << left << mvt
        << setw(20) << left << ten
        << setw(15) << left << loai
        << setw(12) << left << DV;
    stringstream ngaynhap;
    if (ngay < 10 && thang < 10) 
		{
			ngaynhap<< "0" << ngay << "/" 
					<< "0" << thang << "/" 
					<< nam ;
		} else if (ngay < 10) {
			ngaynhap<< "0" << ngay << "/" 
					<< thang << "/" 
					<< nam ;
		} else if (thang < 10) {
			ngaynhap<< ngay << "/" 
					<< "0" << thang << "/" 
					<< nam ;
		} else {
			ngaynhap<< ngay << "/" 
					<< thang << "/" 
					<< nam ;
		}
    cout<< setw(15) << left << ngaynhap.str()
        << setw(15) << left << nsx
        << setw(7) << left << sl
        << setw(10) << left << DG
        << endl;
}

void vattu::update() {
    int choose;
    while(choose) {
        system("cls");
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
        output();
        cout << "\n|--- UPDATE -----------------------------------|";
		cout << "\n|          Chon muc can cap nhat               |";
		cout << "\n|          0. Thoat                            |";
		cout << "\n|          1. Ma so vat tu                     |";
		cout << "\n|          2. Ten vat tu                       |";
		cout << "\n|          3. Loai vat tu                      |";
		cout << "\n|          4. Don vi tinh                      |";
		cout << "\n|          5. Nha san xuat                     |";
		cout << "\n|          6. Ngay                             |";
		cout << "\n|          7. Thang                            |";
		cout << "\n|          8. Nam                              |";
		cout << "\n|          9. So luong                         |";
		cout << "\n|         10. Don gia                          |";
		cout << "\n|----------------------------------------------|";
        cout << "\n\n";
        cout << "Chon muc: ";
        cin  >> choose;
        cin.ignore();

        switch(choose)
        {
            case 0: break;
            case 1: 
            {
                inputString(mvt, "-MS vat tu moi", 10);
                break;
            }
            case 2:
            {
                inputString(ten, "-Ten vat tu moi", 20);
                break;
            }
            case 3: 
            {
                inputString(loai, "-Loai vat tu moi", 15);
                break;
            }
            case 4:
            {
                inputString(DV, "-Don vi tinh moi", 12);
                break;
            }
            case 5: 
            {
                inputString(nsx, "-Nha san xuat moi", 15);
                break;
            }
            case 6: 
            {
                err_feb:
                inputNumber(ngay, "ngay moi: ", 2, 31, 1);
                if (thang==2 && ngay>29) {
                    cout << "Error: Day in February not greater than 29\n";
                    goto err_feb;
                }
                break;
            }
            case 7:
            {
                inputNumber(thang, "thang moi: ", 2, 12, 1);
                break;
            }
            case 8: 
            {
                inputNumber(nam, "nam moi: ", 4, 3000, 1999);
                break;
            }
            case 9: 
            {
                inputNumber(sl, "So luong moi: ", 5, 99999, 1);
                break;
            }
            case 10:
            {
                inputNumber(DG, "Don gia moi: ", 10, 99999999, 1000);
                break;
            }
        }
    }
}

vattu::~vattu()
{
}

istream& operator>>(istream& i, vattu& v)
{
    cout << "NHAP MA SO VAT TU:";
    i >> v.mvt;
    cout << "TEN VAT TU: ";
    i >> v.ten;
    cout << "LOAI:  ";
    i >> v.loai;
    cout << "DON VI TINH: ";
    i >> v.DV;
    cout << "NGAY NHAP:" << endl;
    cout << "NGAY:";
    i >> v.ngay;
    cout << "THANG:";
    i >> v.thang;
    cout << "NAM:";
    i >> v.nam;
    cout << "NHA SAN XUAT: ";
    i >> v.nsx;
    cout << "SO LUONG:  ";
    i >> v.sl;
    cout << "DON GIA: ";
    i >> v.DG;
    
  
    return i;
    // TODO: insert return statement here
}

ostream& operator<<(ostream& o, const vattu& p)
{
    o << "-MA SO VAT TU:" << p.mvt << endl;
    o << "-TEN VAT TU:" << p.ten << endl;
    o << "-LOAI:" << p.loai << endl;
    o << "-DON VI TINH:" << p.DV << endl;
    o << "-NGAY SAN XUAT:" << p.ngay << "/" << p.thang << "/" << p.nam << endl;
    o << "-NHA SAN XUAT:" << p.nsx << endl;
    o << "-SO LUONG:" << p.sl << endl;
    o << "-DON GIA:" << p.DV << endl;
   
    // TODO: insert return statement here
    return o;
}
