#ifndef __SHAPES_H__
#define __SHAPES_H__
class Circle
{
	private:
		double x,y,r;
	public:
		double area(double r_);
		double perimeter();
};
class Rectangle
{
	private:
		double tlx,tly,brx,bry;
	public:
		double area(double tlx_,double tly_,double brx_,double bry_);
		double perimeter();
};
#endif
