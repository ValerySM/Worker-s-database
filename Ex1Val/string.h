#ifndef __STRING_H__
#define __STRING_H__

class MyString
{
public:

	MyString(char* str);
	MyString(const char str[]);
	~MyString();
	MyString(const MyString& other);
	void print();
	void set(char*);

private:

	char* str;
	int length;

};

#endif