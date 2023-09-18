#include <iostream>
#include "number.h"
using namespace std;
int main()
{
	while(1)
	{
		string command;
		cin>>command;
		if(command=="number")
		{
			int num;
			cin>>num;
			Number number;
			number.setNumber(num);
			cout<<"getNumber():"<<number.getNumber()<<endl;
		}
		else if(command=="square")
		{
			int num;
			cin>>num;
			Square square;
			square.setNumber(num);
			cout<<"getNumber():"<<square.getNumber()<<"\ngetSquare():"<<square.getSquare()<<endl;
		}
		else if(command=="cube")
		{
			int num;
			cin>>num;
			Cube cube;
			cube.setNumber(num);
			cout<<"getNumber():"<<cube.getNumber()<<"\ngetSquare():"<<cube.getSquare()<<"\ngetCube():"<<cube.getCube()<<endl;
		}
		else
		{
			break;
		}
	}
	return 0;
}
