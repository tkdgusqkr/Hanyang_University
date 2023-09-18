#include <iostream>
#include "my_string2.h"
MyString2 MyString2::operator+(const MyString2& b)
{
	MyString2 tmp;
	tmp.str=this->str+b.str;
	return tmp;
}
MyString2 MyString2::operator*(const int b)
{
	MyString2 tmp;
	tmp.str="";
	for(int i=0;i<b;++i)
	{
		tmp.str=tmp.str+this->str;
	}
	return tmp;
}
std::ostream& operator<<(std::ostream& out, MyString2& my_string)
{
	out<<my_string.str;
	return out;
}
std::istream& operator>>(std::istream& in, MyString2& my_string)
{
	in>>my_string.str;
	return in;
}
