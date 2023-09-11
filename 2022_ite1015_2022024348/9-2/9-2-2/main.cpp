#include <iostream>
#include <vector>
#include "canvas.h"
int main()
{
	size_t width,height;
	std::cin>>width>>height;
	Canvas canvas(height,width);
	std::vector<Shape*> shapes;
	while(1)
	{
		std::string command;
		std::cin>>command;
		if(command=="add")
		{
			std::string shape;
			std::cin>>shape;
			if(shape=="rect")
			{
				int tlx,tly,w,h;
				std::string b;
				std::cin>>tlx>>tly>>w>>h>>b;
				shapes.push_back(new Rectangle(tlx,tly,w,h,b));
			}
			else if(shape=="diamond")
			{
				int tcx,tcy,d;
				std::string b;
				std::cin>>tcx>>tcy>>d>>b;
				shapes.push_back(new Diamond(tcx,tcy,d,b));
			}
			else if(shape=="tri_up")
			{
				int tcx,tcy,h;
				std::string b;
				std::cin>>tcx>>tcy>>h>>b;
				shapes.push_back(new UpTriangle(tcx,tcy,h,b));
			}
			else if(shape=="tri_down")
			{
				int bcx,bcy,h;
				std::string b;
				std::cin>>bcx>>bcy>>h>>b;
				shapes.push_back(new DownTriangle(bcx,bcy,h,b));
			}
		}
		else if(command=="delete")
		{
			int index;
			std::cin>>index;
			if(index<shapes.size())
			{
				shapes.erase(shapes.begin()+index);
			}
		}
		else if(command=="draw")
		{
			canvas.Clear();
			for(int i=0;i<shapes.size();++i)
			{
				shapes[i]->Draw(&canvas);
			}
			canvas.Print();
		}
		else if(command=="dump")
		{
			for(int i=0;i<shapes.size();++i)
			{
				std::cout<<i<<" ";
				shapes[i]->Print();
			}
		}
		else if(command=="resize")
		{
			size_t w,h;
			std::cin>>w>>h;
			canvas.Resize(w,h);
		}
		else
		{
			break;
		}
	}
	for(int i=0;i<shapes.size();++i)
	{
		delete shapes[i];
	}
	return 0;
}
