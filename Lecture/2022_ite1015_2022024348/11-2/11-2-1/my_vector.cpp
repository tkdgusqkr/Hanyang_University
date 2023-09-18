#include <iostream>
#include "my_vector.h"
MyVector::MyVector(int _length)
{
	length=_length;
	a=new double[length];
	for(int i=0;i<length;++i)
	{
		a[i]=0;
	}
}
MyVector::~MyVector()
{
	delete[] a;
}
MyVector& MyVector::operator=(const MyVector& b)
{
	this->length=b.length;
	for(int i=0;i<b.length;++i)
	{
		this->a[i]=b.a[i];
	}
	return *this;
}
MyVector MyVector::operator+(const MyVector& b)
{
	MyVector tmp(b.length);
	for(int i=0;i<b.length;++i)
	{
		tmp.a[i]=this->a[i]+b.a[i];
	}
	return tmp;
}
MyVector MyVector::operator-(const MyVector& b)
{
	MyVector tmp(b.length);
	for(int i=0;i<length;++i)
	{
		tmp.a[i]=this->a[i]-b.a[i];
	}
	return tmp;
}
MyVector MyVector::operator+(const int b)
{
	MyVector tmp(this->length);
	for(int i=0;i<this->length;++i)
	{
		tmp.a[i]=this->a[i]+b;
	}
	return tmp;
}
MyVector MyVector::operator-(const int b)
{
	MyVector tmp(this->length);
	for(int i=0;i<this->length;++i)
	{
		tmp.a[i]=this->a[i]-b;
	}
	return tmp;
}
std::ostream& operator<<(std::ostream& out, MyVector& b)
{
	for(int i=0;i<b.length;++i)
	{
		out<<b.a[i]<<" ";
	}
	return out;
}
std::istream& operator>>(std::istream& in, MyVector& b)
{
	for(int i=0;i<b.length;++i)
	{
		in>>b.a[i];
	}
	return in;
}
