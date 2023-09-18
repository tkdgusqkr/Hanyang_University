#include <iostream>
#include <string>
#include "message.h"
using namespace std;
int main()
{
	MessageBook messagebook;
	while(1)
	{
		string command;
		cin>>command;
		if(command=="add")
		{
			int number;
			string message;
			cin>>number;
			cin.ignore();
			getline(cin,message);
			messagebook.AddMessage(number,message);
		}
		else if(command=="delete")
		{
			int number;
			cin>>number;
			messagebook.DeleteMessage(number);
		}
		else if(command=="print")
		{
			int number;
			cin>>number;
			cout<<messagebook.GetMessage(number)<<"\n\n";
		}
		else if(command=="list")
		{
			vector<int> numbers=messagebook.GetNumbers();
			for(auto element:numbers)
			{
				cout<<element<<": "<<messagebook.GetMessage(element)<<'\n';
			}
		}
		else
		{
			break;
		}
	}
	return 0;
}
