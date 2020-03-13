#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Driver
{
private:
	string ID, name;
	long long salary;
public:
	Driver();
	string getID();
	string getName();
	long long getSalary();
	void setID(string idMoi);
	void setName(string tenMoi);
	void setSalary(long long tn);
	void inputDriver();
	void outputDriver();
	void wage();
	friend istream &operator >> (istream &in, Driver &t);
	friend ostream &operator << (ostream &out, Driver &t);
};

