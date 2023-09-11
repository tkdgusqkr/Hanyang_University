#include <iostream>
#include <vector>
#include "animal.h"
int main()
{
	std::vector<Animal*> animals;
	while(1)
	{
		char command;
		std::cin>>command;
		if(command=='z')
		{
			std::string name;
			int age;
			int numStripes;
			std::cin>>name>>age>>numStripes;
			animals.push_back(new Zebra(name,age,numStripes));
		}
		else if(command=='c')
		{
			std::string name;
			int age;
			std::string favoriteToy;
			std::cin>>name>>age>>favoriteToy;
			animals.push_back(new Cat(name,age,favoriteToy));
		}
		else
		{
			break;
		}
	}
	for(int i=0;i<animals.size();++i)
	{
		animals[i]->printInfo();
		delete animals[i];
	}
	return 0;
}
