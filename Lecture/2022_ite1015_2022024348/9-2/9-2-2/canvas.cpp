#include <iostream>
#include <vector>
#include <string>
#include "canvas.h"
Canvas::Canvas(size_t row, size_t col)
{
	width=col;
	height=row;
	std::vector<std::string> v;
	for(int i=0;i<=col;++i)
	{
		v.push_back(".");
	}
	for(int i=0;i<=row;++i)
	{
		canvas.push_back(v);
	}
	canvas[0][0]=" ";
	for(size_t i=1;i<=col;++i)
	{
		canvas[0][i]=std::to_string((i-1)%10);
	}
	for(size_t i=1;i<=row;++i)
	{
		canvas[i][0]=std::to_string((i-1)%10);
	}
	Print();
}
Canvas::~Canvas()
{
}
void Canvas::Resize(size_t w, size_t h)
{
	canvas.clear();
	std::vector<std::string> v;
	for(int i=0;i<=w;++i)
	{
		v.push_back(".");
	}
	for(int i=0;i<=h;++i)
	{
		canvas.push_back(v);
	}
	for(size_t i=1;i<=w;++i)
	{
		canvas[0][i]=std::to_string((i-1)%10);
	}
	for(size_t i=1;i<=h;++i)
	{
		canvas[i][0]=std::to_string((i-1)%10);
	}
	width=w;
	height=h;
}
void Canvas::DrawPixel(int y, int x, std::string& brush)
{
	if(y>0&&y<=height&&x>0&&x<=width)
	{
		canvas[y][x]=brush;
	}
}
void Canvas::Print()
{
	for(int i=0;i<=height;++i)
	{
		for(int j=0;j<=width;++j)
		{
			std::cout<<canvas[i][j];
		}
		std::cout<<std::endl;
	}
}
void Canvas::Clear()
{
	for(int i=0;i<=height;++i)
	{
		for(int j=0;j<=width;++j)
		{
			canvas[i][j]=".";
		}
	}
	canvas[0][0]=" ";
	for(int i=1;i<=width;++i)
	{
		canvas[0][i]=std::to_string((i-1)%10);
	}
	for(int i=1;i<=height;++i)
	{
		canvas[i][0]=std::to_string((i-1)%10);
	}
}
Shape::~Shape()
{
}
Rectangle::Rectangle(int tlx,int tly,int w,int h,std::string& b)
{
	x=tlx;
	y=tly;
	width=w;
	height=h;
	brush=b;
}
void Rectangle::Draw(Canvas* canvas)
{
	for(int i=y+1;i<=y+height;++i)
	{
		for(int j=x+1;j<=x+width;++j)
		{
			canvas->DrawPixel(i,j,brush);
		}
	}
}
void Rectangle::Print()
{
	std::cout<<"rect "<<x<<" "<<y<<" "<<width<<" "<<height<<" "<<brush<<std::endl;
}
UpTriangle::UpTriangle(int tcx,int tcy,int h,std::string& b)
{
	x=tcx;
	y=tcy;
	height=h;
	brush=b;
}
void UpTriangle::Draw(Canvas* canvas)
{
	for(int i=0;i<height;++i)
	{
		for(int j=x-i+1;j<=x+i+1;++j)
		{
			canvas->DrawPixel(y+i+1,j,brush);
		}
	}
}
void UpTriangle::Print()
{
	std::cout<<"tri_up "<<x<<" "<<y<<" "<<brush<<std::endl;
}
DownTriangle::DownTriangle(int bcx,int bcy,int h,std::string& b)
{
	x=bcx;
	y=bcy;
	height=h;
	brush=b;
}
void DownTriangle::Draw(Canvas* canvas)
{
	for(int i=0;i<height;++i)
	{
		for(int j=x-i+1;j<=x+i+1;++j)
		{
			canvas->DrawPixel(y-i+1,j,brush);
		}
	}
}
void DownTriangle::Print()
{
	std::cout<<"tri_down "<<x<<" "<<y<<" "<<height<<std::endl;
}
Diamond::Diamond(int tcx,int tcy,int d,std::string& b)
{
	x=tcx;
	y=tcy;
	distance=d;
	brush=b;
}
void Diamond::Draw(Canvas* canvas)
{
	for(int i=0;i<=distance/2+1;++i)
	{
		for(int j=x-i+1;j<=x+i+1;++j)
		{
			canvas->DrawPixel(y+i+1,j,brush);
		}
	}
	for(int i=0;i<=distance/2;++i)
	{
		for(int j=x-i+1;j<=x+i+1;++j)
		{
			canvas->DrawPixel(y+2*distance-i+1,j,brush);
		}
	}
}
void Diamond::Print()
{
	std::cout<<"diamond "<<x<<" "<<y<<" "<<distance<<" "<<brush<<std::endl;
}
