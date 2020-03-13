#include "stdafx.h"
#include "Bus.h"

Bus::Bus()
{
	soNguoiDi = soGoiHang = 0;
}

long long Bus::getSoNguoiDi()
{
	return soNguoiDi;
}

long long Bus::getSoGoiHang()
{
	return soGoiHang;
}

void Bus::setSoNguoiDi(long long soNguoi)
{
	soNguoiDi = soNguoi;
}

void Bus::setSoGoiHang(long long soHang)
{
	soGoiHang = soHang;
}

void Bus::inputVehicle() {
	//Xe buýt không sử dụng TẤT CẢ thuộc tính của PTChoNguoi và PTChoHang.
	Vehicle::inputVehicle();
	long long qD, soCho, dGN, dGH;
	cout << "Nhap quang duong di: ";
	cin >> qD;
	cout << "Nhap so cho ngoi tren xe: ";
	cin >> soCho;
	TransportPeople::setSeating(soCho);
	do {
		cout << "Nhap so nguoi di: ";
		cin >> soNguoiDi;
		if (soCho >= soNguoiDi)
			break;
		else
			cout << "Vui long nhap lai, so cho ngoi phai lon hon hoac bang so nguoi di tren xe." << endl;
	} while (true);
	cout << "Nhap don gia cho nguoi tren 1 km (VND): ";
	cin >> dGN;
	cout << "Nhap so goi hang tren xe: ";
	cin >> soGoiHang;
	cout << "Nhap don gia cho hang tren 1 km (VND): ";
	cin >> dGH;
	setShippingPeopleUnitPrice(dGN);
	setSeating(soCho);
	setShippingGoodsUnitPrice(dGH);
	TransportGoods::setDistance(qD);
	fstream xe,phuongTien;
	//Save the old data
	xe.open("XeBuyt.data", ios::in);
	string str = "", tmp = "";
	do {
		xe >> str;
		tmp += str + " ";
		str = "";
	} while (!xe.eof());
	xe.close();
	xe.open("XeBuyt.data", ios::out);
	xe << tmp << " " << getVehicleID() << " " << qD << " " << soCho << " " << soNguoiDi << " " << dGN << " " << soGoiHang << " " << dGH << " ";
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

void Bus::revenue()
{
	Vehicle::setInterest(TransportGoods::getDistance()*(getShippingGoodsUnitPrice()*soNguoiDi+soGoiHang*getShippingGoodsUnitPrice()));
}
