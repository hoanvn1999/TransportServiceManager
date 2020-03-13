#pragma once

#include "Tools.h"

using namespace std;

class Vehicle
{
private:
	string driverID, vehicleID, vehicleName;
	long long interest;
public:
	Vehicle();
	string getDriverID();
	string getVehicleID();
	string getVehicleName();
	long long getInterest();
	void setDriverID(string IDTX);
	void setVehicleID(string IDX);
	void setVehicleName(string name);
	void setInterest(long long l);
	virtual void inputVehicle();
	virtual void revenue();
	virtual void outputVehicle();
	friend ostream &operator << (ostream &out, Vehicle &p);
};

