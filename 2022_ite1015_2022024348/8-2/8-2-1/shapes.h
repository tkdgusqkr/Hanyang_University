#ifndef __SHAPES_H__
#define __SHAPES_H__
#include <iostream>
using namespace std;
class Shape {
        public:
                Shape();
                Shape(int width,int height);

                double GetArea() {};
                int GetPerimeter() {};
                void Draw(int canvas_width, int canvas_height) {};

        protected:
                int _width,_height;
};
class Rectangle:public Shape{
	public:
		Rectangle(int x,int y,int width,int height,string brush);
                double GetArea();
                int GetPerimeter();
                void Draw(int canvas_width, int canvas_height);
	private:
		int _x,_y;
		string _brush;
};
class Square:public Shape{
	public:
		Square(int x,int y,int length,string brush);
                double GetArea();
                int GetPerimeter();
                void Draw(int canvas_width, int canvas_height);
	private:
		int _x,_y;
		string _brush;
};
class Diamond:public Shape{
	public:
		Diamond(int x,int y,int distance,string brush);
                double GetArea();
                int GetPerimeter();
                void Draw(int canvas_width, int canvas_height);
	private:
		int _x,_y,_distance;
		string _brush;
};
#endif
