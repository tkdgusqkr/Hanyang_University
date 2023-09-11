#include <iostream>
#include <string>
#include <set>
#include "setfunc.h"
std::set<int> parseSet(const std::string& str)
{
	std::set<int> set;
	std::string integer="";
	for(int i=0;i<str.length();++i)
	{
		if(str[i]==' ')
		{
			set.insert(stoi(integer));
			integer="";
		}
		else
		{
			integer+=str[i];
		}
	}
	return set;
}
void printSet(const std::set<int>& set)
{
	std::cout<<"{ ";
	for(std::set<int>::const_iterator it=set.begin();it!=set.end();++it)
	{
		std::cout<<*it<<' ';
	}
	std::cout<<"}\n";
}
std::set<int> getIntersection(const std::set<int>& set0, const std::set<int>& set1)
{
	std::set<int> set;
	for(std::set<int>::const_iterator it=set1.begin();it!=set1.end();++it)
	{
		if(set0.count((*it)))
		{
			set.insert((*it));
		}
	}
	return set;
}
std::set<int> getUnion(const std::set<int>& set0, const std::set<int>& set1)
{
	std::set<int> set;
	for(std::set<int>::const_iterator it=set0.begin();it!=set0.end();++it)
	{
		set.insert((*it));
	}
	for(std::set<int>::const_iterator it=set1.begin();it!=set1.end();++it)
	{
		set.insert((*it));
	}
	return set;
}
std::set<int> getDifference(const std::set<int>& set0, const std::set<int>& set1)
{
	std::set<int> set;
	for(std::set<int>::const_iterator it=set0.begin();it!=set0.end();++it)
	{
		set.insert((*it));
	}
	for(std::set<int>::const_iterator it=set1.begin();it!=set1.end();++it)
	{
		set.erase((*it));
	}
	return set;
}
