#include <iostream>
#include "rect.h"
using namespace std;
int main()
{
	while(1)
	{
		string command;
		cin>>command;
		if(command=="nonsquare")
		{
			int width,height;
			cin>>width>>height;
			NonSquare nonsquare(width,height);
			nonsquare.print();
			cout<<"Area: "<<nonsquare.getArea()<<"\nPerimeter: "<<nonsquare.getPerimeter()<<endl;
		}
		else if(command=="square")
		{
			int length;
			cin>>length;
			Square square(length);
			square.print();
			cout<<"Area: "<<square.getArea()<<"\nPerimeter: "<<square.getPerimeter()<<endl;
		}
		else
		{
			break;
		}
	}
	return 0;
}
