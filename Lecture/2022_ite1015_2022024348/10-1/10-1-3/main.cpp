#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
class B 
{
	public:
		    virtual ~B() {}
};
class C : public B
{
	public:
		    void test_C() { std::cout << "C::test_C()" << std::endl; }
};
class D : public B
{
	public:
		    void test_D() { std::cout << "D::test_D()" << std::endl; }
};
int main()
{
	std::vector<B*> arr;
	while(1)
	{
		std::string cmd;
		std::cin>>cmd;
		if(cmd=="B")
		{
			arr.push_back(new B);
		}
		else if(cmd=="C")
		{
			arr.push_back(new C);
		}
		else if(cmd=="D")
		{
			arr.push_back(new D);
		}
		else
		{
			for(int i=0;i<arr.size();++i)
			{
				if(typeid(*arr[i])==typeid(C))
				{
					dynamic_cast<C*>(arr[i])->test_C();
				}
				else if(typeid(*arr[i])==typeid(D))
				{
					dynamic_cast<D*>(arr[i])->test_D();
				}
			}
			break;
		}
	}
	for(int i=0;i<arr.size();++i)
	{
		delete arr[i];
	}
}
