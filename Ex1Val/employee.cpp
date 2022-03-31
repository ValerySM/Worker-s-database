#include "employee.h"
#include <iostream>


Employee::Employee(char name[], char surname[], Date birthDay, int id, Date start, double selary, int status)
	:e_name(name),
	e_surname(surname),
	e_birthDay(birthDay),
	e_start(start),
	e_id(id)
{
	this->e_selary = selary;
	this->e_status = (Status)status;
}

Date Employee::exp(Date today)
{
	return e_start.difference(today);
}

Date Employee::age(Date today)
{
	return e_birthDay.difference(today);
}

void Employee::print(Date today)
{
	this->e_name.print();
	std::cout << " ";
	this->e_surname.print();
	std::cout << std::endl;
	std::cout << "Status ";
	switch (e_status)
	{
	case Status::DIRECTOR:
		std::cout << "Director";
		break;
	case Status::EMPLOYED:
		std::cout << "Employed";
		break;
	case Status::MANAGER:
		std::cout << "Manager";
		break;
	case Status::SECRETARY:
		std::cout << "Secretary";
	}
	std::cout << std::endl;
	std::cout << "Selary: " << e_selary << std::endl;
	std::cout << "Age: ";
	age(today).print();
	std::cout <<std::endl<< "Exp: ";
	exp(today).print();
	std::cout << std::endl;
}

void Employee::promotion()
{
	switch (e_status)
	{
	case(Status::SECRETARY):
		e_status = Status::MANAGER;
		break;
	case(Status::MANAGER):
		e_status = Status::EMPLOYED;
		break;
	case(Status::EMPLOYED):
		e_status = Status::DIRECTOR;
		break;
	case(Status::DIRECTOR):
		break;
	}
	e_selary *= 1.1;

}
