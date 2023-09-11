#include <iostream>
#include <vector>
class A
{
	public:
		virtual std::string test()
		{
			return "A::test()";
		}
};
class B:public A
{
	public:
		virtual std::string test()

		{
			return "B::test()";
		}
};
class C:public B
{
	public:
		virtual std::string test()
		{
			return "C::test()";
		}
};
int main()
{
	std::vector<A*> arr;
	arr.push_back(new A);
	arr.push_back(new B);
	arr.push_back(new C);
	std::vector<A*>::iterator iter=arr.begin();
	for(int i=0;i<3;++i)
	{
		std::cout<<arr[i]->test()<<std::endl;
		delete arr[i];
	}
	return 0;
}
