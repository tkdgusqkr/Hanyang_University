#include <iostream>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int *arr=new int[N];
	for(int i=0;i<N;++i)
	{
		cin>>arr[i];
	}
	int min=arr[0];
	int max=arr[0];
	for(int i=0;i<N;++i)
	{
		if(min>arr[i])
		{
			min=arr[i];
		}
		if(max<arr[i])
		{
			max=arr[i];
		}
	}
	delete[] arr;
	cout<<"min: "<<min<<'\n'<<"max: "<<max<<'\n';
	return 0;
}
