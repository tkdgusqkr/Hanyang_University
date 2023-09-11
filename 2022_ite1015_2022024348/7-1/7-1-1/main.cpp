#include <iostream>
#include <string>
#include <vector>
#include "sorted.h"
using namespace std;
int main()
{
	SortedArray sortedarray;
	while(1)
	{
		string command;
		cin>>command;
		if(command=="ascend")
		{
			vector<int> array=sortedarray.GetSortedAscending();
			for(int i=0;i<array.size();i++)
			{
				cout<<array[i]<<' ';
			}
			cout<<'\n';
		}
		else if(command=="descend")
		{
			vector<int> array=sortedarray.GetSortedDescending();
			for(int i=0;i<array.size();i++)
			{
				cout<<array[i]<<' ';
			}
			cout<<'\n';
		}
		else if(command=="max")
		{
			cout<<sortedarray.GetMax()<<'\n';
		}
		else if(command=="min")
		{
			cout<<sortedarray.GetMin()<<'\n';
		}
		else if(command=="quit")
		{
			break;
		}
		else
		{
			sortedarray.AddNumber(stoi(command));
			while(getc(stdin)==' ')
			{
				int n;
				cin>>n;
				sortedarray.AddNumber(n);
			}
		}
	}
	return 0;
}
