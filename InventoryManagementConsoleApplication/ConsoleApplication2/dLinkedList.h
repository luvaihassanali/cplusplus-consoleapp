#pragma once
#include "Node.h"
#include <iostream>

class dLinkedList {
private:
	Node * head;
	Node *tail;
public:
	int size;
	dLinkedList();
	~dLinkedList();
	Node*  getHead();
	void addNode(Product *p);
	void printList(Node* head);
	void printProducts(Node* head);
	void printSuppliers(Node* head);
	void deleteSuppliers(Node* head);
	void deleteProduct(std::string name, Node* head);
	Supplier* searchSuppliers(std::string name, Node *head);
	bool increaseStock(Node *head, std::string name, int count);
};