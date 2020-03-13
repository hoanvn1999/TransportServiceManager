#pragma once
#include "ListOfVehicle.h"
#include "ListOfDriver.h"
#include "Tools.h"
#include "Identified.h"
class Login
{
private:
	string id, password;
public:
	Login();
	void changePassword();
	void Run();
	void createAccount();
	void Choose();
};

