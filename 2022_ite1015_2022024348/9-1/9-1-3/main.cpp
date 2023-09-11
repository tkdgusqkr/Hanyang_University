#include <iostream>
#include <vector>
class A
{
	public:
		A(int i)
		{
			memberA=new int;
			*memberA=i;
			std::cout<<"new memberA"<<std::endl;
		}
		virtual ~A()
		{
			delete memberA;
			std::cout<<"delete memberA"<<std::endl;
		}
		virtual void print()
		{
			std::cout<<"*memberA "<<*memberA<<std::endl;
		}
	private:
		int* memberA;
};
class B:public A
{
	public:
		B(double d):A(1)
		{
			memberB=new double;
			*memberB=d;
			std::cout<<"new memberB"<<std::endl;
		}
		virtual ~B()
		{
			delete memberB;
			std::cout<<"delete memberB"<<std::endl;
		}
		virtual void print()
		{
			A::print();
			std::cout<<"*memberB "<<*memberB<<std::endl;
		}
	private:
		double* memberB;
};
class C:public B
{
	public:
		C(const std::string& s):B(1.1)
		{
			memberC=new std::string;
			*memberC=s;
			std::cout<<"new memberC"<<std::endl;
		}
		virtual ~C()
		{
			delete memberC;
			std::cout<<"delete memberC"<<std::endl;
		}
		virtual void print()
		{
			B::print();
			std::cout<<"*memberC "<<*memberC<<std::endl;
		}
	private:
		std::string* memberC;
};
int main()
{
	int i;
	double d;
	std::string s;
	std::vector<A*> arr;
	std::cin>>i>>d>>s;
	arr.push_back(new A(i));
	arr.push_back(new B(d));
	arr.push_back(new C(s));
	for(int i=0;i<3;++i)
	{
		arr[i]->print();
	}
	for(int i=0;i<3;++i)
	{
		delete arr[i];
	}
	return 0;
}
