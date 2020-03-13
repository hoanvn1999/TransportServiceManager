#pragma once
#include "TransportGoods.h"
class Truck: public TransportGoods
{
private:
	int phuongThucThue;
	long long thoiGianThue;
	long long donGiaNgay;
public:
	Truck();
	long long getThoiGianThue();
	long long getDonGiaNgay();
	int getPhuongThucThue();
	void setPhuongThucThue(int chon);
	void setThoiGianThue(long long tGT);
	void setDonGiaNgay(long long dG);
	void revenue();
	void inputVehicle();
};

