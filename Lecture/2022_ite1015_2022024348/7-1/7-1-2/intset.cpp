#include <iostream>
#include <vector>
#include <algorithm>
#include "intset.h"
IntegerSet::IntegerSet()
{
}
IntegerSet::~IntegerSet()
{
}
void IntegerSet::AddNumber(int num)
{
	numbers_.push_back(num);
	for(int i=0;i<numbers_.size()-1;i++)
	{
		if(numbers_[i]==num)
		{
			numbers_.pop_back();
			break;
		}
	}
	std::sort(numbers_.begin(),numbers_.end());
}
void IntegerSet::DeleteNumber(int num)
{
	for(int i=0;i<numbers_.size();i++)
	{
		if(numbers_[i]==num)
		{
			numbers_.erase(numbers_.begin()+i);
			break;
		}
	}
}
int IntegerSet::GetItem(int pos)
{
	if(pos<numbers_.size())
	{
		return numbers_[pos];
	}
	else
	{
		return -1;
	}
}
std::vector<int> IntegerSet::GetAll()
{
	return numbers_;
}
