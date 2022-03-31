#include "Data.h"
#include <iostream>
#include <iomanip>
const int Date::dayInMonth[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

Date::Date(int day, int month, int year)
{
	if (month < 1 || month>12)
	{
		std::cout << "Month has to be 1-12 but not " << month << std::endl;
		this->day = this->month = this->year = 0;
		return;
	}
	this->month = month;

	if (day<1 || day>dayInMonth[month])
	{
		std::cout << "Day in "<<month<<"th has to be 1-"<< dayInMonth[month]<<" but not " << day << std::endl;
		this->day = this->month = this->year = 0;
		return;
	}
	this->day = day;
	this->year = year;

}

Date::Date(const Date& data)
{
	this->day = data.day;
	this->month = data.month;
	this->year = data.year;
}

void Date::print()
{
	std::cout << std::setw(2) << std::setfill('0') << day << "\\" <<
		std::setw(2) << std::setfill('0') << month << "\\"
		<< std::setw(4) << std::setfill('0') << year;
}








Date Date::difference(const Date& other)
{
	int resultDay, resultMonth, resultYear;
	
	const Date* first=nullptr, *second=nullptr;
	Date result=Date();
	if (this->year < other.year)
	{
		first = this;
		second = &other;
	}
	else if (this->year > other.year)
	{
		first = &other;
		second = this;
	}
	else   //this->year == other.year
	{
		if (this->month < other.month)
		{
			first = this;
			second = &other;
		}
		else if (this->month > other.month)
		{
			first = &other;
			second = this;
		}
		else //this->month == other.month
		{
			if (this->day < other.day)
			{
				first = this;
				second = &other;
			}
			else if (this->day >= other.day)
			{
				first = &other;
				second = this;
			}
		}
	}


//data diff
	resultYear = second->year - first->year;
	if (first->month > second->month || (first->month == second->month && first->day > second->day))
	{
		resultYear--;
		resultMonth = second->month - first->month + 12;
	}
	else
	{
		resultMonth = second->month - first->month;
	}
	if (first->day > second->day)
	{
	
		resultDay = second->day - first->day + dayInMonth[resultMonth];
		resultMonth--;
	}
	else
		resultDay = second->day - first->day;
	
	resultMonth++;
//end of data diff


	result.setData(resultDay, resultMonth, resultYear);
	return result;
	
}

Date::~Date()
{
}

Date::Date()
{
	year = day = month = 0;
}

void Date::setData(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}
