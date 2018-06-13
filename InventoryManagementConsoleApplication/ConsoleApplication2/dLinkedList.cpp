#include "stdafx.h"
#include "dLinkedList.h"
#include <list>
dLinkedList::dLinkedList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

dLinkedList::~dLinkedList()
{
	deleteSuppliers(this->head);
	Node* curr = this->head;
	int tracker = 0;
	if (this->head == nullptr) return;
	while (this->head != nullptr)
	{
		tracker++;
		std::cout << std::to_string(tracker) + ".deleting product\n";
		Node* temp = this->head;
		this->head = this->head->next;
		delete temp;
	}
}

Node * dLinkedList::getHead()
{
	return this->head;
}

void dLinkedList::addNode(Product * p)
{
	Node *newNode = new Node(p);
	newNode->next = this->head;
	newNode->prev = nullptr;
	if (this->head != nullptr)
		this->head->prev = newNode;
	this->head = newNode;
	size++;
}

void dLinkedList::printList(Node * head)
{
	std::cout << "\n Printing list of size: " + std::to_string(size) + "\n";
	while (head != nullptr) 
	{
		std::cout << (head->getData()->print());
		head = head->next;
	}
}

void dLinkedList::printProducts(Node * head)
{
	std::cout << "\n Products:\n";
	int tracker = 1;
	std::cout << "    NAME -->"  << "PRICE -->" << "DAYS TILL EXPIRY -->" << "STOCK AMOUNT\n\n";
	while (head != nullptr)
	{
		std::cout << std::to_string(tracker)+". " << (head->getData()->printProduct());
		head = head->next;
		tracker++;
	}
}

void dLinkedList::printSuppliers(Node * head)
{
	std::cout << "\n Suppliers:\n";
	int tracker = 1; 
	std::cout << "    NAME -->" << "ADDRESS -->" << "PHONE NUMBER\n\n";
	std::list<Node> list;
	while(head != nullptr)
	{
		if(tracker == 1) 
		{
			std::cout << std::to_string(tracker) + ". " << (head->getData()->printSupplier());
			list.push_front(*head);
			head = head->next;
			tracker++;
		}
		bool found = false;
		for (std::list<Node>::iterator it = list.begin(); it != list.end(); it++)
		{
			if (it->getData()->getSupplierName() == head->getData()->getSupplierName())
			{
				found = true;
			}
		}
		if (found == true)
		{

		}
		else 
		{
			std::cout << std::to_string(tracker) + ". " << (head->getData()->printSupplier());
			list.push_front(*head);
		}
		head = head->next;
		tracker++;
	}
}

void dLinkedList::deleteSuppliers(Node * head)
{
	int tracker = 0;
	while (head != nullptr) 
	{
		tracker++;
		std::cout << std::to_string(tracker) + ". deleting supplier\n";
		delete head->getData()->getSupplier();
		head = head->next;
	}
}

void dLinkedList::deleteProduct(std::string name, Node * head)
{
	while (head != nullptr) 
	{
		if (name == head->getData()->getName()) {
			head->prev->next = head->next;
			head->next->prev = head->prev;
			delete head->getData()->getSupplier();
			delete head;
			std::cout << "\n Product deleted succesfully\n";
			return;
		}
		head = head->next;
	}
	std::cout << "\n Product not found\n";
}

Supplier* dLinkedList::searchSuppliers(std::string name, Node* head)
{
	while (head != nullptr)
	{
		if (name.compare(head->getData()->getName()))
			return head->getData()->getSupplier();
		head = head->next;
	}
	return nullptr;
}

bool dLinkedList::increaseStock(Node * head, std::string name, int count)
{
	while (head != nullptr)
	{
		if (head->getData()->getName() == name)
		{
			head->getData()->incCount(count);
			return true;
		}
		head = head->next;
	}
	return false;
}
