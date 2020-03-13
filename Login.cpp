#include "stdafx.h"
#include "Login.h"

Login::Login()
{
	id = password = "";
}

void Login::Run()
{
	ListOfDriver dstx;
	Tools tacGia;
	int tc = 0, tb=0;
	string ttk = "", mk = "";
	//Choose the way to run program: login, show Tools's infomation or Exit
	system("CLS");
	tacGia.loading();
	PlaySound(TEXT("Main.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	do {
		int c;
		do {
			cout << "\n\n\n\n\n\n\t\t\t\t\t------------ TRANG CHU ------------" << endl << endl;
			cout << "\t\t\t\t\tNhap 1 de Dang nhap.\n\t\t\t\t\tNhap 2 de hien thi thong tin tac gia\n\t\t\t\t\tNhap 3 de ket thuc chuong trinh.\n\n\t\t\t\t\t\tNhap: ";
			cin >> c;
			//Re-enter if user enter character.
			if (!cin) {
				cin.clear();
				cin.ignore(numeric_limits<int>::max(), '\n');
				system("CLS");
				cout << "Nhap sai, vui long nhap lai theo huong dan." << endl;
				continue;
			}
			if (c == 1)
			{
				system("CLS");
				//Enter id and password to login
				cout << "\n\n\n\n\n\n\t\t\t\t\t******** DANG NHAP ********\n\n\t\t\t\t\tID\t: ";
				cin.ignore();
				getline(cin, id);
				cout << "\t\t\t\t\tMat khau: ";
				password = dstx.passwd(10);
				//Read the infomation in TaiKhoan.data to compare with data that user entered.
				fstream tk;
				tk.open("TaiKhoan.data", ios::in);
				do {
					tk >> ttk >> mk;
					if (ttk == id && mk == password && id.length() >= 4)
					{
						tc = 1;
						tb = 0;
						break;
					}
					ttk = "";
					mk = "";
				} while (!tk.eof());
				if (tc == 1) {
					tc = 0;
					Choose();
				}
				else {
					system("CLS");
					if (tb < 4)
						cout << "Tai khoan hoac mat khau khong ton tai, vui long nhap lai!\n" << endl;
					tb++;
				}
				//If user enter wrong 5 times -> Exit
				if (tb == 5) {
					cout << "Ban da nhap sai qua 5 lan. " << tacGia.remind();
					tacGia.thongTinTacGia();
					tb = 0;
					cout << "\nCHUONG TRINH DA KET THUC.\n";
					exit(0);
				}
				tk.close();
			}
			else if (c == 2) {
				system("CLS");
				Tools tacGia;
				tacGia.thongTinTacGia();
			}
			else if (c == 3) {
				cout << "\nCHUONG TRINH DA KET THUC.\n";
				exit(0);
			}
			else if (c == 100) {
				PlaySound(NULL, NULL, NULL);
				system("CLS");
			}
			else if (c == 200) {
				PlaySound(TEXT("Main.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
				system("CLS");
			}
			else {
				system("CLS");
				cout << "Nhap sai, vui long nhap lai theo huong dan." << endl;
			}
		} while (c != 1 || c != 2);
	} while (tc==0);
}

void Login::Choose()
{
	Tools tacGia;
	ListOfDriver dstx;
	ListOfVehicle dspt;
	dstx.readListDriver();
	dstx.sortSalary();
	dspt.readListVehicle();
	dspt.sortRevenue();
	int chon;
	//Driver
	if (id != "admin")
	{
		system("CLS");
		cout << "ID cua ban la: " << id << endl;
		do {
			cout << "Nhap theo huong dan: \n\t1. Kiem tra thong tin ca nhan.\n\t9. Doi mat khau.\n\t15.Dang xuat.\nChon: ";
			cin >> chon;
			if (!cin) {
				cin.clear();
				cin.ignore(numeric_limits<int>::max(), '\n');
				system("CLS");
				cout << "Nhap sai, vui long nhap lai theo huong dan." << endl;
				continue;
			}
			if (chon == 1)
			{
				system("CLS");
				dstx.findDriverID(id);
			}
			else if (chon == 9)
			{
				system("CLS");
				changePassword();
				system("CLS");
			}
			else if (chon == 15) 
			{
				system("CLS");
				cout << "Ban da dang xuat" << endl;
			}
			else if (chon == 100) {
				PlaySound(NULL, NULL, NULL);
				system("CLS");
			}
			else if (chon == 200) {
				PlaySound(TEXT("Main.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
				system("CLS");
			}
			else 
			{
				system("CLS");
				cout << "Nhap sai, vui long nhap lai." << endl;
			}
		} while (chon != 15);
	}
	//Admintrator
	else 
	{
		system("CLS");
		cout << "ID cua ban la: " << id << endl;
		do {
			cout << "Nhap theo huong dan:\n\t1. Tao tai khoan moi cho quan tri vien.\n\t2. Nhap xe them xe moi.\n\t";
			cout << "3. Xuat danh sach xe.\n\t4. Xuat bao cao tai chinh.\n\t5. Nhap tai xe moi.\n\t";
			cout << "6. Xuat danh sach tai xe.\n\t7. Tai xe co luong cao nhat.\n\t8. Cap nhat du lieu xe.\n\t9. Doi mat khau.\n\t";
			cout << "10. Tim xe bang hinh anh (bien so).\n\t15. Dang xuat.\nChon: ";
			cin >> chon;
			if (!cin) {
				cin.clear();
				cin.ignore(numeric_limits<int>::max(), '\n');
				system("CLS");
				cout << "Nhap sai, vui long nhap lai theo huong dan." << endl;
				continue;
			}
			if (chon == 1)
			{
				system("CLS");
				cout << "ID: admin" << endl;
				createAccount();
				system("CLS");
			}
			else if (chon == 2) 
			{
				system("CLS");
				dspt.inputListVehicle();
				system("CLS");
			}
			else if (chon == 3)
			{
				system("CLS");
				dspt.outputListVehicle();
			}
			else if (chon == 4)
			{
				system("CLS");
				dspt.financialReport();
			}
			else if (chon == 5)
			{
				system("CLS");
				dstx.inputListDriver();
				system("CLS");
			}
			else if (chon == 6)
			{
				system("CLS");
				dstx.outputListDriver();
			}
			else if (chon == 7)
			{
				system("CLS");
				dstx.maxOfSalary();
			}
			else if (chon == 8) 
			{
				system("CLS");
				dspt.updateInfo();
				system("CLS");
			}
			else if (chon == 9) 
			{
				system("CLS");
				changePassword();
				system("CLS");
			}
			else if (chon == 10) 
			{
				system("CLS");
				identified();
			}
			else if (chon == 15) 
			{
				system("CLS");
				cout << "Ban da dang xuat!" << endl;
			}
			else if (chon == 100) {
				PlaySound(NULL, NULL, NULL);
				system("CLS");
			}
			else if (chon == 200) {
				PlaySound(TEXT("Main.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
				system("CLS");
			}
			else 
			{
				system("CLS");
				cout << "Nhap sai, vui long nhap lai." << endl;
			}
		} while (chon != 15);
	}
}

void Login::createAccount()
{
	ListOfDriver dstx;
	//Save the old data in the file
	fstream tk;
	string tmp="", s;
	tk.open("TaiKhoan.data", ios::in);
	do {
		tk >> s;
		tmp = tmp + s + " ";
		s = "";
	} while (!tk.eof());
	tk.close();
	//Enter the old password
	string newPass="";
	do {
		cout << "Nhap mat khau: ";
		s = dstx.passwd(10);
		cout << "Nhap lai mat khau: ";
		newPass = dstx.passwd(10);
		//Save new infomation
		if (s == newPass) {
			tk.open("TaiKhoan.data", ios::out);
			tk << tmp << " admin " << s << " ";
			tk.close();
		}
		else
			cout << "Mat khau khong khop, vui long nhap lai" << endl;
	} while (s != newPass);
}

void Login::changePassword()
{
	ListOfDriver dstx;
	int tc = 0;
	string ttk = "", mk = "", tmp="";
	//Save the old password
	fstream tk;
	tk.open("TaiKhoan.data", ios::in);
	do {
		tk >> ttk >> mk;
		if (ttk == id && mk == password)
		{
			tc=1;
		}
		else
			tmp = tmp + " " + ttk + " " + mk + " ";
		ttk = "";
		mk = "";
	} while (!tk.eof());
	tk.close();
	cout << "Nhap lai mat khau cu: ";
	cin.ignore();
	mk = dstx.passwd(10);
	string newPass="";
	if (mk == password) {
		do {
			cout << "Nhap mat khau moi: ";
			mk = dstx.passwd(10);
			cout << "Nhap lai mat khau: ";
			newPass = dstx.passwd(10);
			//Save new infomation
			if (mk == newPass) {
				tk.open("TaiKhoan.data", ios::out);
				tk << tmp << id << " " << mk << " ";
				tk.close();
				cout << "Doi mat khau thanh cong!\n" << endl;
			}
			else
				cout << "Mat khau khong khop, vui long nhap lai" << endl;
		} while (mk != newPass);
	}
	else
		cout << "Doi mat khau that bai!\n" << endl;
}
