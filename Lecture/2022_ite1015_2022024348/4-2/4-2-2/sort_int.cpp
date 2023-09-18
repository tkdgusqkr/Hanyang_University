#include <iostream>
using namespace std;
int N;
void sort(int *arr)
{
	for(int i=0;i<N;++i)
	{
		for(int j=1;j<N-i;++j)
		{
			if(arr[j-1]>arr[j])
			{
				int tmp=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=tmp;
			}
		}
	}
}
int main()
{
	cin>>N;
	if(N<=0)
	{
		return 0;
	}
	int *arr=new int[N];
	for(int i=0;i<N;++i)
	{
		cin>>arr[i];
	}
	sort(arr);
	for(int i=0;i<N;++i)
	{
		cout<<arr[i]<<' ';
	}
	delete[] arr;
	return 0;
}
