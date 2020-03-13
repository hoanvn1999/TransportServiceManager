#pragma once
#include "Driver.h"
#include "ListOfDriver.h"
#include "ListOfVehicle.h"
#include "Login.h"
#include "Identified.h"
#include <conio.h>

class ListOfDriver
{
private:
	int n=0;
	Driver tx[100];
public:
	void readListDriver();
	void inputListDriver();
	void outputListDriver();
	void sortSalary();
	void maxOfSalary();
	void findVehicle(string ID);
	void findDriverID(string ID);
	string passwd(unsigned maxLength);
	friend class Login;
	friend class Main;
};

