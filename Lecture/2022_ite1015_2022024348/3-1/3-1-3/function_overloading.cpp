#include <iostream>
int add(int a,int b)
{
	return a+b;
}
std::string add(std::string a,std::string b)
{
	return a+'-'+b;
}
int main()
{
	int a,b;
	std::string A,B;
	std::cin>>a>>b>>A>>B;
	std::cout<<add(a,b)<<std::endl<<add(A,B)<<std::endl;
}
