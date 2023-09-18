#include <iostream>
#include <vector>
#include "shape.h"
int main()
{
	std::vector<Shape*> arr;
	while(1)
	{
		std::string command;
		std::cin>>command;
		if(command=="r")
		{
			double width,height;
			std::cin>>width>>height;
			arr.push_back(new Rectangle(width,height));
		}
		else if(command=="t")
		{
			double width,height;
			std::cin>>width>>height;
			arr.push_back(new Triangle(width,height));
		}
		else
		{
			for(int i=0;i<arr.size();++i)
			{
				std::cout<<arr[i]->getArea()<<std::endl;
			}
			break;
		}
	}
	for(int i=0;i<arr.size();++i)
	{
		delete arr[i];
	}
}
