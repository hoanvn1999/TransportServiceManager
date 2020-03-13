#include "stdafx.h"
#include "ListOfVehicle.h"


void ListOfVehicle::readListVehicle()
{
	//Read data from PhuongTien.data.
	n = 0;
	fstream XE;
	XE.open("PhuongTien.data",ios::in);
	string idXe, idTaiXe, tenXe;
	long long lai;
	do {
		XE >> idXe >> tenXe >> idTaiXe >> lai;
		pt[n].setVehicleID(idXe);
		pt[n].setDriverID(idTaiXe);
		pt[n].setVehicleName(tenXe);
		pt[n].setInterest(lai);
		n++;
	} while (!XE.eof());
	XE.close();
	n--;
	//Arrange revenue incrementally
	sortRevenue();
}

void ListOfVehicle::inputListVehicle()
{
	readListVehicle();
	Vehicle *a;
	char Chon, Loai;
	do {
		//Choose the type of vehicle
		do {
			system("CLS");
			cout << "Xe Con, Xe Buyt hay Xe Tai (C/B/T)?\n\tChon: ";
			cin >> Loai;
			Loai = toupper(Loai);
			if(Loai == 'C' || Loai == 'B' || Loai == 'T')
			{
				break;
			}
			else {
				cout << "Nhap sai, vui long nhap lai, hoac lien he nha phat trien\n";
				Tools tacGia;
				tacGia.thongTinTacGia();
			}
		} while (Loai != 'C' || Loai != 'B' || Loai != 'T');
		if (Loai == 'C')
			a = new Car;
		else if (Loai == 'B')
			a = new Bus;
		else 
			a = new Truck;
		a->inputVehicle();
		cout << "Tiep tuc (C/K)?\n\tChon: ";
		cin >> Chon;
		Chon = toupper(Chon);
		if ((n == 100) || (Chon == 'K'))
			break;
	} while (true);
	readListVehicle();
}

void ListOfVehicle::outputVehicle(Vehicle p)
{
	Tools a;
	cout << "\t\tID Xe: " << p.getVehicleID() << "\n\t\tID Tai xe: " << p.getDriverID() << "\n\t\tTen xe: " << a.convertToShow(p.getVehicleName()) <<"\n\t\tLoi nhuan: " << p.getInterest() << endl;
}

void ListOfVehicle::outputListVehicle()
{
	readListVehicle();
	for (int i = 0; i < n; i++)
	{
		cout << "Xe thu " << i + 1 << ":\n";
		cout << pt[i];
	}
}

long long ListOfVehicle::sumOfRevenue()
{
	long long s = 0;
	fstream XE;
	XE.open("PhuongTien.data", ios::in);
	string idXe, idTaiXe, tenXe;
	long long lai;
	do {
		XE >> idXe >> tenXe >> idTaiXe >> lai;
		s += lai;
		lai = 0;
	} while (!XE.eof());
	XE.close();
	return s;
}

void ListOfVehicle::sortRevenue()
{
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if (pt[i].getInterest() > pt[i].getInterest()) 
			{
				Vehicle tmp = pt[i];
				pt[i] = pt[j];
				pt[j] = tmp;
			}
}

void ListOfVehicle::maxOfRevenue()
{
	Vehicle tmp = pt[0];
	for (int i = 1; i < n; i++)
	{
		if (pt[i].getInterest() > tmp.getInterest())
			tmp = pt[i];
	}
	cout << "Xe co danh thu cao nhat la:" << endl;
	outputVehicle(tmp);
}

void ListOfVehicle::minOfRevenue()
{
	Vehicle tmp = pt[0];
	for (int i = 1; i < n; i++)
	{
		if (pt[i].getInterest() < tmp.getInterest())
			tmp = pt[i];
	}
	cout << "Xe co danh thu thap nhat la:" << endl;
	outputVehicle(tmp);
}

long long ListOfVehicle::averageOfRevenue()
{
	long long s = 0;
	int i = -1;
	fstream XE;
	XE.open("PhuongTien.data", ios::in);
	string idXe, idTaiXe, tenXe;
	long long lai;
	do {
		XE >> idXe >> tenXe >> idTaiXe >> lai;
		s += lai;
		lai = 0;
		i++;
	} while (!XE.eof());
	XE.close();
	if(i>0)
		return (s/i);
	return 0;
}

void ListOfVehicle::financialReport()
{
	cout << "BAO CAO TAI CHINH" << endl;
	cout<<"\tTong doanh thu cua cong ty:"<<sumOfRevenue()<<"\n\tTrung binh doanh thu tren tung xe: "<<averageOfRevenue()<<"\n\t";
	maxOfRevenue();
	cout << "\t";
	minOfRevenue();
}



