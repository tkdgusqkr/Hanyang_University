#include <iostream>
using namespace std;
struct Person
{
	string name;
	int age;
};
int main()
{
	int N;
	cin>>N;
	struct Person arr[N];
	for(int i=0;i<N;++i)
	{
		cin>>arr[i].name>>arr[i].age;
	}
	for(int i=0;i<N;++i)
	{
		cout<<"Name:"<<arr[i].name<<", Age:"<<arr[i].age<<'\n';
	}
	return 0;
}
