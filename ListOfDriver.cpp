#include "stdafx.h"
#include "ListOfDriver.h"

void ListOfDriver::readListDriver()
{
	n = 0;
	fstream TX;
	TX.open("TaiXe.data",ios::in);
	string ID, ten;
	do {
		TX >> ID >> ten;
		tx[n].setID(ID);
		tx[n].setName(ten);
		tx[n].wage();
		n++;
	} while (!TX.eof());
	TX.close();
	n--;
	//Sort the salary to ascending
	sortSalary();
}

void ListOfDriver::inputListDriver()
{
	n++;
	cin >> tx[n];
	fstream tk;
	//Save data to tmp
	string tmp = "", s;
	tk.open("TaiKhoan.data", ios::in);
	do {
		tk >> s;
		tmp = tmp + s + " ";
		s = "";
	} while (!tk.eof());
	tk.close();
	//Create account for this driver.
	string newPass="";
	do {
		cout << "Nhap mat khau cua tai xe: ";
		s = passwd(10);
		cout << "Nhap lai mat khau: ";
		newPass = passwd(10);
		//Đưa dữ liệu vào file.
		if (s == newPass) {
			tk.open("TaiKhoan.data", ios::out);
			tk << tmp << " " << tx[n].getID() << " " << s << " ";
			tk.close();
		}
		else
			cout << "Mat khau khong khop, vui long nhap lai." << endl;
	} while (s != newPass);
	cout << endl;
}

void ListOfDriver::outputListDriver()
{
	readListDriver();
	for (int i = 0; i < n; i++) 
	{
		cout << "Tai xe thu " << i + 1 << ":\n";
		cout << tx[i];
	}
}

//Sort the salary to ascending
void ListOfDriver::sortSalary()
{
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if (tx[i].getSalary() > tx[j].getSalary())
			{
				Driver tmp = tx[i];
				tx[i] = tx[j];
				tx[j] = tmp;
			}
}

void ListOfDriver::maxOfSalary()
{
	cout << "Tai xe co luong cao nhat la:" << endl;
	readListDriver();
	Driver l = tx[0];
	for (int i = 0; i < n; i++)
		if (l.getSalary() < tx[i].getSalary())
			l = tx[i];
	l.outputDriver();
}

//Show the infomation of driver
void ListOfDriver::findVehicle(string ID)
{
	if (ID[0] == 'C')
	{
		fstream XC;
		XC.open("XeCon.data", ios::in);
		string idXe;
		long long soChoNgoi, quangDuong, donGiaThue, thoiGianThue, donGiaNgay;
		int phuongThucThue;
		do {
			XC >> idXe >> phuongThucThue >> soChoNgoi >> quangDuong >> donGiaThue >> thoiGianThue >> donGiaNgay;
			if (ID == idXe) {
				cout << "\t\tSo cho ngoi: " << soChoNgoi << "\n\t\tDa di duoc: " << quangDuong << " (km)\n\t\tVoi don gia: " << donGiaThue << " (dong)\n";
				break;
			}
		} while (!XC.eof());
		XC.close();
	}
	else if (ID[0] == 'B')
	{
		fstream XB;
		XB.open("XeBuyt.data", ios::in);
		string idXe;
		long long soChoNgoi, quangDuong, donGiaNguoi, soGoiHang, soNguoiDi, donGiaHang;
		do {
			XB >> idXe >> quangDuong >> soChoNgoi >> soNguoiDi >> donGiaNguoi >> soGoiHang >> donGiaHang;
			if (ID == idXe) {
				cout << "\t\tDa di duoc: " << quangDuong << " (km) \n\t\tSo nguoi di: " << soNguoiDi << " (nguoi)\n\t\tDon gia 1 nguoi: " << donGiaNguoi << " (dong)\n\t\tSo goi hang da van chuyen: " << soGoiHang << " (goi)\n\t\tDon gia 1 goi hang: " << donGiaHang << " (dong)\n";
				break;
			}
		} while (!XB.eof());
		XB.close();
	}
	else if (ID[0] == 'T')
	{
		fstream XT;
		XT.open("XeTai.data", ios::in);
		string idXe;
		long long canNang, quangDuong, donGiaThue, thoiGian, donGiaNgay;
		int phuongThucThue;
		do {
			XT >> idXe >> phuongThucThue >> canNang >> quangDuong >> donGiaThue >> thoiGian >> donGiaNgay;
			if (ID == idXe)
				cout << "\t\tDa van chuyen: " << canNang << " (kg)\n\t\tDa di duoc: " << quangDuong << " (km)\n\t\tVoi don gia: " << donGiaThue << " (dong)\n";
				break;
		} while (!XT.eof());
		XT.close();
	}
}

void ListOfDriver::findDriverID(string ID)
{
	Tools a;
/*	fstream f;
	string idXe, ten, idTaiXe, str="";
	long long lai,tmp=0;
	f.open("TaiXe.data", ios::in);
	do {
		f >> idTaiXe >> ten;
		if (idTaiXe == ID){
			str += ten;
			break;
		}
	} while (!f.eof());
	f.close();
	cout << "\tTen tai xe: " << a.convertToShow(str) << "\n\tLai Xe: ";
	str = "";
	f.open("PhuongTien.data", ios::in);
	do {
		f >> idXe >> ten >> idTaiXe >> lai;
		if (idTaiXe == ID && ten!="") {
			str += ("\n\t\t"+ten);
			tmp += lai;
		}
		ten = "";
		lai = 0;
	} while (!f.eof());
	f.close();
	cout << str << "\n\tTong thu nhap: " << tmp/3 << endl;s
*/
	fstream f;
	string idXe, tenXe, idTaiXe="", tenTX, laiXe="";
	long long lai, tongLai = 0;
	f.open("TaiXe.data", ios::in);
	do {
		f >> idTaiXe >> tenTX;
		if (idTaiXe == ID) {
			cout << "Ten tai xe: " << a.convertToShow(tenTX) << endl;
			break;
		}
	} while (!f.eof());
	f.close();
	cout << "Lai xe: " << endl;
	f.open("PhuongTien.data", ios::in);
	do {
		f >> idXe >> tenXe >> idTaiXe >> lai;
		if (idTaiXe == ID && idXe != "") {
			cout<< "\t" + a.convertToShow(tenXe) +" ("+idXe+")\n";
			findVehicle(idXe);
			tongLai += lai;
		}
		tenXe = "";
		idXe = "";
		lai = 0;
	} while (!f.eof());
	cout << "Tong thu nhap: " << tongLai / 3 << endl;
	f.close();
	cout << endl;
}

//To hide password.
string ListOfDriver::passwd(unsigned maxLength)
{
	string pw;
	for (char c; (c = _getch()); )
	{
		if (c == '\n' || c == '\r') {
			cout << "\n";
			break;
		}
		else if (c == '\b') {
			cout << "\b \b";
			if (!pw.empty()) pw.erase(pw.size() - 1);
		}
		else if (c == -32) {
			_getch();
		}
		else if (isprint(c) && pw.size() < maxLength) {
			cout << '*';
			pw += c;
		}
	}
	return pw;
}