#include <iostream>
#include "shape.h"
Shape::Shape(double width,double height)
{
	w=width;
	h=height;
}
Triangle::Triangle(double width,double height):Shape(width,height) {}
double Triangle::getArea()
{
	return w*h/2;
}
Rectangle::Rectangle(double width,double height):Shape(width,height) {}
double Rectangle::getArea()
{
	return w*h;
}
