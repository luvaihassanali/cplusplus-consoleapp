#pragma once
#include "Product.h"

class Node {
private:
	Product * data;
public:
	Node * next;
	Node *prev;
	Node(Product *d);
	Product* getData();
	~Node();
};