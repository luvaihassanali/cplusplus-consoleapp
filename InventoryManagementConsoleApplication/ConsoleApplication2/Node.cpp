#include "stdafx.h"
#include "Node.h"
#include <iostream>

Node::Node(Product * d)
{
	data = d;
	this->next = nullptr;
	this->prev = nullptr;
}

Product * Node::getData()
{
	return data;
}

Node::~Node()
{
	delete data;
	this->next = nullptr;
	this->prev = nullptr;
}
