#include <iostream>
#include "shapes.h"
using namespace std;
int main()
{
	int canvas_width,canvas_height;
	cin>>canvas_width>>canvas_height;
	while(1)
	{
		string command;
		cin>>command;
		if(command=="rect")
		{
			int x,y,width,height;
			string brush;
			cin>>x>>y>>width>>height>>brush;
			Rectangle rectangle(x,y,width,height,brush);
			cout<<"Area: "<<rectangle.GetArea()<<"\nPerimeter: "<<rectangle.GetPerimeter()<<endl;
			rectangle.Draw(canvas_width,canvas_height);
		}
		else if(command=="square")
		{
			int x,y,length;
			string brush;
			cin>>x>>y>>length>>brush;
			Square square(x,y,length,brush);
			cout<<"Area: "<<square.GetArea()<<"\nPerimeter: "<<square.GetPerimeter()<<endl;
			square.Draw(canvas_width,canvas_height);
		}
		else if(command=="diamond")
		{
			int x,y,distance;
			string brush;
			cin>>x>>y>>distance>>brush;
			Diamond diamond(x,y,distance,brush);
			cout<<"Area: "<<diamond.GetArea()<<"\nPerimeter: "<<diamond.GetPerimeter()<<endl;
			diamond.Draw(canvas_width,canvas_height);
		}
		else
		{
			break;
		}
	}
	return 0;
}
