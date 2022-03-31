#include "string.h"
#include "Data.h"
#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__
class Employee
{



public:
	enum class Status
	{
		SECRETARY=0,
		EMPLOYED,
		MANAGER,
		DIRECTOR
	};
	Employee(char name[], char surname[], Date birthDay, int id, Date start, double selary, int status);
	Date exp(Date today);
	Date age(Date today);
	void print(Date today);
	void promotion();
private:

	MyString e_name;
	MyString e_surname;
	Date e_birthDay;
	const int e_id;
	Date e_start;
	double e_selary;
	Employee::Status e_status;
};

#endif
