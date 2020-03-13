#pragma once
#include "Car.h"
#include "Bus.h"
#include "Truck.h"
#include "ListOfDriver.h"
#include "Login.h"

class ListOfVehicle
{
private:
	int n=0;
	Vehicle pt[100];
public:
	void readListVehicle();
	void inputListVehicle();
	void outputListVehicle();
	void updateInfo(string id);
	void updateInfo();
	long long sumOfRevenue();
	void sortRevenue();
	void outputVehicle(Vehicle p);
	void maxOfRevenue();
	void minOfRevenue();
	long long averageOfRevenue();
	void financialReport();
	friend class Login;
};

