#include "stdafx.h"
#include "TransportPeople.h"


TransportPeople::TransportPeople()
{
	seating = distance = shippingPeopleUnitPrice = 0;
}

long long TransportPeople::getSeating() 
{
	return seating;
}


long long TransportPeople::getDistance() 
{
	return distance;
}

long long TransportPeople::getShippingPeopleUnitPrice()
{
	return shippingPeopleUnitPrice;
}

void TransportPeople::setSeating(long long soCho)
{
	seating = soCho;
}

void TransportPeople::setDistance(long long qD)
{
	distance = qD;
}

void TransportPeople::setShippingPeopleUnitPrice(long long dGT)
{
	shippingPeopleUnitPrice = dGT;
}

void TransportPeople::inputVehicle() 
{
	Vehicle::inputVehicle();
	cout << "Nhap so cho ngoi tren xe: ";
	cin >> seating;
	cout << "Nhap quang duong di cua xe (km): ";
	cin >> distance;
	cout << "Nhap don gia thue cua xe (VND/km): ";
	cin >> shippingPeopleUnitPrice;
}

void TransportPeople::revenue()
{
	Vehicle::setInterest(shippingPeopleUnitPrice*distance);
}