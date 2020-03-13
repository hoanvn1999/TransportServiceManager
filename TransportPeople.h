#pragma once
#include "Vehicle.h"
class TransportPeople : virtual public Vehicle
{
private:
	long long seating;
	long long distance;
	long long shippingPeopleUnitPrice;
public:
	TransportPeople();
	long long getSeating();
	long long getDistance();
	long long getShippingPeopleUnitPrice();
	void setSeating(long long soCho);
	void setDistance(long long qD);
	void setShippingPeopleUnitPrice(long long dGT);
	void inputVehicle();
	void revenue();
	
};

