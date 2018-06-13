#pragma once
#include <string>
class Supplier {
private:
	std::string name;
	std::string address;
	std::string phone_number;
public:
	Supplier();
	~Supplier();
	Supplier(std::string n, std::string a, std::string p);
	void setName(std::string n);
	void setAddress(std::string a);
	void setPNumber(std::string p);
	std::string getName();
	std::string getPNumber();
	std::string getAddress();
	std::string print();
};