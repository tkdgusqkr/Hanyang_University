#include <iostream>
#include <vector>
class A
{
	public:
		virtual std::string getTypeInfo()
		{
			return "This is an instance of class A";
		}
};
class B:public A
{
	public:
		virtual std::string getTypeInfo()
		{
			return "This is an instance of class B";
		}	
};
class C:public B
{
	public:
		virtual std::string getTypeInfo()
		{
			return "This is an instance of class C";
		}
};
void printObjectTypeInfo1(A* object)
{
	std::cout<<object->getTypeInfo()<<std::endl;
}
void printObjectTypeInfo2(A& object)
{
	std::cout<<object.getTypeInfo()<<std::endl;
}
int main()
{
	std::vector<A*> arr;
	arr.push_back(new A);
	arr.push_back(new B);
	arr.push_back(new C);
	for(int i=0;i<3;++i)
	{
		printObjectTypeInfo1(arr[i]);
		printObjectTypeInfo2(*(arr[i]));
		delete arr[i];
	}
	delete arr;
	return 0;
}
