#ifndef __DATA_H__
#define __DATA_H__

class Date
{
private:
	int day, month, year;
	static const int dayInMonth[13];

public:
	Date(int day, int month, int year);
	Date(const Date &data);

	void print();

	Date difference(const Date &other);
	~Date();

private:
	Date();
	void setData(int day, int month, int year);
};


#endif
