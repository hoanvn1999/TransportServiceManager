#include "stdafx.h"
#include "Vehicle.h"

Vehicle::Vehicle() {
	vehicleID = vehicleName = driverID = "";
	interest = 0;
}

long long Vehicle::getInterest() 
{
	return interest;
}

string Vehicle::getDriverID() 
{
	return driverID;
}

string Vehicle::getVehicleID() 
{
	return vehicleID;
}

string Vehicle::getVehicleName() 
{
	return vehicleName;
}

void Vehicle::setInterest(long long l) 
{
	interest = l;
}

void Vehicle::setDriverID(string IDTX) 
{
	driverID = IDTX;
}

void Vehicle::setVehicleID(string IDX) 
{
	vehicleID = IDX;
}

void Vehicle::setVehicleName(string name) 
{
	vehicleName = name;
}

void Vehicle::inputVehicle() 
{	
	Tools a;
	cin.ignore();
	fstream pt;
	int fail;
	//Enter the infomation of vehicle.
	do {
		fail = 0;
		cout << "\n\t\tHUONG DAN:\n\tXe con : CAR + bien so xe\n\tXe buyt: BUS + bien so xe\n\tXe tai : TRU + bien so xe\n\n";
		string str = "";
		cout << "Nhap ID xe: ";
		getline(cin, vehicleID);
		for (int i = 0; i < vehicleID.length(); i++) {
			vehicleID[i] = toupper(vehicleID[i]);
			if (i < 3)
				str += vehicleID[i];
		}
		//Check the accuracy of the ID
		if (str == "CAR" || str == "BUS" || str == "TRU")
		{
			pt.open("PhuongTien.data", ios::in);
			//Check the existence of ID.
			do {
				pt >> str;
				if (str == vehicleID) {
					cout << "ID da ton tai tren he thong. Vui long nhap lai ID khac." << endl;
					fail = 1;
					break;
				}
			} while (!pt.eof());
			pt.close();
		}
		else 
		{
			fail = 1;
		}
	} while (fail==1);
	cout << "Nhap ten xe: ";
	getline(cin, vehicleName);
	a.convertToSave(vehicleName);
	cout << "Nhap ID tai xe lai xe: ";
	getline(cin, driverID);
}

void Vehicle::outputVehicle() 
{
	Tools a;
	cout << "ID xe: " << vehicleID << "\n\tTen xe: " << a.convertToShow(vehicleName) << "\n\tID tai xe lai xe: " << driverID << "\n\tDoanh thu cua xe: " << interest << endl;
}

void Vehicle::revenue()
{
	interest = 0;
}

ostream &operator << (ostream &out, Vehicle &p)
{
	p.outputVehicle();
	return out;
}