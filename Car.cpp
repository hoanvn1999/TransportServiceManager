#include "stdafx.h"
#include "Car.h"


Car::Car()
{
	phuongThucThue = 0;
	thoiGianThue = donGiaNgay = 0;
}

long long Car::getThoiGianThue()
{
	return thoiGianThue;
}

long long Car::getDonGiaNgay()
{
	return thoiGianThue;
}

int Car::getPhuongThucThue()
{
	return phuongThucThue;
}

void Car::setThoiGianThue(long long tGT)
{
	thoiGianThue = tGT;
}

void Car::setDonGiaNgay(long long dG)
{
	donGiaNgay = dG;
}

void Car::setPhuongThucThue(int chon)
{
	phuongThucThue = chon;
}

void Car::revenue() 
{
	if (phuongThucThue == 1)
		TransportPeople::revenue();
	else
		Vehicle::setInterest(thoiGianThue*donGiaNgay);
}

void Car::inputVehicle()
{
	do {
		cout << "Nhap phuong thuc thue:\n\tNhap 1 de thue nhan vien lai xe\n\tNhap 2 de thue xe tu lai\n\n\tMoi ban lua chon phuong thuc thue: ";
		cin >> phuongThucThue;
		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			system("CLS");
			cout << "Nhap sai, vui long nhap lai theo huong dan." << endl;
			continue;
		}
		if (phuongThucThue == 1) {
			TransportPeople::inputVehicle();
			thoiGianThue = 0;
			donGiaNgay = 0;
			break;
		}
		else if (phuongThucThue == 2) 
		{
			Vehicle::inputVehicle();
			cout << "Nhap thoi gian thue (ngay): ";
			cin >> thoiGianThue;
			cout << "Nhap don gia thue trong mot ngay (VND/ngay): ";
			cin >> donGiaNgay;
			int soCho;
			cout << "Nhap so cho ngoi cua xe: ";
			cin >> soCho;
			setSeating(soCho);
			setShippingPeopleUnitPrice(0);
			setDistance(0);
			break;
		}
		else
			cout << "Nhap sai, vui long nhap lai theo huong dan\n";
	} while (true);
	fstream xe,phuongTien;
	xe.open("XeCon.data", ios::in);
	string str="", tmp = "";
	//Save the old data
	do {
		xe >> str;
		tmp += str + " ";
		str = "";
	} while (!xe.eof());
	xe.close();
	xe.open("XeCon.data", ios::out);
	xe << tmp << " " << getVehicleID() << " " << getPhuongThucThue() << " " << getSeating() << " " << getDistance() << " " << getShippingPeopleUnitPrice() << " " << getThoiGianThue() << " " << getDonGiaNgay() << " ";
	xe.close();
	revenue();
	tmp = "";
	//Save the old data
	phuongTien.open("PhuongTien.data", ios::in);
	do {
		phuongTien >> str;
		tmp += str + " ";
		str = "";
	} while (!phuongTien.eof());
	phuongTien.close();
	phuongTien.open("PhuongTien.data", ios::out);
	phuongTien << tmp << " "<< getVehicleID() << " " << getVehicleName() << " " << getDriverID() << " " << getInterest() << " ";
	phuongTien.close();
}