#include <iostream>
#include <string>
#include "my_vector2.h"
using namespace std;
int main()
{
	string command;
	int length;
	cin>>command>>length;
	MyVector2 a(length),b(length);
	cout<<"enter a"<<endl;
	cin>>a;
	cout<<"enter b"<<endl;
	cin>>b;
	while(1)
	{
		string obj1,cmd,obj2;
		cin>>obj1;
		if(obj1=="a")
		{
			cin>>cmd>>obj2;
			if(cmd=="+")
			{
				if(obj2=="a")
				{
					MyVector2 c(a+a);
					cout<<c<<endl;
				}
				else if(obj2=="b")
				{
					MyVector2 c(a+b);
					cout<<c<<endl;
				}
				else
				{
					MyVector2 c(a+stoi(obj2));
					cout<<c<<endl;
				}
			}
			else
			{
				if(obj2=="a")
				{
					MyVector2 c(a-a);
					cout<<c<<endl;
				}
				else if(obj2=="b")
				{
					MyVector2 c(a-b);
					cout<<c<<endl;
				}
				else
				{
					MyVector2 c(a-stoi(obj2));
					cout<<c<<endl;
				}
			}
		}
		else if(obj1=="b")
		{
			cin>>cmd>>obj2;
			if(cmd=="+")
			{
				if(obj2=="a")
				{
					MyVector2 c(b+a);
					cout<<c<<endl;
				}
				else if(obj2=="b")
				{
					MyVector2 c(b+b);
					cout<<c<<endl;
				}
				else
				{
					MyVector2 c(b+stoi(obj2));
					cout<<c<<endl;
				}
			}
			else
			{
				if(obj2=="a")
				{
					MyVector2 c(b-a);
					cout<<c<<endl;
				}
				else if(obj2=="b")
				{
					MyVector2 c(b-b);
					cout<<c<<endl;
				}
				else
				{
					MyVector2 c(b-stoi(obj2));
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
