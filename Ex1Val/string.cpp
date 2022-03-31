#include "string.h"
#include <iostream>


MyString::MyString(char* str)
{
	int length = strlen(str);
	this->str = new char[length + (int)1];
	for (int i = 0; i < length; i++)
	{
		this->str[i] = str[i];
	}
	this->str[length] = '\0';
}

MyString::MyString(const char str[])
{
	int length = strlen(str);
	this->str = new char[length + (int)1];
	for (int i = 0; i < length; i++)
	{
		this->str[i] = str[i];
	}
	this->str[length] = '\0';
}

MyString::~MyString()
{
	delete[] this->str;
}

MyString::MyString(const MyString& other)
{
length = strlen(other.str);
this->str = new char[length + 1];

for (int i = 0; i < length; i++)
{
	this->str[i] = other.str[i];
}

this->str[length] = '\0';
}

void MyString::print()
{
	std::cout << this->str;
}

void MyString::set(char* str)
{
	delete[] this->str;
	int length = strlen(str);
	this->str = new char[length + (int)1];
	for (int i = 0; i < length; i++)
	{
		this->str[i] = str[i];
	}
	this->str[length] = '\0';
}
    