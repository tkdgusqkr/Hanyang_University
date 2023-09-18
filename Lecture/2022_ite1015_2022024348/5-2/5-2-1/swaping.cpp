#include <iostream>
void swapInt(int &n1,int &n2)
{
	int tmp=n1;
	n1=n2;
	n2=tmp;
}
void swapString(std::string &s1,std::string &s2)
{
	std::string tmp=s1;
	s1=s2;
	s2=tmp;
}
int main(int argc,char **argv)
{
	int n1=std::stoi(argv[1]);
	int n2=std::stoi(argv[2]);
	std::string s1=argv[3];
	std::string s2=argv[4];
	std::cout<<"n1: "<<n1<<", n2: "<<n2<<", s1: "<<s1<<", s2: "<<s2<<'\n';
	swapInt(n1,n2);
	swapString(s1,s2);
	std::cout<<"n1: "<<n1<<", n2: "<<n2<<", s1: "<<s1<<", s2: "<<s2<<'\n';
}
