#ifndef __CANVAS_H__
#define __CANVAS_H__
#include <iostream>
#include <vector>
class Canvas {
 public:
  Canvas(size_t row, size_t col);
  ~Canvas();

  // Change this canvas size to w x h. Preserve already existing shapes on the canvas.
  void Resize(size_t w, size_t h);

  // Dot with the brush at (x,y). If (x,y) is outside the canvas, just ignore it.
void DrawPixel(int x, int y, std::string& brush);

//Print out the canvas
void Print();

  // Erase all (initialize with '.')
void Clear();
 private:
// Define data member to save drawn shapes (note the resize function)
	std::vector<std::vector<std::string>> canvas;
	size_t width,height;
};
class Shape {
 public:
  virtual ~Shape();
  virtual void Draw(Canvas* canvas) {};
  virtual void Print() {};
 protected:
  // Define common properties of shapes
  	int x,y;
	std::string brush;
};

class Rectangle : public Shape 
{ 
	/* Define required members */
	public:	
		Rectangle(int tlx,int tly,int w,int h,std::string& b);
		virtual void Draw(Canvas* canvas);
		virtual void Print();
	private:
		int width,height;
};
class UpTriangle : public Shape 
{
       	/* Define required members */
	public:
		UpTriangle(int tcx,int tcy,int h,std::string& b);
		virtual void Draw(Canvas* canvas);
		virtual void Print();
	private:
		int height;
};
class DownTriangle : public Shape 
{
       	/* Define required members */ 
	public:
		DownTriangle(int bcx,int bcy,int h,std::string& b);
		virtual void Draw(Canvas* canvas);
		virtual void Print();
	private:
		int height;
};
class Diamond : public Shape 
{
       	/* Define required members */
	public:
		Diamond(int tcx,int tcy,int d,std::string& b);
		virtual void Draw(Canvas* canvas);
		virtual void Print();
	private:
		int distance;
};
#endif
