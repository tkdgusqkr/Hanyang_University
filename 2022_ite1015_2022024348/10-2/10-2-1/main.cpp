#include <iostream>
#include <vector>
#include "clock_time.h"
#include "clocks.h"
int main()
{
	std::vector<Clock*> clocks;
	clocks.push_back(new SundialClock(0, 0, 0));
	clocks.push_back(new CuckooClock(0, 0, 0));
	clocks.push_back(new GrandFatherClock(0, 0, 0));
	clocks.push_back(new WristClock(0, 0, 0));
	clocks.push_back(new AtomicClock(0, 0, 0));
	int simulationTime;
	std::cin >> simulationTime;
	for(int i = 0;i < clocks.size();++i)
	{
		clocks[i]->reset();
	}
	std::cout << "Reported clock times after resetting:" << std::endl;
	for(int i = 0;i < clocks.size();++i)
	{
		clocks[i]->displayTime();
	}
	std::cout << "\nRunning the clocks...\n" << std::endl;
	for(int sec = 0;sec < simulationTime;++sec)
	{
		for(int i = 0;i < clocks.size();++i)
		{
			clocks[i]->tick();
		}
	}
	for(int i = 0;i < clocks.size();++i)
	{
		clocks[i]->displayTime();
	}
	for(int i = 0;i < clocks.size();++i)
	{
		delete clocks[i];
	}
	return 0;
}
