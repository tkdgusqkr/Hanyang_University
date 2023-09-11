#include "shapes.h"
double Circle::area(double r_)
{
	r=r_;
	return (3.14)*r*r;
}
double Circle::perimeter()
{
	return 2*(3.14)*r;
}
double Rectangle::area(double tlx_,double tly_,double brx_,double bry_)
{
	tlx=tlx_;
	tly=tly_;
	brx=brx_;
	bry=bry_;
	return (brx-tlx)*(tly-bry);
}
double Rectangle::perimeter()
{
	return 2*(brx-tlx+tly-bry);
}
