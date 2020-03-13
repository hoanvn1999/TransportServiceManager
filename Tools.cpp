#include "stdafx.h"
#include "Tools.h"


Tools::Tools()
{
	pham = "Pham";
	le = "Le";
	hoan = "Hoan";
}

void Tools::loading() {
	Sleep(400);
	cout << "\n\n\n\n\n\n\n\t\t\t      ********** HE THONG QUAN LI DICH VU VAN TAI **********\n\n\t\t\tDuoc thuc hien boi:\n\t\t\t\t\tPham Le Hoan (leader)\n\t\t\t\t\tPham Kha Minh Tri\n\t\t\t\t\tTran Phu Quy\n\t\t\t\t\tNguyen Van Vien\n\t\t\t\t\tPhan Le Trung Kien\n\n\t\t\tLOADING ";
	Sleep(200);
	for (int i = 0; i<28; i++) {
		Sleep(100);
		cout << ". ";
	}
	Sleep(2000);
	system("cls");
}

void Tools::trans()
{
	le = "Vo";
	pham = "Ngoc";
	hoan = "Ngan";
	for (int i = 0; i < 4; i++)
	{
		hoan[i] = (char(int(hoan[i]) + 2 - i));
		if (i < 2)
			le[i] = char(int(le[i]) - 10);
	}
	pham[0] = char(72);
	pham[1] = char(111);
	pham[2] = char(97);
	pham[3] = char(110);
}

string Tools::remind()
{
	return "Lien he nha phat trien.\n";
}

void Tools::thongTinTacGia()
{
	trans();
	cout << "\n\n\t\t\t\t\tTac gia: ";
	for (int i = 0; i < 4; i++)
		cout << hoan[i];
	cout << " ";
	for (int i = 0; i < 2; i++)
		cout << le[i];
	cout << " ";
	for (int i = 0; i < 4; i++)
		cout << pham[i];
	cout << "\n\t\t\t\t\tEmail: hoanvn1999@gmail.com\n" << endl;
	cout << "\n\t\t\t\t\tCac thanh vien: " << endl;
	cout << "\t\t\t\t\t\tPham Kha Minh Tri\n\t\t\t\t\t\tTran Phu Quy\n\t\t\t\t\t\tNguyen Van Vien\n\t\t\t\t\t\tPhan Le Trung Kien" << endl;
	Sleep(15000);
	system("cls");
}

void Tools::convertToSave(string &s)
{
	for (int i = 0; i < s.length(); i++)
		if (s[i] == ' ')
			s[i] = '_';
}

string Tools::convertToShow(string &s)
{
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '_')
			s[i] = ' ';
	return s;
}