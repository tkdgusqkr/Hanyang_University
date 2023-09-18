#include <iostream>
#include "shapes.h"
using namespace std;
int main()
{
	while(1)
	{
		char shape;
		cout<<"\n\nshape?\n";
		cin>>shape;
		if(shape=='C')
		{
			double x,y,r;
			cin>>x>>y>>r;
			Circle circle;
			cout<<"area: "<<circle.area(r)<<", perimeter: "<<circle.perimeter()<<'\n';
		}
		else if(shape=='R')
		{
			double tlx,tly,brx,bry;
			cin>>tlx>>tly>>brx>>bry;
			Rectangle rectangle;
			cout<<"area: "<<rectangle.area(tlx,tly,brx,bry)<<", perimeter: "<<rectangle.perimeter()<<'\n';
		}
		else
		{
			break;
		}
	}
	return 0;
}
