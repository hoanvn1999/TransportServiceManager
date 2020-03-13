#pragma once
#include <iostream>
#include <string>
#include "Identified.h"
using namespace std;

class Tools
{
private:
	string pham, le, hoan;
public:
	Tools();
	void loading();
	void trans();
	string remind();
	void thongTinTacGia();
	void convertToSave(string &s);
	string convertToShow(string &s);
	friend class Login;
	friend class ListOfVehicle;
	friend class ListOfDriver;
	friend class Vehicle;
	friend class TransportGoods;
	friend class TransportPeople;
	friend class Driver;
	friend class Bus;
	friend class Car;
	friend class Truck;
	friend class Identified;
};

