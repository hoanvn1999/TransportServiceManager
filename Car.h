#pragma once
#include "TransportPeople.h"
class Car: public TransportPeople
{
private:
	int phuongThucThue;
	long long thoiGianThue;
	long long donGiaNgay;
public:
	Car();
	long long getThoiGianThue();
	long long getDonGiaNgay();
	int getPhuongThucThue();
	void setPhuongThucThue(int chon);
	void setThoiGianThue(long long tGT);
	void setDonGiaNgay(long long dG);
	void revenue();
	void inputVehicle();
	
};

