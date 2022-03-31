#include "dataBase.h"
#include <iostream>
DataBase::DataBase()
{
	head = nullptr;
	size = 0;

}

Employee* DataBase::getEmployee(int index) const
{
	Node* curent = head;
	if (index >= size)
		return nullptr;

	for (int i = 0; i < index; i++)
		curent = curent->getNext();
	return curent->getEmployee();
}

void DataBase::addEmployee(Employee employee)
{
	Node* newOne=nullptr, *last=nullptr;
	Employee* newEmp = new Employee(employee);
	newOne = new Node(newEmp);
	if (size == 0)
	{
		head = newOne;
		size++;
		return;
	}

	for (last = head; last->getNext() != nullptr; last = last->getNext());
	last->setNext(newOne);
	size++;


}

Employee* DataBase::removeEmployee(int index)
{
	Employee* result;
	if (index >= size)
		return nullptr;

	//first case
	if (index == 0)
	{
		if (size == 1)
		{
			result = head->getEmployee();
			delete head;
			head = nullptr;
			size--;
			return result;
		}
		else //size>1;
		{
			Node* oldHead = head;
			result = head->getEmployee();
			head = head->getNext();
			delete oldHead;
			size--;
			return result;
		}
	}
	else //index>0
	{
		Node* prev = head, *old=nullptr;

		for (int i = 0; i < index - 1; i++)
			prev = prev->getNext();

		old = prev->getNext();
		result = old->getEmployee();
		prev->setNext(old->getNext());
		delete old;
		size--;
		return result;
	}
}

void DataBase::print(Date today) const
{
	for (int i = 0; i < size; i++)
	{
		getEmployee(i)->print(today);
		std::cout << std::endl;
	}
}

DataBase::~DataBase()
{
	Node* cur,*next;
	cur = head;
	while (cur != nullptr)
	{
		next = cur->getNext();
		delete cur->getEmployee();
		delete cur;
		cur = next;
	}
	
}