void ListOfVehicle::updateInfo(string id)
{
	//Update infomation
	fstream f;
	string idXe, idTX, tX, tenXe, idTXGoc, tmp = "";
	long long tienGoc = 0, tien;
	int tonTai = 0;
	//Save the old data of PhuongTien.data
	f.open("PhuongTien.data", ios::in);
	do {
		f >> idXe >> tX >> idTX >> tien;
		if (id != idXe) {
			if (idXe != "")
				tmp += idXe + " " + tX + " " + idTX + " " + to_string(tien) + " ";
		}
		else {
			tienGoc = tien;
			idTXGoc = idTX;
			tenXe = tX;
			tonTai = 1;
		}
		idXe = "";
	} while (!f.eof());
	f.close();
	if (tonTai == 0)
		cout << "ID khong ton tai" << endl;
	else
	{
		tmp += id + " " + tenXe + " " + idTXGoc + " ";
		long long quangDuong, soNgayThue;
		//The first character is 'C'
		if (id[0] == 'C')
		{
			Car a;
			string tmp1 = "";
			int pTT;
			long long qD, tG, soCho, dGCN, dGN;
			f.open("XeCon.data", ios::in);
			do {
				f >> idXe >> pTT >> soCho >> qD >> dGCN >> tG >> dGN;
				if (id == idXe)
				{
					if (pTT == 1)
					{
						cout << "Nhap quang duong (km): ";
						cin >> quangDuong;
						qD += quangDuong;
					}
					else
					{
						cout << "Nhap thoi gian thue (ngay): ";
						cin >> soNgayThue;
						tG += soNgayThue;
					}
					a.setVehicleID(idXe);
					a.setPhuongThucThue(pTT);
					a.setSeating(soCho);
					a.setDistance(qD);
					a.setShippingPeopleUnitPrice(dGCN);
					a.setThoiGianThue(tG);
					a.setDonGiaNgay(dGN);
					a.revenue();
					tmp += to_string(a.getInterest()) + " ";
				}
				if (idXe != "")
					tmp1 += idXe + " " + to_string(pTT) + " " + to_string(soCho) + " " + to_string(qD) + " " + to_string(dGCN) + " " + to_string(tG) + " " + to_string(dGN) + " ";
				idXe = "";
			} while (!f.eof());
			f.close();
			f.open("PhuongTien.data", ios::out);
			f << tmp;
			f.close();
			f.open("XeCon.data", ios::out);
			f << tmp1;
			f.close();
		}
		//The first character is 'B'
		else if (id[0] == 'B')
		{
			string tmp1 = "";
			long long qD, soCho, soNguoiDi, dGN, soGoiHang, dGH, soNguoi, soHang;
			f.open("XeBuyt.data", ios::in);
			do {
				f >> idXe >> qD >> soCho >> soNguoiDi >> dGN >> soGoiHang >> dGH;
				if (id == idXe)
				{
					cout << "Nhap quang duong (km): ";
					cin >> quangDuong;
					qD += quangDuong;
					do {
						cout << "Nhap so nguoi di: ";
						cin >> soNguoi;
						if (soCho >= soNguoi)
							break;
						else
							cout << "Vui long nhap lai, so cho ngoi phai lon hon hoac bang so nguoi di tren xe." << endl;
					} while (true);
					soNguoiDi += soNguoi;
					cout << "Nhap so goi hang: ";
					cin >> soHang;
					tmp += to_string(qD*(soNguoiDi*dGN + soGoiHang*dGH)) + " ";
				}
				if (idXe != "")
					tmp1 += idXe + " " + to_string(qD) + " " + to_string(soCho) + " " + to_string(soNguoiDi) + " " + to_string(dGN) + " " + to_string(soGoiHang) + " " + to_string(dGH) + " ";
				idXe = "";
			} while (!f.eof());
			f.close();
			f.open("PhuongTien.data", ios::out);
			f << tmp;
			f.close();
			f.open("XeBuyt.data", ios::out);
			f << tmp1;
			f.close();
		}
		//It's a truck
		else
		{
			Truck a;
			string tmp1 = "";
			int pTT;
			long long qD, tG, cN, canNang, dGCH, dGN;
			f.open("XeTai.data", ios::in);
			do {
				f >> idXe >> pTT >> cN >> qD >> dGCH >> tG >> dGN;
				if (id == idXe)
				{
					if (pTT == 1)
					{
						cout << "Nhap quang duong (km): ";
						cin >> quangDuong;
						qD += quangDuong;
						cout << "Nhap can nang (kg): ";
						cin >> canNang;
						cN += canNang;
					}
					else
					{
						cout << "Nhap thoi gian thue (ngay): ";
						cin >> soNgayThue;
						tG += soNgayThue;
					}
					a.setVehicleID(idXe);
					a.setPhuongThucThue(pTT);
					a.setWeight(canNang);
					a.setDistance(qD);
					a.setShippingGoodsUnitPrice(dGCH);
					a.setThoiGianThue(tG);
					a.setDonGiaNgay(dGN);
					a.revenue();
					tmp += to_string(a.getInterest()) + " ";
				}
				if (idXe != "")
					tmp1 += idXe + " " + to_string(pTT) + " " + to_string(cN) + " " + to_string(qD) + " " + to_string(dGCH) + " " + to_string(tG) + " " + to_string(dGN) + " ";
				idXe = "";
			} while (!f.eof());
			f.close();
			f.open("PhuongTien.data", ios::out);
			f << tmp;
			f.close();
			f.open("XeTai.data", ios::out);
			f << tmp1;
			f.close();
		}
	}
	readListVehicle();
}

void ListOfVehicle::updateInfo()
{
	string id;
	cout << "Nhap ID can cap nhat thong tin: ";
	cin.ignore();
	getline(cin, id);
	updateInfo(id);
}