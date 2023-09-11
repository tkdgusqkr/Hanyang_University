#include <iostream>
#include <vector>
#include <algorithm>
#include "sorted.h"
SortedArray::SortedArray()
{
}
SortedArray::~SortedArray()
{
}
void SortedArray::AddNumber(int num)
{
	numbers_.push_back(num);
}
std::vector<int> SortedArray::GetSortedAscending()
{
	std::sort(numbers_.begin(),numbers_.end());
	return numbers_;
}
std::vector<int> SortedArray::GetSortedDescending()
{
	std::sort(numbers_.begin(),numbers_.end(),std::greater<int>());
	return numbers_;
}
int SortedArray::GetMax()
{
	return *std::max_element(numbers_.begin(),numbers_.end());
}
int SortedArray::GetMin()
{
	return *std::min_element(numbers_.begin(),numbers_.end());
}
