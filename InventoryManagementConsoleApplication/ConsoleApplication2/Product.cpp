#include "stdafx.h"
#include "Product.h"
#include <string>
#include <sstream>
#include <iostream>

Product::Product()
{
}

Product::~Product()
{
}

void Product::setName(std::string n)
{
	name = n;
}

void Product::setPrice(double p)
{
	price = p;
}

void Product::setExpiry(int i)
{
	days_till_expiry = i;
}
std::string Product::getSupplierName() 
{
	return supplier->getName();
}
void Product::setSupplier(Supplier* s)
{
	supplier = s;
}

void Product::setCount(int c)
{
	count = c;
}

void Product::incCount(int c)
{
	count += c;
}

void Product::decCount(int c)
{
	count -= c;
	if (count < 0) count = 0;
}

int Product::getCount()
{
	return count;
}


Supplier * Product::getSupplier()
{
	return supplier;
}

int Product::getExpiry()
{
	return days_till_expiry;
}

double Product::getPrice()
{
	return price;
}

std::string Product::getName()
{
	return name;
}

std::string Product::print()
{
	std::stringstream ss;
	ss << getPrice();
	std::string expiryString;
	if (getExpiry() == 999) {
		expiryString = "Non-perishable";
	}
	else {
		expiryString = std::to_string(getExpiry()) + " days";
	}
	return " PRODUCT - Name: " + getName() + " Price: " + ss.str() + " Expiry: " + expiryString + " Count: " + std::to_string(getCount()) + "\n   SUPPLIER - " + getSupplier()->print(); ;
}

std::string Product::printProduct()
{
	std::stringstream ss;
	ss << getPrice();
	std::string expiryString;
	if (getExpiry() == 999) {
		expiryString = "Non-perishable";
	}
	else {
		expiryString = std::to_string(getExpiry()) + " days";
	}
	return " " + getName()  + " --> " + ss.str() + " --> " + expiryString + " --> " + std::to_string(getCount()) + "\n\n";
}

std::string Product::printSupplier()
{
	return " " + getSupplier()->getName() + " --> " + getSupplier()->getAddress() + " --> " + getSupplier()->getPNumber() + "\n\n";
}

Perishable::Perishable(std::string n, double p, Supplier *s, int c, int i)
{
	setName(n);
	setPrice(p);
	setExpiry(i);
	setSupplier(s);
	setCount(c);
}

Perishable::~Perishable()
{
}

NonPerishable::NonPerishable(std::string n, double p, Supplier *s, int c)
{
	setName(n);
	setPrice(p);
	setExpiry(999);
	setSupplier(s);
	setCount(c);
}

NonPerishable::~NonPerishable()
{
}
