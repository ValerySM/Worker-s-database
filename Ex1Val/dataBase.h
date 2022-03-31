#include "employee.h"
#include "Data.h"
#ifndef __DATABASE_H__
#define __DATABASE_H__

class DataBase {
private:
	class Node
	{
	public:
		Node(Employee* employee) {
			this->employee = employee;
			this->next = nullptr;
		}
	public:
		Employee* getEmployee()
		{
			return this->employee;
		}
		Node* getNext()
		{
			return this->next;
		}
		void setNext(Node* next)
		{
			this->next = next;
		}
	private:
		Employee* employee;
		Node* next;
	};

	Node* head;
	int size;
public:
	DataBase();
	Employee* getEmployee(int index) const;
	void addEmployee(Employee employee);
	Employee* removeEmployee(int index);
	void print(Date today) const;
	~DataBase();
};
#endif