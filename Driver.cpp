#include "stdafx.h"
#include "Driver.h"
#include <iomanip>
#include "Tools.h"

Driver::Driver()
{
	ID = name = "";
	salary = 0;
}

string Driver::getID() 
{
	return ID;
}
string Driver::getName() 
{
	return name;
}
long long Driver::getSalary()
{
	return salary;
}
void Driver::setID(string idMoi) 
{
	ID = idMoi;
}
void Driver::setName(string tenMoi) 
{
	name = tenMoi;
}
void Driver::setSalary(long long tn)
{
	salary = tn;
}
void Driver::inputDriver() 
{	
	Tools a;
	cin.ignore();
	fstream t;
	string str = "", tmp = "";
	int fail = 0;
	//Enter ID of a driver
	do {
		fail = 0;
		cout << "Nhap ID Tai Xe: ";
		getline(cin, ID);
		for (int i = 0; i < ID.length(); i++)
			ID[i] = toupper(ID[i]);
		//Check the accuracy of the ID
		if (ID[0] != 'D'&&ID[1] != 'R'&&ID[2] != 'I')
		{
			cout << "Vui long nhap dung ma tai xe. " << endl;
			fail = 1;
		}
		else {
			t.open("TaiXe.data", ios::in);
			do {
				t >> str;
				if (str == ID) {
					cout << "ID da ton tai tren he thong. Vui long nhap lai ID khac." << endl;
					fail = 1;
					break;
				}
			} while (!t.eof());
			t.close();
		}
	} while (fail==1);
	cout << "Nhap ten Tai xe: ";
	getline(cin, name);
	//If user enter "space", change this character to '_'
	a.convertToSave(name);
	wage();
	str = "";
	//Save the old data.
	t.open("TaiXe.data", ios::in);
	do {
		t >> str;
		tmp += str + " ";
		str = "";
	} while (!t.eof());
	t.close();
	//Save data
	t.open("TaiXe.data", ios::out);
	t << tmp << " " << ID << " " << name << " ";
	t.close();
}
void Driver::outputDriver()
{
	Tools a;
	wage();
	cout << "\tID tai xe: " << ID <<"\n\tTen tai xe: " << a.convertToShow(name) << "\n\tThu nhap: " << salary << endl;
}

void Driver::wage() 
{
	salary = 0;
	fstream XE;
	XE.open("PhuongTien.data", ios::in);
	string idXe, idDriver, tenXe;
	long long lai=0;
	//Tìm tất cả các ID của tài xế, cộng dồn tiền lãi.
	do {
		XE >> idXe >> tenXe >> idDriver >> lai;
		if(ID==idDriver)
			salary = salary + lai;
		//Kí tự cuối cùng là dẫu "space", idDriver = "" để tránh lặp.
		idDriver = "";
	} while (!XE.eof());
	salary = salary / 3;
	XE.close();
}

istream &operator >> (istream &in, Driver &t)
{
	t.inputDriver();
	return in;
}

ostream &operator << (ostream &out, Driver &t)
{
	t.outputDriver();
	return out;
}