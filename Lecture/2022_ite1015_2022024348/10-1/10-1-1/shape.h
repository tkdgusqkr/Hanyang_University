#ifndef __SHAPE_H__
#define __SHAPE_H__
class Shape
{
	public:
		Shape(double width,double height);
		virtual double getArea()=0;
	protected:
		double w,h;
};
class Triangle:public Shape
{
	public:
		Triangle(double width,double height);
		double getArea();
};
class Rectangle:public Shape
{
	public:
		Rectangle(double width,double height);
		double getArea();
};
#endif
