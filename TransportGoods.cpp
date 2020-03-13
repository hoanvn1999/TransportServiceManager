#include "stdafx.h"
#include "TransportGoods.h"


TransportGoods::TransportGoods()
{
	weight = distance = shippingGoodsUnitPrice = 0;
}

long long TransportGoods::getWeight()
{
	return weight;
}

long long TransportGoods::getDistance()
{
	return distance;
}

long long TransportGoods::getShippingGoodsUnitPrice()
{
	return shippingGoodsUnitPrice;
}

void TransportGoods::setWeight(long long nang)
{
	weight = nang;
}

void TransportGoods::setDistance(long long qD)
{
	distance = qD;
}

void TransportGoods::setShippingGoodsUnitPrice(long long dGT)
{
	shippingGoodsUnitPrice = dGT;
}

void TransportGoods::inputVehicle() {
	Vehicle::inputVehicle();
	cout << "Nhap can nang cua hang tren xe (kg): ";
	cin >> weight;
	cout << "Nhap quang duong di cua xe (km): ";
	cin >> distance;
	cout << "Nhap don gia thue cua xe (VND/kg/km): ";
	cin >> shippingGoodsUnitPrice;
}

void TransportGoods::revenue()
{
	Vehicle::setInterest(weight*shippingGoodsUnitPrice*distance);
}
