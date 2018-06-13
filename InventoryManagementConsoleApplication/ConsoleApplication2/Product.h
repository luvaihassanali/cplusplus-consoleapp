#pragma once
#include "Supplier.h"

class Product {
private:
	std::string name;
	double price;
	int days_till_expiry;
	Supplier *supplier;
	int count;
public:
	Product();
	~Product();
	void setName(std::string n);
	void setPrice(double p);
	void setExpiry(int i);
	void setSupplier(Supplier* s);
	void setCount(int c);
	void incCount(int c);
	void decCount(int c);
	int getCount();
	Supplier* getSupplier();
	std::string getSupplierName();
	int getExpiry();
	double getPrice();
	std::string getName();
	std::string print();
	std::string printProduct();
	std::string printSupplier();
};

class Perishable : public Product {
public:
	Perishable(std::string n, double p, Supplier *s, int c, int i);
	~Perishable();
};

class NonPerishable : public Product {
public:
	NonPerishable(std::string n, double p, Supplier *s, int c);
	~NonPerishable();
};