#include <iostream>
#include <vector>
#include "intset.h"
using namespace std;
int main()
{
	IntegerSet integerset;
	while(1)
	{
		string command;
		cin>>command;
		if(command=="add")
		{
			int num;
			cin>>num;
			integerset.AddNumber(num);
			vector<int> array=integerset.GetAll();
			for(int i=0;i<array.size();i++)
			{
				cout<<array[i]<<' ';
			}
			cout<<'\n';
		}
		else if(command=="del")
		{
			int num;
			cin>>num;
			integerset.DeleteNumber(num);
			vector<int> array=integerset.GetAll();
			for(int i=0;i<array.size();i++)
			{
				cout<<array[i]<<' ';
			}
			cout<<'\n';
		}
		else if(command=="get")
		{
			int pos;
			cin>>pos;
			cout<<integerset.GetItem(pos)<<'\n';
		}
		else
		{
			break;
		}
	}
	return 0;
}
