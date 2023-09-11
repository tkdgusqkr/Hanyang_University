#include <iostream>
#include "my_vector2.h"
MyVector2::MyVector2(int _length)
{
	length=_length;
	a=new double[length];
	for(int i=0;i<length;++i)
	{
		a[i]=0;
	}
}
MyVector2::~MyVector2()
{
	delete[] a;
}
MyVector2 MyVector2::operator+(const MyVector2& b)
{
	MyVector2 tmp(b.length);
	for(int i=0;i<b.length;++i)
	{
		tmp.a[i]=this->a[i]+b.a[i];
	}
	return tmp;
}
MyVector2 MyVector2::operator-(const MyVector2& b)
{
	MyVector2 tmp(b.length);
	for(int i=0;i<length;++i)
	{
		tmp.a[i]=this->a[i]-b.a[i];
	}
	return tmp;
}
MyVector2 MyVector2::operator+(const int b)
{
	MyVector2 tmp(this->length);
	for(int i=0;i<this->length;++i)
	{
		tmp.a[i]=this->a[i]+b;
	}
	return tmp;
}
MyVector2 MyVector2::operator-(const int b)
{
	MyVector2 tmp(this->length);
	for(int i=0;i<this->length;++i)
	{
		tmp.a[i]=this->a[i]-b;
	}
	return tmp;
}
std::ostream& operator<<(std::ostream& out, MyVector2& b)
{
	for(int i=0;i<b.length;++i)
	{
		out<<b.a[i]<<" ";
	}
	return out;
}
std::istream& operator>>(std::istream& in, MyVector2& b)
{
	for(int i=0;i<b.length;++i)
	{
		in>>b.a[i];
	}
	return in;
}
