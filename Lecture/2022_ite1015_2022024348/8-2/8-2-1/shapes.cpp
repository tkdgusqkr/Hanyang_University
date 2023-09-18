#include <iostream>
#include "shapes.h"
using namespace std;
Shape::Shape(){}
Shape::Shape(int width,int height)
{
	_width=width;
	_height=height;
}
Square::Square(int x,int y,int length,string brush):Shape(length,length)
{
	_x=x;
	_y=y;
	_brush=brush;
}
double Square::GetArea()
{
	return _width*_height;
}
int Square::GetPerimeter()
{
	return 2*(_width+_height);
}
void Square::Draw(int canvas_width,int canvas_height)
{
	cout<<" ";
	for(int i=0;i<canvas_width;++i)
	{
		cout<<i;
	}
	cout<<endl;
	for(int  i=0;i<canvas_height;++i)
	{
		cout<<i;
		for(int j=0;j<canvas_width;++j)
		{
			if(i>=_y&&i<_y+_height&&j>=_x&&j<_x+_width)
			{
				cout<<_brush;
			}
			else
			{
				cout<<".";
			}
		}
		cout<<endl;
	}
}
Rectangle::Rectangle(int x,int y,int width,int height,string brush):Shape(width,height)
{
	_x=x;
	_y=y;
	_brush=brush;
}
double Rectangle::GetArea()
{
	return _width*_height;
}
int Rectangle::GetPerimeter()
{
	return 2*(_width+_height);
}
void Rectangle::Draw(int canvas_width,int canvas_height)
{
	cout<<" ";
	for(int i=0;i<canvas_width;++i)
	{
		cout<<i;
	}
	cout<<endl;
	for(int  i=0;i<canvas_height;++i)
	{
		cout<<i;
		for(int j=0;j<canvas_width;++j)
		{
			if(i>=_y&&i<_y+_height&&j>=_x&&j<_x+_width)
			{
				cout<<_brush;
			}
			else
			{
				cout<<".";
			}
		}
		cout<<endl;
	}
}
Diamond::Diamond(int x,int y,int distance,string brush):Shape()
{
	_x=x;
	_y=y;
	_distance=distance;
	_brush=brush;
}
double Diamond::GetArea()
{
	return (double)((2*_distance+1)*(2*_distance+1))/2;
}
int Diamond::GetPerimeter()
{
	return _distance+1;
}
void Diamond::Draw(int canvas_width,int canvas_height)
{
	cout<<" ";
	for(int i=0;i<canvas_width;++i)
	{
		cout<<i;
	}
	cout<<endl;
	for(int  i=0;i<canvas_height;++i)
	{
		cout<<i;
		for(int j=0;j<canvas_width;++j)
		{
			bool check=false;
			for(int k=0;k<=_distance;++k)
			{
				if(i==_y+k&&j>=_x-k&&j<=_x+k)
				{
					check=true;
					cout<<_brush;
				}
			}
			for(int k=0;k<_distance;++k)
			{
				if(i==_y+2*_distance-k&&j>=_x-k&&j<=_x+k)
				{
					check=true;
					cout<<_brush;
				}
			}
			if(!check)
			{
				cout<<".";
			}
		}
		cout<<endl;
	}
}
