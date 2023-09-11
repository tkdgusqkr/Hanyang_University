#include <iostream>
#include "my_string.h"
using namespace std;
int main()
{
	string command;
	cin>>command;
	MyString a,b;
	cout<<"enter a"<<endl;
	cin>>a;
	cout<<"enter b"<<endl;
	cin>>b;
	while(1)
	{
		string cmd;
		cin>>cmd;
		if(cmd=="a")
		{
			string oper;
			cin>>oper;
			if(oper=="*")
			{
				int num;
				cin>> num;
				MyString c=a*num;
				cout<<c<<endl;
			}
			else
			{
				string obj;
				cin>>obj;
				if(obj=="a")
				{
					MyString c=a+a;
					cout<<c<<endl;
				}
				else
				{
					MyString c=a+b;
					cout<<c<<endl;
				}
			}
		}
		else if(cmd=="b")
		{
			string oper;
			cin>>oper;
			if(oper=="*")
			{
				int num;
				cin>> num;
				MyString c=b*num;
				cout<<c<<endl;
			}
			else
			{
				string obj;
				cin>>obj;
				if(obj=="a")
				{
					MyString c=b+a;
					cout<<c<<endl;
				}
				else
				{
					MyString c=b+b;
					cout<<c<<endl;
				}
			}
		}
		else
		{
			break;
		}
	}
	return 0;
}
