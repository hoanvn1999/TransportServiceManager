#pragma once
#include "Vehicle.h"
class TransportGoods : virtual public Vehicle
{
private:
	long long weight;
	long long distance;
	long long shippingGoodsUnitPrice;
public:
	TransportGoods();
	long long getWeight();
	long long getDistance();
	long long getShippingGoodsUnitPrice();
	void setWeight(long long nang);
	void setDistance(long long qD);
	void setShippingGoodsUnitPrice(long long dGT);
	void inputVehicle();
	void revenue();
};

