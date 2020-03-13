#include "stdafx.h"
#include "Truck.h"

Truck::Truck()
{
	phuongThucThue = 0;
	thoiGianThue = donGiaNgay = 0;
}

long long Truck::getThoiGianThue()
{
	return thoiGianThue;
}

long long Truck::getDonGiaNgay()
{
	return donGiaNgay;
}

int Truck::getPhuongThucThue()
{
	return phuongThucThue;
}

void Truck::setPhuongThucThue(int chon)
{
	phuongThucThue = chon;
}

void Truck::setThoiGianThue(long long tGT)
{
	thoiGianThue = tGT;
}

void Truck::setDonGiaNgay(long long dG)
{
	donGiaNgay = dG;
}

void Truck::revenue()
{
	if (phuongThucThue == 1)
		TransportGoods::revenue();
	else
		Vehicle::setInterest(thoiGianThue*donGiaNgay);
}

void Truck::inputVehicle()
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
			TransportGoods::inputVehicle();
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
			int trongTai;
			cout << "Nhap trong tai cua xe: ";
			cin >> trongTai;
			setWeight(trongTai);
			setShippingGoodsUnitPrice(0);
			setDistance(0);
			break;
		}
		else
			cout << "Nhap sai, vui long nhap lai theo huong dan\n";
	} while (true);
	fstream xe, phuongTien;
	//Save old data
	xe.open("XeTai.data", ios::in);
	string str = "", tmp = "";
	do {
		xe >> str;
		tmp += str + " ";
		str="";
	} while (!xe.eof());
	xe.close();
	xe.open("XeTai.data", ios::out);
	xe << tmp << " " << getVehicleID()  << " " << getPhuongThucThue() << " " << getWeight() << " " << getDistance() << " " << getShippingGoodsUnitPrice() << " " << getThoiGianThue() << " " << getDonGiaNgay() << " ";;
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
	phuongTien << tmp << " " << getVehicleID() << " " << getVehicleName() << " " << getDriverID() << " " << getInterest() << " ";
	phuongTien.close();
}