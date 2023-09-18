#include <iostream>
#include "minmax.h"
using namespace std;
int main(int argc,char **argv)
{
	int *arr=new int[argc-1];
	for(int i=0;i<argc-1;++i)
	{
		arr[i]=stoi(argv[i+1]);
	}
	int min,max;
	getMinMax(arr,min,max);
	delete[] arr;
	cout<<"min: "<<min<<'\n'<<"max: "<<max<<'\n';
	return 0;
}
