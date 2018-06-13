#include "stdafx.h"
#include "Supplier.h"
#include <iostream>

Supplier::Supplier()
{
}

Supplier::~Supplier() 
{
}

Supplier::Supplier(std::string n, std::string a, std::string p)
{
	name = n; address = a; phone_number = p;

}

void Supplier::setName(std::string n)
{
	name = n;
}

void Supplier::setAddress(std::string a)
{
	address = a;
}

void Supplier::setPNumber(std::string p)
{
	phone_number = p;
}

std::string Supplier::getName()
{
	return name;
}

std::string Supplier::getPNumber()
{
	return phone_number;
}

std::string Supplier::getAddress()
{
	return address;
}

std::string Supplier::print()
{
	return "Name: " + getName() + " Address: " + getAddress() + " Phone number: " + getPNumber() + "\n";
}
