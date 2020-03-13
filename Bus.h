#pragma once
#include "TransportGoods.h"
#include "TransportPeople.h"
class Bus: virtual public TransportPeople, TransportGoods
{
private:
	long long soNguoiDi, soGoiHang;
public:
	Bus();
	long long getSoNguoiDi();
	long long getSoGoiHang();
	void setSoNguoiDi(long long soNguoi);
	void setSoGoiHang(long long soHang);
	void inputVehicle();
	void revenue();

};

