#include <iostream>
#include <vector>
#include <map>
#include "message.h"
MessageBook::MessageBook()
{
}
MessageBook::~MessageBook()
{
}
void MessageBook::AddMessage(int number,const std::string& message)
{
	messages_.insert({number,message});
}
void MessageBook::DeleteMessage(int number)
{
	messages_.erase(number);
}
std::vector<int> MessageBook::GetNumbers()
{
	std::vector<int> numbers;
	for(auto element:messages_)
	{
		numbers.push_back(element.first);
	}
	return numbers;
}
const std::string& MessageBook::GetMessage(int number)
{
	return messages_[number];
}
