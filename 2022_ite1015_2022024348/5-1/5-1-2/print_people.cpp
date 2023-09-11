#include <iostream>
#include <string>
using namespace std;
struct Person
{
	string name;
	double score;
};
int main(int argc,char **argv)
{
	struct Person *person=new struct Person[argc];
	for(int i=0;i<argc/2;++i)
	{
		person[i].name=argv[2*i+1];
		person[i].score=stod(argv[2*i+2]);
	}
	for(int i=0;i<argc/2;++i)
	{
		cout<<"Name:"<<person[i].name<<", Score:"<<person[i].score<<"\n";
	}
	delete[] person;
}
